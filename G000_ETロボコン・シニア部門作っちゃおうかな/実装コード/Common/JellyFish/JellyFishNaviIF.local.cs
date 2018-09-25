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

    public delegate Std_ReturnType PPort_JellyFishNaviIF(JellyFishNaviIF i);
    public delegate Std_ReturnType PPortEv_JellyFishNaviIF(JellyFishNaviIF i);
    public delegate Std_ReturnType RPort_JellyFishNaviIF(out JellyFishNaviIF i);
    public delegate Std_ReturnType RPortEv_JellyFishNaviIF(out JellyFishNaviIF i);
  
    /**
ロボットからプロポに通知するナビ情報
    @author ike
    @version 1.0
    */
    public partial class JellyFishNaviIF
    {
        /*
        User Defined Attribute
        */
        /**
	電源バッテリ電圧。1,200は12.00V
        */
        public int16_t battery;
        /**
	漏水センサーの値。
        */
        public int16_t flood;
        /**
	ロボットの状態
        */
        public uint8_t status;
        /**
	現在のナビ値。
        */
        public JellyFishNavi curNavi;
    }

}

/* Template for JellyFishNaviIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class JellyFishNaviIF
    {
        
    }
}
*/
  