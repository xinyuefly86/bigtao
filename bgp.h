#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


enum {
	BGP_STATE_IDLE = 0, 
	BGP_STATE_CONNECT, 
	BGP_STATE_OPENSENT, 
	BGP_STATE_OPENRECV, 
	BGP_STATE_OPENCONFIRM, 
	BGP_STATE_ESTAB, 
	BGP_STATE_DISABLE 
};


#ifdef __FOR_CSHARP
}
#endif

