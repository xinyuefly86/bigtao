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


//��������
enum {
	RES_CHASSIS_TYPE_220 = 0, 
	RES_CHASSIS_TYPE_6000,
	RES_CHASSIS_TYPE_12000,
	RES_CHASSIS_TYPE_ITESTER_12000, //12��λ���ػ�����
	RES_CHASSIS_TYPE_ITESTER_6000, //6��λ���ػ�����
	RES_CHASSIS_TYPE_OTHER, // ����PC����
	RES_CHASSIS_TYPE_STORM_200,
	RES_CHASSIS_TYPE_STORM_6000,
	RES_CHASSIS_TYPE_STORM_12000,
	RES_CHASSIS_TYPE_6200, 
	RES_CHASSIS_TYPE_COUNT // ��ǰ��Ч������������
};


//�ӿڿ�����
enum {
	RES_CARD_TYPE_T6012C = 0,  // 12*GE Copper, 0x1
	RES_CARD_TYPE_T6012F,      // 12*GE Fiber, 0x2
	RES_CARD_TYPE_T6012M,      // 12*GE Dual Medial, 0x3
	RES_CARD_TYPE_T8004F,      // 4*10GE Fiber, 0x4
	RES_CARD_TYPE_GT5101,      // 4�˿�GE���, 0x5
	RES_CARD_TYPE_GT5102,      // 4�˿�GE/FE���, 0x6
	RES_CARD_TYPE_GT6101,      // 2�˿�10GE���, 0x7
	RES_CARD_TYPE_GT6102,      // 4�˿�10GE���, 0x8
	RES_CARD_TYPE_T6008C,  	   // 8*GE Copper, 0x9
	RES_CARD_TYPE_T6008F,      // 8*GE Fiber, 0xa
	RES_CARD_TYPE_T6008M,      // 8*GE Dual Medial, 0xb
	RES_CARD_TYPE_T6004C,      // 4*GE Copper, 0xc
	RES_CARD_TYPE_T8002F,      // 2*10GE Fiber, 0xd
	RES_CARD_TYPE_GT5103,      // 4�˿�GE���, 0xe
	RES_CARD_TYPE_T6108F,      // 8*GE/FE Fiber, 0xf
	RES_CARD_TYPE_H6004C,      // 4*GE Copper, 0x10
	RES_CARD_TYPE_H6004F,      // 4*GE Fiber, 0x11
	RES_CARD_TYPE_GT6103,      // 2�˿�10GE���, 0x12
	RES_CARD_TYPE_V9002F40G,   // 2*40GE Fiber, 0x13 ��40G�忨
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
	RES_CARD_TYPE_VSD6008C,    // 8*GE Copper 0x23 ���ڵ���
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
	RES_CARD_TYPE_COUNT,       // ��ǰ��Ч�忨��������
};


#define RES_CARD_TYPE_OTHER		(255)


