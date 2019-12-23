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
	TRA_RATE_UNIT_TYPE_NS = 0,//帧间隔，以纳秒为单位
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
	TRA_LEN_TYPE_FIXED = 0, //表示长度固定
	TRA_LEN_TYPE_RANDOM, //表示长度随机
	TRA_LEN_TYPE_INCR,//表示长度递增
	TRA_LEN_TYPE_ALTERNATE,//表示最大最小交替，仅支持P系列板卡
	TRA_LEN_TYPE_DECR//表示长度递减，仅支持40G板卡
};

//时间戳的位置
enum {
	TRA_TIME_STAMP_HEAD = 0,
	TRA_TIME_STAMP_TAIL = 1
};

//Payload的类型
enum {
	TRA_PAY_TYPE_CYCLE = 0, 
	TRA_PAY_TYPE_INCR,
	TRA_PAY_TYPE_RANDOM,
	TRA_PAY_TYPE_UDF,
};

//跳变字段的跳变类型
enum{
	TRA_STEP_TYPE_NONE = 0,//表示不跳变
	TRA_STEP_TYPE_INCR,//表示递增跳变
	TRA_STEP_TYPE_RANDOM,//表示范围随机跳变
	TRA_STEP_TYPE_DECR//表示递减跳变
};

enum {
	TRA_VFD_OFFSET_UDF = 0, //表示跳变偏移从UDF起始位置开始计算
	TRA_VFD_OFFSET_STREAM   //表示跳变偏移从流起始位置开始计算
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
	BOOL   bEdit;//是否编辑MAC地址

	UINT64 ui64SrcMac;//源MAC地址
	ULONG   ulSrcMacStepType;//源MAC地址跳变类型
	union
	{
		ULONG  ulSrcMacCount;//一个跳变周期中源MAC地址的个数
		ULONG  ulSrcMacLast;//随机跳变中源MAC地址的末尾值
	};
	UCHAR  ucSrcMacModBit;//源MAC地址要跳变的bit位，取值范围为17--48
	UCHAR  ucSrcMacModStep;//源MAC地址跳变的步长，取值范围为1--255

	UINT64 ui64DstMac;//目的MAC地址
	ULONG   ulDstMacStepType;//目的MAC地址跳变类型
	union
	{
		ULONG  ulDstMacCount;//一个跳变周期中目的MAC地址的个数
		ULONG  ulDstMacLast;//随机跳变中目的MAC地址的末尾值
	};
	UCHAR  ucDstMacModBit;//目的MAC地址要跳变的bit位，取值范围为17--48
	UCHAR  ucDstMacModStep;//目的MAC地址跳变的步长，取值范围为1--255
} MAC_S;

typedef struct tag_SNAP
{
	BOOL   bEdit;//是否编辑SNAP
	UCHAR  ucDsap;//DSAP
	UCHAR  ucSsap;//SSAP
	UCHAR  ucCtrl;//Control Field
	ULONG  ulOui;//Organization Code, 取值范围为0x0--0xffffff
} SNAP_S;

typedef struct tag_VLAN
{
	BOOL   bEdit;//是否编辑VLAN
	BOOL   bEnable;//是否使能VLAN
	UCHAR  ucVlanCount;//VLAN的层数
	struct VLAN_VALUE
	{
		USHORT usTpid;//TPID
		UCHAR  ucPri;//PRI
		UCHAR  ucCfi;//CFI
		USHORT usVlanId;//VLAN ID
		ULONG  ulVlanIdStepType;//VLAN ID跳变类型
		union
		{
			USHORT usVlanIdCount;//一个跳变周期中目的VLAN ID的个数
			USHORT usVlanIdLast;//随机跳变中VLAN ID的末尾值
		};
		USHORT usVlanIdStep;//VLAN ID的跳变步长
	} arrVlanVal[6];
} VLAN_S;

typedef	struct tag_MPLS
{
	BOOL   bEdit;//是否编辑MPLS
	BOOL   bEnable;//是否使能MPLS
	UCHAR  ucMplsCount;//MPLS的层数
	struct MPLS_VALUE
	{
		UCHAR  ucExp;//EXP
		UCHAR  ucTtl;//TTL
		ULONG  ulLabel;//MPLS label
		ULONG  ulLabelStepType;//label跳变类型
		union
		{
			ULONG  ulLabelCount;//一个跳变周期中目的label的个数
			ULONG  ulLabelLast;//随机跳变中label的末尾值
		};
		ULONG  ulLabelStep;//label的跳变步长
	} arrMplsVal[6];
} MPLS_S;


