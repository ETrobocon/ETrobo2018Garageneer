ARDUINO_DIR = C:\PROGRA~2\Arduino
TOOLS_DIR = C:\PROGRA~2\Arduino\hardware\tools\avr\bin
BR_INO_DIR = C:\PROGRA~2\FCT\BrIno
PROJECT_DIR = C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3
BUILD_DIR = C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build
PATH = $(BR_INO_DIR);$(TOOLS_DIR);$(PATH)
UPLOAD_COM_PORT = COM9
ASFLAGS = -c -g -x assembler-with-cpp
CCFLAGS = -c -g -Os -w -ffunction-sections -fdata-sections -MMD
CXXFLAGS = -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD
LDFLAGS = -w -Os -Wl,--gc-sections
EEPFLAGS = -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 
HEXFLAGS = -O ihex -R .eeprom
MCU = atmega328p
F_CPU = 16000000L
USB_VID = null
USB_PID = null
UPLOAD_PROTOCOL = arduino
UPLOAD_SPEED = 57600
BOARD_TYPE = ARDUINO_AVR_UNO
BOARD_ARCH = ARDUINO_ARCH_AVR
USB_MANUFACTURER = Unknown
USB_PRODUCT = Arduino Nano w/ ATmega328


all : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep

upload : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep
	avrdude -C$(TOOLS_DIR)/../etc/avrdude.conf -v -p$(MCU) -c$(UPLOAD_PROTOCOL) -P\\.\$(UPLOAD_COM_PORT) -b$(UPLOAD_SPEED) -D -Uflash:w:C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf.hex:i

resetupload : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep
	ResetUploader avrdude -C$(TOOLS_DIR)/../etc/avrdude.conf -v -p$(MCU) -c$(UPLOAD_PROTOCOL) -P\\.\$(UPLOAD_COM_PORT) -b$(UPLOAD_SPEED) -D -Uflash:w:C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf.hex:i

brinouploader : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep
	BrInoUploader $(TOOLS_DIR) $(MCU) $(UPLOAD_PROTOCOL) $(UPLOAD_COM_PORT) $(UPLOAD_SPEED) C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf.hex

