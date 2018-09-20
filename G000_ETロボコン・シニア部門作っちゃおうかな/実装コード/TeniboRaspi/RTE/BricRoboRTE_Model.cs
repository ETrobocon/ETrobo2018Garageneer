/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。

	Template:CS,BricRoboRTE_Model.cs.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using BricRoboApp;

namespace BricRoboRTE
{
    partial class BricRoboController
    {
        public static TeniboRaspiApp TopLevel = new TeniboRaspiApp();

        /*
        ConfigParam
        */
        void ConfigParam()
        {
            TopLevel.TEL.ConfigParam(115200);
            TopLevel.WIFI.ConfigParam(5556, 5554);
        }

        /*
        RTE-COM
        */
        void ConnectRteApi()
        {
            TopLevel.RW.Rte_Receive_cmdIn = BricRoboRTE_API.Rte_Receive_RW_cmdIn;
            TopLevel.SW.Rte_Send_cmdToRobo = BricRoboRTE_API.Rte_Send_SW_cmdToRobo;
            TopLevel.SP.Rte_Receive_cmd = BricRoboRTE_API.Rte_Receive_SP_cmd;
            TopLevel.RW.Rte_Send_speech = BricRoboRTE_API.Rte_Send_RW_speech;
            TopLevel.SW.Rte_Receive_cmdFromPropo = BricRoboRTE_API.Rte_Receive_SW_cmdFromPropo;
            TopLevel.WIFI.Rte_Send_command = BricRoboRTE_API.Rte_Send_WIFI_command;
            TopLevel.SW.Rte_Read_naviFromRobo = BricRoboRTE_API.Rte_Read_SW_naviFromRobo;
            TopLevel.TEL.Rte_Write_navi = BricRoboRTE_API.Rte_Write_TEL_navi;
            TopLevel.TEL.Rte_Receive_command = BricRoboRTE_API.Rte_Receive_TEL_command;
            TopLevel.RW.Rte_Send_cmdOut = BricRoboRTE_API.Rte_Send_RW_cmdOut;
            TopLevel.WIFI.Rte_Read_navi = BricRoboRTE_API.Rte_Read_WIFI_navi;
            TopLevel.SW.Rte_Write_naviToPropo = BricRoboRTE_API.Rte_Write_SW_naviToPropo;
            TopLevel.SW.Rte_Receive_cmdFromAuto = BricRoboRTE_API.Rte_Receive_SW_cmdFromAuto;
        }
    }
}
