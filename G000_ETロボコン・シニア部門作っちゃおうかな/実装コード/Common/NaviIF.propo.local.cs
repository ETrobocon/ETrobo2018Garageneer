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

    public delegate Std_ReturnType PPort_NaviIF(NaviIF i);
    public delegate Std_ReturnType PPortEv_NaviIF(NaviIF i);
    public delegate Std_ReturnType RPort_NaviIF(out NaviIF i);
    public delegate Std_ReturnType RPortEv_NaviIF(out NaviIF i);
  
    /**
���{�b�g�̏�Ԃ�m�点��
    @author eguchi
    @version 1.0
    */
    public partial class NaviIF
    {
        /*
        User Defined Attribute
        */
        /**
	���r���̊p�x�̒l(-90..+90)
        */
        public int8_t pecFin;
        /**
	���r���̊p�x�̒l(-90..+90)
        */
        public int8_t tailFin;
        /**
	���i�͂̒l(0-100)
        */
        public int8_t jetPower;
        /**
	
        */
        public uint8_t status;
        /**
	�����v�̒l�i���l�j
        */
        public int16_t waterPressure;
        /**
	���ꂩ��̋���(cm)
        */
        public int16_t bottomDistance;
        /**
	�Z���Z���T�[�̒l(0-1023)
        */
        public int16_t flood;
        /**
	���x�icm/�b�j
        */
        public uint8_t speed;
        /**
	cm�P��
        */
        public uint16_t mile;
        /**
	
        */
        public PositionIF position;
    }

}

/* Template for NaviIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class NaviIF
    {
        
    }
}
*/
  