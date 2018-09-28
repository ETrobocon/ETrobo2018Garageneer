 // 定義
//i2c / ダイセンボード
#include <Wire.h>


// --------------------   関数  ----------------------------
//初期化
void Motar_Custom(void);
//ShortBreak防止
//void ShortBreak(void);
//モータ出力
void MoR(int m1, int m2);

// ----------------------------------------------------------

// --------------------  編集　（調整）  ----------------------------------
//モータ回転方向
// 1:正転方向　-1:逆転方向
#define CH1_SP 1
#define CH2_SP 1
//#define CH3_SP 1
//#define CH4_SP 1

//モータ出力調節パラメータ
// 0.00 ~ 1.00
#define CH1_PM 1.00
#define CH2_PM 1.00
//#define CH3_PM 1.00
//#define CH4_PM 1.00

//スピード コントロール
// 1:有効 0:無効
#define SPEED_COT 0

//モータ最大出力値 80%
#define MOVE_MAX 0.8

//ショートブレイク防止時間(ms)
//#define ShortBreak_TIME 500

// -----------------------------------------------------------------------



// --------------------  変数  ----------------------------------
//各モータ・現在出力値
int CH1_val = 0;
int CH2_val = 0;
//int CH3_val = 0;
//int CH4_val = 0;

//各モータ・過去出力値
int CH1_old = 0;
int CH2_old = 0;
//int CH3_old = 0;
//int CH4_old = 0;

//強制停止時間
unsigned long Time_Break = 0;

// --------------------------------------------------------------

// ------------------  初期化  -----------------------------
void Motar_Custom(void) {
  //i2c
  Wire.begin();
}
// ---------------------------------------------------------
/*
  //---------------[ショートブレイク防止]---------------------
  void ShortBreak(void){
  //強制停止フラグ
  int BREAK = 0;

  //条件
  // ・出力停止信号が入ってから一定時間を経過していない
  // ・逆動作を急激に入った場合

  if((millis() - Time_Break) < ShortBreak_TIME){ // 500ms 以下
    CH1_val = 999;
    CH2_val = 999;
    CH3_val = 999;
    CH4_val = 999;
  }
  else{ //以上

    //すべて停止
    int old_val = CH1_old + CH2_old + CH3_old + CH4_old;
    if((CH1_val == 0) && (CH2_val == 0) && (CH3_val == 0) && (CH4_val == 0) &&
       (CH1_old != 0) && (CH2_old != 0) && (CH3_old != 0) && (CH4_old != 0) )
    {
      Time_Break = millis();
      BREAK = 1;
    }
    //各モータ
    if( ( ((CH1_val > 0) && (CH1_old < 0)) || ((CH1_val < 0) && (CH1_old > 0)) ) || //CH1
        ( ((CH2_val > 0) && (CH2_old < 0)) || ((CH2_val < 0) && (CH2_old > 0)) ) || //CH2
        ( ((CH3_val > 0) && (CH3_old < 0)) || ((CH3_val < 0) && (CH3_old > 0)) ) || //CH3
        ( ((CH4_val > 0) && (CH4_old < 0)) || ((CH4_val < 0) && (CH4_old > 0)) ) )  //CH4
    {
      Time_Break = millis();
      BREAK = 1;
    }

    //ブレイク処理
    if(BREAK){
      CH1_val = 999;
      CH2_val = 999;
      CH3_val = 999;
      CH4_val = 999;
      CH1_old = 0;
      CH2_old = 0;
      CH3_old = 0;
      CH4_old = 0;
    }
    else{
      CH1_old = CH1_val;
      CH2_old = CH2_val;
      CH3_old = CH3_val;
      CH4_old = CH4_val;
    }
  }
  }*/


//---------------[モータ出力]---------------------
void MoR(int m1, int m2) {
  //m1=30,m2=30,m3=30,m4=30;
  int mopp[4] = {0, 0, 0, 0};//
  //ブレーキ
  if ((m1 == 999) && (m2 == 999)) {
    mopp[0] = m1; //30
    mopp[1] = m2;
    //mopp[2] = m3;
    //mopp[3] = m4;
  }
  else {
    mopp[0] = m1 * CH1_SP * CH1_PM * MOVE_MAX;
    mopp[1] = m2 * CH2_SP * CH2_PM * MOVE_MAX;
    //mopp[2] = m3 * CH3_SP * CH3_PM * MOVE_MAX;
    //mopp[3] = m4 * CH4_SP * CH4_PM * MOVE_MAX;
    //mopp[0] = m1 * CH1_SP * CH1_PM * 1;
    //mopp[1] = m2 * CH2_SP * CH2_PM * 1;
    //mopp[2] = m3 * CH3_SP * CH3_PM * 1;
    //mopp[3] = m4 * CH4_SP * CH4_PM * 1;
  }


  //送信処理
  for (int i = 0; i < 4; i++) {
    if (mopp[i] < 0 && mopp[i] >= -100) {
      mopp[i] = abs(mopp[i]);
      mopp[i] = mopp[i] + 128;
    } else if (mopp[i] > 0 && mopp[i] <= 100) {
      mopp[i] = mopp[i];
    } else if (mopp[i] == 0) {
      mopp[i] = 0;
    } else if (mopp[i] == 999 || mopp[i] == -999) {
      mopp[i] = 128;
    } else {
      return;
    }
  }//


  interrupts(); // <- インターラプト割り込みを止めない

  //I2C
  Wire.beginTransmission(0x14 >> 1);
  Wire.write(mopp[0]); // 1ch
  Wire.write(mopp[1]); // 2ch
  Wire.write(0); // 3ch
  Wire.write(0); // 4ch
  Wire.write(0); // 5ch
  Wire.write(0); // 6ch
  Wire.endTransmission();
}
//----------------------------------------



