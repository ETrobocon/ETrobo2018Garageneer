using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Drive2Command
    {
        public void Run()
        {
            DriveInfoIF driveIF;
            if (Rte_Receive_drive(out driveIF) == Std_ReturnType.RTE_E_OK)
            {
                TeniboCommandIF cmdIF = new TeniboCommandIF();
                cmdIF.cmd = (byte)TeniboCommnd.TC_DRIVE;
                cmdIF.param1 = (short)driveIF.steer;
                cmdIF.param2 = (short)driveIF.accel;
                Rte_Send_cmd(cmdIF);
            }
        }
    }
}
  