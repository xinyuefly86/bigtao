#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif

#define OSPF_ERROR_SESSION_ID                 (600)
#define OSPF_ERROR_ROUTE_POOL_ID              (601)
#define OSPF_ERROR_MAXADDRESS                 (602)
#define OSPF_ERROR_MAXLSACOUNT                (603)
#define OSPF_ERROR_NOTFALPPING                (604)
#define OSPF_ERROR_ISFLAPPING                 (605)
#define OSPF_ERROR_STOP_PROTOCOL_EMULATION    (606)
#define OSPF_ERROR_ROUTE_POOL_TYPE            (607)
#define OSPF_ERROR_EXCEED_MAX_SESSION_COUNT   (608)
#define OSPF_ERROR_OPTION                     (520)
#define OSPF_ERROR_ROUTER_TYPE                (255)

enum {
	OSPF_STATE_DISABLE = 0, 
	OSPF_STATE_DOWN, 
	OSPF_STATE_INIT, 
	OSPF_STATE_2WAY, 
	OSPF_STATE_EXSTART, 
	OSPF_STATE_EXCHANGE, 
	OSPF_STATE_LOADING, 
	OSPF_STATE_FULL
};


enum {
	OSPF_LS_ROUTER = 1, 
	OSPF_LS_NETWORK, 
	OSPF_LS_NETWORK_SUMMARY, 
	OSPF_LS_ASBR_SUMMARY, 
	OSPF_LS_AS_EXTERNAL, 
	OSPF_LS_NSSA = 7, 
	OSPF_LS_TE = 10 
};


enum {
	OSPF_LINK_PTP = 1, 
	OSPF_LINK_TRANSIT_NETWORK, 
	OSPF_LINK_STUB_NETWORK, 
	OSPF_LINK_VIRTUAL_LINK 
};


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
COM_EXPORT ULONG OspfAddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulPortIPv4Address, ULONG ulDUTIPv4Address, ULONG AreaId, ULONG RouterId, 
								ULONG InterfaceCost, UCHAR OptionBit, UCHAR RouterType, ULONG HelloInterval, ULONG DeadInterval,
								ULONG LSARefreshTime, ULONG RetransimitTime, ULONG ulCount, ULONG* SessionId);

COM_EXPORT ULONG OspfAddRouterLSAPool(ULONG ulSessionId, ULONG ulRouteCount, UCHAR ucOptionBit, ULONG ulAge, ULONG ulSeqNum, ULONG ulAdvRouterId, UCHAR ucRouterType, ULONG* RouterPoolID);

COM_EXPORT ULONG OspfAddRouterLSALink(ULONG ulSessionId, UCHAR LinkType, ULONG LinkID, ULONG LinkData, ULONG Metric);

COM_EXPORT ULONG OspfAddNetworkLSAPool(ULONG SessionID, ULONG LSACount, UCHAR OptionBit, ULONG Age, ULONG SequenceNumber, ULONG LinkStateID, ULONG AdvRouterID, ULONG PrefixLength, ULONG* RouterPoolID);

COM_EXPORT ULONG OspfAddNetworkLSAAttachedRouter(ULONG RoutePoolID, ULONG AttachedRouterID);

COM_EXPORT ULONG OspfAddSummaryLSAPool(ULONG SessionID, ULONG PoolCount, ULONG LSAType, UCHAR Options, ULONG Age, ULONG SequenceNumber, ULONG AdvRouterID, ULONG FirstAddr, ULONG PrefixLength,
									   ULONG LSACount, ULONG ModifierStep, ULONG ModifierBit, ULONG Metric);

COM_EXPORT ULONG OspfAddExternalLSAPool(ULONG SessionID, ULONG PoolCount, ULONG LSAType, UCHAR Options, ULONG Age, ULONG SequenceNumber, ULONG AdvRouterID, ULONG FirstAddr, ULONG PrefixLength, ULONG LSACount,
										ULONG ModifierStep, ULONG ModifierBit, ULONG Metric, UCHAR MetricType, ULONG ForwardAddr, ULONG ExternalRouterTag);

COM_EXPORT ULONG OspfAddTELSAPool(ULONG SessionID, ULONG LSACount, UCHAR Options, ULONG Age, ULONG SequenceNumber, ULONG AdvRouterID);

COM_EXPORT ULONG OspfAddTELSARouterAddrTLV(ULONG RouterPoolID, ULONG RouterAddr);

COM_EXPORT ULONG OspfAddTELSALinkTLV(ULONG RouterPoolID, ULONG SubTLVType, ULONG SubTLVLength, CString SubTLVValue);

COM_EXPORT ULONG OspfAdvertise(ULONG RouterPoolID);

COM_EXPORT ULONG OspfWithdraw(ULONG RouterPoolID);

COM_EXPORT ULONG OspfFlapSet(ULONG RouterPoolID, ULONG AdvToWit, ULONG WitToAdv);

COM_EXPORT ULONG OspfStartFlaping(ULONG RouterPoolID);

COM_EXPORT ULONG OspfStopFlaping(ULONG RouterPoolID);

COM_EXPORT ULONG OspfCheckNeiborghState();
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

