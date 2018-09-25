/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。

	Template:CS,BricRoboRTE_API.cs.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BricRoboRTE;
using BricRoboApp;

namespace BricRoboRTE
{
    class BricRoboRTE_API
    {
        /*
        RTE API (SenderReceiverInterface)
        */
        /* RteApiID=0 */
        public static Std_ReturnType Rte_Receive_RW_cmdIn(out TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Receive_D1(out v));
        }

        /* RteApiID=3 */
        public static Std_ReturnType Rte_Send_SW_cmdToRobo(TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Send_D1(v));
        }

        /* RteApiID=6 */
        public static Std_ReturnType Rte_Receive_SP_cmd(out SpeechIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Receive_D2(out v));
        }

        /* RteApiID=9 */
        public static Std_ReturnType Rte_Send_RW_speech(SpeechIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Send_D2(v));
        }

        /* RteApiID=12 */
        public static Std_ReturnType Rte_Receive_SW_cmdFromPropo(out TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Receive_D3(out v));
        }

        /* RteApiID=15 */
        public static Std_ReturnType Rte_Send_WIFI_command(TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Send_D3(v));
        }

        /* RteApiID=18 */
        public static Std_ReturnType Rte_Read_SW_naviFromRobo(out TeniboNaviIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Read_D4(out v));
        }

        /* RteApiID=21 */
        public static Std_ReturnType Rte_Write_TEL_navi(TeniboNaviIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Write_D4(v));
        }

        /* RteApiID=24 */
        public static Std_ReturnType Rte_Receive_TEL_command(out TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Receive_D5(out v));
        }

        /* RteApiID=27 */
        public static Std_ReturnType Rte_Send_RW_cmdOut(TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Send_D5(v));
        }

        /* RteApiID=30 */
        public static Std_ReturnType Rte_Read_WIFI_navi(out TeniboNaviIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Read_D6(out v));
        }

        /* RteApiID=33 */
        public static Std_ReturnType Rte_Write_SW_naviToPropo(TeniboNaviIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_Write_D6(v));
        }

        /* RteApiID=36 */
        public static Std_ReturnType Rte_Receive_SW_cmdFromAuto(out TeniboCommandIF v)
        {
            return (Std_ReturnType)(BricRoboCOM_API.COM_NotConnectedR(out v));
        }

        /*
        RTE API (ProcedureCallInterface Assembly)
        */
        /*
        RTE API (ProcedureCallInterface Delegate Provider)
        */
        /*
        RTE API (ProcedureCallInterface Delegate Requester)
        */
    }
}
