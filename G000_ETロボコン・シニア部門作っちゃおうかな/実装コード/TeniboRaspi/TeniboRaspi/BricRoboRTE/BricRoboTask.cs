using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace BricRoboRTE
{
    delegate void BricRoboTaskRun();

    partial class BricRoboTask
    {
	    /* 定期周期 */
        public int _elapse;
	    /* 定期周期の初期値、複数のTaskのタイミング調整に使う */
        public int _timer;
	    /* 実行するRunnableEntityリスト */
        public BricRoboTaskRun _run;

        public BricRoboTask(int elapse, int timer, BricRoboTaskRun run)
        {
            _elapse = elapse;
            _timer = timer;
            _run = run;
        }
    }
}
