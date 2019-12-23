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
���ܣ�ΪDHCP���������ñ�Ҫ����Ϣ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulSrcIp��ԴIP��ַ��
	  ui64SrcMac��ԴMAC��ַ��
	  ulDelay�� ��ʱ���ã�
	  ulDisIp�� �����ip��ַ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  DHCP_IP_ILLLEGAL��ʾ������IP��ַ����
ע�⣺
*********************************************/
COM_EXPORT ULONG DhcpAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSrcIp, ULONG ulDisIp, 
								UINT uiLeaseIpCount, UINT uiLeaseipbit, UINT uiLeaseipstep, UINT uiOptSubNetMask, CString szOptDomainName, UINT uiOptDomainNameSer,
								UINT uiOptLeaseTime, UINT uiOptNetBiosNameSer, CString szOptNetBiosNodeType, CString szOptNetBiosScope, UINT uiOptRebindingTime,
								UINT uiOptRenewalTime, UINT uiOptRouter, UINT uiOptStaticRouterD, UINT uiOptStaticRouter, UINT* puiSessionId);

/********************************************
���ܣ�ɾ��ָ����DHCP Session
���룺ulSessionId�� DHCP Session ID���ɺ���DhcpAddSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  DHCP_ERROR_SESSION_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG DhcpRemoveSession(ULONG ulSessionId);

/********************************************
���ܣ�����ָ����DHCP Session
���룺ulSessionId�� DHCP Session ID���ɺ���DhcpAddSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  DHCP_ERROR_SESSION_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG DhcpConnectSession(ULONG ulSessionId);

/********************************************
���ܣ��Ͽ�����ָ����DHCP Session
���룺ulSessionId�� DHCP Session ID���ɺ���DhcpAddSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  DHCP_ERROR_SESSION_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG DhcpDisconnectSession(ULONG ulSessionId);

/********************************************
���ܣ���ȡDHCP�������Ĺ������
���룺ulSrcIp��ԴIP��ַ��
	  ui64SrcMac��ԴMAC��ַ��
	  ulDisIp�� �����ip��ַ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      DHCP_ERROR_NOT_EXIST_DATA��ʾ��ǰ���ص���Ϣ����Ҫ�õ�����Ϣ������
	  DHCP_ERROR_CONNECT_TIMEOUT��ʾ�ͻ��˱��ķ��ͳ�ʱ��
	  DHCP_ERROR_RESULT_ERROR��ʾ�������˷��ص���Ϣ�Ƿ���
ע�⣺
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
