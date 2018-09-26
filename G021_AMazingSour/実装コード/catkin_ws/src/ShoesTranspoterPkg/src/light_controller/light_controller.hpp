#include <stdio.h>
#include <wiringPi.h>

/* front���C�g�Z���T */
#define LightSensor_front 0
/* rear���C�g�Z���T */
#define LightSensor_rear 1

/* ���O�̃��C�g�Z���T */
#define Left_front_LightSensor 6
/* �E�O�̃��C�g�Z���T */
#define Right_front_LightSensor 5
/* ����̃��C�g�Z���T */
#define Left_rear_LightSensor 13
/* �E��̃��C�g�Z���T */
#define Right_rear_LightSensor 21

/* ���C�g�Z���T�̒l�i���F��or���F��j */
enum EN_Line
{
	en_line_white,                        /* ���F(0) */
	en_line_black,                        /* ���F(1) */
	en_line_error
};

/* �N���X�F���C�g�R���g���[���i���C�g�Z���T�Ǘ����j */
class LightController
{
/* �R���X�g���N�^�ƃf�X�g���N�^ */
public: //���J����
	/* �R���X�g���N�^ */
	LightController(){}    
	/* �R���X�g���N�^�i�����Ƀs���ԍ��j */
	/* light_type��Left_front_LightSensor,Right_front_LightSensor,Left_rear_LightSensor,Right_rear_LightSensor�̂����ꂩ */
	LightController(int light_type)
	{
		/* wiringpi�̃Z�b�g�A�b�v */
		wiringPiSetupGpio();
		/* �s���̐ݒ� */
		pinMode(light_type, INPUT);
	}
	/* �f�X�g���N�^ */
	~LightController(){}

/* ���\�b�h */
public://���J����
	EN_Line detectLine(int id);                 /* ���C�����o */
};
