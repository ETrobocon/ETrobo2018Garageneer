#include "move_controller.hpp"

#define PWM_DUTY 70
/*****************************************************************************************
 * �֐��� | void moveTranspoter(EN_MoveType move_type)                                   *
 * �T�v   | �^���Ԃ̒��i�֐�                                                             *
 * ����   | EN_MoveType �ړ��^�C�v�i�w�b�_�t�@�C���Q�Ɓj                                 *
 * �߂�l | �Ȃ�                                                                         *
 * �ڍ�   | ���C���g���[�X���s���ĉ^���Ԃ𒼐i������B���C���g���[�X�͒P���ȃG�b�W���@   *
 *****************************************************************************************/
void MoveController::moveTranspoter(EN_MoveType move_type)
{
	switch(move_type)
	{
	case en_front_line_right: /* �i�s�����F�O�A���C���ド�C�g�Z���T�F�E */
		m_motor_controller[0].rotateMotor(0); //�E���[�^�ᑬor��~
		m_motor_controller[1].rotateMotor(PWM_DUTY); //�����[�^��]
		break;
        case en_front_line_left: /* �i�s�����F�O�A���C���ド�C�g�Z���T�F�� */
                m_motor_controller[0].rotateMotor(PWM_DUTY);  //�E���[�^��]
                m_motor_controller[1].rotateMotor(0); //�����[�^�ᑬor��~
                break;
        case en_front_line_center: /* �i�s�����F�O�A���C���ド�C�g�Z���T�F���� */
                m_motor_controller[0].rotateMotor(PWM_DUTY); //�E���[�^��]
                m_motor_controller[1].rotateMotor(PWM_DUTY); //�����[�^��]
                break;
        case en_rear_line_right: /* �i�s�����F��A���C���ド�C�g�Z���T�F�E */
                m_motor_controller[0].rotateMotor(-PWM_DUTY); //�E���[�^��](�t��]
                m_motor_controller[1].rotateMotor(0); //�����[�^�ᑬor��~
                break;
        case en_rear_line_left: /* �i�s�����F��A���C���ド�C�g�Z���T�F�� */
                m_motor_controller[0].rotateMotor(0); //�E���[�^��](�t��]�j
                m_motor_controller[1].rotateMotor(-PWM_DUTY);  //�����[�^��](�t��])
                break;
        case en_rear_line_center: /* �i�s�����F��A���C���ド�C�g�Z���T�F���� */
                m_motor_controller[0].rotateMotor(-PWM_DUTY); //�E���[�^��](�t��])
                m_motor_controller[1].rotateMotor(-PWM_DUTY); //�����[�^��](�t��])
                break;
	}
}

/******************************************************************************
 * �֐��� | void stopTranspoter()                                             *
 * �T�v   | �^���Ԃ̒�~�֐�                                                  *
 * ����   | �Ȃ�                                                              *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ��~������B                                              *
 ******************************************************************************/
void MoveController::stopTranspoter()
{
	m_motor_controller[0].stopMotor();//�E���[�^�̒�~
	m_motor_controller[1].stopMotor();//�����[�^�̒�~
}

/******************************************************************************
 * �֐��� | void turnTranspoter( EN_TurnOri turn_ori )                        *
 * �T�v   | �^���Ԃ̒��i�֐�                                                  *
 * ����   | EN_TurnOri  �������                                              *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ��w�肵�������ɐ��񂳂���B                                *
 ******************************************************************************/
void MoveController::turnTranspoter( EN_TurnOri turn_ori )
{
	switch(turn_ori)
	{
	case en_turn_right://�E�ɐ���
		m_motor_controller[0].rotateMotor(-100);//�E���[�^���t��]
		m_motor_controller[1].rotateMotor(100);//�����[�^�𐳓]
		break;
	case en_turn_left://���ɐ���
		m_motor_controller[0].rotateMotor(100);//�E���[�^�𐳓]
		m_motor_controller[1].rotateMotor(-100);//�����[�^���t��]
		break;
	case en_turn_back://�E�ɐ���i180�x����p�j
		m_motor_controller[0].rotateMotor(-100);//�E���[�^���t��]
		m_motor_controller[1].rotateMotor(100);//�����[�^�𐳓]
		break;
	default:
		break;
	}
}
