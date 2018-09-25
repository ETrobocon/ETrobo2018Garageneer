#include "shoes_transpoter.hpp"
/******************************************************************************
 * �֐��� | void mainFunction( ros::Publisher state_pub )                     *
 * �T�v   | �^���Ԃ̃��C���֐�                                                *
 * ����   | ros::Publisher ROS�z�M��                                          *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ̏�ԕύX�ƈ�A�̓���̎��s                                *
 ******************************************************************************/
void ShoesTranspoter::mainFunction( ros::Publisher state_pub )
{
	//�F�̎擾
	EN_Color temp_color = m_color_controller.getColor();

	//��Ԃ��g���[�X���[�h�̂Ƃ�
       	if( m_state == en_trans_trace )
	{
		//�o�̓��b�Z�[�W�̐錾
		ShoesTranspoterPkg::transpoter_status ts_msg;
	
		//��ԑJ�ځF�J���[�Z���T�̒l�Ń��[�h�ύX
		switch( temp_color )
		{
		case en_color_red:/* 0���@�͖ڕW�F�����F�łȂ��Ƃ��͐ԐF�ŏ�ԕύX */
			if( m_id == 0 && m_target_color_type != en_color_yellow ){ changeState(1); }
			break;
		case en_color_blue:/* 1���@�͖ڕW�F�����F�łȂ��Ƃ��͐F�ŏ�ԕύX */
			if( m_id == 1 && m_target_color_type != en_color_yellow){ changeState(1); }
			break;
		case en_color_green:/* 2���@�͖ڕW�F�����F�łȂ��Ƃ��͗ΐF�ŏ�ԕύX */
			if( m_id == 2 && m_target_color_type != en_color_yellow){ changeState(1); }
			break;
		case en_color_yellow:/* �ǂ̍��@���ڕW�F�����F�̂Ƃ��͉��F���m�Œ�~��Ԃ� */
			if(m_target_color_type == en_color_yellow)
			{
				changeState(2);
				/* ��~���̓��b�Z�[�W���쐬 */
				ts_msg.transpoter_id = m_id;
				/* ��~�ʒu�̐ݒ� */
				if(m_location == en_trans_entrance)
				{
					ts_msg.transpoter_location = 0; /* �C�E���G���A */
				}
				else
				{
					ts_msg.transpoter_location = 1; /* ���[�G���A */
				}
				/* �C�̗L�� */
				if(m_shoes ==true)
				{
					ts_msg.transpoter_shoes = 1; /* �C���� */
				}
				else
				{
					ts_msg.transpoter_shoes = 0; /* �C�Ȃ� */
				}
				/* ���b�Z�[�W�̑��M */
				state_pub.publish(ts_msg);
			}
			break;
		default:
			break;
		}
	}

	/* ��Ԃɂ�铮�� */
	switch(m_state)
	{
	EN_LineSide temp_line_side;
	/* �g���[�X��� */
	case en_trans_trace:
		/* �i�s�����F�O�i */
		if(m_orientation == en_trans_front)
		{
			/* ���C���g���[�X */
			m_line_detector.setLightSensor(0); //���C���Z���T�̐ݒ�
			m_line_history = m_line_detector.getLineSide(); //���C�����m
			/* ���C���Ɖ^���Ԃ̈ʒu�֌W�œ����ύX */
			switch( m_line_history )
			{
			case en_line_right: /* �E�Z���T�����C���� */
				m_move_controller.moveTranspoter(en_front_line_right);
				break;
			case en_line_left: /* ���Z���T�����C���� */
				m_move_controller.moveTranspoter(en_front_line_left);
				break;
			case en_line_center: /* ���Z���T�����C���� */
				m_move_controller.moveTranspoter(en_front_line_center);
				break;
			default:
				break;
			}
		}
		/* �i�s�����F��� */
		else
		{
		/* ���C���g���[�X */
                        m_line_detector.setLightSensor(1); //���C���Z���T�̐ݒ�
                        m_line_history = m_line_detector.getLineSide(); //���C�����m
		/* ���C���Ɖ^���Ԃ̈ʒu�֌W�œ����ύX */
                        switch( m_line_history )
                        {
                        case en_line_right: /* �E�Z���T�����C���� */
                                m_move_controller.moveTranspoter(en_rear_line_right);
                                break;
                        case en_line_left: /* ���Z���T�����C���� */
                                m_move_controller.moveTranspoter(en_rear_line_left);
                                break;
                        case en_line_center: /* ���Z���T�����C���� */
                                m_move_controller.moveTranspoter(en_rear_line_center);
                                break;
                        default:
                                break;
                        }
		}
		break;
		/* ������ */
		case en_trans_turn90:
		case en_trans_turn180:
	/* �i�s�����ɂ��킹�ă��C�g�Z���T���Z�b�g */
                if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); } /* �O�i�p���C�g�Z���T */
                else{ m_line_detector.setLightSensor(1); } /* ��ޗp���C�g�Z���T */
	/* ���C�����m */
                temp_line_side = m_line_detector.getLineSide();
		/* �ړI�n�����[�G���A�̏ꍇ�͍��ɐ��� */
		if( m_location == en_trans_shoebox )
		{
			if( m_orientation == en_trans_front ){ m_move_controller.turnTranspoter(en_turn_left); }//�O�i��������
			else{ m_move_controller.turnTranspoter(en_turn_right); }//��ގ��E����
                        if(temp_line_side == en_line_left && m_line_history != en_line_left){ changeState(0); }//����̏I�������F���̃��C�g�Z���T�������獕
                        m_line_history = temp_line_side;//���񔻒�p�Ƀ��C�g�Z���T�̒l��ۑ����Ă���
		}
		/* �ړI�n���C�E���G���A�̏ꍇ�͉E�ɐ��� */
		else
		{
                        if( m_orientation == en_trans_front ){ m_move_controller.turnTranspoter(en_turn_right); }//�O�i���E����
                        else{ m_move_controller.turnTranspoter(en_turn_left); }//��ގ�������
                        if(temp_line_side == en_line_right && m_line_history != en_line_right){ changeState(0); }//����̏I�������F�E�̃��C�g�Z���T�������獕
                        m_line_history = temp_line_side;//���񔻒�p�Ƀ��C�g�Z���T�̒l��ۑ����Ă���
		}
		break;
	case en_trans_stop: /* ��~��� */
		m_move_controller.stopTranspoter();
	default:
		break;
	}
}

