#include "stdafx.h"
#include "ToF_VL53L0X.h"

void ToF_VL53L0X::ConfigParam(int IsLongRange, int speed)
{
	Wire.begin();

	sensor.init();
	sensor.setTimeout(500);

	if (IsLongRange != 0)
	{
		// lower the return signal rate limit (default is 0.25 MCPS)
		sensor.setSignalRateLimit(0.1);
		// increase laser pulse periods (defaults are 14 and 10 PCLKs)
		sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
		sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
	}
	sensor.startContinuous();
	//sensor.setMeasurementTimingBudget(speed * 1000);
}

void ToF_VL53L0X::Run()
{
	ValueIF out;
	//out.value = sensor.readRangeSingleMillimeters();
	out.value = sensor.readRangeContinuousMillimeters();
    Rte_Write_out(out);
}
