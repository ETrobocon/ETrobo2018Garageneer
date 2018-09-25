using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using BricRoboRTE;
using OpenCvSharp;

namespace BricRoboApp
{
    public partial class VideoComStereo
    {
        /// <summary>
        /// ポート番号
        /// </summary>
        int _portNo;
        /// <summary>
        /// 合成後画像のサイズ
        /// </summary>
        int _width, _height;
        /// <summary>
        /// 静止画ファイル
        /// </summary>
        string _filePath;
        public void ConfigParam(int portNo, int width, int height)
        {
            _portNo = portNo;
            _width = width;
            _height = height;
            _server = new TcpServer();
            _server.Start(portNo);

            _filePath = Path.Combine(Path.GetTempPath(), string.Format("WaterRobot.{0}.jpg", portNo));
        }
        public void Run()
        {
            TcpClient client = _server.GetClient();
            if (client != null)
            {
                NetworkStream _stream = client.GetStream();
                if (_stream != null)
                {
                    try
                    {
                        if (_stream.DataAvailable && _stream.ReadByte() != -1)
                        {
                            ImageFrame imgLR = new ImageFrame();
                            imgLR.img = new IplImage(_width, _height, BitDepth.U8, 3);

                            ImageFrame imgLeft;
                            if (Rte_Receive_imgLeft(out imgLeft) == Std_ReturnType.RTE_E_OK)
                            {
                                CvRect rc = new CvRect(0, 0, _width/2, _height);
                                Cv.SetImageROI(imgLR.img, rc);
                                Cv.Copy(imgLeft.img, imgLR.img, null);
                            }
                            ImageFrame imgRight;
                            if (Rte_Receive_imgRight(out imgRight) == Std_ReturnType.RTE_E_OK)
                            {
                                CvRect rc = new CvRect(_width/2, 0, _width/2, _height);
                                Cv.SetImageROI(imgLR.img, rc);
                                Cv.Copy(imgRight.img, imgLR.img, null);
                            }
                            Cv.ResetImageROI(imgLR.img);

                            /*
                            byte[] jpegBuf;
                            int[] param = new int[2];
                            Mat mat = new Mat(img.img);

                            Cv2.ImEncode(".jpeg", mat, out jpegBuf, param);
                            _stream.Write(jpegBuf, 0, jpegBuf.Length);
                             */
                            System.Console.WriteLine("Video->WIFI({0})", _portNo);

                            imgLR.img.SaveImage(_filePath);
                            byte[] buffer = new byte[1024 * 32];
                            using (FileStream fs = new FileStream(_filePath, FileMode.Open))
                            {
                                int readByte;
                                do
                                {
                                    readByte = fs.Read(buffer, 0, buffer.Length);
                                    _stream.Write(buffer, 0, readByte);
                                }
                                while (readByte == buffer.Length);
                            }

                            /*
                            byte[] ngBuffer = new byte[1];
                            _stream.Write(ngBuffer, 0, ngBuffer.Length);
                            */
                        }
                    }
                    catch (Exception ex)
                    {
                    }
                }
            }
        }
    }
}
  