//�˿�����
enum {
	RES_PORT_TYPE_FE_C = 0, //FE��ڣ���������100M�ӿڰ��ϵĵ��
	RES_PORT_TYPE_FE_F,//FE��ڣ���������100M�ӿڰ��ϵĹ�� 
	RES_PORT_TYPE_GE_C,//GE��� 
	RES_PORT_TYPE_GE_F,//GE���
	RES_PORT_TYPE_10GELAN,//10GELAN�����
	RES_PORT_TYPE_10GEWAN,//10GEWAN�����
	RES_PORT_TYPE_10GE_C,//10GE���	
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


//�˿�ģʽ
enum {
	RES_PORT_MODE_ETHERNET = 0, 
	RES_PORT_MODE_POS, 
	RES_PORT_MODE_ATM
};


//�˿�link״̬
enum {
	RES_LINK_STATE_NA = 0, 
	RES_LINK_STATE_DOWN,
	RES_LINK_STATE_UP
};


//��̫���˿�����
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

//POS�˿�����
enum {
	RES_PORT_POS_RATE_155 = 0, 
	RES_PORT_POS_RATE_622, 
	RES_PORT_POS_RATE_2500, 
	RES_PORT_POS_RATE_10000
};
	

//�˿ڹ���ģʽ
enum {
	RES_PORT_OPMODE_NORMAL = 0, 
	RES_PORT_OPMODE_INTERNAL_LOOPBACK, 
	RES_PORT_OPMODE_EXTERNAL_LOOPBACK
};


//CRC���ͣ�����POS�˿�����
enum {
	RES_CRC_16 = 0, 
	RES_CRC_32,
	RES_CRC_NO 
};


//ʱ�����ͣ�����POS�˿�����
enum {
	RES_CLOCK_INTERNAL = 0, 
	RES_CLOCK_LINE_RECOVER
};


//Framing Mode������POS�˿�����
enum {
	RES_FM_SONET = 0, 
	RES_FM_SDH
};


//PPP״̬������POS�˿�����
enum {
	RES_PPP_DISABLE = 0, 
	RES_PPP_NA, 
	RES_PPP_CLOSE, 
	RES_PPP_OPEN, 
	RES_PPP_REQ_SENT,//������������
	RES_PPP_ACK_RCVD,//������������
	RES_PPP_ACK_SENT//������������
};


//PPP״̬���ͣ�����POS�˿�����
enum 
{
	PPP_STATE_TYPE_LCP = 0, 
	PPP_STATE_TYPE_IPCP,
	PPP_STATE_TYPE_IPV6CP, 
	PPP_STATE_TYPE_MPLSCP, 
	PPP_STATE_TYPE_OSINLCP
};


//�����װ����, ������̫���˿�����
enum {
	RES_FAMING_E2 = 0, 
	RES_FAMING_8023
};


//�����װ����, ����POS�˿�����
enum {
	RES_FAMING_PPP = 0, 
	RES_FAMING_CHDLC//Cisco HDLC
};

//�˿�PING���ܵ�����
enum{
	RES_PING_INTERVAL = 0,
	RES_PING_CONTINUOUS,
};

//�˿����ع��ܵ�����
enum{
	RES_FLOW_CTRL_DISABLE = 0,
	RES_FLOW_CTRL_ENABLE,
	RES_FLOW_CTRL_NEGO
};

//�����Է���ARP���ĵ�����
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

//�����Է���NDP���ĵ�����
enum
{
	NDP_TYPE_NONE = 0,
	NDP_TYPE_NS,
	NDP_TYPE_NA,
	NDP_TYPE_NS_NA,
};

//Xϵ�п��˷���ģʽ
enum{
	RES_CORE_MODE_DYNAMIC = 0,
	RES_CORE_MODE_STATIC
};

#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct tag_PORT_ETH
{
	BOOL   bAutoNego;//�Ƿ�ʹ����Э��  P�忨0:ǿ�ƴ� 2:ǿ���� 1:��Э��reapter 5:��Э��DTE
	BOOL   bFullDuplex;//�Ƿ�ʹ��ȫ˫��
	ULONG  ulFlowCtrlType;//�������ͣ�RES_FLOW_CTRL_DISABLE��ʾ��ʹ�ܣ�RES_FLOW_CTRL_ENABLE��ʾʹ�ܣ�RES_FLOW_CTRL_NEGO��ʾЭ��
	UCHAR  ucRate;//����ȡ��ֵΪ��RES_PORT_RATE_10��RES_PORT_RATE_100��RES_PORT_RATE_1000��RES_PORT_RATE_10000;
//	UCHAR  ucOperateMode;//����ȡ��ֵΪ��RES_PORT_OPMODE_NORMAL��RES_PORT_OPMODE_INTERNAL_LOOPBACK

	BOOL   bIPv4Enable;//�Ƿ�ʹ��IPv4Э��ջ
	UCHAR  ucIPv4AddrMap;//���Զ˿�IPv4��ַ��DUT�˿�IPv4��ַ�Ķ�Ӧ��ϵ��0��ʾmany->one��1��ʾmany->many
	UCHAR  ucIPv4PrefixLen;//IPv4��ַ���볤�ȣ�ȡֵ��ΧΪ1--32
	ULONG  ulIPv4PortFirstAddr;//���Զ˿ڵ���ʼIPv4��ַ
	ULONG  ulIPv4PortAddrCount;//���Զ˿�IPv4��ַ��Ŀ����ucIPv4AddrMap==0ʱȡֵ��ΧΪ1--65536����ucIPv4AddrMap==1ʱȡֵ��ΧΪ1--8192����ucIPv4AddrMap==1ʱҲ������DUT
	UCHAR  ucIPv4PortAddrModBit;//���Զ˿�IPv4��ַ�����bitλ��ȡֵ��ΧΪ1--32����ucIPv4AddrMap==1ʱҲ������DUT
	UCHAR  ucIPv4PortAddrModStep;//���Զ˿�IPv4��ַ����Ĳ�����ȡֵ��ΧΪ1--255����ucIPv4AddrMap==1ʱҲ������DUT
	ULONG  ulIPv4DutFirstAddr;//DUT�˿���ʼIPv4��ַ
	BOOL   bIPv4Vlan;//�Ƿ�ʹ��IPv4Э��ջ��VLAN����
	USHORT usIPv4FirstVlanId;//IPv4Э��ջ����ʼVLAN ID��ȡֵ��Χ��0--4094
	USHORT usIPv4VlanIdStep;//IPv4Э��ջVLAN ID�����䲽����ȡֵ��Χ��1--4094, ����ucIPv4AddrMap==1ʱ��Ч
	BOOL   bIPv4UniqueMacAddr;//IPv4Э��ջ��ÿ���ӿ��Ƿ�����һ����ͬ��MAC��ַ
	UCHAR  ucaIPv4FirstMacAddr[6];//���Զ˿�IPv4Э��ջ����ʼMAC��ַ��
	UCHAR  ucIPv4MacAddrModBit;//���Զ˿�IPv4 MAC��ַ�����bitλ��ȡֵ��ΧΪ1--48
	UCHAR  ucIPv4MacAddrModStep;//���Զ˿�IPv4 MAC��ַ����Ĳ�����ȡֵ��ΧΪ0--255
	BOOL   bSendGratArp;//�Ƿ������ARP
	BOOL   bSendArpReply;//�Ƿ��ARP Request����Ӧ��
	ULONG  ulPeriodArpType;//�����Է��͵�ARP�������ͣ�0��ʾ��ʹ�ܣ�1��ʾGratuitous ARP(GRAT)��2��ʾARP Request(REQUEST)��3��ʾARP Reply(REPLY)��
						   //4��ʾGRAT + REQUEST��5��ʾGRAT + REPLY��6��ʾREQUEST + REPLY��7��ʾGRAT + REQUEST + REPLY��Ĭ��ֵΪ0
	USHORT usPeriodArpFrequency;//�����Է���ָ������ARP���ĵ�ʱ��Ƶ�ʣ���λΪ�룬ȡֵ��Χ1--65535
	USHORT usIPv4SendArpRate;//���Զ˿ڷ���ARP���ĵ����ʣ���packets/sΪ��λ��ȡֵ��Χ1--10000

	BOOL   bIPv6Enable;//�Ƿ�ʹ��IPv6Э��ջ
	UCHAR  ucIPv6AddrMap;//���Զ˿�IPv6��ַ��DUT�˿�IPv6��ַ�Ķ�Ӧ��ϵ��0��ʾmany->one��1��ʾmany->many
	UCHAR  ucaIPv6PortFirstAddr[16];//���Զ˿ڵ���ʼIPv6��ַ����������Ĭ��Ϊ64λ
	UCHAR  ucIPv6PrefixLen;//IPv6��ַ���볤�ȣ�ȡֵ��ΧΪ1--128
	ULONG  ulIPv6PortAddrCount;//���Զ˿�IPv6��ַ��Ŀ����ucIPv6AddrMap==0ʱȡֵ��ΧΪ1--65536����ucIPv6AddrMap==1ʱȡֵ��ΧΪ1--8192����ucIPv6AddrMap==1ʱҲ������DUT
	UCHAR  ucIPv6PortAddrModBit;//���Զ˿�IPv6��ַ�����bitλ����ucIPv6AddrMap==0ʱȡֵ��ΧΪ97--128����ucIPv6AddrMap==1ʱȡֵ��ΧΪ33--64����ucIPv6AddrMap==1ʱҲ������DUT
	UCHAR  ucIPv6PortAddrModStep;//���Զ˿�IPv6��ַ����Ĳ�����ȡֵ��ΧΪ1--255����ucIPv6AddrMap==1ʱҲ������DUT
	UCHAR  ucaIPv6DutFirstAddr[16];//DUT�˿���ʼIPv6��ַ
	BOOL   bIPv6Vlan;//�Ƿ�ʹ��IPv6Э��ջ��VLAN����
	USHORT usIPv6FirstVlanId;//IPv6Э��ջ����ʼVLAN ID��ȡֵ��Χ��0--4094
	USHORT usIPv6VlanIdStep;//IPv6Э��ջVLAN ID�����䲽����ȡֵ��Χ��1--4094, ����ucIPv6AddrMap==1ʱ��Ч
	BOOL   bIPv6UniqueMacAddr;//IPv6Э��ջ��ÿ���ӿ��Ƿ�����һ����ͬ��MAC��ַ
	UCHAR  ucaIPv6FirstMacAddr[6];//���Զ˿�IPv6Э��ջ����ʼMAC��ַ��
	UCHAR  ucIPv6MacAddrModBit;//���Զ˿�IPv6 MAC��ַ�����bitλ��ȡֵ��ΧΪ1--48
	UCHAR  ucIPv6MacAddrModStep;//���Զ˿�IPv6 MAC��ַ����Ĳ�����ȡֵ��ΧΪ0--255
	BOOL   bSendGratNa;//�Ƿ������NA
	BOOL   bSendNa;//�Ƿ��neighbor solicitation����Ӧ��
	ULONG  ulPeriodNdpType;//�����Է��͵�NDP�������ͣ�0��ʾ��ʹ�ܣ�1��ʾNeighbor Solicitation(NS)��2��ʾNeighbor Advertisement(NA)��3��ʾNS + NA��Ĭ��ֵΪ0
	USHORT usPeriodNdpFrequency;//�����Է���ָ������NDP���ĵ�ʱ��Ƶ�ʣ���λΪ�룬ȡֵ��Χ1--65535
	USHORT usIPv6SendNdpRate;//���Զ˿ڷ���NDP���ĵ����ʣ���packets/sΪ��λ��ȡֵ��Χ1--10000
} PORT_ETH_S;


/********************************************
���ܣ���ʼ������ģ�顣��ʼ����TeleApi.dllʱ��Ҫ�ȵ��øú���
���룺��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�FD_ERROR��
ע�⣺
*********************************************/
COM_EXPORT ULONG InitAllModules();


/********************************************
���ܣ�ɾ������ģ��
���룺��
�������
���أ���
ע�⣺���н���ʱ��Ҫ���øú���
*********************************************/
COM_EXPORT void DeleteAllModules();


/********************************************
���ܣ����õ��Եȼ����ȼ�Խ�ߣ�����־��ϢԽ��ϸ
���룺nDebugLevel�����Եȼ�����ȡ��ֵΪ��LOG_EMERG��LOG_ALERT��LOG_CRIT��LOG_ERR��
	               LOG_WARNING��LOG_NOTICE��LOG_INFO��LOG_DEBUG��
�������
���أ�ԭ�ȵĵ��Եȼ�
ע�⣺Ĭ�ϵĵ��Եȼ�ΪLOG_ERR
*********************************************/
COM_EXPORT int SetDebugLevel(int nDebugLevel);


/********************************************
���ܣ����ñ����û���ʶID����ʹ�á�GUI Monitor'�ȹ���ʱ�ɸ��ݴ�ID�Բ�ͬ�û���������
���룺caUserID������ʶID��Ϊ��ֵʱ��ʾ���û���ʶID����Ϊ���ؼ������
�������
���أ�ԭ�ȵ��û���ʶID
ע�⣺Ĭ�ϵ��û���ʶIDΪ���ؼ������
*********************************************/
COM_EXPORT const char *SetUserID(const char *caUserID);


/********************************************
���ܣ����������ļ�
���룺pcFilePath�������ļ�·������׺Ϊcfg
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_FILE_EXT��ʾ������ļ�����׺����(ӦΪ'cfg');
	  FD_ERROR_RUNNING_TEST��ʾ�������в���, 
	  FD_ERROR_PINGING��ʾ��������Ping, 
	  FD_ERROR_FILE_CONTENT��ʾ�ļ����ݴ���, 
	  RES_ERROR_HAVE_CONNECTED_CHASSIS��ʾ�����ѽ���TCP���ӵĻ���
ע�⣺
*********************************************/
COM_EXPORT ULONG LoadConfigFile(const char *pcFilePath);

/********************************************
���ܣ����������ļ�
���룺pcFilePath�������ļ�·������׺Ϊcfg
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_FILE_EXT��ʾ������ļ�����׺����(ӦΪ'cfg');
	  FD_ERROR_RUNNING_TEST��ʾ�������в���, 
	  FD_ERROR_PINGING��ʾ��������Ping, 
	  FD_ERROR_FILE_CONTENT��ʾ�ļ����ݴ���, 
	  RES_ERROR_HAVE_CONNECTED_CHASSIS��ʾ�����ѽ���TCP���ӵĻ���
ע�⣺
*********************************************/
COM_EXPORT ULONG LoadConfigFileW(const wchar_t *pcFilePath);


/********************************************
���ܣ����������ļ�
���룺pcFilePath�������ļ�·������׺Ϊcfg
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_FILE_EXT��ʾ������ļ�����׺����(ӦΪ'cfg');
	  FD_ERROR_RUNNING_TEST��ʾ�������в���, 
	  FD_ERROR_PINGING��ʾ��������Ping
ע�⣺
*********************************************/
COM_EXPORT ULONG SaveConfigFile(const char *pcFilePath);

/********************************************
���ܣ����������ļ�
���룺pcFilePath�������ļ�·������׺Ϊcfg
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_FILE_EXT��ʾ������ļ�����׺����(ӦΪ'cfg');
	  FD_ERROR_RUNNING_TEST��ʾ�������в���, 
	  FD_ERROR_PINGING��ʾ��������Ping
ע�⣺
*********************************************/
COM_EXPORT ULONG SaveConfigFileW(const wchar_t *pcFilePath);


/********************************************
���ܣ���ӻ���
���룺ulType���������͡����������У�RES_CHASSIS_TYPE_220��RES_CHASSIS_TYPE_6000��RES_CHASSIS_TYPE_12000��
			RES_CHASSIS_TYPE_ITESTER_12000��RES_CHASSIS_TYPE_ITESTER_6000��RES_CHASSIS_TYPE_OTHER��
      ulIpAddr�������������IP��ַ��
�����pulChassisId������IDָ�룬1-based
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      RES_ERROR_CHASSIS_TYPE��ʾ�����ulType����
	  RES_ERROR_CHASSIS_SAME_IP_ADDR��ʾ������ͬ��IP��ַ��
	  RES_ERROR_CHASSIS_EXCEED_MAX_COUNT��ʾ������������������ֵ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisAdd(ULONG ulType, ULONG ulIpAddr, ULONG *pulChassisId);


/********************************************
���ܣ���ָ�����佨��TCP����
���룺ulChsId������ID��1-based��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_CHASSIS_TYPE_MISMATCH��ʾʵ�ʵĻ������ͺ�GUI�����õĲ�һ�£�
	  RES_ERROR_OLD_SERVER_VERSION��ʾ����������汾̫�ϣ�
	  RES_ERROR_OLD_LOGIC_VERSION��ʾ�߼�����汾̫�ϣ�
	  RES_ERROR_OLD_CLIENT_VERSION��ʾ�ͻ�������汾̫�ϣ�
	  RES_ERROR_CHASSIS_CONNECT_FAIL��ʾ����TCP����ʧ�ܣ�
	  RES_ERROR_LICENSE_MISMATCHED��ʾ����License��ƥ�䡣
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisConnect(ULONG ulChsId);


/********************************************
���ܣ���������
���룺ulChsId������ID��1-based��
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER��ʾ���ڱ������û�ԤԼ�Ķ˿�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisReboot(ULONG ulChsId);


/********************************************
���ܣ��رջ���
���룺ulChsId������ID��1-based��
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER��ʾ���ڱ������û�ԤԼ�Ķ˿�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisShutDown(ULONG ulChsId);


/********************************************
���ܣ�����ָ�������ڵ�TeleManager���������
���룺ulChsId������ID��1-based��
	  pcFilePath��TeleManager�����������·��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_FILE_NOT_EXIST��ʾ�޷���ָ����TeleManager�����������·��
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER��ʾ���ڱ������û�ԤԼ�Ķ˿�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisUpdate(ULONG ulChsId, const char *pcFilePath);


/********************************************
���ܣ�����ָ�������ڵ�TeleManager���������
���룺ulChsId������ID��1-based��
	  pcFilePath��TeleManager�����������·��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_FILE_NOT_EXIST��ʾ�޷���ָ����TeleManager�����������·��
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER��ʾ���ڱ������û�ԤԼ�Ķ˿�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisUpdateW(ULONG ulChsId, const wchar_t *pcFilePath);


/********************************************
���ܣ���¼��ָ�������У���ù���ԱȨ��
���룺ulChsId������ID��1-based��
	  caUsername����¼�û�������ʼ����Ϊ��teletest��
	  caPassword����¼���룬��ʼ����Ϊ��teletest��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_USERNAME��ʾ�ṩ���û�������
	  FD_ERROR_PASSWORD��ʾ�ṩ���������
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisLogin(ULONG ulChsId, const char *caUsername, const char *caPassword);


/********************************************
���ܣ��޸ĵ�ָ�������й���Ա��¼��Ϣ
���룺ulChsId������ID��1-based��
	  caOldUsername���ɵĵ�¼�û���
	  caOldPassword���ɵĵ�¼����
	  caNewUsername���µĵ�¼�û���
	  caNewPassword���µĵ�¼����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_USERNAME��ʾ�ṩ���û�������
	  RES_ERROR_PASSWORD��ʾ�ṩ���������
	  FD_ERROR_ACCESS_DENY��ʾδ��¼��
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  FD_ERROR��ʾ��������
ע�⣺�����ѵ�¼��ָ��������
*********************************************/
COM_EXPORT ULONG ResChassisModifyLoginInfo(ULONG ulChsId, const char *caOldUsername, const char *caOldPassword, const char *caNewUsername, const char *caNewPassword);


/********************************************
���ܣ���ָ���������˳���¼���ͷŹ���ԱȨ��
���룺ulChsId������ID��1-based��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisLogout(ULONG ulChsId);


/********************************************
���ܣ�����Ƿ��ѵ�¼��ָ������
���룺ulChsId������ID��1-based��
�����pbLogined��ָʾ�Ƿ��ѵ�¼��ָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResIsChassisLogined(ULONG ulChsId, BOOL *pbLogined);


/********************************************
���ܣ���ָ������Ͽ�TCP����
���룺ulChsId������ID��1-based��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisDisconnect(ULONG ulChsId);


/********************************************
���ܣ��������Ƿ�������״̬
���룺ulChsId������ID��1-based��
�����pbConnected TRUE��ʾ��������״̬
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResIsChassisConnected(ULONG ulChsId, BOOL* pbConnected);


/********************************************
���ܣ�ɾ��ָ���Ļ���
���룺ulChsId������ID��1-based��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
	  RES_ERROR_IS_CONNECTED_CHASSIS��ʾָ�������ѽ���TCP���ӡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisRemove(ULONG ulChsId);


/********************************************
���ܣ���ȡ�������ID
���룺ulChsId������ID��1-based��
�����
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetChassisRandID(ULONG ulChsId,ULONG* pulRandId);


/********************************************
���ܣ�����ָ���Ļ���Ĺ������ڵ�IP��ַ
���룺ulChsId������ID��1-based��
      ulIpAddr������Ĺ�������IP��ַ
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_CONNECTED_CHASSIS��ʾָ�������ѽ���TCP���ӡ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResChassisSetIpAddress(ULONG ulChsId, ULONG ulIpAddr);


/********************************************
���ܣ���ӽӿڿ�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulCardType: ��16bit��ʾ �ӿڿ����͡��ӿڿ������У�RES_CARD_TYPE_T6012C��RES_CARD_TYPE_T6012F��RES_CARD_TYPE_T6012M��
			RES_CARD_TYPE_T8004F��RES_CARD_TYPE_GT5101��RES_CARD_TYPE_GT5102��RES_CARD_TYPE_GT6101��
			RES_CARD_TYPE_GT6102��RES_CARD_TYPE_T6008C��RES_CARD_TYPE_T6008F��RES_CARD_TYPE_T6008M��
			RES_CARD_TYPE_T6004C;
			��16bit��ʾ �ӿڿ���FPGAģʽ V9��Ч ���ӿڿ���FPGAģʽ������:
	  		FPGA_DEFAULT,FPGA_10_G,FPGA_25_G,FPGA_40_G,FPGA_50_G,FPGA_100_G;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_HAD_CARD��ʾ�ò�λ�Ѿ��нӿڿ���
	  RES_ERROR_CARD_TYPE��ʾulCardType����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResCardAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulCardType);

/********************************************
���ܣ���ӽӿڿ�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulCardType: �ӿڿ����͡��ӿڿ������У�RES_CARD_TYPE_T6012C��RES_CARD_TYPE_T6012F��RES_CARD_TYPE_T6012M��
			RES_CARD_TYPE_T8004F��RES_CARD_TYPE_GT5101��RES_CARD_TYPE_GT5102��RES_CARD_TYPE_GT6101��
			RES_CARD_TYPE_GT6102��RES_CARD_TYPE_T6008C��RES_CARD_TYPE_T6008F��RES_CARD_TYPE_T6008M��
			RES_CARD_TYPE_T6004C;
	  ulFpgaType:�ӿڿ���FPGAģʽ���ӿڿ���FPGAģʽ������:
	  		FPGA_DEFAULT,FPGA_10_G,FPGA_25_G,FPGA_40_G,FPGA_50_G,FPGA_100_G;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_HAD_CARD��ʾ�ò�λ�Ѿ��нӿڿ���
	  RES_ERROR_CARD_TYPE��ʾulCardType����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResCardAddEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulCardType,ULONG ulFpgaType);



/********************************************
���ܣ���ȡ�����ӵ�ָ��������ָ���ӿڿ�����Ϣ
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
�����pCardType: �ӿڿ����͡��ӿڿ������У�RES_CARD_TYPE_T6012C��RES_CARD_TYPE_T6012F��RES_CARD_TYPE_T6012M��
			RES_CARD_TYPE_T8004F��RES_CARD_TYPE_GT5101��RES_CARD_TYPE_GT5102��RES_CARD_TYPE_GT6101��
			RES_CARD_TYPE_GT6102��RES_CARD_TYPE_T6008C��RES_CARD_TYPE_T6008F��RES_CARD_TYPE_T6008M��
			RES_CARD_TYPE_T6004C;
	  pPortCount: ��ʾ�ӿڿ������Ķ˿���
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetCardInfo(ULONG ulChsId, ULONG ulSlotId, ULONG *pulCardType, ULONG *pulPortCount);

/********************************************
���ܣ���ȡ�����ӵ�ָ��������ָ���ӿڿ���PPMֵ
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
�����piPpm
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetCardPPM(ULONG ulChsId, ULONG ulSlotId, int *piPpm);

/********************************************
���ܣ���ȡ�����ӵ�ָ��������ָ���ӿڿ���PPMֵ
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
	  piPpm:-100 - 100;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResSetCardPPM(ULONG ulChsId, ULONG ulSlotId, int iPpm);


/********************************************
���ܣ�ɾ��ָ���Ľӿڿ�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_HAS_NO_CARD��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_CARD_HAD_RESERVED��ʾ�ýӿڿ��Ѿ���Ԥ����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResCardRemove(ULONG ulChsId, ULONG ulSlotId);


/********************************************
���ܣ�����ָ���ӿڿ��ĺˣ�CPU������ģʽ
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulCoreMode���ˣ�CPU������ģʽ����ѡRES_CORE_MODE_DYNAMIC��RES_CORE_MODE_STATIC��Ĭ��ΪRES_CORE_MODE_DYNAMIC
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_NOT_SUPPORT��ʾָ���Ľӿڿ���֧�ִ����ã�
	  FD_ERROR_ACCESS_DENY��ʾδ��¼��
	  RES_ERROR_BUSY_OTHER_USER��ʾ�����û����ڲ����У���ʱ�޷�ת������ģʽ��
	  FD_ERROR_TIMEOUT��ʾ��ʱ, 
	  FD_ERROR��ʾ��������
ע�⣺������ͨ��ResChassisLogin�ӿڻ�ù���ԱȨ��
*********************************************/
COM_EXPORT ULONG ResSetCardCoreMode(ULONG ulChsId, ULONG ulSlotId, ULONG ulCoreMode);


/********************************************
���ܣ���ȡ�����ӵ�ָ��������ָ���ӿڿ���Fpga��Ϣ ����V9602
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
�����pulFpgaType:1:FPGA_40_G ��2:FPGA_100_G;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_CARD_LOADING_FPGA ��ʾ�ýӿڿ����ڼ���FPGA,
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetCardFpgaType(ULONG ulChsId, ULONG ulSlotId, ULONG* pulFpgaType);

/********************************************
���ܣ����������ӵ�ָ��������ָ���ӿڿ���Fpga��Ϣ ����V9602
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
�����pulFpgaType:  1:FPGA_40_G ��2:FPGA_100_G;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_CARD_LOADING_FPGA ��ʾ�ýӿڿ����ڼ���FPGA,
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺���������첽������������Fpga���ͺ���Ҫ����ResGetCardFpgaType �ж�Fpga�л��Ƿ���ɡ�
*********************************************/
COM_EXPORT ULONG ResSetCardFpgaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulFpgaType);

