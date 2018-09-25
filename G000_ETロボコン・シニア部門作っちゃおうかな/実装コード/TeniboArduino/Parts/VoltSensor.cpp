#include "stdafx.h"
#include "VoltSensor.h"

void VoltSensor::ConfigParam(int pin, float K)
{
	_pin = pin;
	pinMode(_pin, INPUT);
	digitalWrite(_pin, HIGH);

	_K = K;
}
  void VoltSensor::Run()
{
	ValueIF volt;
	float v = analogRead(_pin);
	volt.value = (int16_t)(_K * v);
    Rte_Write_volt(volt);
}
