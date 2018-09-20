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
    
    @author eguchi
    @version 1.0
    */
    public partial class LedDriver
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private int8_t _pin;
        /**
	LedPatternの番号
        */
        private int8_t _no;
        /**
	
        */
        private int8_t _row;
        /**
	
        */
        private uint8_t _hiLow;
        /**
	
        */
        private uint8_t _times;
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
        public RPortEv_ValueIF Rte_Receive_patternNo;
    }

}

/* Template for LedDriver.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class LedDriver
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
  