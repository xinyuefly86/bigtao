#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define RIP_ERROR_EXCEED_MAX_SESSION_COUNT		(600)
#define RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT	(601)
#define RIP_ERROR_SESSION_ID					(602)
#define RIP_ERROR_ROUTE_POOL_ID					(603)
#define RIP_ERROR_ROUTE_POOL_FLAPPING			(604)
#define RIP_ERROR_ROUTE_POOL_UNENABLED			(605)


typedef struct tag_IPV4_ROUTE_POOL
{
	ULONG  ulRoute;//IPv4起始路由
	ULONG  ulRouteCount;//IPv4路由数目
	UCHAR  ucRouteModBit;//IPv4路由要跳变的bit位，取值范围为1--32
	UCHAR  ucRouteModStep;//IPv4路由跳变的步长，取值范围为1--255

	UCHAR  ucPrefixLen;//prefix length，取值范围为0--32
	USHORT usRouteTag;//route tag
	ULONG  ulMetric;//metric
	ULONG  ulNextHop;//next hop
} IPV4_ROUTE_POOL_S;


typedef struct tag_IPV6_ROUTE_POOL
{
	UCHAR  ucaRoute[16];//IPv6起始路由
	ULONG  ulRouteCount;//IPv6路由数目
	UCHAR  ucRouteModBit;//IPv6路由要跳变的bit位，取值范围为1--128
	UCHAR  ucRouteModStep;//IPv6路由跳变的步长，取值范围为1--255

	UCHAR  ucPrefixLen;//prefix length，取值范围为0--128
	USHORT usRouteTag;//route tag
	UCHAR  ucMetric;//metric
	UCHAR  ucaNextHop[16];//next hop
} IPV6_ROUTE_POOL_S;


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
功能：添加RIPv2 Session
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPortIPv4Address：测试端口的IPv4接口地址；
	  usUpdateInterval：路由更新间隔，以秒为单位，取值范围为1--65535；
	  ucRoutePerPDU：每个Update PDU中包含路由的数目，取值范围为1--25；
输出：pulSessionId：Session ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV4_ADDRESS表示输入的ulPortIPv4Address不是指定端口的接口IPv4地址，
	  RIP_ERROR_EXCEED_MAX_SESSION_COUNT表示session数目已经超出允许的最大值。
注意：
*********************************************/
COM_EXPORT ULONG RipAddV2Session(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulPortIPv4Address, USHORT usUpdateInterval, UCHAR ucRoutePerPDU, 
	ULONG *pulSessionId);


/********************************************
功能：添加RIPng Session
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucPortIPv6Address：测试端口的IPv6接口Link Local地址指针；
	  usUpdateInterval：路由更新间隔，以秒为单位，取值范围为1--65535；
	  ucRoutePerPDU：每个Update PDU中包含路由的数目，取值范围为1--4000，若超出MTU所能包含的路由数则取该路由数；
输出：pulSessionId：Session ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_IPV6_LINK_LOCAL_ADDRESS表示输入的pucPortIPv6Address不是指定端口的接口IPv6 Link Local地址，
	  RIP_ERROR_EXCEED_MAX_SESSION_COUNT表示session数目已经超出允许的最大值。
注意：
*********************************************/
COM_EXPORT ULONG RipAddNgSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucPortIPv6Address, USHORT usUpdateInterval, USHORT usRoutePerPDU, 
	ULONG *pulSessionId);


/********************************************
功能：删除指定的RIP Session
输入：ulSessionId：RIP Session ID，由函数RipAddV2Session或RipAddNgSession输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  RIP_ERROR_SESSION_ID表示输入的ulSessionId错误。
注意：
*********************************************/
COM_EXPORT ULONG RipRemoveSession(ULONG ulSessionId);


/********************************************
功能：在指定的RIPv2 Session上添加IPv4路由池
输入：ulSessionId： RIPv2 Session ID，由函数RipAddV2Session输出；
      pRoutePool：IPv4路由池指针；
输出：pulRoutePoolId：IPv4路由池ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  RIP_ERROR_SESSION_ID表示输入的ulSessionId错误，
	  RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT表示路由池数已经超出指定端口所允许的最大值，
	  FD_ERROR_EXCEED_MAX_IPV4_ADDRESS表示结束路由超过了255.255.255.255。
注意：
*********************************************/
COM_EXPORT ULONG RipAddIpv4RoutePool(ULONG ulSessionId, IPV4_ROUTE_POOL_S *pRoutePool, ULONG *pulRoutePoolId);


