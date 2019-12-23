#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define CAP_ERROR_CAPTURING					(400)
#define CAP_ERROR_CAPTURE_PLANE				(401)
#define CAP_ERROR_CAPTURE_TYPE				(402)
#define CAP_ERROR_CAPTURE_ID				(403)
#define CAP_ERROR_FRAME_INDEX				(404)
#define CAP_ERROR_DOWNLOADING				(405)
#define CAP_ERROR_FILTER_MAP                (406)

#define CAP_PLANE_CONTROL_AND_DATA			(0)
#define CAP_PLANE_CONTROL					(1)

#define CAP_TYPE_ALL						(0X00000001)
#define CAP_TYPE_FCS_ERROR					(0X00000002)
#define CAP_TYPE_IPV4_CHECKSUN_ERROR		(0X00000004)
#define CAP_TYPE_PAYLOAD_ERROR				(0X00000008)
#define CAP_TYPE_FILTER						(0X00000010)



#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
���ܣ�����ָ���˿ڵĲ�������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucCapPlane������ƽ�档CAP_PLANE_CONTROL_AND_DATA��ʾ������ƺ�����ƽ��Ľ���֡��
	              CAP_PLANE_CONTROL��ʾ�������ƽ��ķ��ͺͽ���֡��
	  ucCapType���������͡�
	             ��ucCapPlane==CAP_PLANE_CONTROL_AND_DATAʱ���������У�
					CAP_TYPE_ALL��ʾ��������֡��
					CAP_TYPE_FCS_ERROR��ʾ����FCS����֡��
					CAP_TYPE_IPV4_CHECKSUN_ERROR��ʾ����IPv4�ײ�У��ʹ���֡��
					CAP_TYPE_PAYLOAD_ERROR��ʾ���񾻺�У�����֡��
					CAP_TYPE_FILTER��ʾ�����������ģ���֡��
					����CAP_TYPE_ALL������4�ֲ��������ǻ����ϵ������4�ֲ��������ǻ�Ĺ�ϵ��
	             ��ucCapPlane==CAP_PLANE_CONTROLʱ���������У�
					CAP_TYPE_ALL��ʾ��������֡��
					CAP_TYPE_FILTER��ʾ�����������ģ���֡���������ǻ����ϵ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  CAP_ERROR_CAPTURE_PLANE��ʾ�����ucCapPlane����
	  CAP_ERROR_CAPTURE_TYPE��ʾ����ucCapType����
ע�⣺�������øú�����Ĭ��Ϊ����ƽ��Ϊ������ƺ�����ƽ��Ľ���֡����������Ϊ��������֡��
*********************************************/
COM_EXPORT ULONG CapSetType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucCapPlane, UCHAR ucCapType);


/********************************************
���ܣ�����ָ���˿ڵĲ������ģ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucFilterMask������ģ�����룻
	  pucFilterValue������ģ��ֵ�ڣ�
	  ulFilterLen��ģ�峤�ȣ����ֽ�Ϊ��λ�����Ϊ128�ֽڣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURING��ʾ���ڲ���֡��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapSetPortFilter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);


/********************************************
���ܣ�����ָ���˿ڵĵڶ����������ģ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucFilterMask������ģ�����룻
	  pucFilterValue������ģ��ֵ�ڣ�
	  ulFilterLen��ģ�峤�ȣ����ֽ�Ϊ��λ�����Ϊ128�ֽڣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURING��ʾ���ڲ���֡��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapSetPortFilterAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);


/********************************************
���ܣ�����ָ���˿ڵĲ������ģ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulFilterUsedMap��1:ģ��1��Ч 2:ģ��2��Ч 3:ģ��1��ģ��2��Ч 4:ģ��1��ģ��2ͬʱ��Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURING��ʾ���ڲ���֡��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapSetPortFilterMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFilterUsedMap);


/********************************************
���ܣ�ʹ�ܻ�ʹ��ָ���˿ڵ�֡����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  bEnable�� �Ƿ�ʹ�ܱ��Ĳ���
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  CAP_ERROR_DOWNLOADING��ʾ�˿��������ز����ġ�
ע�⣺�����øú�����Ĭ��Ϊʹ��֡����
*********************************************/
COM_EXPORT ULONG CapEnablePort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bEnable);


