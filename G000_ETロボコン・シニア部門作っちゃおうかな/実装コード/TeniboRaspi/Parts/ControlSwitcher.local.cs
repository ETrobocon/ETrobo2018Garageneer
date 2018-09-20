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
    プロポからのコマンドを監視して、自動運転になったら自動からのコマンドに切り替え、マニュアルになったら、プロポからに切り替える。
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
  