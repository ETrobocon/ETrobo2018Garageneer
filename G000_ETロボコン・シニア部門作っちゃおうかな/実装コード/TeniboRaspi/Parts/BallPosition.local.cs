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
    画像からボールの位置を割り出す。位置はカメラを原点として、前方がY増加、右がX増加。
単位はメートル。
    @author ike
    @version 1.0
    */
    public partial class BallPosition
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
        public RPortEv_ImageFrameIF Rte_Receive_frame;
        /**
	
        */
        public PPortEv_BallPositionIF Rte_Send_pos;
    }

}

/* Template for BallPosition.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class BallPosition
    {
        public void Run()
        {
        }

    }
}
*/
  