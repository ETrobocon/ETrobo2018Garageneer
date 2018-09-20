/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
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
    デバッグ用
    @author eguchi
    @version 1.0
    */
    public partial class DebugControlCom
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private int _counter = 0;
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

/* Template for DebugControlCom.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class DebugControlCom
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
  