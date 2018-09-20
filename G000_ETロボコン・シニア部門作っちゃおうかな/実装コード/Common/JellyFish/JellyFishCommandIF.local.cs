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

    public delegate Std_ReturnType PPort_JellyFishCommandIF(JellyFishCommandIF i);
    public delegate Std_ReturnType PPortEv_JellyFishCommandIF(JellyFishCommandIF i);
    public delegate Std_ReturnType RPort_JellyFishCommandIF(out JellyFishCommandIF i);
    public delegate Std_ReturnType RPortEv_JellyFishCommandIF(out JellyFishCommandIF i);
  
    /**
ロボットを制御するコマンド
    @author eguchi
    @version 1.0
    */
    public partial class JellyFishCommandIF
    {
        /*
        User Defined Attribute
        */
        /**
	コマンド
        */
        public uint8_t cmd;
        /**
	パラメータ。値の意味はコマンドにより決定する。
        */
        public int16_t param1;
        /**
	パラメータ。値の意味はコマンドにより決定する。
        */
        public int16_t param2;
        /**
	パラメータ。値の意味はコマンドにより決定する。
        */
        public int16_t param3;
        /**
	パラメータ。値の意味はコマンドにより決定する。
        */
        public int16_t param4;
    }

}

/* Template for JellyFishCommandIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class JellyFishCommandIF
    {
        
    }
}
*/
  