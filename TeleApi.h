#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __COMMON
#define COM_EXPORT __declspec(dllexport)
#else
#define COM_EXPORT __declspec(dllimport)
#endif

#include "res.h"
#include "tra.h"
#include "sta.h"
#include "cap.h"
#include "igmp.h"
#include "pim.h"
#include "rip.h"
#include "bgp.h"
#include "ospf.h"
#include "ospfv3.h"
#include "pppoe.h"
#include "dhcp.h"
#include "tcp.h"
#include "telnet.h"
#include "http.h"

