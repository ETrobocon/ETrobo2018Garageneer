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
    Raspi側で処理するコマンドを分岐
    @author ike
    @version 1.0
    */
    public partial class RaspiWorks
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
        public RPortEv_TeniboCommandIF Rte_Receive_cmdIn;
        /**
	
        */
        public PPortEv_TeniboCommandIF Rte_Send_cmdOut;
        /**
	
        */
        public PPortEv_SpeechIF Rte_Send_speech;
    }

}

/* Template for RaspiWorks.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class RaspiWorks
    {
        public void Run()
        {
        }

    }
}
*/
  