/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
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

    public delegate Std_ReturnType PPort_TimeSpanIF(TimeSpanIF i);
    public delegate Std_ReturnType PPortEv_TimeSpanIF(TimeSpanIF i);
    public delegate Std_ReturnType RPort_TimeSpanIF(out TimeSpanIF i);
    public delegate Std_ReturnType RPortEv_TimeSpanIF(out TimeSpanIF i);
  
    /**
�o�ߎ��Ԃ�\��
    @author eguchi
    @version 1.0
    */
    public partial class TimeSpanIF
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        public System.TimeSpan value;
    }

}

/* Template for TimeSpanIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class TimeSpanIF
    {
        
    }
}
*/
  