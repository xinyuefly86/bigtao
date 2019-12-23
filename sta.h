#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif



#define STA_ERROR_PORT_STATISTICS_TYPE					(300)
#define STA_ERROR_STREAM_STATISTICS_TYPE				(301)
#define STA_ERROR_EXCEED_MAX_STREAM_ID					(302)
#define STA_ERROR_DOING_STATISTICS						(303)
#define STA_ERROR_STATIC_STARTING                       (304)
#define STA_ERROR_STATIC_FILTER_MAP                     (305)



#define STA_MEA_TX_STREAM_FRAME				(0)  //�˿ں���������
#define STA_MEA_RX_STREAM_FRAME				(1)  //�˿ں���������
#define STA_MEA_TX_TOTAL_FRAME				(2)  //�˿�����
#define STA_MEA_RX_TOTAL_FRAME				(3)  //�˿�����
#define STA_MEA_TX_FPS						(4)  //�˿ں���������
#define STA_MEA_RX_FPS						(5)  //�˿ں���������
#define STA_MEA_TX_BPS						(6)  //�˿ں���������
#define STA_MEA_RX_BPS						(7)  //�˿ں���������
#define STA_MEA_RX_SEQUENCE_ERROR			(8)  //������
#define STA_MEA_RX_PAYLOAD_ERROR			(9)  //������
#define STA_MEA_RX_IPV4_CHECKSUM_ERROR		(10) //�˿�����
#define STA_MEA_RX_FCS_ERROR				(11) //�˿�����
#define STA_MEA_RX_FILTER					(12) //�˿�����
#define STA_MEA_MIN_LATENCY_S				(13) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_AVG_LATENCY_S				(14) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MAX_LATENCY_S				(15) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MIN_LATENCY_C				(16) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_AVG_LATENCY_C				(17) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MAX_LATENCY_C				(18) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_TX_bps						(19) //�˿ں���������
#define STA_MEA_RX_bps						(20) //�˿ں���������
#define STA_MEA_RX_UTIL						(21) //�˿ں���������
#define STA_MEA_MIN_LATENCY_JITTER_S		(22) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_AVG_LATENCY_JITTER_S		(23) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MAX_LATENCY_JITTER_S		(24) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MIN_LATENCY_JITTER_C		(25) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_AVG_LATENCY_JITTER_C		(26) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_MAX_LATENCY_JITTER_C		(27) //������, ʱ�ӵĵ�λ��us
#define STA_MEA_RX_MIN_BPS					(28)  //������
#define STA_MEA_RX_AVG_BPS					(29)  //������
#define STA_MEA_RX_MAX_BPS					(30)  //������
#define STA_MEA_TX_Mbps						(31) //�˿ں���������
#define STA_MEA_RX_Mbps						(32) //�˿ں���������

#define STA_MEA_TX_TOTAL_BYTE               (33)//�˿�����
#define STA_MEA_RX_TOTAL_BYTE               (34)//�˿�����
#define STA_MEA_RX_PAUSE_FRAME              (35)//�˿�����
#define STA_MEA_RX_UNDER_SIZE_FRAME         (36)//�˿�����
#define STA_MEA_RX_BIT_ERROR_COUNT          (37)//�˿�����
#define STA_MEA_RX_FILTER_RATE              (38)//�˿�����
#define STA_MEA_RX_TCP_CHECKSUM_ERROR       (39)//�˿�����
#define STA_MEA_RX_UDP_CHECKSUM_ERROR       (40)//�˿�����
#define STA_MEA_RX_LOSS_STREAM_FRAME		(41)//������


#define STA_MEA_RX_FIRST_PACKET_TIME        (0)
#define STA_MEA_RX_LAST_PACKET_TIME         (1)

typedef struct tag_STA_MEA_SET
{
	BOOL bTxBpsCrc;
	BOOL bTxBpsPreamble;
	BOOL bTxBpsMinIfg;
	BOOL bTxUda;
	ULONG ulTxUdaLen;
	BOOL bRxBpsCrc;
	BOOL bRxBpsPreamble;
	BOOL bRxBpsMinIfg;
	BOOL bRxUda;
	ULONG ulRxUdaLen;
	ULONG ulUsfThreshold;
} STA_MEA_SET;


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
���ܣ���ָ����Ŀ�Ķ˿ں���ѡ��Ҫͳ�Ƶ���
���룺ulChsId�� Ŀ�Ļ���ID��1-based��
      ulSlotId��Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_DOING_STATISTICS��ʾ���ڽ���ͳ�ƣ�
	  STA_ERROR_EXCEED_MAX_STREAM_ID��ʾ�ö˿�����ѡ��ͳ�Ƶ�����������ID����С����ID֮�����256��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaSelectStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName);


/********************************************
���ܣ�ɾ��ָ����Ŀ�Ķ˿ں���ѡ��Ҫͳ�Ƶ�������
���룺ulChsId�� Ŀ�Ļ���ID��1-based��
      ulSlotId��Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  STA_ERROR_DOING_STATISTICS��ʾ���ڽ���ͳ�ƣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaRemoveStreams(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ���ȡָ���˿ڵĶ��ͳ������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulStaNum: ͳ������Ŀ
	  pucStaItem���˿�ͳ���
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  STA_ERROR_PORT_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_CARD_NOT_RESERVED��ʾ�ýӿڿ���û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺����������ظ���ͳ����
*********************************************/
COM_EXPORT ULONG StaGetPortDatas(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);

/********************************************
���ܣ���ȡָ���˿ڵĶ��ͳ������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulStaNum: ͳ������Ŀ
	  pucStaItem���˿�ͳ���
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  STA_ERROR_PORT_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_CARD_NOT_RESERVED��ʾ�ýӿڿ���û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺����������ظ���ͳ���� ���ܺ�StaGetPortDatas��ͬ  ��������ͳ������double���ݵĶ�����������Ҫ��������ǿת����
*********************************************/
COM_EXPORT ULONG StaGetPortDatasRaw(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);


