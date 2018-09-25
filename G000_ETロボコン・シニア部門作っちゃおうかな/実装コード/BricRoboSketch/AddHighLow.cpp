#include "stdafx.h"
#include "AddHighLow.h"


void AddHighLow::ConfigParam(uint8_t init)
{
	_bit = init;
}

void AddHighLow::Run()
{
	HighLowIF in;
	Rte_Read_in(in);

	_bit += in.value ? 1 : 0 ;

	HighLowIF out, carry;
	switch( _bit )
	{
	case 0:
		out.value = LOW;
		carry.value = LOW;
		break;
	case 1:
		out.value = HIGH;
		carry.value = LOW;
		break;
	default:
		_bit = 0;
		out.value = LOW;
		carry.value = HIGH;
		break;
	}
	Rte_Write_out(out);
	Rte_Write_carry(carry);
}