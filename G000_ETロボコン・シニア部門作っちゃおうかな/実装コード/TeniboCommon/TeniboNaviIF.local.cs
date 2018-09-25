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

    public delegate Std_ReturnType PPort_TeniboNaviIF(TeniboNaviIF i);
    public delegate Std_ReturnType PPortEv_TeniboNaviIF(TeniboNaviIF i);
    public delegate Std_ReturnType RPort_TeniboNaviIF(out TeniboNaviIF i);
    public delegate Std_ReturnType RPortEv_TeniboNaviIF(out TeniboNaviIF i);
  
    /**
ロボットからプロポに通知するナビ情報
    @author ike
    @version 1.0
    */
    public partial class TeniboNaviIF
    {
        /*
        User Defined Attribute
        */
        /**
	電源バッテリ電圧。1,200は12.00V
        */
        public int16_t battery;
        /**
	ステータスビットの集合
        */
        public uint16_t status;
    }

}

/* Template for TeniboNaviIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class TeniboNaviIF
    {
        
    }
}
*/
  