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

    public delegate Std_ReturnType PPort_PidParamIF(PidParamIF i);
    public delegate Std_ReturnType PPortEv_PidParamIF(PidParamIF i);
    public delegate Std_ReturnType RPort_PidParamIF(out PidParamIF i);
    public delegate Std_ReturnType RPortEv_PidParamIF(out PidParamIF i);
  
    /**
PIDパラメタ。１は分子、２は分母。
    @author ike
    @version 1.0
    */
    public partial class PidParamIF
    {
        /*
        User Defined Attribute
        */
        /**
	P成分の分子
        */
        public int16_t p1;
        /**
	P成分の分母
        */
        public int16_t p2;
        /**
	I成分の分子
        */
        public int16_t i1;
        /**
	I成分の分母
        */
        public int16_t i2;
        /**
	D成分の分子
        */
        public int16_t d1;
        /**
	D成分の分母
        */
        public int16_t d2;
    }

}

/* Template for PidParamIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PidParamIF
    {
        
    }
}
*/
  