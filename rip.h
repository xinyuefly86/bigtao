#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define RIP_ERROR_EXCEED_MAX_SESSION_COUNT		(600)
#define RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT	(601)
#define RIP_ERROR_SESSION_ID					(602)
#define RIP_ERROR_ROUTE_POOL_ID					(603)
#define RIP_ERROR_ROUTE_POOL_FLAPPING			(604)
#define RIP_ERROR_ROUTE_POOL_UNENABLED			(605)


typedef struct tag_IPV4_ROUTE_POOL
{
	ULONG  ulRoute;//IPv4��ʼ·��
	ULONG  ulRouteCount;//IPv4·����Ŀ
	UCHAR  ucRouteModBit;//IPv4·��Ҫ�����bitλ��ȡֵ��ΧΪ1--32
	UCHAR  ucRouteModStep;//IPv4·������Ĳ�����ȡֵ��ΧΪ1--255

	UCHAR  ucPrefixLen;//prefix length��ȡֵ��ΧΪ0--32
	USHORT usRouteTag;//route tag
	ULONG  ulMetric;//metric
	ULONG  ulNextHop;//next hop
} IPV4_ROUTE_POOL_S;


typedef struct tag_IPV6_ROUTE_POOL
{
	UCHAR  ucaRoute[16];//IPv6��ʼ·��
	ULONG  ulRouteCount;//IPv6·����Ŀ
	UCHAR  ucRouteModBit;//IPv6·��Ҫ�����bitλ��ȡֵ��ΧΪ1--128
	UCHAR  ucRouteModStep;//IPv6·������Ĳ�����ȡֵ��ΧΪ1--255

	UCHAR  ucPrefixLen;//prefix length��ȡֵ��ΧΪ0--128
	USHORT usRouteTag;//route tag
	UCHAR  ucMetric;//metric
	UCHAR  ucaNextHop[16];//next hop
} IPV6_ROUTE_POOL_S;


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
���ܣ����RIPv2 Session
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Address�����Զ˿ڵ�IPv4�ӿڵ�ַ��
	  usUpdateInterval��·�ɸ��¼��������Ϊ��λ��ȡֵ��ΧΪ1--65535��
	  ucRoutePerPDU��ÿ��Update PDU�а���·�ɵ���Ŀ��ȡֵ��ΧΪ1--25��
�����pulSessionId��Session IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV4_ADDRESS��ʾ�����ulPortIPv4Address����ָ���˿ڵĽӿ�IPv4��ַ��
	  RIP_ERROR_EXCEED_MAX_SESSION_COUNT��ʾsession��Ŀ�Ѿ�������������ֵ��
ע�⣺
*********************************************/
COM_EXPORT ULONG RipAddV2Session(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulPortIPv4Address, USHORT usUpdateInterval, UCHAR ucRoutePerPDU, 
	ULONG *pulSessionId);


/********************************************
���ܣ����RIPng Session
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Address�����Զ˿ڵ�IPv6�ӿ�Link Local��ַָ�룻
	  usUpdateInterval��·�ɸ��¼��������Ϊ��λ��ȡֵ��ΧΪ1--65535��
	  ucRoutePerPDU��ÿ��Update PDU�а���·�ɵ���Ŀ��ȡֵ��ΧΪ1--4000��������MTU���ܰ�����·������ȡ��·������
�����pulSessionId��Session IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV6_LINK_LOCAL_ADDRESS��ʾ�����pucPortIPv6Address����ָ���˿ڵĽӿ�IPv6 Link Local��ַ��
	  RIP_ERROR_EXCEED_MAX_SESSION_COUNT��ʾsession��Ŀ�Ѿ�������������ֵ��
ע�⣺
*********************************************/
COM_EXPORT ULONG RipAddNgSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Address, USHORT usUpdateInterval, USHORT usRoutePerPDU, 
	ULONG *pulSessionId);


/********************************************
���ܣ�ɾ��ָ����RIP Session
���룺ulSessionId��RIP Session ID���ɺ���RipAddV2Session��RipAddNgSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  RIP_ERROR_SESSION_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG RipRemoveSession(ULONG ulSessionId);


/********************************************
���ܣ���ָ����RIPv2 Session�����IPv4·�ɳ�
���룺ulSessionId�� RIPv2 Session ID���ɺ���RipAddV2Session�����
      pRoutePool��IPv4·�ɳ�ָ�룻
�����pulRoutePoolId��IPv4·�ɳ�IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  RIP_ERROR_SESSION_ID��ʾ�����ulSessionId����
	  RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT��ʾ·�ɳ����Ѿ�����ָ���˿�����������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾ����·�ɳ�����255.255.255.255��
ע�⣺
*********************************************/
COM_EXPORT ULONG RipAddIpv4RoutePool(ULONG ulSessionId, IPV4_ROUTE_POOL_S *pRoutePool, ULONG *pulRoutePoolId);