clean :
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\LedDriver.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\LedDriver.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\LedDriver.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\LedDriver.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\VoltSensor.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\VoltSensor.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\VoltSensor.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\VoltSensor.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\XC10A.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\XC10A.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\XC10A.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\XC10A.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\AccelBuffer.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\AccelBuffer.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\AccelBuffer.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\AccelBuffer.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduinControlller.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduinControlller.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\TeniboArduinControlller.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\TeniboArduinControlller.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\DigitalOut.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\DigitalOut.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\DigitalOut.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\DigitalOut.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Telecom.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Telecom.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Telecom.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Telecom.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboCOM_API.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboCOM_API.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboCOM_API.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboCOM_API.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_API.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_API.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_API.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_API.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Model.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Model.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Model.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Model.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Task.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Task.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Task.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Task.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\arduinoMain.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\arduinoMain.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\arduinoMain.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\arduinoMain.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboController.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboController.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboController.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboController.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboTask.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboTask.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboTask.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboTask.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MsTimer2.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MsTimer2.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MsTimer2.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MsTimer2.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MicroView.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MicroView.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MicroView.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MicroView.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\I2Cdev.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\I2Cdev.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\I2Cdev.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\I2Cdev.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MPU6050.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MPU6050.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MPU6050.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MPU6050.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Wire.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Wire.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Wire.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Wire.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\twi.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\twi.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\twi.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\twi.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Servo.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Servo.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp.d"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\SoftwareSerial.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\SoftwareSerial.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\SoftwareSerial.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\SoftwareSerial.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\hooks.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\hooks.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\hooks.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\hooks.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WInterrupts.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WInterrupts.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WInterrupts.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WInterrupts.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_analog.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_analog.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_analog.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_analog.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_digital.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_digital.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_digital.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_digital.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_pulse.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_pulse.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_pulse.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_pulse.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_shift.c.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_shift.c.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_shift.c.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_shift.c.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\abi.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\abi.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\abi.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\abi.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\CDC.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\CDC.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\CDC.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\CDC.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial0.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial0.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial0.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial0.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial1.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial1.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial1.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial1.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial2.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial2.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial2.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial2.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial3.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial3.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial3.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial3.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HID.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HID.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HID.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HID.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\IPAddress.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\IPAddress.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\IPAddress.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\IPAddress.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\main.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\main.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\main.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\main.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\new.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\new.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\new.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\new.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Print.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Print.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Print.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Print.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Stream.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Stream.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Stream.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Stream.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Tone.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Tone.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Tone.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Tone.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\USBCore.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\USBCore.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\USBCore.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\USBCore.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WMath.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WMath.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WMath.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WMath.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WString.cpp.o" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WString.cpp.o"
	@if exist "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WString.cpp.d" del "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WString.cpp.d"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\core.a" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\core.a"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep"
	@if exist "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex" del "C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex"
	@echo ÉtÉ@ÉCÉãÇçÌèúÇµÇ‹ÇµÇΩ

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\LedDriver.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\Common\Parts\LedDriver\LedDriver.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../Common/Parts/LEDDRI~1 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/LedDriver.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../Common/Parts/LedDriver/LedDriver.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\VoltSensor.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\TeniboArduino\Parts\VoltSensor.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../TENIBO~3/Parts -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/VoltSensor.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../TeniboArduino/Parts/VoltSensor.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\XC10A.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\JellyFish\Parts\XC10A\XC10A.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../JELLYF~1/Parts/XC10A -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/XC10A.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../JellyFish/Parts/XC10A/XC10A.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\AccelBuffer.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\TeniboArduino\Parts\AccelBuffer.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../TENIBO~3/Parts -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/AccelBuffer.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../TeniboArduino/Parts/AccelBuffer.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduinControlller.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\TeniboArduino\Parts\TeniboArduinControlller.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../TENIBO~3/Parts -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduinControlller.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../TeniboArduino/Parts/TeniboArduinControlller.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\DigitalOut.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\BricRoboSketch\DigitalOut.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../BRICRO~2 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/DigitalOut.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../BricRoboSketch/DigitalOut.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Telecom.cpp.o : C:\Users\ike\Documents\WaterRobot\TeniboArduino\..\TeniboArduino\Parts\Telecom.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/../TENIBO~3/Parts -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Telecom.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/../TeniboArduino/Parts/Telecom.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboCOM_API.cpp.o : RTE\BricRoboCOM_API.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IRTE -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboCOM_API.cpp.o RTE/BricRoboCOM_API.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_API.cpp.o : RTE\BricRoboRTE_API.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IRTE -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_API.cpp.o RTE/BricRoboRTE_API.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Model.cpp.o : RTE\BricRoboRTE_Model.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IRTE -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_Model.cpp.o RTE/BricRoboRTE_Model.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Task.cpp.o : RTE\BricRoboRTE_Task.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IRTE -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -I. -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_Task.cpp.o RTE/BricRoboRTE_Task.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\arduinoMain.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\BricRobo\utility\arduinoMain.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/BricRobo/utility -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/arduinoMain.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility/arduinoMain.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboController.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\BricRobo\utility\BricRoboController.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/BricRobo/utility -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboController.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility/BricRoboController.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboTask.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\BricRobo\utility\BricRoboTask.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/BricRobo/utility -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboTask.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo/utility/BricRoboTask.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MsTimer2.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\MsTimer2\MsTimer2.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/MsTimer2 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MsTimer2.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2/MsTimer2.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MicroView.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\MicroView\MicroView.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/MICROV~1 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MicroView.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/MicroView/MicroView.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\I2Cdev.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\I2Cdev\I2Cdev.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/I2Cdev -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/I2Cdev.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev/I2Cdev.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MPU6050.cpp.o : C:\Users\ike\DOCUME~1\Arduino\libraries\MPU6050\MPU6050.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/Users/ike/DOCUME~1/Arduino/LIBRAR~1/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MPU6050.cpp.o C:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050/MPU6050.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Wire.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\libraries\Wire\Wire.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/LIBRAR~1/Wire -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire/utility -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Wire.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire/Wire.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\twi.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\libraries\Wire\utility\twi.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/LIBRAR~1/Wire/utility -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire/utility -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/twi.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire/utility/twi.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Servo.cpp.o : C:\PROGRA~2\Arduino\libraries\Servo\src\avr\Servo.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/LIBRAR~1/Servo/src/avr -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/PROGRA~2/Arduino/libraries/Servo/src -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Servo.cpp.o C:/PROGRA~2/Arduino/libraries/Servo/src/avr/Servo.cpp

