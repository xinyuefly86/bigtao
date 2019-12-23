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
���ܣ�����TCP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulDstIp��Ŀ��IP��ַ��
	  ulSrcIp��ԴIP��ַ��
	  usDstPort��Ŀ�Ķ˿ںţ�
	  usSrcPort��Դ�˿ںţ�
�����pulSockId��Socket IDָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  FD_ERROR_TIMEOUT��ʾ���ӳ�ʱ��
	  TCP_ERROR_CONNECT_FAIL��ʾ����ʧ�ܡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG TcpConnect(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulDstIp, ULONG ulSrcIp, USHORT usDstPort, USHORT usSrcPort, ULONG* pulSockId);

/********************************************
���ܣ��ر�TCP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulSockId��Socket ID�� ��TcpConnect���������
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  TCP_ERROR_SOCKET_ID��ʾ�����ulSockId������Ч��Socket���ӱ�ʶ����
ע�⣺
*********************************************/
COM_EXPORT ULONG TcpClose(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId);

/********************************************
���ܣ�����TCP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulSockId��Socket ID����TcpConnect���������
	  pucData�����͵�����
	  usLen�����͵����ݳ���
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  TCP_ERROR_SOCKET_ID��ʾ�����ulSockId������Ч��Socket���ӱ�ʶ����
ע�⣺
*********************************************/
COM_EXPORT ULONG TcpSend(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId, const UCHAR* pucData, USHORT usLen);

/********************************************
���ܣ�����TCP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulSockId��Socket ID����TcpConnect���������
	  usRecvLen����Ҫ���յ����ݳ���
	  pucData������Buffer
�����pucData�����յ����������ݵ�ָ�룬
	  pusLen�����յ����������ݵ���ʵ���ȵ�ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  TCP_ERROR_SOCKET_ID��ʾ�����ulSockId������Ч��Socket���ӱ�ʶ����
	  TCP_ERROR_SOCKET_CLOSED��ʾTCP�����Ѿ����رա�
ע�⣺pusLen����ֵС�ڵ���usRecvLen����û�����ݣ�������һֱ����ֱ�����յ����ݻ�TCP���ӹر�
*********************************************/
COM_EXPORT ULONG TcpRecv(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulSockId, USHORT usRecvLen, UCHAR* pucData, USHORT* pusLen);
#endif


#ifdef __FOR_CSHARP
}
#endif