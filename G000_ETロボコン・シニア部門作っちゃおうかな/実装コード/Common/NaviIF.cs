using BricRoboRTE;
using System;
using int8_t = System.SByte;
using uint8_t = System.Byte;
using int16_t = System.Int16;
using uint16_t = System.UInt16;

namespace BricRoboApp
{
    public partial class NaviIF
    {
        public NaviIF()
        {
            position = new PositionIF();
        }

        public NaviIF(NaviIF s)
        {
            pecFin = s.pecFin;
            tailFin = s.tailFin;
            jetPower = s.jetPower;
            status = s.status;
            waterPressure = s.waterPressure;
            bottomDistance = s.bottomDistance;
            flood = s.flood;
            speed = s.speed;
            mile = s.mile;
            position = new PositionIF(s.position);
        }

        override public string ToString()
        {
            return string.Format("Pec{0} Tail{1} Jet{2} Stat{3} WPs{4} Dis{5} Fld{6} Sp{7} Mil{8}, {9}", pecFin, tailFin, jetPower, status, waterPressure, bottomDistance, flood, speed, mile, position.ToString());
        }

        public const int bufSize = 13 +PositionIF.bufSize; //SpeedSensorÇ™ëùÇ¶ÇΩÅAãóó£Çí«â¡

        public void FromBuffer(byte[] buf, int offset)
        {
            pecFin = (int8_t)buf[offset];
            tailFin = (int8_t)buf[offset+1];
            jetPower = (int8_t)buf[offset+2];
            status = (uint8_t)buf[offset + 3];
            waterPressure = BitConverter.ToInt16(buf, offset+4);
            bottomDistance = BitConverter.ToInt16(buf, offset+6);
            flood = BitConverter.ToInt16(buf, offset+8);
            speed = (uint8_t)buf[offset + 10];
            mile = BitConverter.ToUInt16(buf, offset + 11);
            position.FromBuffer(buf, offset+13);
        }

        public void ToBufer(byte[] buf, int offset)
        {
            BitConverter.GetBytes(pecFin).CopyTo(buf, offset+0);
            BitConverter.GetBytes(tailFin).CopyTo(buf, offset + 1);
            BitConverter.GetBytes(jetPower).CopyTo(buf, offset + 2);
            BitConverter.GetBytes(status).CopyTo(buf, offset + 3);
            BitConverter.GetBytes(waterPressure).CopyTo(buf, offset + 4);
            BitConverter.GetBytes(bottomDistance).CopyTo(buf, offset + 6);
            BitConverter.GetBytes(flood).CopyTo(buf, offset + 8);
            BitConverter.GetBytes(speed).CopyTo(buf, offset + 10);
            BitConverter.GetBytes(mile).CopyTo(buf, offset + 11);
            position.ToBuffer(buf, offset+13);
        }
    }
}
  