typedef	struct tag_IPV4//IPv4首部
{
	BOOL   bEdit;//是否编辑IPv4首部

	BOOL   bAutoVersion;//是否自动填充version
	UCHAR  ucVersion;//version，取值范围为0--15，当bAutoVersion==FALSE时有效
	BOOL   bAutoHeaderLength;//是否自动填充header length
	UCHAR  ucHeaderLength;//header length，取值范围为0--15，当bAutoHeaderLength==FALSE有效
	UCHAR  ucTos;//TOS
	UCHAR  ucFlag;//flag，取值范围为0--7
	USHORT usFragmentOffset;//fragment offset，取值范围为0--8191
	UCHAR  ucTtl;//TTL
	UCHAR  ucProtocol;//protocol
	BOOL   bAutoTotalLength;//是否由硬件自动填写IPv4首部total length字段
	USHORT usTotalLength;//IPv4首部的total length字段，当bAutoTotalLength==FALSE时生效
	BOOL   bAutoChcksm;//是否由硬件自动填写IPv4首部校验和
	USHORT usChecksum;//IPv4首部校验和，当bAutoChcksm==FALSE时生效

	USHORT usIdentification;//identification
	ULONG  ulIdStepType;//identification跳变类型
	union
	{
		USHORT usIdCount;//一个跳变周期中identification的个数
		USHORT usIdLast;//随机跳变中identification的末尾值
	};
	USHORT usIdStep;//identification的跳变步长

	ULONG  ulSrcIPv4Addr;//源IPv4地址
	ULONG  ulSrcIPv4StepType;//源IPv4地址跳变类型
	union
	{
		ULONG  ulSrcIPv4Count;//一个跳变周期中源IPv4地址的个数
		ULONG  ulSrcIPv4Last;//随机跳变中源IPv4地址的末尾值
	};
	UCHAR  ucSrcIPv4ModBit;//源IPv4地址要跳变的bit位，取值范围为1--32
	UCHAR  ucSrcIPv4ModStep;//源IPv4地址跳变的步长，取值范围为1--255

	ULONG  ulDstIPv4Addr;//目的IPv4地址
	ULONG  ulDstIPv4StepType;//目的IPv4地址跳变类型
	union
	{
		ULONG  ulDstIPv4Count;//一个跳变周期中目的IPv4地址的个数
		ULONG  ulDstIPv4Last;//随机跳变中目的IPv4地址的末尾值
	};
	UCHAR  ucDstIPv4ModBit;//目的IPv4地址要跳变的bit位，取值范围为1--32
	UCHAR  ucDstIPv4ModStep;//目的IPv4地址跳变的步长，取值范围为1--255

	UCHAR  ucOptionLength;//IPv4首部可选项的长度，取值范围为0--40
	UCHAR  ucaOption[40];//IPv4首部可选项的字节内容
} IPV4_S;

typedef	struct tag_IPV6//IPv6首部
{
	BOOL   bEdit;//是否编辑IPv6首部

	BOOL   bAutoVersion;//是否自动填充version
	UCHAR  ucVersion;//version，取值范围为0--15，当bAutoVersion==FALSE时有效
	UCHAR  ucTrafficClass;//Traffic Class
	UCHAR  ucNextHeader;//Next Header
	UCHAR  ucHopLimit;//Hop Limit
	BOOL   bAutoPayloadLength;//是否由硬件自动填写Payload Length字段
	USHORT usPayloadLength;//Payload Length，当bAutoPayloadLength==FALSE生效

	ULONG  ulFlowLabel;//Flow Label
	ULONG  ulFlowLabelStepType;//Flow Label字段跳变类型
	union
	{
		ULONG  ulFlowLabelCount;//一个跳变周期中Flow Label的个数
		ULONG  ulFlowLabelLast;//随机跳变中Flow Label的末尾值
	};
	ULONG  ulFlowLabelStep;//Flow Label跳变的步长

	UCHAR  ucaSrcIPv6Addr[16];//源IPv6地址
	ULONG  ulSrcIPv6StepType;//源IPv6地址跳变类型
	union
	{
		ULONG  ulSrcIPv6Count;//一个跳变周期中源IPv6地址的个数
		ULONG  ulSrcIPv6Last;//随机跳变中源IPv6地址的末尾值
	};
	union
	{
		UCHAR  ucSrcIPv6ModBit;//源IPv6地址要跳变的bit位，取值范围为1--128
		UCHAR  ucSrcIPv6Offset;//随机跳变中源IPv6地址跳变起始偏移(4字节为单位)，取值范围为0--3
	};
	UCHAR  ucSrcIPv6ModStep;//源IPv6地址跳变的步长，取值范围为1--255

	UCHAR  ucaDstIPv6Addr[16];//目的IPv6地址
	ULONG  ulDstIPv6StepType;//目的IPv6地址跳变类型
	union
	{
		ULONG  ulDstIPv6Count;//一个跳变周期中目的IPv6地址的个数
		ULONG  ulDstIPv6Last;//随机跳变中目的IPv6地址的末尾值
	};
	union
	{
		UCHAR  ucDstIPv6ModBit;//目的IPv6地址要跳变的bit位，取值范围为1--128
		UCHAR  ucDstIPv6Offset;//随机跳变中目的IPv6地址跳变起始偏移(4字节为单位)，取值范围为0--3
	};
	UCHAR  ucDstIPv6ModStep;//目的IPv6地址跳变的步长，取值范围为1--255
} IPV6_S;

typedef	struct tag_TCP//TCP首部
{
	BOOL   bEdit;//是否编辑TCP首部

	ULONG  ulSequenceNumber;//Sequence Number
	ULONG  ulAckNumber;//Acknowledge Number
	BOOL   bAutoHeaderLength;//是否自动填充header length
	BOOL   bAutoChecksum;//是否由硬件自动填写TCP校验和
	UCHAR  ucHeaderLength;//header length，取值范围为0--15，当bAutoHeaderLength==FALSE有效
	UCHAR  ucReserved;//reserved，取值范围为0--63
	UCHAR  ucFlag;//Flag，取值范围为0x00--0x3f
	USHORT usWindowSize;//Window Size;
	USHORT usChecksum;//TCP校验和，当bAutoChcksm==FALSE时生效
	USHORT usUrgentPointer;//Urgent Pointer

	USHORT usSrcPort;//源端口号
	ULONG  ulSrcPortStepType;//源端口号跳变类型
	union
	{
		USHORT usSrcPortCount;//一个跳变周期中源端口号的个数
		USHORT usSrcPortLast;//随机跳变中源端口号的末尾值
	};
	USHORT usSrcPortStep;//源端口号跳变步长

	USHORT usDstPort;//目的端口号
	ULONG  ulDstPortStepType;//目的端口号跳变类型
	union
	{
		USHORT usDstPortCount;//一个跳变周期中目的端口号的个数
		USHORT usDstPortLast;//随机跳变中目的端口号的末尾值
	};
	USHORT usDstPortStep;//目的端口号跳变步长
} TCP_S;

