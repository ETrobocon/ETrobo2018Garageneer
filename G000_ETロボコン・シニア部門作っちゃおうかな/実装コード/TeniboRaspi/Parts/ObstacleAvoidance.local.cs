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
    障害物を見つけたら回避行動の運転をする。
    @author ike
    @version 1.0
    */
    public partial class ObstacleAvoidance
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
        public RPortEv_ImageFrameIF Rte_Receive_in;
        /**
	
        */
        public PPortEv_DriveInfoIF Rte_Send_out;
    }

}

/* Template for ObstacleAvoidance.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ObstacleAvoidance
    {
        public void Run()
        {
        }

    }
}
*/
  