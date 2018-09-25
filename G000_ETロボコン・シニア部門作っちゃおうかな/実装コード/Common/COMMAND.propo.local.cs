/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,EnumDataType.local.xsl
	Generated Date:2016/04/08 11:18:13
	Generater Name:BricRoboGen Ver:1.7.3.339  
 */


using int8_t = System.SByte;
using int16_t = System.Int16;

namespace BricRoboApp
{

    /**

    @author eguchi
    @version 1.0
    */
    public enum COMMAND
    {
        /*
        User Defined Attribute
        */
        /**
	すべての稼働を停止する。推進力は０に、尾ビレ、胸ビレの角度は０度にする。
param:無視
        */
        CMD_STOP = 0,
        /**
	胸ビレ、尾ビレに0を指定したときの角度オフセットを設定する。
param:1-胸ビレ45..+45
param2:尾ビレ-70..+70

        */
        CMD_SET_FIN_OFFSET = 1,
        /**
	浸水センサーの浸水判定値をセットする。
param1:セットする値
        */
        CMD_SET_FLOOD_ALARM = 2,
        /**
	ライトをON/OFFする
param1:0=OFF ,1=ON
        */
        CMD_LIGHT_ON = 3,
        /**
	
        */
        CMD_SET_STATUS_LIGHT = 4,
        /**
	赤と白のLEDをモールス信号で点滅させる
param1: ０から９９
        */
        CMD_LED_MORSE = 5,
        /**
	
        */
        CMD_RESET_NAVI = 6,
        /**
	
        */
        CMD_SET_DIR = 7,
        /**
	推進パワー、胸ビレ、尾ビレを指定する。
param1:推進パワー0..100
param2:胸ビレ-45..+45
param3:尾ビレ-70..+70
        */
        CMD_CTL = 10,
        /**
	ビデオ撮影をON/OFFする
param1: 0,1=録画開始チャネル -1=録画停止 
        */
        CMD_REC_VIDEO = 11,
        /**
	セーフティモードのOF.OFF
param1: 0=OFF 1=ON
        */
        CMD_SAFETY_MODE = 12,
        /**
	引数で指定した戦略ファイルを読み直し、指定番号の戦略再生を準備する。指定番号とは、戦略一覧の上からの番号で、０始まりである。
param1=戦略番号

        */
        CMD_RELOAD_STRATEGY = 19,
        /**
	自動航行モードをON/OFFする。
param1: 0=OFF 1=ON
        */
        CMD_AUTO_MODE = 20,
        /**
	LOW(H,S,V) HI(H,S,V)
param1=HI(H) &lt;&lt; 8 |  LOW(H)
param2=HI(S) &lt;&lt; 8 |  LOW(S)
param3=HI(V) &lt;&lt; 8 |  LOW(V)
        */
        CMD_SEARCH_BOUY_COLOR = 21,
        /**
	
        */
        CMD_SEARCH_LINE_COLOR = 22,
        /**
	尾ビレの角度を指定するわけではなく、前傾姿勢、後傾姿勢の角度を指定する。
傾斜は限界値以上にならない。
        */
        CMD_CTL_CAUDAL = 23,
        /**
	子機を投下する
param1=0/1 (1=投下)
        */
        CMD_FIRE_BOMB = 24
    }

}
