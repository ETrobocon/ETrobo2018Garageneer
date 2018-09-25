#include "motor_controller.hpp"
/******************************************************************************
 * 関数名 | void rotateMotor(int duty)                                        *
 * 概要   | モータの回転関数                                                  *
 * 引数   | デューティ比                                                      *
 * 戻り値 | なし                                                              *
 * 詳細   | 指定したデューティ比でモータを回転させる。                        *
 ******************************************************************************/
void MotorController::rotateMotor(int duty)
{
	//右モータの回転
	if ( m_motor_type == MOTOR_TYPE_RIGHT)
	{
		//デューティ比が負＝逆回転
		if ( duty<0 )
		{
			digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 0); //正転用出力ピンを0に設定
			digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 1); //逆回転用出力ピンを1に設定
			duty *= -1; //ピンには正の値を入力するため正負反転
		}
		//そうでない場合は正転
		else
		{
			digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 1); //正転用出力ピンを1に設定
			digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 0); //逆回転用出力ピンを0に設定
		}
		//PWM出力
		pwmWrite( RIGHT_MOTOR_PWM_PIN, duty);
	}
	//左モータの回転
	else if ( m_motor_type == MOTOR_TYPE_LEFT)
	{
		//デューティ比が負＝逆回転
		if ( duty<0 )
		{
			digitalWrite( LEFT_MOTOR_ROTATE_PIN, 0); //正転用出力ピンを0に設定
			digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 1); //逆回転用出力ピンを1に設定
			duty *= -1; //ピンには正の値を入力するため正負反転
		}
		else
		{
			digitalWrite( LEFT_MOTOR_ROTATE_PIN, 1); //正転用出力ピンを1に設定
			digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 0); //逆回転用出力ピンを0に設定
		}
		//PWM出力
		pwmWrite( LEFT_MOTOR_PWM_PIN, duty);
	}
}

/******************************************************************************
 * 関数名 | void stopMotor(int duty)                                          *
 * 概要   | モータの停止関数                                                  *
 * 引数   |                                                                   *
 * 戻り値 | なし                                                              *
 * 詳細   | モータを停止させる                                                *
 ******************************************************************************/
void MotorController::stopMotor()
{
	//右モータの停止
	if ( m_motor_type == MOTOR_TYPE_RIGHT)
	{
		pwmWrite( RIGHT_MOTOR_PWM_PIN, 0); //PWM出力ピンの出力を0に設定
		digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 0); //正転用出力ピンを0に設定
		digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 0); //逆回転用出力ピンを0に設定
	}
	//左モータの停止
	else if ( m_motor_type == MOTOR_TYPE_LEFT)
	{
		pwmWrite( LEFT_MOTOR_PWM_PIN, 0);//PWM出力ピンの出力を0に設定
		digitalWrite( LEFT_MOTOR_ROTATE_PIN, 0);//正転用出力ピンを0に設定
		digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 0);//逆回転用出力ピンを0に設定
	}

}
