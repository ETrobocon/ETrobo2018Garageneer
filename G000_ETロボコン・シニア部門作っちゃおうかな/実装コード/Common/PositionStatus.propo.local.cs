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
    public enum PositionStatus
    {
        /*
        User Defined Attribute
        */
        /**
	������
        */
        POS_NOT_READY = 0,
        /**
	�ғ���

        */
        POS_WORKING = 1,
        /**
	�G���[
        */
        POS_ERROR = -1
    }

}
