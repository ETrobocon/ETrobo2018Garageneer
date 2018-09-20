#include "stdafx.h"
#include "LedPatternOuter.h"

void LedPatternOuter::Out(int8_t ptn)
{
	ValueIF v;
	v.value = ptn;
	Rte_Send_out(v);
}