/******************************************************************************
 * �֐��� | void changeState(int type)                                        *
 * �T�v   | ��ԕύX�֐�                                                      *
 * ����   | int ��ԕύX��i0�F�g���[�X�A1�F����A2�F��~�A3�F����180�x�j     *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ̏�ԕύX                                                  *
 ******************************************************************************/
void ShoesTranspoter::changeState(int type)
{
	/* �����ɉ����ď�Ԃ�ύX */
	switch(type)
	{
	/* �g���[�X���[�h�� */
	case 0:
		m_state = en_trans_trace;
		break;
	/* 90�x���� */
	case 1:
		/* �i�s�����ɂ��킹�ă��C�g�Z���T�̐ݒ� */
		if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); }
                else{ m_line_detector.setLightSensor(1); }
		/* ���񒼑O�̃��C����Ԃ��擾���Ă��� */
		m_line_history = m_line_detector.getLineSide();
		/* ��Ԃ�90�x���� */
		m_state = en_trans_turn90;
		/* �ڕW�F�����F�ɕύX */
		m_target_color_type = en_color_yellow;
		break;
	/* ��~ */
	case 2:
		/* �^���Ԃ̒�~ */
		m_move_controller.stopTranspoter();
		/* �^���Ԃ̎���N�����̐i�s�����̐ݒ� */
		if(m_shoes != true || m_location == en_trans_entrance)//�C���ڂ�����ԂŎ��[�G���A�Œ�~�����Ƃ��ȊO�͐i�s�����𔽓]
		{
			if(m_orientation == en_trans_front){ m_orientation = en_trans_rear; }//����܂őO�i�Ȃ��ނ�
			else{ m_orientation = en_trans_front; }//����܂Ŕ��]�Ȃ�O�i��
		}
		/* ��Ԃ��~ */
		m_state = en_trans_stop;
		break;
	/* 180�x���� */
	case 3:
		/* �i�s�����ɂ��킹�ă��C�g�Z���T�̐ݒ� */
		if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); }
                else{ m_line_detector.setLightSensor(1); }
		/* ���C�����m */
		m_line_history = m_line_detector.getLineSide();
		/* 180�x������ */
		m_state = en_trans_turn180;
		/* ID�ɉ����ĖڕW�F�̐ݒ� */
		switch(m_id)
		{
		case 0: /* 0���Ԃ͐� */
			m_target_color_type = en_color_red;
			break;
		case 1: /* 1���Ԃ͐� */
			m_target_color_type = en_color_blue;
			break;
		case 2: /* 2���Ԃ͗�*/
			m_target_color_type = en_color_green;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
/******************************************************************************
 * �֐��� | int getID()                                                       *
 * �T�v   | ID��Ԃ��֐�                                                      *
 * ����   | �Ȃ�                                                              *
 * �߂�l | int �^���Ԃ�ID                                                    *
 * �ڍ�   | �^���Ԃ�ID��Ԃ�                                                  *
 ******************************************************************************/
int ShoesTranspoter::getID()
{
	return m_id;
}
/******************************************************************************
 * �֐��� | EN_TranLoc getLocation()                                          *
 * �T�v   | �ʒu��Ԃ��֐�                                                    *
 * ����   | �Ȃ�                                                              *
 * �߂�l | EN_TranLoc �^���Ԃ̈ʒu                                           *
 * �ڍ�   | �^���Ԃ̈ʒu��Ԃ�                                                *
 ******************************************************************************/
EN_TranLoc ShoesTranspoter::getLocation()
{
	return m_location;
}
/******************************************************************************
 * �֐��� | void setLocation(int location)                                    *
 * �T�v   | �ʒu�ݒ�֐�                                                      *
 * ����   | int �ʒu�i0�F�C�E���G���A�A1�F���[�G���A�j                        *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ̈ʒu��ݒ肷��                                            *
 ******************************************************************************/
void ShoesTranspoter::setLocation(int location)
{
	if (location == 0){ m_location = en_trans_entrance; }
	else { m_location = en_trans_shoebox; }
}
/******************************************************************************
 * �֐��� | EN_TranOri getOrientation()                                       *
 * �T�v   | �i�s������Ԃ��֐�                                                *
 * ����   | �Ȃ�                                                              *
 * �߂�l | EN_TranOri �@�i�s����                                             *
 * �ڍ�   | �^���Ԃ̐i�s������Ԃ�                                            *
 ******************************************************************************/
EN_TranOri ShoesTranspoter::getOrientation()
{
	return m_orientation;
}
/******************************************************************************
 * �֐��� | bool getShoes()                                                   *
 * �T�v   | �C�̗L����Ԃ��֐�                                                *
 * ����   | �Ȃ�                                                              *
 * �߂�l | bool �C�̗L���i0�F�Ȃ��A1�F����j                                 *
 * �ڍ�   | �^���Ԃ̌C�̗L����Ԃ�                                            *
 ******************************************************************************/
bool ShoesTranspoter::getShoes()
{
	return m_shoes;
}
/******************************************************************************
 * �֐��� | void setShoes(bool shoes)                                         *
 * �T�v   | �C�̗L���ݒ�֐�                                                  *
 * ����   | bool �C�̗L���i0�F�Ȃ��A1�F����j                                 *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ̌C�̗L����ݒ�                                            *
 ******************************************************************************/
void ShoesTranspoter::setShoes(bool shoes)
{
	m_shoes = shoes;
}
/******************************************************************************
 * �֐��� | void setInitialTragetColor()                                      *
 * �T�v   | �ڕW�F�ݒ�֐�                                                    *
 * ����   | �Ȃ�                                                              *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ̏����ڕW�F                                                *
 ******************************************************************************/
void ShoesTranspoter::setInitialTragetColor()
{

	switch(m_id)
        {
        case 0: /* 0���Ԃ͐� */
        	m_target_color_type = en_color_red;
                break;
        case 1: /* 1����j�͐� */
                m_target_color_type = en_color_blue;
                break;
        case 2: /* 2���Ԃ͗� */
                m_target_color_type = en_color_green;
                break;
        default:
                break;
        }
}
/******************************************************************************
 * �֐��� | void initializeTranspoter(int id)                                 *
 * �T�v   | �^���ԏ������֐�                                                  *
 * ����   | int ID                                                            *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �^���Ԃ�ID�ɍ��킹�Ĉʒu�Ȃǂ�ݒ�                                *
 ******************************************************************************/
void ShoesTranspoter::initializeTranspoter(int id)
{
	m_id = id; //ID
	m_state = en_trans_stop; //���
	if( id == 0 ){ m_location = en_trans_entrance; } //0���Ԃ̂݌C�E���G���A
        else{  m_location = en_trans_shoebox; } //����ȊO�͎��[�G���A
        m_orientation = en_trans_front; //�i�s�����F�O�i
        m_shoes = false; //�C������
        m_line_history = en_line_right; //���C�����m���
        m_target_color_type = en_color_black; //�ڕW�F
}
