#include "stdafx.h"
#include "LinearConverter.h"

void LinearConverter::ConfigParam(float a, float b)
{
	_a = a;
	_b = b;
}

void LinearConverter::Run()
{
	ValueIF in;
	if( Rte_Read_in(in) == RTE_E_OK )
	{
		ValueIF out;
		out.value = (int)(_a * (float)in.value + _b);
		Rte_Write_out(out);
	}
}
