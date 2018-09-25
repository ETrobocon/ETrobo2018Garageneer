#include "stdafx.h"
#include "DigitalIn.h"

void DigitalIn::ConfigParam(uint8_t pin)
{
	_pin = pin;
	pinMode(pin, INPUT);
}

void DigitalIn::Run()
{
	HighLowIF out;
	out.value = digitalRead(_pin);
    Rte_Write_out(out);

}
