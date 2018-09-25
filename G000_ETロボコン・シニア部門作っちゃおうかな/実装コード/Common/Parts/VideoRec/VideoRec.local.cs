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
    recに0,1で指定録画開始、それ以外の値は録画停止
    @author eguchi
    @version 1.0
    */
    public partial class VideoRec
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private string _videoPathOverlay;
        /**
	
        */
        private string _videoPathOriginal;
        /**
	録画するフレームの時間間隔（ミリ秒）
        */
        private int _elapse;
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
        public RPortEv_ImageFrame Rte_Receive_chaOriginal;
        /**
	
        */
        public RPortEv_ImageFrame Rte_Receive_chaOverlay;
        /**
	
        */
        public RPortEv_VideoRecIF Rte_Receive_rec;
        /**
	
        */
        public PPort_VideoRecIF Rte_Write_status;
    }

}

/* Template for VideoRec.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class VideoRec
    {
        public void ConfigParam(string videoPathOverlay, string videoPathOriginal, int elapse)
        {
        }
        public void RunOverlay()
        {
        }
        public void RunOriginal()
        {
        }

    }
}
*/
  