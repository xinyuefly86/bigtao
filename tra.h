#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define TRA_ERROR_TRANSMITING							(200)
#define TRA_ERROR_NO_TRANSMITING_PORT					(201)
#define TRA_ERROR_TRANSMIT_MODE							(202)
#define TRA_ERROR_SCHEDULE_MODE							(203)
#define TRA_ERROR_FRAME_TYPE							(204)
#define TRA_ERROR_LENGTH_TYPE							(205)
#define TRA_ERROR_PAYLOAD_TYPE							(206)
#define TRA_ERROR_EXCEED_MAX_STREAM_COUNT				(207)
#define TRA_ERROR_EXCEED_FULL_BANDWIDTH					(208)
#define TRA_ERROR_STREAM_LENGTH							(209)
#define TRA_ERROR_EXCEED_STREAM_HEADER_LENGTH			(210)
#define TRA_ERROR_STREAM_UDF							(211)
#define TRA_ERROR_STREAM_UDF_LENGTH						(212)
#define TRA_ERROR_STREAM_UDF_CHECKSUM					(213)
#define TRA_ERROR_STREAM_UDF_VDF_OVERLAP				(214)
#define TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP	(215)
#define TRA_ERROR_STREAM_PAYLOAD_TYPE					(216)
#define TRA_ERROR_EXCEED_MAX_VFD_COUNT					(217)
#define TRA_ERROR_RATE_UNIT								(218)
#define TRA_ERROR_HAVE_NO_STREAM						(219)
#define TRA_ERROR_EXCEED_LAST_STEP_VALUE				(220)
#define TRA_ERROR_STEP_TYPE								(221)
#define TRA_ERROR_EXCEED_MAX_CS_COUNT					(222)


enum {
	TRA_TX_MODE_CONTINUOUS = 0, 
	TRA_TX_MODE_SINGLE_BURST, 
	TRA_TX_MODE_MULTI_BURST, 
	TRA_TX_MODE_TIME_BURST,
	TRA_TX_MODE_STREAM_SERIAL,
	TRA_TX_MODE_ON_STREAM,//5
	TRA_TX_MODE_CONT_MULTI_BURST,
};


enum {
	TRA_IBG_UNIT_TYPE_NONE = 0,
	TRA_IBG_UNIT_TYPE_NS,
	TRA_IBG_UNIT_TYPE_US,
	TRA_IBG_UNIT_TYPE_MS,
	TRA_IBG_UNIT_TYPE_SEC,
	TRA_IBG_UNIT_TYPE_BIT,
};


enum {
	TRA_SCHEDULE_MODE_IFG = 0,
	TRA_SCHEDULE_MODE_FPS,
	TRA_SCHEDULE_MODE_BPS,
	TRA_SCHEDULE_MODE_COUNT,
};


enum {
	TRA_FPS_TYPE_ACCURATE = 0, 
    TRA_FPS_TYPE_EVEN
};


enum {
	TRA_FPS_EVEN_MIN = 0, 
	TRA_FPS_EVEN_MID, 
	TRA_FPS_EVEN_MAX
};


enum {
	TRA_RATE_UNIT_TYPE_NS = 0,//֡�����������Ϊ��λ
	TRA_RATE_UNIT_TYPE_FPS,//Frames/Sec
	TRA_RATE_UNIT_TYPE_ULT,//%Ultilization
	TRA_RATE_UNIT_TYPE_DBS,//DataBits/Sec 
	TRA_RATE_UNIT_TYPE_FBS,//FrameBits/Sec 
	TRA_RATE_UNIT_TYPE_TBS,//TotalBits/Sec 
	TRA_RATE_UNIT_TYPE_LBS//LineBits/Sec
};


enum {
	TRA_PRO_TYPE_CUSTOM = 0, 
	TRA_PRO_TYPE_IPV4, 
    TRA_PRO_TYPE_IPV6, 
	TRA_PRO_TYPE_TCP, 
	TRA_PRO_TYPE_UDP,
    TRA_PRO_TYPE_GTP,
	TRA_PRO_TYPE_TCP6, 
	TRA_PRO_TYPE_UDP6, 
	TRA_PRO_TYPE_ICMPv4, 
	TRA_PRO_TYPE_IGMP, 
	TRA_PRO_TYPE_ARP, 
	TRA_PRO_TYPE_PAUSE,
	TRA_PRO_TYPE_LAYER2,
	TRA_PRO_TYPE_ICMPv6,
	TRA_PRO_TYPE_GOOSE,
};


enum {
	TRA_LEN_TYPE_FIXED = 0, //��ʾ���ȹ̶�
	TRA_LEN_TYPE_RANDOM, //��ʾ�������
	TRA_LEN_TYPE_INCR,//��ʾ���ȵ���
	TRA_LEN_TYPE_ALTERNATE,//��ʾ�����С���棬��֧��Pϵ�а忨
	TRA_LEN_TYPE_DECR//��ʾ���ȵݼ�����֧��40G�忨
};

//ʱ�����λ��
enum {
	TRA_TIME_STAMP_HEAD = 0,
	TRA_TIME_STAMP_TAIL = 1
};

//Payload������
enum {
	TRA_PAY_TYPE_CYCLE = 0, 
	TRA_PAY_TYPE_INCR,
	TRA_PAY_TYPE_RANDOM,
	TRA_PAY_TYPE_UDF,
};

//�����ֶε���������
enum{
	TRA_STEP_TYPE_NONE = 0,//��ʾ������
	TRA_STEP_TYPE_INCR,//��ʾ��������
	TRA_STEP_TYPE_RANDOM,//��ʾ��Χ�������
	TRA_STEP_TYPE_DECR//��ʾ�ݼ�����
};

enum {
	TRA_VFD_OFFSET_UDF = 0, //��ʾ����ƫ�ƴ�UDF��ʼλ�ÿ�ʼ����
	TRA_VFD_OFFSET_STREAM   //��ʾ����ƫ�ƴ�����ʼλ�ÿ�ʼ����
};

enum
{
	TRA_ERROR_CRC = 0x1,
};

enum {
	TRA_BER_TYPE_UDF = 0,
	TRA_BER_TYPE_HFPAT = 1,
	TRA_BER_TYPE_LFPAT = 2,
	TRA_BER_TYPE_MFPAT = 3,
	TRA_BER_TYPE_RPAT = 4,
	TRA_BER_TYPE_CRPAT = 5,
	TRA_BER_TYPE_CSPAT = 6,
	TRA_BER_TYPE_CJTPAT = 7,
	TRA_BER_TYPE_2E9_1 = 8,
	TRA_BER_TYPE_2E11_1 = 9,
	TRA_BER_TYPE_2E15_1 = 0xa,
	TRA_BER_TYPE_2E20_1 = 0xb,
	TRA_BER_TYPE_2E23_1 = 0xc,
	TRA_BER_TYPE_2E29_1 = 0xd,
	TRA_BER_TYPE_2E31_1 = 0xe,
};

