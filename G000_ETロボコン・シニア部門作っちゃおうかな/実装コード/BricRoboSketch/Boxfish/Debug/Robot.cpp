#include "stdafx.h"
#include "Robot.h"

void Robot::ConfigParam(int dummy)
{
	//Serial.begin(9600);
	Serial.begin(115200);
	delay(2000);//���肷��܂ő҂�
	//Serial.flush();�����Ă���Ƃ͎v���Ȃ�
	while( Serial.available() >0 )	//�S�~����菜��
	{
		Serial.read();
	}
}

void Robot::Run()
{
	uView.clear(PAGE);
	uView.setCursor(0,0);

	if( Serial.available() > 0 )
	{
		uint8_t r = Serial.read();
		uView.println(r);
		r += 10;
		Serial.write( r );
	}
	else
	{
		uView.println("---");
	}
}
