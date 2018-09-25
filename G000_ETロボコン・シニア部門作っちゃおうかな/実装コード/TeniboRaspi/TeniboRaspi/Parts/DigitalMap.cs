using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenCvSharp;

namespace BricRoboRTE
{
    public class DigitalMap
    {
        public bool DebugMode = false;
        public float HorzMaskPer = 0.25f;
        /// <summary>
        /// ロボットで計測した座標の4点
        /// </summary>
        OpenCvSharp.Point2f mLU = new Point2f(-0.5f, 1f);
        OpenCvSharp.Point2f mLD = new Point2f(-0.5f, 0.5f);
        OpenCvSharp.Point2f mRD = new Point2f(0.5f, 0.5f);
        OpenCvSharp.Point2f mRU = new Point2f(0.5f, 1f);


        private PerspectiveLocation PL = new PerspectiveLocation();

        public void Save(string filename=null)
        {
            PL.SaveMatrix(filename);
        }
        public void Load(string filename=null)
        {
            PL.LoadMatrix(filename);
        }

        public class BallProperty
        {
            public int index;
            public double area;
            public Mat contour;

            public Point2f GetCenter()
            {
                Moments mu = Cv2.Moments(contour);
                Point2f mc = new Point2f((float)(mu.M10 / mu.M00), (float)(mu.M01 / mu.M00));
                return mc;
            }
        };

        private Mat GetColorMasked(Mat frame)
        {
            Mat hsv = new Mat();
            Cv2.CvtColor(frame, hsv, ColorConversionCodes.BGR2HSV);
            int[] yellowLowColor = { 20, 50, 50 };
            int[] yellowHiColor = { 60, 255, 255 };
            Mat mask = new Mat();
            Cv2.InRange(hsv, InputArray.Create(yellowLowColor), InputArray.Create(yellowHiColor), mask);
            Mat masked = new Mat();
            Cv2.BitwiseAnd(frame, frame, masked, mask);
            if (DebugMode)
            {
                Cv2.ImShow("ColorMasked", masked);
            }
            return masked;
        }
        private Mat GetExpansion(Mat frame)
        {
            Mat gray = new Mat();
            Cv2.CvtColor(frame, gray, ColorConversionCodes.BGR2GRAY);
            Mat grayEx = new Mat();
            var an = 5;
            var element = Cv2.GetStructuringElement(
                    MorphShapes.Ellipse,
                    new Size(an * 2 + 1, an * 2 + 1),
                    new Point(an, an));
            Cv2.Dilate(gray, grayEx, element);
            if (DebugMode)
            {
                Cv2.ImShow("Expansion", grayEx);
            }
            return grayEx;
        }
        private Mat GetCircleMasked(Mat frame)
        {
            Mat bin = frame.ConvertScaleAbs(255);
            if (DebugMode)
            {
                Cv2.ImShow("CircleBin", bin);
                //bin.SaveImage("CircleBin.png");
            }
            CircleSegment[] cs = Cv2.HoughCircles(bin, HoughMethods.Gradient, 1.1f, 5, 20, 20, 5, 100);
            Mat mask = new Mat(frame.Size(), MatType.CV_8UC1, Scalar.Black);
            foreach (CircleSegment c in cs)
            {
                mask.Circle(c.Center, (int)c.Radius, Scalar.White, -1);
            }
            if (DebugMode)
            {
                Cv2.ImShow("CircleMask", mask);
            }
            Mat masked = new Mat();
            frame.CopyTo(masked, mask);
            if (DebugMode)
            {
                Cv2.ImShow("CircleMasked", masked);
            }
            return masked;
        }
        private Mat GetHorizonMasked(Mat frame)
        {
            Mat mask = new Mat(frame.Size(), MatType.CV_8UC1, Scalar.Black);
            Mat masked = frame.Clone();
            masked.Rectangle(new Point(0, 0), new Point(frame.Size().Width, frame.Size().Height * HorzMaskPer), Scalar.Black, -1);
            if (DebugMode)
            {
                Cv2.ImShow("HorizonMasked", masked);
            }
            return masked;
        }
        private Mat[] GetContours(Mat frame)
        {
            Mat[] contours;
            Mat hierarchy = new Mat();
            Cv2.FindContours(frame, out contours, hierarchy, RetrievalModes.Tree, ContourApproximationModes.ApproxSimple);
            Mat con = frame.Clone();
            Cv2.DrawContours(con, contours, -1, Scalar.Red);
            if (DebugMode)
            {
                Cv2.ImShow("Contours", con);
            }
            return contours;
        }
        public List<BallProperty> GetBallPropties(Mat frame)
        {
            //色でマスク
            Mat masked = GetColorMasked(frame);
            //輪郭膨張
            masked = GetExpansion(masked);
            //水平線マスク
            masked = GetHorizonMasked(masked);
            //円でマスク
            //masked = GetCircleMasked(masked);
            //輪郭
            Mat[] contours = GetContours(masked);

            var moList = new List<BallProperty>();
            for (int i = 0; i < contours.Length; i++)
            {
                BallProperty m = new BallProperty();
                m.index = i;
                m.contour = contours[i];
                m.area = Cv2.ContourArea(contours[i]);
                moList.Add(m);
            }
            moList.Sort((a, b) => (int)(b.area - a.area));

            return moList;
        }

        public List<Point2f> GetBallsPos(Mat frame)
        {
            List<Point2f> poss = new List<Point2f>();
            List<BallProperty> prop = GetBallPropties(frame);
            foreach (BallProperty p in prop)
            {
                Point2f real = new Point2f();
                if (PL.CalcLocation(p.GetCenter(), ref real))
                {
                    poss.Add(real);
                }
            }
            return poss;
        }

        public bool Calibration(Mat frame)
        {
            List<BallProperty> moList = GetBallPropties(frame);

            //大きな物体の重心の重い方から4個
            if (moList.Count < 4)
            {
                return false;
            }

            List<Point2f> coners = new List<Point2f>();
            for (int i = 0; i < 4; i++)
            {
                Point2f center = moList[i].GetCenter();
                frame.Circle(center, 3, Scalar.Blue);
                coners.Add(center);
            }

            //4つの角の確定
            coners.Sort((a, b) => (int)(a.X - b.X));
            List<Point2f> left = new List<Point2f>();
            List<Point2f> right = new List<Point2f>();
            left.Add(coners[0]);
            left.Add(coners[1]);
            right.Add(coners[2]);
            right.Add(coners[3]);
            left.Sort((a, b) => (int)(a.Y - b.Y));
            right.Sort((a, b) => (int)(a.Y - b.Y));

            List<Point2f> order = new List<Point2f>();
            order.Add(left[0]);
            order.Add(left[1]);
            order.Add(right[1]);
            order.Add(right[0]);
            List<Point2f> realConer = new List<Point2f>();
            realConer.Add(mLU);
            realConer.Add(mLD);
            realConer.Add(mRD);
            realConer.Add(mRU);
            PL.SetConers(order, realConer);

            if (DebugMode)
            {
                Cv2.ImShow("Moments", frame);
            }

            return true;
        }
    }
}
