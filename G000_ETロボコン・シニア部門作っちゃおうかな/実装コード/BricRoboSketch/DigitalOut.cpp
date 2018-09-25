
#include "stdafx.h"
#include "DigitalOut.h"

void DigitalOut::ConfigParam(uint8_t pin)
{
	_pin = pin;
	pinMode(_pin, OUTPUT);
}

void DigitalOut::Run()
{
  HighLowIF sw;
  Rte_Read_in(sw);
  digitalWrite(_pin, sw.value);
}



