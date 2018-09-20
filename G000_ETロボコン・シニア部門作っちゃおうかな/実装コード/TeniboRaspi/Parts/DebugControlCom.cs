using BricRoboRTE;
using System;
namespace BricRoboApp
{
    public partial class DebugControlCom
    {
        short ledPattern = 0;
        public void ConfigParam(int cmdPortNo, int naviPortNo)
        {
        }
        public void RunFromNavi()
        {
            TeniboNaviIF navi;
            if (Rte_Read_navi(out navi) == Std_ReturnType.RTE_E_OK)
            {
               Console.WriteLine("  COM--NAVI->WIFI {0}", navi.ToString());
            }
        }
        public void RunToCommand()
        {
            
            if (++_counter > 100)
            {
                _counter = 0;

                TeniboCommandIF cmd = new TeniboCommandIF();
                cmd.cmd = (byte)TeniboCommnd.TC_LIGHT;
                cmd.param1 = ledPattern;
                Rte_Send_command(cmd);
                Console.WriteLine("  COM--NAVI<-WIFI cmd:{0}", cmd.cmd);

                if (++ledPattern > 16)
                {
                    ledPattern = 0;
                }

            }
        }

    }
}
  