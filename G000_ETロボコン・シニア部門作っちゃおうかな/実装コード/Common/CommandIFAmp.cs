using BricRoboRTE;

namespace BricRoboApp
{
    public partial class CommandIFAmp
    {
        public void Run()
        {
            CommandIF v;
            if (Rte_Receive_in(out v) == Std_ReturnType.RTE_E_OK)
            {
                Rte_Send_out(v);
            }
        }
    }
}
  