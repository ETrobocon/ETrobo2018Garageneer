#include <wiringPi.h>

/* �C���N���[�h�K�[�h */
#ifndef  MOTOR_CONTROLLER_CLASS
#define MOTOR_CONTROLLER_CLASS

// �E���[�^�������[�^��
#define MOTOR_TYPE_RIGHT 0
#define MOTOR_TYPE_LEFT 1

// PWM����̂��߂�GPIO�s��
#define RIGHT_MOTOR_PWM_PIN 18
#define LEFT_MOTOR_PWM_PIN 19

// ���[�^�h���C�o���́i�E�j
#define RIGHT_MOTOR_ROTATE_PIN 14
#define RIGHT_MOTOR_INV_ROTATE_PIN 15

// ���[�^�h���C�o���́i���j
#define LEFT_MOTOR_ROTATE_PIN 16
#define LEFT_MOTOR_INV_ROTATE_PIN 20

// PWM�ݒ�l
#define CLOCK_FOR_PWM 1000 //�N���b�N
#define RANGE_FOR_PWM 100  //����\

class MotorController
{
	// �A�g���r���[�g�E����
	private://����J����
		int m_motor_type; // �E���[�^�������[�^��

	// �R���X�g���N�^�A�f�X�g���N�^
	public://���J����
	// �R���X�g���N�^
	MotorController(){}
	// �R���X�g���N�^�i�����ɂǂ���̃��[�^�������^�Ŏw��j
	MotorController( int motor_type )
	{
		//wiringpi�̃Z�b�g�A�b�v
		wiringPiSetupGpio();
		//�����̃��[�^�̃^�C�v�������o�ϐ��Ɋi�[
		m_motor_type = motor_type;
		//�E���[�^�Ƃ��Đݒ�
		if ( m_motor_type == MOTOR_TYPE_RIGHT)
		{
			pinMode( RIGHT_MOTOR_PWM_PIN, PWM_OUTPUT);    //�s����PWM���[�h�Ɏw��
			pinMode( RIGHT_MOTOR_ROTATE_PIN, OUTPUT);     //�s�����o�̓��[�h�Ɏw��
			pinMode( RIGHT_MOTOR_INV_ROTATE_PIN, OUTPUT); //�s�����o�̓��[�h�Ɏw��
		}
		//�����[�^�Ƃ��Đݒ�
		else if ( m_motor_type == MOTOR_TYPE_LEFT)
		{
			pinMode( LEFT_MOTOR_PWM_PIN, PWM_OUTPUT);    //�s����PWM���[�h�Ɏw��
			pinMode( LEFT_MOTOR_ROTATE_PIN, OUTPUT);     //�s�����o�̓��[�h�Ɏw��
			pinMode( LEFT_MOTOR_INV_ROTATE_PIN, OUTPUT); //�s�����o�̓��[�h�Ɏw��
		}

		//PWM�̐ݒ�
		pwmSetMode( PWM_MODE_MS );//���[�h
		pwmSetClock( CLOCK_FOR_PWM );//�N���b�N
		pwmSetRange( RANGE_FOR_PWM );//����\

	}
	//�f�X�g���N�^
	~MotorController(){}

	// ���\�b�h�E�֐�
	public://���J����
		void rotateMotor(int duty); // ���[�^�̉�]
		void stopMotor(); // ���[�^�̒�~
};
#endif