/********************************************
功能：在指定的RIPng Session上添加IPv6路由池
输入：ulSessionId： RIPng Session ID，由函数RipAddNgSession输出；
      pRoutePool：IPv6路由池指针；
输出：pulRoutePoolId：IPv6路由池ID指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  RIP_ERROR_SESSION_ID表示输入的ulSessionId错误，
	  RIP_ERROR_EXCEED_MAX_ROUTE_POOL_COUNT表示路由池数已经超出指定端口所允许的最大值，
	  FD_ERROR_EXCEED_MAX_IPV6_ADDRESS表示结束IPv6路由超过了允许的最大值。
注意：
*********************************************/
COM_EXPORT ULONG RipAddIpv6RoutePool(ULONG ulSessionId, IPV6_ROUTE_POOL_S *pRoutePool, ULONG *pulRoutePoolId);


/********************************************
功能：删除指定的路由池
输入：ulRoutePoolId： 路由池ID，由函数RipAddIpv4RoutePool或RipAddIpv6RoutePool 输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  RIP_ERROR_ROUTE_POOL_ID表示输入的ulRoutePoolId错误。
注意：
*********************************************/
COM_EXPORT ULONG RipRemoveRoutePool(ULONG ulRoutePoolId);


/********************************************
功能：使能或不使能指定的路由池
输入：ulRoutePoolId： 路由池ID，由函数RipAddIpv4RoutePool或RipAddIpv6RoutePool 输出；
      bEnable：是否使能指定的路由池；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  RIP_ERROR_ROUTE_POOL_ID表示输入的ulRoutePoolId错误，
	  RIP_ERROR_ROUTE_POOL_FLAPPING表示指定路由池正在进行路由振荡。
注意：不调用该函数，默认为使能路由池。
*********************************************/
COM_EXPORT ULONG RipEnableRoutePool(ULONG ulRoutePoolId, BOOL bEnable);


/********************************************
功能：设置指定端口发送RIP response PDU的速率
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulPPS：   发送RIP response PDU的速率，单位为Packets/Sec，取值范围为1--1000；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG RipSetPduTransmitRate(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPPS);


/********************************************
功能：设置指定的路由池的振荡参数
输入：ulRoutePoolId： 路由池ID，由函数RipAddIpv4RoutePool或RipAddIpv6RoutePool 输出；
      usA2WDelay：从路由通告完毕到开始路由撤销的时间间隔，以秒为单位，取值范围为1--65535；
      usW2ADelay：从路由撤销完毕到开始路由通告的时间间隔，以秒为单位，取值范围为1--65535；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_START_PROTOCOL_EMULATION表示正在进行协议仿真，
	  RIP_ERROR_ROUTE_POOL_ID表示输入的ulRoutePoolId错误。
注意：
*********************************************/
COM_EXPORT ULONG RipSetFlapParameter(ULONG ulRoutePoolId, USHORT usA2WDelay, USHORT usW2ADelay);


/********************************************
功能：启动指定的路由池的振荡
输入：ulRoutePoolId： 路由池ID，由函数RipAddIpv4RoutePool或RipAddIpv6RoutePool 输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示还没有进行协议仿真，
	  RIP_ERROR_ROUTE_POOL_ID表示输入的ulRoutePoolId错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定路由池所属接口卡还没有预定，
	  RIP_ERROR_ROUTE_POOL_UNENABLED表示指定路由池没有使能。
注意：
*********************************************/
COM_EXPORT ULONG RipStartFlap(ULONG ulRoutePoolId);


/********************************************
功能：停止指定的路由池的振荡
输入：ulRoutePoolId： 路由池ID，由函数RipAddIpv4RoutePool或RipAddIpv6RoutePool 输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  FD_ERROR_STOP_PROTOCOL_EMULATION表示还没有进行协议仿真，
	  RIP_ERROR_ROUTE_POOL_ID表示输入的ulRoutePoolId错误，
	  FD_ERROR_CARD_NOT_RESERVED表示指定路由池所属接口卡还没有预定，
	  RIP_ERROR_ROUTE_POOL_UNENABLED表示指定路由池没有使能。
注意：
*********************************************/
COM_EXPORT ULONG RipStopFlap(ULONG ulRoutePoolId);
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

