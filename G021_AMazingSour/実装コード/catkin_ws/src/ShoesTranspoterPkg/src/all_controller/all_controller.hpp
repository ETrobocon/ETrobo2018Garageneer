#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "../led_controller/led_controller.hpp"
#include "../human_detector/human_detector.hpp"
#include "../shoes_transpoter/shoes_transpoter.hpp"

// インクルードガード
#ifndef ALL_CONTROLLER_CLASS
#define ALL_CONTROLLER_CLASS

// 全体管理部の状態
enum EN_ContState
{
	en_cont_wait,	/* 待機状態 */
	en_cont_reject	/* 拒否状態 */
};

/* クラス：全体管理部 */
class AllController{

/* コンストラクタとデストラクタ */
public:
	// コンストラクタ
	AllController()
	{
		m_trans_id = -1;//退場者の靴が乗っている運搬車のIDの初期化
		m_transpoter_num = 0;//運搬車台数初期化
		m_state = en_cont_wait;//自身の状態初期化
		m_shoes_transpoter = NULL;//運搬車ポインタ初期化
		m_human_detector[0] = HumanDetector();//指紋認証機初期化①
		m_human_detector[1] = HumanDetector();//指紋認証機初期化②
	}
	// コンストラクタ（整数型引数有）
	AllController(int num)
	{
		m_trans_id = -1;//退場者の靴が乗っている運搬車のIDの初期化
		m_transpoter_num = num;//運搬車の台数を引数で初期化
		m_state = en_cont_wait;//自身の状態初期化
		m_shoes_transpoter =  new ShoesTranspoter[num];//運搬車の配列の領域を確保
		//運搬車の初期化
		for(int i=0;i<num;i++)
		{
			m_shoes_transpoter[i].initializeTranspoter(i);
		}
		m_human_detector[0] = HumanDetector();//指紋認証機初期化①
		m_human_detector[1] = HumanDetector();//指紋認証機初期化②
	}
	// デストラクタ
	~AllController()
	{
		// 運搬車配列の領域解放
		if(m_shoes_transpoter != NULL)
		{
			delete [] m_shoes_transpoter;
		}
	}

/* アトリビュート */
private: // 非公開部分
	int m_trans_id; //退場者の靴が乗っている運搬車のID
	int m_transpoter_num; //運搬車数
	EN_ContState m_state; //自身の状態変数
	HumanDetector m_human_detector[2]; //指紋認証機（複数台想定として2つで作成）
	ShoesTranspoter* m_shoes_transpoter; //運搬車（複数台想定のためポインタで作成）

/* メソッド */
public: //公開部分
	void mainFunction( ros::Publisher state_pub ); //全体管理部メイン関数
	void settingEntrance( ros::Publisher state_pub,int shoes ); //靴脱ぎエリア準備関数
	void setTranspoterStatus(int id, int loc, int shoes);//運搬車配列管理関数
	void changeState();//自身の状態変更関数
};
#endif