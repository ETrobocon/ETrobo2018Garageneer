#include "stdafx.h"
#include "ColorLedDriver.h"

void ColorLedDriver::ConfigParam(int8_t pinR, int8_t pinG, int8_t pinB)
{
	R.ConfigParam(pinR);
	G.ConfigParam(pinG);
	B.ConfigParam(pinB);
}

void ColorLedDriver::Run()
{
	ColorLedPattern pattern;
	if (Rte_Receive_pattern(pattern) != RTE_E_OK)
	{
		return;
	}

	if (pattern.color & LEDCOLOR_RED)
	{
		RO.Out(pattern.patternNo);
	}
	if (pattern.color & LEDCOLOR_GREEN)
	{
		GO.Out(pattern.patternNo);
	}
	if (pattern.color & LEDCOLOR_BLUE)
	{
		BO.Out(pattern.patternNo);
	}

	RunDrivers();
}
