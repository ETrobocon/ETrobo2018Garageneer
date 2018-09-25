using BricRoboRTE;
using System;

namespace BricRoboApp
{
    public partial class TeniboCommandIF
    {
        public const int bufSize = 1 + 2 * 5;
        override public string ToString()
        {
            return string.Format("({0}) {1} {2} {3} {4} {5}", cmd, param1, param2, param3, param4, param5);
        }
        public void FromBuffer(byte[] buf, int offset)
        {
            cmd = buf[offset + 0];
            param1 = BitConverter.ToInt16(buf, offset + 1);
            param2 = BitConverter.ToInt16(buf, offset + 3);
            param3 = BitConverter.ToInt16(buf, offset + 5);
            param4 = BitConverter.ToInt16(buf, offset + 7);
            param5 = BitConverter.ToInt16(buf, offset + 9);
        }
        public void ToBuffer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(cmd).CopyTo(buf, offset + 0);
            BitConverter.GetBytes(param1).CopyTo(buf, offset + 1);
            BitConverter.GetBytes(param2).CopyTo(buf, offset + 3);
            BitConverter.GetBytes(param3).CopyTo(buf, offset + 5);
            BitConverter.GetBytes(param4).CopyTo(buf, offset + 7);
            BitConverter.GetBytes(param5).CopyTo(buf, offset + 9);
        }
    }
}
  