using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace BricRoboRTE
{
    delegate void BricRoboTaskRun();

    partial class BricRoboTask
    {
	    /* ������� */
        public int _elapse;
	    /* ��������̏����l�A������Task�̃^�C�~���O�����Ɏg�� */
        public int _timer;
	    /* ���s����RunnableEntity���X�g */
        public BricRoboTaskRun _run;

        public BricRoboTask(int elapse, int timer, BricRoboTaskRun run)
        {
            _elapse = elapse;
            _timer = timer;
            _run = run;
        }
    }
}
