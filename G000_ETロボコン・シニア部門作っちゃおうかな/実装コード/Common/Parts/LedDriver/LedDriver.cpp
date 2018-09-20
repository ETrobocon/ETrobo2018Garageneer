#define __PROG_TYPES_COMPAT__	//Arduino IDE 1.7.9�ł�prog_uchar���g���ɂ�avr/pgmspace.h��include����O�ɁA���̒�`���K�v

#include "stdafx.h"
#include "LedDriver.h"
//#include "avr/pgmspace.h"		//Arduino IDE 1.7.9�ł�Arduino.h��avr/pgmspace.h��include����Ă���s�v

void LedDriver::ConfigParam(int8_t pin)
{
	_pin = pin;
	pinMode( _pin, OUTPUT );

	_no = ALL_OFF;
	_row = 0;
	_times = 0;
}

#define O	5

#define	X	1,O,	0,O
#define XXX 1,O*3,	0,O
#define S	0,O*2,	0xff,0xff

typedef struct atom
{
	prog_uchar hiLow;	//0=�����A1=�_���A0xff=�I�[
	prog_uchar times;	//�ێ�����񐔁A0xff=�I�[
} ATM;

#define WIDE	12

const PROGMEM ATM pattern[][WIDE] =	//Arduino IDE 1.7.9 �ł�const�����Ȃ��ƃR���p�C���ł��Ȃ�
{
	{	//0
		XXX, XXX, XXX, XXX, XXX, S
	},
	{	//1
		X, XXX, XXX, XXX, XXX, S
	},
	{	//2
		X, X, XXX, XXX, XXX, S
	},
	{	//3
		X, X, X, XXX, XXX, S
	},
	{	//4
		X, X, X, X, XXX, S
	},
	{	//5
		X, X, X, X, X, S
	},
	{	//6
		XXX, X, X, X, X, S
	},
	{	//7
		XXX, XXX, X, X, X, S
	},
	{	//8
		XXX, XXX, XXX, X, X, S
	},
	{	//9
		XXX, XXX, XXX, XXX, X, S
	},
	{	//10 ALL_OFF
		0,	1,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},
	{	//11 ALL_ON
		1,	1,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},

	{	//12 STATE_STANDBY
		1,	1,
		0,	199,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},
	{	//13 STATE_CMD
		1,	1,
		0,	99,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},
	{	//14 STATE_ERROR
		1,	12,
		0,	12,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},
	{	//15 ONESHOT_FLASH
		1,	4,
		0,	1,
		0xfe,	0xfe,
		0xff,	0xff,
		0xff,	0xff,
		0xff,	0xff,
	},
	{	//16 STATE_AUTO
		1,	1,
		0,	9,
		1,	1,
		0,	89,
		0xff,	0xff,
		0xff,	0xff,
	}
};

 void LedDriver::Run()
{
	ValueIF patternNo;
    if( Rte_Receive_patternNo(patternNo) == RTE_E_OK )
	{
		if( _no != patternNo.value )
		{
			_no = patternNo.value;
			_row = 0;
			_times = pgm_read_byte( (prog_uchar*)pattern+sizeof(ATM)*WIDE*_no+sizeof(ATM)*_row +1 );
			//_times = pattern[_no][_row].times;
		}
	}

	if( _times == 0 )
	{
		++_row;
		uint8_t hiLow = pgm_read_byte( (prog_uchar*)pattern+sizeof(ATM)*WIDE*_no+sizeof(ATM)*_row );
		if( hiLow == 0xff )
		{
			//�����̐擪�ɖ߂�
			_row = 0;
			_times = pgm_read_byte( (prog_uchar*)pattern+sizeof(ATM)*WIDE*_no+sizeof(ATM)*_row +1 );
			//_times = pattern[_no][_row].times;
		}
		else if( hiLow == 0xfe )
		{
			//�Ō�̕����ő����݂�����
			_no = ALL_OFF;
			_row = 0;
			_times = 0;
		}
		else
		{
			//���̕����̒����ݒ�
			_times = pgm_read_byte( (prog_uchar*)pattern+sizeof(ATM)*WIDE*_no+sizeof(ATM)*_row +1 );
			//_times = pattern[_no][_row].times;
		}
	}
	else
	{
		--_times;
	}

	int hiLow = pgm_read_byte( (prog_uchar*)pattern+sizeof(ATM)*WIDE*_no+sizeof(ATM)*_row );
	//int hiLow = pattern[_no][_row].hiLow;
	digitalWrite( _pin, hiLow );

	/*
	Serial.println("");
	Serial.print("times=");
	Serial.print( _times);
	Serial.print(" row=");
	Serial.print( _row);
	Serial.print(" hiLow=");
	Serial.println( hiLow);
	*/
}
