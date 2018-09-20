#include "stdafx.h"
#include "PidInt16.h"

void PidInt16::ConfigParam(int16_t Kp1, int16_t Kp2, int16_t Ki1, int16_t Ki2, int16_t Kd1, int16_t Kd2)
{
	_Kp1 = Kp1;
	_Kp2 = Kp2;
	_Ki1 = Ki1;
	_Ki2 = Ki2;
	_Kd1 = Kd1;
	_Kd2 = Kd2;
	_oldD = 0;// ‘O‰ñ‚Ì•Î·
	_I = 0;
}

int16_t PidInt16::Calc(int16_t target, int16_t current)
{
	int16_t D = current - target;  // •Î·
	_I += (D + _oldD) / 2;

	int16_t p = (D * _Kp1) / _Kp2;
	int16_t i = (_I * _Ki1) / _Ki2;
	int16_t d = ((D - _oldD) * _Kd1) / _Kd2;
	int16_t ret = p + i + d;
	_oldD = D;

	return ret;
}

void PidInt16::Reset()
{
	_oldD = 0;
	_I = 0;
}

void PidInt16::SetParam(int16_t p1, int16_t p2, int16_t i1, int16_t i2, int16_t d1, int16_t d2)
{
	_Kp1 = p1;
	_Kp2 = p2;
	_Ki1 = i1;
	_Ki2 = i2;
	_Kd1 = d1;
	_Kd2 = d2;
	_oldD = 0;// ‘O‰ñ‚Ì•Î·
	_I = 0;
}