/********************************************
���ܣ����������ӵ�ָ��������ָ���ӿڿ���Fpga��Ϣ ����V9602
���룺ulChsId������ID��1-based��
	  ulSlotId: ��λ�ţ�1-based;
�����pulFpgaType:  1:FPGA_40_G ��2:FPGA_100_G;
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR��ʾ����������ڿ�ָ�룬
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_CARD_LOADING_FPGA ��ʾ�ýӿڿ����ڼ���FPGA,
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺�������apiֻ�ǰ�100G������ģʽ���浽�����ļ���������ɺ���Ҫ�������䡣
*********************************************/
COM_EXPORT ULONG ResSetCardFpgaTypeCfg(ULONG ulChsId, ULONG ulSlotId, ULONG ulFpgaType);

/********************************************
���ܣ�Ԥ��ָ���Ķ˿�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulPortId: �˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD��ʾ�ò�λ��û����ӽӿڿ���
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_HAD_RESERVED_BY_OTHER_USER��ʾ�ö˿��Ѿ��������û���Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortReserve(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
���ܣ���ѯָ���Ķ˿��Ƿ���ԤԼ
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulPortId: �˿ںţ�1-based;
�����pbReserved��TRUE��ʾ�˿���ԤԼ
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResIsPortReserved(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL* pbReserved);


/********************************************
���ܣ�Ԥ��ָ���Ķ˿�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulPortId: �˿ںţ�1-based;
	  bSetPhy����ʾ�˴�ԤԼ�Ƿ����ö˿ڵ��������
�����pPeerIp: ���˿��ѱ�ռ���򷵻�ռ��IP
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾָ������δ����TCP���ӣ�
	  RES_ERROR_HAS_NO_CARD��ʾ�ò�λ��û����ӽӿڿ���
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾʵ�ʻ������Ӧ��λ��û�в���ӿڿ���
	  RES_ERROR_PORT_HAD_RESERVED_BY_OTHER_USER��ʾ�ö˿��Ѿ��������û���Ԥ����
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortReserveEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bSetPhy, ULONG* pPeerIp);


/********************************************
���ܣ��ͷ���Ԥ����ָ���Ķ˿�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based;
	  ulPortId: �˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_HAS_NO_CARD��ʾ�ò�λ��û����ӽӿڿ���
	  FD_ERROR_TIMEOUT��ʾ��ʱ��
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortRelease(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ�����ǿ���ͷ��ѱ������û�ԤԼ�Ķ˿�
���룺ulChsId:  ����ID��1-based;
	  ulSlotId: ��λ�ţ�1-based��ΪINVALID_SLOT_ID��ʾ�ͷ�ָ�����������ж˿�;
	  ulPortId: �˿ںţ�1-based��ΪINVALID_PORT_ID��ʾ�ͷ�ָ���忨�����ж˿�;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_ACCESS_DENY��ʾδ��¼��
	  FD_ERROR��ʾ��������
ע�⣺������ͨ��ResChassisLogin�ӿڻ�ù���ԱȨ��
*********************************************/
COM_EXPORT ULONG ResTryReleasePorts(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ�����ָ�����Զ˿ڼ���DUT�˿ڵ�IPv4��ַ����Ҫ����һ���˿ڵĶ��IPv4��ַ��
      ���ú���ResEthernetPortSetup��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Addr�����Զ˿ڵ�IPv4��ַ;
	  ulDutIPv4Addr�� DUT��IPv4��ַ��	
	  ucPrefix�����볤�ȣ�ȡֵ��ΧΪ1--32
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PREFIX_LEN��ʾ���볤�ȴ���
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv4��ַ������ͬһ�����Ρ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortSetIPv4Address(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UCHAR ucPrefixLen);


/********************************************
���ܣ���IPv4��ַ�ӿ�Ƕ�뵽ָ�����Զ˿ڵ�IPv4Э��ջ����ַ�ӿڶ�����IPv4Э��ջ��ַ�ء�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Addr�����Զ˿ڵ�IPv4��ַ����usVlanId������ڶ˿���Ψһ;
	  ulDutIPv4Addr�� DUT��IPv4��ַ��	
	  ui64PortMacAddr�����Զ˿ڵ�MAC��ַ��
	  usVlanId�����Զ˿ڵ�VLAN ID����ulPortIPv4Addr������ڶ˿���Ψһ;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV4_ADDRESS��ʾ�˿��ڴ�����ͬ��IPv4��ַ��
	  FD_ERROR_DUT_IPV4_ADDRESS��ʾ�˿��ڴ�����ulDutIPv4Addr��ͬ��IPv4��ַ��
	  RES_ERROR_EXCEED_IPV4_INTERFACE_MAX_COUNT��ʾ�˿ڵ�IPv4��ַ�ӿ����ﵽ���ޣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv4��ַ������ͬһ�����Σ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortAddIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
���ܣ���IPv4��ַ�ӿ�Ƕ�뵽ָ�����Զ˿ڵ�IPv4Э��ջ����ַ�ӿڶ�����IPv4Э��ջ��ַ�أ���������ͬ�ӿ���༭�ýӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Addr�����Զ˿ڵ�IPv4��ַ����usVlanId������ڶ˿���Ψһ;
	  ulDutIPv4Addr�� DUT��IPv4��ַ��	
	  ui64PortMacAddr�����Զ˿ڵ�MAC��ַ��
	  usVlanId�����Զ˿ڵ�VLAN ID����ulPortIPv4Addr������ڶ˿���Ψһ;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV4_ADDRESS��ʾ�˿ڵ�ַ���ڴ�����ͬ��IPv4��ַ��
	  FD_ERROR_DUT_IPV4_ADDRESS��ʾ�˿��ڴ�����ulDutIPv4Addr��ͬ��IPv4��ַ��
	  RES_ERROR_EXCEED_IPV4_INTERFACE_MAX_COUNT��ʾ�˿ڵ�IPv4��ַ�ӿ����ﵽ���ޣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv4��ַ������ͬһ�����Σ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortSetIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, ULONG ulDutIPv4Addr, UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
���ܣ��Ƴ�ָ�����Զ˿ڵĵ���IPv4��ַ�ӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulPortIPv4Addr�����Զ˿ڵ�IPv4��ַ���˿���Ψһ;
	  usVlanId����IPv4��ַ�ӿڶ�Ӧ��VLAN ID
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortRemoveIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Addr, USHORT usVlanId);


/********************************************
���ܣ��Ƴ�ָ�����Զ˿ڵ�ȫ��IPv4��ַ�ӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortRemoveAllIPv4Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ���IPv6��ַ�ӿ�Ƕ�뵽ָ�����Զ˿ڵ�IPv6Э��ջ����ַ�ӿڶ�����IPv6Э��ջ��ַ�ء�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Addr�����Զ˿ڵ�IPv6��ַ����usVlanId������ڶ˿���Ψһ;
	  pucDutIPv6Addr�� DUT��IPv6��ַ��	
	  ui64PortMacAddr�����Զ˿ڵ�MAC��ַ��
	  usVlanId�����Զ˿ڵ�VLAN ID����pucPortIPv6Addr������ڶ˿���Ψһ;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV6_ADDRESS��ʾ�˿��ڴ�����ͬ��IPv6��ַ��
	  FD_ERROR_DUT_IPV6_ADDRESS��ʾ�˿��ڴ�����pucDutIPv6Addr��ͬ��IPv6��ַ��
	  RES_ERROR_EXCEED_IPV6_INTERFACE_MAX_COUNT��ʾ�˿ڵ�IPv6��ַ�ӿ����ﵽ���ޣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv6��ַ������ͬһ�����Σ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortAddIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucPortIPv6Addr[16], UCHAR pucDutIPv6Addr[16], UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
���ܣ���IPv6��ַ�ӿ�Ƕ�뵽ָ�����Զ˿ڵ�IPv6Э��ջ����ַ�ӿڶ�����IPv6Э��ջ��ַ�أ���������ͬ�ӿ���༭�ýӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Addr�����Զ˿ڵ�IPv6��ַ����usVlanId������ڶ˿���Ψһ;
	  pucDutIPv6Addr�� DUT��IPv6��ַ��	
	  ui64PortMacAddr�����Զ˿ڵ�MAC��ַ��
	  usVlanId�����Զ˿ڵ�VLAN ID����pucPortIPv6Addr������ڶ˿���Ψһ;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_IPV6_ADDRESS��ʾ�˿ڵ�ַ���ڴ�����ͬ��IPv6��ַ��
	  FD_ERROR_DUT_IPV6_ADDRESS��ʾ�˿��ڴ�����pucDutIPv6Addr��ͬ��IPv6��ַ��
	  RES_ERROR_EXCEED_IPV6_INTERFACE_MAX_COUNT��ʾ�˿ڵ�IPv6��ַ�ӿ����ﵽ���ޣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv6��ַ������ͬһ�����Σ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucPortIPv6Addr[16], UCHAR pucDutIPv6Addr[16], UINT64 ui64PortMacAddr, USHORT usVlanId);


/********************************************
���ܣ��Ƴ�ָ�����Զ˿�IPv6��ַ�ӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Addr�����Զ˿ڵ�IPv6��ַ���˿���Ψһ;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortRemoveIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucPortIPv6Addr, USHORT usVlanId);


/********************************************
���ܣ��Ƴ�ָ�����Զ˿ڵ�ȫ��IPv6��ַ�ӿڡ�
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortRemoveAllIPv6Interface(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ�����ָ�����Զ˿ڼ���DUT�˿ڵ�IPv6��ַ����Ҫ����һ���˿ڵĶ��IPv6��ַ��
      ���ú���ResEthernetPortSetup��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Addr�����Զ˿ڵ�16�ֽ�IPv6��ַָ�룬��������Ĭ��Ϊ64λ;
	  pucDutIP64Addr�� DUT��16�ֽ�IPv6��ַָ�룻	
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv6��ַ������ͬһ�����Ρ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6Address(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Addr, UCHAR *pucDutIPv6Addr);


/********************************************
���ܣ�����ָ�����Զ˿ڼ���DUT�˿ڵ�IPv6��ַ����Ҫ����һ���˿ڵĶ��IPv6��ַ��
      ���ú���ResEthernetPortSetup��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPortIPv6Addr�����Զ˿ڵ�16�ֽ�IPv6��ַָ�룬��������Ĭ��Ϊ64λ;
	  pucDutIP64Addr�� DUT��16�ֽ�IPv6��ַָ�룻	
	  ucPrefixLen�����볤�ȣ�ȡֵ��ΧΪ1--128
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_NOT_SAME_SUBNET��ʾ��̫�����Զ˿ں�DUT�˿ڵ�IPv6��ַ������ͬһ�����Ρ�
ע�⣺
*********************************************/
COM_EXPORT ULONG ResPortSetIPv6AddressEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Addr, UCHAR *pucDutIPv6Addr, UCHAR ucPrefixLen);


