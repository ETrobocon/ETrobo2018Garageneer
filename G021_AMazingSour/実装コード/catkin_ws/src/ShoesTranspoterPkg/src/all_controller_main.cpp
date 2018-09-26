/* �S�̊Ǘ����̎��s�t�@�C���iAllController�j��main�֐��L�q�t�@�C�� */
#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "all_controller/all_controller.hpp"

#define SHOES_NUM 2 /* �^���ԑ䐔 */
static AllController test_all= AllController(SHOES_NUM); /* �S�̊Ǘ�����` */

/* ROS���b�Z�[�W�w�ǎ��̃R�[���o�b�N�֐� */
void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg);

/*****************************************************************************************
 * �֐��� | int main(int argc, char** argv)                                              *
 * �T�v   | ���s�t�@�C����main�֐�                                                       *
 * ����   | int ���s���̃p�����[�^���Achar** ���s���̃p�����[�^                          *
 * �߂�l | �Ȃ�                                                                         *
 * �ڍ�   | ROS�m�[�h�̐ݒ肨���100ms�����őS�̊Ǘ����̃��C���֐��̎��s                 *
 *****************************************************************************************/
int main(int argc, char** argv)
{
		/* �m�[�h�̏������i�m�[�h���Fall_controller�j */
        ros::init(argc, argv, "all_controller");
		/* ���s�m�F�R�����g�\�� */
        ROS_INFO("Start All Controller");
		/* �m�[�h�n���h���̐錾 */
        ros::NodeHandle n;
		/* ROS���b�Z�[�W�̔z�M�҂̒�`�i�g�s�b�N���Foperation_msg�j */
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
		/* ROS���b�Z�[�W�̍w�ǎ҂̒�`�i�g�s�b�N���Ftrans_status�j */
        ros::Subscriber operation_sub = n.subscribe ("trans_status", 100, transpoterstatusCallback);
		/* ROS�m�[�h�̓�����g���i10Hz��100ms�����j */
        ros::Rate loop_rate(10);
		/* 100ms�����őS�̊Ǘ����̃��C���֐��̎��s */
        while( ros::ok() )
        {
				test_all.mainFunction(status_pub); /* �S�̊Ǘ����̃��C���֐��̎��s */
				ros::spinOnce(); /* �w�ǎґ҂��֐� */
				loop_rate.sleep(); /* 100ms���������֐� */
        }
        return 0;
}

/*****************************************************************************************
 * �֐��� | void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg)*
 * �T�v   | �^���Ԃ���̃g�s�b�N���w�ǂ����Ƃ��ɌĂяo�����֐�                         *
 * ����   | const ShoesTranspoterPkg::transpoter_status& �w�ǃg�s�b�N                    *
 * �߂�l | �Ȃ�                                                                         *
 * �ڍ�   | �^���Ԃ��C�E���G���A�ɓ���->��ԕύX�A���[�G���A�ɓ���->���̉^���Ԃ��C�E���G���A��*
 *****************************************************************************************/
void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg)
{
	/* �w�ǂ����g�s�b�N�ɍ��킹�ĉ^���Ԃ̏�Ԃ��X�V */
	test_all.setTranspoterStatus(msg.transpoter_id,msg.transpoter_location,msg.transpoter_shoes);
	/* �����^���Ԃ̈ʒu���C�E���G���A->���g�̏�ԕύX�i�F�؋���->�F�ؑ҂��j */
	if(msg.transpoter_location == 0)
	{
		test_all.changeState();
	}
	/* ��L�ȊO->���̉^���Ԃ��C�E���G���A�Ɉړ� */
	else
	{
		/* �m�[�h�n���h���̒�` */
		ros::NodeHandle n;
		/* ROS���b�Z�[�W�̔z�M�҂̒�`�i�g�s�b�N���Foperation_msg�j */
		ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
		/* �C�E���G���A�ݒ�֐��̎��s�i���̉^���Ԃ��C�E���G���A�Ɉړ��j */
		test_all.settingEntrance( status_pub,msg.transpoter_shoes );
	}
}
