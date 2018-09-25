#include "stdafx.h"
#include "HighLowWave.h"

void HighLowWave::ConfigParam(uint8_t lastState)
{
	_lastState = lastState;
}
void HighLowWave::Run()
{
        HighLowIF sw;
        _lastState = (_lastState == LOW) ? HIGH : LOW;
        sw.value = _lastState;
        Rte_Write_out(sw);
}



