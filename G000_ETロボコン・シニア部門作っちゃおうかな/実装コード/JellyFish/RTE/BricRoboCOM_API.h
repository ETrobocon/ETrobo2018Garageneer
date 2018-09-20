/*
	[NOTE] This file is automatically generated. Please do not hand-coded.

	Template:C++,BricRoboCOM_API.h.xsl
	Generated Date:2017/01/23 13:47:44
	Generater Name:BricRoboGen Ver:1.7.10.351  
 */
#ifndef ComsarCOM_API_H
#define ComsarCOM_API_H
#include "BricRoboCOM.h"

/*
Interface
*/
#include "../../BricRoboSketch/ValueIF.h"
#include "../../Common/JellyFish/JellyFishCommandIF.h"
#include "../../Common/JellyFish/JellyFishNavi.h"
#include "../Parts/SwimController/SwimControllerIF.h"
#include "../../Common/PidParamIF.h"
#include "../Parts/CmdController/StabiIF.h"
#include "../../Common/PositionIF.h"
#include "../../Common/JellyFish/JellyFishNaviIF.h"

/*
COM API
*/
#define COM_Write_D1(v)	COM_Write(TaskCom_D1,v,TaskCom_D1_status)
#define COM_Read_D1(v)	COM_Read(TaskCom_D1,v,TaskCom_D1_status)
#define COM_Send_D1(v)	COM_Send(TaskCom_D1,v,TaskCom_D1_status)
#define COM_Receive_D1(v)	COM_Receive(TaskCom_D1,v,TaskCom_D1_status)
#define COM_Write_D2(v)	COM_Write(TaskCom_D2,v,TaskCom_D2_status)
#define COM_Read_D2(v)	COM_Read(TaskCom_D2,v,TaskCom_D2_status)
#define COM_Send_D2(v)	COM_Send(TaskCom_D2,v,TaskCom_D2_status)
#define COM_Receive_D2(v)	COM_Receive(TaskCom_D2,v,TaskCom_D2_status)
#define COM_Write_D3(v)	COM_Write(TaskCom_D3,v,TaskCom_D3_status)
#define COM_Read_D3(v)	COM_Read(TaskCom_D3,v,TaskCom_D3_status)
#define COM_Send_D3(v)	COM_Send(TaskCom_D3,v,TaskCom_D3_status)
#define COM_Receive_D3(v)	COM_Receive(TaskCom_D3,v,TaskCom_D3_status)
#define COM_Write_D4(v)	COM_Write(TaskCom_D4,v,TaskCom_D4_status)
#define COM_Read_D4(v)	COM_Read(TaskCom_D4,v,TaskCom_D4_status)
#define COM_Send_D4(v)	COM_Send(TaskCom_D4,v,TaskCom_D4_status)
#define COM_Receive_D4(v)	COM_Receive(TaskCom_D4,v,TaskCom_D4_status)
#define COM_Write_D5(v)	COM_Write(TaskCom_D5,v,TaskCom_D5_status)
#define COM_Read_D5(v)	COM_Read(TaskCom_D5,v,TaskCom_D5_status)
#define COM_Send_D5(v)	COM_Send(TaskCom_D5,v,TaskCom_D5_status)
#define COM_Receive_D5(v)	COM_Receive(TaskCom_D5,v,TaskCom_D5_status)
#define COM_Write_D6(v)	COM_Write(TaskCom_D6,v,TaskCom_D6_status)
#define COM_Read_D6(v)	COM_Read(TaskCom_D6,v,TaskCom_D6_status)
#define COM_Send_D6(v)	COM_Send(TaskCom_D6,v,TaskCom_D6_status)
#define COM_Receive_D6(v)	COM_Receive(TaskCom_D6,v,TaskCom_D6_status)
#define COM_Write_D7(v)	COM_Write(TaskCom_D7,v,TaskCom_D7_status)
#define COM_Read_D7(v)	COM_Read(TaskCom_D7,v,TaskCom_D7_status)
#define COM_Send_D7(v)	COM_Send(TaskCom_D7,v,TaskCom_D7_status)
#define COM_Receive_D7(v)	COM_Receive(TaskCom_D7,v,TaskCom_D7_status)
#define COM_Write_D8(v)	COM_Write(TaskCom_D8,v,TaskCom_D8_status)
#define COM_Read_D8(v)	COM_Read(TaskCom_D8,v,TaskCom_D8_status)
#define COM_Send_D8(v)	COM_Send(TaskCom_D8,v,TaskCom_D8_status)
#define COM_Receive_D8(v)	COM_Receive(TaskCom_D8,v,TaskCom_D8_status)
#define COM_Write_D9(v)	COM_Write(TaskCom_D9,v,TaskCom_D9_status)
#define COM_Read_D9(v)	COM_Read(TaskCom_D9,v,TaskCom_D9_status)
#define COM_Send_D9(v)	COM_Send(TaskCom_D9,v,TaskCom_D9_status)
#define COM_Receive_D9(v)	COM_Receive(TaskCom_D9,v,TaskCom_D9_status)
#define COM_Write_D10(v)	COM_Write(TaskCom_D10,v,TaskCom_D10_status)
#define COM_Read_D10(v)	COM_Read(TaskCom_D10,v,TaskCom_D10_status)
#define COM_Send_D10(v)	COM_Send(TaskCom_D10,v,TaskCom_D10_status)
#define COM_Receive_D10(v)	COM_Receive(TaskCom_D10,v,TaskCom_D10_status)
#define COM_Write_D11(v)	COM_Write(TaskCom_D11,v,TaskCom_D11_status)
#define COM_Read_D11(v)	COM_Read(TaskCom_D11,v,TaskCom_D11_status)
#define COM_Send_D11(v)	COM_Send(TaskCom_D11,v,TaskCom_D11_status)
#define COM_Receive_D11(v)	COM_Receive(TaskCom_D11,v,TaskCom_D11_status)
#define COM_Write_D12(v)	COM_Write(TaskCom_D12,v,TaskCom_D12_status)
#define COM_Read_D12(v)	COM_Read(TaskCom_D12,v,TaskCom_D12_status)
#define COM_Send_D12(v)	COM_Send(TaskCom_D12,v,TaskCom_D12_status)
#define COM_Receive_D12(v)	COM_Receive(TaskCom_D12,v,TaskCom_D12_status)
#define COM_Write_D13(v)	COM_Write(TaskCom_D13,v,TaskCom_D13_status)
#define COM_Read_D13(v)	COM_Read(TaskCom_D13,v,TaskCom_D13_status)
#define COM_Send_D13(v)	COM_Send(TaskCom_D13,v,TaskCom_D13_status)
#define COM_Receive_D13(v)	COM_Receive(TaskCom_D13,v,TaskCom_D13_status)
#define COM_Write_D14(v)	COM_Write(TaskCom_D14,v,TaskCom_D14_status)
#define COM_Read_D14(v)	COM_Read(TaskCom_D14,v,TaskCom_D14_status)
#define COM_Send_D14(v)	COM_Send(TaskCom_D14,v,TaskCom_D14_status)
#define COM_Receive_D14(v)	COM_Receive(TaskCom_D14,v,TaskCom_D14_status)
#define COM_Write_D15(v)	COM_Write(TaskCom_D15,v,TaskCom_D15_status)
#define COM_Read_D15(v)	COM_Read(TaskCom_D15,v,TaskCom_D15_status)
#define COM_Send_D15(v)	COM_Send(TaskCom_D15,v,TaskCom_D15_status)
#define COM_Receive_D15(v)	COM_Receive(TaskCom_D15,v,TaskCom_D15_status)
#define COM_Write_D16(v)	COM_Write(TaskCom_D16,v,TaskCom_D16_status)
#define COM_Read_D16(v)	COM_Read(TaskCom_D16,v,TaskCom_D16_status)
#define COM_Send_D16(v)	COM_Send(TaskCom_D16,v,TaskCom_D16_status)
#define COM_Receive_D16(v)	COM_Receive(TaskCom_D16,v,TaskCom_D16_status)
#define COM_Write_D17(v)	COM_Write(TaskCom_D17,v,TaskCom_D17_status)
#define COM_Read_D17(v)	COM_Read(TaskCom_D17,v,TaskCom_D17_status)
#define COM_Send_D17(v)	COM_Send(TaskCom_D17,v,TaskCom_D17_status)
#define COM_Receive_D17(v)	COM_Receive(TaskCom_D17,v,TaskCom_D17_status)
#define COM_Write_D18(v)	COM_Write(TaskCom_D18,v,TaskCom_D18_status)
#define COM_Read_D18(v)	COM_Read(TaskCom_D18,v,TaskCom_D18_status)
#define COM_Send_D18(v)	COM_Send(TaskCom_D18,v,TaskCom_D18_status)
#define COM_Receive_D18(v)	COM_Receive(TaskCom_D18,v,TaskCom_D18_status)
#define COM_Write_D19(v)	COM_Write(TaskCom_D19,v,TaskCom_D19_status)
#define COM_Read_D19(v)	COM_Read(TaskCom_D19,v,TaskCom_D19_status)
#define COM_Send_D19(v)	COM_Send(TaskCom_D19,v,TaskCom_D19_status)
#define COM_Receive_D19(v)	COM_Receive(TaskCom_D19,v,TaskCom_D19_status)
#define COM_Write_D20(v)	COM_Write(TaskCom_D20,v,TaskCom_D20_status)
#define COM_Read_D20(v)	COM_Read(TaskCom_D20,v,TaskCom_D20_status)
#define COM_Send_D20(v)	COM_Send(TaskCom_D20,v,TaskCom_D20_status)
#define COM_Receive_D20(v)	COM_Receive(TaskCom_D20,v,TaskCom_D20_status)
#define COM_Write_D21(v)	COM_Write(TaskCom_D21,v,TaskCom_D21_status)
#define COM_Read_D21(v)	COM_Read(TaskCom_D21,v,TaskCom_D21_status)
#define COM_Send_D21(v)	COM_Send(TaskCom_D21,v,TaskCom_D21_status)
#define COM_Receive_D21(v)	COM_Receive(TaskCom_D21,v,TaskCom_D21_status)
#define COM_Write_D22(v)	COM_Write(TaskCom_D22,v,TaskCom_D22_status)
#define COM_Read_D22(v)	COM_Read(TaskCom_D22,v,TaskCom_D22_status)
#define COM_Send_D22(v)	COM_Send(TaskCom_D22,v,TaskCom_D22_status)
#define COM_Receive_D22(v)	COM_Receive(TaskCom_D22,v,TaskCom_D22_status)
#define COM_Write_D23(v)	COM_Write(TaskCom_D23,v,TaskCom_D23_status)
#define COM_Read_D23(v)	COM_Read(TaskCom_D23,v,TaskCom_D23_status)
#define COM_Send_D23(v)	COM_Send(TaskCom_D23,v,TaskCom_D23_status)
#define COM_Receive_D23(v)	COM_Receive(TaskCom_D23,v,TaskCom_D23_status)
#define COM_Write_D24(v)	COM_Write(TaskCom_D24,v,TaskCom_D24_status)
#define COM_Read_D24(v)	COM_Read(TaskCom_D24,v,TaskCom_D24_status)
#define COM_Send_D24(v)	COM_Send(TaskCom_D24,v,TaskCom_D24_status)
#define COM_Receive_D24(v)	COM_Receive(TaskCom_D24,v,TaskCom_D24_status)

