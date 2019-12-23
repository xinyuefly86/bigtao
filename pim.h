#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define PIM_ERROR_EXCEED_MAX_SESSION_COUNT			(500)
#define PIM_ERROR_EXCEED_MAX_GROUP_COUNT			(501)
#define PIM_ERROR_SESSION_ID						(502)
#define PIM_ERROR_GROUP_STATE_ID					(503)


typedef struct tag_GROUP_STATE_POOL
{
	ULONG  ulGroupAddr;//���ַ
	ULONG  ulGroupAddrCount;//���ַ��Ŀ
	UCHAR  ucGroupAddrModBit;//���ַҪ�����bitλ��ȡֵ��ΧΪ1--32
	UCHAR  ucGroupAddrModStep;//���ַ����Ĳ�����ȡֵ��ΧΪ1--255

	BOOL   bVlan;//�����ַ���Ƿ��VLAN
	USHORT usVlanId;//VLAN ID
	UCHAR  ucVlanPri;//VLAN PRI
	UCHAR  ucVlanCfi;//VLAN CFI
} GROUP_STATE_POOL_S;

enum 
{
	PIM_GROUP_POOL_JION_TIME=0,
	PIM_GROUP_POOL_LEAVE_TIME,
};


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
���ܣ����PIMv2 Session
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Address�����Զ˿ڵ�IPv4�ӿڵ�ַ��
�����pulSessionId��Session IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV4_ADDRESS��ʾ�����ulPortIPv4Address����ָ���˿ڵĽӿ�IPv4��ַ��
	  PIM_ERROR_EXCEED_MAX_SESSION_COUNT��ʾsession��Ŀ�Ѿ�����ָ���˿�����������ֵ��
ע�⣺
*********************************************/
COM_EXPORT ULONG PimAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucServiceMode,
	ULONG ulPortIPv4Address, ULONG *pulSessionId);


/********************************************
���ܣ�ɾ��ָ����PIM Session
���룺ulSessionId�� PIM Session ID���ɺ���PimAddV2Session�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  PIM_ERROR_SESSION_ID��ʾ�����ulSessionId����
ע�⣺
*********************************************/
COM_EXPORT ULONG PimRemoveSession(ULONG ulSessionId);


/********************************************
���ܣ���ָ����PIM Session��������ַ��
���룺ulSessionId�� PIM Session ID���ɺ���PimAddV2Session�����
      pGroupPool�����ַ��ָ�룻
�����pulGroupPoolId�����ַ��IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  PIM_ERROR_SESSION_ID��ʾ�����ulSessionId����
	  PIM_ERROR_EXCEED_MAX_GROUP_COUNT��ʾ���ַ���Ѿ�����ָ���˿�����������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾ����·�ɳ�����255.255.255.255��
ע�⣺
*********************************************/
COM_EXPORT ULONG PimAddGroupPool(ULONG ulSessionId, GROUP_POOL_S *pGroupPool, ULONG *pulGroupPoolId);


/********************************************
���ܣ�ɾ��ָ�������ַ��
���룺ulGroupPoolId�� ���ַ��ID���ɺ���PimAddGroupPool�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
	  PIM_ERROR_GROUP_POOL_ID��ʾ�����ulGroupPoolId����
ע�⣺
*********************************************/
COM_EXPORT ULONG PimRemoveGroupPool(ULONG ulGroupPoolId);


/********************************************
���ܣ�ʹ�ܻ�ʹ��ָ�������ַ��
���룺ulGroupPoolId�� ���ַ��ID���ɺ���PimAddGroupPool�����
      bEnable���Ƿ�ʹ��ָ�������ַ�أ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  PIM_ERROR_GROUP_POOL_ID��ʾ�����ulGroupPoolId����
ע�⣺�����øú�����Ĭ��Ϊʹ�����ַ�ء�
*********************************************/
COM_EXPORT ULONG PimEnableGroupPool(ULONG ulGroupPoolId, BOOL bEnable);


/********************************************
���ܣ�����ָ���˿ڷ���PIM Membership Report���ĵ�����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPPS��   ����PIM Membership Report���ĵ����ʣ���λΪPackets/Sec��ȡֵ��ΧΪ1--10000��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_START_PROTOCOL_EMULATION��ʾ���ڽ���Э����棬
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG PimSetMessageTransmitRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPPS);

/********************************************
���ܣ���ȡָ�����ַ�ؼ���/�뿪��ʱ��
���룺ulGroupPoolId�� ���ַ��ID���ɺ���PimAddGroupPool�����
ucStaItem: 0 ����ʱ�� 1�뿪ʱ��
			
������鲥�����/�뿪��ʱ��(��λ8ns)
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
ע�⣺
*********************************************/

COM_EXPORT ULONG PimGetGroupPoolTime(ULONG ulGroupPoolId,UCHAR ucStaItem, ULONG *pulValue);
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

