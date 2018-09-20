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

    public delegate Std_ReturnType PPort_CommandIF(CommandIF i);
    public delegate Std_ReturnType PPortEv_CommandIF(CommandIF i);
    public delegate Std_ReturnType RPort_CommandIF(out CommandIF i);
    public delegate Std_ReturnType RPortEv_CommandIF(out CommandIF i);
  
    /**
���{�b�g�𐧌䂷��R�}���h
    @author eguchi
    @version 1.0
    */
    public partial class CommandIF
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
  