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
	
        */
        MAGIC_1 = 0xAA,
        /**
	
        */
        MAGIC_2 = 0xBB
    }

}
