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
通信の際、先頭に浸けるマジックナンバー。これが一致すれば正しいパケットとみなす。
    @author eguchi
    @version 1.0
    */
    public enum MAGIC_NO
    {
        /*
        User Defined Attribute
        */
        /**
	先頭1バイト目の値。
        */
        MAGIC_1 = 0xAA,
        /**
	先頭2バイト目の値。
        */
        MAGIC_2 = 0xBB
    }

}
