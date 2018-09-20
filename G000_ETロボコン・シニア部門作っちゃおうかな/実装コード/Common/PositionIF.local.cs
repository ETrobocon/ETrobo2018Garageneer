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

    public delegate Std_ReturnType PPort_PositionIF(PositionIF i);
    public delegate Std_ReturnType PPortEv_PositionIF(PositionIF i);
    public delegate Std_ReturnType RPort_PositionIF(out PositionIF i);
    public delegate Std_ReturnType RPortEv_PositionIF(out PositionIF i);
  
    /**
姿勢のYow、Roll、Pitch
    @author eguchi
    @version 1.0
    */
    public partial class PositionIF
    {
        /*
        User Defined Attribute
        */
        /**
	進行方向の向き（-180..+180）
0x8000のときはERRORを示す。
0x7FFFのときは準備中を示す。
        */
        public int16_t yaw;
        /**
	左右の傾き（-180..+180）
        */
        public int16_t roll;
        /**
	前後の傾き（-180..+180）
        */
        public int16_t pitch;
        /**
	
        */
        public int8_t status;
    }

}

/* Template for PositionIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PositionIF
    {
        
    }
}
*/
  