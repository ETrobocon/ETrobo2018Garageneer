#include <wiringPi.h>

/* インクルードガード */
#ifndef  MOTOR_CONTROLLER_CLASS
#define MOTOR_CONTROLLER_CLASS

// 右モータか左モータか
#define MOTOR_TYPE_RIGHT 0
#define MOTOR_TYPE_LEFT 1

// PWM制御のためのGPIOピン
#define RIGHT_MOTOR_PWM_PIN 18
#define LEFT_MOTOR_PWM_PIN 19

// モータドライバ入力（右）
#define RIGHT_MOTOR_ROTATE_PIN 14
#define RIGHT_MOTOR_INV_ROTATE_PIN 15

// モータドライバ入力（左）
#define LEFT_MOTOR_ROTATE_PIN 16
#define LEFT_MOTOR_INV_ROTATE_PIN 20

// PWM設定値
#define CLOCK_FOR_PWM 1000 //クロック
#define RANGE_FOR_PWM 100  //分解能

class MotorController
{
	// アトリビュート・属性
	private://非公開部分
		int m_motor_type; // 右モータか左モータか

	// コンストラクタ、デストラクタ
	public://公開部分
	// コンストラクタ
	MotorController(){}
	// コンストラクタ（引数にどちらのモータか整数型で指定）
	MotorController( int motor_type )
	{
		//wiringpiのセットアップ
		wiringPiSetupGpio();
		//引数のモータのタイプをメンバ変数に格納
		m_motor_type = motor_type;
		//右モータとして設定
		if ( m_motor_type == MOTOR_TYPE_RIGHT)
		{
			pinMode( RIGHT_MOTOR_PWM_PIN, PWM_OUTPUT);    //ピンをPWMモードに指定
			pinMode( RIGHT_MOTOR_ROTATE_PIN, OUTPUT);     //ピンを出力モードに指定
			pinMode( RIGHT_MOTOR_INV_ROTATE_PIN, OUTPUT); //ピンを出力モードに指定
		}
		//左モータとして設定
		else if ( m_motor_type == MOTOR_TYPE_LEFT)
		{
			pinMode( LEFT_MOTOR_PWM_PIN, PWM_OUTPUT);    //ピンをPWMモードに指定
			pinMode( LEFT_MOTOR_ROTATE_PIN, OUTPUT);     //ピンを出力モードに指定
			pinMode( LEFT_MOTOR_INV_ROTATE_PIN, OUTPUT); //ピンを出力モードに指定
		}

		//PWMの設定
		pwmSetMode( PWM_MODE_MS );//モード
		pwmSetClock( CLOCK_FOR_PWM );//クロック
		pwmSetRange( RANGE_FOR_PWM );//分解能

	}
	//デストラクタ
	~MotorController(){}

	// メソッド・関数
	public://公開部分
		void rotateMotor(int duty); // モータの回転
		void stopMotor(); // モータの停止
};
#endif