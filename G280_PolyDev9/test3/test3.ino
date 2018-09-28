#include "MotarControl.h"
#include <Wire.h>

//asciiコード使用
//32~126 : 94進数 - 1
//スタートビット : 0x7e
#define Serial_MIN 0x20
#define Serial_MAX 0x7d
#define Serial_START 0x7e

//データ数
#define DATE_MAX 1

//モータ出力定時
#define MotarOUT_TIME 50

#define IR_BIT_LENGTH 32    // number of bits sent by IR remote
#define FirstLastBit 15     // divide 32 bits into two 15 bit chunks for integer variables. Ignore center two bits. they are all the same.
#define BIT_1 1500          // Binary 1 threshold (Microseconds)
#define BIT_0 450           // Binary 0 threshold (Microseconds)
#define BIT_START 4000      // Start bit threshold (Microseconds)

#define IR_PIN 2            // IR Sensor pin
#define LED_PIN 13          // LED goes off when signal is received

//変数
//入力データ(全て)
int Serial_date[1];
//カウント
int Serial_co = 0;

//外部出力フラグ
bool OUTPUT_PM = true;

//モータ出力時間
unsigned long Time_MotarOUT = 0;

int debug = 0;              // flag as 1 to output raw IR pulse data stream length in microseconds
int output_verify = 0;      // flag as 1 to print decoded verification integers. same number for all buttons
int output_key = 0;         // flag as 1 to print decoded key integers
int remote_verify = 16128;  // verifies first bits are 11111100000000 different remotes may have different start codes



//出力処理
void Motar_process(void) {


  //50ms 毎に出力
  if ((millis() - Time_MotarOUT) > MotarOUT_TIME) {
    //ショートブレイク防止
    //ShortBreak();

    //モータ出力
    MoR(CH1_val, CH2_val);

    //更新

    Time_MotarOUT = millis();
    //def

    Serial.print(CH1_val);
    Serial.print(",");
    Serial.print(CH2_val);
    Serial.print("\n");
    /*  Serial.print(CH3_val);
        Serial.print(",");
        Serial.print(CH4_val);
        Serial.println(",");*/
  }
}

void setup() {
  Serial.begin(9600);
  Motar_Custom();
  pinMode(LED_PIN, OUTPUT);  //This shows when ready to recieve
  pinMode(IR_PIN, INPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(2, INPUT);
  pinMode(3, INPUT);

  //Serial.begin(9600);
}

void loop() {
  int Rainval0 = analogRead(A0);
  int Rainval1 = analogRead(A1);
  int Rainval2 = analogRead(A2);
  int Rainval3 = analogRead(A3);
  int limit1 = 0;
  int limit2 = 0;

  while (1) {
    Rainval0 = analogRead(A0);
    Rainval1 = analogRead(A1);
    Rainval2 = analogRead(A2);
    Rainval3 = analogRead(A3);

    //-------------------------------------------------------------------
    char c;

    //digitalWrite(LED_PIN, HIGH);
    //int key = get_ir_key();
    //digitalWrite(LED_PIN, LOW);  // turn LED off while processing response
    //do_response(key);
    //delay(130);

    //出力処理
    if (OUTPUT_PM == true) {
      Motar_process();
    }

    Serial.print("Moisture Level: ");
    Serial.print(analogRead(A0));
    Serial.print(",");
    Serial.print(analogRead(A1));
    Serial.print(",");
    Serial.print(analogRead(A2));
    Serial.print(",");
    Serial.print(analogRead(A3));
    Serial.print("\n");
    delay(500);


    //晴れ
    if (Rainval0 >= 900 && Rainval1 >= 900 && Rainval2 >= 900 && Rainval3 >= 900) {
      Serial.print("晴");
      Serial.print("\n");
      CH1_val = CH2_val = -30;
      limit1 = 1;
      limit2 = 0;
    }
    //雨１
    else if (Rainval0 < 900 && Rainval1 >= 900 && Rainval2 >= 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 < 900 && Rainval2 >= 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 >= 900 && Rainval2 < 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 >= 900 && Rainval2 >= 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    //雨２
    else if (Rainval0 < 900 && Rainval1 < 900 && Rainval2 >= 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 < 900 && Rainval2 < 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 >= 900 && Rainval2 < 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 < 900 && Rainval1 >= 900 && Rainval2 >= 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    //雨３
    else if (Rainval0 < 900 && Rainval1 < 900 && Rainval2 < 900 && Rainval3 >= 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 >= 900 && Rainval1 < 900 && Rainval2 < 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 < 900 && Rainval1 >= 900 && Rainval2 < 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    else if (Rainval0 < 900 && Rainval1 < 900 && Rainval2 >= 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }
    //雨４
    else if (Rainval0 < 900 && Rainval1 < 900 && Rainval2 < 900 && Rainval3 < 900) {
      Serial.print("雨");
      Serial.print("\n");
      CH1_val = CH2_val = 30;
      limit2 = 1;
      limit1 = 0;
    }



    if (digitalRead(2) == HIGH && limit1 == 1) {
      Serial.print(digitalRead(2));
      Serial.print("\n");
      Serial.print("OPEN限界");
      Serial.print("\n");
      CH1_val = CH2_val = 0;

      if (limit2 == 1) {
        CH1_val = CH2_val = 30;
        delay(500);
      }
    }
    if (digitalRead(3) == HIGH && limit2 == 1) {
      Serial.print(digitalRead(3));
      Serial.print("\n");
      Serial.print("CLOSE限界");
      Serial.print("\n");
      CH1_val = CH2_val = 0;

      if (limit1 == 1) {
        CH1_val = CH2_val = -30;
        delay(500);
      }
    }

    //-------------------------------------------------------------------
  }

}



