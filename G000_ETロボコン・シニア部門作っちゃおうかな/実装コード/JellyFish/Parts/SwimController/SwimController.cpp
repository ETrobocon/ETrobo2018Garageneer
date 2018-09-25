#include "stdafx.h"
#include "SwimController.h"

void balanceTurn(int16_t& left, int16_t& right, int16_t forward, int16_t turn)
{
	int16_t L = forward + turn;
	int16_t R = forward - turn;
	if (L > 100)
	{
		R -= L - 100;
	}
	else if (R > 100)
	{
		L -= R - 100;
	}
	else if (L < -100)
	{
		R -= L + 100;
	}
	else if (R < -100)
	{
		L -= R + 100;
	}
	left = constrain(L, -100, 100);
	right = constrain(R, -100, 100);
}

void SwimController::ConfigParam(int dummy)
{
	_keepDir = 0;
	_keepDepth = 0;
}

bool WithIn(int16_t value, int16_t min, int16_t max)
{
	if (value < min || value > max)
	{
		return false;
	}
	else
	{
		return true;
	}
}

#define TURN	ctrl.turn
#define ROLL	ctrl.roll

void SwimController::Run()
{
	SwimControllerIF ctrl;
	ValueIF diveL;
	ValueIF diveR;
	ValueIF right;
	ValueIF left;
	StabiIF stabi;
	PidParamIF pidParamDep;
	PidParamIF pidParamDir;
	JellyFishNavi navi;

	if (Rte_Receive_pidParamDep(pidParamDep) == RTE_E_OK)
	{
		PID_DIVE.SetParam(
			pidParamDep.p1, pidParamDep.p2,
			pidParamDep.i1, pidParamDep.i2,
			pidParamDep.d1, pidParamDep.d2
		);
	}

	if (Rte_Receive_pidParamDir(pidParamDir) == RTE_E_OK)
	{
		PID_DIR.SetParam(
			pidParamDir.p1, pidParamDir.p2,
			pidParamDir.i1, pidParamDir.i2,
			pidParamDir.d1, pidParamDir.d2
		);
	}

	if ((Rte_Read_ctrl(ctrl) != RTE_E_OK)
		|| (Rte_Read_navi(navi) != RTE_E_OK)
		|| (Rte_Read_stabi(stabi) != RTE_E_OK)
		)
	{
		//���͂�����Ȃ���΃��[�^�[���񂳂Ȃ�
		//�댯����̂��߂�Zero
		diveL.value = 0;
		diveR.value = 0;
		right.value = 0;
		left.value = 0;
	}
	else
	{
		Rte_Write_curNavi(navi);//���M����̂̓I�t�Z�b�g�����ς�

		//�����X�^�r
		if ((stabi.mode & STABIMODE_DIR) != 0 && WithIn(TURN,-1,+1))
		{
			int16_t turn;
			int16_t target;

			if ((stabi.mode & STABIMODE_TARGET) != 0)
			{
				//�]���͎̂w�����
				target = stabi.dir;
			}
			else
			{
				//�]���̂͑O��܂Ŋo���Ă�������
				target = _keepDir;
			}

			//180�x�ȏ�͔��Ή��̂ق����߂�
			int16_t delta = target - navi.dir;
			if (delta >= 180)
			{
				delta -= 360;
			}
			else if (delta <= -180)
			{
				delta += 360;
			}

			//�����̍����Ȃ��Ȃ�悤��PID����
			TURN = PID_DIR.Calc(delta, 0);
			
			//LR�ɕ��z
			balanceTurn(left.value, right.value, ctrl.forward, TURN);
		}
		else
		{
			balanceTurn(left.value, right.value, ctrl.forward, TURN);
			_keepDir = navi.dir;
		}

		//�[�x�X�^�r
		if ((stabi.mode & STABIMODE_DIVE) != 0 && WithIn(ctrl.dive, -1, +1))
		{
			if ((stabi.mode & STABIMODE_TARGET) != 0)
			{
				//���݂̐[���ƁA�w��[���̍���PID����
				diveL.value = diveR.value = -PID_DIVE.Calc(stabi.depth, navi.depth);
			}
			else
			{
				//���݂̐[���ƁA���O�܂Ŋo���Ă����[���̍���PID����
				diveL.value = diveR.value = -PID_DIVE.Calc(_keepDepth, navi.depth);
			}
		}
		else
		{
			diveL.value = diveR.value  = -ctrl.dive;
			_keepDepth = navi.depth;//���݂̐[�����X�V
		}

		//Roll�ō��E����
		diveL.value = constrain(diveL.value + ROLL, -100, 100);
		diveR.value = constrain(diveR.value - ROLL, -100, 100);


		//�f�o�b�O�p
		//curNavi.depth = 100;// compass.value;
		//Rte_Write_curNavi(curNavi);
	}

	Rte_Write_diveL(diveL);
	Rte_Write_diveR(diveR);
	Rte_Write_right(right);
	Rte_Write_left(left);
}

