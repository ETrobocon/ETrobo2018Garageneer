#include "stdafx.h"
#include "ServoMotor.h"

void ServoMotor::ConfigParam(int8_t pin, int8_t center, float K)
{
	_servo.attach(pin);
	_center = center;
	_K = K;
}

void ServoMotor::Run()
{
	ValueIF in;
    Rte_Read_in(in);
	_servo.write((int)(_K*in.value+_center));
}