#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
typedef struct tag_MAC
{
	BOOL   bEdit;//�Ƿ�༭MAC��ַ

	UINT64 ui64SrcMac;//ԴMAC��ַ
	ULONG   ulSrcMacStepType;//ԴMAC��ַ��������
	union
	{
		ULONG  ulSrcMacCount;//һ������������ԴMAC��ַ�ĸ���
		ULONG  ulSrcMacLast;//���������ԴMAC��ַ��ĩβֵ
	};
	UCHAR  ucSrcMacModBit;//ԴMAC��ַҪ�����bitλ��ȡֵ��ΧΪ17--48
	UCHAR  ucSrcMacModStep;//ԴMAC��ַ����Ĳ�����ȡֵ��ΧΪ1--255

	UINT64 ui64DstMac;//Ŀ��MAC��ַ
	ULONG   ulDstMacStepType;//Ŀ��MAC��ַ��������
	union
	{
		ULONG  ulDstMacCount;//һ������������Ŀ��MAC��ַ�ĸ���
		ULONG  ulDstMacLast;//���������Ŀ��MAC��ַ��ĩβֵ
	};
	UCHAR  ucDstMacModBit;//Ŀ��MAC��ַҪ�����bitλ��ȡֵ��ΧΪ17--48
	UCHAR  ucDstMacModStep;//Ŀ��MAC��ַ����Ĳ�����ȡֵ��ΧΪ1--255
} MAC_S;

typedef struct tag_SNAP
{
	BOOL   bEdit;//�Ƿ�༭SNAP
	UCHAR  ucDsap;//DSAP
	UCHAR  ucSsap;//SSAP
	UCHAR  ucCtrl;//Control Field
	ULONG  ulOui;//Organization Code, ȡֵ��ΧΪ0x0--0xffffff
} SNAP_S;

typedef struct tag_VLAN
{
	BOOL   bEdit;//�Ƿ�༭VLAN
	BOOL   bEnable;//�Ƿ�ʹ��VLAN
	UCHAR  ucVlanCount;//VLAN�Ĳ���
	struct VLAN_VALUE
	{
		USHORT usTpid;//TPID
		UCHAR  ucPri;//PRI
		UCHAR  ucCfi;//CFI
		USHORT usVlanId;//VLAN ID
		ULONG  ulVlanIdStepType;//VLAN ID��������
		union
		{
			USHORT usVlanIdCount;//һ������������Ŀ��VLAN ID�ĸ���
			USHORT usVlanIdLast;//���������VLAN ID��ĩβֵ
		};
		USHORT usVlanIdStep;//VLAN ID�����䲽��
	} arrVlanVal[6];
} VLAN_S;

typedef	struct tag_MPLS
{
	BOOL   bEdit;//�Ƿ�༭MPLS
	BOOL   bEnable;//�Ƿ�ʹ��MPLS
	UCHAR  ucMplsCount;//MPLS�Ĳ���
	struct MPLS_VALUE
	{
		UCHAR  ucExp;//EXP
		UCHAR  ucTtl;//TTL
		ULONG  ulLabel;//MPLS label
		ULONG  ulLabelStepType;//label��������
		union
		{
			ULONG  ulLabelCount;//һ������������Ŀ��label�ĸ���
			ULONG  ulLabelLast;//���������label��ĩβֵ
		};
		ULONG  ulLabelStep;//label�����䲽��
	} arrMplsVal[6];
} MPLS_S;


typedef	struct tag_IPV4//IPv4�ײ�
{
	BOOL   bEdit;//�Ƿ�༭IPv4�ײ�

	BOOL   bAutoVersion;//�Ƿ��Զ����version
	UCHAR  ucVersion;//version��ȡֵ��ΧΪ0--15����bAutoVersion==FALSEʱ��Ч
	BOOL   bAutoHeaderLength;//�Ƿ��Զ����header length
	UCHAR  ucHeaderLength;//header length��ȡֵ��ΧΪ0--15����bAutoHeaderLength==FALSE��Ч
	UCHAR  ucTos;//TOS
	UCHAR  ucFlag;//flag��ȡֵ��ΧΪ0--7
	USHORT usFragmentOffset;//fragment offset��ȡֵ��ΧΪ0--8191
	UCHAR  ucTtl;//TTL
	UCHAR  ucProtocol;//protocol
	BOOL   bAutoTotalLength;//�Ƿ���Ӳ���Զ���дIPv4�ײ�total length�ֶ�
	USHORT usTotalLength;//IPv4�ײ���total length�ֶΣ���bAutoTotalLength==FALSEʱ��Ч
	BOOL   bAutoChcksm;//�Ƿ���Ӳ���Զ���дIPv4�ײ�У���
	USHORT usChecksum;//IPv4�ײ�У��ͣ���bAutoChcksm==FALSEʱ��Ч

	USHORT usIdentification;//identification
	ULONG  ulIdStepType;//identification��������
	union
	{
		USHORT usIdCount;//һ������������identification�ĸ���
		USHORT usIdLast;//���������identification��ĩβֵ
	};
	USHORT usIdStep;//identification�����䲽��

	ULONG  ulSrcIPv4Addr;//ԴIPv4��ַ
	ULONG  ulSrcIPv4StepType;//ԴIPv4��ַ��������
	union
	{
		ULONG  ulSrcIPv4Count;//һ������������ԴIPv4��ַ�ĸ���
		ULONG  ulSrcIPv4Last;//���������ԴIPv4��ַ��ĩβֵ
	};
	UCHAR  ucSrcIPv4ModBit;//ԴIPv4��ַҪ�����bitλ��ȡֵ��ΧΪ1--32
	UCHAR  ucSrcIPv4ModStep;//ԴIPv4��ַ����Ĳ�����ȡֵ��ΧΪ1--255

	ULONG  ulDstIPv4Addr;//Ŀ��IPv4��ַ
	ULONG  ulDstIPv4StepType;//Ŀ��IPv4��ַ��������
	union
	{
		ULONG  ulDstIPv4Count;//һ������������Ŀ��IPv4��ַ�ĸ���
		ULONG  ulDstIPv4Last;//���������Ŀ��IPv4��ַ��ĩβֵ
	};
	UCHAR  ucDstIPv4ModBit;//Ŀ��IPv4��ַҪ�����bitλ��ȡֵ��ΧΪ1--32
	UCHAR  ucDstIPv4ModStep;//Ŀ��IPv4��ַ����Ĳ�����ȡֵ��ΧΪ1--255

	UCHAR  ucOptionLength;//IPv4�ײ���ѡ��ĳ��ȣ�ȡֵ��ΧΪ0--40
	UCHAR  ucaOption[40];//IPv4�ײ���ѡ����ֽ�����
} IPV4_S;

