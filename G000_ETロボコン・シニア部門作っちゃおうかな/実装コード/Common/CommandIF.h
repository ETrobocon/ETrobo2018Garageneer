/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,SenderReceiverInterface.h.xsl
	Generated Date:2017/08/21 17:25:14
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */
#ifndef CommandIF_H
#define CommandIF_H

#include "COMMAND.h"
#include "MAGIC_NO.h"


/**
ロボットを制御するコマンド
@author eguchi
@version 1.0
*/
class CommandIF
{
	/*
	User Defined Attribute
	*/
	/**
	コマンド
	*/
	public: uint8_t cmd;
	/**
	パラメータ。値の意味はコマンドにより決定する。
	*/
	public: int16_t param1;
	/**
	パラメータ。値の意味はコマンドにより決定する。
	*/
	public: int16_t param2;
	/**
	パラメータ。値の意味はコマンドにより決定する。
	*/
	public: int16_t param3;
	/*
	User Defined Method
	*/
};

#endif /* CommandIF_H */
