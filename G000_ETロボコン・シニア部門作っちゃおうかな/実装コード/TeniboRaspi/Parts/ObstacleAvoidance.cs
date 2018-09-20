using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ObstacleAvoidance
    {
        public void Run()
        {
            ImageFrameIF frame;
            if (Rte_Receive_in(out frame) == Std_ReturnType.RTE_E_OK)
            {
                //DriveInfoIF drive = new DriveInfoIF();
                //Rte_Send_out(drive);
            }
        }
    }
}
  