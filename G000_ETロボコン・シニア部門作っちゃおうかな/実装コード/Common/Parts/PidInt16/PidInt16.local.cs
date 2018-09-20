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
    Arduinoでメモリ節約するため、パラメタが8ビットのPID、。
    @author eguchi
    @version 1.0
    */
    public partial class PidInt16
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private int16_t _Kp1;
        /**
	
        */
        private int16_t _Kp2;
        /**
	
        */
        private int16_t _Ki1;
        /**
	
        */
        private int16_t _Ki2;
        /**
	
        */
        private int16_t _Kd1;
        /**
	
        */
        private int16_t _Kd2;
        /**
	
        */
        private int16_t _oldD;
        /**
	
        */
        private int16_t _I;
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
    }

}

/* Template for PidInt16.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PidInt16
    {
        public int16_t Calc(int16_t target, int16_t current)
        {
        }
        public void Reset()
        {
        }
        public void SetParam(int16_t p1, int16_t p2, int16_t i1, int16_t i2, int16_t d1, int16_t d2)
        {
        }
        public void ConfigParam(int16_t Kp1, int16_t Kp2, int16_t Ki1, int16_t Ki2, int16_t Kd1, int16_t Kd2)
        {
        }

    }
}
*/
  