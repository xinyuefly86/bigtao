#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define DHCP_STATE_INIT (800)
#define DHCP_IP_ILLEGAL	(801)
#define DHCP_ERROR_EXIST_SAME_IP_ADDR	(802)
#define DHCP_ERROR_CONNECT_TIMEOUT (803)
#define DHCP_ERROR_RESULT_ERROR (804)
#define DHCP_ERROR_NOT_EXIST_DATA (805)
#define DHCP_ERROR_SESSION_ID			(806)
#define DHCP_ERROR_LEASETIME_OUTRANGE	(807)
#define DHCP_ERROR_MSGTIME_OUTRANGE		(808)
#define DHCP_ERROR_OPTION_NETBIOSNODETYPE	(809)


#ifdef __FOR_CSHARP
extern "C" {
#endif

#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
	
typedef CList<UCHAR*, UCHAR*> CDhcpClientIpMacList;
typedef CMap<ULONG,ULONG,CDhcpClientIpMacList*, CDhcpClientIpMacList*> CDhcpClientLeaseIpMacMap;
extern CDhcpClientLeaseIpMacMap g_CDhcpClientLeaseIpMacMap;

typedef struct tag_PACKET
{
	UCHAR*	pucPacket;
	ULONG	ulLen;
} PACKET_S;

/*typedef CList <ULONG ,ULONG> IP_LIST;

IP_LIST* ul_IPList;*/

typedef struct
{
	ULONG srcIp;
	UINT64 srcMac;
	ULONG disIp;
	USHORT state;
}DHCP_RETURN;

// CMap<ULONG, ULONG, ULONG, ULONG> g_mapDhcpSssnId2Sssn;
/********************************************
功能：为DHCP服务器配置必要的信息
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulSrcIp：源IP地址；
	  ui64SrcMac：源MAC地址；
	  ulDelay： 超时设置；
	  ulDisIp： 分配的ip地址；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  DHCP_IP_ILLLEGAL表示给定的IP地址错误；
注意：
*********************************************/
COM_EXPORT ULONG DhcpAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSrcIp, ULONG ulDisIp, 
								UINT uiLeaseIpCount, UINT uiLeaseipbit, UINT uiLeaseipstep, UINT uiOptSubNetMask, CString szOptDomainName, UINT uiOptDomainNameSer,
								UINT uiOptLeaseTime, UINT uiOptNetBiosNameSer, CString szOptNetBiosNodeType, CString szOptNetBiosScope, UINT uiOptRebindingTime,
								UINT uiOptRenewalTime, UINT uiOptRouter, UINT uiOptStaticRouterD, UINT uiOptStaticRouter, UINT* puiSessionId);

/********************************************
功能：删除指定的DHCP Session
输入：ulSessionId： DHCP Session ID，由函数DhcpAddSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  DHCP_ERROR_SESSION_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG DhcpRemoveSession(ULONG ulSessionId);

/********************************************
功能：连接指定的DHCP Session
输入：ulSessionId： DHCP Session ID，由函数DhcpAddSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  DHCP_ERROR_SESSION_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG DhcpConnectSession(ULONG ulSessionId);

/********************************************
功能：断开连接指定的DHCP Session
输入：ulSessionId： DHCP Session ID，由函数DhcpAddSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  DHCP_ERROR_SESSION_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG DhcpDisconnectSession(ULONG ulSessionId);

/********************************************
功能：获取DHCP服务器的工作结果
输入：ulSrcIp：源IP地址；
	  ui64SrcMac：源MAC地址；
	  ulDisIp： 分配的ip地址；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      DHCP_ERROR_NOT_EXIST_DATA表示当前返回的信息与需要得到的信息不符，
	  DHCP_ERROR_CONNECT_TIMEOUT表示客户端报文发送超时，
	  DHCP_ERROR_RESULT_ERROR表示服务器端返回的信息非法；
注意：
*********************************************/
COM_EXPORT ULONG DhcpGetResult(ULONG ulSrcIp, UINT64 ui64SrcMac, ULONG ulDisIp);

COM_EXPORT ULONG Dhcpv6ReceiveStart(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

COM_EXPORT ULONG Dhcpv6ReceiveStop(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

COM_EXPORT ULONG Dhcpv6GetPacketCount(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG* pulPacketCount);

COM_EXPORT ULONG Dhcpv6GetPacket(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PACKET_S** ppaPacket, ULONG* pulPacketCount);

COM_EXPORT ULONG Dhcpv6DeletePacket(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

COM_EXPORT ULONG DhcpClientGetLeaseIp(ULONG* pLeaseIp, UCHAR* pMac, ULONG* pulMacIpCount, ULONG ulSssnId);

#endif //__FW
#endif //__SERVER


#ifdef __FOR_CSHARP
}
#endif
