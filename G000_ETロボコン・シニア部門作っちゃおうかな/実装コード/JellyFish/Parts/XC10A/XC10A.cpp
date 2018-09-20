#include "stdafx.h"
#include "XC10A.h"

void XC10A::ConfigParam(int8_t pin, int8_t deadZone, int16_t range)
{
	_servo.attach(pin);
	_deadZone = deadZone;
	_range = range;
}

#define half	500
#define T_N		1500

void XC10A::Run()
{
	ValueIF deadZone;
	if (Rte_Receive_deadZone(deadZone) == RTE_E_OK)
	{
		_deadZone = deadZone.value;
	}

	int ms = T_N;
	ValueIF in;
	if (Rte_Read_in(in) == RTE_E_OK)
	{
		if (in.value < 0)
		{
			in.value -= _deadZone;
		}
		else if( in.value > 0)
		{
			in.value += _deadZone;
		}
		int16_t sat = constrain(in.value, -100, 100);
		int16_t m = map(sat, -100, 100, -_range, _range);

		ms += ((half*(int)m) / 100);
	}
	_servo.writeMicroseconds(ms);
}
