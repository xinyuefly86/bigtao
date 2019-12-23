#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define FD_OK										(0)
#define FD_ERROR									(1)
#define FD_FAIL										(2)
#define FD_ERROR_RUNNING_TEST						(3)
#define FD_ERROR_TIMEOUT							(4)
#define FD_ERROR_FILE_EXT							(5)
#define FD_ERROR_PINGING							(6)
#define FD_ERROR_FILE_CONTENT						(7)
#define FD_ERROR_CHASSIS_ID							(8)
#define FD_ERROR_SLOT_ID							(9)
#define FD_ERROR_PORT_ID							(10)
#define FD_ERROR_STREAM_NAME						(11)
#define FD_ERROR_EXCEED_MAX_MAC_ADDRESS				(12)
#define FD_ERROR_EXCEED_MAX_IPV4_ADDRESS			(13)
#define FD_ERROR_EXCEED_MAX_IPV6_ADDRESS			(14)
#define FD_ERROR_EXCEED_MAX_PORT					(15)
#define FD_ERROR_EXCEED_MAX_VLAN_ID					(16)
#define FD_ERROR_EXCEED_MAX_MPLS_LABEL				(17)
#define FD_ERROR_EXCEED_MAX_FLOW_LABEL				(18)
#define FD_ERROR_EXCEED_MAX_IDENTIFICATION			(19)
#define FD_ERROR_EXCEED_MAX_VFD_VALUE				(20)
#define FD_ERROR_EXIST_SAME_STREAM_NAME				(21)
#define FD_ERROR_PORT_TYPE							(22)
#define FD_ERROR_SCHEDULE_MODE						(23)
#define FD_ERROR_PORT_NOT_RESERVED					(24)
#define FD_ERROR_START_PROTOCOL_EMULATION			(25)
#define FD_ERROR_STOP_PROTOCOL_EMULATION			(26)
#define FD_ERROR_PORT_IPV4_ADDRESS					(27)
#define FD_ERROR_PORT_IPV6_ADDRESS					(28)
#define FD_ERROR_PORT_IPV6_LINK_LOCAL_ADDRESS		(29)
#define FD_ERROR_FILE_NOT_EXIST						(30)
#define FD_ERROR_NOT_SUPPORT						(31)
#define FD_ERROR_INSUFFICIENT_MEMORY				(32)
#define FD_ERROR_BUSY_STOPPING						(33)
#define FD_ERROR_TCPIP_STACK_INACTIVE				(34)
#define FD_ERROR_ACCESS_DENY						(35)
#define FD_ERROR_USERNAME							(36)
#define FD_ERROR_PASSWORD							(37)
#define FD_ERROR_DUT_IPV4_ADDRESS					(38)
#define FD_ERROR_DUT_IPV6_ADDRESS					(39)
#define FD_ERROR_FILE_BAD_HASH						(40)
#define FD_ERROR_LICENSE_EXPIRES					(41)
#define FD_ERROR_DUPLICATE_LICENSE					(42)

#define RES_ERROR_CHASSIS_TYPE						(100)
#define RES_ERROR_CHASSIS_SAME_IP_ADDR				(101)
#define RES_ERROR_CHASSIS_CONNECT_FAIL				(102)
#define RES_ERROR_CHASSIS_TYPE_MISMATCH				(103)
#define RES_ERROR_CHASSIS_EXCEED_MAX_COUNT			(104)
#define RES_ERROR_CARD_TYPE							(105)
#define RES_ERROR_CARD_TYPE_MISMATCH				(106)
#define RES_ERROR_CARD_HAD_RESERVED_PORT			(107)
#define RES_ERROR_HAD_RESERVED_BY_OTHER_USER		(108)
#define RES_ERROR_LICENSE_MISMATCHED				(109)
#define RES_ERROR_OLD_SERVER_VERSION				(110)
#define RES_ERROR_OLD_LOGIC_VERSION					(111)
#define RES_ERROR_OLD_CLIENT_VERSION				(112)
#define RES_ERROR_HAVE_CONNECTED_CHASSIS			(113)
#define RES_ERROR_IS_CONNECTED_CHASSIS				(114)
#define RES_ERROR_IS_DISCONNECTED_CHASSIS			(115)
#define RES_ERROR_HAS_NO_CARD						(116)
#define RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT			(117)
#define RES_ERROR_HAD_CARD							(118)
#define RES_ERROR_PORT_MODE							(119)
#define RES_ERROR_PREFIX_LEN						(120)
#define RES_ERROR_NOT_SAME_SUBNET					(121)
#define RES_ERROR_CARD_LOAD_FPGA_ERROR				(122)
#define RES_ERROR_PING_TYPE							(123)
#define RES_ERROR_PING_DATA_SIZE					(124)
#define RES_ERROR_EXCEED_IPV4_INTERFACE_MAX_COUNT	(125)
#define RES_ERROR_PORT_IPV4_NEED_VLAN				(126)
#define RES_ERROR_PORT_IPV4_VLAN_NOT_ENABLE			(127)
#define RES_ERROR_PORT_RELEASING					(128)
#define RES_ERROR_BUSY_OTHER_USER					(129)
#define RES_ERROR_NO_FREE_CORE						(130)
#define RES_ERROR_EXCEED_IPV6_INTERFACE_MAX_COUNT	(131)
#define RES_ERROR_PORT_IPV6_NEED_VLAN				(132)
#define RES_ERROR_PORT_IPV6_VLAN_NOT_ENABLE			(133)
#define RES_ERROR_CHASSIS_INACTIVE					(134)
#define RES_ERROR_CARD_FPGA_TYPE                    (135)
#define RES_ERROR_CARD_LOADING_FPGA                 (136)
#define RES_ERROR_SERIAL_NUMBER_MISMATCH			(137)
#define RES_ERROR_CARD_FPGA_MISMATCH                (138)  


#define INVALID_CHASSIS_ID	(0)
#define INVALID_SLOT_ID		(0)
#define INVALID_PORT_ID		(0)

#define INVALID_VLAN_ID		(0xFFF)


#define MAX_IPV4_INTERFACE_COUNT (4096)
#define MAX_IPV6_INTERFACE_COUNT (4096)


#ifndef LOG_LEVEL
#define LOG_LEVEL
	#define	LOG_EMERG	0	/* system is unusable */
	#define	LOG_ALERT	1	/* action must be taken immediately */
	#define	LOG_CRIT	2	/* critical conditions */
	#define	LOG_ERR		3	/* error conditions */
	#define	LOG_WARNING	4	/* warning conditions */
	#define	LOG_NOTICE	5	/* normal but significant condition */
	#define	LOG_INFO	6	/* informational */
	#define	LOG_DEBUG	7	/* debug-level messages */
#endif


//机箱类型
enum {
	RES_CHASSIS_TYPE_220 = 0, 
	RES_CHASSIS_TYPE_6000,
	RES_CHASSIS_TYPE_12000,
	RES_CHASSIS_TYPE_ITESTER_12000, //12槽位工控机机箱
	RES_CHASSIS_TYPE_ITESTER_6000, //6槽位工控机机箱
	RES_CHASSIS_TYPE_OTHER, // 其它PC机箱
	RES_CHASSIS_TYPE_STORM_200,
	RES_CHASSIS_TYPE_STORM_6000,
	RES_CHASSIS_TYPE_STORM_12000,
	RES_CHASSIS_TYPE_6200, 
	RES_CHASSIS_TYPE_COUNT // 当前有效机箱类型数量
};


