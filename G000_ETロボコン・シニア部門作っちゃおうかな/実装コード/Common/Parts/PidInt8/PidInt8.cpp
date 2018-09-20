#include "stdafx.h"
#include "PidInt8.h"

void PidInt8::ConfigParam(int8_t Kp1, int8_t Kp2, int8_t Ki1, int8_t Ki2, int8_t Kd1, int8_t Kd2)
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

void PidInt8::SetParam(int8_t p1, int8_t p2, int8_t i1, int8_t i2, int8_t d1, int8_t d2)
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


int16_t PidInt8::Calc(short target, short current)
{
	int16_t D = ((int16_t)current - (int16_t)target);  // •Î·
	_I += (D + _oldD) / 2;

	int16_t p = (D * (int16_t)_Kp1) / (int16_t)_Kp2;
	int16_t i = (_I * (int16_t)_Ki1) / (int16_t)_Ki2;
	int16_t d = ((D - _oldD) * (int16_t)_Kd1) / (int16_t)_Kd2;
	int16_t ret = p + i + d;
	_oldD = D;

#if 0
	Serial.print("PidInt8::Calc() target:");//@@@
	Serial.print(target);//@@@
	Serial.print(" current:");//@@@
	Serial.print(current);//@@@
	Serial.print(" D:");//@@@
	Serial.print(D);//@@@
	Serial.print(" p:");//@@@
	Serial.print(p);//@@@
	Serial.print(" i:");//@@@
	Serial.print(i);//@@@
	Serial.print(" d:");//@@@
	Serial.print(d);//@@@
	Serial.print(" ret:");//@@@
	Serial.print(ret);//@@@
	Serial.println("");//@@@
#endif

	return ret;
}

void PidInt8::Reset()
{
	_oldD = 0;
	_I = 0;
}
