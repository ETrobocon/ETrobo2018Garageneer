using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenCvSharp;
using System.Configuration;
using System.IO;

namespace BricRoboRTE
{
    class PerspectiveLocation
    {
        /// <summary>
        /// 透視変換行列
        /// </summary>
        Mat matrix;
        public void SaveMatrix(string filename=null)
        {
            try
            {
                if (filename == null)
                {
                    filename = "Tenibo.PL.calib.txt";
                }
                StreamWriter sr = new StreamWriter(filename);

                for (int d0 = 0; d0 < 3; d0++)
                {
                    for (int d1 = 0; d1 < 3; d1++)
                    {
                        sr.WriteLine(matrix.At<double>(d0, d1).ToString());
                    }
                }
                sr.Close();
                Console.WriteLine("Save Tenibo.PL.calib.txt");
            }
            catch (Exception)
            {
                Console.WriteLine("ERROR: Save Tenibo.PL.calib.txt");
            }
        }
        public void LoadMatrix(string filename=null)
        {
            try
            {
                if (filename == null)
                {
                    filename = "Tenibo.PL.calib.txt";
                }
                StreamReader sr = new StreamReader(filename);
                matrix = new Mat(3, 3, MatType.CV_64F);
                var index = matrix.GetGenericIndexer<double>();
                for (int d0 = 0; d0 < 3; d0++)
                {
                    for (int d1 = 0; d1 < 3; d1++)
                    {
                        string line = sr.ReadLine();
                        index[d0, d1] = Double.Parse(line);
                    }
                }
                Console.WriteLine("PerspectiveLocation OK");
            }
            catch (Exception)
            {
                matrix = null;
                Console.WriteLine("ERROR: {0}", filename);
            }
        }
        /// <summary>
        /// 画像上の４点座標と、計測した4点座標をセット
        /// </summary>
        /// <param name="iConers">画像上の4点座標</param>
        /// <param name="mConers">計測した4点座標</param>
        public void SetConers(List<Point2f> iConers, List<Point2f> mConers)
        {
            matrix = Cv2.GetPerspectiveTransform(iConers, mConers);
        }
        /// <summary>
        /// 画像上の座標から計測の座標に変換する
        /// </summary>
        /// <param name="iPos">画像上の座標</param>
        /// <param name="mPos">計測の座標</param>
        /// <returns>成功すればtrue</returns>
        public bool CalcLocation(Point2f iPos, ref Point2f mPos)
        {
            if (matrix == null)
            {
                return false;
            }

            List<Point2f> list = new List<Point2f>();
            list.Add(iPos);

            //自分で行列演算をしても答えが合わない、OpenCVの関数を使うこと
            Point2f[] result = Cv2.PerspectiveTransform(list, matrix);
            mPos = result[0];
            return true;
        }
    }
}
