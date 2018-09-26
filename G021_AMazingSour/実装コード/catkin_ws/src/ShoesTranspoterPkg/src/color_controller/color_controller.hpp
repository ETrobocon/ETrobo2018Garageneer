#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <time.h>

/* 列挙型：検出する色 */
enum EN_Color
{
	en_color_red,                         /* 赤色(0) */
	en_color_green,                       /* 緑色(1) */
	en_color_blue,                        /* 青色(2) */
	en_color_yellow,                      /* 黄色(3) */
	en_color_black,                       /* 黒色(4) */
	en_color_error
};

/* クラス：カラーコントローラ（カラーセンサ制御クラス） */
class ColorController
{
/* アトリビュート */
private:  //非公開部分
	int m_color_r;                        /* rの値 */
	int m_color_g;                        /* gの値 */
	int m_color_b;                        /* bの値 */
	char *m_bus = "/dev/i2c-1";  /* i2cの通信バスへのパス */
	int m_file;			/* カラーセンサの通信バス */
	int m_flag = 0;			/* カラーセンサの初期化フラグ */

/* コンストラクタとデストラクタ */
public: //公開部分
	     ColorController(){};                    /* コンストラクタ */
    	~ColorController(){};                   /* デストラクタ */

/* メソッド */
public: //公開部分
	EN_Color getColor();                  /* 色情報取得 */
	EN_Color classifyColor();             /* 色の識別 */
	void initColor();			/* カラーセンサ初期化関数 */
};

#define COLOR_THRESHOLD_F 0.5    /* 割合が最大となるrgbを見つけるための閾値 */
#define COLOR_THRESHOLD_S 0.3     /* 割合が2番目に大きいrgbを見つけるための閾値*/
#define COLOR_THRESHOLD 20000    /* 黄色検出のための閾値 */