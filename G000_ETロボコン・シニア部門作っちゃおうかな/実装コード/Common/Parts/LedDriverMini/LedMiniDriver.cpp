#define __PROG_TYPES_COMPAT__	//Arduino IDE 1.7.9ではprog_ucharを使うにはavr/pgmspace.hをincludeする前に、この定義が必要

#include "stdafx.h"
#include "LedMiniDriver.h"

void LedMiniDriver::ConfigParam(int8_t pin)
{
	_pin = pin;
	pinMode(_pin, OUTPUT);

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
	prog_uchar hiLow;	//0=消灯、1=転倒、0xff=終端
	prog_uchar times;	//維持する回数、0xff=終端
} ATM;

#define WIDE	10

const PROGMEM ATM pattern[][WIDE] =	//Arduino IDE 1.7.9 ではconstをつけないとコンパイルできない
{
	{	//10 ALL_OFF
		0,	1,
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
	},

	{	//12 STATE_STANDBY
		1,	1,
		0,	199,
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
	},
	{	//14 STATE_ERROR
		1,	12,
		0,	12,
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
	},
	{	//16 STATE_AUTO
		1,	1,
		0,	9,
		1,	1,
		0,	89,
		0xff,	0xff,
	}
};

void LedMiniDriver::Run()
{
	ValueIF patternNo;
	if (Rte_Receive_patternNo(patternNo) == RTE_E_OK)
	{
		if (_no != patternNo.value)
		{
			_no = patternNo.value;
			_row = 0;
			_times = pgm_read_byte((prog_uchar*)pattern + sizeof(ATM)*WIDE*_no + sizeof(ATM)*_row + 1);
			//_times = pattern[_no][_row].times;
		}
	}

	if (_times == 0)
	{
		++_row;
		uint8_t hiLow = pgm_read_byte((prog_uchar*)pattern + sizeof(ATM)*WIDE*_no + sizeof(ATM)*_row);
		if (hiLow == 0xff)
		{
			//符号の先頭に戻る
			_row = 0;
			_times = pgm_read_byte((prog_uchar*)pattern + sizeof(ATM)*WIDE*_no + sizeof(ATM)*_row + 1);
			//_times = pattern[_no][_row].times;
		}
		else if (hiLow == 0xfe)
		{
			//最後の符号で足踏みさせる
			_no = ALL_OFF;
			_row = 0;
			_times = 0;
		}
		else
		{
			//次の符号の長さ設定
			_times = pgm_read_byte((prog_uchar*)pattern + sizeof(ATM)*WIDE*_no + sizeof(ATM)*_row + 1);
			//_times = pattern[_no][_row].times;
		}
	}
	else
	{
		--_times;
	}

	int hiLow = pgm_read_byte((prog_uchar*)pattern + sizeof(ATM)*WIDE*_no + sizeof(ATM)*_row);
	//int hiLow = pattern[_no][_row].hiLow;
	digitalWrite(_pin, hiLow);
}
