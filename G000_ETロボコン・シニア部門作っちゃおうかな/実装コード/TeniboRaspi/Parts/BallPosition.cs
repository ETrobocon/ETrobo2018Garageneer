using System.Collections.Generic;
using BricRoboRTE;
using OpenCvSharp;
using System;

namespace BricRoboApp
{
    public partial class BallPosition
    {
        private DigitalMap map = new DigitalMap();

        public BallPosition()
        {
            map.Load();
        }
        public void Run()
        {
            ImageFrameIF frame;
            if (Rte_Receive_frame(out frame) != Std_ReturnType.RTE_E_OK)
            {
                Console.WriteLine("No BallPosition");
                return;
            }

            BallPositionIF ballIF = new BallPositionIF();
            List<Point2f> balls = map.GetBallsPos(frame.image);
            ballIF.balls = balls.ToArray();
            Rte_Send_pos(ballIF);

            if (Environment.OSVersion.Platform != PlatformID.Unix)
            {
                Cv2.WaitKey(1);
            }
        }
    }
}
  