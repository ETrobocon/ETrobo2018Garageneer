/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,CompositionType.local.xsl
	Generated Date:2017/01/23 13:47:48
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */

using BricRoboRTE;
using OpenCvSharp;
using System.IO.Ports;

namespace BricRoboApp
{
    /**
    カメラの映像を要求するクライアントに送信する。
送信方法は、TCPサーバに接続してきたクライアントに対し、1枚の画像をJPEG圧縮して、32KB単位で分割して送信する。
    @author eguchi
    @version 1.0
    */
    public partial class VideoCom
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private TcpServer _server;
        /*
        Auto Generated Attribute
        */
        /*
        Auto Generated Method
        */
        /*
        Auto RunnableEntity
        */
        /*
        Port
        */
        /**
	
        */
        public RPortEv_ImageFrame Rte_Receive_img;
    }

}

/* Template for VideoCom.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class VideoCom
    {
        public void ConfigParam(int portNo)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  