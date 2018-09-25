#include "stdafx.h"
#include "NaviSelevtor.h"

void NaviSelevtor::ConfigParam(int dummy)
{
	_deviceNo = 1;//ジャイロ
	_offsetDir = 0;
	_offsetRoll = 0;
	_offsetPitch = 0;
}

void NaviSelevtor::Run()
{
	ValueIF compass;
	PositionIF gyro;
	ValueIF depth;
	JellyFishNavi navi;

	if (
		(Rte_Read_compass(compass) == RTE_E_OK) &&
		(Rte_Read_gyro(gyro) == RTE_E_OK) &&
		(Rte_Read_depth(depth) == RTE_E_OK) &&
		(gyro.status == POS_WORKING)
		)
	{
		if (gyro.yaw < -179)
		{
			gyro.yaw += 360;
		}
		else if (gyro.yaw > 179)
		{
			gyro.yaw -= 360;
		}

		compass.value -= 180;


		switch (_deviceNo)
		{
		case 0:
		default:
			navi.dir = -compass.value;
			navi.roll = 0;
			navi.pitch = 0;
			break;
		case 1:
			navi.dir = -gyro.yaw;
			navi.roll = gyro.roll;
			navi.pitch = gyro.pitch;
			break;
		}

		navi.depth = depth.value;

		ValueIF reset;
		if (Rte_Receive_reset(reset) == RTE_E_OK)
		{
			_deviceNo = (uint8_t)reset.value;
			_offsetDir = navi.dir;
			_offsetRoll = navi.roll;
			_offsetPitch = navi.pitch;
		}

		//NAVIリセットのオフセット反映
		navi.dir -= _offsetDir;
		navi.roll -= _offsetRoll;
		navi.pitch -= _offsetPitch;

		if (navi.dir < -179)
		{
			navi.dir += 360;
		}
		else if (navi.dir > 179)
		{
			navi.dir -= 360;
		}

		Rte_Write_navi(navi);
	}
}
