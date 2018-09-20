/*
	[NOTE] This file is automatically generated. Please do not hand-coded.
  
	Template:C++,CompositionType.h.xsl
	Generated Date:2014/02/22 14:08:27
	Generater Name:BricRoboGen Ver:1.6.0.305  
 */
#ifndef LinearConverter_H
#define LinearConverter_H

#include "ValueIF.h"

/*
void LinearConverter::ConfigParam(float a, float b)
{
}
  void LinearConverter::Run()
{
	ValueIF in;
    Rte_Read_in(in);
	ValueIF out;
    Rte_Write_out(out);

}
*/


/**
入力した値を、1次方程式にしたがって、値を変換して、出力します。
式は　y = a* x + b とします。
x: 入力値
a, b : 係数
y: 出力値
@author ike
@version 1.0
*/
class LinearConverter
{
	/*
	User Defined Attribute
	*/
	/**
	係数a
	*/
	public: float _a;
	/**
	係数b
	*/
	public: float _b;
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
	@param a	係数a
	@param b	係数b
	*/
	public: void ConfigParam(float a, float b);
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

#endif /* LinearConverter_H */
