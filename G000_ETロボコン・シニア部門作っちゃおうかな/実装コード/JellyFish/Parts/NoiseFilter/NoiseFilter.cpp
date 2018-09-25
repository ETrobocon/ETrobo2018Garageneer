#include "stdafx.h"
#include "NoiseFilter.h"

void NoiseFilter::ConfigParam(int16_t limit)
{
	_limit = limit;
	_current = _lost = 0;
}

 void NoiseFilter::Run()
{
	ValueIF in;
    Rte_Read_in(in);

	//現在値と比較して範囲外なら
	if ((_current - _limit > in.value) || (_current + _limit < in.value))
	{
		//前回捨てた値の範囲外なら
		if ((_lost - _limit > in.value) || (_lost + _limit < in.value))
		{
			//捨てた値を更新
			_lost = in.value;
		}
		else
		{
			//現在値を捨てた値と入れ替えて更新
			_lost = _current;
			_current = in.value;
		}
	}
	//範囲内なら
	else
	{
		_current = in.value;
	}

	ValueIF out;
	out.value = _current;
    Rte_Write_out(out);
}
