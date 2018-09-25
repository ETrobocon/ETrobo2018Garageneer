#include "motor_controller.hpp"
/******************************************************************************
 * �֐��� | void rotateMotor(int duty)                                        *
 * �T�v   | ���[�^�̉�]�֐�                                                  *
 * ����   | �f���[�e�B��                                                      *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �w�肵���f���[�e�B��Ń��[�^����]������B                        *
 ******************************************************************************/
void MotorController::rotateMotor(int duty)
{
	//�E���[�^�̉�]
	if ( m_motor_type == MOTOR_TYPE_RIGHT)
	{
		//�f���[�e�B�䂪�����t��]
		if ( duty<0 )
		{
			digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 0); //���]�p�o�̓s����0�ɐݒ�
			digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 1); //�t��]�p�o�̓s����1�ɐݒ�
			duty *= -1; //�s���ɂ͐��̒l����͂��邽�ߐ������]
		}
		//�����łȂ��ꍇ�͐��]
		else
		{
			digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 1); //���]�p�o�̓s����1�ɐݒ�
			digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 0); //�t��]�p�o�̓s����0�ɐݒ�
		}
		//PWM�o��
		pwmWrite( RIGHT_MOTOR_PWM_PIN, duty);
	}
	//�����[�^�̉�]
	else if ( m_motor_type == MOTOR_TYPE_LEFT)
	{
		//�f���[�e�B�䂪�����t��]
		if ( duty<0 )
		{
			digitalWrite( LEFT_MOTOR_ROTATE_PIN, 0); //���]�p�o�̓s����0�ɐݒ�
			digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 1); //�t��]�p�o�̓s����1�ɐݒ�
			duty *= -1; //�s���ɂ͐��̒l����͂��邽�ߐ������]
		}
		else
		{
			digitalWrite( LEFT_MOTOR_ROTATE_PIN, 1); //���]�p�o�̓s����1�ɐݒ�
			digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 0); //�t��]�p�o�̓s����0�ɐݒ�
		}
		//PWM�o��
		pwmWrite( LEFT_MOTOR_PWM_PIN, duty);
	}
}

/******************************************************************************
 * �֐��� | void stopMotor(int duty)                                          *
 * �T�v   | ���[�^�̒�~�֐�                                                  *
 * ����   |                                                                   *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | ���[�^���~������                                                *
 ******************************************************************************/
void MotorController::stopMotor()
{
	//�E���[�^�̒�~
	if ( m_motor_type == MOTOR_TYPE_RIGHT)
	{
		pwmWrite( RIGHT_MOTOR_PWM_PIN, 0); //PWM�o�̓s���̏o�͂�0�ɐݒ�
		digitalWrite( RIGHT_MOTOR_ROTATE_PIN, 0); //���]�p�o�̓s����0�ɐݒ�
		digitalWrite( RIGHT_MOTOR_INV_ROTATE_PIN, 0); //�t��]�p�o�̓s����0�ɐݒ�
	}
	//�����[�^�̒�~
	else if ( m_motor_type == MOTOR_TYPE_LEFT)
	{
		pwmWrite( LEFT_MOTOR_PWM_PIN, 0);//PWM�o�̓s���̏o�͂�0�ɐݒ�
		digitalWrite( LEFT_MOTOR_ROTATE_PIN, 0);//���]�p�o�̓s����0�ɐݒ�
		digitalWrite( LEFT_MOTOR_INV_ROTATE_PIN, 0);//�t��]�p�o�̓s����0�ɐݒ�
	}

}
