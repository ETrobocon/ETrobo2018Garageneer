/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
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
���{�b�g�𐧌䂷��R�}���h
    @author eguchi
    @version 1.0
    */
    public partial class TeniboCommandIF
    {
        /*
        User Defined Attribute
        */
        /**
	�R�}���h
        */
        public uint8_t cmd;
        /**
	�p�����[�^�B�l�̈Ӗ��̓R�}���h�ɂ�茈�肷��B
        */
        public int16_t param1;
        /**
	�p�����[�^�B�l�̈Ӗ��̓R�}���h�ɂ�茈�肷��B
        */
        public int16_t param2;
        /**
	�p�����[�^�B�l�̈Ӗ��̓R�}���h�ɂ�茈�肷��B
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
  