/********************************************
���ܣ���ȡָ���˿ڵ�ͳ������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucStaItem���˿�ͳ���������ͣ�
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  STA_ERROR_PORT_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR������������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaGetPortData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucStaItem, UINT64 *pui64Value);


/********************************************
���ܣ���ȡָ������ͳ������
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  ucStaItem����ͳ���
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_STREAM_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR������������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaGetStreamData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, UCHAR ucStaItem, UINT64 *pui64Value);

/********************************************
����:��ȡָ����ĳ�����Ľ���ʱ��
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  ucStaItem����ͳ����0��һ�����յ�ʱ�䣬1���һ�������յ�ʱ��

ucStaItem:0��һ�����յ�ʱ�䣬1���һ�������յ�ʱ��
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_STREAM_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR������������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaGetPacketRecTime(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, UCHAR ucStaItem, UINT64 *pui64Value);

/********************************************
����:��ȡָ�����ӿ�ʼͳ�Ƶ�ͳ�Ƶ������ʱ����
���룺ulDstChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulDstSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulDstPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_STREAM_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  FD_ERROR������������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaGetStreamSeqErrorTime(ULONG ulDstChsId, ULONG ulDstSlotId, ULONG ulDstPortId, const char *pcStreamName,UINT64 *pui64Value);


/********************************************
���ܣ���ȡָ�����Ķ��ͳ������
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  ulStaNum: ͳ������Ŀ
	  pucStaItem����ͳ���
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_STREAM_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_CARD_NOT_RESERVED��ʾ�ýӿڿ���û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺����������ظ���ͳ����
*********************************************/
COM_EXPORT ULONG StaGetStreamDatas(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);

/********************************************
���ܣ���ȡָ�����Ķ��ͳ������
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  ulStaNum: ͳ������Ŀ
	  pucStaItem����ͳ���
�����pui64Value��ͳ������ָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  STA_ERROR_STREAM_STATISTICS_TYPE��ʾ�����ucStaType����
	  FD_ERROR_CARD_NOT_RESERVED��ʾ�ýӿڿ���û�б�Ԥ����
	  FD_ERROR��ʾ��������
ע�⣺����������ظ���ͳ���� ���ܺ�StaGetPortDatas��ͬ  ��������ͳ������double���ݵĶ�����������Ҫ��������ǿת����
*********************************************/
COM_EXPORT ULONG StaGetStreamDatasRaw(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);


/********************************************
���ܣ����˿���ͳ���У����ָ���˿ڵ�ͳ�����ݣ����˿�δ��ͳ���У���λ�˿ڷ��ͺ�ͳ��״̬
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  TRA_ERROR_TRANSMITING��ʾ�ö˿����ڷ��ͣ�
	  FD_ERROR��ʾ��������
ע�⣺�ڶ˿�ֻ�������Ͳ�����ͳ��ʱ��Ҫ�ȵ��øú���
*********************************************/
COM_EXPORT ULONG StaClearData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ�����ָ���˿ڵ�ͳ�ƹ���ģ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucFilterMask������ģ�����룻
	  pucFilterValue������ģ��ֵ�ڣ�
	  ulFilterLen��ģ�峤�ȣ����ֽ�Ϊ��λ�����Ϊ128�ֽڣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  STA_ERROR_DOING_STATISTICS��ʾ���ڽ���ͳ�ƣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG StaSetPortFilter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);

/********************************************
���ܣ�����ָ���˿ڵĵڶ���ͳ�ƹ���ģ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucFilterMask������ģ�����룻
	  pucFilterValue������ģ��ֵ�ڣ�
	  ulFilterLen��ģ�峤�ȣ����ֽ�Ϊ��λ�����Ϊ128�ֽڣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  STA_ERROR_DOING_STATISTICS��ʾ���ڽ���ͳ�ƣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG StaSetPortFilterAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);

/********************************************
���ܣ�����ָ���˿ڵ�ͳ�ƹ�����Ч����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulFilterUsedMap��1:ģ��1��Ч 2:ģ��2��Ч 3:ģ��1��ģ��2��Ч 4:ģ��1��ģ��2ͬʱ��Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  STA_ERROR_DOING_STATISTICS��ʾ���ڽ���ͳ�ƣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG StaSetPortFilterMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFilterUsedMap);



/********************************************
���ܣ���ʼָ���˿ڵ�ͳ��
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾ�ö˿ڻ�û�б�Ԥ����
	  TRA_ERROR_TRANSMITING��ʾ�ö˿����ڷ��ͣ�
	  FD_ERROR��ʾ��������
ע�⣺�ڶ˿���Ҫͬʱ����������ͳ��ʱ��Ӧ�ȿ���ͳ���ٿ�������
*********************************************/
COM_EXPORT ULONG StaStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ�ָֹͣ���˿ڵ�ͳ��
���룺ulChsId�� ָ������Ŀ�Ļ���ID��1-based��
      ulSlotId��ָ������Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��ָ������Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ����ָ���˿��Ƿ�����ͳ��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  nType��������ͣ�0��ʾ��Ȿ�ز���״̬��1��ʾ������������״̬��
�����pbTesting��TRUE(1)��ʾ����ͳ�ƣ�FALSE(0)��ʾͳ��δ����;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG StaPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);

/********************************************
���ܣ���ȡͳ��״̬
���룺��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
     		STA_ERROR_STATIC_STARTING ��ʼͳ��ִ����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG StaGetStaState();

COM_EXPORT ULONG StaSetPortBitErrorMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId ,BOOL bEnable,UCHAR ucData[16]);

#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

