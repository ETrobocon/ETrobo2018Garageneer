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
    HMC5883Lで計測したX軸方向
（0－360度）
    @author ike
    @version 1.0
    */
    public partial class Compass_HMC5883L
    {
        /*
        User Defined Attribute
        */
        /**
	
        */
        private HMC5883L compass;
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
        public PPort_ValueIF Rte_Write_dir;
    }

}

/* Template for Compass_HMC5883L.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class Compass_HMC5883L
    {
        public void ConfigParam(int dummy)
        {
        }
        public void Run()
        {
        }

    }
}
*/
  