//接口卡类型
enum {
	RES_CARD_TYPE_T6012C = 0,  // 12*GE Copper, 0x1
	RES_CARD_TYPE_T6012F,      // 12*GE Fiber, 0x2
	RES_CARD_TYPE_T6012M,      // 12*GE Dual Medial, 0x3
	RES_CARD_TYPE_T8004F,      // 4*10GE Fiber, 0x4
	RES_CARD_TYPE_GT5101,      // 4端口GE电口, 0x5
	RES_CARD_TYPE_GT5102,      // 4端口GE/FE光口, 0x6
	RES_CARD_TYPE_GT6101,      // 2端口10GE光口, 0x7
	RES_CARD_TYPE_GT6102,      // 4端口10GE光口, 0x8
	RES_CARD_TYPE_T6008C,  	   // 8*GE Copper, 0x9
	RES_CARD_TYPE_T6008F,      // 8*GE Fiber, 0xa
	RES_CARD_TYPE_T6008M,      // 8*GE Dual Medial, 0xb
	RES_CARD_TYPE_T6004C,      // 4*GE Copper, 0xc
	RES_CARD_TYPE_T8002F,      // 2*10GE Fiber, 0xd
	RES_CARD_TYPE_GT5103,      // 4端口GE电口, 0xe
	RES_CARD_TYPE_T6108F,      // 8*GE/FE Fiber, 0xf
	RES_CARD_TYPE_H6004C,      // 4*GE Copper, 0x10
	RES_CARD_TYPE_H6004F,      // 4*GE Fiber, 0x11
	RES_CARD_TYPE_GT6103,      // 2端口10GE光口, 0x12
	RES_CARD_TYPE_V9002F40G,   // 2*40GE Fiber, 0x13 旧40G板卡
	RES_CARD_TYPE_P6012C,      // 12*GE Copper, 0x14
	RES_CARD_TYPE_T6108C,      // 8*GE Copper, 0x15
	RES_CARD_TYPE_T6108M,      // 8*GE Dual Medial, 0x16
	RES_CARD_TYPE_T6104C,      // 4*GE Copper, 0x17
	RES_CARD_TYPE_P6012D,      // 12*GE Dual Medial, 0x18
	RES_CARD_TYPE_P6012E,      // 12*GE Dual Medial, 0x19
	RES_CARD_TYPE_P6012F,      // 12*GE Fiber, 0x1a
	RES_CARD_TYPE_P6016C,      // 16*GE Copper, 0x1b
	RES_CARD_TYPE_TPNA702,     // 4*GE Copper/SFP Comb & 4 Fiber 0x1c
	RES_CARD_TYPE_P6016D,      // 16*GE Dual Medial, 12*Copper&4*SPF  0X1D
	RES_CARD_TYPE_P6016E,      // 16*GE Dual Medial, 8*Copper&8*SPF  0X1E
	RES_CARD_TYPE_P6016F,      // 16*GE  Fiber  0XIF
	RES_CARD_TYPE_V6016C,      // 16*GE Copper 0x20        
	RES_CARD_TYPE_V6016F,      // 16*GE/FE Fiber   0x21
	RES_CARD_TYPE_T6104F,      // 4*GE/FE Fiber, 0x22
	RES_CARD_TYPE_VSD6008C,    // 8*GE Copper 0x23 深圳电器
	RES_CARD_TYPE_V9002F,      //  2*100GE Fiber  0x24 V9602F only 40G mode 
	RES_CARD_TYPE_P8004M,      // 4*10GE Dual Medial,2*Copper&2Fiber 0x25
	RES_CARD_TYPE_P8002F,      // 2*10GE Fiber, 0x26
	RES_CARD_TYPE_P8004F,      // 4*10GE Fiber, 0x27
	RES_CARD_TYPE_P8008F,      // 8*10GE Fiber, 0x28
	RES_CARD_TYPE_P8002C,      // 2*10GE Copper 0x29
	RES_CARD_TYPE_P9002F40G,   // 2*40GE Fiber, 0x2A
	RES_CARD_TYPE_P8004C,      // 4*10GE Copper 0x2B
	RES_CARD_TYPE_P8008C,      // 8*10GE Copper 0x2C
	RES_CARD_TYPE_P8008M,      // 8*10GE Dual Medial,4*Copper&4Fiber 0x2D
	RES_CARD_TYPE_V8004C,      // 4*10GE Copper, 0x2E
	RES_CARD_TYPE_V8008M,      // 8*10GE Dual Medial,4*Copper&4Fiber 0x2F
	RES_CARD_TYPE_V8002F,      // 2*10GE Fiber, 0x30
	RES_CARD_TYPE_V8004F,      // 4*10GE Fiber, 0x31
	RES_CARD_TYPE_V8008F,      // 8*10GE Fiber, 0x32
	RES_CARD_TYPE_V8002C,      // 2*GE Copper  0x33 
	RES_CARD_TYPE_V9602F,      // 2*100GE Fiber  0x34 
	RES_CARD_TYPE_V6004C, 	   // 4*GE Copper  0x35 
	RES_CARD_TYPE_V6004F,      // 4*GE/FE Fiber 0x36
	RES_CARD_TYPE_V6008C,      // 8*GE Copper 0x37 
	RES_CARD_TYPE_V6008M,      // 8*GE Dual Medial,4*Copper&4*SPF  0x38 
	RES_CARD_TYPE_V6008F,      // 8*GE/FE Fiber 0x39 
	RES_CARD_TYPE_V6016M,      // 16*GE Dual Medial,8*Copper&8*SPF, 0x3a
	RES_CARD_TYPE_V8008C,      // 8*10GE Copper  0x3b
	RES_CARD_TYPE_V8004M,      // 4*10GE Dual Medial,2*Copper&2Fiber 0x3c 
	RES_CARD_TYPE_V6108C,      // 8*GE Copper 0x3d  
	RES_CARD_TYPE_V6108M,      // 8*GE Dual Medial ,4*Copper&4*SPF 0x3e 
	RES_CARD_TYPE_V6108F,      // 8*GE/FE Fiber 0x3f 
	RES_CARD_TYPE_X6016D,	   // 12*GE Dual Medial, 0x40
	RES_CARD_TYPE_X8004F,	   // 4*10GE Fiber, 0x41
	RES_CARD_TYPE_X6008D,	   // 6*GE Dual Medial, 0x42
	RES_CARD_TYPE_X8002F,	   // 2*10GE Fiber, 0x43
	RES_CARD_TYPE_X6004D,      // 4*GE Dual Medial, 0x44
	RES_CARD_TYPE_P9602F,      // 2*100GE Fiber  0x45 
	RES_CARD_TYPE_P9002F,      //  2*100GE Fiber  0x46 P9602F only 40G mode 
	RES_CARD_TYPE_V9804F,      // 4*100GE Fiber  0x47 
	RES_CARD_TYPE_P6016C_E,	   // 16*GE Copper 0x48
	RES_CARD_TYPE_P6016F_E,    // 16*GE/FE Fiber 0x49
	RES_CARD_TYPE_P6016M_E,    // 16*GE Dual Medial,8*Copper&8*SPF, 0x4a
	RES_CARD_TYPE_P6008M_E,	   // 8*GE Dual Medial,4*Copper&4*SPF  0x4b 
	RES_CARD_TYPE_P8008M_E,    // 8*10GE Dual Medial,4*Copper&4Fiber 0x4c
	RES_CARD_TYPE_P6008F_E,    // 8*GE/FE Fiber 0x4d
	RES_CARD_TYPE_P9804F,      // 4*100GE Fiber  0x4e 
	RES_CARD_TYPE_P6216C,      // 16*GE Copper, 0x4f
	RES_CARD_TYPE_COUNT,       // 当前有效板卡类型数量
};


#define RES_CARD_TYPE_OTHER		(255)


//端口类型
enum {
	RES_PORT_TYPE_FE_C = 0, //FE电口，仅适用于100M接口板上的电口
	RES_PORT_TYPE_FE_F,//FE光口，仅适用于100M接口板上的光口 
	RES_PORT_TYPE_GE_C,//GE电口 
	RES_PORT_TYPE_GE_F,//GE光口
	RES_PORT_TYPE_10GELAN,//10GELAN，光口
	RES_PORT_TYPE_10GEWAN,//10GEWAN，光口
	RES_PORT_TYPE_10GE_C,//10GE电口	
	RES_PORT_TYPE_POS155,//POS155
	RES_PORT_TYPE_POS622,//POS622
	RES_PORT_TYPE_POS2500,//POS2500
	RES_PORT_TYPE_10GPOS,//10GPOS
	RES_PORT_TYPE_25GELAN,
	RES_PORT_TYPE_25GEWAN,
	RES_PORT_TYPE_40GELAN,
	RES_PORT_TYPE_40GEWAN,
	RES_PORT_TYPE_50GELAN,
	RES_PORT_TYPE_50GEWAN,
	RES_PORT_TYPE_100GELAN,
	RES_PORT_TYPE_100GEWAN,
};


//端口模式
enum {
	RES_PORT_MODE_ETHERNET = 0, 
	RES_PORT_MODE_POS, 
	RES_PORT_MODE_ATM
};


//端口link状态
enum {
	RES_LINK_STATE_NA = 0, 
	RES_LINK_STATE_DOWN,
	RES_LINK_STATE_UP
};


//以太网端口速率
enum {
	RES_PORT_RATE_10 = 0, 
	RES_PORT_RATE_100, 
	RES_PORT_RATE_1000, 
	RES_PORT_RATE_10000,
	RES_PORT_RATE_40G,
	RES_PORT_RATE_100G,
	RES_PORT_RATE_25G,
	RES_PORT_RATE_50G
};

