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
    UDP�ʐM�ɂă��{�b�g�O���ƒʐM����B
    @author eguchi
    @version 1.0
    */
    public partial class ControlCom
    {
        /*
        User Defined Attribute
        */
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
        public PPortEv_TeniboCommandIF Rte_Send_command;
        /**
	
        */
        public RPort_TeniboNaviIF Rte_Read_navi;
    }

}

/* Template for ControlCom.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ControlCom
    {
        public void ConfigParam(int cmdPortNo, int naviPortNo)
        {
        }
        public void RunFromNavi()
        {
        }
        public void RunToCommand()
        {
        }

    }
}
*/
  