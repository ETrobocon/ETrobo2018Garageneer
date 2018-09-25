#include <stdio.h>
#include <wiringPi.h>

/* frontライトセンサ */
#define LightSensor_front 0
/* rearライトセンサ */
#define LightSensor_rear 1

/* 左前のライトセンサ */
#define Left_front_LightSensor 6
/* 右前のライトセンサ */
#define Right_front_LightSensor 5
/* 左後のライトセンサ */
#define Left_rear_LightSensor 13
/* 右後のライトセンサ */
#define Right_rear_LightSensor 21

/* ライトセンサの値（白色上or黒色上） */
enum EN_Line
{
	en_line_white,                        /* 白色(0) */
	en_line_black,                        /* 黒色(1) */
	en_line_error
};

/* クラス：ライトコントローラ（ライトセンサ管理部） */
class LightController
{
/* コンストラクタとデストラクタ */
public: //公開部分
	/* コンストラクタ */
	LightController(){}    
	/* コンストラクタ（引数にピン番号） */
	/* light_typeはLeft_front_LightSensor,Right_front_LightSensor,Left_rear_LightSensor,Right_rear_LightSensorのいずれか */
	LightController(int light_type)
	{
		/* wiringpiのセットアップ */
		wiringPiSetupGpio();
		/* ピンの設定 */
		pinMode(light_type, INPUT);
	}
	/* デストラクタ */
	~LightController(){}

/* メソッド */
public://公開部分
	EN_Line detectLine(int id);                 /* ライン検出 */
};