typedef	struct tag_UDP//UDP首部
{
	BOOL   bEdit;//是否编辑UDP首部

	BOOL   bAutoTotalLength;//是否由硬件自动填写UDP首部total length字段
	BOOL   bAutoChecksum;//是否由硬件自动填写UDP校验和
	USHORT usTotalLength;//UDP首部的total length字段，当bAutoTotalLength==FALSE时生效
	USHORT usChecksum;//UDP校验和，当bAutoChcksm==FALSE时生效

	USHORT usSrcPort;//源端口号
	ULONG  ulSrcPortStepType;//源端口号跳变类型
	union
	{
		USHORT usSrcPortCount;//一个跳变周期中源端口号的个数
		USHORT usSrcPortLast;//随机跳变中源端口号的末尾值
	};
	USHORT usSrcPortStep;//源端口号跳变步长

	USHORT usDstPort;//目的端口号
	ULONG  ulDstPortStepType;//目的端口号是否跳变
	union
	{
		USHORT usDstPortCount;//一个跳变周期中目的端口号的个数
		USHORT usDstPortLast;//随机跳变中目的端口号的末尾值
	};
	USHORT usDstPortStep;//目的端口号跳变步长
} UDP_S;

typedef	struct tag_UDF//用户自定义数据
{
	BOOL   bEdit;//是否编辑用户自定义数据，对TraStreamCustomAdd函数无效
	USHORT usLen;//用户自定义数据长度，最小支持34字节，最大支持128字节
	UCHAR  ucaData[256];//用户自定义数据内容
	BOOL   bChecksum;//用户自定义数据里是否有校验和字段
	UCHAR  ucRso;//校验和计算范围的起始字节偏移量，从用户自定义数据开始计算，0-based
	UCHAR  ucReo;//校验和计算范围的结束字节偏移量，从用户自定义数据开始计算，0-based，0xFF表示计算至报文结尾
	UCHAR  ucFso;//校验和字段的起始字节偏移量，从用户自定义数据开始计算，0-based
	UCHAR  ucVfdCount;//在用户自定义数据里跳变字段的个数
	struct VFD//跳变字段数据
	{
		UCHAR  ucStartOffset;//跳变字段起始字节偏移量，从用户自定义数据开始计算，0-based
		UCHAR  ucRange;//跳变字段字段所占的字节数
		UCHAR  ucOffsetType;//跳变字段起始字节偏移量类型，可取TRA_VFD_OFFSET_UDF或TRA_VFD_OFFSET_STREAM，默认为TRA_VFD_OFFSET_UDF
		UCHAR  ucVfdId;//使用TCL接口编辑流时此VFD的唯一标识，其他情况下无具体意义
		ULONG  ulStepType;//跳变类型
		ULONG  ulFirstValue;//跳变字段的起始值，0xFFFFFFFF表示取指定偏移字段的当前值，若超出跳变范围，此跳变将不再有效
		ULONG  ulStep;//跳变字段的步长
		union
		{
			ULONG ulCount;//一个跳变周期中跳变的次数
			ULONG ulLastValue;//随机跳变中跳变字段的末尾值
		};
	} arrVfd[6];
} UDF_S;


typedef	struct tag_PAYLOAD//净荷
{
	BOOL   bEdit;//是否编辑净荷
	UCHAR  ucType;//净荷类型
	UCHAR  ucData;//净荷内容字节
} PAYLOAD_S;

typedef	struct tag_SIGNATURE_BLOCK//流标签块
{
	BOOL   bEdit;//是否编辑流标签块
	BOOL   bInclude;//是否包括流标签块
} SIGNATURE_BLOCK_S;


typedef struct tag_STREAM
{
	USHORT    usRepeatCount;//该流的repeat count，当调度模式为TRA_SCHEDULE_MODE_IFG时有效
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
功能：设置指定端口的发送模式
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucTxMode：发送模式。
	            TRA_TX_MODE_CONTINUOUS表示连续发送，
	  		    TRA_TX_MODE_SINGLE_BURST表示单次突发，
		        TRA_TX_MODE_MULTI_BURST表示多次突发
		        TRA_TX_MODE_TIME_BURST表示按时间发送
	  ui64FramesPerBurst：每次突发的帧数。当ucTxMode==TRA_TX_MODE_CONTINUOUS无效，缺省值为100；当ucTxMode==TRA_TX_MODE_TIME_BURST时，该参数表示发送时间，单位为秒。
	  ulBurstCount：突发次数。当ucTxMode==TRA_TX_MODE_MULTI_BURST有效，缺省值为10；
	  ulInterBurstGap：两个相邻突发之间的间隔，单位为8ns。当ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   有效，缺省值为1200，不能小于最小帧间隔；
	                   TRA_TX_MODE_ON_STREAM表示基于流的的发送模式 
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_TRANSMIT_MODE表示输入的发送模式错误。
注意：在调用该函数之前默认发送模式为TRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraSetPortTransmitMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, ULONG ulInterBurstGap);


