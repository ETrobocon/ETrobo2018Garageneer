#include "stdafx.h"
#include "HighLowInverter.h"

void HighLowInverter::Run()
{
	HighLowIF v;
	if( Rte_Read_in(v) == RTE_E_OK )
	{
		v.value = v.value != LOW ? LOW : HIGH;
		Rte_Write_out(v);
	}
}
