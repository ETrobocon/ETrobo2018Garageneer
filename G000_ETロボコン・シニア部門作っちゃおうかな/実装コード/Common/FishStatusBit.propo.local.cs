/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
	Template:CS,EnumDataType.local.xsl
	Generated Date:2016/04/08 11:18:13
	Generater Name:BricRoboGen Ver:1.7.3.339  
 */


using int8_t = System.SByte;
using int16_t = System.Int16;

namespace BricRoboApp
{

    /**

    @author eguchi
    @version 1.0
    */
    public enum FishStatusBit
    {
        /*
        User Defined Attribute
        */
        /**
	�Ɩ�ON
        */
        FS_LIGHT_ON = 0x01,
        /**
	�r�f�I�^�撆�i�`���l��0�j
        */
        FS_VIDEO_REC_OVL = 0x02,
        /**
	�r�f�I�^�撆�i�`���l���P�j
        */
        FS_VIDEO_REC_ORG = 0x04,
        /**
	�ً}�Ώ���
        */
        FS_EMERGENCY = 0x40,
        /**
	�Z�[�t�e�B���[�h��ON/OFF
        */
        FS_SAFETY_MODE = 0x80
    }

}
