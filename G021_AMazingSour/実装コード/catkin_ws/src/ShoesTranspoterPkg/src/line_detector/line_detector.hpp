#include "../light_controller/light_controller.hpp"

enum EN_LineSide
{
	en_line_right,                         /* �E��(0) */
	en_line_left,                          /* ����(1) */
	en_line_center                        /* ����(2) */
};

class LineDetector
{
/* �A�g���r���[�g */
private:  //����J����
	int m_mode;	/* �^���Ԃ̐i�s�����i0�F�O�i,1�F��ށj */
	LightController m_light_controller[4]; /* ���C�g�R���g���[�� */

/* �R���X�g���N�^�ƃf�X�g���N�^ */
public: //���J����
	/* �R���X�g���N�^ */
	LineDetector()
	{
		/* ���C�g�R���g���[���̐ݒ� */
		m_light_controller[0] = LightController(Left_front_LightSensor);
		m_light_controller[1] = LightController(Right_front_LightSensor);
		m_light_controller[2] = LightController(Left_rear_LightSensor);
		m_light_controller[3] = LightController(Right_rear_LightSensor);
	}
	/* �f�X�g���N�^ */
	~LineDetector(){}

/* ���\�b�h */
public://���J����
	void setLightSensor(int mode); /* �g�p���郉�C�g�Z���T�[���Z�b�g����B*/
	EN_LineSide getLineSide(); /* Line���ǂ��������ɂ��邩��������*/
};