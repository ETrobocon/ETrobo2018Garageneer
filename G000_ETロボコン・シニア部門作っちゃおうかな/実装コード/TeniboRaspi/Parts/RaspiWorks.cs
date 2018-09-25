using BricRoboRTE;

namespace BricRoboApp
{
    public partial class RaspiWorks
    {
        SpeechIF _speechIF;
        public void Run()
        {
            TeniboCommandIF cmd;
            if (Rte_Receive_cmdIn(out cmd) == Std_ReturnType.RTE_E_OK)
            {
                if ((cmd.cmd & (byte)TeniboCommnd.TC_TALK) != 0)
                {
                    if ((cmd.cmd & (byte)TeniboCommnd.TC_TALKS) != 0)
                    {
                        _speechIF = new SpeechIF();
                    }
                    CramText(cmd);
                    if ((cmd.cmd & (byte)TeniboCommnd.TC_TALKE) != 0)
                    {
                        Rte_Send_speech(_speechIF);
                    }
                }
                Rte_Send_cmdOut(cmd);
            }
        }
        private void CramText(TeniboCommandIF cmd)
        {
            if (_speechIF != null)
            {
                if (cmd.param1 != 0)
                {
                    _speechIF.text += (char)cmd.param1;
                }
                if (cmd.param2 != 0)
                {
                    _speechIF.text += (char)cmd.param2;
                }
                if (cmd.param3 != 0)
                {
                    _speechIF.text += (char)cmd.param3;
                }
                if (cmd.param4 != 0)
                {
                    _speechIF.text += (char)cmd.param4;
                }
                if (cmd.param5 != 0)
                {
                    _speechIF.text += (char)cmd.param5;
                }
            }
        }
    }
}
  