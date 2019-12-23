#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define TELNET_ERROR_CONNECT_FAIL				(900)
#define TELNET_ERROR_TCP_FAIL                   (901)
#define TELNET_ERROR_TELNET_ID                  (902)
#define TELNET_ERROR_TELNET_SOCKET_CLOSED       (903)
#define TELNET_ERROR_TELNET_TIME_OUT            (904)

#ifdef __FOR_CSHARP
extern "C" {
#endif

#ifndef __SERVER
/********************************************
功能：建立telnet 连接
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulTimeout: 函数超时时间，单位为ms
	   
输出：telnetId:telnet 连接 ID指针；
	  bConn: 连接是否成功标志，TRUE 表示连接成功，FALSE 表示连接未成功
	  iRetType:命令返回类型
	  pcRev:  命令返回结果
	  piRevLen: pcRev 字符串的长度
	  
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  FD_ERROR_TIMEOUT表示连接超时，
	  TELNET_ERROR_CONNECT_FAIL表示连接失败。
注意：
*********************************************/
COM_EXPORT ULONG TelnetConnect(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG dstIp,ULONG *telnetId,ULONG ulTimeout,char *pcRev,int *piRevLen);
/********************************************
功能：关闭telnet 连接
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulSockId：Socket ID， 由TelnetConnect函数输出；
输出：无

返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约。
注意：
*********************************************/
COM_EXPORT ULONG TelnetClose(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId);

/********************************************
功能：发送telnet 命令 或者用户名，密码
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  telnetId：telnet 连接ID，由TelnetConnect函数输出；
	  ulTimeout:函数超时时间 单位ms
	  pcSend：发送的数据，以0结尾的字符串，每条命令请字符串结尾添加\r\n
输出：
	  bConn: 连接是否成功标志，TRUE 表示连接成功，FALSE 表示连接未成功
	  iRetType:命令返回类型
	  pcRev:  命令返回结果
	  piRevLen: pcRev 字符串的长度
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约。
注意：
*********************************************/
 COM_EXPORT ULONG TelnetSend(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,BOOL *bConn,int *iRetType,const char *pcSend,char *pcRev,int *piRevLen);

/********************************************
功能：发送telnet 命令 或者用户名，密码
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  telnetId：telnet 连接ID，由TelnetConnect函数输出；
	  ulTimeout:函数超时时间 单位ms
	  pcSend：发送的数据，以0结尾的字符串
输出：
	  bConn: 连接是否成功标志，TRUE 表示连接成功，FALSE 表示连接未成功
	  iRetType:命令返回类型
	  pcRev:  命令返回结果
	  piRevLen: pcRev 字符串的长度
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约。
注意：
*********************************************/
 COM_EXPORT ULONG TelnetSendLine(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,const char *pcSend,int iSendLen,char *pcRev,int *piRevLen);

/********************************************
功能：设置Telenet接收数据的结束字符
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  telnetId：telnet 连接ID，由TelnetConnect函数输出；
	  ulTimeout:函数超时时间 单位ms
	  cEndAscii：结束字符
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约。
注意：每次TelnetConnect成功之后需要重新设置。
*********************************************/
 COM_EXPORT ULONG TelnetSetEndAscii(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,char cEndAscii);

#endif
#ifdef __FOR_CSHARP
}
#endif