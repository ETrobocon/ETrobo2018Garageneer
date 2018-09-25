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
    SCL：A5ピン
SDA：A4ピン
INT：D2
I2Cを使ってMPU-6050と通信するので、この部品は1回しか使えない。
    @author eguchi
    @version 1.0
    */
    public partial class PositionSensor
    {
        /*
        User Defined Attribute
        */
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
	計測した姿勢
        */
        public PPort_PositionIF Rte_Write_out;
    }

}

/* Template for PositionSensor.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PositionSensor
    {
        public void ConfigParam(int8_t dummy)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  