typedef	struct tag_IPV6//IPv6�ײ�
{
	BOOL   bEdit;//�Ƿ�༭IPv6�ײ�

	BOOL   bAutoVersion;//�Ƿ��Զ����version
	UCHAR  ucVersion;//version��ȡֵ��ΧΪ0--15����bAutoVersion==FALSEʱ��Ч
	UCHAR  ucTrafficClass;//Traffic Class
	UCHAR  ucNextHeader;//Next Header
	UCHAR  ucHopLimit;//Hop Limit
	BOOL   bAutoPayloadLength;//�Ƿ���Ӳ���Զ���дPayload Length�ֶ�
	USHORT usPayloadLength;//Payload Length����bAutoPayloadLength==FALSE��Ч

	ULONG  ulFlowLabel;//Flow Label
	ULONG  ulFlowLabelStepType;//Flow Label�ֶ���������
	union
	{
		ULONG  ulFlowLabelCount;//һ������������Flow Label�ĸ���
		ULONG  ulFlowLabelLast;//���������Flow Label��ĩβֵ
	};
	ULONG  ulFlowLabelStep;//Flow Label����Ĳ���

	UCHAR  ucaSrcIPv6Addr[16];//ԴIPv6��ַ
	ULONG  ulSrcIPv6StepType;//ԴIPv6��ַ��������
	union
	{
		ULONG  ulSrcIPv6Count;//һ������������ԴIPv6��ַ�ĸ���
		ULONG  ulSrcIPv6Last;//���������ԴIPv6��ַ��ĩβֵ
	};
	union
	{
		UCHAR  ucSrcIPv6ModBit;//ԴIPv6��ַҪ�����bitλ��ȡֵ��ΧΪ1--128
		UCHAR  ucSrcIPv6Offset;//���������ԴIPv6��ַ������ʼƫ��(4�ֽ�Ϊ��λ)��ȡֵ��ΧΪ0--3
	};
	UCHAR  ucSrcIPv6ModStep;//ԴIPv6��ַ����Ĳ�����ȡֵ��ΧΪ1--255

	UCHAR  ucaDstIPv6Addr[16];//Ŀ��IPv6��ַ
	ULONG  ulDstIPv6StepType;//Ŀ��IPv6��ַ��������
	union
	{
		ULONG  ulDstIPv6Count;//һ������������Ŀ��IPv6��ַ�ĸ���
		ULONG  ulDstIPv6Last;//���������Ŀ��IPv6��ַ��ĩβֵ
	};
	union
	{
		UCHAR  ucDstIPv6ModBit;//Ŀ��IPv6��ַҪ�����bitλ��ȡֵ��ΧΪ1--128
		UCHAR  ucDstIPv6Offset;//���������Ŀ��IPv6��ַ������ʼƫ��(4�ֽ�Ϊ��λ)��ȡֵ��ΧΪ0--3
	};
	UCHAR  ucDstIPv6ModStep;//Ŀ��IPv6��ַ����Ĳ�����ȡֵ��ΧΪ1--255
} IPV6_S;

typedef	struct tag_TCP//TCP�ײ�
{
	BOOL   bEdit;//�Ƿ�༭TCP�ײ�

	ULONG  ulSequenceNumber;//Sequence Number
	ULONG  ulAckNumber;//Acknowledge Number
	BOOL   bAutoHeaderLength;//�Ƿ��Զ����header length
	BOOL   bAutoChecksum;//�Ƿ���Ӳ���Զ���дTCPУ���
	UCHAR  ucHeaderLength;//header length��ȡֵ��ΧΪ0--15����bAutoHeaderLength==FALSE��Ч
	UCHAR  ucReserved;//reserved��ȡֵ��ΧΪ0--63
	UCHAR  ucFlag;//Flag��ȡֵ��ΧΪ0x00--0x3f
	USHORT usWindowSize;//Window Size;
	USHORT usChecksum;//TCPУ��ͣ���bAutoChcksm==FALSEʱ��Ч
	USHORT usUrgentPointer;//Urgent Pointer

	USHORT usSrcPort;//Դ�˿ں�
	ULONG  ulSrcPortStepType;//Դ�˿ں���������
	union
	{
		USHORT usSrcPortCount;//һ������������Դ�˿ںŵĸ���
		USHORT usSrcPortLast;//���������Դ�˿ںŵ�ĩβֵ
	};
	USHORT usSrcPortStep;//Դ�˿ں����䲽��

	USHORT usDstPort;//Ŀ�Ķ˿ں�
	ULONG  ulDstPortStepType;//Ŀ�Ķ˿ں���������
	union
	{
		USHORT usDstPortCount;//һ������������Ŀ�Ķ˿ںŵĸ���
		USHORT usDstPortLast;//���������Ŀ�Ķ˿ںŵ�ĩβֵ
	};
	USHORT usDstPortStep;//Ŀ�Ķ˿ں����䲽��
} TCP_S;

typedef	struct tag_UDP//UDP�ײ�
{
	BOOL   bEdit;//�Ƿ�༭UDP�ײ�

	BOOL   bAutoTotalLength;//�Ƿ���Ӳ���Զ���дUDP�ײ�total length�ֶ�
	BOOL   bAutoChecksum;//�Ƿ���Ӳ���Զ���дUDPУ���
	USHORT usTotalLength;//UDP�ײ���total length�ֶΣ���bAutoTotalLength==FALSEʱ��Ч
	USHORT usChecksum;//UDPУ��ͣ���bAutoChcksm==FALSEʱ��Ч

	USHORT usSrcPort;//Դ�˿ں�
	ULONG  ulSrcPortStepType;//Դ�˿ں���������
	union
	{
		USHORT usSrcPortCount;//һ������������Դ�˿ںŵĸ���
		USHORT usSrcPortLast;//���������Դ�˿ںŵ�ĩβֵ
	};
	USHORT usSrcPortStep;//Դ�˿ں����䲽��

	USHORT usDstPort;//Ŀ�Ķ˿ں�
	ULONG  ulDstPortStepType;//Ŀ�Ķ˿ں��Ƿ�����
	union
	{
		USHORT usDstPortCount;//һ������������Ŀ�Ķ˿ںŵĸ���
		USHORT usDstPortLast;//���������Ŀ�Ķ˿ںŵ�ĩβֵ
	};
	USHORT usDstPortStep;//Ŀ�Ķ˿ں����䲽��
} UDP_S;

