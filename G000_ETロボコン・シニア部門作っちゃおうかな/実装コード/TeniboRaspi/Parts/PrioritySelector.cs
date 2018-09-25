using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PrioritySelector
    {
        public void Run()
        {
            DriveInfoIF first;
            DriveInfoIF second;
            if (Rte_Receive_first(out first) == Std_ReturnType.RTE_E_OK)
            {
                Rte_Send_out(first);
            }
            else
            {
                if (Rte_Receive_second(out second) == Std_ReturnType.RTE_E_OK)
                {
                    Rte_Send_out(second);
                }
            }
        }
    }
}
  