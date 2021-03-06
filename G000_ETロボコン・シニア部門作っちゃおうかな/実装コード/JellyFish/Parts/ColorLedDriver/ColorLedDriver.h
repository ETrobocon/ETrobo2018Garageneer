/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2017/01/23 13:47:44
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */
#ifndef ColorLedDriver_H
#define ColorLedDriver_H

#include "../../../Common/Parts/LedDriver/LedDriver.h"
#include "../../../Common/Parts/LedDriver/LedPatternOuter.h"
#include "ColorLedPattern.h"

/* 実装のテンプレートとして利用してください
#include "stdafx.h"
#include "ColorLedDriver.h"

void ColorLedDriver::ConfigParam(int8_t pinR, int8_t pinG, int8_t pinB)
{
}
  void ColorLedDriver::RunDrivers()
{
	ColorLedPattern pattern;
    Rte_Receive_pattern(pattern);

}
void ColorLedDriver::Run()
{
	ColorLedPattern pattern;
    Rte_Receive_pattern(pattern);

}
*/


/**
色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
@author ike
@version 1.0
*/
class ColorLedDriver
{
	/*
	User Defined Attribute
	*/
	/*
	User Defined Method
	*/
	/*
	Auto Generated Attribute
	*/
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedDriver B;
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedPatternOuter BO;
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedDriver G;
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedPatternOuter GO;
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedDriver R;
	/**
	色と点滅パターンで、RGB3色からなるカラーLEDを点灯する。
RGBはON/OFFの制御しか行わず、PWM制御による微妙な発色をしない。
色はRGBの組み合わせで8色（黒を含む）である。
	*/
	public: LedPatternOuter RO;
	/*
	Auto Generated Method
	*/
	/**
	ConfigParam
	@param pinR	
	@param pinG	
	@param pinB	
	*/
	public: void ConfigParam(int8_t pinR, int8_t pinG, int8_t pinB);
	/*
	RunnableEntity
	*/
	/**
	
	*/
	public: void RunDrivers()
	{
		R.Run();
		G.Run();
		B.Run();
	};
	/**
	
	*/
	public: void Run();
	/*
	Port
	*/
	/**
	
	*/
	/* Rte_Receive_pattern(ColorLedPattern) */
	BricRoboPortReceive(ColorLedPattern,pattern);
};

/* Procedure Template
*/

#endif /* ColorLedDriver_H */
