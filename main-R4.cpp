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
SOCKET sClient; //�ͻ��˾��
const int BUF_SIZE = 64;//64 
char receivebuf[BUF_SIZE];	//�������ݻ�����
char sendBuf[BUF_SIZE];//���ظ��ͻ��˵�����

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


//�߳�1�����տͻ�������
void receive_from_client()
{
	int retVal;	//����ֵ
	while (true)
	{
		ZeroMemory(receivebuf, BUF_SIZE);//���տͻ�������
		retVal = recv(sClient, receivebuf, BUF_SIZE, 0);
		if (retVal == SOCKET_ERROR)
		{
			cout << "recv failed!" << endl;
			closesocket(sClient);	//�ر��׽���		
			WSACleanup();			//�ͷ��׽�����Դ;
			//return -1;
		}
		else
			cout << "�ͻ��˷��͵�����: " << receivebuf << endl;

		//���տͻ��˵Ŀ������0����ֹͣ���ͣ�1������
		if (receivebuf[0] == '0')
		{
			send_flag = false;
			TraStop(); //ֹͣ������
			StaStopPort(ulChassisId, ulSlotId, ulPortId); //ָֹͣ���˿ڵ�ͳ��
		}
		else if (receivebuf[0] == '1')
		{
			send_flag = true;
			TraStart(); //��ʼ������
			StaStartPort(ulChassisId, ulSlotId, ulPortId); //��ʼָ���˿ڵ�ͳ��
		}
	}
}


//�߳�2��ÿ���1�룬��ͻ��˷�������
void send_to_client()
{
	while (true)
	{
		if (send_flag == true)
		{
			std::cout << "SendframeRate: " << SendframeRate << "  RecvframeRate: " << RecvframeRate << "  Sendbps:" << Sendbps << "  Recvbps:" << Recvbps << std::endl;
			std::cout << "Average cut through latency: " << Average_latency_ct << std::endl;
			cout << endl;
			_ui64toa_s(Recvbps, sendBuf, sizeof(sendBuf), 10);//��������ת��
			int len = strlen(sendBuf);
			sendBuf[len] = '\n';
			sendBuf[len + 1] = '\0';
			send(sClient, sendBuf, strlen(sendBuf), 0);			
		}
		Sleep(1000);
	}
}

