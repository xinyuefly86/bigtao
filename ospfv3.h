#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif
	
#define OSPFV3_ERROR_SESSION_ID                          (600)
#define OSPFV3_ERROR_ROUTE_POOL_ID                       (601)
#define OSPFV3_ERROR_MAXADDRESS                          (602)
#define OSPFV3_ERROR_MAX_LSA_COUNT                       (603)
#define OSPFV3_ERROR_NOTFALPPING                         (604)
#define OSPFV3_ERROR_ISFLAPPING                          (605)
#define OSPFV3_ERROR_START_EMULATION                     (606)
#define OSPFV3_ERROR_STOP_EMULATION                      (608)
#define OSPFV3_ERROR_ROUTE_POOL_TYPE                     (607)
#define OSPFV3_ERROR_EXCEED_MAX_SESSION_COUNT            (609)
#define OSPFV3_IPv6ADDRESS_EXCEED_ROUTE_POOL             (610)
#define OSPFV3_ERROR_ROUTERLSA_OPTION                    (253)
#define OSPFV3_ERROR_EXTERNAL_ROUTEPOOL_OPTION           (254)
#define OSPFV3_ERROR_NSSA_ROUTEPOOL_OPTION               (254)
#define OSPFV3_ERROR_OPTION                              (520)
#define OSPFV3_ERROR_PREFIX_OPTIION                      (255)    


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW

COM_EXPORT ULONG Ospfv3AddSession(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR* ucPortIPv6Address, UCHAR* ucDUTIPv6Address, UCHAR InstanceID, ULONG AreaId, ULONG RouterId, 
								  ULONG InterfaceCost, UCHAR OptionBit, UCHAR RouterBit, ULONG HelloInterval, ULONG DeadInterval,
								  ULONG LSARefreshTime, ULONG RetransimitTime, ULONG ulCount, ULONG* SessionId);

COM_EXPORT ULONG Ospfv3AddRouterLSAPool(ULONG SessionId, ULONG RouteCount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, UCHAR Options, ULONG* RouterPoolID);

COM_EXPORT ULONG Ospfv3AddRouterLSALink(ULONG RouterID, UCHAR LinkType, ULONG InterfaceID, ULONG Metric, ULONG NeighborInterfaceID, ULONG NeighborRouterID);

COM_EXPORT ULONG Ospfv3AddNetworkLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequencNum);

COM_EXPORT ULONG Ospfv3AddNetworkLSAAttachedRouter(ULONG RoutePoolID, ULONG AttachedRouterID);

COM_EXPORT ULONG Ospfv3AddInterAreaPrefixLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequencNum, UCHAR PrefixOptions,
												 UCHAR* AddrPrefix, ULONG PrefixLength, ULONG AddrPrefixCount, ULONG ModifierStep, ULONG ModifierBit, ULONG Metric);

COM_EXPORT ULONG Ospfv3AddInterAreaRouterLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, ULONG Metric, ULONG DestinationRouterID);

COM_EXPORT ULONG Ospfv3AddASExternalLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, UCHAR RoutePoolOptions, UCHAR PrefixOptions,
											ULONG ReferenceLSType, UCHAR* AddrPrefix, ULONG PrefixLength, ULONG AddrPrefixCount, ULONG ModifierStep, ULONG ModifierBit,
											ULONG Metric, UCHAR* ForwardAddr, ULONG ExternalRouterTag, ULONG ReferenceLinkStateID);

COM_EXPORT ULONG Ospfv3AddNSSALSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, UCHAR RoutePoolOptions, UCHAR PrefixOptions,
									  ULONG ReferenceLSType, UCHAR* AddrPrefix, ULONG PrefixLength, ULONG AddrPrefixCount, ULONG ModifierStep, ULONG ModifierBit,
									  ULONG Metric, UCHAR* ForwardAddr, ULONG ExternalRouterTag, ULONG ReferenceLinkStateID);

COM_EXPORT ULONG Ospfv3AddLinkLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, UCHAR* LinkLocalInterfaceAddr, UCHAR Options, 
                                      UCHAR* AddrPrefix, ULONG PrefixLength, ULONG PrefixCount, ULONG PrefixStep, ULONG PrefixBit);

COM_EXPORT ULONG Ospfv3AddIntraAreaPrefixLSAPool(ULONG SessionID, ULONG LSACount, ULONG Age, ULONG LinkStateID, ULONG AdvRouter, ULONG SequenceNum, USHORT ReferenceLSType, ULONG ReferenceLinkStateID, ULONG ReferenceAdvRouter,
                                                 UCHAR Options, UCHAR* AddrPrefix, ULONG PrefixLength, ULONG PrefixCount, ULONG PrefixStep, ULONG PrefixBit, ULONG Metric);


COM_EXPORT ULONG Ospfv3Advertise(ULONG RouterPoolID);
 
COM_EXPORT ULONG Ospfv3Withdraw(ULONG RouterPoolID);
 
COM_EXPORT ULONG Ospfv3FlapSet(ULONG RouterPoolID, ULONG AdvToWit, ULONG WitToAdv);
 
COM_EXPORT ULONG Ospfv3StartFlaping(ULONG RouterPoolID);
 
COM_EXPORT ULONG Ospfv3StopFlaping(ULONG RouterPoolID);
#endif
#endif


#ifdef __FOR_CSHARP
}
#endif