typedef	struct tag_UDF//�û��Զ�������
{
	BOOL   bEdit;//�Ƿ�༭�û��Զ������ݣ���TraStreamCustomAdd������Ч
	USHORT usLen;//�û��Զ������ݳ��ȣ���С֧��34�ֽڣ����֧��128�ֽ�
	UCHAR  ucaData[256];//�û��Զ�����������
	BOOL   bChecksum;//�û��Զ����������Ƿ���У����ֶ�
	UCHAR  ucRso;//У��ͼ��㷶Χ����ʼ�ֽ�ƫ���������û��Զ������ݿ�ʼ���㣬0-based
	UCHAR  ucReo;//У��ͼ��㷶Χ�Ľ����ֽ�ƫ���������û��Զ������ݿ�ʼ���㣬0-based��0xFF��ʾ���������Ľ�β
	UCHAR  ucFso;//У����ֶε���ʼ�ֽ�ƫ���������û��Զ������ݿ�ʼ���㣬0-based
	UCHAR  ucVfdCount;//���û��Զ��������������ֶεĸ���
	struct VFD//�����ֶ�����
	{
		UCHAR  ucStartOffset;//�����ֶ���ʼ�ֽ�ƫ���������û��Զ������ݿ�ʼ���㣬0-based
		UCHAR  ucRange;//�����ֶ��ֶ���ռ���ֽ���
		UCHAR  ucOffsetType;//�����ֶ���ʼ�ֽ�ƫ�������ͣ���ȡTRA_VFD_OFFSET_UDF��TRA_VFD_OFFSET_STREAM��Ĭ��ΪTRA_VFD_OFFSET_UDF
		UCHAR  ucVfdId;//ʹ��TCL�ӿڱ༭��ʱ��VFD��Ψһ��ʶ������������޾�������
		ULONG  ulStepType;//��������
		ULONG  ulFirstValue;//�����ֶε���ʼֵ��0xFFFFFFFF��ʾȡָ��ƫ���ֶεĵ�ǰֵ�����������䷶Χ�������佫������Ч
		ULONG  ulStep;//�����ֶεĲ���
		union
		{
			ULONG ulCount;//һ����������������Ĵ���
			ULONG ulLastValue;//��������������ֶε�ĩβֵ
		};
	} arrVfd[6];
} UDF_S;


typedef	struct tag_PAYLOAD//����
{
	BOOL   bEdit;//�Ƿ�༭����
	UCHAR  ucType;//��������
	UCHAR  ucData;//���������ֽ�
} PAYLOAD_S;

typedef	struct tag_SIGNATURE_BLOCK//����ǩ��
{
	BOOL   bEdit;//�Ƿ�༭����ǩ��
	BOOL   bInclude;//�Ƿ��������ǩ��
} SIGNATURE_BLOCK_S;


typedef struct tag_STREAM
{
	USHORT    usRepeatCount;//������repeat count��������ģʽΪTRA_SCHEDULE_MODE_IFGʱ��Ч
	MAC_S     stMac;
	SNAP_S    stSnap;
	VLAN_S    stVlan;
	MPLS_S    stMpls;
	IPV4_S    stIpv4;
	IPV6_S    stIpv6;
	TCP_S     stTcp;
	UDP_S     stUdp;
	UDF_S	  stUdf;
	PAYLOAD_S stPayload;
	SIGNATURE_BLOCK_S stSignature;
} STREAM_S;


/********************************************
���ܣ�����ָ���˿ڵķ���ģʽ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucTxMode������ģʽ��
	            TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
	  		    TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		        TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		        TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	  ui64FramesPerBurst��ÿ��ͻ����֡������ucTxMode==TRA_TX_MODE_CONTINUOUS��Ч��ȱʡֵΪ100����ucTxMode==TRA_TX_MODE_TIME_BURSTʱ���ò�����ʾ����ʱ�䣬��λΪ�롣
	  ulBurstCount��ͻ����������ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��ȱʡֵΪ10��
	  ulInterBurstGap����������ͻ��֮��ļ������λΪ8ns����ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   ��Ч��ȱʡֵΪ1200������С����С֡�����
	                   TRA_TX_MODE_ON_STREAM��ʾ�������ĵķ���ģʽ 
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_TRANSMIT_MODE��ʾ����ķ���ģʽ����
ע�⣺�ڵ��øú���֮ǰĬ�Ϸ���ģʽΪTRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraSetPortTransmitMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, ULONG ulInterBurstGap);


/********************************************
���ܣ���ȡָ���˿ڵĵ�ǰ����ģʽ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pucTxMode������ģʽ��
	            TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
	  		    TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		        TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		        TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	  pui64FramesPerBurst��ÿ��ͻ����֡������ucTxMode==TRA_TX_MODE_CONTINUOUS��Ч��ȱʡֵΪ100����ucTxMode==TRA_TX_MODE_TIME_BURSTʱ���ò�����ʾ����ʱ�䣬��λΪ�롣
	  pulBurstCount��ͻ����������ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��ȱʡֵΪ10��
	  pulInterBurstGap����������ͻ��֮��ļ������λΪ8ns����ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   ��Ч��ȱʡֵΪ1200������С����С֡�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_TRANSMIT_MODE��ʾ����ķ���ģʽ����
ע�⣺�ڵ��øú���֮ǰĬ�Ϸ���ģʽΪTRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraGetPortTransmitMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTxMode,
		UINT64 *pui64FramesPerBurst, ULONG *pulBurstCount, ULONG *pulInterBurstGap);


/********************************************
���ܣ�����ָ���˿ڵķ���ģʽ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucTxMode������ģʽ��
	            TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
	  		    TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		        TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		        TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	  ui64FramesPerBurst��ÿ��ͻ����֡������ucTxMode==TRA_TX_MODE_CONTINUOUS��Ч��ȱʡֵΪ100����ucTxMode==TRA_TX_MODE_TIME_BURSTʱ���ò�����ʾ����ʱ�䣬��λΪ�롣
	  ulBurstCount��ͻ����������ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��ȱʡֵΪ10��
	  dbInterBurstGap����������ͻ��֮��ļ������λΪ8ns����ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   ��Ч��ȱʡֵΪ1200������С����С֡�����
	  ucInterBurstGapUnit��dbInterBurstGap�����ĵ�λ���ͣ���ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��
						 TRA_IBG_UNIT_TYPE_NONE��ʾ��λΪӲ��ʱ�Ӿ��ȣ�
						 TRA_IBG_UNIT_TYPE_NS��ʾ��λΪ���룬
						 TRA_IBG_UNIT_TYPE_US��ʾ��λΪ΢�룬
						 TRA_IBG_UNIT_TYPE_MS��ʾ��λΪ���룬
						 TRA_IBG_UNIT_TYPE_SEC��ʾ��λΪ�룬
						 TRA_IBG_UNIT_TYPE_BIT��ʾ��λΪ���ء�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_TRANSMIT_MODE��ʾ����ķ���ģʽ����
ע�⣺�ڵ��øú���֮ǰĬ�Ϸ���ģʽΪTRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraSetPortTransmitModeEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, double dbInterBurstGap, UCHAR ucInterBurstGapUnit);


/********************************************
���ܣ���ȡָ���˿ڵĵ�ǰ����ģʽ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pucTxMode������ģʽ��
	            TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
	  		    TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		        TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		        TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	  pui64FramesPerBurst��ÿ��ͻ����֡������ucTxMode==TRA_TX_MODE_CONTINUOUS��Ч��ȱʡֵΪ100����ucTxMode==TRA_TX_MODE_TIME_BURSTʱ���ò�����ʾ����ʱ�䣬��λΪ�롣
	  pulBurstCount��ͻ����������ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��ȱʡֵΪ10��
	  pdbInterBurstGap����������ͻ��֮��ļ������λΪ8ns����ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   ��Ч��ȱʡֵΪ1200������С����С֡�����
	  pucInterBurstGapUnit��dbInterBurstGap�����ĵ�λ���ͣ���ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��
						 TRA_IBG_UNIT_TYPE_NONE��ʾ��λΪӲ��ʱ�Ӿ��ȣ�
						 TRA_IBG_UNIT_TYPE_NS��ʾ��λΪ���룬
						 TRA_IBG_UNIT_TYPE_US��ʾ��λΪ΢�룬
						 TRA_IBG_UNIT_TYPE_MS��ʾ��λΪ���룬
						 TRA_IBG_UNIT_TYPE_SEC��ʾ��λΪ�룬
						 TRA_IBG_UNIT_TYPE_BIT��ʾ��λΪ���ء�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_TRANSMIT_MODE��ʾ����ķ���ģʽ����
ע�⣺�ڵ��øú���֮ǰĬ�Ϸ���ģʽΪTRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraGetPortTransmitModeEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTxMode,
		UINT64 *pui64FramesPerBurst, ULONG *pulBurstCount, double *pdbInterBurstGap, UCHAR *pucInterBurstGapUnit);


/********************************************
���ܣ�����ָ���˿ڵ������͵���ģʽ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucScheduleMode�������͵���ģʽ����ȡ��ֵΪ��TRA_SCHEDULE_MODE_IFG��TRA_SCHEDULE_MODE_FPS��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_SCHEDULE_MODE��ʾ����ĵ���ģʽ����
ע�⣺���øú���֮ǰ��Ĭ�ϵ���ģʽΪTRA_SCHEDULE_MODE_IFG
*********************************************/
COM_EXPORT ULONG TraSetPortScheduleMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucScheduleMode);



