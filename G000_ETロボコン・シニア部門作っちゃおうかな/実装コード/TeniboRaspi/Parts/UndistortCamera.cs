using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using OpenCvSharp;

namespace BricRoboApp
{
    public class UndistortCamera
    {
        Mat _cameraMatrix = new Mat(3, 3, MatType.CV_64F);
        Mat _distCoeffs = new Mat(5, 1, MatType.CV_64F);
        Mat _map1 = new Mat();
        Mat _map2 = new Mat();
        bool _init = false;
        bool _ready = false;
        public UndistortCamera(string matrixFile = null)
        {
            try
            {
                const string defaultMatrix = "TeniboRaspi.camera.calib.txt";
                if (matrixFile == null)
                {
                    matrixFile = defaultMatrix;
                }
                StreamReader sr = new StreamReader(matrixFile);
                _cameraMatrix.Set<double>(0, 0, double.Parse(sr.ReadLine()));//fx
                _cameraMatrix.Set<double>(1, 1, double.Parse(sr.ReadLine()));//fy
                _cameraMatrix.Set<double>(0, 2, double.Parse(sr.ReadLine()));//cx
                _cameraMatrix.Set<double>(1, 2, double.Parse(sr.ReadLine()));//cy
                _distCoeffs.Set<double>(0, double.Parse(sr.ReadLine()));
                _distCoeffs.Set<double>(1, double.Parse(sr.ReadLine()));
                _distCoeffs.Set<double>(2, double.Parse(sr.ReadLine()));
                _distCoeffs.Set<double>(3, double.Parse(sr.ReadLine()));
                _distCoeffs.Set<double>(4, double.Parse(sr.ReadLine()));
                _init = true;
            }
            catch (Exception)
            {
                Console.WriteLine("ERROR: {0}", matrixFile);
            }
            Console.WriteLine("UndistortCamera OK");
        }
        public Mat Remap(Mat img)
        {
            if (_init)
            {
                if (!_ready)
                {
                    Mat newCameraMatrix = new Mat();
                    Cv2.InitUndistortRectifyMap(_cameraMatrix, _distCoeffs, newCameraMatrix, _cameraMatrix, img.Size(), MatType.CV_32FC1, _map1, _map2);
                    _ready = true;
                }
                Mat newM = new Mat();
                Cv2.Remap(img, newM, _map1, _map2);
                return newM;
            }
            else
            {
                return img;
            }
        }
        public Mat Undistort2(Mat img)
        {
            if (_init)
            {
                Mat newMat = new Mat();
                Cv2.Undistort(img, newMat, _cameraMatrix, _distCoeffs);
                return newMat;
            }
            else
            {
                return img;
            }
        }
        public List<Point2f> UndistortPoint(List<Point2f> src)
        {
            if (_init)
            {
                List<Point2f> dst = new List<Point2f>();
                Cv2.UndistortPoints(InputArray.Create(src), OutputArray.Create(dst), _cameraMatrix, _distCoeffs);
                return dst;
            }
            else
            {
                return src;
            }
        }
    }
}
