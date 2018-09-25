#include "stdafx.h"
#include "WaterPressureSensor.h"

void WaterPressureSensor::ConfigParam(int pin)
{
	_pin = pin;
}

int Adc2Dist2(int adc)
{
	double x = (double)adc;
	double icm = (5E-10)*x*x*x - (3E-07)*x*x + 0.0001*x + 0.0003;
	double cm = 1.0 / icm;
	return cm;
}

void WaterPressureSensor::Run()
{
	ValueIF out;

	int raw = analogRead(_pin);
	int y = Adc2Dist2(raw);
	int rowLPF = LPF.Calc(y);

	out.value = rowLPF;
	Rte_Write_out(out);
}
