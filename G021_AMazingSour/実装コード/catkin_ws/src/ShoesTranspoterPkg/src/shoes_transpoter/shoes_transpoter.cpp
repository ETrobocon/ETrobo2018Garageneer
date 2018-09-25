#include "shoes_transpoter.hpp"
/******************************************************************************
 * 関数名 | void mainFunction( ros::Publisher state_pub )                     *
 * 概要   | 運搬車のメイン関数                                                *
 * 引数   | ros::Publisher ROS配信者                                          *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車の状態変更と一連の動作の実行                                *
 ******************************************************************************/
void ShoesTranspoter::mainFunction( ros::Publisher state_pub )
{
	//色の取得
	EN_Color temp_color = m_color_controller.getColor();

	//状態がトレースモードのとき
       	if( m_state == en_trans_trace )
	{
		//出力メッセージの宣言
		ShoesTranspoterPkg::transpoter_status ts_msg;
	
		//状態遷移：カラーセンサの値でモード変更
		switch( temp_color )
		{
		case en_color_red:/* 0号機は目標色が黄色でないときは赤色で状態変更 */
			if( m_id == 0 && m_target_color_type != en_color_yellow ){ changeState(1); }
			break;
		case en_color_blue:/* 1号機は目標色が黄色でないときは青色で状態変更 */
			if( m_id == 1 && m_target_color_type != en_color_yellow){ changeState(1); }
			break;
		case en_color_green:/* 2号機は目標色が黄色でないときは緑色で状態変更 */
			if( m_id == 2 && m_target_color_type != en_color_yellow){ changeState(1); }
			break;
		case en_color_yellow:/* どの号機も目標色が黄色のときは黄色検知で停止状態へ */
			if(m_target_color_type == en_color_yellow)
			{
				changeState(2);
				/* 停止時はメッセージを作成 */
				ts_msg.transpoter_id = m_id;
				/* 停止位置の設定 */
				if(m_location == en_trans_entrance)
				{
					ts_msg.transpoter_location = 0; /* 靴脱ぎエリア */
				}
				else
				{
					ts_msg.transpoter_location = 1; /* 収納エリア */
				}
				/* 靴の有無 */
				if(m_shoes ==true)
				{
					ts_msg.transpoter_shoes = 1; /* 靴あり */
				}
				else
				{
					ts_msg.transpoter_shoes = 0; /* 靴なし */
				}
				/* メッセージの送信 */
				state_pub.publish(ts_msg);
			}
			break;
		default:
			break;
		}
	}

	/* 状態による動作 */
	switch(m_state)
	{
	EN_LineSide temp_line_side;
	/* トレース状態 */
	case en_trans_trace:
		/* 進行方向：前進 */
		if(m_orientation == en_trans_front)
		{
			/* ライントレース */
			m_line_detector.setLightSensor(0); //ラインセンサの設定
			m_line_history = m_line_detector.getLineSide(); //ライン検知
			/* ラインと運搬車の位置関係で動作を変更 */
			switch( m_line_history )
			{
			case en_line_right: /* 右センサがライン上 */
				m_move_controller.moveTranspoter(en_front_line_right);
				break;
			case en_line_left: /* 左センサがライン上 */
				m_move_controller.moveTranspoter(en_front_line_left);
				break;
			case en_line_center: /* 両センサがライン上 */
				m_move_controller.moveTranspoter(en_front_line_center);
				break;
			default:
				break;
			}
		}
		/* 進行方向：後退 */
		else
		{
		/* ライントレース */
                        m_line_detector.setLightSensor(1); //ラインセンサの設定
                        m_line_history = m_line_detector.getLineSide(); //ライン検知
		/* ラインと運搬車の位置関係で動作を変更 */
                        switch( m_line_history )
                        {
                        case en_line_right: /* 右センサがライン上 */
                                m_move_controller.moveTranspoter(en_rear_line_right);
                                break;
                        case en_line_left: /* 左センサがライン上 */
                                m_move_controller.moveTranspoter(en_rear_line_left);
                                break;
                        case en_line_center: /* 両センサがライン上 */
                                m_move_controller.moveTranspoter(en_rear_line_center);
                                break;
                        default:
                                break;
                        }
		}
		break;
		/* 旋回状態 */
		case en_trans_turn90:
		case en_trans_turn180:
	/* 進行方向にあわせてライトセンサをセット */
                if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); } /* 前進用ライトセンサ */
                else{ m_line_detector.setLightSensor(1); } /* 後退用ライトセンサ */
	/* ライン検知 */
                temp_line_side = m_line_detector.getLineSide();
		/* 目的地が収納エリアの場合は左に旋回 */
		if( m_location == en_trans_shoebox )
		{
			if( m_orientation == en_trans_front ){ m_move_controller.turnTranspoter(en_turn_left); }//前進時左旋回
			else{ m_move_controller.turnTranspoter(en_turn_right); }//後退時右旋回
                        if(temp_line_side == en_line_left && m_line_history != en_line_left){ changeState(0); }//旋回の終了条件：左のライトセンサが白から黒
                        m_line_history = temp_line_side;//次回判定用にライトセンサの値を保存しておく
		}
		/* 目的地が靴脱ぎエリアの場合は右に旋回 */
		else
		{
                        if( m_orientation == en_trans_front ){ m_move_controller.turnTranspoter(en_turn_right); }//前進時右旋回
                        else{ m_move_controller.turnTranspoter(en_turn_left); }//後退時左旋回
                        if(temp_line_side == en_line_right && m_line_history != en_line_right){ changeState(0); }//旋回の終了条件：右のライトセンサが白から黒
                        m_line_history = temp_line_side;//次回判定用にライトセンサの値を保存しておく
		}
		break;
	case en_trans_stop: /* 停止状態 */
		m_move_controller.stopTranspoter();
	default:
		break;
	}
}

