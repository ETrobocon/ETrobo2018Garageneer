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
    �v���|����̃R�}���h���Ď����āA�����^�]�ɂȂ����玩������̃R�}���h�ɐ؂�ւ��A�}�j���A���ɂȂ�����A�v���|����ɐ؂�ւ���B
    @author ike
    @version 1.0
    */
    public partial class ControlSwitcher
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        public bool isAutoMode = false;
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
        public RPortEv_TeniboCommandIF Rte_Receive_cmdFromAuto;
        /**
	
        */
        public RPortEv_TeniboCommandIF Rte_Receive_cmdFromPropo;
        /**
	
        */
        public PPortEv_TeniboCommandIF Rte_Send_cmdToRobo;
        /**
	
        */
        public RPort_TeniboNaviIF Rte_Read_naviFromRobo;
        /**
	
        */
        public PPort_TeniboNaviIF Rte_Write_naviToPropo;
    }

}

/* Template for ControlSwitcher.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ControlSwitcher
    {
        public void RunCmd()
        {
        }
        public void RunNavi()
        {
        }

    }
}
*/
  