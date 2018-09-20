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

    public delegate Std_ReturnType PPort_TeniboCommandIF(TeniboCommandIF i);
    public delegate Std_ReturnType PPortEv_TeniboCommandIF(TeniboCommandIF i);
    public delegate Std_ReturnType RPort_TeniboCommandIF(out TeniboCommandIF i);
    public delegate Std_ReturnType RPortEv_TeniboCommandIF(out TeniboCommandIF i);
  
    /**
ロボットを制御するコマンド
    @author eguchi
    @version 1.0
    */
    public partial class TeniboCommandIF
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
	
        */
        public int16_t param4;
        /**
	
        */
        public int16_t param5;
    }

}

/* Template for TeniboCommandIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class TeniboCommandIF
    {
        
    }
}
*/
  