#include "stdafx.h"
#include "Monitor.h"

void Monitor::Run()
{
#if 1
	uView.clear(PAGE);

	PositionIF position;
    Rte_Read_position(position);
	switch( position.status )
	{
	case POS_NOT_READY:
		uView.setCursor(0,0);
		uView.print("INT");
		break;
	case POS_ERROR:
		uView.setCursor(0,0);
		uView.print("ERR");
		break;
	case POS_WORKING:
		uView.setCursor(0,0);
		uView.print("Y:");
		uView.print(position.yow);
		uView.setCursor(0,8);
		uView.print("R:");
		uView.print(position.roll);
		uView.setCursor(0,16);
		uView.print("P:");
		uView.print(position.pitch);
		break;
	}

	ValueIF jet;
    Rte_Read_jet(jet);
	uView.setCursor(0,24);
	uView.print("J:");
	uView.print(jet.value);

	ValueIF pecFin;
    Rte_Read_pecFin(pecFin);
	uView.setCursor(0,32);
	uView.print("F:");
	uView.print(pecFin.value);
	
	ValueIF tailFin;
    Rte_Read_tailFin(tailFin);
	uView.setCursor(0,40);
	uView.print("T:");
	uView.print(tailFin.value);

	ValueIF waterDepth;
    Rte_Read_waterDepth(waterDepth);
	uView.setCursor(40,40);
	uView.print("D");
	uView.print(waterDepth.value);


	uView.setCursor(40,0);
	CommandIF command;
    if( Rte_Receive_command(command) == RTE_E_OK )
	{
		char* label = "???";
		switch( command.cmd )
		{
		case CMD_CTL:
			label = "CTL";
			break;;
		}
		uView.print(label);
	}
	else
	{
		uView.print("CMD");
	}

#endif
}
