/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,EnumDataType.local.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */


using BricRoboRTE;
using int8_t = System.SByte;
using int16_t = System.Int16;

namespace BricRoboApp
{

    /**
ArduinoとRaspiがCOMで通信するとき、頭につける２バイトのマジックナンバー。この番号がついていないと正しいパケットとはみなさない。
    @author ike
    @version 1.0
    */
    public enum TeniboComMagic
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        MAGIC_1 = 0xAA,
        /**
	
        */
        MAGIC_2 = 0xBB
    }

}
