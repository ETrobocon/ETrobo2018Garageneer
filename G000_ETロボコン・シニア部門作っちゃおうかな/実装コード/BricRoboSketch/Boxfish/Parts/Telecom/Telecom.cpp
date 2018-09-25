#include "stdafx.h"
#include "Telecom.h"

void Telecom::ConfigParam(int dummy)
{
	//Serial.begin(9600);
	Serial.begin(115200);
	delay(2000);//���肷��܂ő҂�
	//Serial.flush();�����Ă���Ƃ͎v���Ȃ�
	while( Serial.available() >0 )	//�S�~����菜��
	{
		Serial.read();
	}
}

void Telecom::RunRx()
{
	CommandIF command;
	if( Serial.available() >= sizeof(command)+2 )
	{
		if( (Serial.read() == MAGIC_1) && (Serial.read() == MAGIC_2) )
		{
			uint8_t* put = (uint8_t*)&command;
			for( int i = 0; i < sizeof(command); i++ )
			{
				*put = Serial.read();
				put++;
			}
			Rte_Send_command(command);
		}
		else
		{
			//��ǂ݂��đS���̂Ă�
			while( Serial.available() )
			{
				Serial.read();
			}
		}
	}
}
void Telecom::RunTx()
{
	NaviIF navi;
    Rte_Read_navi(navi);

	//�擪�Ƀ}�W�b�N�R�[�h������
	Serial.write( (uint8_t)MAGIC_1 );
	Serial.write( (uint8_t)MAGIC_2 );
	
	/*
	uint8_t* put = (uint8_t*)&navi;
	for( int i = 0; i < sizeof(navi); i++ )
	{
		Serial.write( *put );
		put++;
	}
	*/
	Serial.write( (uint8_t*)&navi, sizeof(navi) );
}
