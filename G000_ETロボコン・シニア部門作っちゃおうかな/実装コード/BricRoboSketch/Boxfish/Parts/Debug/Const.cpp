#include "stdafx.h"
#include "Const.h"

void Const::ConfigParam(int value)
{
	ValueIF out;
	out.value = value;

	Rte_Write_out(out);

}