enum {
	RES_PHY_MODE_AUTO = 0,
	RES_PHY_MODE_1000BASEX,
	RES_PHY_MODE_SGMII
};

//POS端口速率
enum {
	RES_PORT_POS_RATE_155 = 0, 
	RES_PORT_POS_RATE_622, 
	RES_PORT_POS_RATE_2500, 
	RES_PORT_POS_RATE_10000
};
	

//端口工作模式
enum {
	RES_PORT_OPMODE_NORMAL = 0, 
	RES_PORT_OPMODE_INTERNAL_LOOPBACK, 
	RES_PORT_OPMODE_EXTERNAL_LOOPBACK
};


//CRC类型，仅对POS端口适用
enum {
	RES_CRC_16 = 0, 
	RES_CRC_32,
	RES_CRC_NO 
};


//时钟类型，仅对POS端口适用
enum {
	RES_CLOCK_INTERNAL = 0, 
	RES_CLOCK_LINE_RECOVER
};


//Framing Mode，仅对POS端口适用
enum {
	RES_FM_SONET = 0, 
	RES_FM_SDH
};


//PPP状态，仅对POS端口适用
enum {
	RES_PPP_DISABLE = 0, 
	RES_PPP_NA, 
	RES_PPP_CLOSE, 
	RES_PPP_OPEN, 
	RES_PPP_REQ_SENT,//仅服务器适用
	RES_PPP_ACK_RCVD,//仅服务器适用
	RES_PPP_ACK_SENT//仅服务器适用
};


//PPP状态类型，仅对POS端口适用
enum 
{
	PPP_STATE_TYPE_LCP = 0, 
	PPP_STATE_TYPE_IPCP,
	PPP_STATE_TYPE_IPV6CP, 
	PPP_STATE_TYPE_MPLSCP, 
	PPP_STATE_TYPE_OSINLCP
};


//二层封装类型, 仅对以太网端口适用
enum {
	RES_FAMING_E2 = 0, 
	RES_FAMING_8023
};


//二层封装类型, 仅对POS端口适用
enum {
	RES_FAMING_PPP = 0, 
	RES_FAMING_CHDLC//Cisco HDLC
};

//端口PING功能的类型
enum{
	RES_PING_INTERVAL = 0,
	RES_PING_CONTINUOUS,
};

//端口流控功能的类型
enum{
	RES_FLOW_CTRL_DISABLE = 0,
	RES_FLOW_CTRL_ENABLE,
	RES_FLOW_CTRL_NEGO
};

//周期性发送ARP报文的类型
enum
{
	ARP_TYPE_NONE = 0,
	ARP_TYPE_GRAT,
	ARP_TYPE_REQUEST,
	ARP_TYPE_REPLY,
	ARP_TYPE_GRAT_REQUEST,
	ARP_TYPE_GRAT_REPLY,
	ARP_TYPE_REQUEST_REPLY,
	ARP_TYPE_GRAT_REQUEST_REPLY,
};

//周期性发送NDP报文的类型
enum
{
	NDP_TYPE_NONE = 0,
	NDP_TYPE_NS,
	NDP_TYPE_NA,
	NDP_TYPE_NS_NA,
};

//X系列卡核分配模式
enum{
	RES_CORE_MODE_DYNAMIC = 0,
	RES_CORE_MODE_STATIC
};

#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct tag_PORT_ETH
{
	BOOL   bAutoNego;//是否使能自协商  P板卡0:强制从 2:强制主 1:自协商reapter 5:自协商DTE
	BOOL   bFullDuplex;//是否使能全双工
	ULONG  ulFlowCtrlType;//流控类型，RES_FLOW_CTRL_DISABLE表示不使能，RES_FLOW_CTRL_ENABLE表示使能，RES_FLOW_CTRL_NEGO表示协商
	UCHAR  ucRate;//可以取的值为：RES_PORT_RATE_10、RES_PORT_RATE_100、RES_PORT_RATE_1000、RES_PORT_RATE_10000;
//	UCHAR  ucOperateMode;//可以取的值为：RES_PORT_OPMODE_NORMAL、RES_PORT_OPMODE_INTERNAL_LOOPBACK

	BOOL   bIPv4Enable;//是否使能IPv4协议栈
	UCHAR  ucIPv4AddrMap;//测试端口IPv4地址和DUT端口IPv4地址的对应关系，0表示many->one，1表示many->many
	UCHAR  ucIPv4PrefixLen;//IPv4地址掩码长度，取值范围为1--32
	ULONG  ulIPv4PortFirstAddr;//测试端口的起始IPv4地址
	ULONG  ulIPv4PortAddrCount;//测试端口IPv4地址数目，当ucIPv4AddrMap==0时取值范围为1--65536，当ucIPv4AddrMap==1时取值范围为1--8192，当ucIPv4AddrMap==1时也适用于DUT
	UCHAR  ucIPv4PortAddrModBit;//测试端口IPv4地址跳变的bit位，取值范围为1--32，当ucIPv4AddrMap==1时也适用于DUT
	UCHAR  ucIPv4PortAddrModStep;//测试端口IPv4地址跳变的步长，取值范围为1--255，当ucIPv4AddrMap==1时也适用于DUT
	ULONG  ulIPv4DutFirstAddr;//DUT端口起始IPv4地址
	BOOL   bIPv4Vlan;//是否使能IPv4协议栈的VLAN功能
	USHORT usIPv4FirstVlanId;//IPv4协议栈的起始VLAN ID，取值范围：0--4094
	USHORT usIPv4VlanIdStep;//IPv4协议栈VLAN ID的跳变步长，取值范围：1--4094, 仅当ucIPv4AddrMap==1时有效
	BOOL   bIPv4UniqueMacAddr;//IPv4协议栈的每个接口是否生成一个不同的MAC地址
	UCHAR  ucaIPv4FirstMacAddr[6];//测试端口IPv4协议栈的起始MAC地址。
	UCHAR  ucIPv4MacAddrModBit;//测试端口IPv4 MAC地址跳变的bit位，取值范围为1--48
	UCHAR  ucIPv4MacAddrModStep;//测试端口IPv4 MAC地址跳变的步长，取值范围为0--255
	BOOL   bSendGratArp;//是否发送免费ARP
	BOOL   bSendArpReply;//是否对ARP Request进行应答
	ULONG  ulPeriodArpType;//周期性发送的ARP报文类型，0表示不使能，1表示Gratuitous ARP(GRAT)，2表示ARP Request(REQUEST)，3表示ARP Reply(REPLY)，
						   //4表示GRAT + REQUEST，5表示GRAT + REPLY，6表示REQUEST + REPLY，7表示GRAT + REQUEST + REPLY，默认值为0
	USHORT usPeriodArpFrequency;//周期性发送指定类型ARP报文的时间频率，单位为秒，取值范围1--65535
	USHORT usIPv4SendArpRate;//测试端口发送ARP报文的速率，以packets/s为单位，取值范围1--10000

	BOOL   bIPv6Enable;//是否使能IPv6协议栈
	UCHAR  ucIPv6AddrMap;//测试端口IPv6地址和DUT端口IPv6地址的对应关系，0表示many->one，1表示many->many
	UCHAR  ucaIPv6PortFirstAddr[16];//测试端口的起始IPv6地址，网段掩码默认为64位
	UCHAR  ucIPv6PrefixLen;//IPv6地址掩码长度，取值范围为1--128
	ULONG  ulIPv6PortAddrCount;//测试端口IPv6地址数目，当ucIPv6AddrMap==0时取值范围为1--65536，当ucIPv6AddrMap==1时取值范围为1--8192，当ucIPv6AddrMap==1时也适用于DUT
	UCHAR  ucIPv6PortAddrModBit;//测试端口IPv6地址跳变的bit位，当ucIPv6AddrMap==0时取值范围为97--128，当ucIPv6AddrMap==1时取值范围为33--64，当ucIPv6AddrMap==1时也适用于DUT
	UCHAR  ucIPv6PortAddrModStep;//测试端口IPv6地址跳变的步长，取值范围为1--255，当ucIPv6AddrMap==1时也适用于DUT
	UCHAR  ucaIPv6DutFirstAddr[16];//DUT端口起始IPv6地址
	BOOL   bIPv6Vlan;//是否使能IPv6协议栈的VLAN功能
	USHORT usIPv6FirstVlanId;//IPv6协议栈的起始VLAN ID，取值范围：0--4094
	USHORT usIPv6VlanIdStep;//IPv6协议栈VLAN ID的跳变步长，取值范围：1--4094, 仅当ucIPv6AddrMap==1时有效
	BOOL   bIPv6UniqueMacAddr;//IPv6协议栈的每个接口是否生成一个不同的MAC地址
	UCHAR  ucaIPv6FirstMacAddr[6];//测试端口IPv6协议栈的起始MAC地址。
	UCHAR  ucIPv6MacAddrModBit;//测试端口IPv6 MAC地址跳变的bit位，取值范围为1--48
	UCHAR  ucIPv6MacAddrModStep;//测试端口IPv6 MAC地址跳变的步长，取值范围为0--255
	BOOL   bSendGratNa;//是否发送免费NA
	BOOL   bSendNa;//是否对neighbor solicitation进行应答
	ULONG  ulPeriodNdpType;//周期性发送的NDP报文类型，0表示不使能，1表示Neighbor Solicitation(NS)，2表示Neighbor Advertisement(NA)，3表示NS + NA，默认值为0
	USHORT usPeriodNdpFrequency;//周期性发送指定类型NDP报文的时间频率，单位为秒，取值范围1--65535
	USHORT usIPv6SendNdpRate;//测试端口发送NDP报文的速率，以packets/s为单位，取值范围1--10000
} PORT_ETH_S;


