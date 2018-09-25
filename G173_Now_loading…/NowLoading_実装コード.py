import wiringpi as pi
import time, math
import RPi.GPIO as GPIO
import Adafruit_PCA9685

servo_pin = 18

degree = 0

CYCLE = 20         # Unit : ms
SERVO_MIN = 0.5    # Unit : ms
SERVO_MAX = 2.4    # Unit : ms

RANGE = 2000

clock = int( 19.2 / float(RANGE) * CYCLE * 1000 )

pi.wiringPiSetupGpio()
pi.pinMode( servo_pin, pi.GPIO.PWM_OUTPUT )
pi.pwmSetMode( pi.GPIO.PWM_MODE_MS )
pi.pwmSetRange( RANGE )
pi.pwmSetClock( clock )

SERVO_MIN_VALUE = int( SERVO_MIN * RANGE / CYCLE )
SERVO_MAX_VALUE = int( SERVO_MAX * RANGE / CYCLE )

SPI_CS = 0

SPI_SPEED = 100000

pi.wiringPiSPISetup (SPI_CS, SPI_SPEED)

#走行モードの選択
def mode_select():
    pushSW_PIN = 15
    slideSW_PIN =  14

    pi.wiringPiSetupGpio()
    pi.pullUpDnControl( pushSW_PIN, pi.PUD_DOWN )
    pi.pullUpDnControl( slideSW_PIN, pi.PUD_DOWN )
    pi.pinMode( pushSW_PIN, pi.INPUT )
    pi.pinMode( slideSW_PIN, pi.INPUT )

        
    if( pi.digitalRead( slideSW_PIN) == pi.HIGH and pi.digitalRead( pushSW_PIN) == pi.LOW ):
        print( "slideSwitch On" )
        print( "pushSwitch Off" )
        mode_select = 1
        print( "TRANSLATIONAL MODE" )
        print( 'mode_select=%d' % mode_select )
    elif( pi.digitalRead( slideSW_PIN) == pi.HIGH and pi.digitalRead( pushSW_PIN) == pi.HIGH ):
        print( "slideSwitch On" )
        print( "pushSwitch On" )
        mode_select = 2
        print( "ROTATIONAL MODE" )
        print( 'mode_select=%d' % mode_select )
    else:
        print( "slideSwitch Off" )
        print( "pushSwitch Off" )
        mode_select = 0
        print( "PUPPET MODE" )
        print( 'mode_select=%d' % mode_select )
        
    return(mode_select)

def spi_read( read_addr ):
    command = read_addr | 0x80
    buffer = command << 8
    buffer = buffer.to_bytes(2, byteorder='big')
    pi.wiringPiSPIDataRW(SPI_CS, buffer)
    return( buffer[1] )

def conv_two_byte( high, low ):
    dat = high << 8 | low
    if ( high >= 0x80 ):
        dat = dat - 65536
    dat = dat >> 4
    return ( dat )

def conv_angle( x, y, z ):
    x_angle = math.degrees( math.atan2( x, math.sqrt( y ** 2 + z ** 2 ) ) )
    y_angle = math.degrees( math.atan2( y, math.sqrt( x ** 2 + z ** 2 ) ) )
    return ( x_angle, y_angle )


#グローブ＋パペットサーボ駆動
pwm = Adafruit_PCA9685.PCA9685()
pwm.set_pwm_freq(60)

GPIO.setmode(GPIO.BOARD)
pin_A_R = 11
pin_B_R = 12
pin_A_L = 16
pin_B_L = 18
pin_A_N = 13
pin_B_N = 15
pin_R_H = 33
pin_L_H = 37
pin_N_H = 35

globalCounter_R = 0
globalCounter_L = 0
globalCounter_N = 0

#パペットの右手に相当するグローブデバイスのエンコーダ値取得し、パペット駆動実行
def callBack_R(channel):
    global globalCounter_R
    Last_RoA_Status_R = GPIO.input(pin_A_R)
    Last_RoB_Status_R = GPIO.input(pin_B_R)
    if Last_RoB_Status_R == 1 :
        globalCounter_R = globalCounter_R + 3
    elif Last_RoB_Status_R == 0 :
        globalCounter_R = globalCounter_R - 3
    print("Right " ,globalCounter_R ,globalCounter_L, globalCounter_N)
    if globalCounter_R <= 18 and globalCounter_R >= -18:
          mode = mode_select()
          if (mode == 0):
          	duty_R = globalCounter_R*10 + 350
          else:
          	duty_R = 0
          pwm.set_pwm(0,0,duty_R)
    elif globalCounter_R > 18 :
        globalCounter_R = 18
    elif globalCounter_R < -18:
        globalCounter_R = -18

