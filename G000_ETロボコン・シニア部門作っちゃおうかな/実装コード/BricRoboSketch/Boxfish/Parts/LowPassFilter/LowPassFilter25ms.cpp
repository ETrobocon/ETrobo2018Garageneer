#include "stdafx.h"
#include "LowPassFilter25ms.h"

LowPassFilter25ms::LowPassFilter25ms()
{
	_pre1 = _pre2 = 0.0;
}

#define A1	1.614837
#define A2	-0.635305
#define B0	0.005117
#define B1	0.010234
#define B2	0.005117

int LowPassFilter25ms::Calc(int inp)
{
	float reg = inp + A1*_pre1 + A2*_pre2;

	int result = (int)(B0*reg + B1*_pre1 + B2*_pre2);

	_pre2 = _pre1;
	_pre1 = reg;

	return result;
}