/********************************************
功能：初始化所有模块。开始运行TeleApi.dll时需要先调用该函数
输入：无
输出：无
返回：成功则返回FD_OK；失败则返回FD_ERROR；
注意：
*********************************************/
COM_EXPORT ULONG InitAllModules();


/********************************************
功能：删除所有模块
输入：无
输出：无
返回：无
注意：运行结束时需要调用该函数
*********************************************/
COM_EXPORT void DeleteAllModules();


/********************************************
功能：设置调试等级，等级越高，则日志信息越详细
输入：nDebugLevel：调试等级，可取的值为：LOG_EMERG、LOG_ALERT、LOG_CRIT、LOG_ERR、
	               LOG_WARNING、LOG_NOTICE、LOG_INFO、LOG_DEBUG；
输出：无
返回：原先的调试等级
注意：默认的调试等级为LOG_ERR
*********************************************/
COM_EXPORT int SetDebugLevel(int nDebugLevel);


/********************************************
功能：设置本地用户标识ID，在使用‘GUI Monitor'等功能时可根据此ID对不同用户加以区分
输入：caUserID：户标识ID，为空值时表示将用户标识ID设置为本地计算机名
输出：无
返回：原先的用户标识ID
注意：默认的用户标识ID为本地计算机名
*********************************************/
COM_EXPORT const char *SetUserID(const char *caUserID);


/********************************************
功能：加载配置文件
输入：pcFilePath：配置文件路径，后缀为cfg
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_FILE_EXT表示输入的文件名后缀错误(应为'cfg');
	  FD_ERROR_RUNNING_TEST表示正在运行测试, 
	  FD_ERROR_PINGING表示正在运行Ping, 
	  FD_ERROR_FILE_CONTENT表示文件内容错误, 
	  RES_ERROR_HAVE_CONNECTED_CHASSIS表示存在已建立TCP连接的机箱
注意：
*********************************************/
COM_EXPORT ULONG LoadConfigFile(const char *pcFilePath);

/********************************************
功能：加载配置文件
输入：pcFilePath：配置文件路径，后缀为cfg
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_FILE_EXT表示输入的文件名后缀错误(应为'cfg');
	  FD_ERROR_RUNNING_TEST表示正在运行测试, 
	  FD_ERROR_PINGING表示正在运行Ping, 
	  FD_ERROR_FILE_CONTENT表示文件内容错误, 
	  RES_ERROR_HAVE_CONNECTED_CHASSIS表示存在已建立TCP连接的机箱
注意：
*********************************************/
COM_EXPORT ULONG LoadConfigFileW(const wchar_t *pcFilePath);


/********************************************
功能：保存配置文件
输入：pcFilePath：配置文件路径，后缀为cfg
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_FILE_EXT表示输入的文件名后缀错误(应为'cfg');
	  FD_ERROR_RUNNING_TEST表示正在运行测试, 
	  FD_ERROR_PINGING表示正在运行Ping
注意：
*********************************************/
COM_EXPORT ULONG SaveConfigFile(const char *pcFilePath);

/********************************************
功能：保存配置文件
输入：pcFilePath：配置文件路径，后缀为cfg
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_FILE_EXT表示输入的文件名后缀错误(应为'cfg');
	  FD_ERROR_RUNNING_TEST表示正在运行测试, 
	  FD_ERROR_PINGING表示正在运行Ping
注意：
*********************************************/
COM_EXPORT ULONG SaveConfigFileW(const wchar_t *pcFilePath);


/********************************************
功能：添加机箱
输入：ulType：机箱类型。机箱类型有：RES_CHASSIS_TYPE_220、RES_CHASSIS_TYPE_6000、RES_CHASSIS_TYPE_12000、
			RES_CHASSIS_TYPE_ITESTER_12000、RES_CHASSIS_TYPE_ITESTER_6000、RES_CHASSIS_TYPE_OTHER；
      ulIpAddr：机箱管理网口IP地址；
输出：pulChassisId：机箱ID指针，1-based
返回：成功则返回FD_OK；失败则返回如下值：
      RES_ERROR_CHASSIS_TYPE表示输入的ulType错误，
	  RES_ERROR_CHASSIS_SAME_IP_ADDR表示存在相同的IP地址，
	  RES_ERROR_CHASSIS_EXCEED_MAX_COUNT表示机箱数超出允许的最大值；
注意：
*********************************************/
COM_EXPORT ULONG ResChassisAdd(ULONG ulType, ULONG ulIpAddr, ULONG *pulChassisId);


/********************************************
功能：和指定机箱建立TCP连接
输入：ulChsId：机箱ID，1-based；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_CHASSIS_TYPE_MISMATCH表示实际的机箱类型和GUI里配置的不一致，
	  RES_ERROR_OLD_SERVER_VERSION表示服务器软件版本太老，
	  RES_ERROR_OLD_LOGIC_VERSION表示逻辑软件版本太老，
	  RES_ERROR_OLD_CLIENT_VERSION表示客户端软件版本太老，
	  RES_ERROR_CHASSIS_CONNECT_FAIL表示建立TCP连接失败，
	  RES_ERROR_LICENSE_MISMATCHED表示机箱License不匹配。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisConnect(ULONG ulChsId);


/********************************************
功能：重启机箱
输入：ulChsId：机箱ID，1-based；
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_TIMEOUT表示超时, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER表示存在被其他用户预约的端口
注意：
*********************************************/
COM_EXPORT ULONG ResChassisReboot(ULONG ulChsId);


/********************************************
功能：关闭机箱
输入：ulChsId：机箱ID，1-based；
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_TIMEOUT表示超时, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER表示存在被其他用户预约的端口
注意：
*********************************************/
COM_EXPORT ULONG ResChassisShutDown(ULONG ulChsId);


/********************************************
功能：升级指定机箱内的TeleManager服务器软件
输入：ulChsId：机箱ID，1-based；
	  pcFilePath：TeleManager服务器软件包路径
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_FILE_NOT_EXIST表示无法打开指定的TeleManager服务器软件包路径
	  FD_ERROR_TIMEOUT表示超时, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER表示存在被其他用户预约的端口
注意：
*********************************************/
COM_EXPORT ULONG ResChassisUpdate(ULONG ulChsId, const char *pcFilePath);


/********************************************
功能：升级指定机箱内的TeleManager服务器软件
输入：ulChsId：机箱ID，1-based；
	  pcFilePath：TeleManager服务器软件包路径
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_FILE_NOT_EXIST表示无法打开指定的TeleManager服务器软件包路径
	  FD_ERROR_TIMEOUT表示超时, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER表示存在被其他用户预约的端口
注意：
*********************************************/
COM_EXPORT ULONG ResChassisUpdateW(ULONG ulChsId, const wchar_t *pcFilePath);


