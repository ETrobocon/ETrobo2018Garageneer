#include "./line_detector.hpp"

/******************************************************************************
 * �֐��� | void LightDetector::setLightSensor(int mode)                      *
 * �T�v   | ���C�g�Z���T�[�̐ݒ�                                              *
 * ����   | mode: �i�s�������O����납                                        *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �g�p���郉�C�g�Z���T��ݒ肷��B                                  *
 ******************************************************************************/
void LineDetector::setLightSensor(int mode)
{	  
	/* �S���邤���̓�̃Z���T���g�p����B*/
	if (mode == 0)
	{
		/*�O�̏ꍇ�̐ݒ�*/
		m_mode = 0;
	}
	else if (mode == 1) 
	{
		/*���̏ꍇ�̐ݒ�*/
		m_mode = 1;
	}
	else
	{
		printf("mode error\n");
	}
}

/******************************************************************************
 * �֐��� | EN_LineSide LightDetector::getLineSide()                          *
 * �T�v   | ���C���������o�֐��@�@                                            *
 * ����   | �Ȃ�                                                              *
 * �߂�l | EN_LineSide: �����E���^�񒆂�                                     *
 * �ڍ�   | ���E�̃J���[�Z���T�̂ǂ��炪���C����ɂ��邩�����m���ĕԂ�        *
 ******************************************************************************/
EN_LineSide LineDetector::getLineSide()
{
	int right,left; //���C�g�Z���T�̒l�i�[�p�ϐ��i�E�A���j
	switch(m_mode){
		case 0: /*�i�s�������O��*/
			left = m_light_controller[0].detectLine(0);
			right = m_light_controller[1].detectLine(1);
			break; 
		case 1: /*�i�s���������*/
			right = m_light_controller[2].detectLine(2);
			left = m_light_controller[3].detectLine(3);
			break;
		default:
			printf("Invalid Mode\n");
			break;
	}
	/* �������A�E���� */
	if(left == en_line_white && right == en_line_black)
	{
		return en_line_right;
	}
	/* �������A�E���� */
	else if(left == en_line_black && right == en_line_white)
	{
		return en_line_left;
	}
	/* �����i�ǂ�������܂��͂ǂ�������j */
	else if(left == en_line_white && right == en_line_white)
	{
		return en_line_center;
	}
}
