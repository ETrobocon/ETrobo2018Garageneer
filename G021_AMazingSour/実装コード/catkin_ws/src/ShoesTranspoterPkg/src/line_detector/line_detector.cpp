#include "./line_detector.hpp"

/******************************************************************************
 * 関数名 | void LightDetector::setLightSensor(int mode)                      *
 * 概要   | ライトセンサーの設定                                              *
 * 引数   | mode: 進行方向が前か後ろか                                        *
 * 戻り値 | なし                                                              *
 * 詳細   | 使用するライトセンサを設定する。                                  *
 ******************************************************************************/
void LineDetector::setLightSensor(int mode)
{	  
	/* ４つあるうちの二つのセンサを使用する。*/
	if (mode == 0)
	{
		/*前の場合の設定*/
		m_mode = 0;
	}
	else if (mode == 1) 
	{
		/*後ろの場合の設定*/
		m_mode = 1;
	}
	else
	{
		printf("mode error\n");
	}
}

/******************************************************************************
 * 関数名 | EN_LineSide LightDetector::getLineSide()                          *
 * 概要   | ライン向き検出関数　　                                            *
 * 引数   | なし                                                              *
 * 戻り値 | EN_LineSide: 左か右か真ん中か                                     *
 * 詳細   | 左右のカラーセンサのどちらがライン上にあるかを検知して返す        *
 ******************************************************************************/
EN_LineSide LineDetector::getLineSide()
{
	int right,left; //ライトセンサの値格納用変数（右、左）
	switch(m_mode){
		case 0: /*進行方向が前方*/
			left = m_light_controller[0].detectLine(0);
			right = m_light_controller[1].detectLine(1);
			break; 
		case 1: /*進行方向が後方*/
			right = m_light_controller[2].detectLine(2);
			left = m_light_controller[3].detectLine(3);
			break;
		default:
			printf("Invalid Mode\n");
			break;
	}
	/* 左が白、右が黒 */
	if(left == en_line_white && right == en_line_black)
	{
		return en_line_right;
	}
	/* 左が黒、右が白 */
	else if(left == en_line_black && right == en_line_white)
	{
		return en_line_left;
	}
	/* 中央（どちらも白またはどちらも黒） */
	else if(left == en_line_white && right == en_line_white)
	{
		return en_line_center;
	}
}
