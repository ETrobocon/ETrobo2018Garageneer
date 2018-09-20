#include "stdafx.h"
#include "Compass_HMC5883L.h"

void Compass_HMC5883L::ConfigParam(int dummy)
{
	compass.SetScale(1.3);
	compass.SetMeasurementMode(Measurement_Continuous);
}

void Compass_HMC5883L::Run()
{
	MagnetometerScaled scaled = compass.ReadScaledAxis();
	float heading = atan2(scaled.YAxis, scaled.XAxis);
	float declinationAngle = 0.0404;
	heading += declinationAngle;

	if (heading < 0)
	{
		heading += 2 * PI;
	}

	if (heading > 2*PI)
	{
		heading -= 2 * PI;
	}

	// Convert radians to degrees for readability.
	float headingDegrees = 180.0 *  heading / PI;

	ValueIF dir;
	dir.value = (int16_t)headingDegrees;
    Rte_Write_dir(dir);
}

