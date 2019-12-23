#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define IGMP_ERROR_EXCEED_MAX_SESSION_COUNT			(500)
#define IGMP_ERROR_EXCEED_MAX_GROUP_COUNT			(501)
#define IGMP_ERROR_SESSION_ID						(502)
#define IGMP_ERROR_GROUP_POOL_ID					(503)
#define IMGP_ERROR_GROUP_STA_ITEM_ID                                                              (504)
#define IMGP_ERROR_ITEM_ID                           (505)


typedef struct tag_GROUP_POOL
{
	ULONG  ulGroupAddr;//组地址
	ULONG  ulGroupAddrCount;//组地址数目
	UCHAR  ucGroupAddrModBit;//组地址要跳变的bit位，取值范围为1--32
	UCHAR  ucGroupAddrModStep;//组地址跳变的步长，取值范围为1--255

	BOOL   bVlan;//该组地址池是否带VLAN
	USHORT usVlanId;//VLAN ID
	UCHAR  ucVlanPri;//VLAN PRI
	UCHAR  ucVlanCfi;//VLAN CFI
} GROUP_POOL_S;

enum 
{
	IGMP_GROUP_POOL_JION_TIME=0,
	IGMP_GROUP_POOL_LEAVE_TIME,
};


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
功能：添加IGMPv2 Session
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Address：测试端口的IPv4接口地址；
输出：pulSessionId：Session ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV4_ADDRESS表示输入的ulPortIPv4Address不是指定端口的接口IPv4地址，
	  IGMP_ERROR_EXCEED_MAX_SESSION_COUNT表示session数目已经超出指定端口所允许的最大值。
注意：
*********************************************/
COM_EXPORT ULONG IgmpAddV2Session(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulPortIPv4Address, ULONG *pulSessionId);


/********************************************
功能：删除指定的IGMP Session
输入：ulSessionId： IGMP Session ID，由函数IgmpAddV2Session输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  IGMP_ERROR_SESSION_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG IgmpRemoveSession(ULONG ulSessionId);


/********************************************
功能：在指定的IGMP Session上添加组地址池
输入：ulSessionId： IGMP Session ID，由函数IgmpAddV2Session输出；
      pGroupPool：组地址池指针；
输出：pulGroupPoolId：组地址池ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  IGMP_ERROR_SESSION_ID表示输入的ulSessionId错误，
	  IGMP_ERROR_EXCEED_MAX_GROUP_COUNT表示组地址数已经超出指定端口所允许的最大值，
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS表示结束路由超过了255.255.255.255。
注意：
*********************************************/
COM_EXPORT ULONG IgmpAddGroupPool(ULONG ulSessionId, GROUP_POOL_S *pGroupPool, ULONG *pulGroupPoolId);


/********************************************
功能：删除指定的组地址池
输入：ulGroupPoolId： 组地址池ID，由函数IgmpAddGroupPool输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  IGMP_ERROR_GROUP_POOL_ID表示输入的ulGroupPoolId错误。
注意：
*********************************************/
COM_EXPORT ULONG IgmpRemoveGroupPool(ULONG ulGroupPoolId);


/********************************************
功能：使能或不使能指定的组地址池
输入：ulGroupPoolId： 组地址池ID，由函数IgmpAddGroupPool输出；
      bEnable：是否使能指定的组地址池；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  IGMP_ERROR_GROUP_POOL_ID表示输入的ulGroupPoolId错误。
注意：不调用该函数，默认为使能组地址池。
*********************************************/
COM_EXPORT ULONG IgmpEnableGroupPool(ULONG ulGroupPoolId, BOOL bEnable);


/********************************************
功能：设置指定端口发送IGMP Membership Report报文的速率
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPPS：   发送IGMP Membership Report报文的速率，单位为Packets/Sec，取值范围为1--10000；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG IgmpSetMessageTransmitRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPPS);

/********************************************
功能：获取指定组地址池加入/离开的时间
输入：ulGroupPoolId： 组地址池ID，由函数IgmpAddGroupPool输出；
ucStaItem: 0 加入时间 1离开时间
			
输出：组播组加入/离开的时间(单位8ns)
返回：成功则返回FD_OK；失败则返回如下值：
注意：
*********************************************/

COM_EXPORT ULONG IgmpGetGroupPoolTime(ULONG ulGroupPoolId,UCHAR ucStaItem, ULONG *pulValue);
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

