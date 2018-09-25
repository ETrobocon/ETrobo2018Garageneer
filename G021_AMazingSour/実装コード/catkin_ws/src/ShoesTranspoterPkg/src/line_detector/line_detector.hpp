#include "../light_controller/light_controller.hpp"

enum EN_LineSide
{
	en_line_right,                         /* 右側(0) */
	en_line_left,                          /* 左側(1) */
	en_line_center                        /* 中央(2) */
};

class LineDetector
{
/* アトリビュート */
private:  //非公開部分
	int m_mode;	/* 運搬車の進行方向（0：前進,1：後退） */
	LightController m_light_controller[4]; /* ライトコントローラ */

/* コンストラクタとデストラクタ */
public: //公開部分
	/* コンストラクタ */
	LineDetector()
	{
		/* ライトコントローラの設定 */
		m_light_controller[0] = LightController(Left_front_LightSensor);
		m_light_controller[1] = LightController(Right_front_LightSensor);
		m_light_controller[2] = LightController(Left_rear_LightSensor);
		m_light_controller[3] = LightController(Right_rear_LightSensor);
	}
	/* デストラクタ */
	~LineDetector(){}

/* メソッド */
public://公開部分
	void setLightSensor(int mode); /* 使用するライトセンサーをセットする。*/
	EN_LineSide getLineSide(); /* Lineがどっち向きにあるかを見つける*/
};