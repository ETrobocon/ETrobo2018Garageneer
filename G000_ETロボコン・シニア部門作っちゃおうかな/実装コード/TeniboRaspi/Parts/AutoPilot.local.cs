/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
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
    �J�����Ń{�[����ǂ������鎩���^�]������
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
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public BallPosition BALLPOS = new BallPosition();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public Drive2Command BLDCMD = new Drive2Command();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public VideoCamera CAM = new VideoCamera();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public Driving DIRACC = new Driving();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public ObstacleAvoidance OA = new ObstacleAvoidance();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
        */
        public PrioritySelector PS = new PrioritySelector();
        /**
	�J�����Ń{�[����ǂ������鎩���^�]������
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
  