/********************************************
功能：获取指定端口的当前发送模式
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pucTxMode：发送模式。
	            TRA_TX_MODE_CONTINUOUS表示连续发送，
	  		    TRA_TX_MODE_SINGLE_BURST表示单次突发，
		        TRA_TX_MODE_MULTI_BURST表示多次突发
		        TRA_TX_MODE_TIME_BURST表示按时间发送
	  pui64FramesPerBurst：每次突发的帧数。当ucTxMode==TRA_TX_MODE_CONTINUOUS无效，缺省值为100；当ucTxMode==TRA_TX_MODE_TIME_BURST时，该参数表示发送时间，单位为秒。
	  pulBurstCount：突发次数。当ucTxMode==TRA_TX_MODE_MULTI_BURST有效，缺省值为10；
	  pulInterBurstGap：两个相邻突发之间的间隔，单位为8ns。当ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   有效，缺省值为1200，不能小于最小帧间隔；
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_TRANSMIT_MODE表示输入的发送模式错误。
注意：在调用该函数之前默认发送模式为TRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraGetPortTransmitMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTxMode,
		UINT64 *pui64FramesPerBurst, ULONG *pulBurstCount, ULONG *pulInterBurstGap);


/********************************************
功能：设置指定端口的发送模式
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucTxMode：发送模式。
	            TRA_TX_MODE_CONTINUOUS表示连续发送，
	  		    TRA_TX_MODE_SINGLE_BURST表示单次突发，
		        TRA_TX_MODE_MULTI_BURST表示多次突发
		        TRA_TX_MODE_TIME_BURST表示按时间发送
	  ui64FramesPerBurst：每次突发的帧数。当ucTxMode==TRA_TX_MODE_CONTINUOUS无效，缺省值为100；当ucTxMode==TRA_TX_MODE_TIME_BURST时，该参数表示发送时间，单位为秒。
	  ulBurstCount：突发次数。当ucTxMode==TRA_TX_MODE_MULTI_BURST有效，缺省值为10；
	  dbInterBurstGap：两个相邻突发之间的间隔，单位为8ns。当ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   有效，缺省值为1200，不能小于最小帧间隔；
	  ucInterBurstGapUnit：dbInterBurstGap参数的单位类型，当ucTxMode==TRA_TX_MODE_MULTI_BURST有效。
						 TRA_IBG_UNIT_TYPE_NONE表示单位为硬件时钟精度，
						 TRA_IBG_UNIT_TYPE_NS表示单位为纳秒，
						 TRA_IBG_UNIT_TYPE_US表示单位为微秒，
						 TRA_IBG_UNIT_TYPE_MS表示单位为毫秒，
						 TRA_IBG_UNIT_TYPE_SEC表示单位为秒，
						 TRA_IBG_UNIT_TYPE_BIT表示单位为比特。
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_TRANSMIT_MODE表示输入的发送模式错误。
注意：在调用该函数之前默认发送模式为TRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraSetPortTransmitModeEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, double dbInterBurstGap, UCHAR ucInterBurstGapUnit);


/********************************************
功能：获取指定端口的当前发送模式
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pucTxMode：发送模式。
	            TRA_TX_MODE_CONTINUOUS表示连续发送，
	  		    TRA_TX_MODE_SINGLE_BURST表示单次突发，
		        TRA_TX_MODE_MULTI_BURST表示多次突发
		        TRA_TX_MODE_TIME_BURST表示按时间发送
	  pui64FramesPerBurst：每次突发的帧数。当ucTxMode==TRA_TX_MODE_CONTINUOUS无效，缺省值为100；当ucTxMode==TRA_TX_MODE_TIME_BURST时，该参数表示发送时间，单位为秒。
	  pulBurstCount：突发次数。当ucTxMode==TRA_TX_MODE_MULTI_BURST有效，缺省值为10；
	  pdbInterBurstGap：两个相邻突发之间的间隔，单位为8ns。当ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   有效，缺省值为1200，不能小于最小帧间隔；
	  pucInterBurstGapUnit：dbInterBurstGap参数的单位类型，当ucTxMode==TRA_TX_MODE_MULTI_BURST有效。
						 TRA_IBG_UNIT_TYPE_NONE表示单位为硬件时钟精度，
						 TRA_IBG_UNIT_TYPE_NS表示单位为纳秒，
						 TRA_IBG_UNIT_TYPE_US表示单位为微秒，
						 TRA_IBG_UNIT_TYPE_MS表示单位为毫秒，
						 TRA_IBG_UNIT_TYPE_SEC表示单位为秒，
						 TRA_IBG_UNIT_TYPE_BIT表示单位为比特。
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_TRANSMIT_MODE表示输入的发送模式错误。
注意：在调用该函数之前默认发送模式为TRA_TX_MODE_CONTINUOUS
*********************************************/
COM_EXPORT ULONG TraGetPortTransmitModeEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTxMode,
		UINT64 *pui64FramesPerBurst, ULONG *pulBurstCount, double *pdbInterBurstGap, UCHAR *pucInterBurstGapUnit);


/********************************************
功能：设置指定端口的流发送调度模式
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucScheduleMode：流发送调度模式。可取的值为：TRA_SCHEDULE_MODE_IFG、TRA_SCHEDULE_MODE_FPS；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_SCHEDULE_MODE表示输入的调度模式错误。
注意：调用该函数之前的默认调度模式为TRA_SCHEDULE_MODE_IFG
*********************************************/
COM_EXPORT ULONG TraSetPortScheduleMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucScheduleMode);



/********************************************
功能：设置指定以太网端口的速率。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucRateUnit：速率单位类型，可取的值为：TRA_RATE_UNIT_TYPE_NS、TRA_RATE_UNIT_TYPE_FPS
	              TRA_RATE_UNIT_TYPE_ULT、TRA_RATE_UNIT_TYPE_DBS、TRA_RATE_UNIT_TYPE_FBS、
				  TRA_RATE_UNIT_TYPE_TBS、TRA_RATE_UNIT_TYPE_LBS；
	  dbRate：速率值；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示指定端口不是以太网端口，
	  FD_ERROR_SCHEDULE_MODE不是指定端口的流调度模式错误，
	  TRA_ERROR_RATE_UNIT表示输入的ucRateUnit错误。
注意：该函数对调度模式为TRA_SCHEDULE_MODE_IFG时适用，
      调度模式为TRA_SCHEDULE_MODE_FPS时请使用函数
	  TraSetStreamRate对流进行调速。
*********************************************/
COM_EXPORT ULONG TraSetEthernetPortRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucRateUnit, double dbRate);


