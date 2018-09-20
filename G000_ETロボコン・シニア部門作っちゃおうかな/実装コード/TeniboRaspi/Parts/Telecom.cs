using BricRoboRTE;
using System;
using System.IO.Ports;
using int8_t = System.SByte;
using int16_t = System.Int16;

namespace BricRoboApp
{
    public partial class Telecom
    {
        /*
         * ナビゲーションをシリアルで送るときのバイト数
         * */
        public const int bufferSizeNavi = 2 + TeniboNaviIF.bufSize;
        /*
         * コマンドをシリアルで送るときのバイト数
         * */
        public const int bufferSizeCommand = 2 + TeniboCommandIF.bufSize;
        public void ConfigParam(int baudRate)
        {
            string[] tty;
            if (Environment.OSVersion.Platform == PlatformID.Unix)
            {
                tty = System.IO.Directory.GetFiles("/dev", "ttyUSB*");
            }
            else
            {
                tty = new string[] { "COM9" };
            }
            if (tty.Length == 1)
            {
                Console.WriteLine("Open COM:{0}", tty[0]);
                _port = new SerialPort(tty[0], baudRate, Parity.None, 8, StopBits.One);
                try
                {
                    //_port.WriteBufferSize = bufferSizeCommand;
                    //_port.ReadBufferSize = bufferSizeNavi;
                    _port.Open();
                    System.Console.WriteLine("opened " + tty[0]);
                }
                catch (Exception ex)
                {
                    System.Console.WriteLine("ERROR: Open COM. [{0}]", ex.Message);
                }
            }
            else
            {
                System.Console.WriteLine("ERROR: No COM");
            }
        }
        public void RunTxNavi()
        {
            try
            {
                if (_port.BytesToRead >= bufferSizeNavi)
                {
                    //System.Console.WriteLine("COM BytesToRead {0}byte", _port.BytesToRead);
                    byte[] buf = new byte[bufferSizeNavi];
                    _port.Read(buf, 0, bufferSizeNavi);
                    _port.DiscardInBuffer();//ここで貯まったバッファは捨てる

                    byte magic1 = buf[0];
                    byte magic2 = buf[1];

                    if (magic1 != (byte)TeniboComMagic.MAGIC_1 || magic2 != (byte)TeniboComMagic.MAGIC_2)
                    {
                        //マジックが合わないので終了
                        return;
                    }

                    TeniboNaviIF naviIF = new TeniboNaviIF();
                    naviIF.FromBuffer(buf, 2);
                    Rte_Write_navi(naviIF);

                    System.Console.WriteLine("COM->NAVI--WIFI {0}", naviIF.ToString());//@@@
                }
            }
            catch (Exception)
            {
                //TeniboNaviIF naviIF = new TeniboNaviIF();//@@@
                //naviIF.battery = 1234;
                //naviIF.status = (ushort)TeniboStatus.TS_OK;
                //Rte_Write_navi(naviIF);

                System.Console.WriteLine("ERROR: Read COM(navi)");
            }
        }
        public void RunRxCommand()
        {
            TeniboCommandIF commandIF;
            if (Rte_Receive_command(out commandIF) == Std_ReturnType.RTE_E_OK)
            {
                byte[] buf = new byte[bufferSizeCommand];
                buf[0] = (byte)TeniboComMagic.MAGIC_1;
                buf[1] = (byte)TeniboComMagic.MAGIC_2;
                commandIF.ToBuffer(buf, 2);

                try
                {
                    _port.Write(buf, 0, bufferSizeCommand);
                }
                catch (Exception)
                {
                    System.Console.WriteLine("ERROR: Write COM(cmd)");
                }

                System.Console.WriteLine("  COM<-CMD--WIFI {0}", commandIF.ToString());//@@@
            }
        }
    }
}
  