/********************************************
���ܣ���̫�����Զ˿ڲ������ã���������ṩһ�����ö˿���ϸ�����ķ�����
      ��ֻ���ò��Զ˿ں�DUT�˿ڵ�һ��IPv4��ַ��IPv6��ַ����ʹ�ú���
	  ResPortSetIPv4Address��ResPortSetIPv6Address��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pPortEth��Ҫ���õ���̫���˿ڲ����ṹָ��;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ���Զ˿ں�DUT�˿ڵ�IP��ַ������ͬһ�����Σ�
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾ��ַ���е����IPv4��ַ����255.255.255.255��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetup(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth);


COM_EXPORT ULONG ResPortDhcpSerEnable(ULONG ulChsId,ULONG ulSlotId,ULONG ulPortId,BOOL bEnable);


/********************************************
���ܣ�����ָ���˿ڵ�ý������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  bCopper��ý�����ͣ�TRUE��ʾ��ý�飬FALSE��ʾ��ý�飻
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_NOT_SUPPORT��ʾָ���˿ڲ�֧������ý�����ͣ�
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿�û��ԤԼ��
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG ResSetPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bCopper);


/********************************************
���ܣ�����ָ���˿ڵ�ý������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  bCopper��ý�����ͣ�TRUE��ʾ��ý�飬FALSE��ʾ��ý�飻
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_NOT_SUPPORT��ʾָ���˿ڲ�֧������ý�����ͣ�
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿�û��ԤԼ��
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG ResGetPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL* bCopper);



/********************************************
���ܣ�����ͬһ�Ű忨�ڵĶ���˿ڵ�ý������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  pulPortId���˿ں�ָ�룬1-based;
	  ulPortCount��pulPortIdָ��Ķ˿���Ŀ��
	  bCopper��ý�����ͣ�TRUE��ʾ��ý�飬FALSE��ʾ��ý�飻
	  pulRetCode���˿����ý������ֵָ��;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_NOT_SUPPORT��ʾָ���˿ڲ�֧������ý�����ͣ�
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿�û��ԤԼ��
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG ResSetMultiPortMediaType(ULONG ulChsId, ULONG ulSlotId, ULONG pulPortId[], ULONG ulPortCount, BOOL bCopper, ULONG pulRetCode[]);


/********************************************
���ܣ���̫�����Զ˿ڲ������ã���������ṩһ�����ö˿���ϸ�����ķ�����
      ��ֻ���ò��Զ˿ں�DUT�˿ڵ�һ��IPv4��ַ��IPv6��ַ����ʹ�ú���
	  ResPortSetIPv4Address��ResPortSetIPv6Address��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pPortEth��Ҫ���õ���̫���˿ڲ����ṹָ��;
	  bResetPhy����ʾ�Ƿ�Ҫ���ö˿ڵ�����״̬��������ΪRES_PORT_TYPE_GE_C�Ķ˿���Ч��
	  bSetPhy����ʾpPortEth��bAutoNego��bFullDuplex��ulFlowCtrlType��ucRate�����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSetIPv4Stack����ʾIPv4Э��ջ��ز����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSetIPv6Stack����ʾIPv6Э��ջ��ز����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSendArp����ʾ�Ƿ���ARP���󣬶˿���ԤԼʱ��Ч��
	  ulWaitTime����ʾ�ڷ���ARP����֮ǰ�ĵȴ��ĺ�������bSendArpΪTRUEʱ��Ч(��bResetPhy��bSetPhyΪTRUEʱ����ɶ˿�down������ʱ�޷���֤ARP�ĳɹ�����Ӧ�ʵ����ӵȴ�ʱ��)��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ���Զ˿ں�DUT�˿ڵ�IP��ַ������ͬһ�����Σ�
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾ��ַ���е����IPv4��ַ����255.255.255.255��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetupEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth
		, BOOL bResetPhy, BOOL bSetPhy, BOOL bSetIPv4Stack, BOOL bSetIPv6Stack, BOOL bSendArp, ULONG ulWaitTime);

/********************************************
���ܣ���̫�����Զ˿ڲ������ã���������ṩһ�����ö˿���ϸ�����ķ�����
      ��ֻ���ò��Զ˿ں�DUT�˿ڵ�һ��IPv4��ַ��IPv6��ַ����ʹ�ú���
	  ResPortSetIPv4Address��ResPortSetIPv6Address��
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pPortEth��Ҫ���õ���̫���˿ڲ����ṹָ��;
	  bResetPhy����ʾ�Ƿ�Ҫ���ö˿ڵ�����״̬��������ΪRES_PORT_TYPE_GE_C�Ķ˿���Ч��
	  bSetPhy����ʾpPortEth��bAutoNego��bFullDuplex��ulFlowCtrlType��ucRate�����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSetIPv4Stack����ʾIPv4Э��ջ��ز����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSetIPv6Stack����ʾIPv6Э��ջ��ز����Ƿ���Ч��ΪFALSE��������һ�ε����ã�
	  bSendArp����ʾ�Ƿ���ARP���󣬶˿���ԤԼʱ��Ч��
	  ulWaitTime����ʾ�ڷ���ARP����֮ǰ�ĵȴ��ĺ�������bSendArpΪTRUEʱ��Ч(��bResetPhy��bSetPhyΪTRUEʱ����ɶ˿�down������ʱ�޷���֤ARP�ĳɹ�����Ӧ�ʵ����ӵȴ�ʱ��)��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  RES_ERROR_NOT_SAME_SUBNET��ʾ���Զ˿ں�DUT�˿ڵ�IP��ַ������ͬһ�����Σ�
	  RES_ERROR_EXCEED_MAX_IPV4_ADDRESS��ʾ��ַ���е����IPv4��ַ����255.255.255.255��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResEthernetPortSetupSync(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth
		, BOOL bResetPhy, BOOL bSetPhy, BOOL bSetIPv4Stack, BOOL bSetIPv6Stack, BOOL bSendArp, ULONG ulWaitTime);


/********************************************
���ܣ��ȴ�ָ������Ķ˿����ò������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulWaitTime���ȴ���ʱʱ�䣻
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR_TIMEOUT��ʾ�ȴ���ʱ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResWaitForPhySetupFinish(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulWaitTime);


/********************************************
���ܣ���ȡ��̫�����Զ˿ڵ�ǰ��ϸ���ò�����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pPortEth��Ҫ���õ���̫���˿ڲ����ṹָ��;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortParameter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, PORT_ETH_S *pPortEth);


/********************************************
���ܣ�MDIO�Ĵ���������ȡ��
���룺ulChsId�� ����ID��1-based��
      	  ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulRegisterAddr���Ĵ�����ַ;
	  pulReadData����������;
	  ulWaitTime����ʱʱ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
            FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/

COM_EXPORT ULONG ResMdioReadEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulRegisterAddr, ULONG* pulReadData, ULONG ulWaitTime);


/********************************************
���ܣ�MDIO�Ĵ���������ȡ��
���룺ulChsId�� ����ID��1-based��
      	  ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulRegisterAddr���Ĵ�����ַ;
	  ulWriteData��д������;
	  ulWaitTime����ʱʱ��
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_RUNNING_TEST��ʾ�������в��ԣ�
            FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/

COM_EXPORT ULONG ResMdioWriteEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulRegisterAddr, ULONG ulWriteData, ULONG ulWaitTime);


/********************************************
���ܣ����÷��������������͵Ķ˿������������Чʱ�䡣
���룺ulExpireTime���˿������������Чʱ��;
�������
���أ���һ�Σ���Ĭ�ϵģ����õĹ���ʱ�䡣
ע�⣺
*********************************************/
COM_EXPORT ULONG ResSetPhyParamExpireTime(ULONG ulExpireTime);


