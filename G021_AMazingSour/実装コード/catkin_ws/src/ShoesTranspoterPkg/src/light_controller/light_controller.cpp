#include "light_controller.hpp"


/******************************************************************************
 * �֐��� | EN_Line LightController::detectLine(int id)                       *
 * �T�v   | ���C���̌��o                                                      *
 * ����   | �g�p����Z���T��ID                                                *
 * �߂�l | EN_Line():������                                                  *
 * �ڍ�   | ���C�g�Z���T�����C���i���F�j��ɂ��邩�ۂ��𔻒�                  *
 ******************************************************************************/
EN_Line LightController::detectLine(int id)
{
	int i = 10; //�o�͗p�ϐ�
	int no = 10;//�s���ԍ��i�[�p�ϐ�
	
	/* sensor choice�@*/
	/* �g�p���郉�C�g�Z���T�ɉ����ēǂݍ��ރs���ԍ������� */
	switch(id){
		case 0:
			no = Left_front_LightSensor;
			break; 
		case 1:
			no = Right_front_LightSensor;
			break;
		case 2:
			no = Left_rear_LightSensor;
			break;
		case 3:
			no = Right_rear_LightSensor;
			break;
		default:
			printf("lightsensor is no choise \n");
			return en_line_error;
	}

	// no�̃s���̃Z���T��ǂݍ���
	i = digitalRead(no);
	
	// ���C�g�Z���T�����F�̏�̂Ƃ�
	if(i == en_line_white &&  i != en_line_black)
	{
		return en_line_white;
	}
	// ����ȊO�͍��Ƃ���
	return en_line_black;
}

