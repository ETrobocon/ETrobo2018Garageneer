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

    public delegate Std_ReturnType PPort_TeniboNaviIF(TeniboNaviIF i);
    public delegate Std_ReturnType PPortEv_TeniboNaviIF(TeniboNaviIF i);
    public delegate Std_ReturnType RPort_TeniboNaviIF(out TeniboNaviIF i);
    public delegate Std_ReturnType RPortEv_TeniboNaviIF(out TeniboNaviIF i);
  
    /**
���{�b�g����v���|�ɒʒm����i�r���
    @author ike
    @version 1.0
    */
    public partial class TeniboNaviIF
    {
        /*
        User Defined Attribute
        */
        /**
	�d���o�b�e���d���B1,200��12.00V
        */
        public int16_t battery;
        /**
	�X�e�[�^�X�r�b�g�̏W��
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
  