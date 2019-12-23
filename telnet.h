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
���ܣ�����telnet ����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulTimeout: ������ʱʱ�䣬��λΪms
	   
�����telnetId:telnet ���� IDָ�룻
	  bConn: �����Ƿ�ɹ���־��TRUE ��ʾ���ӳɹ���FALSE ��ʾ����δ�ɹ�
	  iRetType:���������
	  pcRev:  ����ؽ��
	  piRevLen: pcRev �ַ����ĳ���
	  
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  FD_ERROR_TIMEOUT��ʾ���ӳ�ʱ��
	  TELNET_ERROR_CONNECT_FAIL��ʾ����ʧ�ܡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG TelnetConnect(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG dstIp,ULONG *telnetId,ULONG ulTimeout,char *pcRev,int *piRevLen);
/********************************************
���ܣ��ر�telnet ����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  ulSockId��Socket ID�� ��TelnetConnect���������
�������

���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
ע�⣺
*********************************************/
COM_EXPORT ULONG TelnetClose(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId);

/********************************************
���ܣ�����telnet ���� �����û���������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  telnetId��telnet ����ID����TelnetConnect���������
	  ulTimeout:������ʱʱ�� ��λms
	  pcSend�����͵����ݣ���0��β���ַ�����ÿ���������ַ�����β���\r\n
�����
	  bConn: �����Ƿ�ɹ���־��TRUE ��ʾ���ӳɹ���FALSE ��ʾ����δ�ɹ�
	  iRetType:���������
	  pcRev:  ����ؽ��
	  piRevLen: pcRev �ַ����ĳ���
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
ע�⣺
*********************************************/
 COM_EXPORT ULONG TelnetSend(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,BOOL *bConn,int *iRetType,const char *pcSend,char *pcRev,int *piRevLen);

/********************************************
���ܣ�����telnet ���� �����û���������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  telnetId��telnet ����ID����TelnetConnect���������
	  ulTimeout:������ʱʱ�� ��λms
	  pcSend�����͵����ݣ���0��β���ַ���
�����
	  bConn: �����Ƿ�ɹ���־��TRUE ��ʾ���ӳɹ���FALSE ��ʾ����δ�ɹ�
	  iRetType:���������
	  pcRev:  ����ؽ��
	  piRevLen: pcRev �ַ����ĳ���
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
ע�⣺
*********************************************/
 COM_EXPORT ULONG TelnetSendLine(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,const char *pcSend,int iSendLen,char *pcRev,int *piRevLen);

/********************************************
���ܣ�����Telenet�������ݵĽ����ַ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based��
	  ulPortId���˿ںţ�1-based��
	  telnetId��telnet ����ID����TelnetConnect���������
	  ulTimeout:������ʱʱ�� ��λms
	  cEndAscii�������ַ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
ע�⣺ÿ��TelnetConnect�ɹ�֮����Ҫ�������á�
*********************************************/
 COM_EXPORT ULONG TelnetSetEndAscii(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG telnetId,ULONG ulTimeout,char cEndAscii);

#endif
#ifdef __FOR_CSHARP
}
#endif