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
    制御システムとシリアル通信する。
シリアルポートは1つしかない前提なので、検索して決定する。
    @author eguchi
    @version 1.0
    */
    public partial class Telecom
    {
        /*
        User Defined Attribute
        */
        /**
	SerialPort オブジェクト
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
  