#パペットの左手に相当するグローブデバイスのエンコーダ値取得し、パペット駆動実行
def callBack_L(channel):
    global globalCounter_L
    Last_RoA_Status_L = GPIO.input(pin_A_L)
    Last_RoB_Status_L = GPIO.input(pin_B_L)
    if Last_RoB_Status_L == 1 :
        globalCounter_L = globalCounter_L - 3
    elif Last_RoB_Status_L == 0 :
        globalCounter_L = globalCounter_L + 3
    print("Left " ,globalCounter_R ,globalCounter_L, globalCounter_N)
    if globalCounter_L <= 18 and globalCounter_L >= -18:
          mode = mode_select()
          if (mode == 0):
          	duty_L= globalCounter_L*10 + 350
          else:
          	duty_L = 0
          pwm.set_pwm(1,0,duty_L)
    elif globalCounter_L > 18 :
        globalCounter_L = 18
    elif globalCounter_L < -18:
        globalCounter_L = -18
        
#パペットの首に相当するグローブデバイスのエンコーダ値取得し、パペット駆動実行
def callBack_N(channel):
    global globalCounter_N
    Last_RoA_Status_N = GPIO.input(pin_A_N)
    Last_RoB_Status_N = GPIO.input(pin_B_N)
    if Last_RoB_Status_N == 1 :
        globalCounter_N = globalCounter_N - 3
    elif Last_RoB_Status_N == 0 :
        globalCounter_N = globalCounter_N + 3
    print("Neck " ,globalCounter_R ,globalCounter_L, globalCounter_N)
    if globalCounter_N <= 18 and globalCounter_N >= -18:
          mode = mode_select()
          if (mode == 0):
          	duty_N = globalCounter_N*10 + 350
          else:
          	duty_N = 0
          pwm.set_pwm(3,0,duty_N)
          pwm.set_pwm(5,0,duty_N)
    elif globalCounter_N > 18 :
        globalCounter_N = 18
    elif globalCounter_N < -18:
        globalCounter_N = -18
        
def callBack_R_H(channel):
    global globalCounter_R
    globalCounter_R = 0
    print("RH")
    
def callBack_L_H(channel):
    global globalCounter_L
    globalCounter_L = 0
    print("RL")
    
def callBack_N_H(channel):
    global globalCounter_N
    globalCounter_N = 0
    print("RN")
    
