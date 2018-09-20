/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2015/03/24 16:25:58
	Generater Name:BricRoboGen Ver:1.6.1.332  
 */
#ifndef Controller_H
#define Controller_H

#include "../../../Common/CommandIF.h"
#include "../../../BricRoboSketch/ValueIF.h"
#include "../../../Common/NaviIF.h"
#include "../../../Common/PositionIF.h"
#include "../LedDriver/LedPattern.h"

/*
void Controller::ConfigParam(int16_t pecOff, int16_t tailOff, int16_t flood, int16_t offlineJudgeCnt)
{
}
  void Controller::Run()
{
	CommandIF command;
    Rte_Receive_command(command);
	ValueIF floodAlarm;
    Rte_Receive_floodAlarm(floodAlarm);
	ValueIF jetPower;
    Rte_Write_jetPower(jetPower);
	ValueIF ledLight;
    Rte_Send_ledLight(ledLight);
	ValueIF ledPattern;
    Rte_Send_ledPattern(ledPattern);
	NaviIF navi;
    Rte_Write_navi(navi);
	ValueIF pecFin;
    Rte_Write_pecFin(pecFin);
	PositionIF position;
    Rte_Read_position(position);
	ValueIF tailFin;
    Rte_Write_tailFin(tailFin);
	ValueIF waterDepth;
    Rte_Read_waterDepth(waterDepth);
	ValueIF waterPressure;
    Rte_Read_waterPressure(waterPressure);

}
*/


/**
ロボット全体を制御する。
制御コマンドが一定時間以内に届かない場合には回避行動を取る。
@author eguchi
@version 1.0
*/
class Controller
{
	/*
	User Defined Attribute
	*/
	/**
	尾ビレのオフセット値
	*/
	private: int16_t _tailOffset;
	/**
	
	*/
	private: int16_t _floodAlarm;
	/**
	
	*/
	private: int16_t _pecFin;
	/**
	胸ビレのオフセット値
	*/
	private: int16_t _pecOffset;
	/**
	
	*/
	private: int16_t _tailFin;
	/**
	
	*/
	private: int16_t _jetPower;
	/**
	通信が途絶して、OFFラインとみなすまでの回数。
25msを１回と想定。
	*/
	private: int16_t _offlineJudgeCnd;
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
	@param pecOff	
	@param tailOff	
	@param flood	
	@param offlineJudgeCnt	
	*/
	public: void ConfigParam(int16_t pecOff, int16_t tailOff, int16_t flood, int16_t offlineJudgeCnt);
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
	ロボットを操縦するコマンド
	*/
	/* Rte_Receive_command(CommandIF) */
	BricRoboPortReceive(CommandIF,command);
	/**
	浸水警告
	*/
	/* Rte_Receive_floodAlarm(ValueIF) */
	BricRoboPortReceive(ValueIF,floodAlarm);
	/**
	推進力パワー
	*/
	/* Rte_Write_jetPower(ValueIF) */
	BricRoboPortWrite(ValueIF,jetPower);
	/**
	底を照らすLEDを制御する。
	*/
	/* Rte_Send_ledLight(ValueIF) */
	BricRoboPortSend(ValueIF,ledLight);
	/**
	状態を表すLEDを制御する。
	*/
	/* Rte_Send_ledPattern(ValueIF) */
	BricRoboPortSend(ValueIF,ledPattern);
	/**
	ロボットの状態
	*/
	/* Rte_Write_navi(NaviIF) */
	BricRoboPortWrite(NaviIF,navi);
	/**
	胸ビレの角度
	*/
	/* Rte_Write_pecFin(ValueIF) */
	BricRoboPortWrite(ValueIF,pecFin);
	/**
	ロボットの姿勢。

	*/
	/* Rte_Read_position(PositionIF) */
	BricRoboPortRead(PositionIF,position);
	/**
	尾ビレの角度
	*/
	/* Rte_Write_tailFin(ValueIF) */
	BricRoboPortWrite(ValueIF,tailFin);
	/**
	
	*/
	/* Rte_Read_waterDepth(ValueIF) */
	BricRoboPortRead(ValueIF,waterDepth);
	/**
	水深
	*/
	/* Rte_Read_waterPressure(ValueIF) */
	BricRoboPortRead(ValueIF,waterPressure);
};

/* Procedure Template
*/

#endif /* Controller_H */
