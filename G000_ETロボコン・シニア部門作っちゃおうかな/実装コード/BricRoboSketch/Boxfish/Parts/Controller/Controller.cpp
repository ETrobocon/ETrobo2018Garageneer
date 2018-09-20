#include "stdafx.h"
#include "Controller.h"

#define ALARM_JETPOWER	50
#define ALARM_PECFIN	30
#define ALARM_TAILFIN	60

void Controller::ConfigParam(int16_t pecOff, int16_t tailOff, int16_t flood, int16_t offlineJudgeCnt)
{
	_pecOffset = pecOff;
	_tailOffset = tailOff;
	_floodAlarm = flood;
}

void Controller::Run()
{
	CommandIF command;
    if( Rte_Receive_command(command) == RTE_E_OK )
	{
		switch( command.cmd )
		{
		case CMD_STOP:
			{
				_jetPower = 0;
				_pecFin = 0;
				_tailFin = 0;
			}
			break;

		case CMD_SET_FIN_OFFSET:
			{
				_pecOffset = command.param1;
				_tailOffset = command.param2;
			}
			break;

		case CMD_SET_FLOOD_ALARM:
			{
				_floodAlarm = command.param1;
			}
			break;

		case CMD_SET_LIGHT:
			{
				ValueIF ledLight;
				ledLight.value = command.param1;
				Rte_Send_ledLight(ledLight);
			}
			break;

		case CMD_SET_STATUS_LIGHT:
			{
				ValueIF ledPattern;
				ledPattern.value = command.param1;
				Rte_Send_ledPattern(ledPattern);
			}
			break;

		case CMD_CTL:
			{
				_jetPower = command.param1;
				_pecFin = command.param2;
				_tailFin = command.param3;
			}
			break;
		}
	}
	else
	{
		//í êMÇ™ìrê‚Ç¶ÇΩèÍçá
		///@@@
	}

	ValueIF floodAlarm;
	floodAlarm.value = 0;
    if( Rte_Receive_floodAlarm(floodAlarm) == RTE_E_OK )
	{
		//êZêÖÇµÇΩÇÁóLñ≥ÇÇ¢ÇÌÇ≥Ç∏ïÇè„
		_jetPower = ALARM_JETPOWER;
		_pecFin = ALARM_PECFIN;
		_tailFin = ALARM_TAILFIN;
	}

	ValueIF pec, tail, jet;
	pec.value = _pecFin+_pecOffset;
	tail.value = _tailFin+_tailOffset;
	jet.value = _jetPower;
    Rte_Write_pecFin(pec);
    Rte_Write_tailFin(tail);
    Rte_Write_jetPower(jet);

	ValueIF waterDepth;
    Rte_Read_waterDepth(waterDepth);

	ValueIF waterPressure;
    Rte_Read_waterPressure(waterPressure);

	PositionIF position;
    Rte_Read_position(position);


	NaviIF navi;
	navi.pecFin = pec.value;
	navi.jetPower = jet.value;
	navi.tailFin = tail.value;
	navi.waterPressure = waterPressure.value;
	navi.bottomDistance = waterDepth.value;
	navi.position = position;
	navi.flood = floodAlarm.value;
	Rte_Write_navi(navi);

}