/********************************************
���ܣ�����ָ����̫���˿ڵ����ʡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucRateUnit�����ʵ�λ���ͣ���ȡ��ֵΪ��TRA_RATE_UNIT_TYPE_NS��TRA_RATE_UNIT_TYPE_FPS
	              TRA_RATE_UNIT_TYPE_ULT��TRA_RATE_UNIT_TYPE_DBS��TRA_RATE_UNIT_TYPE_FBS��
				  TRA_RATE_UNIT_TYPE_TBS��TRA_RATE_UNIT_TYPE_LBS��
	  dbRate������ֵ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾָ���˿ڲ�����̫���˿ڣ�
	  FD_ERROR_SCHEDULE_MODE����ָ���˿ڵ�������ģʽ����
	  TRA_ERROR_RATE_UNIT��ʾ�����ucRateUnit����
ע�⣺�ú����Ե���ģʽΪTRA_SCHEDULE_MODE_IFGʱ���ã�
      ����ģʽΪTRA_SCHEDULE_MODE_FPSʱ��ʹ�ú���
	  TraSetStreamRate�������е��١�
*********************************************/
COM_EXPORT ULONG TraSetEthernetPortRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucRateUnit, double dbRate);


/********************************************
���ܣ���ȡָ����̫���˿ڵĵ�ǰ���ʡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucRateUnit�����ʵ�λ���ͣ���ȡ��ֵΪ��TRA_RATE_UNIT_TYPE_NS��TRA_RATE_UNIT_TYPE_FPS
	              TRA_RATE_UNIT_TYPE_ULT��TRA_RATE_UNIT_TYPE_DBS��TRA_RATE_UNIT_TYPE_FBS��
				  TRA_RATE_UNIT_TYPE_TBS��TRA_RATE_UNIT_TYPE_LBS��
�����pdbRate������ֵָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾָ���˿ڲ�����̫���˿ڣ�
	  FD_ERROR_SCHEDULE_MODE����ָ���˿ڵ�������ģʽ����
	  TRA_ERROR_HAVE_NO_STREAM��ʾָ���˿���û������
	  TRA_ERROR_RATE_UNIT��ʾ�����ucRateUnit����
ע�⣺�ú����Ե���ģʽΪTRA_SCHEDULE_MODE_IFGʱ���á�
*********************************************/
COM_EXPORT ULONG TraGetEthernetPortRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucRateUnit, double *pdbRate);


/********************************************
���ܣ�ʹ�ܻ�ʹ��ָ���˿ڵ�������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  bEnable�� �Ƿ�ʹ�������ͣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraEnablePort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bEnable);


/********************************************
���ܣ�����ָ���˿ڷ���֡ʱ�Ƿ��CRC����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  bCrcError������ʱ�Ƿ�ʹ��CRC����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺��
*********************************************/
COM_EXPORT ULONG TraEnableCrcError(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bCrcError);


/********************************************
���ܣ�����ָ���˿ڷ���֡ʱ���ɵĴ�������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulErrorMask�������������룬��ȡTRA_ERROR_CRC��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺��
*********************************************/
COM_EXPORT ULONG TraSetPortError(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulErrorMask);


/********************************************
���ܣ���ָ���˿�����������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  ucFrameType��������֡���ͣ���ȡֵΪ��TRA_PRO_TYPE_IPV4��TRA_PRO_TYPE_IPV6��TRA_PRO_TYPE_TCP��TRA_PRO_TYPE_UDP��
	               TRA_PRO_TYPE_TCP6��TRA_PRO_TYPE_UDP6��
	  usRepeatCount���������͵��ظ�������������ģʽΪTRA_SCHEDULE_MODE_IFGʱ��Ч��ȡֵ��ΧΪ1--65535��
	  ucLenType�������ĳ������ͣ���ȡֵΪ��TRA_LEN_TYPE_FIXED��TRA_LEN_TYPE_RANDOM��
	             TRA_LEN_TYPE_INCR��
	  usMinLen��������Сֵ(������β��CRC�ֽ�)��
	  usMaxLen���������ֵ(������β��CRC�ֽ�)����ucFrameType==TRA_LEN_TYPE_FIXED��Ч��
	  bIncludeSignatureBlock�������Ƿ����ǩ�飻
	  ucPayloadType���������͡���ȡֵΪ��TRA_PAY_TYPE_CYCLE��TRA_PAY_TYPE_INCR��TRA_PAY_TYPE_RANDOM��
	  ucPayloadByte�������ֽڣ�
	  ucL2Type���������ͣ�0��ʾ��̫������1��ʾLLC/SNAP������̫���˿���Ч��
	  ui64SrcMac��ԴMAC��ַ��
	  ui64DstMac��Ŀ��MAC��ַ��
	  ulIPv4SrcAddr��IPv4Դ��ַ����ucFrameTypeΪTRA_PRO_TYPE_IPV4��TRA_PRO_TYPE_TCP��TRA_PRO_TYPE_UDPʱ��Ч��
	  ulIPv4DstAddr��IPv4Ŀ�ĵ�ַ����ucFrameTypeΪTRA_PRO_TYPE_IPV4��TRA_PRO_TYPE_TCP��TRA_PRO_TYPE_UDPʱ��Ч��
	  pucIPv6SrcAddr��IPv6Դ16�ֽڵ�ַָ�롣��ucFrameTypeΪTRA_PRO_TYPE_IPV6��TRA_PRO_TYPE_TCP6��TRA_PRO_TYPE_UDP6ʱ��Ч��
	  pucIPv6DstAddr��IPv6Ŀ��16�ֽڵ�ַָ�롣��ucFrameTypeΪTRA_PRO_TYPE_IPV6��TRA_PRO_TYPE_TCP6��TRA_PRO_TYPE_UDP6ʱ��Ч��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_EXIST_SAME_STREAM_NAME��ʾ������ͬ��������
	  TRA_ERROR_FRAME_TYPE��ʾ�����֡���ʹ���
	  TRA_ERROR_LENGTH_TYPE��ʾ����ĳ������ʹ���
	  TRA_ERROR_PAYLOAD_TYPE��ʾ����ľ������ʹ���
      TRA_ERROR_EXCEED_MAX_STREAM_COUNT��ʾ�����ö˿ڿ��õ��������Ŀ��
	  TRA_ERROR_EXCEED_FULL_BANDWIDTH��ʾ�����ö˿ڵ�������
ע�⣺Ҫ�������и����ӵ��������ڵ��øú������ٵ��ú���TraEditStream��
*********************************************/
COM_EXPORT ULONG TraAddStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char* pcStreamName, UCHAR ucFrameType, 
	USHORT usRepeatCount, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen, BOOL bIncludeSignatureBlock, 
	UCHAR ucPayloadType, UCHAR ucPayloadByte, UCHAR ucL2Type, UINT64 ui64PortMac, UINT64 ui64DutMac,
	ULONG ulIPv4SrcAddr, ULONG ulIPv4DstAddr, UCHAR *pucIPv6SrcAddr, UCHAR *pucIPv6DstAddr);


