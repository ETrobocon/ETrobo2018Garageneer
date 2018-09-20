#include "stdafx.h"
#include "MS580314BA.h"

MS5803 sensor(ADDRESS_HIGH);
float atm;
#define BAR_CM	0.980665

void MS580314BA::ConfigParam(int dummy)
{
	sensor.reset();
	sensor.begin();
	atm = 0;
	atm = sensor.getPressure(ADC_4096);
}

void MS580314BA::Run()
{
	/*
	��C��1013.25 mbar =  1.01325 bar

	1 �H�w�C�� = 1 �d�ʃL���O�����������Z���`���[�g�� (kgf/cm2) = 98 066.5 Pa = 98.0665 kPa
	1g/cm2 = 98.0665 Pa = 0.000980665 bar =  0.980665 mbar

	1 �o�[�� (bar) = 100 000 Pa
	*/
	
	float cur = sensor.getPressure(ADC_4096);

	float d = cur - atm;
	int16_t cm = (int16_t)(d / BAR_CM);

	ValueIF out;
	out.value = cm;
    Rte_Write_out(out);

#if 0
	Serial.print("MS580314BA::Run() ");
	Serial.print(cm);
	Serial.println("");
#endif
}
