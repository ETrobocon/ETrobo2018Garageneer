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
ロボットの状態。
    @author eguchi
    @version 1.0
    */
    public enum JellyFishStatusBit
    {
        /*
        User Defined Attribute
        */
        /**
	緊急対処中
        */
        JFS_EMERGENCY = 0x40,
        /**
	セーフティモードのON/OFF
        */
        JFS_SAFETY_MODE = 0x80
    }

}
