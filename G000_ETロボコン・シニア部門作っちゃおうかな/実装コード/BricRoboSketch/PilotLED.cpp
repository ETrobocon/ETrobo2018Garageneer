#include "stdafx.h"
#include "PilotLED.h"

void PilotLED::ConfigParam(int pin)
{
	_pin = pin;
	pinMode(_pin, OUTPUT);
}

void PilotLED::Run()
{
	_on = !_on;
	if( _on )
	{
		digitalWrite( _pin, HIGH );
	}
	else
	{
		digitalWrite( _pin, LOW );
	}
}
