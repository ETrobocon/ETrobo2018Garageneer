/* �^���Ԃ̎��s�t�@�C���iTransporter*�j��main�֐��L�q�t�@�C�� */
#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "shoes_transpoter/shoes_transpoter.hpp"

#define SHOES_TRANSPOTER_ID 1 /* �^����ID */
#define SHOES_TRANSPOTER_NODE_NAME "shoes_transpoter_1" /* �^���ԃm�[�h�� */

static ShoesTranspoter test_move = ShoesTranspoter(SHOES_TRANSPOTER_ID); /* �^���Ԓ�` */

/* ROS���b�Z�[�W�w�ǎ��̃R�[���o�b�N�֐� */
void operationCallback(const ShoesTranspoterPkg::operation_msg& msg);

/*****************************************************************************************
 * �֐��� | int main(int argc, char** argv)                                              *
 * �T�v   | ���s�t�@�C����main�֐�                                                       *
 * ����   | int ���s���̃p�����[�^���Achar** ���s���̃p�����[�^                          *
 * �߂�l | �Ȃ�                                                                         *
 * �ڍ�   | ROS�m�[�h�̐ݒ肨���10ms�����ŉ^���Ԃ̃��C���֐��̎��s                      *
 *****************************************************************************************/
int main(int argc, char** argv)
{
		/* �m�[�h�̏������i�m�[�h���Fshoes_transpoter_*�j */
        ros::init(argc, argv, SHOES_TRANSPOTER_NODE_NAME);
		/* ���s�m�F�R�����g�\�� */
        ROS_INFO("Transpoter Start");
		/* �m�[�h�n���h���̐錾 */
        ros::NodeHandle n;
		/* ROS���b�Z�[�W�̔z�M�҂̒�`�i�g�s�b�N���Ftrans_status�j */
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::transpoter_status>( "/trans_status", 100 );
		/* ROS���b�Z�[�W�̍w�ǎ҂̒�`�i�g�s�b�N���Foperation_msg�j */
        ros::Subscriber operation_sub = n.subscribe ("/operation_msg", 100, operationCallback);
		/* ROS�m�[�h�̓�����g���i100Hz��10ms�����j */
        ros::Rate loop_rate(100);
		/* 100ms�����őS�̊Ǘ����̃��C���֐��̎��s */
        while( ros::ok() )
        {
			test_move.mainFunction(status_pub); /* �^���Ԃ̃��C���֐��̎��s */
			ros::spinOnce(); /* �w�ǎґ҂��֐� */
        }
        return 0;
}

/*****************************************************************************************
 * �֐��� | void operationCallback(const ShoesTranspoterPkg::operation_msg& msg)         *
 * �T�v   | �S�̊Ǘ�������̃g�s�b�N���w�ǂ����Ƃ��ɌĂяo�����֐�                     *
 * ����   | const ShoesTranspoterPkg::operation_msg& �w�ǃg�s�b�N                        *
 * �߂�l | �Ȃ�                                                                         *
 * �ڍ�   | �w�ǂ���ROS�g�s�b�N�ɏ]���A�^���ԏ����X�V���A�^���Ԃ��ړ�������            *
 *****************************************************************************************/
void operationCallback(const ShoesTranspoterPkg::operation_msg& msg)
{
	/* �g�s�b�N�ɋL�ڂ��ꂽID�ƈ�v����ID�����^���Ԃ̂ݏ��������s */
	if ( msg.trans_id == test_move.getID() )
	{
		/* �ޏ�҂̌C������Ă���ꍇ��180�x���񂵂ČC�E���G���A�Ɉړ� */
		if(test_move.getLocation() == en_trans_shoebox && test_move.getShoes() == true)
		{
			test_move.setShoes(false); /* �ޏ�҂��C�𗚂��̂ŌC�̗L���͖����ɕύX */
			test_move.setLocation(msg.trans_location); /* �ʒu���C�E���G���A�ɕύX */
			test_move.changeState(3); /* 180�x�����Ԃ֑J�� */
			ROS_INFO("Get Message of Change to Turn180"); /* ��ԑJ�ڂ������R�����g�\�� */
		}
		else
		{
			if ( msg.trans_shoes == 1){ test_move.setShoes(true); } /* ����҂̏ꍇ�͌C�̗L����L��ɕύX */
			else { test_move.setShoes(false); } /* ����ȊO�̏ꍇ�͌C�̗L���𖳂��ɐݒ� */
			test_move.setLocation(msg.trans_location); /* �ʒu���g�s�b�N�ɏ]���ύX */
            test_move.changeState(0); /* ���C���g���[�X��Ԃ֑J�� */
			test_move.setInitialTragetColor(); /* �ڕW�F�̐ݒ� */
            ROS_INFO("Get Message of Change to Trace"); /* ��ԑJ�ڂ������R�����g�\�� */
		}
	}
}
