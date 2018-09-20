using BricRoboRTE;
using System;

namespace BricRoboApp
{
    public partial class PositionIF
    {
        public PositionIF()
        {
        }

        public PositionIF(PositionIF s)
        {
            yaw = s.yaw;
            roll = s.roll;
            pitch = s.pitch;
            status = s.status;
        }

        public override string ToString()
        {
            return string.Format("Yaw{0} Roll{1} Pitch{2} ST{3}", yaw, roll, pitch, status
                );
        }

        public const int bufSize = 6+1;

        public void FromBuffer(byte[] buf, int offset)
        {
            yaw = BitConverter.ToInt16(buf, offset);
            roll = BitConverter.ToInt16(buf, offset+2);
            pitch = BitConverter.ToInt16(buf, offset+4);
            status = (sbyte)buf[offset + 6];
        }

        public void ToBuffer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(yaw).CopyTo(buf, offset + 0);
            BitConverter.GetBytes(roll).CopyTo(buf, offset + 2);
            BitConverter.GetBytes(pitch).CopyTo(buf, offset + 4);
            buf[offset + 6] = (byte)status;
        }
    }
}
  