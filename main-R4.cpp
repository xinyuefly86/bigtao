#include<afxtempl.h>
#include <atlstr.h>
#include "TeleApi.h"
#include<iostream>
#include<winsock2.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<ctime>
#include <thread>
//#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")

#define MYPORT 8888
#define MYIP "192.168.109.104"
#define MAX_CONNECT_NUM 10
#define NUM_THREADS 2
#define StreamRate_FPS_mode 0
#define StreamRate_bps_mode 1
#define StreamRate_FPS 2203368
#define StreamRate_radio 0.95

using namespace std;

bool send_flag;
SOCKET sClient; //客户端句柄
const int BUF_SIZE = 64;//64 
char receivebuf[BUF_SIZE];	//接收数据缓冲区
char sendBuf[BUF_SIZE];//返回给客户端的数据

ULONG error = 1;
ULONG ulChassisId = 0;
ULONG ulSlotId = 2;
ULONG ulPortId = 1;
ULONG ulPortId_v1 = 2;
UINT64 SendframeRate = 0;
UINT64 Sendbps = 0;
UINT64 RecvframeRate = 0;
UINT64 Recvbps = 0;
UINT64 Average_latency_ct = 0;
UINT64 Max_latency_ct = 0;
UINT64 Min_latency_ct = 0;


//线程1，接收客户端数据
void receive_from_client()
{
	int retVal;	//返回值
	while (true)
	{
		ZeroMemory(receivebuf, BUF_SIZE);//接收客户端数据
		retVal = recv(sClient, receivebuf, BUF_SIZE, 0);
		if (retVal == SOCKET_ERROR)
		{
			cout << "recv failed!" << endl;
			closesocket(sClient);	//关闭套接字		
			WSACleanup();			//释放套接字资源;
			//return -1;
		}
		else
			cout << "客户端发送的数据: " << receivebuf << endl;

		//接收客户端的控制命令，0代表停止发送，1代表发送
		if (receivebuf[0] == '0')
		{
			send_flag = false;
			TraStop(); //停止流发送
			StaStopPort(ulChassisId, ulSlotId, ulPortId); //停止指定端口的统计
		}
		else if (receivebuf[0] == '1')
		{
			send_flag = true;
			TraStart(); //开始流发送
			StaStartPort(ulChassisId, ulSlotId, ulPortId); //开始指定端口的统计
		}
	}
}


//线程2，每间隔1秒，向客户端发送数据
void send_to_client()
{
	while (true)
	{
		if (send_flag == true)
		{
			std::cout << "SendframeRate: " << SendframeRate << "  RecvframeRate: " << RecvframeRate << "  Sendbps:" << Sendbps << "  Recvbps:" << Recvbps << std::endl;
			std::cout << "Average cut through latency: " << Average_latency_ct << std::endl;
			cout << endl;
			_ui64toa_s(Recvbps, sendBuf, sizeof(sendBuf), 10);//数据类型转换
			int len = strlen(sendBuf);
			sendBuf[len] = '\n';
			sendBuf[len + 1] = '\0';
			send(sClient, sendBuf, strlen(sendBuf), 0);			
		}
		Sleep(1000);
	}
}

