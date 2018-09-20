/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,EnumDataType.local.xsl
	Generated Date:2017/01/23 13:47:48
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */


using BricRoboRTE;
using int8_t = System.SByte;
using int16_t = System.Int16;

namespace BricRoboApp
{

    /**
ロボットに命令するコマンドの種類。
    @author eguchi
    @version 1.0
    */
    public enum JellyFishCmd
    {
        /*
        User Defined Attribute
        */
        /**
	すべての稼働を停止する。モーターを止める。
param:無視
        */
        JFCMD_STOP = 0,
        /**
	浸水センサーの浸水判定値をセットする。
param1:セットする値
        */
        JFCMD_SET_FLOOD_ALARM = 2,
        /**
	ナビゲーションの基準値を現在の姿勢でリセットする。マルチローター用。
param:無視
        */
        JFCMD_RESET_NAVI = 6,
        /**
	現在の方向が０度になるようにリセットする。マルチローター用。
param:無視
        */
        __JFCMD_RESET_DIR = 7,
        /**
	姿勢を制御する。マルチローター用。
param1=向き(Dir)
param2=水深(Depth)
param3=ピッチ(Pitch)
param4=ロール(Roll)

        */
        __JFCMD_CTL = 10,
        /**
	直接モーターを回して制御する。
param1=dive
param2=roll
param3=forward
param4=turn

        */
        JFCMD_CTL_DIRECT = 11,
        /**
	セーフティモードのOF.OFF
param1: 0=OFF 1=ON
        */
        JFCMD_SAFETY_MODE = 12,
        /**
	スタビライザーのON.OFF
param1:
bit0=水平 
bit1=垂直
bit2=目標型、param2, param3の値有効
param2: 目標方位(度)
param3: 目標深度(cm)
        */
        JFCMD_STABI = 13,
        /**
	スタビライザーの水平方向パラメタ設定。分母は100固定。
p1=param1
i1=param2
d1=param3

        */
        JFCMD_STABI_PID_DIR = 14,
        /**
	スタビライザーの垂直（水深）歩行パラメタ設定。分母は100固定。
p1=param1
i1=param2
d1=param3

        */
        JFCMD_STABI_PID_DEP = 15,
        /**
	4つのESCのデッドゾーンを設定する
param1=DIVE_R
param2_DIVE_L
param3=RIGHT
param4=LEFT
        */
        JFCMD_SET_DEAD_ZONE = 16
    }

}