/********************************************
���ܣ���ָ����RIPng Session�����IPv6·�ɳ�
���룺ulSessionId�� RIPng Session ID���ɺ���RipAddNgSession�����
      pRoutePool��IPv6·�ɳ�ָ�룻
�����pulRoutePoolId��IPv6·�ɳ�IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  RIP_ERROR_SESSION_ID��ʾ�����ulSessionId����
	  RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT��ʾ·�ɳ����Ѿ�����ָ���˿�����������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS��ʾ����IPv6·�ɳ�������������ֵ��
ע�⣺
*********************************************/
COM_EXPORT ULONG RipAddIpv6RoutePool(ULONG ulSessionId, IPV6_ROUTE_POOL_S *pRoutePool, ULONG *pulRoutePoolId);


/********************************************
���ܣ�ɾ��ָ����·�ɳ�
���룺ulRoutePoolId�� ·�ɳ�ID���ɺ���RipAddIpv4RoutePool��RipAddIpv6RoutePool �����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  RIP_ERROR_ROUTE_POOL_ID��ʾ�����ulRoutePoolId����
ע�⣺
*********************************************/
COM_EXPORT ULONG RipRemoveRoutePool(ULONG ulRoutePoolId);


/********************************************
���ܣ�ʹ�ܻ�ʹ��ָ����·�ɳ�
���룺ulRoutePoolId�� ·�ɳ�ID���ɺ���RipAddIpv4RoutePool��RipAddIpv6RoutePool �����
      bEnable���Ƿ�ʹ��ָ����·�ɳأ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  RIP_ERROR_ROUTE_POOL_ID��ʾ�����ulRoutePoolId����
	  RIP_ERROR_ROUTE_POOL_FLAPPING��ʾָ��·�ɳ����ڽ���·���񵴡�
ע�⣺�����øú�����Ĭ��Ϊʹ��·�ɳء�
*********************************************/
COM_EXPORT ULONG RipEnableRoutePool(ULONG ulRoutePoolId, BOOL bEnable);


/********************************************
���ܣ�����ָ���˿ڷ���RIP response PDU������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPPS��   ����RIP response PDU�����ʣ���λΪPackets/Sec��ȡֵ��ΧΪ1--1000��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG RipSetPduTransmitRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPPS);


/********************************************
���ܣ�����ָ����·�ɳص��񵴲���
���룺ulRoutePoolId�� ·�ɳ�ID���ɺ���RipAddIpv4RoutePool��RipAddIpv6RoutePool �����
      usA2WDelay����·��ͨ����ϵ���ʼ·�ɳ�����ʱ����������Ϊ��λ��ȡֵ��ΧΪ1--65535��
      usW2ADelay����·�ɳ�����ϵ���ʼ·��ͨ���ʱ����������Ϊ��λ��ȡֵ��ΧΪ1--65535��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  RIP_ERROR_ROUTE_POOL_ID��ʾ�����ulRoutePoolId����
ע�⣺
*********************************************/
COM_EXPORT ULONG RipSetFlapParameter(ULONG ulRoutePoolId, USHORT usA2WDelay, USHORT usW2ADelay);


/********************************************
���ܣ�����ָ����·�ɳص���
���룺ulRoutePoolId�� ·�ɳ�ID���ɺ���RipAddIpv4RoutePool��RipAddIpv6RoutePool �����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾ��û�н���Э����棬
	  RIP_ERROR_ROUTE_POOL_ID��ʾ�����ulRoutePoolId����
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ��·�ɳ������ӿڿ���û��Ԥ����
	  RIP_ERROR_ROUTE_POOL_UNENABLED��ʾָ��·�ɳ�û��ʹ�ܡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG RipStartFlap(ULONG ulRoutePoolId);


/********************************************
���ܣ�ָֹͣ����·�ɳص���
���룺ulRoutePoolId�� ·�ɳ�ID���ɺ���RipAddIpv4RoutePool��RipAddIpv6RoutePool �����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾ��û�н���Э����棬
	  RIP_ERROR_ROUTE_POOL_ID��ʾ�����ulRoutePoolId����
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ��·�ɳ������ӿڿ���û��Ԥ����
	  RIP_ERROR_ROUTE_POOL_UNENABLED��ʾָ��·�ɳ�û��ʹ�ܡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG RipStopFlap(ULONG ulRoutePoolId);
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

