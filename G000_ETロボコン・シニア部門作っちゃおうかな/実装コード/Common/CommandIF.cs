using BricRoboRTE;
using System;

namespace BricRoboApp
{
    public partial class CommandIF
    {
        override public string ToString()
        {
            return string.Format("({0}) {1} {2} {3}", cmd, param1, param2, param3);
        }

        public const int bufSize = 7;

        public void FromBuffer( byte[] buf, int offset )
        {
            cmd = buf[offset+0];
            param1 = BitConverter.ToInt16(buf, offset + 1);
            param2 = BitConverter.ToInt16(buf, offset + 3);
            param3 = BitConverter.ToInt16(buf, offset + 5);
        }

        public void ToBuffer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(cmd).CopyTo(buf, offset+0);
            BitConverter.GetBytes(param1).CopyTo(buf, offset + 1);
            BitConverter.GetBytes(param2).CopyTo(buf, offset + 3);
            BitConverter.GetBytes(param3).CopyTo(buf, offset + 5);
        }
    }
}