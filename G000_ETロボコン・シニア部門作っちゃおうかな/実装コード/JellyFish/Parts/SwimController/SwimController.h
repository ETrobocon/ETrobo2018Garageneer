/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2017/01/23 13:47:44
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */
#ifndef SwimController_H
#define SwimController_H

#include "../../../Common/Parts/PidInt16/PidInt16.h"
#include "SwimControllerIF.h"
#include "../../../Common/JellyFish/JellyFishNavi.h"
#include "../../../BricRoboSketch/ValueIF.h"
#include "../../../Common/PidParamIF.h"
#include "../CmdController/StabiIF.h"

/* 実装のテンプレートとして利用してください
#include "stdafx.h"
#include "SwimController.h"

void SwimController::ConfigParam(int dummy)
{
}
  void SwimController::Run()
{
	SwimControllerIF ctrl;
    Rte_Read_ctrl(ctrl);
	JellyFishNavi curNavi;
    Rte_Write_curNavi(curNavi);
	ValueIF depth;
    Rte_Read_depth(depth);
	ValueIF diveL;
    Rte_Write_diveL(diveL);
	ValueIF diveR;
    Rte_Write_diveR(diveR);
	ValueIF left;
    Rte_Write_left(left);
	JellyFishNavi navi;
    Rte_Read_navi(navi);
	PidParamIF pidParamDep;
    Rte_Receive_pidParamDep(pidParamDep);
	PidParamIF pidParamDir;
    Rte_Receive_pidParamDir(pidParamDir);
	ValueIF right;
    Rte_Write_right(right);
	StabiIF stabi;
    Rte_Read_stabi(stabi);

}
*/


/**

@author ike
@version 1.0
*/
class SwimController
{
	/*
	User Defined Attribute
	*/
	/**
	ターンが0のとき保つ方向。
	*/
	private: int16_t _keepDir;
	/**
	ダイブが0のとき保つ方向。
	*/
	private: int16_t _keepDepth;
	/*
	User Defined Method
	*/
	/*
	Auto Generated Attribute
	*/
	/**
	
	*/
	public: PidInt16 PID_DIR;
	/**
	
	*/
	public: PidInt16 PID_DIVE;
	/**
	
	*/
	public: PidInt16 PID_PITCH;
	/*
	Auto Generated Method
	*/
	/**
	ConfigParam
	@param dummy	
	*/
	public: void ConfigParam(int dummy);
	/*
	RunnableEntity
	*/
	/**
	
	*/
	public: void Run();
	/*
	Port
	*/
	/**
	
	*/
	/* Rte_Read_ctrl(SwimControllerIF) */
	BricRoboPortRead(SwimControllerIF,ctrl);
	/**
	現在の姿勢を表すナビゲーション値
	*/
	/* Rte_Write_curNavi(JellyFishNavi) */
	BricRoboPortWrite(JellyFishNavi,curNavi);
	/**
	
	*/
	/* Rte_Read_depth(ValueIF) */
	BricRoboPortRead(ValueIF,depth);
	/**
	フロントモーターESCの出力値
	*/
	/* Rte_Write_diveL(ValueIF) */
	BricRoboPortWrite(ValueIF,diveL);
	/**
	リヤモーターESCの出力値
	*/
	/* Rte_Write_diveR(ValueIF) */
	BricRoboPortWrite(ValueIF,diveR);
	/**
	左モーターESCの出力値
	*/
	/* Rte_Write_left(ValueIF) */
	BricRoboPortWrite(ValueIF,left);
	/**
	
	*/
	/* Rte_Read_navi(JellyFishNavi) */
	BricRoboPortRead(JellyFishNavi,navi);
	/**
	スタビライザーの垂直方向PIDパラメタセット
	*/
	/* Rte_Receive_pidParamDep(PidParamIF) */
	BricRoboPortReceive(PidParamIF,pidParamDep);
	/**
	スタビライザーの水平方向PIDパラメタセット
	*/
	/* Rte_Receive_pidParamDir(PidParamIF) */
	BricRoboPortReceive(PidParamIF,pidParamDir);
	/**
	右モーターESCの出力値
	*/
	/* Rte_Write_right(ValueIF) */
	BricRoboPortWrite(ValueIF,right);
	/**
	0以外のときスタビライザーON
ビット組み合わせで水平垂直を別々に指定する。
１：水平
２：垂直
３：水平垂直両方
	*/
	/* Rte_Read_stabi(StabiIF) */
	BricRoboPortRead(StabiIF,stabi);
};

/* Procedure Template
*/

#endif /* SwimController_H */
