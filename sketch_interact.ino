// Plant water project
// Interactive section

//---------------------------------LIBRARIES
#include <TimerOne.h>
#include <CapacitiveSensor.h>

//---------------------------------GLOBAL VARIABLES
// timer variables
int count = 0;
int timercount = 0;

// capacitive touch sensor
// 10M resistor between pins 4 & 2, pin 2 is sensor pin, foil added
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);
int touchThreshold = 2500;

// motors pins
//PWM control for motors
const int pwm_right = 3;
const int pwm_left = 11;
//dir control for motors
const int dir_right = 12;
const int dir_left = 13;
// motor speed control (min speed = 255, max speed = 0);
int MotorStop = 255;
int MotorSpeed = 0;

//---------------------------------INTERRUPT
// every ms increment "timercount"
void timer_int(){
  timercount++;
}

//---------------------------------SETUP
void setup() {

  // initialize timer
  noInterrupts();
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timer_int);
  
  // initialize serial communication
  Serial.begin(9600);
  
  // Set motor control pins to be outputs
  pinMode(pwm_right , OUTPUT);
  pinMode(pwm_left , OUTPUT);
  pinMode(dir_right , OUTPUT);
  pinMode(dir_left , OUTPUT);
  // set the motor direction to FORWARD
  digitalWrite(dir_right , 1);
  digitalWrite(dir_left , 0);
  // set the motors speed to 0
  analogWrite(pwm_right, MotorStop);
  analogWrite(pwm_left, MotorStop);

}


//---------------------------------LOOP
void loop() {

  long touchMe =  cs_4_2.capacitiveSensor(30);
  Serial.println(touchMe);
  
  if (touchMe > touchThreshold){
    Serial.println("touch is happening!");
//    count = 0;
//    timercount = 0;
    interrupts();
    analogWrite(pwm_right, MotorSpeed);
    analogWrite(pwm_left, MotorSpeed);
  }

  if(timercount > 100){
    timercount = 0;
    count++;
    digitalWrite(dir_right , !digitalRead(dir_right));
    digitalWrite(dir_left , !digitalRead(dir_left));
    if(count > 5){
      noInterrupts();
      analogWrite(pwm_right, MotorStop);
      analogWrite(pwm_left, MotorStop);
      count = 0;
      timercount = 0;
    }
  }
  
  //delay(1000);
}
