#include "stdafx.h"
#include "Telecom.h"

//#define SOFT

void Telecom::ConfigParam(int rx, int tx)
{
#ifdef SOFT
	//_ss = new SoftwareSerial(rx,tx);
	_ss = new SoftwareSerial(1,0);
	_ss->begin(38400);
#else
	Serial.begin(9600);
	Serial.flush();
#endif
}

void Telecom::RunRx()
{
#ifdef SOFT
	uView.clear(PAGE);
	uView.setCursor(0,0);
	if( _ss->available()>0 )
	{
		uint8_t c = _ss->read();
		uView.println(c);
	}
	uView.display();
	/*
	CommandIF command;
	if( _ss->available() >= sizeof(command)+2 )
	{
		if( (_ss->read() == MAGIC_1) && (_ss->read() == MAGIC_2) )
		{
			uint8_t* put = (uint8_t*)&command;
			for( int i = 0; i < sizeof(command); i++ )
			{
				uint8_t c = _ss->read();
				*put = c;
				put++;
			}
			Rte_Send_command(command);
		}
		else
		{
			while( _ss->available() )
			{
				_ss->read();
			}
		}

	}
	*/
#else
	uView.clear(PAGE);
	uView.setCursor(0,0);
	if( Serial.available()>0 )
	{
		uint8_t c = Serial.read();
		uView.println(c);
		Serial.write( c++ );
	}
	else
	{
		uView.print("---");
	}
	uView.display();

#endif
}
void Telecom::RunTx()
{
#ifdef SOFT
	static uint8_t c = 128;
	_ss->write( c++ );
	_ss->flush();

	/*
	NaviIF navi;
    Rte_Read_navi(navi);

	_ss->write( (uint8_t)MAGIC_1 );
	_ss->write( (uint8_t)MAGIC_2 );

	uint8_t* put = (uint8_t*)&navi;
	for( int i = 0; i < sizeof(navi); i++ )
	{
		_ss->write( *put );
		put++;
	}
	*/
#else
	/*
	static uint8_t c = 128;
	Serial.write( c++ );
	Serial.flush();
	*/
#endif
}
