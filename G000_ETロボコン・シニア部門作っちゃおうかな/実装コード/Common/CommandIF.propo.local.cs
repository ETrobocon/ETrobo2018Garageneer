/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,SenderReceiverInterface.local.xsl
	Generated Date:2016/04/08 11:18:13
	Generater Name:BricRoboGen Ver:1.7.3.339  
 */


using BricRoboRTE;
using int8_t = System.SByte;
using uint8_t = System.Byte;
using int16_t = System.Int16;
using uint16_t = System.UInt16;


namespace BricRoboApp
{

    public delegate Std_ReturnType PPort_CommandIF(CommandIF i);
    public delegate Std_ReturnType PPortEv_CommandIF(CommandIF i);
    public delegate Std_ReturnType RPort_CommandIF(out CommandIF i);
    public delegate Std_ReturnType RPortEv_CommandIF(out CommandIF i);
  
    /**
ロボットを制御するコマンド
    @author eguchi
    @version 1.0
    */
    public partial class CommandIF
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
    }

}

/* Template for CommandIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class CommandIF
    {
        
    }
}
*/
  