/********************************************
功能：获取指定以太网端口的当前速率。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucRateUnit：速率单位类型，可取的值为：TRA_RATE_UNIT_TYPE_NS、TRA_RATE_UNIT_TYPE_FPS
	              TRA_RATE_UNIT_TYPE_ULT、TRA_RATE_UNIT_TYPE_DBS、TRA_RATE_UNIT_TYPE_FBS、
				  TRA_RATE_UNIT_TYPE_TBS、TRA_RATE_UNIT_TYPE_LBS；
输出：pdbRate：速率值指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示指定端口不是以太网端口，
	  FD_ERROR_SCHEDULE_MODE不是指定端口的流调度模式错误，
	  TRA_ERROR_HAVE_NO_STREAM表示指定端口下没有流，
	  TRA_ERROR_RATE_UNIT表示输入的ucRateUnit错误。
注意：该函数对调度模式为TRA_SCHEDULE_MODE_IFG时适用。
*********************************************/
COM_EXPORT ULONG TraGetEthernetPortRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucRateUnit, double *pdbRate);


/********************************************
功能：使能或不使能指定端口的流发送
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  bEnable： 是否使能流发送；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG TraEnablePort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bEnable);


/********************************************
功能：设置指定端口发送帧时是否带CRC错误
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  bCrcError：发送时是否使能CRC错误；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：无
*********************************************/
COM_EXPORT ULONG TraEnableCrcError(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bCrcError);


/********************************************
功能：设置指定端口发送帧时生成的错误类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulErrorMask：错误类型掩码，可取TRA_ERROR_CRC；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：无
*********************************************/
COM_EXPORT ULONG TraSetPortError(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulErrorMask);


/********************************************
功能：在指定端口下增加流。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pcStreamName：流名称；
	  ucFrameType：该流的帧类型，可取值为：TRA_PRO_TYPE_IPV4、TRA_PRO_TYPE_IPV6、TRA_PRO_TYPE_TCP、TRA_PRO_TYPE_UDP、
	               TRA_PRO_TYPE_TCP6、TRA_PRO_TYPE_UDP6；
	  usRepeatCount：该流发送的重复次数，当调度模式为TRA_SCHEDULE_MODE_IFG时有效。取值范围为1--65535；
	  ucLenType：该流的长度类型，可取值为：TRA_LEN_TYPE_FIXED、TRA_LEN_TYPE_RANDOM、
	             TRA_LEN_TYPE_INCR；
	  usMinLen：长度最小值(不包括尾部CRC字节)；
	  usMaxLen：长度最大值(不包括尾部CRC字节)。当ucFrameType==TRA_LEN_TYPE_FIXED无效；
	  bIncludeSignatureBlock：该流是否带标签块；
	  ucPayloadType：净荷类型。可取值为：TRA_PAY_TYPE_CYCLE、TRA_PAY_TYPE_INCR、TRA_PAY_TYPE_RANDOM；
	  ucPayloadByte：净荷字节；
	  ucL2Type：二层类型，0表示以太网二，1表示LLC/SNAP。对以太网端口有效；
	  ui64SrcMac：源MAC地址；
	  ui64DstMac：目的MAC地址；
	  ulIPv4SrcAddr：IPv4源地址。当ucFrameType为TRA_PRO_TYPE_IPV4、TRA_PRO_TYPE_TCP、TRA_PRO_TYPE_UDP时有效；
	  ulIPv4DstAddr：IPv4目的地址。当ucFrameType为TRA_PRO_TYPE_IPV4、TRA_PRO_TYPE_TCP、TRA_PRO_TYPE_UDP时有效；
	  pucIPv6SrcAddr：IPv6源16字节地址指针。当ucFrameType为TRA_PRO_TYPE_IPV6、TRA_PRO_TYPE_TCP6、TRA_PRO_TYPE_UDP6时有效；
	  pucIPv6DstAddr：IPv6目的16字节地址指针。当ucFrameType为TRA_PRO_TYPE_IPV6、TRA_PRO_TYPE_TCP6、TRA_PRO_TYPE_UDP6时有效；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_EXIST_SAME_STREAM_NAME表示存在相同的流名，
	  TRA_ERROR_FRAME_TYPE表示输入的帧类型错误，
	  TRA_ERROR_LENGTH_TYPE表示输入的长度类型错误，
	  TRA_ERROR_PAYLOAD_TYPE表示输入的净荷类型错误，
      TRA_ERROR_EXCEED_MAX_STREAM_COUNT表示超出该端口可用的最大流数目，
	  TRA_ERROR_EXCEED_FULL_BANDWIDTH表示超出该端口的最大带宽。
注意：要对流进行更复杂的配置请在调用该函数后再调用函数TraEditStream。
*********************************************/
COM_EXPORT ULONG TraAddStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char* pcStreamName, UCHAR ucFrameType, 
	USHORT usRepeatCount, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen, BOOL bIncludeSignatureBlock, 
	UCHAR ucPayloadType, UCHAR ucPayloadByte, UCHAR ucL2Type, UINT64 ui64PortMac, UINT64 ui64DutMac,
	ULONG ulIPv4SrcAddr, ULONG ulIPv4DstAddr, UCHAR *pucIPv6SrcAddr, UCHAR *pucIPv6DstAddr);


