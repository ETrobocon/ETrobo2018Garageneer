/*
	�y���Ӂz���̃t�@�C���͎�����������܂��B�n���h�R�[�f�B���O���Ȃ��ł��������B

	Template:CS,BricRoboRTE_Task.cs.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using BricRoboRTE;

namespace BricRoboRTE
{
    partial class BricRoboController
    {
        void TASK_CMD_Run()
        {
	        TopLevel.WIFI.RunToCommand();
	        TopLevel.SW.RunCmd();
	        TopLevel.RW.Run();
	        TopLevel.TEL.RunRxCommand();
        }
        void TASK_NAVI_Run()
        {
	        TopLevel.TEL.RunTxNavi();
	        TopLevel.SW.RunNavi();
	        TopLevel.WIFI.RunFromNavi();
        }
        void TASK_UI_Run()
        {
	        TopLevel.SP.Run();
        }


        List<BricRoboTask> _taskList;
        void InitTask()
        {
            _taskList = new List<BricRoboTask>
            {

                /**
                �v���|����Arduino����
                @author eguchi
                @version 1.0
                */
                new BricRoboTask( 50, 0, TASK_CMD_Run ),
                /**
                Arduino������v���|��
                @author eguchi
                @version 1.0
                */
                new BricRoboTask( 50, 1, TASK_NAVI_Run ),
                /**
                UI�n�̂�����肵������
                @author eguchi
                @version 1.0
                */
                new BricRoboTask( 500, 2, TASK_UI_Run )
            };
        }
    }
}
