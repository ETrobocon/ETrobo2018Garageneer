#include "move_controller.hpp"

#define PWM_DUTY 70
/*****************************************************************************************
 * 関数名 | void moveTranspoter(EN_MoveType move_type)                                   *
 * 概要   | 運搬車の直進関数                                                             *
 * 引数   | EN_MoveType 移動タイプ（ヘッダファイル参照）                                 *
 * 戻り値 | なし                                                                         *
 * 詳細   | ライントレースを行って運搬車を直進させる。ライントレースは単純なエッジ走法   *
 *****************************************************************************************/
void MoveController::moveTranspoter(EN_MoveType move_type)
{
	switch(move_type)
	{
	case en_front_line_right: /* 進行方向：前、ライン上ライトセンサ：右 */
		m_motor_controller[0].rotateMotor(0); //右モータ低速or停止
		m_motor_controller[1].rotateMotor(PWM_DUTY); //左モータ回転
		break;
        case en_front_line_left: /* 進行方向：前、ライン上ライトセンサ：左 */
                m_motor_controller[0].rotateMotor(PWM_DUTY);  //右モータ回転
                m_motor_controller[1].rotateMotor(0); //左モータ低速or停止
                break;
        case en_front_line_center: /* 進行方向：前、ライン上ライトセンサ：両方 */
                m_motor_controller[0].rotateMotor(PWM_DUTY); //右モータ回転
                m_motor_controller[1].rotateMotor(PWM_DUTY); //左モータ回転
                break;
        case en_rear_line_right: /* 進行方向：後、ライン上ライトセンサ：右 */
                m_motor_controller[0].rotateMotor(-PWM_DUTY); //右モータ回転(逆回転
                m_motor_controller[1].rotateMotor(0); //左モータ低速or停止
                break;
        case en_rear_line_left: /* 進行方向：後、ライン上ライトセンサ：左 */
                m_motor_controller[0].rotateMotor(0); //右モータ回転(逆回転）
                m_motor_controller[1].rotateMotor(-PWM_DUTY);  //左モータ回転(逆回転)
                break;
        case en_rear_line_center: /* 進行方向：後、ライン上ライトセンサ：両方 */
                m_motor_controller[0].rotateMotor(-PWM_DUTY); //右モータ回転(逆回転)
                m_motor_controller[1].rotateMotor(-PWM_DUTY); //左モータ回転(逆回転)
                break;
	}
}

/******************************************************************************
 * 関数名 | void stopTranspoter()                                             *
 * 概要   | 運搬車の停止関数                                                  *
 * 引数   | なし                                                              *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車を停止させる。                                              *
 ******************************************************************************/
void MoveController::stopTranspoter()
{
	m_motor_controller[0].stopMotor();//右モータの停止
	m_motor_controller[1].stopMotor();//左モータの停止
}

/******************************************************************************
 * 関数名 | void turnTranspoter( EN_TurnOri turn_ori )                        *
 * 概要   | 運搬車の直進関数                                                  *
 * 引数   | EN_TurnOri  旋回方向                                              *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車を指定した方向に旋回させる。                                *
 ******************************************************************************/
void MoveController::turnTranspoter( EN_TurnOri turn_ori )
{
	switch(turn_ori)
	{
	case en_turn_right://右に旋回
		m_motor_controller[0].rotateMotor(-100);//右モータを逆回転
		m_motor_controller[1].rotateMotor(100);//左モータを正転
		break;
	case en_turn_left://左に旋回
		m_motor_controller[0].rotateMotor(100);//右モータを正転
		m_motor_controller[1].rotateMotor(-100);//左モータを逆回転
		break;
	case en_turn_back://右に旋回（180度旋回用）
		m_motor_controller[0].rotateMotor(-100);//右モータを逆回転
		m_motor_controller[1].rotateMotor(100);//左モータを正転
		break;
	default:
		break;
	}
}