/********************************************
���ܣ���ָ���˿��������û��Զ�������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pcStreamName�������ƣ�
	  usRepeatCount���������͵��ظ�������������ģʽΪTRA_SCHEDULE_MODE_IFGʱ��Ч��ȡֵ��ΧΪ1--65535��
	  ucLenType�������ĳ������ͣ���ȡֵΪ��TRA_LEN_TYPE_FIXED��TRA_LEN_TYPE_RANDOM��
	             TRA_LEN_TYPE_INCR��
	  usMinLen��������Сֵ(������β��CRC�ֽ�)��������̫�����Զ˿ڣ�
	            ����ǩ�����������Сֵ����С��24�ֽڣ�������ǩ���
				����Сֵ����С��4�ֽڣ�����POS���Զ˿ڣ�����ǩ���
				��������Сֵ����С��24�ֽڣ�������ǩ�������Сֵ����
				С��4�ֽڣ�
	  usMaxLen���������ֵ(������β��CRC�ֽ�)����ucFrameType==TRA_LEN_TYPE_FIXED��Ч��
	  bIncludeSignatureBlock�������Ƿ����ǩ�飻
	  ucPayloadType���������͡���ȡֵΪ��TRA_PAY_TYPE_CYCLE��TRA_PAY_TYPE_INCR��TRA_PAY_TYPE_RANDOM��
	  ucPayloadByte�������ֽڣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_EXIST_SAME_STREAM_NAME��ʾ������ͬ��������
	  TRA_ERROR_LENGTH_TYPE��ʾ����ĳ������ʹ���
	  TRA_ERROR_PAYLOAD_TYPE��ʾ����ľ������ʹ���
      TRA_ERROR_EXCEED_MAX_STREAM_COUNT��ʾ�����ö˿ڿ��õ��������Ŀ��
	  TRA_ERROR_EXCEED_FULL_BANDWIDTH��ʾ�����ö˿ڵ�������
	  TRA_ERROR_STREAM_LENGTH��ʾ�����������ô���
	  TRA_ERROR_STREAM_UDF_LENGTH��ʾ�û��Զ������ݳ��ȴ���
	  TRA_ERROR_STREAM_UDF_CHECKSUM��ʾ�û��Զ��������е�У������ô���
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP��ʾ�û��Զ��������ж�������ֶεķ�Χ�ص���
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP��ʾ�û��Զ���������У����ֶκ������ֶ��ص���
	  FD_ERROR_EXCEED_MAX_VFD_VALUE��ʾ�����ֶ�ֵ������������ֵ��
	  TRA_ERROR_STREAM_UDF��ʾ�û��Զ����������ô���
	  TRA_ERROR_STEP_TYPE��ʾ�����ֶε������������ô���
ע�⣺Ҫ���û��Զ��������б༭���ڵ��øú������ٵ��ú���TraEditStream��
*********************************************/
COM_EXPORT ULONG TraAddCustomStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char* pcStreamName, UDF_S *pUdf, 
	USHORT usRepeatCount, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen, BOOL bIncludeSignatureBlock, 
	UCHAR ucPayloadType, UCHAR ucPayloadByte);


/********************************************
���ܣ�����ָ�����ĳ��ȡ�
���룺pcStreamName��Ҫ���б༭���������ƣ�
	  ucLenType�������ĳ������ͣ���ȡֵΪ��TRA_LEN_TYPE_FIXED��TRA_LEN_TYPE_RANDOM��
	             TRA_LEN_TYPE_INCR��
	  usMinLen��������Сֵ(������β��CRC�ֽ�)��������̫�����Զ˿ڣ�
	            ����ǩ�����������Сֵ����С��24�ֽڣ�������ǩ���
				����Сֵ����С��4�ֽڣ�����POS���Զ˿ڣ�����ǩ���
				��������Сֵ����С��24�ֽڣ�������ǩ�������Сֵ����
				С��4�ֽڣ�
	  usMaxLen���������ֵ(������β��CRC�ֽ�)����ucFrameType==TRA_LEN_TYPE_FIXED��Ч��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
	  FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  TRA_ERROR_LENGTH_TYPE��ʾ����ĳ������ʹ���
	  TRA_ERROR_STREAM_LENGTH��ʾ�����������ô���
	  FD_ERROR��ʾ��������
ע�⣺�˺���ֻ��ı�����Payload���ֵĳ��ȣ������ó���С�ڵ�ǰ���ȣ���Payload���ֵĳ���С�����ߵĲ�ֵʱ������TRA_ERROR_STREAM_LENGTH����
*********************************************/
COM_EXPORT ULONG TraSetStreamLength(const char *pcStreamName, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen);


/********************************************
���ܣ��ж�ָ�������Ƿ���ڡ�
���룺pcStreamName��ָ���������ƣ�      
�������
���أ������򷵻�TRUE(1)���������򷵻�FALSE(0)��
ע�⣺
*********************************************/
COM_EXPORT BOOL TraStreamExists(const char *pcStreamName);


