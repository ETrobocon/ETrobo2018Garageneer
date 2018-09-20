using BricRoboRTE;
using OpenCvSharp;
using System;

namespace BricRoboApp
{
    public partial class VideoCamera
    {
        const string url = "http://localhost:8080/?action=stream";
        const int width = 320;
        const int height = 240;
        VideoCapture cap;
        public VideoCamera()
        {
        }
        private bool OpenCam()
        {
            cap = new VideoCapture();
            if (Environment.OSVersion.Platform == PlatformID.Unix)
            {
                cap.Open(url);
            }
            else
            {
                cap.Open(0);
            }
            if (!cap.IsOpened())
            {
                Console.WriteLine("ERROR: VideoCamera");
                return false;
            }
            cap.Set(CaptureProperty.FrameWidth, width);
            cap.Set(CaptureProperty.FrameHeight, height);
            return true;
        }
        private void CloseCam()
        {
            cap.Release();
            cap = null;
        }
        public void Run()
        {
#if false
            Mat frame = Cv2.ImRead(@"calib.png");
            ImageFrameIF frm = new ImageFrameIF();
            frm.image = frame;
            Rte_Send_frame(frm);
#else
            if (OpenCam())
            {
                Mat frame = new Mat();
                cap.Read(frame);

                ImageFrameIF frm = new ImageFrameIF();
                frm.image = frame;
                Rte_Send_frame(frm);

                CloseCam();
            }
#endif
        }
    }
}
  