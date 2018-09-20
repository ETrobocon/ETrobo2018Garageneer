/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,SenderReceiverInterface.local.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */


using BricRoboRTE;
using OpenCvSharp;
using int8_t = System.SByte;
using uint8_t = System.Byte;
using int16_t = System.Int16;
using uint16_t = System.UInt16;

namespace BricRoboApp
{

    public delegate Std_ReturnType PPort_SpeechIF(SpeechIF i);
    public delegate Std_ReturnType PPortEv_SpeechIF(SpeechIF i);
    public delegate Std_ReturnType RPort_SpeechIF(out SpeechIF i);
    public delegate Std_ReturnType RPortEv_SpeechIF(out SpeechIF i);
  
    /**

    @author ike
    @version 1.0
    */
    public partial class SpeechIF
    {
        /*
        User Defined Attribute
        */
        /**
	発音する文章
        */
        public string text;
    }

}

/* Template for SpeechIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class SpeechIF
    {
        
    }
}
*/
  