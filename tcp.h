#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define TCP_ERROR_CONNECT_FAIL					(1000)
#define TCP_ERROR_SOCKET_ID						(1001)
#define TCP_ERROR_SOCKET_CLOSED					(1002)

#ifdef __FOR_CSHARP
extern "C" {
#endif


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
/********************************************
功能：建立TCP连接
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulDstIp：目的IP地址；
	  ulSrcIp：源IP地址；
	  usDstPort：目的端口号；
	  usSrcPort：源端口号；
输出：pulSockId：Socket ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  FD_ERROR_TIMEOUT表示连接超时，
	  TCP_ERROR_CONNECT_FAIL表示连接失败。
注意：
*********************************************/
COM_EXPORT ULONG TcpConnect(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulDstIp, ULONG ulSrcIp, USHORT usDstPort, USHORT usSrcPort, ULONG* pulSockId);

/********************************************
功能：关闭TCP连接
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulSockId：Socket ID， 由TcpConnect函数输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  TCP_ERROR_SOCKET_ID表示输入的ulSockId不是有效的Socket连接标识符。
注意：
*********************************************/
COM_EXPORT ULONG TcpClose(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId);

/********************************************
功能：发送TCP数据
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulSockId：Socket ID，由TcpConnect函数输出；
	  pucData：发送的数据
	  usLen：发送的数据长度
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  TCP_ERROR_SOCKET_ID表示输入的ulSockId不是有效的Socket连接标识符。
注意：
*********************************************/
COM_EXPORT ULONG TcpSend(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId, const UCHAR* pucData, USHORT usLen);

/********************************************
功能：接收TCP数据
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulSockId：Socket ID，由TcpConnect函数输出；
	  usRecvLen：需要接收的数据长度
	  pucData：接收Buffer
输出：pucData：接收到的数据内容的指针，
	  pusLen：接收到的数据内容的真实长度的指针
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  TCP_ERROR_SOCKET_ID表示输入的ulSockId不是有效的Socket连接标识符，
	  TCP_ERROR_SOCKET_CLOSED表示TCP连接已经被关闭。
注意：pusLen返回值小于等于usRecvLen，若没有数据，函数将一直阻塞直至接收到数据或TCP连接关闭
*********************************************/
COM_EXPORT ULONG TcpRecv(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId, USHORT usRecvLen, UCHAR* pucData, USHORT* pusLen);
#endif


#ifdef __FOR_CSHARP
}
#endif