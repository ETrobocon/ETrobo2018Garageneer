using BricRoboRTE;
using OpenCvSharp;
using System;
using System.Collections.Generic;

namespace BricRoboApp
{
    public partial class UndistortCam
    {
        UndistortCamera tool = new UndistortCamera();
        public void Run()
        {
            BallPositionIF posIF;
            if (Rte_Receive_in(out posIF) == Std_ReturnType.RTE_E_OK)
            {
                List<Point2f> original = new List<Point2f>(posIF.balls);
                List<Point2f> undis = tool.UndistortPoint(original);
                posIF.balls = undis.ToArray();
                Rte_Send_out(posIF);
            }
            else
            {
                Console.WriteLine("No UndistortCam");
            }
        }
    }
}
  