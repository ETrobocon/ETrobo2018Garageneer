/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
	Template:CS,CompositionType.local.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using BricRoboRTE;
using OpenCvSharp;
using System.IO.Ports;

namespace BricRoboApp
{
    /**
    ����V�X�e���ƃV���A���ʐM����B
�V���A���|�[�g��1�����Ȃ��O��Ȃ̂ŁA�������Č��肷��B
    @author eguchi
    @version 1.0
    */
    public partial class Telecom
    {
        /*
        User Defined Attribute
        */
        /**
	SerialPort �I�u�W�F�N�g
        */
        private SerialPort _port;
        /*
        Auto Generated Attribute
        */
        /*
        Auto Generated Method
        */
        /*
        Auto RunnableEntity
        */
        /*
        Port
        */
        /**
	
        */
        public RPortEv_TeniboCommandIF Rte_Receive_command;
        /**
	
        */
        public PPort_TeniboNaviIF Rte_Write_navi;
    }

}

/* Template for Telecom.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Telecom
    {
        public void ConfigParam(int baudRate)
        {
        }
        public void RunTxNavi()
        {
        }
        public void RunRxCommand()
        {
        }

    }
}
*/
  