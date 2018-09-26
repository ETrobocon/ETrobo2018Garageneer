#include"all_controller.hpp"

/******************************************************************************
 * �֐��� | void mainFunction( ros::Publisher state_pub );                    *
 * �T�v   | �S�̊Ǘ����N���X�̃��C���֐�                                      *
 * ����   | ROS���b�Z�[�W�̔z�M��                                             *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �w��F�؋@�̒l���擾���A���g�̏�ԕύX�Ɖ^���Ԃւ̎w�ߒl���M���s��*
 ******************************************************************************/
void AllController::mainFunction( ros::Publisher state_pub )
{
	// ���g�̏�Ԋm�F
	if(m_state == en_cont_wait)
	{
		int detect_result = -1; // �w��F�؋@�̔F�،��ʊi�[�p�ϐ��i�����l-1�j
		
		// �w��F�؋@�ɂ��l���F��
		detect_result = m_human_detector[0].detectHuman(&m_trans_id);
		
		// �F�؎ҁ�����҂̏���
		if(detect_result == 0)
		{
			// ���g�̏�Ԃ̕ύX
			changeState();
			
			// �C�E���G���A�ɂ���^���Ԃ����[�G���A�Ɉړ�
			for(int i=0;i<m_transpoter_num;i++)
			{
				if(m_shoes_transpoter[i].getLocation() == en_trans_entrance) // �^���Ԕz�񂩂�C�E���G���A�ɂ���^���Ԃ�������
				{
					// �^���Ԃւ̎w�ߗp���b�Z�[�W�̍쐬
					ShoesTranspoterPkg::operation_msg op_msg; // ���b�Z�[�W�^�Foperation_msg
					op_msg.trans_id = i; // �ړ�����^���Ԃ�ID
					op_msg.trans_location = 1; // �ړ���̎w��i�^���Ԃ̈ʒu�����[�G���A�ɕύX�j
					op_msg.trans_shoes = 1; // �^���ԂɌC������Ă��邱�Ɓi1�j���w��
					// ���b�Z�[�W�̑��M
					state_pub.publish(op_msg);
					return;
				}
			}
		}
		// �F�؎ҁ��ޏ�҂̏���
		else if(detect_result == 1)
		{
			// ���g�̏�Ԃ̕ύX
			changeState();
			
			// �C�E���G���A�ɂ���^���Ԃ����[�G���A�Ɉړ�
			for(int i=0;i<m_transpoter_num;i++)
			{
				if(m_shoes_transpoter[i].getLocation() == en_trans_entrance) // �^���Ԕz�񂩂�C�E���G���A�ɂ���^���Ԃ�������
				{
					// �^���Ԃւ̎w�ߗp���b�Z�[�W�̍쐬
					ShoesTranspoterPkg::operation_msg op_msg; // ���b�Z�[�W�^�Foperation_msg
					op_msg.trans_id = i;  // �ړ�����^���Ԃ�ID
					op_msg.trans_location = 1;  // �ړ���̎w��i�^���Ԃ̈ʒu�����[�G���A�ɕύX�j
					op_msg.trans_shoes = 0;  // �^���ԂɌC������Ă��邱�Ɓi0�j���w��
					// ���b�Z�[�W�̑��M
					state_pub.publish(op_msg);
					return;
				}
			}
		}
		// �F�؎҂Ȃ�
		else
		{
			return;
		}
	}
}
/******************************************************************************
 * �֐��� | void settingEntrance( ros::Publisher state_pub, int shoes );      *
 * �T�v   | �C�E���G���A�����֐�                                              *
 * ����   | ROS���b�Z�[�W�̔z�M�ҁA���[�G���A�Ɉړ������^���Ԃ̌C�̗L��       *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | ���[�G���A�ɉ^���Ԃ��ړ�������A�ʂ̉^���Ԃ��C�E���G���A�Ɉړ�����*
 ******************************************************************************/
