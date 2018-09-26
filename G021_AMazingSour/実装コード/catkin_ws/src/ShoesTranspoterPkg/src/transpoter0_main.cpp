/* 運搬車の実行ファイル（Transporter*）のmain関数記述ファイル */
#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "shoes_transpoter/shoes_transpoter.hpp"

#define SHOES_TRANSPOTER_ID 0 /* 運搬車ID */
#define SHOES_TRANSPOTER_NODE_NAME "shoes_transpoter_0" /* 運搬車ノード名 */

static ShoesTranspoter test_move = ShoesTranspoter(SHOES_TRANSPOTER_ID); /* 運搬車定義 */

/* ROSメッセージ購読時のコールバック関数 */
void operationCallback(const ShoesTranspoterPkg::operation_msg& msg);

/*****************************************************************************************
 * 関数名 | int main(int argc, char** argv)                                              *
 * 概要   | 実行ファイルのmain関数                                                       *
 * 引数   | int 実行時のパラメータ数、char** 実行時のパラメータ                          *
 * 戻り値 | なし                                                                         *
 * 詳細   | ROSノードの設定および10ms周期で運搬車のメイン関数の実行                      *
 *****************************************************************************************/
int main(int argc, char** argv)
{
		/* ノードの初期化（ノード名：shoes_transpoter_*） */
        ros::init(argc, argv, SHOES_TRANSPOTER_NODE_NAME);
		/* 実行確認コメント表示 */
        ROS_INFO("Transpoter Start");
		/* ノードハンドルの宣言 */
        ros::NodeHandle n;
		/* ROSメッセージの配信者の定義（トピック名：trans_status） */
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::transpoter_status>( "/trans_status", 100 );
		/* ROSメッセージの購読者の定義（トピック名：operation_msg） */
        ros::Subscriber operation_sub = n.subscribe ("/operation_msg", 100, operationCallback);
		/* ROSノードの動作周波数（100Hz＝10ms周期） */
        ros::Rate loop_rate(100);
		/* 100ms周期で全体管理部のメイン関数の実行 */
        while( ros::ok() )
        {
			test_move.mainFunction(status_pub); /* 運搬車のメイン関数の実行 */
			ros::spinOnce(); /* 購読者待ち関数 */
        }
        return 0;
}

/*****************************************************************************************
 * 関数名 | void operationCallback(const ShoesTranspoterPkg::operation_msg& msg)         *
 * 概要   | 全体管理部からのトピックを購読したときに呼び出される関数                     *
 * 引数   | const ShoesTranspoterPkg::operation_msg& 購読トピック                        *
 * 戻り値 | なし                                                                         *
 * 詳細   | 購読したROSトピックに従い、運搬車情報を更新し、運搬車を移動させる            *
 *****************************************************************************************/
void operationCallback(const ShoesTranspoterPkg::operation_msg& msg)
{
	/* トピックに記載されたIDと一致するIDを持つ運搬車のみ処理を実行 */
	if ( msg.trans_id == test_move.getID() )
	{
		/* 退場者の靴が乗っている場合は180度旋回して靴脱ぎエリアに移動 */
		if(test_move.getLocation() == en_trans_shoebox && test_move.getShoes() == true)
		{
			test_move.setShoes(false); /* 退場者が靴を履くので靴の有無は無しに変更 */
			test_move.setLocation(msg.trans_location); /* 位置を靴脱ぎエリアに変更 */
			test_move.changeState(3); /* 180度旋回状態へ遷移 */
			ROS_INFO("Get Message of Change to Turn180"); /* 状態遷移を示すコメント表示 */
		}
		else
		{
			if ( msg.trans_shoes == 1){ test_move.setShoes(true); } /* 入場者の場合は靴の有無を有りに変更 */
			else { test_move.setShoes(false); } /* それ以外の場合は靴の有無を無しに設定 */
			test_move.setLocation(msg.trans_location); /* 位置をトピックに従い変更 */
            test_move.changeState(0); /* ライントレース状態へ遷移 */
			test_move.setInitialTragetColor(); /* 目標色の設定 */
            ROS_INFO("Get Message of Change to Trace"); /* 状態遷移を示すコメント表示 */
		}
	}
}