/********************************************
功能：登录到指定机箱中，获得管理员权限
输入：ulChsId：机箱ID，1-based；
	  caUsername：登录用户名，初始设置为“teletest”
	  caPassword：登录密码，初始设置为“teletest”
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_USERNAME表示提供的用户名错误，
	  FD_ERROR_PASSWORD表示提供的密码错误，
	  FD_ERROR_TIMEOUT表示超时, 
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisLogin(ULONG ulChsId, const char *caUsername, const char *caPassword);


/********************************************
功能：修改到指定机箱中管理员登录信息
输入：ulChsId：机箱ID，1-based；
	  caOldUsername：旧的登录用户名
	  caOldPassword：旧的登录密码
	  caNewUsername：新的登录用户名
	  caNewPassword：新的登录密码
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_USERNAME表示提供的用户名错误，
	  RES_ERROR_PASSWORD表示提供的密码错误，
	  FD_ERROR_ACCESS_DENY表示未登录，
	  FD_ERROR_TIMEOUT表示超时, 
	  FD_ERROR表示其它错误。
注意：必须已登录到指定机箱中
*********************************************/
COM_EXPORT ULONG ResChassisModifyLoginInfo(ULONG ulChsId, const char *caOldUsername, const char *caOldPassword, const char *caNewUsername, const char *caNewPassword);


/********************************************
功能：从指定机箱中退出登录，释放管理员权限
输入：ulChsId：机箱ID，1-based；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  FD_ERROR_TIMEOUT表示超时, 
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisLogout(ULONG ulChsId);


/********************************************
功能：检测是否已登录到指定机箱
输入：ulChsId：机箱ID，1-based；
输出：pbLogined，指示是否已登录的指针
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResIsChassisLogined(ULONG ulChsId, BOOL *pbLogined);


/********************************************
功能：和指定机箱断开TCP连接
输入：ulChsId：机箱ID，1-based；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisDisconnect(ULONG ulChsId);


/********************************************
功能：检查机箱是否处于连接状态
输入：ulChsId：机箱ID，1-based；
输出：pbConnected TRUE表示处于连接状态
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResIsChassisConnected(ULONG ulChsId, BOOL* pbConnected);


/********************************************
功能：删除指定的机箱
输入：ulChsId：机箱ID，1-based；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
	  RES_ERROR_IS_CONNECTED_CHASSIS表示指定机箱已建立TCP连接。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisRemove(ULONG ulChsId);


/********************************************
功能：获取机箱随机ID
输入：ulChsId：机箱ID，1-based；
输出：
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
注意：
*********************************************/
COM_EXPORT ULONG ResGetChassisRandID(ULONG ulChsId,ULONG* pulRandId);


/********************************************
功能：设置指定的机箱的管理网口的IP地址
输入：ulChsId：机箱ID，1-based；
      ulIpAddr：机箱的管理网口IP地址
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_CONNECTED_CHASSIS表示指定机箱已建立TCP连接。
注意：
*********************************************/
COM_EXPORT ULONG ResChassisSetIpAddress(ULONG ulChsId, ULONG ulIpAddr);


/********************************************
功能：添加接口卡
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulCardType: 低16bit表示 接口卡类型。接口卡类型有：RES_CARD_TYPE_T6012C、RES_CARD_TYPE_T6012F、RES_CARD_TYPE_T6012M、
			RES_CARD_TYPE_T8004F、RES_CARD_TYPE_GT5101、RES_CARD_TYPE_GT5102、RES_CARD_TYPE_GT6101、
			RES_CARD_TYPE_GT6102、RES_CARD_TYPE_T6008C、RES_CARD_TYPE_T6008F、RES_CARD_TYPE_T6008M、
			RES_CARD_TYPE_T6004C;
			高16bit表示 接口卡的FPGA模式 V9有效 。接口卡的FPGA模式类型有:
	  		FPGA_DEFAULT,FPGA_10_G,FPGA_25_G,FPGA_40_G,FPGA_50_G,FPGA_100_G;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_HAD_CARD表示该槽位已经有接口卡，
	  RES_ERROR_CARD_TYPE表示ulCardType错误。
注意：
*********************************************/
COM_EXPORT ULONG ResCardAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulCardType);

/********************************************
功能：添加接口卡
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulCardType: 接口卡类型。接口卡类型有：RES_CARD_TYPE_T6012C、RES_CARD_TYPE_T6012F、RES_CARD_TYPE_T6012M、
			RES_CARD_TYPE_T8004F、RES_CARD_TYPE_GT5101、RES_CARD_TYPE_GT5102、RES_CARD_TYPE_GT6101、
			RES_CARD_TYPE_GT6102、RES_CARD_TYPE_T6008C、RES_CARD_TYPE_T6008F、RES_CARD_TYPE_T6008M、
			RES_CARD_TYPE_T6004C;
	  ulFpgaType:接口卡的FPGA模式。接口卡的FPGA模式类型有:
	  		FPGA_DEFAULT,FPGA_10_G,FPGA_25_G,FPGA_40_G,FPGA_50_G,FPGA_100_G;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_HAD_CARD表示该槽位已经有接口卡，
	  RES_ERROR_CARD_TYPE表示ulCardType错误。
注意：
*********************************************/
COM_EXPORT ULONG ResCardAddEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulCardType,ULONG ulFpgaType);



/********************************************
功能：获取已连接的指定机箱中指定接口卡的信息
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
输出：pCardType: 接口卡类型。接口卡类型有：RES_CARD_TYPE_T6012C、RES_CARD_TYPE_T6012F、RES_CARD_TYPE_T6012M、
			RES_CARD_TYPE_T8004F、RES_CARD_TYPE_GT5101、RES_CARD_TYPE_GT5102、RES_CARD_TYPE_GT6101、
			RES_CARD_TYPE_GT6102、RES_CARD_TYPE_T6008C、RES_CARD_TYPE_T6008F、RES_CARD_TYPE_T6008M、
			RES_CARD_TYPE_T6004C;
	  pPortCount: 表示接口卡包含的端口数
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResGetCardInfo(ULONG ulChsId, ULONG ulSlotId, ULONG *pulCardType, ULONG *pulPortCount);

/********************************************
功能：获取已连接的指定机箱中指定接口卡的PPM值
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
输出：piPpm
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResGetCardPPM(ULONG ulChsId, ULONG ulSlotId, int *piPpm);

/********************************************
功能：获取已连接的指定机箱中指定接口卡的PPM值
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
	  piPpm:-100 - 100;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResSetCardPPM(ULONG ulChsId, ULONG ulSlotId, int iPpm);


/********************************************
功能：删除指定的接口卡
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_HAS_NO_CARD表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_CARD_HAD_RESERVED表示该接口卡已经被预订。
注意：
*********************************************/
COM_EXPORT ULONG ResCardRemove(ULONG ulChsId, ULONG ulSlotId);


/********************************************
功能：设置指定接口卡的核（CPU）分配模式
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulCoreMode：核（CPU）分配模式，可选RES_CORE_MODE_DYNAMIC和RES_CORE_MODE_STATIC，默认为RES_CORE_MODE_DYNAMIC
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_NOT_SUPPORT表示指定的接口卡不支持此设置，
	  FD_ERROR_ACCESS_DENY表示未登录，
	  RES_ERROR_BUSY_OTHER_USER表示其他用户正在测试中，暂时无法转换分配模式，
	  FD_ERROR_TIMEOUT表示超时, 
	  FD_ERROR表示其它错误。
注意：必须先通过ResChassisLogin接口获得管理员权限
*********************************************/
COM_EXPORT ULONG ResSetCardCoreMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulCoreMode);


/********************************************
功能：获取已连接的指定机箱中指定接口卡的Fpga信息 用于V9602
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
输出：pulFpgaType:1:FPGA_40_G 、2:FPGA_100_G;
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_CARD_LOADING_FPGA 表示该接口卡正在加载FPGA,
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResGetCardFpgaType(ULONG ulChsId, ULONG ulSlotId, ULONG* pulFpgaType);

/********************************************
功能：设置已连接的指定机箱中指定接口卡的Fpga信息 用于V9602
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
输出：pulFpgaType:  1:FPGA_40_G 、2:FPGA_100_G;
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_CARD_LOADING_FPGA 表示该接口卡正在加载FPGA,
	  FD_ERROR_TIMEOUT表示超时。
注意：此设置是异步操作，设置完Fpga类型后需要调用ResGetCardFpgaType 判断Fpga切换是否完成。
*********************************************/
COM_EXPORT ULONG ResSetCardFpgaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulFpgaType);