/********************************************
���ܣ���ָ����̫���˿��Ϸ���ARP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulIpIndex��IP��ַ��ţ���ʾΪָ���˿�IPv4��ַ�صĵڼ���IP��������1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿ڻ�û��Ԥ����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResSendArpRequest(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulIpIndex);


/********************************************
���ܣ���ָ����̫���˿��Ϸ���NDP����
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulIpIndex��IP��ַ��ţ���ʾΪָ���˿�IPv4��ַ�صĵڼ���IP��������1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_TYPE��ʾ�˿����ʹ���
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿ڻ�û��Ԥ����
ע�⣺
*********************************************/
COM_EXPORT ULONG ResSendNdpNS(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulIpIndex);


/********************************************
���ܣ����ͱ��ġ��ú��������һ�������ı��ģ�Ȼ�󽻸�Ӳ������
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucPacket��Ҫ���͵ı�������;
	  ulPacketLen��Ҫ���͵ı��ĵĳ��ȣ�
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_CARD_NOT_RESERVED��ʾָ���ӿڿ�û��ԤԼ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResSendPacket(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR* pucPacket, ULONG ulPacketLen);


/********************************************
���ܣ���ʼָ���˿ڵ�PINGv4����
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulTargetIp����ҪPING��Ŀ��IPv4��ַ;
	  ucPingType��PING�����ͣ�RES_PING_INTERVAL��ʾ��ʱ������RES_PING_CONTINUOUS��ʾ������
	  ulDataSize��PING���ݵĴ�С��ȡֵ��ΧΪ1 - 65000��
	  bIncrement��PING���ݴ�С�Ƿ����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿�û��ԤԼ��
	  RES_ERROR_PING_TYPE��ʾ�����ucPingType����
	  RES_ERROR_PING_DATA_SIZE��ʾ�����ulDataSize����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResStartPing4(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulTargetIp, UCHAR ucPingType, ULONG ulDataSize, BOOL bIncrement);


/********************************************
���ܣ�ָֹͣ���˿ڵ�PINGv4����
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResStopPing4(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ���ȡָ���˿�PINGv4���ܵ�ͳ��״̬
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pulTargetIp����һ�ο���PINGv4����ʱ��Ŀ��IPv4��ַ��ΪNULL��ʾ������Ч
	  pulSuccessCount����һ�ο���PINGv4���ܵ��˴λ�ȡ״̬ʱPING�ĳɹ�������ΪNULL��ʾ������Ч
	  pulFailCount����һ�ο���PINGv4���ܵ��˴λ�ȡ״̬ʱPING��ʧ�ܴ�����ΪNULL��ʾ������Ч
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺��PING�Ĺ������Լ�ֹ֮ͣ�����ʹ�øú���
*********************************************/
COM_EXPORT ULONG ResGetPing4State(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulTargetIp, ULONG *pulSuccessCount, ULONG *pulFailCount);


