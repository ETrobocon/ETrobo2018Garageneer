/* 全体管理部の実行ファイル（AllController）のmain関数記述ファイル */
#include "ros/ros.h"
#include "ShoesTranspoterPkg/transpoter_status.h"
#include "ShoesTranspoterPkg/operation_msg.h"
#include "all_controller/all_controller.hpp"

#define SHOES_NUM 2 /* 運搬車台数 */
static AllController test_all= AllController(SHOES_NUM); /* 全体管理部定義 */

/* ROSメッセージ購読時のコールバック関数 */
void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg);

/*****************************************************************************************
 * 関数名 | int main(int argc, char** argv)                                              *
 * 概要   | 実行ファイルのmain関数                                                       *
 * 引数   | int 実行時のパラメータ数、char** 実行時のパラメータ                          *
 * 戻り値 | なし                                                                         *
 * 詳細   | ROSノードの設定および100ms周期で全体管理部のメイン関数の実行                 *
 *****************************************************************************************/
int main(int argc, char** argv)
{
		/* ノードの初期化（ノード名：all_controller） */
        ros::init(argc, argv, "all_controller");
		/* 実行確認コメント表示 */
        ROS_INFO("Start All Controller");
		/* ノードハンドルの宣言 */
        ros::NodeHandle n;
		/* ROSメッセージの配信者の定義（トピック名：operation_msg） */
        ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
		/* ROSメッセージの購読者の定義（トピック名：trans_status） */
        ros::Subscriber operation_sub = n.subscribe ("trans_status", 100, transpoterstatusCallback);
		/* ROSノードの動作周波数（10Hz＝100ms周期） */
        ros::Rate loop_rate(10);
		/* 100ms周期で全体管理部のメイン関数の実行 */
        while( ros::ok() )
        {
				test_all.mainFunction(status_pub); /* 全体管理部のメイン関数の実行 */
				ros::spinOnce(); /* 購読者待ち関数 */
				loop_rate.sleep(); /* 100ms周期調整関数 */
        }
        return 0;
}

/*****************************************************************************************
 * 関数名 | void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg)*
 * 概要   | 運搬車からのトピックを購読したときに呼び出される関数                         *
 * 引数   | const ShoesTranspoterPkg::transpoter_status& 購読トピック                    *
 * 戻り値 | なし                                                                         *
 * 詳細   | 運搬車が靴脱ぎエリアに到着->状態変更、収納エリアに到着->他の運搬車を靴脱ぎエリアに*
 *****************************************************************************************/
void transpoterstatusCallback(const ShoesTranspoterPkg::transpoter_status& msg)
{
	/* 購読したトピックに合わせて運搬車の状態を更新 */
	test_all.setTranspoterStatus(msg.transpoter_id,msg.transpoter_location,msg.transpoter_shoes);
	/* 到着運搬車の位置が靴脱ぎエリア->自身の状態変更（認証拒否->認証待ち） */
	if(msg.transpoter_location == 0)
	{
		test_all.changeState();
	}
	/* 上記以外->他の運搬車を靴脱ぎエリアに移動 */
	else
	{
		/* ノードハンドラの定義 */
		ros::NodeHandle n;
		/* ROSメッセージの配信者の定義（トピック名：operation_msg） */
		ros::Publisher status_pub = n.advertise<ShoesTranspoterPkg::operation_msg>( "operation_msg", 100 );
		/* 靴脱ぎエリア設定関数の実行（他の運搬車を靴脱ぎエリアに移動） */
		test_all.settingEntrance( status_pub,msg.transpoter_shoes );
	}
}