//ע�����.lib��
int main()
{
	/************************************    Server Socket Operation   **********************/ 

	//��ʼ��WSA
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//�����׽���
	SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //TCP
	if (sServer == INVALID_SOCKET)
	{
		printf("socket error");
		return 0;
	}

	//��IP�Ͷ˿�
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(MYPORT);
	sin.sin_addr.S_un.S_addr = inet_addr(MYIP);
	if (bind(sServer, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error");
		return 0;
	}

	//��ʼ����
	if (listen(sServer, MAX_CONNECT_NUM) == SOCKET_ERROR)
	{
		printf("listen error");
		return 0;
	}

	//ȷ������
	sockaddr_in remoteAddr; //���ӵĿͻ���IP��ַ
	int nAddrlen = sizeof(remoteAddr);
	printf("�ȴ�����...\n");

	sClient = accept(sServer, (SOCKADDR*)&remoteAddr, &nAddrlen);
	if (sClient == INVALID_SOCKET)
	{
		printf("accept error");
		return 0;
	}
	else
		printf("���ӳɹ�\n");


	/**********************************  BigTao Regular Operation srart  *****************/

	//��ʼ������ģ�飬��Ҫ�ڳ������ڴ����øú���
	InitAllModules();  

	//���һ���ͺ�ΪRES_CHASSIS_TYPE_220, ����IP��ַΪ192.168.108.181�Ļ���
	error = ResChassisAdd(RES_CHASSIS_TYPE_220, 0xC0A86CB5, &ulChassisId); 
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	//�ڻ���ĵ�һ����λ���һ��RES_CARD_TYPE_V8002F�Ľӿڿ�
	error = ResCardAdd(ulChassisId, ulSlotId, RES_CARD_TYPE_V8002F);
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Card Added \n" << std::endl;


	error = ResChassisConnect(ulChassisId); //��ָ�����佨��TCP����
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Chassis connected \n" << std::endl;


	error = ResPortReserve(ulChassisId, ulSlotId, ulPortId); //ԤԼָ�������һ��λ�ϵĵ�һ���˿�
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	error = ResPortReserve(ulChassisId, ulSlotId, ulPortId_v1); //ԤԼָ�������һ��λ�ϵĵڶ����˿�
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Port Reserved \n" << std::endl;

	error = TraEnablePort(ulChassisId, ulSlotId, ulPortId, TRUE); //ʹ��ָ�������һ��λ�ϵ�һ���˿ڵ������͹���
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Stream send enabled \n" << std::endl;
	

	/**********************************   BigTao Setup Start   ****************************/


	/*********************************************************************************
		TraSetPortTransmitMode:ָ�������һ��λ�Ͻӿڿ��ĵ�һ�˿ڵķ���ģʽΪ�������ͣ�
		������������������������Ч��
		mode to be select :
		TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
		TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	*********************************************************************************/
	error = TraSetPortTransmitMode(ulChassisId, ulSlotId, ulPortId, TRA_TX_MODE_CONTINUOUS, 0, 0, 0); 
	
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Transmit Mode set \n" << std::endl;

	
	/*****************************************************************************
	  TraSetPortScheduleMode:����ָ�������һ��λ�Ͻӿڿ��ĵ�һ�˿ڵ������ȷ�ʽ
	  TRA_SCHEDULE_MODE_IFG�����ڶ˿ڵ��٣�
	  TRA_SCHEDULE_MODE_FPS�����������٣�
	*****************************************************************************/
	error = TraSetPortScheduleMode(ulChassisId, ulSlotId, ulPortId, TRA_SCHEDULE_MODE_FPS);
	
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	std::cout << "Schedule Mode set \n" << std::endl;


	/******************************************************************************
		TraAddStream:ָ�������һ��λ�ϵ�һ�˿������һ����s1, ����Ϊipv4���ģ� 
		�̶����ȣ�����Ϊ1000�ֽڣ�
		ԴMAC��ַΪ00-00-00-01-02-03-04�� Ŀ��MAC��ַΪ00-00-01-02-03-05; 
		Դipv4��ַΪ1.0.0.1��Ŀ��IPV4��ַΪ1.0.0.2��
	**********************************************************************************/
	error = TraAddStream(ulChassisId, ulSlotId, ulPortId, "s1", TRA_PRO_TYPE_UDP, 1, TRA_LEN_TYPE_FIXED, 512, 512, FALSE, TRA_PAY_TYPE_CYCLE, 0x5a,
		0, 0x000001020304, 0x000001020305, 0x01000000, 0x01000002, NULL, NULL); 

	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = TraEnableStream("s1", TRUE); //ʹ��s1��
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	/******************************************************************************
		TraSetStreamRate:�������ķ���ģʽ������
		StreamRate_bps_mode match StreamRate_radio
		StreamRate_FPS_mode match StreamRate_FPS
	**********************************************************************************/
	error = TraSetStreamRate("s1", StreamRate_bps_mode, StreamRate_radio);//�������ķ���ģʽ������
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = StaSelectStream(ulChassisId, ulSlotId, ulPortId, "s1"); //����s1����ָ�������һ��λ�µ�һ�˿��½���ͳ��
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	error = StaSelectStream(ulChassisId, ulSlotId, ulPortId_v1, "s1"); //����s1����ָ�������һ��λ�µڶ��˿��½���ͳ��
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	std::cout << "StaSelect s1 Stream success" << std::endl;

	error = StaStartPort(ulChassisId, ulSlotId, ulPortId); //��ʼָ�������һ��λ�Ͻӿڿ��ĵ�һ�˿ڵ�ͳ��
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}
	printf("1\n");
	error = StaStartPort(ulChassisId, ulSlotId, ulPortId_v1); //��ʼָ�������һ��λ�Ͻӿڿ��ĵڶ��˿ڵ�ͳ��
	if (error != 0) {
		std::cout << "Error Code: " << error << std::endl;
		exit(error);
	}

	EnableGUIMonitor(ulChassisId);
	//TraStart();//��ʼ������
	//TraStartPort(ulChassisId, ulSlotId, ulPortId);
	Sleep(5000);


	/********************  open two thread   **************************/
	thread t1(receive_from_client);
	thread t2(send_to_client);

	while (true)
	{	
		//��ȡ��ָ�������1��λ�Ͻӿڿ��ĵ�1�˿��½���ͳ�Ƶ���s1�� ������֡��ͳ������
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId, "s1", STA_MEA_TX_FPS, &SendframeRate);
		error = StaGetStreamData(ulChassisId, ulSlotId, ulPortId, "s1", STA_MEA_TX_bps, &Sendbps);
		if (error != 0) {
			std::cout << "Error Code: " << error << std::endl;
			exit(error);
		}

		//��ȡָ�������һ��λ�Ͻӿڿ��ĵ�һ�˿ڵķ��͵�����֡��ͳ�ƣ������frameRate��
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
	TraRemoveStream("s1"); //ɾ��ָ������
	ResPortRelease(ulChassisId, ulSlotId, ulPortId); //�ͷ�ָ���Ľӿڿ��Ķ˿�
	DeleteAllModules();//�ͷ�������Դ
	return 0;
}
