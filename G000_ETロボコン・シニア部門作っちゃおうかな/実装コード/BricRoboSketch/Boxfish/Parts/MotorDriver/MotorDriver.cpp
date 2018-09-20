#include "stdafx.h"
#include "MotorDriver.h"

void MotorDriver::ConfigParam(int pin, float K)
{
	_pin = pin;
	_K = K;
}

void MotorDriver::Run()
{
	ValueIF in;
    Rte_Read_in(in);
	analogWrite( _pin, (int)(_K*(float)in.value) );
}
