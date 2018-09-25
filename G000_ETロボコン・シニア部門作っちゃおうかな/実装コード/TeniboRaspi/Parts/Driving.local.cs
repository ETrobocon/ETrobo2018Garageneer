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
    複数のボール位置から狙うボールを１つ決めて、それを拾うためにハンドルとアクセルを操作する。遠いボールほど速く移動。
    @author ike
    @version 1.0
    */
    public partial class Driving
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
        public RPortEv_BallPositionIF Rte_Receive_balls;
        /**
	
        */
        public PPortEv_DriveInfoIF Rte_Send_drive;
    }

}

/* Template for Driving.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Driving
    {
        public void Run()
        {
        }

    }
}
*/
  