C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o : C:\PROGRA~2\Arduino\libraries\Servo\src\sam\Servo.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/LIBRAR~1/Servo/src/sam -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/PROGRA~2/Arduino/libraries/Servo/src -o C:/Users/ike/Documents/WaterRobot/TeniboArduino/Build/Servo.cpp~1.o C:/PROGRA~2/Arduino/libraries/Servo/src/sam/Servo.cpp

C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o : C:\PROGRA~2\Arduino\libraries\Servo\src\samd\Servo.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/LIBRAR~1/Servo/src/samd -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -IC:/PROGRA~2/Arduino/libraries/Servo/src -o C:/Users/ike/Documents/WaterRobot/TeniboArduino/Build/Servo.cpp~1.o C:/PROGRA~2/Arduino/libraries/Servo/src/samd/Servo.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\SoftwareSerial.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\libraries\SoftwareSerial\SoftwareSerial.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/LIBRAR~1/SOFTWA~1 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -IC:/Users/ike/DOCUME~1/Arduino/libraries/BricRobo -IC:/Users/ike/DOCUME~1/Arduino/libraries/MsTimer2 -IC:/Users/ike/DOCUME~1/Arduino/libraries/MicroView -IC:/Users/ike/DOCUME~1/Arduino/libraries/I2Cdev -IC:/Users/ike/DOCUME~1/Arduino/libraries/MPU6050 -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/Wire -IC:/PROGRA~2/Arduino/libraries/Servo/src -IC:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/SoftwareSerial.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/libraries/SoftwareSerial/SoftwareSerial.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\hooks.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\hooks.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/hooks.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/hooks.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WInterrupts.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\WInterrupts.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WInterrupts.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/WInterrupts.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\wiring.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/wiring.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_analog.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\wiring_analog.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_analog.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/wiring_analog.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_digital.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\wiring_digital.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_digital.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_pulse.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\wiring_pulse.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_pulse.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/wiring_pulse.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_shift.c.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\wiring_shift.c
	avr-gcc $(CCFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_shift.c.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/wiring_shift.c

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\abi.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\abi.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/abi.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/abi.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\CDC.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\CDC.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/CDC.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/CDC.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial0.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial0.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial0.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial0.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial1.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial1.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial1.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial1.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial2.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial2.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial2.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial2.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial3.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial3.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial3.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HardwareSerial3.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HID.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\HID.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HID.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/HID.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\IPAddress.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\IPAddress.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/IPAddress.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/IPAddress.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\main.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\main.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/main.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/main.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\new.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\new.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/new.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/new.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Print.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\Print.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Print.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/Print.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Stream.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\Stream.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Stream.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/Stream.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Tone.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\Tone.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Tone.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/Tone.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\USBCore.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\USBCore.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/USBCore.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/USBCore.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WMath.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\WMath.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WMath.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/WMath.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WString.cpp.o : C:\PROGRA~2\Arduino\hardware\arduino\avr\cores\arduino\WString.cpp
	avr-g++ $(CXXFLAGS) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO=10709 -D$(BOARD_TYPE) -D$(BOARD_ARCH) -DUSB_VID=$(USB_VID) -DUSB_PID=$(USB_PID) -DUSB_MANUFACTURER="\"$(USB_MANUFACTURER)\"" -DUSB_PRODUCT="\"$(USB_PRODUCT)\"" -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino -IC:/PROGRA~2/Arduino/hardware/arduino/avr/variants/eightanaloginputs -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WString.cpp.o C:/PROGRA~2/Arduino/hardware/arduino/avr/cores/arduino/WString.cpp

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\core.a : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\hooks.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WInterrupts.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_analog.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_digital.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_pulse.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\wiring_shift.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\abi.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\CDC.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial0.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial1.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial2.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HardwareSerial3.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\HID.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\IPAddress.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\main.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\new.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Print.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Stream.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Tone.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\USBCore.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WMath.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\WString.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/hooks.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WInterrupts.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_analog.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_digital.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_pulse.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/wiring_shift.c.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/abi.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/CDC.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial0.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial1.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial2.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HardwareSerial3.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/HID.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/IPAddress.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/main.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/new.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Print.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Stream.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Tone.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/USBCore.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WMath.cpp.o
	avr-ar rcs C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/WString.cpp.o

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\LedDriver.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\VoltSensor.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\XC10A.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\AccelBuffer.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduinControlller.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\DigitalOut.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Telecom.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboCOM_API.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_API.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Model.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboRTE_Task.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\arduinoMain.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboController.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\BricRoboTask.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MsTimer2.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MicroView.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\I2Cdev.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\MPU6050.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Wire.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\twi.c.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\Servo.cpp.o C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\SoftwareSerial.cpp.o C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\core.a
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) -o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/LedDriver.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/VoltSensor.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/XC10A.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/AccelBuffer.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduinControlller.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/DigitalOut.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Telecom.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboCOM_API.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_API.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_Model.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboRTE_Task.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/arduinoMain.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboController.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/BricRoboTask.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MsTimer2.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MicroView.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/I2Cdev.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/MPU6050.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Wire.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/twi.c.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/Servo.cpp.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/Build/Servo.cpp~1.o C:/Users/ike/Documents/WaterRobot/TeniboArduino/Build/Servo.cpp~1.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/SoftwareSerial.cpp.o C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/core.a -lm

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.eep : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf
	avr-objcopy $(EEPFLAGS) C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf.eep

