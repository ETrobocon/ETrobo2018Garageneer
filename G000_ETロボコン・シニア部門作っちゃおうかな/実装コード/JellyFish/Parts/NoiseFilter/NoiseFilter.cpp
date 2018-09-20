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

	//���ݒl�Ɣ�r���Ĕ͈͊O�Ȃ�
	if ((_current - _limit > in.value) || (_current + _limit < in.value))
	{
		//�O��̂Ă��l�͈̔͊O�Ȃ�
		if ((_lost - _limit > in.value) || (_lost + _limit < in.value))
		{
			//�̂Ă��l���X�V
			_lost = in.value;
		}
		else
		{
			//���ݒl���̂Ă��l�Ɠ���ւ��čX�V
			_lost = _current;
			_current = in.value;
		}
	}
	//�͈͓��Ȃ�
	else
	{
		_current = in.value;
	}

	ValueIF out;
	out.value = _current;
    Rte_Write_out(out);
}
