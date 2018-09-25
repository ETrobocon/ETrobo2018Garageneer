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
    カメラ・レンズの歪みで生じる位置のズレを取り除く
    @author ike
    @version 1.0
    */
    public partial class UndistortCam
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
        public RPortEv_BallPositionIF Rte_Receive_in;
        /**
	
        */
        public PPortEv_BallPositionIF Rte_Send_out;
    }

}

/* Template for UndistortCam.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class UndistortCam
    {
        public void Run()
        {
        }

    }
}
*/
  