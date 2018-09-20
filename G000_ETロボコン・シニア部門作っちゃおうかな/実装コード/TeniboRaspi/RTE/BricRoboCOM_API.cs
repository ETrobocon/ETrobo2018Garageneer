/*
	【注意】このファイルは自動生成されます。ハンドコーディングしないでください。

	Template:CS,BricRoboCOM_API.cs.xsl
	Generated Date:2018/09/19 14:45:53
	Generater Name:BricRoboGen Ver:1.7.10.355  
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using BricRoboApp;

namespace BricRoboRTE
{
    partial class BricRoboCOM_API
    {
        public static Std_ReturnType COM_Read<Type>(out Type v, ref Type data, ref Std_ReturnType status)
        {
            if (status == Std_ReturnType.RTE_E_OK)
            {
                v = data;
            }
            else
            {
                v = default(Type);
            }
            return status;
        }
        public static Std_ReturnType COM_Write<Type>(Type v, ref Type data, ref Std_ReturnType status)
        {
            data = v;
            status = Std_ReturnType.RTE_E_OK;
            return Std_ReturnType.RTE_E_OK;
        }
        public static Std_ReturnType COM_Receive<Type>(out Type v, ref Type data, ref Std_ReturnType status)
        {
            if (status == Std_ReturnType.RTE_E_OK)
            {
                status = Std_ReturnType.RTE_E_NO_DATA;
                v = data;
                return Std_ReturnType.RTE_E_OK;
            }
            else
            {
                v = default(Type);
                return status;
            }
        }
        public static Std_ReturnType COM_Send<Type>(Type v, ref Type data, ref Std_ReturnType status)
        {
            status = Std_ReturnType.RTE_E_OK;
            data = v;
            return Std_ReturnType.RTE_E_OK;
        }
        public static Std_ReturnType COM_NotConnected<Type>(Type v)
        {
            return Std_ReturnType.RTE_E_NOT_CONNECTED;
        }
        public static Std_ReturnType COM_NotConnectedR<Type>(out Type v)
        {
            v = default(Type);
            return Std_ReturnType.RTE_E_NOT_CONNECTED;
        }

        private static TeniboCommandIF TaskCom_D1; /* RW_cmdIn */
        private static Std_ReturnType TaskCom_D1_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Receive_D1(out TeniboCommandIF v)
        {
            return COM_Receive<TeniboCommandIF>(out v, ref TaskCom_D1, ref TaskCom_D1_status);
        }
        public static Std_ReturnType COM_Send_D1(TeniboCommandIF v)
        {
            return COM_Send<TeniboCommandIF>(v, ref TaskCom_D1, ref TaskCom_D1_status);
        }
        private static SpeechIF TaskCom_D2; /* SP_cmd */
        private static Std_ReturnType TaskCom_D2_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Receive_D2(out SpeechIF v)
        {
            return COM_Receive<SpeechIF>(out v, ref TaskCom_D2, ref TaskCom_D2_status);
        }
        public static Std_ReturnType COM_Send_D2(SpeechIF v)
        {
            return COM_Send<SpeechIF>(v, ref TaskCom_D2, ref TaskCom_D2_status);
        }
        private static TeniboCommandIF TaskCom_D3; /* SW_cmdFromPropo */
        private static Std_ReturnType TaskCom_D3_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Receive_D3(out TeniboCommandIF v)
        {
            return COM_Receive<TeniboCommandIF>(out v, ref TaskCom_D3, ref TaskCom_D3_status);
        }
        public static Std_ReturnType COM_Send_D3(TeniboCommandIF v)
        {
            return COM_Send<TeniboCommandIF>(v, ref TaskCom_D3, ref TaskCom_D3_status);
        }
        private static TeniboNaviIF TaskCom_D4; /* SW_naviFromRobo */
        private static Std_ReturnType TaskCom_D4_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Read_D4(out TeniboNaviIF v)
        {
            return COM_Read<TeniboNaviIF>(out v, ref TaskCom_D4, ref TaskCom_D4_status);
        }
        public static Std_ReturnType COM_Write_D4(TeniboNaviIF v)
        {
            return COM_Write<TeniboNaviIF>(v, ref TaskCom_D4, ref TaskCom_D4_status);
        }
        private static TeniboCommandIF TaskCom_D5; /* TEL_command */
        private static Std_ReturnType TaskCom_D5_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Receive_D5(out TeniboCommandIF v)
        {
            return COM_Receive<TeniboCommandIF>(out v, ref TaskCom_D5, ref TaskCom_D5_status);
        }
        public static Std_ReturnType COM_Send_D5(TeniboCommandIF v)
        {
            return COM_Send<TeniboCommandIF>(v, ref TaskCom_D5, ref TaskCom_D5_status);
        }
        private static TeniboNaviIF TaskCom_D6; /* WIFI_navi */
        private static Std_ReturnType TaskCom_D6_status = Std_ReturnType.RTE_E_NO_DATA;
        public static Std_ReturnType COM_Read_D6(out TeniboNaviIF v)
        {
            return COM_Read<TeniboNaviIF>(out v, ref TaskCom_D6, ref TaskCom_D6_status);
        }
        public static Std_ReturnType COM_Write_D6(TeniboNaviIF v)
        {
            return COM_Write<TeniboNaviIF>(v, ref TaskCom_D6, ref TaskCom_D6_status);
        }
    }
}
