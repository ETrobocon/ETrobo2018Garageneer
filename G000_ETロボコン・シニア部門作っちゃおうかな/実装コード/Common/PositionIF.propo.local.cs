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

    public delegate Std_ReturnType PPort_PositionIF(PositionIF i);
    public delegate Std_ReturnType PPortEv_PositionIF(PositionIF i);
    public delegate Std_ReturnType RPort_PositionIF(out PositionIF i);
    public delegate Std_ReturnType RPortEv_PositionIF(out PositionIF i);
  
    /**
�p����Yow�ARoll�APitch
    @author eguchi
    @version 1.0
    */
    public partial class PositionIF
    {
        /*
        User Defined Attribute
        */
        /**
	�i�s�����̌����i-180..+180�j
0x8000�̂Ƃ���ERROR�������B
0x7FFF�̂Ƃ��͏������������B
        */
        public int16_t yow;
        /**
	���E�̌X���i-180..+180�j
        */
        public int16_t roll;
        /**
	�O��̌X���i-180..+180�j
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
  