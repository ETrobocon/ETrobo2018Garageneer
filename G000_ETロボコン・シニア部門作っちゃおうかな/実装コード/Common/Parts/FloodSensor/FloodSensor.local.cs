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
    AD変換して抵抗値を測る。

    @author eguchi
    @version 1.0
    */
    public partial class FloodSensor
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private int8_t _pin;
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
	AD変換した値。
        */
        public PPort_ValueIF Rte_Write_value;
    }

}

/* Template for FloodSensor.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class FloodSensor
    {
        public void ConfigParam(int8_t pin)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  