/********************************************
功能：设置已连接的指定机箱中指定接口卡的Fpga信息 用于V9602
输入：ulChsId：机箱ID，1-based；
	  ulSlotId: 槽位号，1-based;
输出：pulFpgaType:  1:FPGA_40_G 、2:FPGA_100_G;
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR表示输出参数存在空指针，
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_CARD_LOADING_FPGA 表示该接口卡正在加载FPGA,
	  FD_ERROR_TIMEOUT表示超时。
注意：调用这个api只是把100G的速率模式保存到配置文件，调用完成后需要重启机箱。
*********************************************/
COM_EXPORT ULONG ResSetCardFpgaTypeCfg(ULONG ulChsId, ULONG ulSlotId, ULONG ulFpgaType);

/********************************************
功能：预订指定的端口
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulPortId: 端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD表示该槽位还没有添加接口卡，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER表示该端口已经被其它用户被预订，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResPortReserve(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：查询指定的端口是否已预约
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulPortId: 端口号，1-based;
输出：pbReserved：TRUE表示端口已预约
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResIsPortReserved(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL* pbReserved);


/********************************************
功能：预订指定的端口
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulPortId: 端口号，1-based;
	  bSetPhy：表示此次预约是否设置端口的物理参数
输出：pPeerIp: 若端口已被占用则返回占用IP
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示指定机箱未处于TCP连接，
	  RES_ERROR_HAS_NO_CARD表示该槽位还没有添加接口卡，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示实际机箱的相应槽位中没有插入接口卡，
	  RES_ERROR_PORT_HAD_RESERVED_BY_OTHER_USER表示该端口已经被其它用户被预订，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResPortReserveEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bSetPhy, ULONG* pPeerIp);


/********************************************
功能：释放已预订的指定的端口
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based;
	  ulPortId: 端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_HAS_NO_CARD表示该槽位还没有添加接口卡，
	  FD_ERROR_TIMEOUT表示超时。
注意：
*********************************************/
COM_EXPORT ULONG ResPortRelease(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：尝试强制释放已被其他用户预约的端口
输入：ulChsId:  机箱ID，1-based;
	  ulSlotId: 槽位号，1-based，为INVALID_SLOT_ID表示释放指定机箱上所有端口;
	  ulPortId: 端口号，1-based，为INVALID_PORT_ID表示释放指定板卡上所有端口;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_ACCESS_DENY表示未登录，
	  FD_ERROR表示其它错误。
注意：必须先通过ResChassisLogin接口获得管理员权限
*********************************************/
COM_EXPORT ULONG ResTryReleasePorts(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：设置指定测试端口及其DUT端口的IPv4地址。若要设置一个端口的多个IPv4地址，
      请用函数ResEthernetPortSetup。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Addr：测试端口的IPv4地址;
	  ulDutIPv4Addr： DUT的IPv4地址；	
	  ucPrefix：掩码长度，取值范围为1--32
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PREFIX_LEN表示掩码长度错误，
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv4地址不属于同一个网段。
注意：
*********************************************/
COM_EXPORT ULONG ResPortSetIPv4Address(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UCHAR ucPrefixLen);


/********************************************
功能：将IPv4地址接口嵌入到指定测试端口的IPv4协议栈，地址接口独立于IPv4协议栈地址池。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Addr：测试端口的IPv4地址，与usVlanId的组合在端口内唯一;
	  ulDutIPv4Addr： DUT的IPv4地址；	
	  ui64PortMacAddr：测试端口的MAC地址；
	  usVlanId：测试端口的VLAN ID，与ulPortIPv4Addr的组合在端口内唯一;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV4_ADDRESS表示端口内存在相同的IPv4地址，
	  FD_ERROR_DUT_IPV4_ADDRESS表示端口内存在与ulDutIPv4Addr相同的IPv4地址，
	  RES_ERROR_EXCEED_IPV4_INTERFACE_MAX_COUNT表示端口的IPv4地址接口数达到上限，
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv4地址不属于同一个网段，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortAddIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
功能：将IPv4地址接口嵌入到指定测试端口的IPv4协议栈，地址接口独立于IPv4协议栈地址池，若存在相同接口则编辑该接口。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Addr：测试端口的IPv4地址，与usVlanId的组合在端口内唯一;
	  ulDutIPv4Addr： DUT的IPv4地址；	
	  ui64PortMacAddr：测试端口的MAC地址；
	  usVlanId：测试端口的VLAN ID，与ulPortIPv4Addr的组合在端口内唯一;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV4_ADDRESS表示端口地址池内存在相同的IPv4地址，
	  FD_ERROR_DUT_IPV4_ADDRESS表示端口内存在与ulDutIPv4Addr相同的IPv4地址，
	  RES_ERROR_EXCEED_IPV4_INTERFACE_MAX_COUNT表示端口的IPv4地址接口数达到上限，
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv4地址不属于同一个网段，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortSetIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
功能：移除指定测试端口的单个IPv4地址接口。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Addr：测试端口的IPv4地址，端口内唯一;
	  usVlanId：该IPv4地址接口对应的VLAN ID
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortRemoveIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, USHORT usVlanId);


/********************************************
功能：移除指定测试端口的全部IPv4地址接口。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortRemoveAllIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：将IPv6地址接口嵌入到指定测试端口的IPv6协议栈，地址接口独立于IPv6协议栈地址池。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Addr：测试端口的IPv6地址，与usVlanId的组合在端口内唯一;
	  pucDutIPv6Addr： DUT的IPv6地址；	
	  ui64PortMacAddr：测试端口的MAC地址；
	  usVlanId：测试端口的VLAN ID，与pucPortIPv6Addr的组合在端口内唯一;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV6_ADDRESS表示端口内存在相同的IPv6地址，
	  FD_ERROR_DUT_IPV6_ADDRESS表示端口内存在与pucDutIPv6Addr相同的IPv6地址，
	  RES_ERROR_EXCEED_IPV6_INTERFACE_MAX_COUNT表示端口的IPv6地址接口数达到上限，
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv6地址不属于同一个网段，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortAddIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucPortIPv6Addr[16], UCHAR pucDutIPv6Addr[16], UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
功能：将IPv6地址接口嵌入到指定测试端口的IPv6协议栈，地址接口独立于IPv6协议栈地址池，若存在相同接口则编辑该接口。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Addr：测试端口的IPv6地址，与usVlanId的组合在端口内唯一;
	  pucDutIPv6Addr： DUT的IPv6地址；	
	  ui64PortMacAddr：测试端口的MAC地址；
	  usVlanId：测试端口的VLAN ID，与pucPortIPv6Addr的组合在端口内唯一;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV6_ADDRESS表示端口地址池内存在相同的IPv6地址，
	  FD_ERROR_DUT_IPV6_ADDRESS表示端口内存在与pucDutIPv6Addr相同的IPv6地址，
	  RES_ERROR_EXCEED_IPV6_INTERFACE_MAX_COUNT表示端口的IPv6地址接口数达到上限，
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv6地址不属于同一个网段，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucPortIPv6Addr[16], UCHAR pucDutIPv6Addr[16], UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
功能：移除指定测试端口IPv6地址接口。
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Addr：测试端口的IPv6地址，端口内唯一;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortRemoveIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucPortIPv6Addr, USHORT usVlanId);


/********************************************
功能：移除指定测试端口的全部IPv6地址接口。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG ResPortRemoveAllIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：设置指定测试端口及其DUT端口的IPv6地址。若要设置一个端口的多个IPv6地址，
      请用函数ResEthernetPortSetup。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Addr：测试端口的16字节IPv6地址指针，网段掩码默认为64位;
	  pucDutIP64Addr： DUT的16字节IPv6地址指针；	
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv6地址不属于同一个网段。
注意：
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6Address(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Addr, UCHAR *pucDutIPv6Addr);


/********************************************
功能：设置指定测试端口及其DUT端口的IPv6地址。若要设置一个端口的多个IPv6地址，
      请用函数ResEthernetPortSetup。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Addr：测试端口的16字节IPv6地址指针，网段掩码默认为64位;
	  pucDutIP64Addr： DUT的16字节IPv6地址指针；	
	  ucPrefixLen：掩码长度，取值范围为1--128
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
	  RES_ERROR_NOT_SAME_SUBNET表示以太网测试端口和DUT端口的IPv6地址不属于同一个网段。
注意：
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6AddressEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Addr, UCHAR *pucDutIPv6Addr, UCHAR ucPrefixLen);


/********************************************
功能：以太网测试端口参数设置，这个函数提供一种设置端口详细参数的方法。
      若只设置测试端口和DUT端口的一个IPv4地址或IPv6地址，请使用函数
	  ResPortSetIPv4Address或ResPortSetIPv6Address。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pPortEth：要设置的以太网端口参数结构指针;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  RES_ERROR_NOT_SAME_SUBNET表示测试端口和DUT端口的IP地址不属于同一个网段，
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS表示地址池中的最后IPv4地址超出255.255.255.255，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetup(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth);


COM_EXPORT ULONG ResPortDhcpSerEnable(ULONG ulChsId,ULONG ulSlotId,ULONG ulPortId,BOOL bEnable);


/********************************************
功能：设置指定端口的媒介类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  bCopper：媒介类型，TRUE表示电媒介，FALSE表示光媒介；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_NOT_SUPPORT表示指定端口不支持设置媒介类型，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口没有预约，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG ResSetPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bCopper);


/********************************************
功能：设置指定端口的媒介类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  bCopper：媒介类型，TRUE表示电媒介，FALSE表示光媒介；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_NOT_SUPPORT表示指定端口不支持设置媒介类型，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口没有预约，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG ResGetPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL* bCopper);



/********************************************
功能：设置同一张板卡内的多个端口的媒介类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  pulPortId：端口号指针，1-based;
	  ulPortCount：pulPortId指向的端口数目；
	  bCopper：媒介类型，TRUE表示电媒介，FALSE表示光媒介；
	  pulRetCode：端口设置结果返回值指针;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_NOT_SUPPORT表示指定端口不支持设置媒介类型，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口没有预约，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG ResSetMultiPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG pulPortId[], ULONG ulPortCount, BOOL bCopper, ULONG pulRetCode[]);


/********************************************
功能：以太网测试端口参数设置，这个函数提供一种设置端口详细参数的方法。
      若只设置测试端口和DUT端口的一个IPv4地址或IPv6地址，请使用函数
	  ResPortSetIPv4Address或ResPortSetIPv6Address。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pPortEth：要设置的以太网端口参数结构指针;
	  bResetPhy：表示是否要重置端口的物理状态，对类型为RES_PORT_TYPE_GE_C的端口有效；
	  bSetPhy：表示pPortEth中bAutoNego、bFullDuplex、ulFlowCtrlType、ucRate参数是否有效，为FALSE将保留上一次的设置；
	  bSetIPv4Stack：表示IPv4协议栈相关参数是否有效，为FALSE将保留上一次的设置；
	  bSetIPv6Stack：表示IPv6协议栈相关参数是否有效，为FALSE将保留上一次的设置；
	  bSendArp：表示是否发送ARP请求，端口已预约时有效；
	  ulWaitTime：表示在发送ARP请求之前的等待的毫秒数，bSendArp为TRUE时有效(当bResetPhy或bSetPhy为TRUE时会造成端口down掉，此时无法保证ARP的成功处理，应适当增加等待时间)；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  RES_ERROR_NOT_SAME_SUBNET表示测试端口和DUT端口的IP地址不属于同一个网段，
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS表示地址池中的最后IPv4地址超出255.255.255.255，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetupEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth
		, BOOL bResetPhy, BOOL bSetPhy, BOOL bSetIPv4Stack, BOOL bSetIPv6Stack, BOOL bSendArp, ULONG ulWaitTime);

/********************************************
功能：以太网测试端口参数设置，这个函数提供一种设置端口详细参数的方法。
      若只设置测试端口和DUT端口的一个IPv4地址或IPv6地址，请使用函数
	  ResPortSetIPv4Address或ResPortSetIPv6Address。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pPortEth：要设置的以太网端口参数结构指针;
	  bResetPhy：表示是否要重置端口的物理状态，对类型为RES_PORT_TYPE_GE_C的端口有效；
	  bSetPhy：表示pPortEth中bAutoNego、bFullDuplex、ulFlowCtrlType、ucRate参数是否有效，为FALSE将保留上一次的设置；
	  bSetIPv4Stack：表示IPv4协议栈相关参数是否有效，为FALSE将保留上一次的设置；
	  bSetIPv6Stack：表示IPv6协议栈相关参数是否有效，为FALSE将保留上一次的设置；
	  bSendArp：表示是否发送ARP请求，端口已预约时有效；
	  ulWaitTime：表示在发送ARP请求之前的等待的毫秒数，bSendArp为TRUE时有效(当bResetPhy或bSetPhy为TRUE时会造成端口down掉，此时无法保证ARP的成功处理，应适当增加等待时间)；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  RES_ERROR_NOT_SAME_SUBNET表示测试端口和DUT端口的IP地址不属于同一个网段，
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS表示地址池中的最后IPv4地址超出255.255.255.255，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetupSync(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth
		, BOOL bResetPhy, BOOL bSetPhy, BOOL bSetIPv4Stack, BOOL bSetIPv6Stack, BOOL bSendArp, ULONG ulWaitTime);


/********************************************
功能：等待指定机箱的端口设置操作完成
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulWaitTime：等待超时时间；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR_TIMEOUT表示等待超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResWaitForPhySetupFinish(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulWaitTime);


/********************************************
功能：获取以太网测试端口当前详细设置参数。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pPortEth：要设置的以太网端口参数结构指针;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortParameter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth);


/********************************************
功能：MDIO寄存器参数读取。
输入：ulChsId： 机箱ID，1-based；
      	  ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulRegisterAddr：寄存器地址;
	  pulReadData：读出数据;
	  ulWaitTime：超时时间
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
            FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  FD_ERROR表示其它错误。
注意：
*********************************************/

COM_EXPORT ULONG ResMdioReadEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulRegisterAddr, ULONG* pulReadData, ULONG ulWaitTime);


/********************************************
功能：MDIO寄存器参数读取。
输入：ulChsId： 机箱ID，1-based；
      	  ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulRegisterAddr：寄存器地址;
	  ulWriteData：写入数据;
	  ulWaitTime：超时时间
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_RUNNING_TEST表示正在运行测试，
            FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  FD_ERROR表示其它错误。
注意：
*********************************************/

COM_EXPORT ULONG ResMdioWriteEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulRegisterAddr, ULONG ulWriteData, ULONG ulWaitTime);