/********************************************
���ܣ���ȡָ���������ݽṹ��
���룺pcStreamName��ָ���������ƣ�
�����ps: ָ�������ݽṹָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetStreamParams(const char* pcStreamName, STREAM_S *ps);


/********************************************
���ܣ���ȡָ������ͷ�����ݡ�
���룺pcStreamName��ָ���������ƣ�      
�����pucData: ָ����ͷ������ָ��
      pulLen��ָ����ͷ�����ݳ���ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetStreamHeaderData(const char *pcStreamName, UCHAR *pucData, ULONG *pulLen);


/********************************************
���ܣ���ȡָ������ͷ�����ݳ��ȡ�
���룺pcStreamName��ָ���������ƣ�      
�����pulLen��ָ����ͷ�����ݳ���ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetStreamHeaderLength(const char *pcStreamName, ULONG *pulLen);


/********************************************
���ܣ���ȡָ���������ݳ��ȡ�
���룺pcStreamName��ָ���������ƣ�      
�����pulLen��ָ�������ݳ���ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetStreamLength(const char *pcStreamName, ULONG *pulLen);


/********************************************
���ܣ���ָ���������б༭��
���룺pcStreamName��Ҫ���б༭���������ƣ�
      pStreamEdit��Ҫ�༭��������ָ��;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  TRA_ERROR_STREAM_LENGTH��ʾ����ԭ�����õĳ��Ȳ�����֧�������ı༭��
	  TRA_ERROR_EXCEED_STREAM_HEADER_LENGTH��ʾ���ײ����ȳ������ֵ��
	  FD_ERROR_EXCEED_MAX_MAC_ADDRESS��ʾMAC��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾIPv4��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS��ʾIPv6��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_PORT��ʾTCP��UDP�˿ںų������ֵ��
	  FD_ERROR_EXCEED_MAX_VLAN_ID��ʾVLAN ID�������ֵ��
	  FD_ERROR_EXCEED_MAX_MPLS_LABEL��ʾMPLS Label�������ֵ��
	  FD_ERROR_EXCEED_MAX_FLOW_LABEL��ʾIPv6�ײ���Flow Label�������ֵ��
	  TRA_ERROR_STREAM_UDF_LENGTH��ʾ�û��Զ������ݳ��ȴ���
	  TRA_ERROR_STREAM_UDF_CHECKSUM��ʾ�û��Զ��������е�У������ô���
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP��ʾ�û��Զ��������ж�������ֶεķ�Χ�ص���
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP��ʾ�û��Զ���������У����ֶκ������ֶ��ص���
	  FD_ERROR_EXCEED_MAX_VFD_VALUE��ʾ�����ֶ�ֵ������������ֵ��
	  TRA_ERROR_STREAM_UDF��ʾ�û��Զ����������ô���
	  TRA_ERROR_STREAM_PAYLOAD_TYPE��ʾ����ľ������ʹ���
	  TRA_ERROR_EXCEED_MAX_VFD_COUNT��ʾ�����ֶθ����������ֵ��
	  TRA_ERROR_EXCEED_MAX_CS_COUNT��ʾ�Զ�У��͸����������ֵ��
	  TRA_ERROR_STEP_TYPE��ʾ�����ֶε������������ô���
ע�⣺�ú������ܸı�ָ���������͡���ԭ����IPv4���������øú����༭ΪIPv6����
*********************************************/
COM_EXPORT ULONG TraEditStream(const char* pcStreamName, STREAM_S *pStreamEdit);

/********************************************
���ܣ���ָ���������б༭��
���룺pcStreamName��Ҫ���б༭���������ƣ�
      ui64SrcMac;//ԴMAC��ַ
      ULONG  ulSrcMacCount;//һ������������ԴMAC��ַ�ĸ���
	UCHAR  ucSrcMacModBit;//ԴMAC��ַҪ�����bitλ��ȡֵ��ΧΪ33--48
	UCHAR  ucSrcMacModStep;//ԴMAC��ַ����Ĳ�����ȡֵ��ΧΪ1--255
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  TRA_ERROR_STREAM_LENGTH��ʾ����ԭ�����õĳ��Ȳ�����֧�������ı༭��
	  TRA_ERROR_EXCEED_STREAM_HEADER_LENGTH��ʾ���ײ����ȳ������ֵ��
	  FD_ERROR_EXCEED_MAX_MAC_ADDRESS��ʾMAC��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾIPv4��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS��ʾIPv6��ַ�������ֵ��
	  FD_ERROR_EXCEED_MAX_PORT��ʾTCP��UDP�˿ںų������ֵ��
	  FD_ERROR_EXCEED_MAX_VLAN_ID��ʾVLAN ID�������ֵ��
	  FD_ERROR_EXCEED_MAX_MPLS_LABEL��ʾMPLS Label�������ֵ��
	  FD_ERROR_EXCEED_MAX_FLOW_LABEL��ʾIPv6�ײ���Flow Label�������ֵ��
	  TRA_ERROR_STREAM_UDF_LENGTH��ʾ�û��Զ������ݳ��ȴ���
	  TRA_ERROR_STREAM_UDF_CHECKSUM��ʾ�û��Զ��������е�У������ô���
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP��ʾ�û��Զ��������ж�������ֶεķ�Χ�ص���
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP��ʾ�û��Զ���������У����ֶκ������ֶ��ص���
	  FD_ERROR_EXCEED_MAX_VFD_VALUE��ʾ�����ֶ�ֵ������������ֵ��
	  TRA_ERROR_STREAM_UDF��ʾ�û��Զ����������ô���
	  TRA_ERROR_STREAM_PAYLOAD_TYPE��ʾ����ľ������ʹ���
	  TRA_ERROR_EXCEED_MAX_VFD_COUNT��ʾ�����ֶθ����������ֵ��
	  TRA_ERROR_EXCEED_MAX_CS_COUNT��ʾ�Զ�У��͸����������ֵ��
	  TRA_ERROR_STEP_TYPE��ʾ�����ֶε������������ô���
ע�⣺�ú������ܸı�ָ���������͡���ԭ����IPv4���������øú����༭ΪIPv6����
*********************************************/
COM_EXPORT ULONG TraEditStreamSrcMac(const char* pcStreamName,UINT64 ui64SrcMac,ULONG  ulSrcMacCount,UCHAR  ucSrcMacModBit,UCHAR  ucSrcMacModStep);

