#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "../led_controller/led_controller.hpp"
#include "../human_detector/human_detector.hpp"
#include "../shoes_transpoter/shoes_transpoter.hpp"

// �C���N���[�h�K�[�h
#ifndef ALL_CONTROLLER_CLASS
#define ALL_CONTROLLER_CLASS

// �S�̊Ǘ����̏��
enum EN_ContState
{
	en_cont_wait,	/* �ҋ@��� */
	en_cont_reject	/* ���ۏ�� */
};

/* �N���X�F�S�̊Ǘ��� */
class AllController{

/* �R���X�g���N�^�ƃf�X�g���N�^ */
public:
	// �R���X�g���N�^
	AllController()
	{
		m_trans_id = -1;//�ޏ�҂̌C������Ă���^���Ԃ�ID�̏�����
		m_transpoter_num = 0;//�^���ԑ䐔������
		m_state = en_cont_wait;//���g�̏�ԏ�����
		m_shoes_transpoter = NULL;//�^���ԃ|�C���^������
		m_human_detector[0] = HumanDetector();//�w��F�؋@�������@
		m_human_detector[1] = HumanDetector();//�w��F�؋@�������A
	}
	// �R���X�g���N�^�i�����^�����L�j
	AllController(int num)
	{
		m_trans_id = -1;//�ޏ�҂̌C������Ă���^���Ԃ�ID�̏�����
		m_transpoter_num = num;//�^���Ԃ̑䐔�������ŏ�����
		m_state = en_cont_wait;//���g�̏�ԏ�����
		m_shoes_transpoter =  new ShoesTranspoter[num];//�^���Ԃ̔z��̗̈���m��
		//�^���Ԃ̏�����
		for(int i=0;i<num;i++)
		{
			m_shoes_transpoter[i].initializeTranspoter(i);
		}
		m_human_detector[0] = HumanDetector();//�w��F�؋@�������@
		m_human_detector[1] = HumanDetector();//�w��F�؋@�������A
	}
	// �f�X�g���N�^
	~AllController()
	{
		// �^���Ԕz��̗̈���
		if(m_shoes_transpoter != NULL)
		{
			delete [] m_shoes_transpoter;
		}
	}

/* �A�g���r���[�g */
private: // ����J����
	int m_trans_id; //�ޏ�҂̌C������Ă���^���Ԃ�ID
	int m_transpoter_num; //�^���Ԑ�
	EN_ContState m_state; //���g�̏�ԕϐ�
	HumanDetector m_human_detector[2]; //�w��F�؋@�i������z��Ƃ���2�ō쐬�j
	ShoesTranspoter* m_shoes_transpoter; //�^���ԁi������z��̂��߃|�C���^�ō쐬�j

/* ���\�b�h */
public: //���J����
	void mainFunction( ros::Publisher state_pub ); //�S�̊Ǘ������C���֐�
	void settingEntrance( ros::Publisher state_pub,int shoes ); //�C�E���G���A�����֐�
	void setTranspoterStatus(int id, int loc, int shoes);//�^���Ԕz��Ǘ��֐�
	void changeState();//���g�̏�ԕύX�֐�
};
#endif