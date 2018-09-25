/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。
  
	Template:CS,CompositionType.local.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using BricRoboRTE;
using OpenCvSharp;
using System.IO.Ports;

namespace BricRoboApp
{
    /**
    ２つの入力のうち、firstを優先してoutに出力する。firstに何も入力がない場合だけsecondがoutに出力される。
    @author ike
    @version 1.0
    */
    public partial class PrioritySelector
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
	
        */
        public RPortEv_DriveInfoIF Rte_Receive_first;
        /**
	
        */
        public PPortEv_DriveInfoIF Rte_Send_out;
        /**
	
        */
        public RPortEv_DriveInfoIF Rte_Receive_second;
    }

}

/* Template for PrioritySelector.cs
using BricRoboRTE;

namespace BricRoboApp
{
    public partial class PrioritySelector
    {
        public void Run()
        {
        }

    }
}
*/
  