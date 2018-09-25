/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,SenderReceiverInterface.local.xsl
	Generated Date:2017/01/23 13:47:48
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */


using BricRoboRTE;
using OpenCvSharp;
using int8_t = System.SByte;
using uint8_t = System.Byte;
using int16_t = System.Int16;
using uint16_t = System.UInt16;

namespace BricRoboApp
{

    public delegate Std_ReturnType PPort_VideoRecIF(VideoRecIF i);
    public delegate Std_ReturnType PPortEv_VideoRecIF(VideoRecIF i);
    public delegate Std_ReturnType RPort_VideoRecIF(out VideoRecIF i);
    public delegate Std_ReturnType RPortEv_VideoRecIF(out VideoRecIF i);
  
    /**

    @author eguchi
    @version 1.0
    */
    public partial class VideoRecIF
    {
        /*
        User Defined Attribute
        */
        /**
	チャネル0ビデオ録画指示
        */
        public bool channelOvl;
        /**
	チャネル0ビデオ録画指示
        */
        public bool channelOrg;
    }

}

/* Template for VideoRecIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class VideoRecIF
    {
        
    }
}
*/
  