/********************************************
功能：在指定端口下增加用户自定义流。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pcStreamName：流名称；
	  usRepeatCount：该流发送的重复次数，当调度模式为TRA_SCHEDULE_MODE_IFG时有效。取值范围为1--65535；
	  ucLenType：该流的长度类型，可取值为：TRA_LEN_TYPE_FIXED、TRA_LEN_TYPE_RANDOM、
	             TRA_LEN_TYPE_INCR；
	  usMinLen：长度最小值(不包括尾部CRC字节)。对于以太网测试端口，
	            带标签块的流长度最小值不能小于24字节，不带标签块的
				流最小值不能小于4字节；对于POS测试端口，带标签块的
				流长度最小值不能小于24字节，不带标签块的流最小值不能
				小于4字节；
	  usMaxLen：长度最大值(不包括尾部CRC字节)。当ucFrameType==TRA_LEN_TYPE_FIXED无效；
	  bIncludeSignatureBlock：该流是否带标签块；
	  ucPayloadType：净荷类型。可取值为：TRA_PAY_TYPE_CYCLE、TRA_PAY_TYPE_INCR、TRA_PAY_TYPE_RANDOM；
	  ucPayloadByte：净荷字节；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_EXIST_SAME_STREAM_NAME表示存在相同的流名，
	  TRA_ERROR_LENGTH_TYPE表示输入的长度类型错误，
	  TRA_ERROR_PAYLOAD_TYPE表示输入的净荷类型错误，
      TRA_ERROR_EXCEED_MAX_STREAM_COUNT表示超出该端口可用的最大流数目，
	  TRA_ERROR_EXCEED_FULL_BANDWIDTH表示超出该端口的最大带宽，
	  TRA_ERROR_STREAM_LENGTH表示该流长度设置错误，
	  TRA_ERROR_STREAM_UDF_LENGTH表示用户自定义数据长度错误，
	  TRA_ERROR_STREAM_UDF_CHECKSUM表示用户自定义数据中的校验和设置错误，
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP表示用户自定义数据中多个跳变字段的范围重叠，
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP表示用户自定义数据中校验和字段和跳变字段重叠，
	  FD_ERROR_EXCEED_MAX_VFD_VALUE表示跳变字段值超出允许的最大值，
	  TRA_ERROR_STREAM_UDF表示用户自定义数据设置错误，
	  TRA_ERROR_STEP_TYPE表示跳变字段的跳变类型设置错误。
注意：要对用户自定义流进行编辑请在调用该函数后再调用函数TraEditStream。
*********************************************/
COM_EXPORT ULONG TraAddCustomStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char* pcStreamName, UDF_S *pUdf, 
	USHORT usRepeatCount, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen, BOOL bIncludeSignatureBlock, 
	UCHAR ucPayloadType, UCHAR ucPayloadByte);


/********************************************
功能：设置指定流的长度。
输入：pcStreamName：要进行编辑的流的名称；
	  ucLenType：该流的长度类型，可取值为：TRA_LEN_TYPE_FIXED、TRA_LEN_TYPE_RANDOM、
	             TRA_LEN_TYPE_INCR；
	  usMinLen：长度最小值(不包括尾部CRC字节)。对于以太网测试端口，
	            带标签块的流长度最小值不能小于24字节，不带标签块的
				流最小值不能小于4字节；对于POS测试端口，带标签块的
				流长度最小值不能小于24字节，不带标签块的流最小值不能
				小于4字节；
	  usMaxLen：长度最大值(不包括尾部CRC字节)。当ucFrameType==TRA_LEN_TYPE_FIXED无效；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  TRA_ERROR_LENGTH_TYPE表示输入的长度类型错误，
	  TRA_ERROR_STREAM_LENGTH表示该流长度设置错误，
	  FD_ERROR表示其他错误。
注意：此函数只会改变流的Payload部分的长度，当设置长度小于当前长度，而Payload部分的长度小于两者的差值时将返回TRA_ERROR_STREAM_LENGTH错误。
*********************************************/
COM_EXPORT ULONG TraSetStreamLength(const char *pcStreamName, UCHAR ucLenType, USHORT usMinLen, USHORT usMaxLen);


/********************************************
功能：判断指定的流是否存在。
输入：pcStreamName：指定流的名称；      
输出：无
返回：存在则返回TRUE(1)，不存在则返回FALSE(0)。
注意：
*********************************************/
COM_EXPORT BOOL TraStreamExists(const char *pcStreamName);


/********************************************
功能：获取指定流的数据结构。
输入：pcStreamName：指定流的名称；
输出：ps: 指定流数据结构指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误
注意：
*********************************************/
COM_EXPORT ULONG TraGetStreamParams(const char* pcStreamName, STREAM_S *ps);


/********************************************
功能：获取指定流的头部数据。
输入：pcStreamName：指定流的名称；      
输出：pucData: 指定流头部数据指针
      pulLen：指定流头部数据长度指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误
注意：
*********************************************/
COM_EXPORT ULONG TraGetStreamHeaderData(const char *pcStreamName, UCHAR *pucData, ULONG *pulLen);


/********************************************
功能：获取指定流的头部数据长度。
输入：pcStreamName：指定流的名称；      
输出：pulLen：指定流头部数据长度指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误
注意：
*********************************************/
COM_EXPORT ULONG TraGetStreamHeaderLength(const char *pcStreamName, ULONG *pulLen);


/********************************************
功能：获取指定流的数据长度。
输入：pcStreamName：指定流的名称；      
输出：pulLen：指定流数据长度指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误
注意：
*********************************************/
COM_EXPORT ULONG TraGetStreamLength(const char *pcStreamName, ULONG *pulLen);


