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
���ܣ����PPPoE Session
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ucAuthType����֤���ͣ�����PPPOE_AUTH_CHAP��PPPOE_AUTH_PAP��
	  szUserName����֤�û�������󳤶�Ϊ20������Ϊ�գ�
	  szPassword����֤���룬��󳤶�Ϊ20������Ϊ�գ�
	  bStaticIp���Ƿ�ʹ�þ�̬�����IP��ַ��
	  ulSrcIp����̬�����IP��ַ��bStaticIpΪTRUEʱ��Ч��
	  ui64SrcMac��Session��ʹ�õ�ΨһMAC��ַ��
	  bEnableEcho���Ƿ�ʹ��Session��EchoRequest���ܣ�
	  ulEchoFrequency��Session��EchoRequestƵ�ʣ�����Ϊ��λ��bEnableEchoΪTRUEʱ��Ч��
	  ulEchoAttempts��Session��EchoRequestʧ��ʱ���ԵĴ�����bEnableEchoΪTRUEʱ��Ч��
�����pulSessionId��Session IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  PPPOE_ERROR_USER_NAME_EMPTY��ʾ�����szUserNameΪ�գ�
	  PPPOE_ERROR_PASS_WORD_EMPTY��ʾ�����szPasswordΪ�գ�
	  PPPOE_ERROR_USER_NAME_LEN��ʾ�����szUserName����Ϊ0�����20��
	  PPPOE_ERROR_PASS_WORD_LEN��ʾ�����szPassword����Ϊ0�����20��
	  PPPOE_ERROR_EXIST_SAME_MAC_ADDR��ʾ��ǰ�˿����Ѵ���MAC��ַ��ui64SrcMac��ͬ��Session
	  PPPOE_ERROR_EXCEED_MAX_SESSION_COUNT��ʾsession��Ŀ�Ѿ�����ָ���˿�����������ֵ�����˿�֧��2000��Session��
ע�⣺
*********************************************/
COM_EXPORT ULONG PppoeAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucAuthType, const char* szUserName, const char* szPassword
	, BOOL bStaticIp, ULONG ulSrcIp, UINT64 ui64SrcMac, BOOL bEnableEcho, ULONG ulEchoFrequency, ULONG ulEchoAttempts, ULONG *pulSessionId);

/********************************************
���ܣ�ɾ��ָ����PPPoE Session
���룺ulSssnId�� IGMP Session ID���ɺ���PppoeAddSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  PPPOE_ERROR_SSSN_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG PppoeRemoveSession(ULONG ulSssnId);

/********************************************
���ܣ�����ָ����PPPoE Session
���룺ulSssnId�� PPPoE Session ID���ɺ���PppoeAddSession���	��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾδ����Э����棬
	  PPPOE_ERROR_SSSN_ID��ʾ�����ulSessionId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ����TCP����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ
	  PPPOE_ERROR_SSSN_DISCONNECTING��ʾSession���ڶϿ�����
	  FD_ERROR��ʾ�������ͨ��ʧ��
ע�⣺
*********************************************/
COM_EXPORT ULONG PppoeConnectSession(ULONG ulSssnId);

/********************************************
���ܣ��Ͽ�ָ����PPPoE Session
���룺ulSssnId�� PPPoE Session ID���ɺ���PppoeAddSession�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾδ����Э����棬
	  PPPOE_ERROR_SSSN_ID��ʾ�����ulSessionId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ����TCP����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ
	  FD_ERROR��ʾ�������ͨ��ʧ��
ע�⣺
*********************************************/
COM_EXPORT ULONG PppoeDisconnectSession(ULONG ulSssnId);

/********************************************
���ܣ���ȡָ����PPPoE Session������״̬�������Ϣ
���룺ulSssnId�� PPPoE Session ID���ɺ���PppoeAddSession�����
�����pucSssnState��Session��ǰ������״̬������PPPOE_STATE_DISCONNECTED��PPPOE_STATE_CONNECTING��PPPOE_STATE_DISCONNECTING��PPPOE_STATE_CONNECTED��
	  pusSssnId��PPPoE�Ự�׶ε�Session ID����ѡ��
	  pulSrcIp��Session��ԴIP��ַ����ѡ��
	  pulDstIp��PPPoE��������IP��ַ����ѡ��
	  pui64DstMac��PPPoE��������MAC��ַ����ѡ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_STOP_PROTOCOL_EMULATION��ʾδ����Э����棬
	  PPPOE_ERROR_SSSN_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG PppoeGetSessionState(ULONG ulSssnId, UCHAR* pucSssnState, USHORT* pusSssnId
									  , ULONG* pulSrcIp, ULONG* pulDstIp, UINT64* pui64DstMac);
#endif


#ifdef __FOR_CSHARP
}
#endif