GPIO.setup(pin_A_R,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_B_R,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_A_L,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_B_L,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_A_N,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_B_N,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_R_H,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_L_H,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(pin_N_H,GPIO.IN,GPIO.PUD_UP)

GPIO.add_event_detect(pin_A_R,GPIO.FALLING,callback=callBack_R,bouncetime=30)
GPIO.add_event_detect(pin_A_L,GPIO.FALLING,callback=callBack_L,bouncetime=30)
GPIO.add_event_detect(pin_A_N,GPIO.FALLING,callback=callBack_N,bouncetime=30)
GPIO.add_event_detect(pin_R_H,GPIO.FALLING,callback=callBack_R_H,bouncetime=30)
GPIO.add_event_detect(pin_L_H,GPIO.FALLING,callback=callBack_L_H,bouncetime=30)
GPIO.add_event_detect(pin_N_H,GPIO.FALLING,callback=callBack_N_H,bouncetime=30)


#ポインターによる指差し
def LED_pointer():
    SW_PIN = 15
    LED_PIN = 4

    pi.wiringPiSetupGpio()
    pi.pullUpDnControl( SW_PIN, pi.PUD_DOWN)
    pi.pinMode( SW_PIN, pi.INPUT )
    pi.pinMode( LED_PIN, pi.OUTPUT )
    
    if ( pi.digitalRead( SW_PIN ) == pi.HIGH ):
        pi.digitalWrite( LED_PIN, pi.HIGH )
    else:
        pi.digitalWrite( LED_PIN, pi.LOW )
    time.sleep(0.1)
    return
    
# 6つのPWMにデューティー比をまとめてセットするためのマクロ
def pwm6Write(v1_forward, v1_reverse, v2_forward, v2_reverse, v3_forward, v3_reverse, PWM_rate):
    MOTOR1_PIN = 25
    MOTOR2_PIN = 16
    MOTOR3_PIN = 6
    MOTOR4_PIN = 5
    MOTOR5_PIN = 21
    MOTOR6_PIN = 20
    
    # GPIOライブラリの取得
    pi.wiringPiSetupGpio()
    
    #GPIOを出力モードに設定
    pi.pinMode( MOTOR1_PIN, pi.OUTPUT )
    pi.pinMode( MOTOR2_PIN, pi.OUTPUT )
    pi.pinMode( MOTOR3_PIN, pi.OUTPUT )
    pi.pinMode( MOTOR4_PIN, pi.OUTPUT )
    pi.pinMode( MOTOR5_PIN, pi.OUTPUT )
    pi.pinMode( MOTOR6_PIN, pi.OUTPUT )
    
    #PWMの幅を設定
    pi.softPwmCreate( MOTOR1_PIN, 0, PWM_rate)
    pi.softPwmCreate( MOTOR2_PIN, 0, PWM_rate)
    pi.softPwmCreate( MOTOR3_PIN, 0, PWM_rate)
    pi.softPwmCreate( MOTOR4_PIN, 0, PWM_rate)
    pi.softPwmCreate( MOTOR5_PIN, 0, PWM_rate)
    pi.softPwmCreate( MOTOR6_PIN, 0, PWM_rate)
    
    # 初期のデューティー比を0%に（静止状態）
    pi.softPwmWrite( MOTOR1_PIN, 0 )
    pi.softPwmWrite( MOTOR2_PIN, 0 )
    pi.softPwmWrite( MOTOR3_PIN, 0 )
    pi.softPwmWrite( MOTOR4_PIN, 0 )
    pi.softPwmWrite( MOTOR5_PIN, 0 )
    pi.softPwmWrite( MOTOR6_PIN, 0 )
      
    #後輪（M1）にPWM出力
    pi.softPwmWrite( MOTOR1_PIN,  int(v1_reverse))
    pi.softPwmWrite( MOTOR2_PIN,  int(v1_forward))
    
    #右前輪（M2）にPWM出力
    pi.softPwmWrite( MOTOR3_PIN,  int(v2_reverse))
    pi.softPwmWrite( MOTOR4_PIN,  int(v2_forward))
    
    #左前輪（M3）にPWM出力
    pi.softPwmWrite( MOTOR5_PIN,  int(v3_reverse))
    pi.softPwmWrite( MOTOR6_PIN,  int(v3_forward))
    
    return

buffer = 0x20 << 8 | 0x77
buffer = buffer.to_bytes( 2, byteorder='big' )
pi.wiringPiSPIDataRW( SPI_CS, buffer )

angle = 0

while True:
    #加速度センサから各軸の加速度を取得する
    lb = spi_read( 0x28 )
    hb = spi_read( 0x29 )
    x = conv_two_byte( hb, lb )

    lb = spi_read( 0x2a )
    hb = spi_read( 0x2b )
    y = conv_two_byte( hb, lb )

    lb = spi_read( 0x2c )
    hb = spi_read( 0x2d )
    z = conv_two_byte( hb, lb )

    #加速度から傾き角を算出する
    ( x_angle, y_angle ) = conv_angle( x, y, z )

    #不感帯設定、上限設定
    if ( x_angle > 45):
    	x_angle = 45
    elif ( x_angle < -45):
    	x_angle = -45
    elif ( x_angle > 0 and x_angle <= 5):
    	x_angle = 0
    elif ( x_angle < 0 and x_angle >= -5):
    	x_angle = 0
    	
    if ( y_angle > 45):
    	y_angle = 45
    elif ( y_angle < -45):
    	y_angle = -45
    elif ( y_angle > 0 and y_angle <= 5):
    	y_angle = 0
    elif ( y_angle < 0 and y_angle >= -5):
    	y_angle = 0
    
    #print( 'x_angle=%6.3f' % x_angle )
    #print( 'y_angle=%6.3f' % y_angle )
    #print()      # 改行.   

    mode = mode_select()
    
    #傾斜角度から速度指令値を算出
    rate = 30
    L = 0.3
    
    if (mode == 1):
    	vx = rate / 45 * x_angle
    	vy = rate / 45 * y_angle
    	vt = 0
    elif(mode == 2):
        vx = 0
        vy = 0
        vt = rate / 45 * x_angle
    else:
        vx = 0
        vy = 0
        vt = 0
        LED_pointer()
    
    #各車輪に速度指令値を分配（運動学モデル）
    #後輪（M1）
    v1 = vx + L * vt
    #右前輪（M2）
    v2 = -1/2 * vx + math.sqrt(3)/2 * vy + L*vt
    #左前輪（M3）
    v3 = -1/2 * vx - math.sqrt(3)/2 * vy + L*vt
    
    print( 'v1=%6.3f' % v1 )
    print( 'v2=%6.3f' % v2 )
    print( 'v3=%6.3f' % v3 )
    print()      # 改行.     
    
    v1_plus = 0
    v1_minus = 0
    v2_plus = 0
    v2_minus = 0
    v3_plus = 0
    v3_minus = 0
    
    #PWM出力の正逆転振り分け
    #後輪（M1）にPWM出力
    if ( v1 > 0 ):
        v1_plus= abs(v1)
    elif (v1 < 0 ):
    	v1_minus = abs(v1)
    	
    #前輪輪（M2）にPWM出力
    if ( v2 > 0 ):
        v2_plus= abs(v2)
    elif (v2 < 0 ):
    	v2_minus = abs(v2)
    	
    #前輪輪（M3）にPWM出力
    if ( v3 > 0 ):
        v3_plus= abs(v3)
    elif (v3 < 0 ):
    	v3_minus = abs(v3)

    #移動機構　各モータへの駆動指令
    pwm6Write(v1_plus,  v1_minus, v2_plus,  v2_minus, v3_plus,  v3_minus, rate)

    time.sleep(0.1)

