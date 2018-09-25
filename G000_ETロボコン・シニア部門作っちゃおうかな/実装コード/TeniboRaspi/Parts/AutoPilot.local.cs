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
    カメラでボールを追いかける自動運転をする
    @author ike
    @version 1.0
    */
    public partial class AutoPilot
    {
        /*
        User Defined Attribute
        */
        /*
        Auto Generated Attribute
        */
        /**
	カメラでボールを追いかける自動運転をする
        */
        public BallPosition BALLPOS = new BallPosition();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public Drive2Command BLDCMD = new Drive2Command();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public VideoCamera CAM = new VideoCamera();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public Driving DIRACC = new Driving();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public ObstacleAvoidance OA = new ObstacleAvoidance();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public PrioritySelector PS = new PrioritySelector();
        /**
	カメラでボールを追いかける自動運転をする
        */
        public UndistortCam UD = new UndistortCam();
        /*
        Auto Generated Method
        */
        /*
        Auto RunnableEntity
        */
        /**
	
        */
        public void Run()
        {
            CAM.Run();
            BALLPOS.Run();
            UD.Run();
            DIRACC.Run();
            OA.Run();
            PS.Run();
            BLDCMD.Run();
        }
        /*
        Port
        */
        /**
	
        */
        public PPortEv_TeniboCommandIF Rte_Send_cmdToRobo;
        /**
	
        */
        public RPortEv_TeniboCommandIF Rte_Receive_fromPropo;
    }

}

/* Template for AutoPilot.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class AutoPilot
    {

    }
}
*/
  