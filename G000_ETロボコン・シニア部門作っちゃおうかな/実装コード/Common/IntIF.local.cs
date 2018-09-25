/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,SenderReceiverInterface.local.xsl
	Generated Date:2017/01/23 13:47:48
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */


using BricRoboRTE;
using OpenCvSharp;
using int8_t = System.SByte;
using uint8_t = System.Byte;
using int16_t = System.Int16;
using uint16_t = System.UInt16;

namespace BricRoboApp
{

    public delegate Std_ReturnType PPort_IntIF(IntIF i);
    public delegate Std_ReturnType PPortEv_IntIF(IntIF i);
    public delegate Std_ReturnType RPort_IntIF(out IntIF i);
    public delegate Std_ReturnType RPortEv_IntIF(out IntIF i);
  
    /**
値Intを扱うIF
    @author eguchi
    @version 1.0
    */
    public partial class IntIF
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        public int value;
    }

}

/* Template for IntIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class IntIF
    {
        
    }
}
*/
  