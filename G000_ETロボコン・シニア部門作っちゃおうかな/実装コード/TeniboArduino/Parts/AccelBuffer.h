/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2018/09/19 14:45:51
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */
#ifndef AccelBuffer_H
#define AccelBuffer_H

#include "../../BricRoboSketch/ValueIF.h"

/* 実装のテンプレートとして利用してください
#include "stdafx.h"
#include "AccelBuffer.h"

void AccelBuffer::ConfigParam(int InitValue, int SleepCnt, int Range)
{
}
  void AccelBuffer::Run()
{
	ValueIF in;
    Rte_Read_in(in);
	ValueIF out;
    Rte_Write_out(out);

}
*/


/**
値の急激な変化を避ける。プラスからマイナス、マイナスからプラスに変わるときは、すこし時間を空ける。
@author ike
@version 1.0
*/
class AccelBuffer
{
	/*
	User Defined Attribute
	*/
	/**
	
	*/
	private: int _current;
	/**
	
	*/
	private: int _range;
	/**
	
	*/
	private: int _sleepCnt;
	/**
	
	*/
	private: int _sleepCur;
	/*
	User Defined Method
	*/
	/*
	Auto Generated Attribute
	*/
	/*
	Auto Generated Method
	*/
	/**
	ConfigParam
	@param InitValue	
	@param SleepCnt	
	@param Range	一度に動ける値の片側の範囲。
	*/
	public: void ConfigParam(int InitValue, int SleepCnt, int Range);
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
	/* Rte_Read_in(ValueIF) */
	BricRoboPortRead(ValueIF,in);
	/**
	
	*/
	/* Rte_Write_out(ValueIF) */
	BricRoboPortWrite(ValueIF,out);
};

/* Procedure Template
*/

#endif /* AccelBuffer_H */
