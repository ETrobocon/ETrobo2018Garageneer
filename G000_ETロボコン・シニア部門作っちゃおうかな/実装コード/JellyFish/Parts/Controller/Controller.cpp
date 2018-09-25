#include "stdafx.h"
#include "Controller.h"

#define OFFLINE_WARNING	10

void Controller::ConfigParam(int16_t flood, int16_t offlineJudgeCnt)
{
	_floodAlarm = flood;
	_offlineJudgeCnt = offlineJudgeCnt;
	_swimCmd.mode = SM_OFF;
	_swimCmd.navi.dir = _swimCmd.navi.depth = _swimCmd.navi.pitch = _swimCmd.navi.roll = 0;
	_fishStatus = 0;
}

void Controller::RunRcv()
{
	ValueIF led;
	led.value = -1;

	_fishStatus &= ~JFS_EMERGENCY;

	JellyFishCommandIF command;
	if (Rte_Receive_command(command) == RTE_E_OK)
	{
		switch (command.cmd)
		{
		case JFCMD_STOP:
			_swimCmd.mode = SM_OFF;
			_swimCmd.navi.dir = _swimCmd.navi.depth = _swimCmd.navi.pitch = _swimCmd.navi.roll = 0;
			led.value = STATE_STANDBY;
			break;
		case JFCMD_SET_FLOOD_ALARM:
			_floodAlarm = command.param1;
			break;
		case JFCMD_RESET_NAVI:
			_swimCmd.mode = SM_RESET_NAVI;
			led.value = ALL_ON;
			break;
		case JFCMD_RESET_DIR:
			_swimCmd.mode = SM_RESET_DIR;
			led.value = ALL_ON;
			break;
		case JFCMD_CTL:
			_swimCmd.mode = SM_NAVI;
			_swimCmd.navi.dir = command.param1;
			_swimCmd.navi.depth = command.param2;
			_swimCmd.navi.pitch = command.param3;
			_swimCmd.navi.roll = command.param4;
			led.value = STATE_CTL;
			break;
		case JFCMD_SAFETY_MODE:
			if (_fishStatus & JFS_SAFETY_MODE != 0)
			{
				_fishStatus &= ~JFS_SAFETY_MODE;
			}
			else
			{
				_fishStatus |= JFS_SAFETY_MODE;
			}
			break;
		}
		_offlineCnt = 0;//通信回復
	}
	else
	{
		++_offlineCnt;
		if (_offlineCnt >= OFFLINE_WARNING)
		{
			//通信が切れたら
			led.value = STATE_ERROR;
		}
	}

	//************ 浸水したら緊急モード

	ValueIF floodAlarm;
	Rte_Read_floodAlarm(floodAlarm);
	_curFlood = floodAlarm.value;
	if (_fishStatus & JFS_SAFETY_MODE)
	{
		if (floodAlarm.value <= _floodAlarm)
		{
			//浸水したら有無をいわさず浮上
			_fishStatus |= JFS_EMERGENCY;
		}
	}

	//************ 緊急モードの動作
	
	if (_fishStatus & JFS_EMERGENCY)
	{
		_swimCmd.mode = SM_EMERGENCY;
		led.value = STATE_ERROR;
	}

	//************** LED制御
	
	if (led.value != -1)
	{
		Rte_Send_led(led);
	}

	//*************** 姿勢制御

	Rte_Write_cmd(_swimCmd);

}


void Controller::RunSend()
{
	JellyFishNaviIF navi;

	JellyFishNavi curNavi;
	Rte_Read_curNavi(curNavi);

	navi.curNavi = curNavi;
	navi.flood = _curFlood;
	navi.status = _fishStatus;
	Rte_Write_navi(navi);

}