/********************************************
���ܣ���ʼָ���˿ڵ�PINGv6����
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  pucTargetIp����ҪPING��Ŀ��IPv6��ַ;
	  ucPingType��PING�����ͣ�RES_PING_INTERVAL��ʾ��ʱ������RES_PING_CONTINUOUS��ʾ������
	  ulDataSize��PING���ݵĴ�С��ȡֵ��ΧΪ1 - 1452��
	  bIncrement��PING���ݴ�С�Ƿ����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR_PORT_NOT_RESERVED��ʾָ���˿�û��ԤԼ��
	  RES_ERROR_PING_TYPE��ʾ�����ucPingType����
	  RES_ERROR_PING_DATA_SIZE��ʾ�����ulDataSize����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResStartPing6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR *pucTargetIp, UCHAR ucPingType, ULONG ulDataSize, BOOL bIncrement);


/********************************************
���ܣ�ָֹͣ���˿ڵ�PINGv6����
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResStopPing6(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
���ܣ���ȡָ���˿�PINGv6���ܵ�ͳ��״̬
���룺ulChsId������ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
�����pucTargetIp����һ�ο���PINGv6����ʱ��Ŀ��IPv6��ַ��ΪNULL��ʾ������Ч
	  pulSuccessCount����һ�ο���PINGv6���ܵ��˴λ�ȡ״̬ʱPING�ĳɹ�������ΪNULL��ʾ������Ч
	  pulFailCount����һ�ο���PINGv6���ܵ��˴λ�ȡ״̬ʱPING��ʧ�ܴ�����ΪNULL��ʾ������Ч
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  FD_ERROR��ʾ��������
ע�⣺��PING�Ĺ������Լ�ֹ֮ͣ�����ʹ�øú���
*********************************************/
COM_EXPORT ULONG ResGetPing6State(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR pucTargetIp[16], ULONG *pulSuccessCount, ULONG *pulFailCount);


