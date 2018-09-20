using BricRoboRTE;
using System;

namespace BricRoboApp
{
    public partial class TeniboNaviIF
    {
        public const int bufSize = 2 * 2;
        public TeniboNaviIF()
        {
            battery = 0;
        }
        override public string ToString()
        {
            return string.Format("Bat:{0} Stat:0x{1:X}", battery, status);
        }
        public void ToBufer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(battery).CopyTo(buf, offset + 0);
            BitConverter.GetBytes(status).CopyTo(buf, offset + 2);
        }
        public void FromBuffer(byte[] buf, int offset)
        {
            battery = BitConverter.ToInt16(buf, offset + 0);
            status = BitConverter.ToUInt16(buf, offset + 2);
        }

    }
}
  