//注意添加.lib库
int main()
{
	/************************************    Server Socket Operation   **********************/ 

	//初始化WSA
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//创建套接字
	SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //TCP
	if (sServer == INVALID_SOCKET)
	{
		printf("socket error");
		return 0;
	}

	//绑定IP和端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(MYPORT);
	sin.sin_addr.S_un.S_addr = inet_addr(MYIP);
	if (bind(sServer, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error");
		return 0;
	}

	//开始监听
	if (listen(sServer, MAX_CONNECT_NUM) == SOCKET_ERROR)
	{
		printf("listen error");
		return 0;
	}

	//确认连接
	sockaddr_in remoteAddr; //连接的客户端IP地址
	int nAddrlen = sizeof(remoteAddr);
	printf("等待连接...\n");

	sClient = accept(sServer, (SOCKADDR*)&remoteAddr, &nAddrlen);
	if (sClient == INVALID_SOCKET)
	{
		printf("accept error");
		return 0;
	}
	else
		printf("连接成功\n");


	/**********************************  BigTao Regular Operation srart  *****************/

	//初始化所有模块，需要在程序的入口处调用该函数
	InitAllModules();  

	//添加一个型号为RES_CHASSIS_TYPE_220, 网口IP地址为192.168.108.181的机箱
	error = ResChassisAdd(RES_CHASSIS_TYPE_220, 0xC0A86CB5, &ulChassisId); 
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	//在机箱的第一个槽位添加一块RES_CARD_TYPE_V8002F的接口卡
	error = ResCardAdd(ulChassisId, ulSlotId, RES_CARD_TYPE_V8002F);
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Card Added \n" << std::endl;


	error = ResChassisConnect(ulChassisId); //和指定机箱建立TCP连接
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Chassis connected \n" << std::endl;


	error = ResPortReserve(ulChassisId, ulSlotId, ulPortId); //预约指定机箱第一槽位上的第一个端口
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	error = ResPortReserve(ulChassisId, ulSlotId, ulPortId_v1); //预约指定机箱第一槽位上的第二个端口
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Port Reserved \n" << std::endl;

	error = TraEnablePort(ulChassisId, ulSlotId, ulPortId, TRUE); //使能指定机箱第一槽位上第一个端口的流发送功能
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Stream send enabled \n" << std::endl;
	

	/**********************************   BigTao Setup Start   ****************************/


	/*********************************************************************************
		TraSetPortTransmitMode:指定机箱第一槽位上接口卡的第一端口的发送模式为连续发送，
		后面三个参数对连续发送无效。
		mode to be select :
		TRA_TX_MODE_CONTINUOUS表示连续发送，
		TRA_TX_MODE_SINGLE_BURST表示单次突发，
		TRA_TX_MODE_MULTI_BURST表示多次突发
		TRA_TX_MODE_TIME_BURST表示按时间发送
	*********************************************************************************/
	error = TraSetPortTransmitMode(ulChassisId, ulSlotId, ulPortId, TRA_TX_MODE_CONTINUOUS, 0, 0, 0); 
	
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Transmit Mode set \n" << std::endl;

	
	/*****************************************************************************
	  TraSetPortScheduleMode:设置指定机箱第一槽位上接口卡的第一端口的流调度方式
	  TRA_SCHEDULE_MODE_IFG（基于端口调速）
	  TRA_SCHEDULE_MODE_FPS（基于流调速）
	*****************************************************************************/
	error = TraSetPortScheduleMode(ulChassisId, ulSlotId, ulPortId, TRA_SCHEDULE_MODE_FPS);
	
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Schedule Mode set \n" << std::endl;


	/******************************************************************************
		TraAddStream:指定机箱第一槽位上第一端口下添加一个流s1, 该流为ipv4报文， 
		固定长度，长度为1000字节，
		源MAC地址为00-00-00-01-02-03-04； 目的MAC地址为00-00-01-02-03-05; 
		源ipv4地址为1.0.0.1，目的IPV4地址为1.0.0.2。
	**********************************************************************************/
	error = TraAddStream(ulChassisId, ulSlotId, ulPortId, "s1", TRA_PRO_TYPE_UDP, 1, TRA_LEN_TYPE_FIXED, 512, 512, FALSE, TRA_PAY_TYPE_CYCLE, 0x5a,
		0, 0x000001020304, 0x000001020305, 0x01000000, 0x01000002, NULL, NULL); 

	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = TraEnableStream("s1", TRUE); //使能s1流
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	/******************************************************************************
		TraSetStreamRate:设置流的发送模式和速率
		StreamRate_bps_mode match StreamRate_radio
		StreamRate_FPS_mode match StreamRate_FPS
	**********************************************************************************/
	error = TraSetStreamRate("s1", StreamRate_bps_mode, StreamRate_radio);//设置流的发送模式和速率
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = StaSelectStream(ulChassisId, ulSlotId, ulPortId, "s1"); //把流s1挂在指定机箱第一槽位下第一端口下进行统计
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = StaSelectStream(ulChassisId, ulSlotId, ulPortId_v1, "s1"); //把流s1挂在指定机箱第一槽位下第二端口下进行统计
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	std::cout << "StaSelect s1 Stream success" << std::endl;

	error = StaStartPort(ulChassisId, ulSlotId, ulPortId); //开始指定机箱第一槽位上接口卡的第一端口的统计
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	printf("1\n");
	error = StaStartPort(ulChassisId, ulSlotId, ulPortId_v1); //开始指定机箱第一槽位上接口卡的第二端口的统计
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	EnableGUIMonitor(ulChassisId);
	//TraStart();//开始流发送
	//TraStartPort(ulChassisId, ulSlotId, ulPortId);
	Sleep(5000);


	/********************  open two thread   **************************/
	thread t1(receive_from_client);
	thread t2(send_to_client);

	while (true)
	{	
		//获取在指定机箱第1槽位上接口卡的第1端口下进行统计的流s1的 发送流帧数统计数据
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId, "s1", STA_MEA_TX_FPS, &SendframeRate);
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId, "s1", STA_MEA_TX_bps, &Sendbps);
		if (error != 0) {
			std::cout << "Error Code: " << error << std::endl;
			exit(error);
		}

		//获取指定机箱第一槽位上接口卡的第一端口的发送的流的帧数统计，结果在frameRate中
		error = StaGetPortData(ulChassisId, ulSlotId, ulPortId_v1, STA_MEA_RX_FPS, &RecvframeRate);
		error = StaGetPortData(ulChassisId, ulSlotId, ulPortId_v1, STA_MEA_RX_bps, &Recvbps);
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId_v1, "s1", STA_MEA_MAX_LATENCY_C, &Max_latency_ct);
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId_v1, "s1", STA_MEA_AVG_LATENCY_C, &Average_latency_ct);
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId_v1, "s1", STA_MEA_MIN_LATENCY_C, &Min_latency_ct);
		if (error != 0) {

			std::cout << "Error Code: " << error << std::endl;
			exit(error);
		}
		Sleep(1000);//1000 means 1 second
		
	}

	// remember to release the resources
	TraRemoveStream("s1"); //删除指定的流
	ResPortRelease(ulChassisId, ulSlotId, ulPortId); //释放指定的接口卡的端口
	DeleteAllModules();//释放所有资源
	return 0;
}
