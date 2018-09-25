/******************************************************************************
	BricRobo Controller for Boxfish C#
	Copyright(C) 2008-2014 Fujitsu Computer Technologies Ltd.
*******************************************************************************/

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using MicroLibrary;
using BricRoboApp;

namespace BricRoboRTE
{
    partial class BricRoboController
    {
        static bool _stop = false;
		const long oneMsTick = 1000L;

        static void Main(string[] args)
        {
            BricRoboController ctl = new BricRoboController();
            
            ctl.Init();
            ctl.Run();
        }

        BricRoboController()
        {
        }

        void Init()
        {
            InitTask();
			PreTask();
            ConnectRteApi();
            ConfigParam();
        }

        class TaskElement
        {
            public BricRoboTask br;
            public int elapse;
            public AutoResetEvent signal;
            public Thread threadTimer;
            public TaskElement(BricRoboTask b)
            {
                br = b;
                elapse = b._timer;
                signal = new AutoResetEvent(false);
                ThreadStart threadStart = delegate ()
                {
                    while (true)
                    {
                        signal.WaitOne();
                        br._run();
                    }
                };
                threadTimer = new Thread(threadStart);
                threadTimer.Priority = System.Threading.ThreadPriority.AboveNormal;
                threadTimer.Start();
            }
        }

        List<TaskElement> tasks = new List<TaskElement>();
        MicroTimer masterTimer;

        void Tick()
        {
            foreach (TaskElement ele in tasks)
            {
                if (--ele.elapse <= 0)
                {
                    ele.elapse = ele.br._elapse;
                    ele.signal.Set();
                }
            }
        }
        void PreTask()
        {

            foreach (BricRoboTask br in _taskList)
            {
                TaskElement ele = new TaskElement(br);
                tasks.Add(ele);
            }

            masterTimer = new MicroTimer(oneMsTick);
            masterTimer.MicroTimerElapsed += new MicroTimer.MicroTimerElapsedEventHandler(
                delegate {
                    Tick();
                });
        }
        void Run ()
		{
            masterTimer.Start();

            while (!_stop)
            {
				Thread.Sleep(1000);
            }

            masterTimer.Stop();

            foreach (TaskElement ele in tasks)
            {
                ele.threadTimer.Abort();
            }
        }
        public static void Exit()
		{
			_stop = true;
		}
    }
}