/********************************************
功能：设置服务器端主动推送的端口物理参数的有效时间。
输入：ulExpireTime：端口物理参数的有效时间;
输出：无
返回：上一次（或默认的）设置的过期时间。
注意：
*********************************************/
COM_EXPORT ULONG ResSetPhyParamExpireTime(ULONG ulExpireTime);


/********************************************
功能：在指定以太网端口上发送ARP请求
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulIpIndex：IP地址序号，表示为指定端口IPv4地址池的第几个IP发送请求，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口还没有预定。
注意：
*********************************************/
COM_EXPORT ULONG ResSendArpRequest(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulIpIndex);


/********************************************
功能：在指定以太网端口上发送NDP请求
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulIpIndex：IP地址序号，表示为指定端口IPv4地址池的第几个IP发送请求，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_TYPE表示端口类型错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口还没有预定。
注意：
*********************************************/
COM_EXPORT ULONG ResSendNdpNS(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulIpIndex);


/********************************************
功能：发送报文。该函数构造好一个完整的报文，然后交给硬件发送
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPacket：要发送的报文码流;
	  ulPacketLen：要发送的报文的长度；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定接口卡没有预约，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResSendPacket(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR* pucPacket, ULONG ulPacketLen);


/********************************************
功能：开始指定端口的PINGv4功能
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulTargetIp：需要PING的目标IPv4地址;
	  ucPingType：PING的类型，RES_PING_INTERVAL表示按时间间隔，RES_PING_CONTINUOUS表示连续；
	  ulDataSize：PING数据的大小，取值范围为1 - 65000；
	  bIncrement：PING数据大小是否递增
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口没有预约，
	  RES_ERROR_PING_TYPE表示输入的ucPingType错误，
	  RES_ERROR_PING_DATA_SIZE表示输入的ulDataSize错误
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResStartPing4(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulTargetIp, UCHAR ucPingType, ULONG ulDataSize, BOOL bIncrement);


/********************************************
功能：停止指定端口的PINGv4功能
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResStopPing4(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：获取指定端口PINGv4功能的统计状态
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pulTargetIp：上一次开启PINGv4功能时的目标IPv4地址，为NULL表示参数无效
	  pulSuccessCount：上一次开启PINGv4功能到此次获取状态时PING的成功次数，为NULL表示参数无效
	  pulFailCount：上一次开启PINGv4功能到此次获取状态时PING的失败次数，为NULL表示参数无效
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：在PING的过程中以及停止之后均可使用该函数
*********************************************/
COM_EXPORT ULONG ResGetPing4State(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulTargetIp, ULONG *pulSuccessCount, ULONG *pulFailCount);


