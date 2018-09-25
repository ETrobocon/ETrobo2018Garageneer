using BricRoboRTE;
using System;
using System.Net;
using System.Net.Sockets;

namespace BricRoboApp
{
    public partial class ControlCom
    {
        /// <summary>
        /// コマンドを受けるUDP
        /// </summary>
        UdpClient cmdClient;
        /// <summary>
        /// ナビゲーションを送るUDP
        /// </summary>
        UdpClient naviClient;
        /// <summary>
        /// コマンドを受信したときの送信元
        /// </summary>
        IPEndPoint transmitterEP;
        /// <summary>
        /// 受信したコマンド
        /// </summary>
        TeniboCommandIF receiveCommand;
        /// <summary>
        /// 非同期でコマンド受信中
        /// </summary>
        bool isCmdRsving = false;
        /// <summary>
        /// コマンドを非同期受信するときに渡す情報
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
                ///Arduinoで処理せず、ここで処理したらtrueを返すこと
                default:
                    return false;
            }
        }

        /// <summary>
        /// コマンド受信
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
        /// コマンド解析
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
        /// Navi→プロポ
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