C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf.hex : C:\Users\ike\DOCUME~1\WATERR~1\TENIBO~3\Build\TeniboArduino.elf
	avr-objcopy $(HEXFLAGS) C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf C:/Users/ike/DOCUME~1/WATERR~1/TENIBO~3/Build/TeniboArduino.elf.hex

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\LedDriver.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\LedDriver.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\VoltSensor.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\VoltSensor.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\XC10A.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\XC10A.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\AccelBuffer.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\AccelBuffer.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\TeniboArduinControlller.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\TeniboArduinControlller.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\DigitalOut.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\DigitalOut.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Telecom.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Telecom.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboCOM_API.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboCOM_API.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_API.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_API.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Model.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Model.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Task.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboRTE_Task.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\arduinoMain.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\arduinoMain.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboController.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboController.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboTask.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\BricRoboTask.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MsTimer2.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MsTimer2.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MicroView.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MicroView.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\I2Cdev.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\I2Cdev.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MPU6050.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\MPU6050.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Wire.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Wire.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\twi.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\twi.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Servo.cpp~1.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\SoftwareSerial.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\SoftwareSerial.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\hooks.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\hooks.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WInterrupts.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WInterrupts.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_analog.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_analog.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_digital.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_digital.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_pulse.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_pulse.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_shift.c.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\wiring_shift.c.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\abi.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\abi.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\CDC.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\CDC.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial0.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial0.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial1.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial1.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial2.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial2.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial3.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HardwareSerial3.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HID.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\HID.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\IPAddress.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\IPAddress.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\main.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\main.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\new.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\new.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Print.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Print.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Stream.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Stream.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Tone.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\Tone.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\USBCore.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\USBCore.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WMath.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WMath.cpp.d"
!endif

!if exist (C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WString.cpp.d)
!include "C:\Users\ike\Documents\WaterRobot\TeniboArduino\Build\WString.cpp.d"
!endif

