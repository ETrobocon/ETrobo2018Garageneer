using BricRoboRTE;
using uint16_t = System.UInt16;

namespace BricRoboApp
{
    public partial class ControlSwitcher
    {
        public void RunCmd()
        {
            TeniboCommandIF cmdPropo = null;
            Rte_Receive_cmdFromPropo(out cmdPropo);

            if (cmdPropo != null && cmdPropo.cmd == (byte)TeniboCommnd.TC_MODE)
            {
                isAutoMode = cmdPropo.param1 == 1;
            }

            TeniboCommandIF cmdAuto = null;
            Rte_Receive_cmdFromAuto(out cmdAuto);

            if (isAutoMode)
            {
                if (cmdAuto != null)
                {
                    Rte_Send_cmdToRobo(cmdAuto);
                }
            }
            else
            {
                if (cmdPropo != null)
                {
                    Rte_Send_cmdToRobo(cmdPropo);
                }
            }
        }
        public void RunNavi()
        {
            TeniboNaviIF navi;
            if (Rte_Read_naviFromRobo(out navi) == Std_ReturnType.RTE_E_OK)
            {
                if (isAutoMode)
                {
                    navi.status |= (uint16_t)TeniboStatus.TS_AUTO;
                }

                Rte_Write_naviToPropo(navi);
            }
        }
    }
}
  