/********************************************
���ܣ���FloodServer����ָ���˿��Ѿ������֡
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pulCapId������IDָ�롣����ID������ģ����������ʹ�ã�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURING��ʾ���ڲ����ģ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿ڵĶ˿ڻ�û��Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapDownloadFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulCapId);


/********************************************
���ܣ���FloodServer����ָ���˿��Ѿ������֡
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  caCapFilePath��Ϊ�����ʾ���ص��ڴ棬��Ϊ�ձ�ʾ��cap�ļ���ʽ���浽ָ��·����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURING��ʾ���ڲ����ģ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿ڵĶ˿ڻ�û��Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortDownloadFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char *caCapFilePath);


/********************************************
���ܣ�ָֹͣ���˿ڵ�����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
���������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapDownloadStop(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ��ȴ���һ������ָ�����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulTimeout���ȴ���ʱʱ�䣬��λΪms��
���������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapWaitForDownloadFinish(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulTimeout);


/********************************************
���ܣ��ж�ָ���˿��Ƿ���������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  nType��������ͣ�0��ʾ��Ȿ�ز���״̬��1��ʾ������������״̬��
�����pbDownloading��TRUE(1)��ʾ�������أ�FALSE(0)��ʾ����δ����;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortIsDownloading(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbDownloading);


/********************************************
���ܣ���ȡ��ǰ�����ػ򲶻��֡��Ŀ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  nType����ȡ���ͣ�0��ʾ��ȡ���������ص�֡��Ŀ��1��ʾ��ȡ�������Ѳ����֡��Ŀ��
�����pulFrameCount������֡����Ŀָ�룻
	  pbIsFull���Ƿ񲶻�����ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  FD_ERROR_TIMEOUT��ʾ��ȡ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortGetFrameCount(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, ULONG *pulFrameCount, BOOL *pbIsFull);


/********************************************
���ܣ���ȡ��ǰ�����ص�֡��Ŀ
���룺ulCapId�� ����ID���ɺ���CapDownloadFrames�����
�����pulFrameCount������֡����Ŀָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURE_ID��ʾ�����ulCapId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapGetFrameCount(ULONG ulCapId, ULONG *pulFrameCount);


/********************************************
���ܣ���ȡ��ǰ�������Ѳ��񵽵�֡��Ŀ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pulFrameCount������֡����Ŀָ�룻
	  pbIsFull���Ƿ񲶻�����ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�˿�δԤԼ��
	  FD_ERROR_TIMEOUT��ʾ��ȡ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapGetFrameCountEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulFrameCount, BOOL *pbIsFull);


/********************************************
���ܣ���ȡָ����ŵ�֡
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
      ulFrameIndex��Ҫ��ȡ���Ѿ������֡����ţ�1-based;
�����ppucFrame����֡���ݵ�ָ���ָ�룻
      pulFrameLength��֡����ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  CAP_ERROR_FRAME_INDEX��ʾ�����֡��Ŵ���
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortGetFrame(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFrameIndex, UCHAR **ppucFrame, ULONG *pulFrameLength);


/********************************************
���ܣ���ȡָ����ŵ�֡
���룺ulCapId�� ����ID���ɺ���CapDownloadFrames�����
      ulFrameIndex��Ҫ��ȡ���Ѿ������֡����ţ�1-based;
�����ppucFrame����֡���ݵ�ָ���ָ�룻
      pulFrameLength��֡����ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURE_ID��ʾ�����ulCapId����
	  CAP_ERROR_FRAME_INDEX��ʾ�����֡��Ŵ���
ע�⣺
*********************************************/
COM_EXPORT ULONG CapGetFrame(ULONG ulCapId, ULONG ulFrameIndex, UCHAR **ppucFrame, ULONG *pulFrameLength);


/********************************************
���ܣ�ɾ��ָ���˿������صı���
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺CapPortDownloadFrames����֮������øú������ͷ�����Ŀռ䡣
*********************************************/
COM_EXPORT ULONG CapPortDeleteFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ���ָ���˿������ص�֡��cap�ļ���ʽ���浽ָ��·����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  caCapFilePath��cap�ļ�·����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortSaveFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char *caCapFilePath);


/********************************************
���ܣ�ɾ����Capture IDָ����֡
���룺ulCapId�� ����ID���ɺ���CapDownloadFrames�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  CAP_ERROR_CAPTURE_ID��ʾ�����ulCapId����
ע�⣺CapDownloadFrames����֮������øú������ͷ�����Ŀռ䡣
*********************************************/
COM_EXPORT ULONG CapDeleteFrames(ULONG ulCapId);
#endif


/********************************************
���ܣ���ʼָ���˿ڵĲ���
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG CapStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ�ָֹͣ���˿ڵĲ���
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG CapStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ��ж�ָ���˿��Ƿ����ڲ���
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  nType��������ͣ�0��ʾ��Ȿ�ز���״̬��1��ʾ������������״̬��
�����pbTesting��TRUE(1)��ʾ���ڲ���FALSE(0)��ʾ����δ����;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG CapPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);


/********************************************
���ܣ��������Ĳ���
���룺��
�������
���أ���
ע�⣺
*********************************************/
COM_EXPORT void CapStart();


/********************************************
���ܣ�ֹͣ���Ĳ���
���룺��
�������
���أ���
ע�⣺
*********************************************/
COM_EXPORT void CapStop();
#endif


#ifdef __FOR_CSHARP
}
#endif

