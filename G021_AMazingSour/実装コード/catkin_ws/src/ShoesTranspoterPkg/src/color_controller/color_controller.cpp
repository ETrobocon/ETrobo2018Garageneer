#include "color_controller.hpp"

/******************************************************************************
 * 関数名 | EN_Color getColor()                                               *
 * 概要   | 色情報取得関数                                                    *
 * 引数   | なし                                                              *
 * 戻り値 | 色                                                                *
 * 詳細   | 指定した色を検出する。                                            *
 ******************************************************************************/
EN_Color ColorController::getColor()
{
	// カラーセンサの初期化
	initColor();

	// データ取得処理
	// Read 8 bytes of data from register(0x94)
	// register(0x94) = cData lsb, cData msb, red lsb, red msb, green lsb, green msb, blue lsb, blue msb
	// 今回使用するのはRGBのみのため上位8bitと下位8bitを使用
	char reg[1] = { 0x94 }; // 読み込むレジスタ（0x94）
	write(m_file, reg, 1); //m_fileにレジスタの値を書き込み
	char data[8] = { 0 }; // register(0x94)の値格納用変数、0で初期化
	
	// m_fileに書き込んだ値を変数dataに格納
	if (read(m_file, data, 8) != 8)
	{
		// 値の読み込み失敗
		printf("Erorr : Input/output Erorr \n");
	}
	else
	{
		// Convert the data
		m_color_r = (data[3] * 256 + data[2]);       /* 赤の値（最大値：65535）*/
		m_color_g = (data[5] * 256 + data[4]);      /* 緑の値（最大値：65535）*/
		m_color_b = (data[7] * 256 + data[6]);      /* 青の値（最大値：65535）*/
	}
	// 色を判別して、色の種類を返す
	return classifyColor();
}

/******************************************************************************
 * 関数名 | EN_Color classifyColor();                                         *
 * 概要   | 色判別関数                                                        *
 * 引数   | なし                                                              *
 * 戻り値 | 色                                                                *
 * 詳細   | どの色かを判定する関数                                            *
 ******************************************************************************/
EN_Color ColorController::classifyColor()
{
	int i = 10;		// 出力変数、初期値は外れ値を格納。
	float temp_sum = m_color_r + m_color_g + m_color_b;		// 正規化用のrgb総和
	float temp_color_rate[3];	// rgbの総和に対する割合（正規化したrgb値）

	// rgbの正規化
	temp_color_rate[0] = ((float)m_color_r)/temp_sum;
	temp_color_rate[1] = ((float)m_color_g)/temp_sum;
	temp_color_rate[2] = ((float)m_color_b)/temp_sum;

	// 色判別処理
	// 赤色判別
	if(temp_color_rate[0] >= COLOR_THRESHOLD_F)
	{
		i = en_color_red;
	}
	// 緑色判別
	if(temp_color_rate[1] >= COLOR_THRESHOLD_F)
	{
		i = en_color_green;
	}
	// 青色判別
	if(temp_color_rate[2] >= (COLOR_THRESHOLD_F)-0.1) // bはrgに比べて値が小さいため、オフセット
	{
		i = en_color_blue;
	}
	
	// 黄色／黒色（白色）判別
	// 黄色はrとgが高くなる
	if(temp_color_rate[0] >= COLOR_THRESHOLD_S && temp_color_rate[1] >= COLOR_THRESHOLD_S)
	{
		// 黄色はbが低くなるが、割合のみで判別すると白や黒でもbだけが異様に低い状態があるのでrの値で判別
		if(temp_color_rate[2] < COLOR_THRESHOLD_S && m_color_r >= COLOR_THRESHOLD)
		{
			i = en_color_yellow;
		}
		else
		{
			i = en_color_black;
		}
	}
	if (i == 10) /* 初期値のままなら黒色判定 */
	{
		i = en_color_black;
	}

	/* 識別完了 */
	// 判別した色を返す
	switch(i){
		case en_color_red:
			return en_color_red;
			break;
		case en_color_green:
			return en_color_green;
			break;
		case en_color_blue:
			return en_color_blue;
			break;
		case en_color_yellow:
			return en_color_yellow;
			break;
		case en_color_black:
			return en_color_black;
			break;
		default:
			printf("Invalid Color\n"); // エラー
			return en_color_error;
	}
}

/******************************************************************************
 * 関数名 | void initColor();                                                 *
 * 概要   | カラーセンサ初期化関数                                            *
 * 引数   | なし                                                              *
 * 戻り値 | なし                                                              *
 * 詳細   | カラーセンサのバスを取得し、読み込み準備を行う                    *
 ******************************************************************************/
void ColorController::initColor()
{
	// カラーセンサの初期化は最初に色を取得する1度のみ実行
	if(m_flag == 0)
	{
		m_flag++; // フラグ反転
		m_file = open(m_bus, O_RDWR); // 通信バスの取得
		
		// バスが取得できたか判定
        if (m_file < 0)
        {
                printf("Failed to open the bus. \n");
                exit(1);
        }
		
        // Get I2C device, TCS34725 I2C address is 0x29(41)
        ioctl(m_file, I2C_SLAVE, 0x29);

        // Select enable register(0x80)
        // Power ON, RGBC enable, wait time disable(0x03)
        char config[2] = { 0 };
        config[0] = 0x80;
        config[1] = 0x03;
        write(m_file, config, 2);
        
		// Select ALS time register(0x81)
        // Atime = 700 ms(0x00)
        config[0] = 0x81;
        config[1] = 0x00;
        write(m_file, config, 2);
        
		// Select Wait Time register(0x83)
        // WTIME : 2.4ms(0xFF)
        config[0] = 0x83;
        config[1] = 0xFF;
        write(m_file, config, 2);
        
		// Select control register(0x8F)
        // AGAIN = 1x(0x00)
        config[0] = 0x8F;
        config[1] = 0x00;
        write(m_file, config, 2);
		
        sleep(1); // 設定完了に1s程度waitが必要
	}
}
