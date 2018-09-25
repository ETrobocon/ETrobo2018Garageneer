using BricRoboRTE;

namespace BricRoboApp
{
    public partial class NaviIFAmp
    {
        public void Run()
        {
            NaviIF navi;
            if (Rte_Read_in(out navi) == Std_ReturnType.RTE_E_OK)
            {
                Rte_Write_out(navi);
            }
        }
    }
}
  