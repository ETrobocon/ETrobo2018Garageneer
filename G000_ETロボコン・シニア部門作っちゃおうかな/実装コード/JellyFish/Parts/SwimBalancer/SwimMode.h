/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,EnumDataType.h.xsl
	Generated Date:2017/01/23 13:47:44
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */
#ifndef SwimMode_H
#define SwimMode_H



/**

@author ike
@version 1.0
*/
enum SwimMode
{
	/**
	モーター停止、自然と浮き上がることを期待。
	*/
	SM_OFF = 0,
	/**
	ナビ値を目標値として制御する。
	*/
	SM_NAVI = 1,
	/**
	緊急浮上する。ナビ値は無関係。
	*/
	SM_EMERGENCY = 2,
	/**
	現在のナビゲーション値を静止状態としてリセットする。
目標値は関係なし。
	*/
	SM_RESET_NAVI = 3,
	/**
	現在の方向をゼロ度としてリセットする、
	*/
	SM_RESET_DIR = 4,
};

#endif /* SwimMode_H */
