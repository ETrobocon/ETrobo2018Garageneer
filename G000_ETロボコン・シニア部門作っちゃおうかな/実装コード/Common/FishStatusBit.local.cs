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

    @author eguchi
    @version 1.0
    */
    public enum FishStatusBit
    {
        /*
        User Defined Attribute
        */
        /**
	照明ON
        */
        FS_LIGHT_ON = 0x01,
        /**
	ビデオ録画中（チャネル0）
        */
        FS_VIDEO_REC_OVL = 0x02,
        /**
	ビデオ録画中（チャネル１）
        */
        FS_VIDEO_REC_ORG = 0x04,
        /**
	緊急対処中
        */
        FS_EMERGENCY = 0x40,
        /**
	セーフティモードのON/OFF
        */
        FS_SAFETY_MODE = 0x80
    }

}
