#include "stdafx.h"
#include "AnalogIn.h"

void AnalogIn::ConfigParam(uint8_t pin)
{
	_pin = pin;

	Serial.begin(38400);
}

void AnalogIn::Run()
{
	ValueIF v;
	v.value = analogRead(_pin);
	Rte_Write_out(v);

	Serial.print("Analogin:");
	Serial.println( v.value );
}
