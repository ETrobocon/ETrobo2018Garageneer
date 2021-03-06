#include "stdafx.h"
#include "Telecom.h"

void Telecom::ConfigParam(int dummy)
{
	Serial.begin(115200);
	delay(2000);//安定するまで待つ
				//Serial.flush();効いているとは思えない
	while (Serial.available() >0)	//ゴミを取り除く
	{
		Serial.read();
	}
}

void Telecom::RunRx()
{
	TeniboCommandIF command;
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
			  //空読みして全部捨てる
			  while (Serial.available())
			  {
				  Serial.read();
			  }
		  }
	  }
}

void Telecom::RunTx()
{
	TeniboNaviIF navi;
	Rte_Read_navi(navi);

	//先頭にマジックコードをつける
	Serial.write((uint8_t)MAGIC_1);
	Serial.write((uint8_t)MAGIC_2);

	Serial.write((uint8_t*)&navi, sizeof(navi));
}
