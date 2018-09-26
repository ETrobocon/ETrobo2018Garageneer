#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "../move_controller/move_controller.hpp"
#include "../line_detector/line_detector.hpp"
#include "../color_controller/color_controller.hpp"
#include <chrono>
#include <time.h>

/* �C���N���[�h�K�[�h */
#ifndef SHOES_TRANSPOTER_CLASS
#define SHOES_TRANSPOTER_CLASS

/* �񋓌^�F�^���Ԃ̈ʒu */
enum EN_TranLoc{
	en_trans_entrance, /* �C�E���G���A */
	en_trans_shoebox   /* ���[�G���A */
};

/* �񋓌^�F�^���Ԃ̏�� */
enum EN_TranState{
	en_trans_stop,   /* ��~��� */
	en_trans_trace,  /* ���C���g���[�X��� */
	en_trans_turn90, /* 90�x������ */
	en_trans_turn180 /* 180�x������ */
};

/* �񋓌^�F�^���Ԃ̐i�s���� */
enum EN_TranOri{
	en_trans_front, /* �O�i */
	en_trans_rear   /* ��� */
};

/* �N���X�F�^���� */
class ShoesTranspoter{
	/* �R���X�g���N�^�ƃf�X�g���N�^ */
	public: //���J����
	/* �R���X�g���N�^ */
	ShoesTranspoter()
	{
		m_move_controller = MoveController();   /* �ړ��Ǘ��N���X */
		m_line_detector = LineDetector();	/* ���C�����m�N���X */
		m_color_controller = ColorController(); /* �J���[�Z���T�Ǘ��N���X */
		initializeTranspoter(0);                /* �^���Ԃ̏����� */
	}
	/* �R���X�g���N�^�i������ID�j */
	ShoesTranspoter(int id)
	{
		m_move_controller = MoveController();    /* �ړ��Ǘ��N���X */
		m_line_detector = LineDetector();        /* ���C�����m�N���X */
		m_color_controller = ColorController();  /* �J���[�Z���T�Ǘ��N���X */
		initializeTranspoter(id);                /* �^���Ԃ̏����� */
	}
	/* �f�X�g���N�^ */
	~ShoesTranspoter(){}

	/* �A�g���r���[�g */
	private: //����J����
	MoveController m_move_controller;    /* �ړ��Ǘ��N���X */
	LineDetector m_line_detector;	     /* ���C�����m�N���X */
	ColorController m_color_controller;  /* �J���[�Z���T�Ǘ��N���X */
	int m_id;			     /* ID */
	EN_TranState m_state;		     /* ��� */
	EN_TranLoc m_location;		     /* �ʒu */
	EN_TranOri m_orientation;	     /* �i�s���� */
	bool m_shoes;			     /* �C�̗L�� */
	EN_LineSide m_line_history;	     /* ���C�����m�̌��ʁi����̏I�������̂��߂ɗ��������j */
	EN_Color m_target_color_type;	     /* �ڕW�̐F */

	/* ���\�b�h */
	public: //���J����
	void mainFunction( ros::Publisher state_pub); /* �^���ԃ��C���֐� */
	void changeState(int type); /* ��ԕύX */
	int getID(); /* ID��Ԃ��֐� */
	EN_TranLoc getLocation(); /* �ʒu��Ԃ��֐� */
	void setLocation(int location); /* �ʒu��ݒ肷��֐� */
	EN_TranOri getOrientation(); /* �i�s������Ԃ��֐� */
	bool getShoes(); /* �C�̗L����Ԃ��֐� */
	void setShoes(bool shoes); /* �C�̗L����ݒ肷��֐� */
	void setInitialTragetColor(); /* �����ڕW�F�ݒ� */
	void initializeTranspoter(int id); /* �������֐� */
};
#endif