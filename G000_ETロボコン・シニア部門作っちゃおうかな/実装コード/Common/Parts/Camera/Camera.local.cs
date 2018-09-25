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
    Webカメラ。番号を指定して複数台から1台を決定。キャプチャサイズを指定する。
    @author eguchi
    @version 1.0
    */
    public partial class Camera
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private CvCapture _cap;
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
        public PPortEv_ImageFrame Rte_Send_image;
    }

}

/* Template for Camera.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Camera
    {
        public void ConfigParam(int camNo, int width, int height)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  