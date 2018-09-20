using BricRoboRTE;
using System;
using System.Linq;
using OpenCvSharp;

namespace BricRoboApp
{
    public partial class Driving
    {
        public void Run()
        {
            BallPositionIF ballIF;
            if (Rte_Receive_balls(out ballIF) != Std_ReturnType.RTE_E_OK)
            {
                return;
            }

            if( ballIF.balls.Length > 0 )
            {
                ballIF.balls.OrderBy(b => b.X * b.X + b.Y * b.Y);
                Point2f target = ballIF.balls[0];
                double R = Math.Sqrt(target.X * target.X + target.Y * target.Y);
                double angle = Math.Sin(target.X / R);

                if (angle != double.NaN)
                {
                    DriveInfoIF driveIF = new DriveInfoIF();
                    driveIF.steer = (int)(90.0 * angle);
                    double accel = Math.Min(R * 100, 100);
                    accel = Math.Max(accel, 10);
                    driveIF.accel = (int)accel;
                    Rte_Send_drive(driveIF);
                }
            }
        }
    }
}
  