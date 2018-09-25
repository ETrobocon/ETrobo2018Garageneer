using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BricRoboRTE
{
    public enum Std_ReturnType
    {
        RTE_E_OK = 0,
        RTE_E_INVALID = 1,
        RTE_E_MAX_AGE_EXCEEDED = 2,
        RTE_E_NO_DATA = 4,
        RTE_E_TIMEOUT = 8,
        RTE_E_LOST_DATA = 16,
        RTE_E_LIMIT = 32,
        RTE_E_COM_STOPPED = 64,
        //接続されていないPortへのアクセス
        RTE_E_NOT_CONNECTED = 128,
    }
}
