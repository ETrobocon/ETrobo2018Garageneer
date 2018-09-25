#include "stdafx.h"
#include "FloodSensor.h"

void FloodSensor::ConfigParam(int8_t pin)
{
	_pin = pin;
	pinMode( pin, INPUT );
}
  void FloodSensor::Run()
{
	ValueIF value;
	value.value = analogRead(_pin);
    Rte_Write_value(value);
}
