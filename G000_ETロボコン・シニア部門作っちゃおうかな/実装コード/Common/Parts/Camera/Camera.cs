using BricRoboRTE;
using System;
using OpenCvSharp;

namespace BricRoboApp
{
    public partial class Camera
    {
        public void ConfigParam(int camNo, int width, int height)
        {
            try
            {
                _cap = Cv.CreateCameraCapture(camNo);
                _cap.FrameWidth = width;
                _cap.FrameHeight = height;
            }
            catch (Exception)
            {
                System.Console.WriteLine("Video {0}({1}x{2}) error", camNo, width, height);
            }
        }
        public void Run()
        {
            if (_cap != null)
            {
                ImageFrame imageFrame = new ImageFrame();
                if ((imageFrame.img = _cap.QueryFrame()) != null)
                {
                    Rte_Send_image(imageFrame);
                }
            }
        }
    }
}