/********************************************
���ܣ���ȡָ���˿ڵ�����������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ucParamType�������������ͣ�0��ʾ��Э�̲�����1��ʾ˫��������2��ʾ���ز�����3��ʾ���ʲ�����4��ʾ����ģʽ��5��ʾ�˿�״̬;
�����pulParamValue��ָ���������ֵָ�롣��Э��ΪTRUE������Э��ΪFALSE��ȫ˫��ΪTRUE����˫��ΪFALSE��
                     ����ΪTRUE��������ΪFALSE��RES_PORT_RATE_10��ʾ10M��RES_PORT_RATE_100��ʾ100M��
					 RES_PORT_RATE_1000��ʾ1000M��RES_PORT_OPMODE_NORMAL��ʾ��������ģʽ��
					 RES_PORT_OPMODE_INTERNAL_LOOPBACK��ʾ�Ի���RES_LINK_STATE_DOWN��ʾ�˿�״̬Ϊdown��
					 RES_LINK_STATE_UP��ʾ�˿�״̬Ϊup��RES_LINK_STATE_NA��ʾ�˿�״̬δ֪
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾ��������ʵ��λû�нӿڿ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucParamType, ULONG *pulParamValue);

// ����ʱʱ��
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameterEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucParamType, ULONG *pulParamValue, ULONG ulWaitTime );


/********************************************
���ܣ���ȡָ���˿ڵĶ������������
���룺ulChsId�� ����ID��1-based��
      ulSlotId����λ�ţ�1-based;
	  ulPortId���˿ںţ�1-based;
	  ulParamNum����Ҫ��ȡ��������������
	  pucParamType�������������ͣ�0��ʾ��Э�̲�����1��ʾ˫��������2��ʾ���ز�����3��ʾ���ʲ�����4��ʾ����ģʽ��5��ʾ�˿�״̬;
�����pulParamValue��ָ���������ֵָ�롣��Э��ΪTRUE������Э��ΪFALSE��ȫ˫��ΪTRUE����˫��ΪFALSE��
                     ����ΪTRUE��������ΪFALSE��RES_PORT_RATE_10��ʾ10M��RES_PORT_RATE_100��ʾ100M��
					 RES_PORT_RATE_1000��ʾ1000M��RES_PORT_OPMODE_NORMAL��ʾ��������ģʽ��
					 RES_PORT_OPMODE_INTERNAL_LOOPBACK��ʾ�Ի���RES_LINK_STATE_DOWN��ʾ�˿�״̬Ϊdown��
					 RES_LINK_STATE_UP��ʾ�˿�״̬Ϊup��RES_LINK_STATE_NA��ʾ�˿�״̬δ֪
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR_SLOT_ID��ʾ�����ulSlotId����
	  FD_ERROR_PORT_ID��ʾ�����ulPortId����
	  RES_ERROR_PORT_MODE��ʾָ���˿ڲ�����̫���˿ڣ�
	  RES_ERROR_HAS_NO_CARD_IN_REAL_SLOT��ʾ��������ʵ��λû�нӿڿ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetEthernetPortPhysicalParameters(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulParamNum, UCHAR *pucParamType, ULONG *pulParamValue);

// ����ʱʱ��
COM_EXPORT ULONG ResGetEthernetPortPhysicalParametersEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulParamNum, UCHAR *pucParamType, ULONG *pulParamValue, ULONG ulWaitTime );


/********************************************
���ܣ�����Э����棬Ŀǰ֧�ֵ�Э���У�IGMP��RIPv2&RIPng��OSPFv2��BGP
���룺��
�������
���أ���
ע�⣺ÿ��Э����ע������Ӧ��Э��Licesne�����Ч
*********************************************/
COM_EXPORT void StartProtocolEmulation();


