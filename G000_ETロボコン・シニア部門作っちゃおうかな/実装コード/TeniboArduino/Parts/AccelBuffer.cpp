#include "stdafx.h"
#include "AccelBuffer.h"

void AccelBuffer::ConfigParam(int InitValue, int SleepCnt, int Range)
{
	_current = InitValue;
	_sleepCnt = SleepCnt;
	_range = Range;
	_sleepCur = 0;
}
void AccelBuffer::Run()
{
	ValueIF in;
	Rte_Read_in(in);


	int newValue = constrain(in.value, _current - _range, _current + _range);
	if (newValue*_current >= 0)
	{
		if (_sleepCur > 0)
		{
			--_sleepCur;
		}
		else
		{
			_current = newValue;
		}
	}
	else
	{
		_sleepCur = _sleepCnt;
		_current = 0;
	}


	ValueIF out;
	out.value = _current;
	Rte_Write_out(out);
}