void AllController::settingEntrance( ros::Publisher state_pub,int shoes )
{
	// ���[�G���A�Ɉړ������^���҂ɌC������Ă��Ȃ��ꍇ���F�؎҂͑ޏ��
	if(shoes == 0 )
	{
		// ���[�G���A�ɂ���^���Ԃ��C�E���G���A�Ɉړ�
		for(int i=0;i<m_transpoter_num;i++)
		{
			if(m_shoes_transpoter[i].getLocation() == en_trans_shoebox && m_shoes_transpoter[i].getID() == m_trans_id) // �^���Ԕz�񂩂�ޏ�҂̌C������Ă���^���Ԃ�������
			{
				// �^���Ԃւ̎w�ߗp���b�Z�[�W�̍쐬
				ShoesTranspoterPkg::operation_msg op_msg; // ���b�Z�[�W�^�Foperation_msg
				op_msg.trans_id = i; // �ړ�����^���Ԃ�ID
				op_msg.trans_location = 0; // �ړ���̎w��i�^���Ԃ̈ʒu���C�E���G���A�ɕύX�j
				op_msg.trans_shoes = 0; // �^���ԂɌC������Ă��Ȃ����Ɓi0�j���w��i�ޏ�҂��C�𗚂��čs�����߁j
				// ���b�Z�[�W�̑��M
				state_pub.publish(op_msg);
				return;
			}
		}
	}
	// ���[�G���A�Ɉړ������^���҂ɌC������Ă��Ȃ��ꍇ���F�؎҂͓����
	else
	{
		// ���[�G���A�ɂ���^���Ԃ��C�E���G���A�Ɉړ�
		for(int i=0;i<m_transpoter_num;i++)
		{
			if(m_shoes_transpoter[i].getLocation() == en_trans_shoebox && m_shoes_transpoter[i].getShoes() == false) // �^���Ԕz�񂩂�C������Ă��Ȃ��^���Ԃ�������
			{
				// �^���Ԃւ̎w�ߗp���b�Z�[�W�̍쐬
				ShoesTranspoterPkg::operation_msg op_msg; // ���b�Z�[�W�^�Foperation_msg
				op_msg.trans_id = i; // �ړ�����^���Ԃ�ID
				op_msg.trans_location = 0; // �ړ���̎w��i�^���Ԃ̈ʒu���C�E���G���A�ɕύX�j
				op_msg.trans_shoes = 0; // �^���ԂɌC������Ă��Ȃ����Ɓi0�j���w��
				// ���b�Z�[�W�̑��M
				state_pub.publish(op_msg);
				return;
			}
		}
	}
}
/******************************************************************************
 * �֐��� | void setTranspoterStatus(int id, int loc, int shoes);             *
 * �T�v   | �^���Ԕz��Ǘ��֐�                                                *
 * ����   | �^����id�A�^���Ԉړ���A�^���Ԃ̌C�̗L��				          *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | ���g���Ǘ�����^���Ԕz��̃f�[�^�����ۂ̉^���Ԃɍ��킹��          *
 ******************************************************************************/
void AllController::setTranspoterStatus(int id, int loc, int shoes)
{
	m_shoes_transpoter[id].setLocation(loc); // �^���Ԃ̈ʒu�̕ύX
	if(shoes == 0){ m_shoes_transpoter[id].setShoes(false); } // �^���ԂɌC������Ă��Ȃ��ꍇ�̃t���O�o�^
	else{ m_shoes_transpoter[id].setShoes(true); } // �^���ԂɌC������Ă���ꍇ�̃t���O�o�^
}
/******************************************************************************
 * �֐��� | void changeState();                                               *
 * �T�v   | ���g�̏�ԕύX�֐�                                                *
 * ����   | �Ȃ�													          *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �ҋ@��Ԃ����ۏ�ԂɁA���ۏ�Ԃ�ҋ@��ԂɕύX					  *
 ******************************************************************************/
void AllController::changeState()
{
	// �ҋ@��Ԃ����ۏ�ԂɕύX
	if(m_state == en_cont_wait)
	{
		m_state = en_cont_reject;
		ROS_INFO("Change State to Reject");
	}
	// ���ۏ�Ԃ�ҋ@��ԂɕύX
	else
	{
		m_state = en_cont_wait;
		ROS_INFO("Change State to Wait");
	}
}