/*
COM Buffer
*/
extern ValueIF TaskCom_D1;
extern Std_ReturnType TaskCom_D1_status;
extern JellyFishCommandIF TaskCom_D2;
extern Std_ReturnType TaskCom_D2_status;
extern JellyFishNavi TaskCom_D3;
extern Std_ReturnType TaskCom_D3_status;
extern ValueIF TaskCom_D4;
extern Std_ReturnType TaskCom_D4_status;
extern ValueIF TaskCom_D5;
extern Std_ReturnType TaskCom_D5_status;
extern ValueIF TaskCom_D6;
extern Std_ReturnType TaskCom_D6_status;
extern ValueIF TaskCom_D7;
extern Std_ReturnType TaskCom_D7_status;
extern ValueIF TaskCom_D8;
extern Std_ReturnType TaskCom_D8_status;
extern ValueIF TaskCom_D9;
extern Std_ReturnType TaskCom_D9_status;
extern ValueIF TaskCom_D10;
extern Std_ReturnType TaskCom_D10_status;
extern ValueIF TaskCom_D11;
extern Std_ReturnType TaskCom_D11_status;
extern ValueIF TaskCom_D12;
extern Std_ReturnType TaskCom_D12_status;
extern ValueIF TaskCom_D13;
extern Std_ReturnType TaskCom_D13_status;
extern ValueIF TaskCom_D14;
extern Std_ReturnType TaskCom_D14_status;
extern SwimControllerIF TaskCom_D15;
extern Std_ReturnType TaskCom_D15_status;
extern JellyFishNavi TaskCom_D16;
extern Std_ReturnType TaskCom_D16_status;
extern PidParamIF TaskCom_D17;
extern Std_ReturnType TaskCom_D17_status;
extern PidParamIF TaskCom_D18;
extern Std_ReturnType TaskCom_D18_status;
extern StabiIF TaskCom_D19;
extern Std_ReturnType TaskCom_D19_status;
extern ValueIF TaskCom_D20;
extern Std_ReturnType TaskCom_D20_status;
extern ValueIF TaskCom_D21;
extern Std_ReturnType TaskCom_D21_status;
extern PositionIF TaskCom_D22;
extern Std_ReturnType TaskCom_D22_status;
extern ValueIF TaskCom_D23;
extern Std_ReturnType TaskCom_D23_status;
extern JellyFishNaviIF TaskCom_D24;
extern Std_ReturnType TaskCom_D24_status;

#endif /* ComsarCOM_API_H */
