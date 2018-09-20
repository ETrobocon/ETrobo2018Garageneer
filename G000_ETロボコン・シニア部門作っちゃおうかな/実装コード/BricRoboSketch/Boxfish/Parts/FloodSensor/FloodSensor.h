/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2015/03/24 16:25:58
	Generater Name:BricRoboGen Ver:1.6.1.332  
 */
#ifndef FloodSensor_H
#define FloodSensor_H

#include "../../../BricRoboSketch/ValueIF.h"

/*
void FloodSensor::ConfigParam(int thresh, int pin)
{
}
  void FloodSensor::Run()
{
	ValueIF alert;
    Rte_Send_alert(alert);

}
*/


/**
浸水を警告する。
@author eguchi
@version 1.0
*/
class FloodSensor
{
	/*
	User Defined Attribute
	*/
	/**
	
	*/
	private: int _pin;
	/**
	
	*/
	private: int _thresh;
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
	@param thresh	AD変換してこの値を下回ると警告を発する。
	@param pin	使用するアナログピン番号
	*/
	public: void ConfigParam(int thresh, int pin);
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
	AD変換した値。
	*/
	/* Rte_Send_alert(ValueIF) */
	BricRoboPortSend(ValueIF,alert);
};

/* Procedure Template
*/

#endif /* FloodSensor_H */
