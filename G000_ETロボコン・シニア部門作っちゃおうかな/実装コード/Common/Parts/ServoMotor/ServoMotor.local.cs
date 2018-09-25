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
    単位は度。

    @author eguchi
    @version 1.0
    */
    public partial class ServoMotor
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private Servo _servo;
        /**
	0度を指定したときのサーボホーンの角度(0..180)
        */
        private int8_t _center;
        /**
	入力値に掛ける値。-1を指定すれば回転方向が逆になる。
        */
        private float _K;
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
	サーボモーターの角度。
        */
        public RPort_ValueIF Rte_Read_in;
    }

}

/* Template for ServoMotor.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class ServoMotor
    {
        public void ConfigParam(int8_t pin, int8_t center, float K)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  