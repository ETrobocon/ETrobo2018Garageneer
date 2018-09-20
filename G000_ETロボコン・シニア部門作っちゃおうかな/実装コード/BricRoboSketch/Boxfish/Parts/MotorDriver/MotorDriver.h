/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2015/03/24 16:25:58
	Generater Name:BricRoboGen Ver:1.6.1.332  
 */
#ifndef MotorDriver_H
#define MotorDriver_H

#include "../../../BricRoboSketch/ValueIF.h"

/*
void MotorDriver::ConfigParam(int pin, float K)
{
}
  void MotorDriver::Run()
{
	ValueIF in;
    Rte_Read_in(in);

}
*/


/**

@author eguchi
@version 1.0
*/
class MotorDriver
{
	/*
	User Defined Attribute
	*/
	/**
	
	*/
	private: int _pin;
	/**
	
	*/
	private: float _K;
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
	@param pin	
	@param K	
	*/
	public: void ConfigParam(int pin, float K);
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
};

/* Procedure Template
*/

#endif /* MotorDriver_H */
