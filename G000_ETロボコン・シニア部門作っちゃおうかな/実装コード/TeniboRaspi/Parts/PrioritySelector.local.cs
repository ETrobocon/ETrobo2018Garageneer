/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B
  
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
    �Q�̓��͂̂����Afirst��D�悵��out�ɏo�͂���Bfirst�ɉ������͂��Ȃ��ꍇ����second��out�ɏo�͂����B
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
  