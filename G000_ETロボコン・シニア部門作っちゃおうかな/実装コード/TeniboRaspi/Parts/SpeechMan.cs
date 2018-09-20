using System;
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class SpeechMan
    {
        public void Run()
        {
            SpeechIF cmd;
            if (Rte_Receive_cmd(out cmd) == Std_ReturnType.RTE_E_OK)
            {
                Console.WriteLine("Speech:{0}", cmd.text);
                try
                {
                    string cmdline = string.Format("/home/pi/jsay.sh {0}", cmd.text);
                    System.Diagnostics.Process.Start("sh", cmdline);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("ERROR:{0}", ex.Message);
                }
            }
        }
    }
}
  