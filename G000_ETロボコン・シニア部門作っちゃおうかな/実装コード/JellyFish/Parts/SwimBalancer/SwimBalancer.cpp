#include "stdafx.h"
#include "SwimBalancer.h"

void SwimBalancer::ConfigParam(int16_t emergencyPower)
{
	_emergencyPower = emergencyPower;
	_offsetDir = 0;
	_offsetDepth = 0;
	_offsetRoll = 0;
	_offsetPitch = 0;
}

void SwimBalancer::Run()
{
	SwimCmd cmd;
	ValueIF front;
	ValueIF rear;
	ValueIF right;
	ValueIF left;
	ValueIF depth;
	PositionIF pos;

	//危険回避のためにZero
	front.value = 0;
	rear.value = 0;
	right.value = 0;
	left.value = 0;

	if ((Rte_Read_cmd(cmd) != RTE_E_OK) 
		|| (Rte_Read_depth(depth) != RTE_E_OK)
		|| (Rte_Read_pos(pos) != RTE_E_OK)
		|| (pos.status != POS_WORKING)
		)
	{
		//入力が揃わなければモーターを回さない
	}
	else
	{
		//yawの360度修正
		if (pos.yaw < -179)
		{
			pos.yaw += 360;
		}
		else if (pos.yaw > 179)
		{
			pos.yaw -= 360;
		}

#if 0
		cmd.mode = SM_NAVI;//@@@
		Serial.print("pos: yaw:");//@@@
		Serial.print(pos.yaw);//@@@
		Serial.print(" roll:");//@@@
		Serial.print(pos.roll);//@@@
		Serial.print(" pitch:");//@@@
		Serial.print(pos.pitch);//@@@
		Serial.print(" depth:");//@@@
		Serial.println(depth.value);//@@@
#endif

		//NAVI値はリセットしたときの値をオフセットとして反映
		JellyFishNavi curNavi;
		curNavi.dir = pos.yaw - _offsetDir;
		curNavi.roll = pos.roll - _offsetRoll;
		curNavi.pitch = pos.pitch - _offsetPitch;
		curNavi.depth = depth.value - _offsetDepth;
		Rte_Write_curNavi(curNavi);//送信するのはオフセット調整済み

//		cmd.mode = SM_NAVI;//@@@


		switch (cmd.mode)
		{
		case SM_OFF:
		default:
			break;

		case SM_NAVI:
		{
			//yawを45度回転させるので、影響を受けるroll, pitchを45度回転
#define RT	77	// =1/sqrt(2)
			int16_t roll45 = ((curNavi.roll - curNavi.pitch) * RT) / 100;
			int16_t pitch45 = ((curNavi.roll + curNavi.pitch) * RT) / 100;

			int16_t Vyaw = PID_DIR.Calc(cmd.navi.dir, curNavi.dir);
			int16_t Vroll = PID_ROLL.Calc(cmd.navi.roll, roll45);
			int16_t Vpitch = PID_PITCH.Calc(cmd.navi.pitch, pitch45);
			int16_t Vthrottle = PID_DEPTH.Calc(cmd.navi.depth, curNavi.depth);

#if 0
			Serial.print("PID: yaw:");//@@@
			Serial.print(Vyaw);//@@@
			Serial.print(" roll:");//@@@
			Serial.print(Vroll);//@@@
			Serial.print(" pitch:");//@@@
			Serial.print(Vpitch);//@@@
			Serial.print(" throttle:");//@@@
			Serial.println(Vthrottle);//@@@
#endif

			front.value = (Vthrottle + Vyaw + 2 * Vpitch) / 4;
			rear.value = (Vthrottle + Vyaw - 2 * Vpitch) / 4;
			right.value = (Vthrottle - Vyaw + 2 * Vroll) / 4;
			left.value  = (Vthrottle - Vyaw - 2 * Vroll) / 4;
		}
			break;

		case SM_EMERGENCY:
			front.value = _emergencyPower;
			rear.value = _emergencyPower;
			right.value = _emergencyPower;
			left.value = _emergencyPower;
			break;

		case SM_RESET_NAVI:
			_offsetDir = curNavi.dir;
			_offsetDepth = curNavi.depth;
			_offsetRoll = curNavi.roll;
			_offsetPitch = curNavi.pitch;
			break;

		case SM_RESET_DIR:
			_offsetDir = curNavi.dir;

		}

	}

#if 0
	Serial.print("PWM: front");//@@@
	Serial.print(front.value);//@@@
	Serial.print(" rear:");//@@@
	Serial.print(rear.value);//@@@
	Serial.print(" right:");//@@@
	Serial.print(right.value);//@@@
	Serial.print(" left:");//@@@
	Serial.println(left.value);//@@@
#endif

	Rte_Write_front(front);
	Rte_Write_rear(rear);
	Rte_Write_right(right);
	Rte_Write_left(left);
}
