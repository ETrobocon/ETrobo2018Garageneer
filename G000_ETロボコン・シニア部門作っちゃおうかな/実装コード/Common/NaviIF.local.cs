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

    public delegate Std_ReturnType PPort_NaviIF(NaviIF i);
    public delegate Std_ReturnType PPortEv_NaviIF(NaviIF i);
    public delegate Std_ReturnType RPort_NaviIF(out NaviIF i);
    public delegate Std_ReturnType RPortEv_NaviIF(out NaviIF i);
  
    /**
ロボットの状態を知らせる
    @author eguchi
    @version 1.0
    */
    public partial class NaviIF
    {
        /*
        User Defined Attribute
        */
        /**
	胸ビレの角度の値(-90..+90)
        */
        public int8_t pecFin;
        /**
	尾ビレの角度の値(-90..+90)
        */
        public int8_t tailFin;
        /**
	推進力の値(0-100)
        */
        public int8_t jetPower;
        /**
	
        */
        public uint8_t status;
        /**
	水圧計の値（生値）
        */
        public int16_t waterPressure;
        /**
	水底からの距離(cm)
        */
        public int16_t bottomDistance;
        /**
	浸水センサーの値(0-1023)
        */
        public int16_t flood;
        /**
	速度（cm/秒）
        */
        public uint8_t speed;
        /**
	cm単位
        */
        public uint16_t mile;
        /**
	
        */
        public PositionIF position;
    }

}

/* Template for NaviIF.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class NaviIF
    {
        
    }
}
*/
  