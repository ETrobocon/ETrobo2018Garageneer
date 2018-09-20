#include "stdafx.h"
#include "Telecom.h"


void Telecom::ConfigParam(int dummy)
{
	//Serial.begin(9600);
	Serial.begin(115200);
	delay(2000);//���肷��܂ő҂�
	while (Serial.available() >0)	//�S�~����菜��
	{
		Serial.read();
	}
}

void Telecom::RunRcv()
{
	JellyFishCommandIF command;
	if (Serial.available() >= sizeof(command) + 2)
	{
		if ((Serial.read() == MAGIC_1) && (Serial.read() == MAGIC_2))
		{
			uint8_t* put = (uint8_t*)&command;
			for (int i = 0; i < sizeof(command); i++)
			{
				*put = Serial.read();
				put++;
			}
			Rte_Send_command(command);
		}
		else
		{
			//��ǂ݂��đS���̂Ă�
			while (Serial.available())
			{
				Serial.read();
			}
		}
	}
}
void Telecom::RunSend()
{
#if 0
	JellyFishNaviIF navi;
	int s = sizeof(navi);
	//Serial.print("1234567890 ");
	Serial.print(s, DEC);
#else
	JellyFishNaviIF navi;
	Rte_Read_navi(navi);

	//�擪�Ƀ}�W�b�N�R�[�h������
	Serial.write((uint8_t)MAGIC_1);
	Serial.write((uint8_t)MAGIC_2);

	Serial.write((uint8_t*)&navi, sizeof(navi));
#endif
}