/********************************************
功能：开始指定端口的PINGv6功能
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucTargetIp：需要PING的目标IPv6地址;
	  ucPingType：PING的类型，RES_PING_INTERVAL表示按时间间隔，RES_PING_CONTINUOUS表示连续；
	  ulDataSize：PING数据的大小，取值范围为1 - 1452；
	  bIncrement：PING数据大小是否递增
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口没有预约，
	  RES_ERROR_PING_TYPE表示输入的ucPingType错误，
	  RES_ERROR_PING_DATA_SIZE表示输入的ulDataSize错误
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResStartPing6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTargetIp, UCHAR ucPingType, ULONG ulDataSize, BOOL bIncrement);


/********************************************
功能：停止指定端口的PINGv6功能
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResStopPing6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：获取指定端口PINGv6功能的统计状态
输入：ulChsId：机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pucTargetIp：上一次开启PINGv6功能时的目标IPv6地址，为NULL表示参数无效
	  pulSuccessCount：上一次开启PINGv6功能到此次获取状态时PING的成功次数，为NULL表示参数无效
	  pulFailCount：上一次开启PINGv6功能到此次获取状态时PING的失败次数，为NULL表示参数无效
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：在PING的过程中以及停止之后均可使用该函数
*********************************************/
COM_EXPORT ULONG ResGetPing6State(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucTargetIp[16], ULONG *pulSuccessCount, ULONG *pulFailCount);


/********************************************
功能：获取指定端口的物理层参数。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucParamType：物理层参数类型，0表示自协商参数，1表示双工参数，2表示流控参数，3表示速率参数，4表示操作模式，5表示端口状态;
输出：pulParamValue：指定参数输出值指针。自协商为TRUE，非自协商为FALSE；全双工为TRUE，半双工为FALSE；
                     流控为TRUE，非流控为FALSE；RES_PORT_RATE_10表示10M，RES_PORT_RATE_100表示100M，
					 RES_PORT_RATE_1000表示1000M；RES_PORT_OPMODE_NORMAL表示正常操作模式，
					 RES_PORT_OPMODE_INTERNAL_LOOPBACK表示自环；RES_LINK_STATE_DOWN表示端口状态为down，
					 RES_LINK_STATE_UP表示端口状态为up，RES_LINK_STATE_NA表示端口状态未知
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示机箱中真实槽位没有接口卡
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucParamType, ULONG *pulParamValue);

// 带超时时间
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameterEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucParamType, ULONG *pulParamValue, ULONG ulWaitTime );


/********************************************
功能：获取指定端口的多个物理层参数。
输入：ulChsId： 机箱ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulParamNum：需要获取的物理层参数个数
	  pucParamType：物理层参数类型，0表示自协商参数，1表示双工参数，2表示流控参数，3表示速率参数，4表示操作模式，5表示端口状态;
输出：pulParamValue：指定参数输出值指针。自协商为TRUE，非自协商为FALSE；全双工为TRUE，半双工为FALSE；
                     流控为TRUE，非流控为FALSE；RES_PORT_RATE_10表示10M，RES_PORT_RATE_100表示100M，
					 RES_PORT_RATE_1000表示1000M；RES_PORT_OPMODE_NORMAL表示正常操作模式，
					 RES_PORT_OPMODE_INTERNAL_LOOPBACK表示自环；RES_LINK_STATE_DOWN表示端口状态为down，
					 RES_LINK_STATE_UP表示端口状态为up，RES_LINK_STATE_NA表示端口状态未知
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  RES_ERROR_PORT_MODE表示指定端口不是以太网端口，
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT表示机箱中真实槽位没有接口卡
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameters(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulParamNum, UCHAR *pucParamType, ULONG *pulParamValue);

// 带超时时间
COM_EXPORT ULONG ResGetEthernetPortPhysicalParametersEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulParamNum, UCHAR *pucParamType, ULONG *pulParamValue, ULONG ulWaitTime );


/********************************************
功能：启动协议仿真，目前支持的协议有：IGMP、RIPv2&RIPng、OSPFv2、BGP
输入：无
输出：无
返回：无
注意：每个协议在注册了相应的协议Licesne后才生效
*********************************************/
COM_EXPORT void StartProtocolEmulation();


/********************************************
功能：停止协议仿真，目前支持的协议有：IGMP、RIPv2&RIPng、OSPFv2、BGP
输入：无
输出：无
返回：无
注意：每个协议在注册了相应的协议Licesne后才生效
*********************************************/
COM_EXPORT void StopProtocolEmulation();


/********************************************
功能：允许Tele系列软件GUI应用程序对指定机箱中由本地所开启的流量统计进行实时监测
输入：ulChsId： 机箱ID，1-based；当‘ulChsId == INVALID_CHASSIS_ID’时将对所有已添加的机箱有效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG EnableGUIMonitor(ULONG ulChsId);


/********************************************
功能：禁止Tele系列软件GUI应用程序对指定机箱中由本地所开启的流量统计进行实时监测
输入：ulChsId： 机箱ID，1-based；当‘ulChsId == INVALID_CHASSIS_ID’时将对所有已添加的机箱有效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG DisableGUIMonitor(ULONG ulChsId);


/********************************************
功能：允许本机不同用户重复预约同一端口，之前预约的用户将被释放
输入：ulChsId： 机箱ID，1-based；当‘ulChsId == INVALID_CHASSIS_ID’时将对所有已添加的机箱有效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG EnablePortReuse(ULONG ulChsId);


/********************************************
功能：禁止本机不同用户重复预约同一端口
输入：ulChsId： 机箱ID，1-based；当‘ulChsId == INVALID_CHASSIS_ID’时将对所有已添加的机箱有效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG DisablePortReuse(ULONG ulChsId);


/********************************************
功能：获取指定机箱上服务器针对本地用户的唯一标识ID
输入：ulChsId： 机框ID，1-based；
输出：pulUserId：用户ID指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG ResGetServerUserId(ULONG ulChsId, ULONG *pulUserId);


/********************************************
功能：上传许可文件
输入：ulChsId：机箱ID，1-based；
      strLicenseFilePath：许可文件的本地存放全路径;
	  bOverwriteIfExists：指示当有重名License文件时是否覆盖，如果为TRUE，则直接覆盖无提示；如果为FALSE，则当有重名时，返回ERROR;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR_FILE_NOT_EXIST表示许可文件不存在，
	  FD_ERROR_FILE_CONTENT表示输入的License文件格式不正确，
	  FD_ERROR_FILE_BAD_HASH表示输入的License文件HASH校验不通过，
	  FD_ERROR_LICENSE_EXPIRES表示License文件已过期，
	  FD_ERROR_DUPLICATE_LICENSE表示License文件名重复，仅当参数OverwriteIfExisits才可能返回该错误值，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG UploadLicense(ULONG ulChsId, const char *strLicenseFilePath, BOOL bOverwriteIfExists);


/********************************************
功能：删除许可文件
输入：ulChsId：机箱ID，1-based；
      strLicenseFileName：指定的License文件的文件名，用于指定删除机箱上多个License文件中的一个。如果该参数为空（NULL）,则删除所有的License文件;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR_FILE_NOT_EXIST表示许可文件不存在，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG DeleteLicense(ULONG ulChsId, const char *strLicenseFileName);


/********************************************
功能：获取许可文件名列表
输入：ulChsId：机箱ID，1-based；
输出：pstrLicenseFileList：许可文件名列表的指针
      pulCount：许可文件名列表的文件名数目
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG GetLicenseList(ULONG ulChsId, char ***pstrLicenseFileList, ULONG *pulCount);


/********************************************
功能：释放获取到的许可文件名列表的内存空间
输入：strLicenseFileList：许可文件名列表的指针；
      ulCount：许可文件名列表的文件名数目；
输出：无
返回：无
注意：
*********************************************/
COM_EXPORT void FreeLicenseList(char **strLicenseFileList, ULONG ulCount);


/********************************************
功能：下载许可文件
输入：ulChsId：机箱ID，1-based；
      strLicenseFileName：指定的License文件的文件名；
      strLicenseFilePath：许可文件的本地存放全路径；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  RES_ERROR_IS_DISCONNECTED_CHASSIS表示机箱未连接，
	  FD_ERROR_FILE_NOT_EXIST表示许可文件不存在，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG DownloadLicense(ULONG ulChsId, const char *strLicenseFileName, const char *strLicenseFilePath);
#endif


#ifdef __FOR_CSHARP
}
#endif