/********************************************
功能：对指定的流进行编辑。
输入：pcStreamName：要进行编辑的流的名称；
      pStreamEdit：要编辑的流内容指针;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  TRA_ERROR_STREAM_LENGTH表示该流原先设置的长度不足以支持所作的编辑，
	  TRA_ERROR_EXCEED_STREAM_HEADER_LENGTH表示流首部长度超出最大值，
	  FD_ERROR_EXCEED_MAX_MAC_ADDRESS表示MAC地址超出最大值，
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS表示IPv4地址超出最大值，
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS表示IPv6地址超出最大值，
	  FD_ERROR_EXCEED_MAX_PORT表示TCP或UDP端口号超出最大值，
	  FD_ERROR_EXCEED_MAX_VLAN_ID表示VLAN ID超出最大值，
	  FD_ERROR_EXCEED_MAX_MPLS_LABEL表示MPLS Label超出最大值，
	  FD_ERROR_EXCEED_MAX_FLOW_LABEL表示IPv6首部的Flow Label超出最大值，
	  TRA_ERROR_STREAM_UDF_LENGTH表示用户自定义数据长度错误，
	  TRA_ERROR_STREAM_UDF_CHECKSUM表示用户自定义数据中的校验和设置错误，
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP表示用户自定义数据中多个跳变字段的范围重叠，
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP表示用户自定义数据中校验和字段和跳变字段重叠，
	  FD_ERROR_EXCEED_MAX_VFD_VALUE表示跳变字段值超出允许的最大值，
	  TRA_ERROR_STREAM_UDF表示用户自定义数据设置错误，
	  TRA_ERROR_STREAM_PAYLOAD_TYPE表示输入的净荷类型错误，
	  TRA_ERROR_EXCEED_MAX_VFD_COUNT表示跳变字段个数超过最大值，
	  TRA_ERROR_EXCEED_MAX_CS_COUNT表示自动校验和个数超过最大值，
	  TRA_ERROR_STEP_TYPE表示跳变字段的跳变类型设置错误。
注意：该函数不能改变指定流的类型。如原来是IPv4流，不能用该函数编辑为IPv6流。
*********************************************/
COM_EXPORT ULONG TraEditStream(const char* pcStreamName, STREAM_S *pStreamEdit);

/********************************************
功能：对指定的流进行编辑。
输入：pcStreamName：要进行编辑的流的名称；
      ui64SrcMac;//源MAC地址
      ULONG  ulSrcMacCount;//一个跳变周期中源MAC地址的个数
	UCHAR  ucSrcMacModBit;//源MAC地址要跳变的bit位，取值范围为33--48
	UCHAR  ucSrcMacModStep;//源MAC地址跳变的步长，取值范围为1--255
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  TRA_ERROR_STREAM_LENGTH表示该流原先设置的长度不足以支持所作的编辑，
	  TRA_ERROR_EXCEED_STREAM_HEADER_LENGTH表示流首部长度超出最大值，
	  FD_ERROR_EXCEED_MAX_MAC_ADDRESS表示MAC地址超出最大值，
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS表示IPv4地址超出最大值，
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS表示IPv6地址超出最大值，
	  FD_ERROR_EXCEED_MAX_PORT表示TCP或UDP端口号超出最大值，
	  FD_ERROR_EXCEED_MAX_VLAN_ID表示VLAN ID超出最大值，
	  FD_ERROR_EXCEED_MAX_MPLS_LABEL表示MPLS Label超出最大值，
	  FD_ERROR_EXCEED_MAX_FLOW_LABEL表示IPv6首部的Flow Label超出最大值，
	  TRA_ERROR_STREAM_UDF_LENGTH表示用户自定义数据长度错误，
	  TRA_ERROR_STREAM_UDF_CHECKSUM表示用户自定义数据中的校验和设置错误，
	  TRA_ERROR_STREAM_UDF_VDF_OVERLAP表示用户自定义数据中多个跳变字段的范围重叠，
	  TRA_ERROR_STREAM_UDF_CHECKSUMFIELD_VDF_OVERLAP表示用户自定义数据中校验和字段和跳变字段重叠，
	  FD_ERROR_EXCEED_MAX_VFD_VALUE表示跳变字段值超出允许的最大值，
	  TRA_ERROR_STREAM_UDF表示用户自定义数据设置错误，
	  TRA_ERROR_STREAM_PAYLOAD_TYPE表示输入的净荷类型错误，
	  TRA_ERROR_EXCEED_MAX_VFD_COUNT表示跳变字段个数超过最大值，
	  TRA_ERROR_EXCEED_MAX_CS_COUNT表示自动校验和个数超过最大值，
	  TRA_ERROR_STEP_TYPE表示跳变字段的跳变类型设置错误。
注意：该函数不能改变指定流的类型。如原来是IPv4流，不能用该函数编辑为IPv6流。
*********************************************/
COM_EXPORT ULONG TraEditStreamSrcMac(const char* pcStreamName,UINT64 ui64SrcMac,ULONG  ulSrcMacCount,UCHAR  ucSrcMacModBit,UCHAR  ucSrcMacModStep);

/********************************************
功能：获取指定端口下已添加的流的数目
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pulStreamCount: 指定端口的流数目；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetPortStreamCount(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG* pulCount);


/********************************************
功能：删除指定的流
输入：pcStreamName：要删除的流的名称；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误。
注意：
*********************************************/
COM_EXPORT ULONG TraRemoveStream(const char* pcStreamName);


/********************************************
功能：删除指定端口下所有已添加的流
输入：ulChsId： 目的机框ID，1-based；
      ulSlotId：目的槽位号，1-based;
	  ulPortId：目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  TRA_ERROR_TRANSMITING表示正在进行发送，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraRemoveStreams(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：使能或不使能指定的流
输入：pcStreamName：要使能的流的名称；
      bEnable：是否使能指定的流；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误。
注意：
*********************************************/
COM_EXPORT ULONG TraEnableStream(const char* pcStreamName, BOOL bEnable);


/********************************************
功能：激活或不激活指定的流，处于非激活状态的流将暂停发送
输入：pcStreamName：要使能的流的名称；
      bActive：是否激活指定的流；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误。
注意：
*********************************************/
COM_EXPORT ULONG TraActiveStream(const char* pcStreamName, BOOL bActive);


