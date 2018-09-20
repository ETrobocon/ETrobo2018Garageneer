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
    ハンドルとアクセル情報から操作コマンドを発生する。
    @author ike
    @version 1.0
    */
    public partial class Drive2Command
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
        public PPortEv_TeniboCommandIF Rte_Send_cmd;
        /**
	
        */
        public RPortEv_DriveInfoIF Rte_Receive_drive;
    }

}

/* Template for Drive2Command.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Drive2Command
    {
        public void Run()
        {
        }

    }
}
*/
  