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

    public delegate Std_ReturnType PPort_JellyFishNavi(JellyFishNavi i);
    public delegate Std_ReturnType PPortEv_JellyFishNavi(JellyFishNavi i);
    public delegate Std_ReturnType RPort_JellyFishNavi(out JellyFishNavi i);
    public delegate Std_ReturnType RPortEv_JellyFishNavi(out JellyFishNavi i);
  
    /**
マルチローター用。
ロボットのなかで使うナビ情報
    @author ike
    @version 1.0
    */
    public partial class JellyFishNavi
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        public int16_t dir;
        /**
	
        */
        public int16_t depth;
        /**
	
        */
        public int16_t pitch;
        /**
	
        */
        public int16_t roll;
    }

}

/* Template for JellyFishNavi.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class JellyFishNavi
    {
        
    }
}
*/
  