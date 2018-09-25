#include "stdafx.h"
#include "Battery.h"

void Battery::ConfigParam(int8_t pin, float lowV, float highV)
{
	_pin = pin;
	_K = (lowV + highV) / lowV * 0.92;//Т▓Ро
}
void Battery::Run()
{
	int R = analogRead(_pin);
	double M = map(R, 0, 1023, 0, 500);
	ValueIF v;
	v.value = (int)(M * _K);
    Rte_Write_v(v);
}
