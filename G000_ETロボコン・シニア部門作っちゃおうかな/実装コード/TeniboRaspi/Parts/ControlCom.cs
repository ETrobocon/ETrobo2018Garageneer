using BricRoboRTE;
using System;
using System.Net;
using System.Net.Sockets;

namespace BricRoboApp
{
    public partial class ControlCom
    {
        /// <summary>
        /// �R�}���h���󂯂�UDP
        /// </summary>
        UdpClient cmdClient;
        /// <summary>
        /// �i�r�Q�[�V�����𑗂�UDP
        /// </summary>
        UdpClient naviClient;
        /// <summary>
        /// �R�}���h����M�����Ƃ��̑��M��
        /// </summary>
        IPEndPoint transmitterEP;
        /// <summary>
        /// ��M�����R�}���h
        /// </summary>
        TeniboCommandIF receiveCommand;
        /// <summary>
        /// �񓯊��ŃR�}���h��M��
        /// </summary>
        bool isCmdRsving = false;
        /// <summary>
        /// �R�}���h��񓯊���M����Ƃ��ɓn�����
        /// </summary>
        class UdpState
        {
            public UdpClient client;
            public IPEndPoint ep;
        }

        int _naviPortNo;

        public void ConfigParam(int cmdPortNo, int naviPortNo)
        {
            cmdClient = new UdpClient(cmdPortNo);
            cmdClient.Client.ReceiveBufferSize = 0;
            naviClient = new UdpClient();
            _naviPortNo = naviPortNo;
            System.Console.WriteLine("CmdPort={0} NaviPort={1}", cmdPortNo, naviPortNo);
        }
        public void RunToCommand()
        {
            if (receiveCommand != null)
            {
                System.Console.WriteLine("  COM--CMD<-WIFI {0}", receiveCommand.ToString());//@@@
                DispatchCommand(receiveCommand);
                Rte_Send_command(receiveCommand);
                receiveCommand = null;
            }
            if (!isCmdRsving)
            {
                isCmdRsving = true;
                IPEndPoint ep = new IPEndPoint(IPAddress.Any, 0);
                UdpState st = new UdpState();
                st.client = cmdClient;
                st.ep = ep;
                cmdClient.BeginReceive(new AsyncCallback(ReceiveCallback), st);
            }
        }

        bool DispatchCommand(TeniboCommandIF cmd)
        {
            switch (cmd.cmd)
            {
                ///Arduino�ŏ��������A�����ŏ���������true��Ԃ�����
                default:
                    return false;
            }
        }

        /// <summary>
        /// �R�}���h��M
        /// </summary>
        /// <param name="ar"></param>
        public void ReceiveCallback(IAsyncResult ar)
        {
            UdpClient ct = ((UdpState)ar.AsyncState).client;
            IPEndPoint ep = ((UdpState)ar.AsyncState).ep;
            byte[] data = ct.EndReceive(ar, ref ep);
            ParseRsvBuffer(data, ep);
            transmitterEP = ep;
            transmitterEP.Port = _naviPortNo;
            isCmdRsving = false;
        }
        /// <summary>
        /// �R�}���h���
        /// </summary>
        /// <param name="rsvData"></param>
        /// <param name="ep"></param>
        void ParseRsvBuffer(byte[] rsvData, IPEndPoint ep)
        {
            if (rsvData.Length != TeniboCommandIF.bufSize)
            {
                return;
            }
            TeniboCommandIF cmdIF = new TeniboCommandIF();
            cmdIF.FromBuffer(rsvData, 0);
            receiveCommand = cmdIF;
        }

        /// <summary>
        /// Navi���v���|
        /// </summary>
        public void RunFromNavi()
        {
            TeniboNaviIF naviIF;
            if (Rte_Read_navi(out naviIF) == Std_ReturnType.RTE_E_OK)
            {
                if (transmitterEP != null)
                {
                    byte[] data = new byte[TeniboNaviIF.bufSize];
                    naviIF.ToBufer(data, 0);
                    naviClient.Send(data, data.Length, transmitterEP);
                    System.Console.WriteLine("COM--NAVI->WIFI {0}", naviIF.ToString());//@@@
                }
            }
        }
    }
}
