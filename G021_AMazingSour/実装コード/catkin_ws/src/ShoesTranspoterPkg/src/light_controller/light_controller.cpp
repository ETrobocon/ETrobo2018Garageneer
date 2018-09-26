#include "light_controller.hpp"


/******************************************************************************
 * 関数名 | EN_Line LightController::detectLine(int id)                       *
 * 概要   | ラインの検出                                                      *
 * 引数   | 使用するセンサのID                                                *
 * 戻り値 | EN_Line():黒か白                                                  *
 * 詳細   | ライトセンサがライン（黒色）上にあるか否かを判定                  *
 ******************************************************************************/
EN_Line LightController::detectLine(int id)
{
	int i = 10; //出力用変数
	int no = 10;//ピン番号格納用変数
	
	/* sensor choice　*/
	/* 使用するライトセンサに応じて読み込むピン番号を決定 */
	switch(id){
		case 0:
			no = Left_front_LightSensor;
			break; 
		case 1:
			no = Right_front_LightSensor;
			break;
		case 2:
			no = Left_rear_LightSensor;
			break;
		case 3:
			no = Right_rear_LightSensor;
			break;
		default:
			printf("lightsensor is no choise \n");
			return en_line_error;
	}

	// noのピンのセンサを読み込む
	i = digitalRead(no);
	
	// ライトセンサが白色の上のとき
	if(i == en_line_white &&  i != en_line_black)
	{
		return en_line_white;
	}
	// それ以外は黒とする
	return en_line_black;
}

