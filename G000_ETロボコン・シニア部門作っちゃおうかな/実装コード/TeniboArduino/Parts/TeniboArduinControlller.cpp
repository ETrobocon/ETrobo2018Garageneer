#include "stdafx.h"
#include "TeniboArduinControlller.h"

#define OFFLINE_WARNING	10

TeniboArduinControlller::TeniboArduinControlller()
{
	_accel.value = 0;
	_ballPick.value = HIGH;
	_frontLed.value = STATE_ERROR;
	_steer1.value = 0;
	_steer2.value = 0;
}

void TeniboArduinControlller::Run()
{
	ValueIF battery;
	TeniboCommandIF command;
	TeniboNaviIF navi;

	//�Z���T�[�ޓǂݎ��
	Rte_Read_battery(battery);

	//�R�}���h��M
	if (Rte_Receive_command(command) == RTE_E_OK) 
	{
		switch (command.cmd)
		{
		case TC_STOP:
			_frontLed.value = STATE_STANDBY;
			_steer1.value = _steer2.value = 0;
			_accel.value = 0;
			_ballPick.value = HIGH;
			break;

		case TC_MODE:
			_frontLed.value = command.param1 ? STATE_AUTO : STATE_CTL;
			break;

		case TC_DRIVE:
			_steer1.value = _steer2.value = command.param1;
			_accel.value = command.param2;
			break;

		case TC_LIGHT:
			_frontLed.value = command.param1 ? ALL_ON : ALL_OFF;
			break;

		case TC_BALLPICK:
			_ballPick.value = command.param1 == 0 ? HIGH : LOW;
			break;
		}

		_offlineCount = 0;
	}
	else
	{
		++_offlineCount;
		if (_offlineCount >= OFFLINE_WARNING)
		{
			_frontLed.value = STATE_ERROR;
		}
	}

	//�A�N�`���G�[�^�w��
	Rte_Send_frontLed(_frontLed);
	Rte_Write_steer1(_steer1);
	Rte_Write_steer2(_steer2);
	Rte_Write_accel(_accel);
	Rte_Write_ballPick(_ballPick);

	//��Ԓʒm]
	navi.battery = battery.value;
	navi.status = TS_OK;
	Rte_Write_navi(navi);

}