/********************************************
���ܣ���ȡָ���˿�������ӵ�������Ŀ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pulStreamCount: ָ���˿ڵ�����Ŀ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetPortStreamCount(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG* pulCount);


/********************************************
���ܣ�ɾ��ָ������
���룺pcStreamName��Ҫɾ�����������ƣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraRemoveStream(const char* pcStreamName);


/********************************************
���ܣ�ɾ��ָ���˿�����������ӵ���
���룺ulChsId�� Ŀ�Ļ���ID��1-based��
      ulSlotId��Ŀ�Ĳ�λ�ţ�1-based;
	  ulPortId��Ŀ�Ķ˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  TRA_ERROR_TRANSMITING��ʾ���ڽ��з��ͣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraRemoveStreams(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ�ʹ�ܻ�ʹ��ָ������
���룺pcStreamName��Ҫʹ�ܵ��������ƣ�
      bEnable���Ƿ�ʹ��ָ��������
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraEnableStream(const char* pcStreamName, BOOL bEnable);


/********************************************
���ܣ�����򲻼���ָ�����������ڷǼ���״̬��������ͣ����
���룺pcStreamName��Ҫʹ�ܵ��������ƣ�
      bActive���Ƿ񼤻�ָ��������
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraActiveStream(const char* pcStreamName, BOOL bActive);


/********************************************
���ܣ���ָ���������е���
���룺pcStreamName��Ҫʹ�ܵ��������ƣ�
      ucRateUnit�����ʵ�λ���ͣ�0��ʾFrames/Sec����0��ʾ����ٷֱȣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  FD_ERROR_SCHEDULE_MODE����ָ���˿ڵ�������ģʽ����
ע�⣺�ú����Ե���ģʽΪTRA_SCHEDULE_MODE_FPSʱ���ã�
      ����ģʽΪTRA_SCHEDULE_MODE_IFGʱ��ʹ�ú���
	  TraSetPortRate�������е��١�
*********************************************/
COM_EXPORT ULONG TraSetStreamRate(const char* pcStreamName, UCHAR ucRateUnit, double dbRate);

/********************************************
���ܣ���ָ�������ķ���ģʽ��������
���룺pcStreamName��Ҫʹ�ܵ��������ƣ�
       ucTxMode������ģʽ��
	            TRA_TX_MODE_CONTINUOUS��ʾ�������ͣ�
	  		    TRA_TX_MODE_SINGLE_BURST��ʾ����ͻ����
		        TRA_TX_MODE_MULTI_BURST��ʾ���ͻ��
		        TRA_TX_MODE_TIME_BURST��ʾ��ʱ�䷢��
	  ui64FramesPerBurst��ÿ��ͻ����֡������ucTxMode==TRA_TX_MODE_CONTINUOUS��Ч��ȱʡֵΪ100����ucTxMode==TRA_TX_MODE_TIME_BURSTʱ���ò�����ʾ����ʱ�䣬��λΪ�롣
	  ulBurstCount��ͻ����������ucTxMode==TRA_TX_MODE_MULTI_BURST��Ч��ȱʡֵΪ10��
	  ulInterBurstGap����������ͻ��֮��ļ������λΪ8ns����ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   ��Ч��ȱʡֵΪ1200������С����С֡�����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  TRA_ERROR_TRANSMITING��ʾ���ڷ��ͣ�
      FD_ERROR_STREAM_NAME��ʾ�����pcStreamName����
	  FD_ERROR_SCHEDULE_MODE����ָ���˿ڵ�������ģʽ����
ע�⣺�˿ڵķ���ģʽΪ RA_TX_MODE_ON_STREAM ��Ч
*********************************************/
COM_EXPORT ULONG TraSetStreamTransmitMode(const char* pcStreamName, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, ULONG ulInterBurstGap);


/********************************************
���ܣ���ȡָ����̫���˿ڵ�IPv4Э��ջ��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pui64PortMacAddr: ָ���˿ڵ�MAC��ַָ�룻
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetPortMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64PortMacAddr);


/********************************************
���ܣ���ȡָ����̫���˿ڵ�IPv4Э��ջ��DUT(�����豸)��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pui64DutMacAddr: DUT��MAC��ַָ�룬*pui64DutMacAddr==0��ʾ��ȡʧ�ܣ�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
���ܣ���ȡָ����̫���˿ڵ�IPv4Э��ջ��DUT(�����豸)��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulWaitTime����ȡʧ��ʱ�ĵȴ�ʱ�䣬��λΪ���룻
�����pui64DutMacAddr: DUT��MAC��ַָ�룬*pui64DutMacAddr==0��ʾ��ȡʧ�ܣ�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr, ULONG ulWaitTime);


/********************************************
���ܣ�ͨ��ָ����DUT(�����豸)IP��ַ��ȡָ����̫���˿ڵ�IPv4Э��ջ��DUT(�����豸)��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulDutIp��DUT��IP��ַ
�����pui64DutMacAddr: DUT��MAC��ַָ�룬*pui64DutMacAddr==0��ʾ��ȡʧ�ܣ�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressByIP(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulDutIp, UINT64 *pui64DutMacAddr);


/********************************************
���ܣ�ͨ��ָ����DUT(�����豸)IP��ַ��ȡָ����̫���˿ڵ�IPv6Э��ջ��DUT(�����豸)��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucDutIpv6��DUT��IPv6��ַ
�����pui64DutMacAddr: DUT��MAC��ַָ�룬*pui64DutMacAddr==0��ʾ��ȡʧ�ܣ�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressByIPV6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucDutIpv6, UINT64 *pui64DutMacAddr);


/********************************************
���ܣ���ȡָ����̫���˿ڵ�IPv6Э��ջ��DUT(�����豸)��MAC��ַ
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pui64DutMacAddr: DUT��MAC��ַָ�룬*pui64DutMacAddr==0��ʾ��ȡʧ�ܣ�
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressV6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
���ܣ���ȡָ����̫���˿ڵ�IPv4Э��ջ�Ķ��DUT(�����豸)��MAC��ַ������ַӳ��ģʽ��one to oneʱ����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pui64DutMacAddr: DUT��MAC��ַָ�룬ָ����ָ��ַ��Ŷ��DUT MAC��ַ����ַ����Ϊ�ö˿�IP��ַ������Ӧ����Ŀ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���˿ڵĽӿڿ���û��Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG TraGetMultiDutMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
���ܣ���ʼָ���˿ڵķ���
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
ע�⣺�ڶ˿���Ҫͬʱ����������ͳ��ʱ��Ӧ�ȿ���ͳ���ٿ�������
*********************************************/
COM_EXPORT ULONG TraStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ�ָֹͣ���˿ڵķ���
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
COM_EXPORT ULONG TraStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ��ж�ָ���˿��Ƿ����ڷ���
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  nType��������ͣ�0��ʾ��Ȿ�ز���״̬��1��ʾ������������״̬��
�����pbTesting��TRUE(1)��ʾ���ڷ��ͣ�FALSE(0)��ʾ����δ����;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);
#endif


/********************************************
���ܣ�����������
���룺��
�������
���أ���
ע�⣺
*********************************************/
COM_EXPORT void TraStart();


/********************************************
���ܣ�ֹͣ������
���룺��
�������
���أ���
ע�⣺
*********************************************/
COM_EXPORT void TraStop();

/********************************************
���ܣ����ö˿ڵ�PayloadMap
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG TraSetPortBitErrorMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId ,BOOL bEnable,UCHAR ucData[16]);
#endif


#ifdef __FOR_CSHARP
}
#endif

