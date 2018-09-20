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

    public delegate Std_ReturnType PPort_EventIF(EventIF i);
    public delegate Std_ReturnType PPortEv_EventIF(EventIF i);
    public delegate Std_ReturnType RPort_EventIF(out EventIF i);
    public delegate Std_ReturnType RPortEv_EventIF(out EventIF i);
  
    /**
イベントが発生したことを表す。メンバはない。
    @author eguchi
    @version 1.0
    */
    public partial class EventIF
    {
        /*
        User Defined Attribute
        */
    }

}

/* Template for EventIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class EventIF
    {
        
    }
}
*/
  