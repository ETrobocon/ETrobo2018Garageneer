#include"all_controller.hpp"

/******************************************************************************
 * 関数名 | void mainFunction( ros::Publisher state_pub );                    *
 * 概要   | 全体管理部クラスのメイン関数                                      *
 * 引数   | ROSメッセージの配信者                                             *
 * 戻り値 | なし                                                              *
 * 詳細   | 指紋認証機の値を取得し、自身の状態変更と運搬車への指令値送信を行う*
 ******************************************************************************/
void AllController::mainFunction( ros::Publisher state_pub )
{
	// 自身の状態確認
	if(m_state == en_cont_wait)
	{
		int detect_result = -1; // 指紋認証機の認証結果格納用変数（初期値-1）
		
		// 指紋認証機による人物認証
		detect_result = m_human_detector[0].detectHuman(&m_trans_id);
		
		// 認証者＝入場者の処理
		if(detect_result == 0)
		{
			// 自身の状態の変更
			changeState();
			
			// 靴脱ぎエリアにいる運搬車を収納エリアに移動
			for(int i=0;i<m_transpoter_num;i++)
			{
				if(m_shoes_transpoter[i].getLocation() == en_trans_entrance) // 運搬車配列から靴脱ぎエリアにいる運搬車を見つける
				{
					// 運搬車への指令用メッセージの作成
					ShoesTranspoterPkg::operation_msg op_msg; // メッセージ型：operation_msg
					op_msg.trans_id = i; // 移動する運搬車のID
					op_msg.trans_location = 1; // 移動先の指定（運搬車の位置を収納エリアに変更）
					op_msg.trans_shoes = 1; // 運搬車に靴が乗っていること（1）を指定
					// メッセージの送信
					state_pub.publish(op_msg);
					return;
				}
			}
		}
		// 認証者＝退場者の処理
		else if(detect_result == 1)
		{
			// 自身の状態の変更
			changeState();
			
			// 靴脱ぎエリアにいる運搬車を収納エリアに移動
			for(int i=0;i<m_transpoter_num;i++)
			{
				if(m_shoes_transpoter[i].getLocation() == en_trans_entrance) // 運搬車配列から靴脱ぎエリアにいる運搬車を見つける
				{
					// 運搬車への指令用メッセージの作成
					ShoesTranspoterPkg::operation_msg op_msg; // メッセージ型：operation_msg
					op_msg.trans_id = i;  // 移動する運搬車のID
					op_msg.trans_location = 1;  // 移動先の指定（運搬車の位置を収納エリアに変更）
					op_msg.trans_shoes = 0;  // 運搬車に靴が乗っていること（0）を指定
					// メッセージの送信
					state_pub.publish(op_msg);
					return;
				}
			}
		}
		// 認証者なし
		else
		{
			return;
		}
	}
}
/******************************************************************************
 * 関数名 | void settingEntrance( ros::Publisher state_pub, int shoes );      *
 * 概要   | 靴脱ぎエリア準備関数                                              *
 * 引数   | ROSメッセージの配信者、収納エリアに移動した運搬車の靴の有無       *
 * 戻り値 | なし                                                              *
 * 詳細   | 収納エリアに運搬車が移動したら、別の運搬車を靴脱ぎエリアに移動する*
 ******************************************************************************/
void AllController::settingEntrance( ros::Publisher state_pub,int shoes )
{
	// 収納エリアに移動した運搬者に靴が乗っていない場合＝認証者は退場者
	if(shoes == 0 )
	{
		// 収納エリアにいる運搬車を靴脱ぎエリアに移動
		for(int i=0;i<m_transpoter_num;i++)
		{
			if(m_shoes_transpoter[i].getLocation() == en_trans_shoebox && m_shoes_transpoter[i].getID() == m_trans_id) // 運搬車配列から退場者の靴が乗っている運搬車を見つける
			{
				// 運搬車への指令用メッセージの作成
				ShoesTranspoterPkg::operation_msg op_msg; // メッセージ型：operation_msg
				op_msg.trans_id = i; // 移動する運搬車のID
				op_msg.trans_location = 0; // 移動先の指定（運搬車の位置を靴脱ぎエリアに変更）
				op_msg.trans_shoes = 0; // 運搬車に靴が乗っていないこと（0）を指定（退場者が靴を履いて行くため）
				// メッセージの送信
				state_pub.publish(op_msg);
				return;
			}
		}
	}
	// 収納エリアに移動した運搬者に靴が乗っていない場合＝認証者は入場者
	else
	{
		// 収納エリアにいる運搬車を靴脱ぎエリアに移動
		for(int i=0;i<m_transpoter_num;i++)
		{
			if(m_shoes_transpoter[i].getLocation() == en_trans_shoebox && m_shoes_transpoter[i].getShoes() == false) // 運搬車配列から靴が乗っていない運搬車を見つける
			{
				// 運搬車への指令用メッセージの作成
				ShoesTranspoterPkg::operation_msg op_msg; // メッセージ型：operation_msg
				op_msg.trans_id = i; // 移動する運搬車のID
				op_msg.trans_location = 0; // 移動先の指定（運搬車の位置を靴脱ぎエリアに変更）
				op_msg.trans_shoes = 0; // 運搬車に靴が乗っていないこと（0）を指定
				// メッセージの送信
				state_pub.publish(op_msg);
				return;
			}
		}
	}
}
/******************************************************************************
 * 関数名 | void setTranspoterStatus(int id, int loc, int shoes);             *
 * 概要   | 運搬車配列管理関数                                                *
 * 引数   | 運搬車id、運搬車移動先、運搬車の靴の有無				          *
 * 戻り値 | なし                                                              *
 * 詳細   | 自身が管理する運搬車配列のデータを実際の運搬車に合わせる          *
 ******************************************************************************/
void AllController::setTranspoterStatus(int id, int loc, int shoes)
{
	m_shoes_transpoter[id].setLocation(loc); // 運搬車の位置の変更
	if(shoes == 0){ m_shoes_transpoter[id].setShoes(false); } // 運搬車に靴が乗っていない場合のフラグ登録
	else{ m_shoes_transpoter[id].setShoes(true); } // 運搬車に靴が乗っている場合のフラグ登録
}
/******************************************************************************
 * 関数名 | void changeState();                                               *
 * 概要   | 自身の状態変更関数                                                *
 * 引数   | なし													          *
 * 戻り値 | なし                                                              *
 * 詳細   | 待機状態を拒否状態に、拒否状態を待機状態に変更					  *
 ******************************************************************************/
void AllController::changeState()
{
	// 待機状態を拒否状態に変更
	if(m_state == en_cont_wait)
	{
		m_state = en_cont_reject;
		ROS_INFO("Change State to Reject");
	}
	// 拒否状態を待機状態に変更
	else
	{
		m_state = en_cont_wait;
		ROS_INFO("Change State to Wait");
	}
}
