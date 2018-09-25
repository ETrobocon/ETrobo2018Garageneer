using System;

namespace BricRoboApp
{
    public partial class JellyFishNavi
    {
        public const int bufSize = 2 * 4;

        override public string ToString()
        {
            return string.Format("Dir:{0} Dep:{1} Pit:{2} Rol:{3}", dir, depth, pitch, roll);
        }

        public void FromBuffer(byte[] buf, int offset)
        {
            dir = BitConverter.ToInt16(buf, offset + 0);
            depth = BitConverter.ToInt16(buf, offset + 2);
            pitch = BitConverter.ToInt16(buf, offset + 4);
            roll = BitConverter.ToInt16(buf, offset + 6);
        }
        public void ToBufer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(dir).CopyTo(buf, offset + 0);
            BitConverter.GetBytes(depth).CopyTo(buf, offset + 2);
            BitConverter.GetBytes(pitch).CopyTo(buf, offset + 4);
            BitConverter.GetBytes(roll).CopyTo(buf, offset + 6);
        }
    }
}
