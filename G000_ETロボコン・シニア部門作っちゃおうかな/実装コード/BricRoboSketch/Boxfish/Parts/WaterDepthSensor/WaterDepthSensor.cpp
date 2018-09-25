#include "stdafx.h"
#include "WaterDepthSensor.h"

void WaterDepthSensor::ConfigParam(int pin)
{
	_pin = pin;
}

//
#define CMK	0.15

void WaterDepthSensor::Run()
{
	ValueIF out;

	int row = analogRead(_pin);
	int rowLPF = LPF.Calc(row);

	int cm = (int)((float)(1023-rowLPF)*CMK);

	out.value = cm;
    Rte_Write_out(out);
}
