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
ジャイロセンサーの状態
    @author eguchi
    @version 1.0
    */
    public enum PositionStatus
    {
        /*
        User Defined Attribute
        */
        /**
	準備中
        */
        POS_NOT_READY = 0,
        /**
	稼働中

        */
        POS_WORKING = 1,
        /**
	エラー
        */
        POS_ERROR = -1
    }

}
