#include "stdafx.h"
#include "FloodSensor.h"

void FloodSensor::ConfigParam(int thresh, int pin)
{
	_pin = pin;
	_thresh = thresh;
}
  void FloodSensor::Run()
{
	int raw = analogRead(_pin);
	if( raw < _thresh )
	{
		ValueIF alert;
		alert.value = raw;
		Rte_Send_alert(alert);
	}
}