/********************************************
���ܣ�ֹͣЭ����棬Ŀǰ֧�ֵ�Э���У�IGMP��RIPv2&RIPng��OSPFv2��BGP
���룺��
�������
���أ���
ע�⣺ÿ��Э����ע������Ӧ��Э��Licesne�����Ч
*********************************************/
COM_EXPORT void StopProtocolEmulation();


/********************************************
���ܣ�����Teleϵ�����GUIӦ�ó����ָ���������ɱ���������������ͳ�ƽ���ʵʱ���
���룺ulChsId�� ����ID��1-based������ulChsId == INVALID_CHASSIS_ID��ʱ������������ӵĻ�����Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG EnableGUIMonitor(ULONG ulChsId);


/********************************************
���ܣ���ֹTeleϵ�����GUIӦ�ó����ָ���������ɱ���������������ͳ�ƽ���ʵʱ���
���룺ulChsId�� ����ID��1-based������ulChsId == INVALID_CHASSIS_ID��ʱ������������ӵĻ�����Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG DisableGUIMonitor(ULONG ulChsId);


/********************************************
���ܣ���������ͬ�û��ظ�ԤԼͬһ�˿ڣ�֮ǰԤԼ���û������ͷ�
���룺ulChsId�� ����ID��1-based������ulChsId == INVALID_CHASSIS_ID��ʱ������������ӵĻ�����Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG EnablePortReuse(ULONG ulChsId);


/********************************************
���ܣ���ֹ������ͬ�û��ظ�ԤԼͬһ�˿�
���룺ulChsId�� ����ID��1-based������ulChsId == INVALID_CHASSIS_ID��ʱ������������ӵĻ�����Ч
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
	  FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  FD_ERROR��ʾ��������
ע�⣺��
*********************************************/
COM_EXPORT ULONG DisablePortReuse(ULONG ulChsId);


/********************************************
���ܣ���ȡָ�������Ϸ�������Ա����û���Ψһ��ʶID
���룺ulChsId�� ����ID��1-based��
�����pulUserId���û�IDָ��
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG ResGetServerUserId(ULONG ulChsId, ULONG *pulUserId);


/********************************************
���ܣ��ϴ�����ļ�
���룺ulChsId������ID��1-based��
      strLicenseFilePath������ļ��ı��ش��ȫ·��;
	  bOverwriteIfExists��ָʾ��������License�ļ�ʱ�Ƿ񸲸ǣ����ΪTRUE����ֱ�Ӹ�������ʾ�����ΪFALSE����������ʱ������ERROR;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR_FILE_NOT_EXIST��ʾ����ļ������ڣ�
	  FD_ERROR_FILE_CONTENT��ʾ�����License�ļ���ʽ����ȷ��
	  FD_ERROR_FILE_BAD_HASH��ʾ�����License�ļ�HASHУ�鲻ͨ����
	  FD_ERROR_LICENSE_EXPIRES��ʾLicense�ļ��ѹ��ڣ�
	  FD_ERROR_DUPLICATE_LICENSE��ʾLicense�ļ����ظ�����������OverwriteIfExisits�ſ��ܷ��ظô���ֵ��
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG UploadLicense(ULONG ulChsId, const char *strLicenseFilePath, BOOL bOverwriteIfExists);


/********************************************
���ܣ�ɾ������ļ�
���룺ulChsId������ID��1-based��
      strLicenseFileName��ָ����License�ļ����ļ���������ָ��ɾ�������϶��License�ļ��е�һ��������ò���Ϊ�գ�NULL��,��ɾ�����е�License�ļ�;
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR_FILE_NOT_EXIST��ʾ����ļ������ڣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG DeleteLicense(ULONG ulChsId, const char *strLicenseFileName);


/********************************************
���ܣ���ȡ����ļ����б�
���룺ulChsId������ID��1-based��
�����pstrLicenseFileList������ļ����б��ָ��
      pulCount������ļ����б���ļ�����Ŀ
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG GetLicenseList(ULONG ulChsId, char ***pstrLicenseFileList, ULONG *pulCount);


/********************************************
���ܣ��ͷŻ�ȡ��������ļ����б���ڴ�ռ�
���룺strLicenseFileList������ļ����б��ָ�룻
      ulCount������ļ����б���ļ�����Ŀ��
�������
���أ���
ע�⣺
*********************************************/
COM_EXPORT void FreeLicenseList(char **strLicenseFileList, ULONG ulCount);


/********************************************
���ܣ���������ļ�
���룺ulChsId������ID��1-based��
      strLicenseFileName��ָ����License�ļ����ļ�����
      strLicenseFilePath������ļ��ı��ش��ȫ·����
�������
���أ��ɹ��򷵻�FD_OK��ʧ���򷵻�����ֵ��
      FD_ERROR_CHASSIS_ID��ʾ�����ulChsId����
	  RES_ERROR_IS_DISCONNECTED_CHASSIS��ʾ����δ���ӣ�
	  FD_ERROR_FILE_NOT_EXIST��ʾ����ļ������ڣ�
	  FD_ERROR��ʾ��������
ע�⣺
*********************************************/
COM_EXPORT ULONG DownloadLicense(ULONG ulChsId, const char *strLicenseFileName, const char *strLicenseFilePath);
#endif


#ifdef __FOR_CSHARP
}
#endif
