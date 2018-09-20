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
    ToF距離センサー　VL53L0Xを使って距離計測する。
    @author ike
    @version 1.0
    */
    public partial class ToF_VL53L0X
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private VL53L0X sensor;
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
        public PPort_ValueIF Rte_Write_out;
    }

}

/* Template for ToF_VL53L0X.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ToF_VL53L0X
    {
        public void ConfigParam(int IsLongRange, int speed)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  