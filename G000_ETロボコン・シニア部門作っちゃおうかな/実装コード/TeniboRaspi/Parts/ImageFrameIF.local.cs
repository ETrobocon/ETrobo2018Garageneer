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

    public delegate Std_ReturnType PPort_ImageFrameIF(ImageFrameIF i);
    public delegate Std_ReturnType PPortEv_ImageFrameIF(ImageFrameIF i);
    public delegate Std_ReturnType RPort_ImageFrameIF(out ImageFrameIF i);
    public delegate Std_ReturnType RPortEv_ImageFrameIF(out ImageFrameIF i);
  
    /**
�摜1��
    @author ike
    @version 1.0
    */
    public partial class ImageFrameIF
    {
        /*
        User Defined Attribute
        */
        /**
	OpenCV��MAT�N���X
        */
        public Mat image;
    }

}

/* Template for ImageFrameIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ImageFrameIF
    {
        
    }
}
*/
  