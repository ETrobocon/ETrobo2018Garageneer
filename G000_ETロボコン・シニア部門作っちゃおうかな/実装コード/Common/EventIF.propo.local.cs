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

    public delegate Std_ReturnType PPort_EventIF(EventIF i);
    public delegate Std_ReturnType PPortEv_EventIF(EventIF i);
    public delegate Std_ReturnType RPort_EventIF(out EventIF i);
    public delegate Std_ReturnType RPortEv_EventIF(out EventIF i);
  
    /**
�C�x���g�������������Ƃ�\���B�����o�͂Ȃ��B
    @author eguchi
    @version 1.0
    */
    public partial class EventIF
    {
        /*
        User Defined Attribute
        */
    }

}

/* Template for EventIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class EventIF
    {
        
    }
}
*/
  