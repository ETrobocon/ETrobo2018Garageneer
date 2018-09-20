using BricRoboRTE;
using System;
using System.Collections.Generic;
using System.Net;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace BricRoboApp
{
    public partial class TcpServer
    {
        /// <summary>
        /// 接続待ちリスナ
        /// </summary>
        private TcpListener _listener;
        /// <summary>
        /// 接続したTCPクライアント
        /// </summary>
        TcpClient _client;
        /// <summary>
        /// コンストラクタ
        /// </summary>
        public  TcpServer()
        {
        }
        /// <summary>
        /// 接続待ち開始
        /// </summary>
        public void Start(int portNo)
        {
            _listener = new TcpListener(IPAddress.Any, portNo);
            _listener.Start();
            _listener.BeginAcceptTcpClient(HandleAccept, _listener);
        }
        /// <summary>
        /// 接続待ち終了
        /// </summary>
        public void Stop()
        {
            if (_listener != null)
            {
                _listener.Stop();
            }
        }
        /// <summary>
        /// 接続時処理ハンドラ
        /// </summary>
        /// <param name="result"></param>
        private void HandleAccept(IAsyncResult result)
        {
            _client = _listener.EndAcceptTcpClient(result);
            _client.NoDelay = true;
            _listener.BeginAcceptTcpClient(HandleAccept, _listener);
            // DO SOMETHING.
        }
        /// <summary>
        /// 接続済みクライアント取得
        /// </summary>
        /// <returns></returns>
        public TcpClient GetClient()
        {
            return _client;
        }
    }
}
