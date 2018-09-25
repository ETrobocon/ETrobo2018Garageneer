using BricRoboRTE;
using System;

namespace BricRoboApp
{
    public partial class JellyFishNaviIF
    {
        public const int bufSize = 5 + JellyFishNavi.bufSize;
        public JellyFishNaviIF()
        {
            battery = 0;
            flood = 0;
            status = 0;
            curNavi = new JellyFishNavi();
        }
        override public string ToString()
        {
            return string.Format("Bt:{3} Fl:{0} St:{1} {2}", flood, status, curNavi.ToString(), battery);
        }
        public void ToBufer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(battery).CopyTo(buf, offset + 0);
            BitConverter.GetBytes(flood).CopyTo(buf, offset + 2);
            BitConverter.GetBytes(status).CopyTo(buf, offset + 4);
            curNavi.ToBufer(buf, 5);
        }
        public void FromBuffer(byte[] buf, int offset)
        {
            battery = BitConverter.ToInt16(buf, offset + 0);
            flood = BitConverter.ToInt16(buf, offset + 2);
            status = buf[offset + 4];
            curNavi.FromBuffer(buf, offset + 5);
        }

    }
}
  