/******************************************************************************
 * 関数名 | void changeState(int type)                                        *
 * 概要   | 状態変更関数                                                      *
 * 引数   | int 状態変更先（0：トレース、1：旋回、2：停止、3：旋回180度）     *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車の状態変更                                                  *
 ******************************************************************************/
void ShoesTranspoter::changeState(int type)
{
	/* 引数に応じて状態を変更 */
	switch(type)
	{
	/* トレースモードへ */
	case 0:
		m_state = en_trans_trace;
		break;
	/* 90度旋回 */
	case 1:
		/* 進行方向にあわせてライトセンサの設定 */
		if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); }
                else{ m_line_detector.setLightSensor(1); }
		/* 旋回直前のライン状態を取得しておく */
		m_line_history = m_line_detector.getLineSide();
		/* 状態を90度旋回 */
		m_state = en_trans_turn90;
		/* 目標色を黄色に変更 */
		m_target_color_type = en_color_yellow;
		break;
	/* 停止 */
	case 2:
		/* 運搬車の停止 */
		m_move_controller.stopTranspoter();
		/* 運搬車の次回起動時の進行方向の設定 */
		if(m_shoes != true || m_location == en_trans_entrance)//靴が載った状態で収納エリアで停止したとき以外は進行方向を反転
		{
			if(m_orientation == en_trans_front){ m_orientation = en_trans_rear; }//これまで前進なら後退へ
			else{ m_orientation = en_trans_front; }//これまで反転なら前進へ
		}
		/* 状態を停止 */
		m_state = en_trans_stop;
		break;
	/* 180度旋回 */
	case 3:
		/* 進行方向にあわせてライトセンサの設定 */
		if(m_orientation == en_trans_front){ m_line_detector.setLightSensor(0); }
                else{ m_line_detector.setLightSensor(1); }
		/* ライン検知 */
		m_line_history = m_line_detector.getLineSide();
		/* 180度旋回状態 */
		m_state = en_trans_turn180;
		/* IDに応じて目標色の設定 */
		switch(m_id)
		{
		case 0: /* 0号車は赤 */
			m_target_color_type = en_color_red;
			break;
		case 1: /* 1号車は青 */
			m_target_color_type = en_color_blue;
			break;
		case 2: /* 2号車は緑*/
			m_target_color_type = en_color_green;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
/******************************************************************************
 * 関数名 | int getID()                                                       *
 * 概要   | IDを返す関数                                                      *
 * 引数   | なし                                                              *
 * 戻り値 | int 運搬車のID                                                    *
 * 詳細   | 運搬車のIDを返す                                                  *
 ******************************************************************************/
int ShoesTranspoter::getID()
{
	return m_id;
}
/******************************************************************************
 * 関数名 | EN_TranLoc getLocation()                                          *
 * 概要   | 位置を返す関数                                                    *
 * 引数   | なし                                                              *
 * 戻り値 | EN_TranLoc 運搬車の位置                                           *
 * 詳細   | 運搬車の位置を返す                                                *
 ******************************************************************************/
EN_TranLoc ShoesTranspoter::getLocation()
{
	return m_location;
}
/******************************************************************************
 * 関数名 | void setLocation(int location)                                    *
 * 概要   | 位置設定関数                                                      *
 * 引数   | int 位置（0：靴脱ぎエリア、1：収納エリア）                        *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車の位置を設定する                                            *
 ******************************************************************************/
void ShoesTranspoter::setLocation(int location)
{
	if (location == 0){ m_location = en_trans_entrance; }
	else { m_location = en_trans_shoebox; }
}
/******************************************************************************
 * 関数名 | EN_TranOri getOrientation()                                       *
 * 概要   | 進行方向を返す関数                                                *
 * 引数   | なし                                                              *
 * 戻り値 | EN_TranOri 　進行方向                                             *
 * 詳細   | 運搬車の進行方向を返す                                            *
 ******************************************************************************/
EN_TranOri ShoesTranspoter::getOrientation()
{
	return m_orientation;
}
/******************************************************************************
 * 関数名 | bool getShoes()                                                   *
 * 概要   | 靴の有無を返す関数                                                *
 * 引数   | なし                                                              *
 * 戻り値 | bool 靴の有無（0：なし、1：あり）                                 *
 * 詳細   | 運搬車の靴の有無を返す                                            *
 ******************************************************************************/
bool ShoesTranspoter::getShoes()
{
	return m_shoes;
}
/******************************************************************************
 * 関数名 | void setShoes(bool shoes)                                         *
 * 概要   | 靴の有無設定関数                                                  *
 * 引数   | bool 靴の有無（0：なし、1：あり）                                 *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車の靴の有無を設定                                            *
 ******************************************************************************/
void ShoesTranspoter::setShoes(bool shoes)
{
	m_shoes = shoes;
}
/******************************************************************************
 * 関数名 | void setInitialTragetColor()                                      *
 * 概要   | 目標色設定関数                                                    *
 * 引数   | なし                                                              *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車の初期目標色                                                *
 ******************************************************************************/
void ShoesTranspoter::setInitialTragetColor()
{

	switch(m_id)
        {
        case 0: /* 0号車は赤 */
        	m_target_color_type = en_color_red;
                break;
        case 1: /* 1号車jは青 */
                m_target_color_type = en_color_blue;
                break;
        case 2: /* 2号車は緑 */
                m_target_color_type = en_color_green;
                break;
        default:
                break;
        }
}
/******************************************************************************
 * 関数名 | void initializeTranspoter(int id)                                 *
 * 概要   | 運搬車初期化関数                                                  *
 * 引数   | int ID                                                            *
 * 戻り値 | なし                                                              *
 * 詳細   | 運搬車のIDに合わせて位置などを設定                                *
 ******************************************************************************/
void ShoesTranspoter::initializeTranspoter(int id)
{
	m_id = id; //ID
	m_state = en_trans_stop; //状態
	if( id == 0 ){ m_location = en_trans_entrance; } //0号車のみ靴脱ぎエリア
        else{  m_location = en_trans_shoebox; } //それ以外は収納エリア
        m_orientation = en_trans_front; //進行方向：前進
        m_shoes = false; //靴が無い
        m_line_history = en_line_right; //ライン検知状態
        m_target_color_type = en_color_black; //目標色
}
