#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PPPOE_ERROR_EXCEED_MAX_SESSION_COUNT	(700)
#define PPPOE_ERROR_EXIST_SAME_MAC_ADDR			(701)
#define PPPOE_ERROR_SSSN_ID						(702)
#define PPPOE_ERROR_USER_NAME_EMPTY				(703)
#define PPPOE_ERROR_PASS_WORD_EMPTY				(704)
#define PPPOE_ERROR_USER_NAME_LEN				(705)
#define PPPOE_ERROR_PASS_WORD_LEN				(706)
#define PPPOE_ERROR_SSSN_DISCONNECTING			(707)

enum
{
	PPPOE_STATE_DISCONNECTED = 0,
	PPPOE_STATE_CONNECTING = 1,
	PPPOE_STATE_DISCONNECTING = 2,
	PPPOE_STATE_CONNECTED = 8,
};

enum
{
	PPPOE_AUTH_CHAP = 0,
	PPPOE_AUTH_PAP = 1,
};

#ifdef __FOR_CSHARP
extern "C" {
#endif


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
/********************************************
功能：添加PPPoE Session
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ucAuthType：认证类型，包括PPPOE_AUTH_CHAP、PPPOE_AUTH_PAP；
	  szUserName：认证用户名，最大长度为20，不能为空；
	  szPassword：认证密码，最大长度为20，不能为空；
	  bStaticIp：是否使用静态分配的IP地址；
	  ulSrcIp：静态分配的IP地址，bStaticIp为TRUE时有效；
	  ui64SrcMac：Session所使用的唯一MAC地址；
	  bEnableEcho：是否使能Session的EchoRequest功能；
	  ulEchoFrequency：Session的EchoRequest频率，以秒为单位，bEnableEcho为TRUE时有效；
	  ulEchoAttempts：Session的EchoRequest失败时重试的次数，bEnableEcho为TRUE时有效；
输出：pulSessionId：Session ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  PPPOE_ERROR_USER_NAME_EMPTY表示输入的szUserName为空，
	  PPPOE_ERROR_PASS_WORD_EMPTY表示输入的szPassword为空，
	  PPPOE_ERROR_USER_NAME_LEN表示输入的szUserName长度为0或大于20，
	  PPPOE_ERROR_PASS_WORD_LEN表示输入的szPassword长度为0或大于20，
	  PPPOE_ERROR_EXIST_SAME_MAC_ADDR表示当前端口下已存在MAC地址与ui64SrcMac相同的Session
	  PPPOE_ERROR_EXCEED_MAX_SESSION_COUNT表示session数目已经超出指定端口所允许的最大值，单端口支持2000个Session。
注意：
*********************************************/
COM_EXPORT ULONG PppoeAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucAuthType, const char* szUserName, const char* szPassword
	, BOOL bStaticIp, ULONG ulSrcIp, UINT64 ui64SrcMac, BOOL bEnableEcho, ULONG ulEchoFrequency, ULONG ulEchoAttempts, ULONG *pulSessionId);

/********************************************
功能：删除指定的PPPoE Session
输入：ulSssnId： IGMP Session ID，由函数PppoeAddSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示正在进行协议仿真，
	  PPPOE_ERROR_SSSN_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG PppoeRemoveSession(ULONG ulSssnId);

/********************************************
功能：连接指定的PPPoE Session
输入：ulSssnId： PPPoE Session ID，由函数PppoeAddSession输出	；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示未开启协议仿真，
	  PPPOE_ERROR_SSSN_ID表示输入的ulSessionId错误。
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未建立TCP连接
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约
	  PPPOE_ERROR_SSSN_DISCONNECTING表示Session正在断开连接
	  FD_ERROR表示与服务器通信失败
注意：
*********************************************/
COM_EXPORT ULONG PppoeConnectSession(ULONG ulSssnId);

/********************************************
功能：断开指定的PPPoE Session
输入：ulSssnId： PPPoE Session ID，由函数PppoeAddSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示未开启协议仿真，
	  PPPOE_ERROR_SSSN_ID表示输入的ulSessionId错误。
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未建立TCP连接
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约
	  FD_ERROR表示与服务器通信失败
注意：
*********************************************/
COM_EXPORT ULONG PppoeDisconnectSession(ULONG ulSssnId);

/********************************************
功能：获取指定的PPPoE Session的连接状态及相关信息
输入：ulSssnId： PPPoE Session ID，由函数PppoeAddSession输出；
输出：pucSssnState：Session当前的连接状态，包括PPPOE_STATE_DISCONNECTED、PPPOE_STATE_CONNECTING、PPPOE_STATE_DISCONNECTING、PPPOE_STATE_CONNECTED；
	  pusSssnId：PPPoE会话阶段的Session ID，可选；
	  pulSrcIp：Session的源IP地址，可选；
	  pulDstIp：PPPoE服务器的IP地址，可选；
	  pui64DstMac：PPPoE服务器的MAC地址，可选；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示未开启协议仿真，
	  PPPOE_ERROR_SSSN_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG PppoeGetSessionState(ULONG ulSssnId, UCHAR* pucSssnState, USHORT* pusSssnId
									  , ULONG* pulSrcIp, ULONG* pulDstIp, UINT64* pui64DstMac);
#endif


#ifdef __FOR_CSHARP
}
#endif