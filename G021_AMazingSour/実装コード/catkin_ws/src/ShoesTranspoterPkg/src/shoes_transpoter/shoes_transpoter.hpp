#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "../move_controller/move_controller.hpp"
#include "../line_detector/line_detector.hpp"
#include "../color_controller/color_controller.hpp"
#include <chrono>
#include <time.h>

/* インクルードガード */
#ifndef SHOES_TRANSPOTER_CLASS
#define SHOES_TRANSPOTER_CLASS

/* 列挙型：運搬車の位置 */
enum EN_TranLoc{
	en_trans_entrance, /* 靴脱ぎエリア */
	en_trans_shoebox   /* 収納エリア */
};

/* 列挙型：運搬車の状態 */
enum EN_TranState{
	en_trans_stop,   /* 停止状態 */
	en_trans_trace,  /* ライントレース状態 */
	en_trans_turn90, /* 90度旋回状態 */
	en_trans_turn180 /* 180度旋回状態 */
};

/* 列挙型：運搬車の進行方向 */
enum EN_TranOri{
	en_trans_front, /* 前進 */
	en_trans_rear   /* 後退 */
};

/* クラス：運搬車 */
class ShoesTranspoter{
	/* コンストラクタとデストラクタ */
	public: //公開部分
	/* コンストラクタ */
	ShoesTranspoter()
	{
		m_move_controller = MoveController();   /* 移動管理クラス */
		m_line_detector = LineDetector();	/* ライン検知クラス */
		m_color_controller = ColorController(); /* カラーセンサ管理クラス */
		initializeTranspoter(0);                /* 運搬車の初期化 */
	}
	/* コンストラクタ（引数にID） */
	ShoesTranspoter(int id)
	{
		m_move_controller = MoveController();    /* 移動管理クラス */
		m_line_detector = LineDetector();        /* ライン検知クラス */
		m_color_controller = ColorController();  /* カラーセンサ管理クラス */
		initializeTranspoter(id);                /* 運搬車の初期化 */
	}
	/* デストラクタ */
	~ShoesTranspoter(){}

	/* アトリビュート */
	private: //非公開部分
	MoveController m_move_controller;    /* 移動管理クラス */
	LineDetector m_line_detector;	     /* ライン検知クラス */
	ColorController m_color_controller;  /* カラーセンサ管理クラス */
	int m_id;			     /* ID */
	EN_TranState m_state;		     /* 状態 */
	EN_TranLoc m_location;		     /* 位置 */
	EN_TranOri m_orientation;	     /* 進行方向 */
	bool m_shoes;			     /* 靴の有無 */
	EN_LineSide m_line_history;	     /* ライン検知の結果（旋回の終了条件のために履歴を取る） */
	EN_Color m_target_color_type;	     /* 目標の色 */

	/* メソッド */
	public: //公開部分
	void mainFunction( ros::Publisher state_pub); /* 運搬車メイン関数 */
	void changeState(int type); /* 状態変更 */
	int getID(); /* IDを返す関数 */
	EN_TranLoc getLocation(); /* 位置を返す関数 */
	void setLocation(int location); /* 位置を設定する関数 */
	EN_TranOri getOrientation(); /* 進行方向を返す関数 */
	bool getShoes(); /* 靴の有無を返す関数 */
	void setShoes(bool shoes); /* 靴の有無を設定する関数 */
	void setInitialTragetColor(); /* 初期目標色設定 */
	void initializeTranspoter(int id); /* 初期化関数 */
};
#endif