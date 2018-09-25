#include "stdafx.h"
#include "EscDriver.h"

void EscDriver::ConfigParam(int8_t pin, int16_t revise, int16_t plusePower, int8_t counter)
{
	_servo.attach(pin);
	_revise = revise;
	_plusePower = plusePower;
	_counter = counter;
}

#define half	500
#define T_N		1500
#define _range	30

void EscDriver::Run()
{
	int ms = T_N;
	ValueIF in;
	if (Rte_Read_in(in) == RTE_E_OK)
	{
		int16_t sat = constrain(in.value, -100, 100);
		int16_t m = map(sat, -100, 100, -_range, _range);

		ms += _revise*((half*(int)m) / 100);
	}
	_servo.writeMicroseconds(ms);
}

#if 0
void EscDriver::Run()
{
	if (++_counter > 100)
	{
		_counter = 0;
	}

	int ms = T_N;
	ValueIF in;
	if (Rte_Read_in(in) == RTE_E_OK)
	{
		in.value = 8;

		if ((in.value > _counter) || (in.value < -_counter))
		{
			ms += _revise*((half*(int)_plusePower) / RANGE);
#if 0
			Serial.print("EscDriver::Run ");//@@@
			Serial.println(ms);//@@@
#endif
		}
		else
		{
		}
	}
	_servo.writeMicroseconds(ms);
}
#endif