/********************************************
功能：对指定的流进行调速
输入：pcStreamName：要使能的流的名称；
      ucRateUnit：速率单位类型，0表示Frames/Sec，非0表示带宽百分比；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  FD_ERROR_SCHEDULE_MODE不是指定端口的流调度模式错误。
注意：该函数对调度模式为TRA_SCHEDULE_MODE_FPS时适用，
      调度模式为TRA_SCHEDULE_MODE_IFG时请使用函数
	  TraSetPortRate对流进行调速。
*********************************************/
COM_EXPORT ULONG TraSetStreamRate(const char* pcStreamName, UCHAR ucRateUnit, double dbRate);

/********************************************
功能：对指定的流的发送模式进行配置
输入：pcStreamName：要使能的流的名称；
       ucTxMode：发送模式。
	            TRA_TX_MODE_CONTINUOUS表示连续发送，
	  		    TRA_TX_MODE_SINGLE_BURST表示单次突发，
		        TRA_TX_MODE_MULTI_BURST表示多次突发
		        TRA_TX_MODE_TIME_BURST表示按时间发送
	  ui64FramesPerBurst：每次突发的帧数。当ucTxMode==TRA_TX_MODE_CONTINUOUS无效，缺省值为100；当ucTxMode==TRA_TX_MODE_TIME_BURST时，该参数表示发送时间，单位为秒。
	  ulBurstCount：突发次数。当ucTxMode==TRA_TX_MODE_MULTI_BURST有效，缺省值为10；
	  ulInterBurstGap：两个相邻突发之间的间隔，单位为8ns。当ucTxMode==TRA_TX_MODE_MULTI_BURST
	                   有效，缺省值为1200，不能小于最小帧间隔；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  TRA_ERROR_TRANSMITING表示正在发送，
      FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  FD_ERROR_SCHEDULE_MODE不是指定端口的流调度模式错误。
注意：端口的发送模式为 RA_TX_MODE_ON_STREAM 有效
*********************************************/
COM_EXPORT ULONG TraSetStreamTransmitMode(const char* pcStreamName, UCHAR ucTxMode,
		UINT64 ui64FramesPerBurst, ULONG ulBurstCount, ULONG ulInterBurstGap);


/********************************************
功能：获取指定以太网端口的IPv4协议栈的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pui64PortMacAddr: 指定端口的MAC地址指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetPortMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64PortMacAddr);


/********************************************
功能：获取指定以太网端口的IPv4协议栈的DUT(被测设备)的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pui64DutMacAddr: DUT的MAC地址指针，*pui64DutMacAddr==0表示获取失败；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定，
	  FD_ERROR_TIMEOUT表示超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
功能：获取指定以太网端口的IPv4协议栈的DUT(被测设备)的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulWaitTime：获取失败时的等待时间，单位为毫秒；
输出：pui64DutMacAddr: DUT的MAC地址指针，*pui64DutMacAddr==0表示获取失败；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定，
	  FD_ERROR_TIMEOUT表示超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr, ULONG ulWaitTime);


/********************************************
功能：通过指定的DUT(被测设备)IP地址获取指定以太网端口的IPv4协议栈的DUT(被测设备)的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulDutIp：DUT的IP地址
输出：pui64DutMacAddr: DUT的MAC地址指针，*pui64DutMacAddr==0表示获取失败；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定。
注意：
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressByIP(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulDutIp, UINT64 *pui64DutMacAddr);


/********************************************
功能：通过指定的DUT(被测设备)IP地址获取指定以太网端口的IPv6协议栈的DUT(被测设备)的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucDutIpv6：DUT的IPv6地址
输出：pui64DutMacAddr: DUT的MAC地址指针，*pui64DutMacAddr==0表示获取失败；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定。
注意：
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressByIPV6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucDutIpv6, UINT64 *pui64DutMacAddr);


/********************************************
功能：获取指定以太网端口的IPv6协议栈的DUT(被测设备)的MAC地址
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pui64DutMacAddr: DUT的MAC地址指针，*pui64DutMacAddr==0表示获取失败；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定，
	  FD_ERROR_TIMEOUT表示超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetDutMacAddressV6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
功能：获取指定以太网端口的IPv4协议栈的多个DUT(被测设备)的MAC地址。当地址映射模式是one to one时适用
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pui64DutMacAddr: DUT的MAC地址指针，指针所指地址存放多个DUT MAC地址，地址个数为该端口IP地址池所对应的数目；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定端口的接口卡还没有预定，
	  FD_ERROR_TIMEOUT表示超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraGetMultiDutMacAddress(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UINT64 *pui64DutMacAddr);


/********************************************
功能：开始指定端口的发送
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR表示其它错误。
注意：在端口需要同时开启发送与统计时，应先开启统计再开启发送
*********************************************/
COM_EXPORT ULONG TraStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：停止指定端口的发送
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG TraStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：判断指定端口是否正在发送
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  nType：检测类型，0表示检测本地测试状态，1表示检测服务器测试状态；
输出：pbTesting：TRUE(1)表示正在发送，FALSE(0)表示发送未开启;
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG TraPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);
#endif


/********************************************
功能：启动流发送
输入：无
输出：无
返回：无
注意：
*********************************************/
COM_EXPORT void TraStart();


/********************************************
功能：停止流发送
输入：无
输出：无
返回：无
注意：
*********************************************/
COM_EXPORT void TraStop();

/********************************************
功能：设置端口的PayloadMap
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG TraSetPortBitErrorMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId ,BOOL bEnable,UCHAR ucData[16]);
#endif


#ifdef __FOR_CSHARP
}
#endif

