#include "stdafx.h"
#include "DigitalInPullup.h"

void DigitalInPullup::ConfigParam(uint8_t pin)
{
	_pin = pin;
	pinMode(pin, INPUT_PULLUP);
}
  void DigitalInPullup::Run()
{
	HighLowIF out;
	out.value = digitalRead(_pin);
	Rte_Write_out(out);
  }
