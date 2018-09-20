using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class VideoCom
    {
        /// <summary>
        /// ポート番号
        /// </summary>
        int _portNo;
        /// <summary>
        /// 静止画ファイル
        /// </summary>
        string _filePath;

        public void ConfigParam(int portNo)
        {
            _portNo = portNo;
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
                            ImageFrame img;
                            if (Rte_Receive_img(out img) == Std_ReturnType.RTE_E_OK)
                            {
                                /*
                                byte[] jpegBuf;
                                int[] param = new int[2];
                                Mat mat = new Mat(img.img);

                                Cv2.ImEncode(".jpeg", mat, out jpegBuf, param);
                                _stream.Write(jpegBuf, 0, jpegBuf.Length);
                                 */
                                System.Console.WriteLine("Video->WIFI({0})", _portNo);

                                img.img.SaveImage(_filePath);
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
                            }
                            else
                            {
                                byte[] ngBuffer = new byte[1];
                                _stream.Write(ngBuffer, 0, ngBuffer.Length);
                            }
                        }
                    }
                    catch (Exception)
                    {
                    }
                }
            }
        }
    }
}
  