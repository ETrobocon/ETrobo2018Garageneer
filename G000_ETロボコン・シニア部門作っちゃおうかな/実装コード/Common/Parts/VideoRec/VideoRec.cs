using OpenCvSharp;
using System;
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class VideoRec
    {
        CvVideoWriter _writerOvl;
        CvVideoWriter _writerOrg;

        public void ConfigParam(string videoPathOverlay, string videoPathOriginal, int elapse)
        {
            _videoPathOverlay = videoPathOverlay;
            _videoPathOriginal = videoPathOriginal;
            _elapse = elapse;
        }
        public void RunOverlay()
        {
            VideoRecIF rec;
            if (Rte_Receive_rec(out rec) == Std_ReturnType.RTE_E_OK)
            {
                DateTime now = DateTime.Now;
                string time = string.Format("{0:0000}{1:00}{2:00}{3:00}{4:00}{5:00}", now.Year, now.Month, now.Day,
                    now.Hour, now.Minute, now.Second);
                if (rec.channelOvl && _writerOvl == null)
                {
                    string file = string.Format(_videoPathOverlay, time) + ".avi";
                    _writerOvl = new CvVideoWriter(file, 0, 1000 / _elapse, new CvSize(160, 120), true);
                }
                if (!rec.channelOvl && _writerOvl != null)
                {
                    _writerOvl.Dispose();
                    _writerOvl = null;
                }
            }

            if (_writerOvl != null)
            {
                ImageFrame img;
                if (Rte_Receive_chaOverlay(out img) == Std_ReturnType.RTE_E_OK)
                {
                    _writerOvl.WriteFrame(img.img);
                }
            }

            VideoRecIF status = new VideoRecIF();
            status.channelOvl = _writerOvl != null;
            status.channelOrg = _writerOrg != null;
            Rte_Write_status(status);
        }
        public void RunOriginal()
        {
            VideoRecIF rec;
            if (Rte_Receive_rec(out rec) == Std_ReturnType.RTE_E_OK)
            {
                DateTime now = DateTime.Now;
                string time = string.Format("{0:0000}{1:00}{2:00}{3:00}{4:00}{5:00}", now.Year, now.Month, now.Day,
                    now.Hour, now.Minute, now.Second);
                if (rec.channelOrg && _writerOrg == null)
                {
                    string file = string.Format(_videoPathOriginal, time) + ".avi";
                    _writerOrg = new CvVideoWriter(file, 0, 1000 / _elapse, new CvSize(160, 120), true);
                }
                if (!rec.channelOrg && _writerOrg != null)
                {
                    _writerOrg.Dispose();
                    _writerOrg = null;
                }
            }

            if (_writerOrg != null)
            {
                ImageFrame img;
                if (Rte_Receive_chaOriginal(out img) == Std_ReturnType.RTE_E_OK)
                {
                    _writerOrg.WriteFrame(img.img);
                }
            }

            VideoRecIF status = new VideoRecIF();
            status.channelOvl = _writerOvl != null;
            status.channelOrg = _writerOrg != null;
            Rte_Write_status(status);
        }
    }
}
  