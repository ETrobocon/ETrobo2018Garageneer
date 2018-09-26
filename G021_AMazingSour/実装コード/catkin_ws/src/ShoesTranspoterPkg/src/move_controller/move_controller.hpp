#include "../motor_controller/motor_controller.hpp"

/* �C���N���[�h�K�[�h */
#ifndef  MOVE_CONTROLLER_CLASS
#define MOVE_CONTROLLER_CLASS

/* ������� */
enum EN_TurnOri
{
	en_turn_right, /* �E���� */
	en_turn_left,  /* ������ */
	en_turn_back   /* �E�����i180�x���]�j*/
};

/* �ړ��^�C�v */
enum EN_MoveType
{
	en_front_line_right,  /* �i�s�����F�O�A���C���ド�C�g�Z���T�F�E */
	en_front_line_left,   /* �i�s�����F�O�A���C���ド�C�g�Z���T�F�� */
	en_front_line_center, /* �i�s�����F�O�A���C���ド�C�g�Z���T�F���� */
	en_rear_line_right,   /* �i�s�����F��A���C���ド�C�g�Z���T�F�E */
	en_rear_line_left,    /* �i�s�����F��A���C���ド�C�g�Z���T�F�� */
	en_rear_line_center,  /* �i�s�����F��A���C���ド�C�g�Z���T�F���� */
};

/* �N���X�F�ړ��Ǘ��� */
class MoveController{

	/*�@�A�g���r���[�g */
	private://����J����
	MotorController m_motor_controller[2];//���[�^�R���g���[��

	/* �R���X�g���N�^�ƃf�X�g���N�^ */
	public:
	/* �R���X�g���N�^ */
	MoveController()
	{
		m_motor_controller[0] = MotorController( MOTOR_TYPE_RIGHT ); //�E���[�^
		m_motor_controller[1] = MotorController( MOTOR_TYPE_LEFT );  //�����[�^
	}
	/* �f�X�g���N�^ */
	~MoveController(){}

	/* ���\�b�h */
	public:
	void moveTranspoter( EN_MoveType move_type); //�^���Ԃ̒��i
	void stopTranspoter(); //�^���Ԃ̒�~
	void turnTranspoter( EN_TurnOri turn_ori ); //�^���Ԃ̐���
};
#endif