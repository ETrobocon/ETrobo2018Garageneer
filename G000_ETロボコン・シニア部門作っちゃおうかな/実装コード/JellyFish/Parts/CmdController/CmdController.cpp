#include "stdafx.h"
#include "CmdController.h"

#define OFFLINE_WARNING	10

void CmdController::ConfigParam(int16_t flood, int16_t offlineJudgeCnt)
{
	_floodAlarm = flood;
	_offlineJudgeCnt = offlineJudgeCnt;
	_fishStatus = 0;
	_ctrl.dive = _ctrl.roll = _ctrl.forward = _ctrl.turn = 0;
	_stabi.mode = 0;
	_stabi.dir = 0;
	_stabi.depth = 0;
}

int8_t HiInt16(int16_t v)
{
	return v >> 8;
}

int8_t LowInt16(int16_t v)
{
	return v & 0xff;
}



void CmdController::RunRcv()
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
			_ctrl.dive = _ctrl.roll = _ctrl.forward = _ctrl.turn = 0;
			led.value = STATE_STANDBY;
			_stabi.mode = 0;
			break;
		case JFCMD_SET_FLOOD_ALARM:
			_floodAlarm = command.param1;
			led.value = ALL_ON;
			break;
		case JFCMD_RESET_NAVI:
			ValueIF resetNavi;
			resetNavi.value = command.param1;
			Rte_Send_resetNavi(resetNavi);
			led.value = ALL_ON;
			break;
		case JFCMD_CTL_DIRECT:
			_ctrl.dive = command.param1;
			_ctrl.roll = command.param2;
			_ctrl.forward = command.param3;
			_ctrl.turn = command.param4;
			led.value = STATE_CTL;
			break;
		case JFCMD_SAFETY_MODE:
			if (command.param1 == 1)
			{
				_fishStatus |= JFS_SAFETY_MODE;
			}
			else
			{
				_fishStatus &= ~JFS_SAFETY_MODE;
			}
			break;
		case JFCMD_STABI:
			_stabi.mode = command.param1;
			_stabi.dir = command.param2;
			_stabi.depth = command.param3;
			led.value = ALL_ON;
			break;
		case JFCMD_STABI_PID_DEP:
			PidParamIF pidParamDep;
			pidParamDep.p1 = command.param1;
			pidParamDep.p2 = 100;
			pidParamDep.i1 = command.param2;
			pidParamDep.i2 = 100;
			pidParamDep.d1 = command.param3;
			pidParamDep.d2 = 100;
			Rte_Send_pidParamDep(pidParamDep);
			led.value = ALL_ON;
			break;
		case JFCMD_STABI_PID_DIR:
			PidParamIF pidParamDir;
			pidParamDir.p1 = command.param1;
			pidParamDir.p2 = 100;
			pidParamDir.i1 = command.param2;
			pidParamDir.i2 = 100;
			pidParamDir.d1 = command.param3;
			pidParamDir.d2 = 100;
			Rte_Send_pidParamDir(pidParamDir);
			led.value = ALL_ON;
			break;
		case JFCMD_SET_DEAD_ZONE:
			ValueIF deadZoneDiveR;
			ValueIF deadZoneDiveL;
			ValueIF deadZoneRight;
			ValueIF deadZoneLeft;
			deadZoneDiveR.value = command.param1;
			deadZoneDiveL.value = command.param2;
			deadZoneRight.value = command.param3;
			deadZoneLeft.value = command.param4;
			Rte_Send_deadZoneDiveR(deadZoneDiveR);
			Rte_Send_deadZoneDiveL(deadZoneDiveL);
			Rte_Send_deadZoneRight(deadZoneRight);
			Rte_Send_deadZoneLeft(deadZoneLeft);
			led.value = ALL_ON;
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
		_ctrl.dive = -10;
		_ctrl.roll = _ctrl.forward = _ctrl.turn = 0;
		led.value = STATE_ERROR;
		_stabi.mode = 0;
	}

	//************** LED制御

	if (led.value != -1)
	{
		Rte_Send_led(led);
	}

	//*************** 姿勢制御

	Rte_Write_ctrl(_ctrl);
	Rte_Write_stabi(_stabi);
}
void CmdController::RunSend()
{
	JellyFishNaviIF navi;

	JellyFishNavi curNavi;
	Rte_Read_curNavi(curNavi);

	//*** バッテリ電圧 ***
	ValueIF battery;
	Rte_Read_battery(battery);

	navi.battery = battery.value;
	navi.curNavi = curNavi;
	navi.flood = _curFlood;
	navi.status = _fishStatus;
	Rte_Write_navi(navi);
}
