#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef __FOR_CSHARP
extern "C" {
#endif

#define  TPHTTP_ERROR    (1100) //session交互失败
#define  TPHTTP_TCP_ERROR_CONNECT_FAIL (1101) //TCP 连接失败
#define  TPHTTP_TCP_ERROR_NOT_LOG_ON (1102) //未登陆 TP-LINK

//WLAN_TYPE
enum WLAN_TYPE{
	WLAN_24G,
	WLAN_50G,
};

//ENCRYPT TYPE
enum ENCRYPT_TYPE{
	ENCRYPT_NO_KEY = 1,
	ENCRYPT_ASCII_WEP,
	ENCRYPT_HEX_WEP,
	ENCRYPT_WPA_PSK,
};
//WEP KEY SEQ
enum WEP_KEY_SEQ{
	WEP_KEY_SEQ1 = 1,
	WEP_KEY_SEQ2,
	WEP_KEY_SEQ3,
	WEP_KEY_SEQ4,
};
//AUTH_TYPE
enum AUTH_TYPE{
	AUTH_TYPE_OPEN_SYSTEM = 1,
	AUTH_TYPE_SHARE_KEY,
};

enum CHANNEL_24G{
	CHANNEL_24G_auto = 1,//default
	CHANNEL_24G_1,
	CHANNEL_24G_2,
	CHANNEL_24G_3,
	CHANNEL_24G_4,
	CHANNEL_24G_5,
	CHANNEL_24G_6,
	CHANNEL_24G_7,
	CHANNEL_24G_8,
	CHANNEL_24G_9,
	CHANNEL_24G_10,
	CHANNEL_24G_12,
	CHANNEL_24G_13,
};

enum CHANNEL_50G{
	CHANNEL_50G_auto = 1,//default
	CHANNEL_50G_149,
	CHANNEL_50G_153,
	CHANNEL_50G_157,
	CHANNEL_50G_161,
};

enum MODEL_24G
{
	MODEL_24G_B_ONLY = 1,
	MODEL_24G_G_ONLY,
	MODEL_24G_N_ONLY,
	MODEL_24G_BG_MIXED,
	MODEL_24G_BGN_MIXED,//defualt
};
enum MODEL_5G
{
	MODEL_5G_A_ONLY = 1,
	MODEL_5G_N_ONLY,
	MODEL_5G_AN_MIXED,//defualt
};

enum FRB {
	FRB_AUTO = 1,//defualt
	FRB_20_MHZ,
	FRB_40_MHZ,
};

enum SECURITY_OPTION {
	SECURITY_OPTION_CLOSE = 1,
	SECURITY_OPTION_WPA_PSK,
	SECURITY_OPTION_WPA,
	SECURITY_OPTION_WEP,
};

typedef struct tag_WLAN_WDS
{
	UCHAR ucWlanType; //	WLAN_TYPE
	BOOL bEnable;
	char szSSID[128];
	UCHAR szBSSID[6];//mac地址
	UCHAR ucChannel; // CHANNEL_24G CHANNEL_50G
	UCHAR ucEncryptType;//ENCRYPT_TYPE
	UCHAR ucWebKeySeq; //WEP_KEY_SEQ 
	UCHAR ucAuthType; //AUTH_TYPE
	char szKey[128];
}WLAN_WDS_S;

typedef struct tag_WLAN_BASIC
{
	UCHAR ucWlanType; //WLAN_24G WLAN_50G
	BOOL bEnable; 
	UCHAR ucChannel; // CHANNEL_24G CHANNEL_50G
	UCHAR ucModel;//0 MODEL_24G MODEL_5G
	UCHAR FRB;//频段带宽 FRB
	char szSSID[128];
	char szDescribe[128];
	BOOL bBroadcast;//default true
	BOOL bApInSeg; //default false
	UCHAR ucSecurityOp;//SECURITY_OPTION 		
}WLAN_BASIC_S;


#ifndef __SERVER
/********************************************
功能：登陆TP-LINK
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulDstIp: TP-LINK IP地址；
	  szUserName: TP-LINK 用户名 
	  szPwd: TP-LINK 密码
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpLogonTplink(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG ulDstIp,char* szUserName,char* szPwd,ULONG ulTimeout);
/********************************************
功能：登陆TP-LINK
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulDstIp: TP-LINK IP地址；
	  szUserName: TP-LINK 用户名 
	  szPwd: TP-LINK 密码
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：用户名和密码固定为 admin 123456
*********************************************/
COM_EXPORT ULONG TphttpLogonTplink900(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG ulDstIp,char* szUserName,char* szPwd,ULONG ulTimeout);

/********************************************
功能: 设置TP-LINK WLAN Basic
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  stWlanBasic: WLAN basic 参数
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpSetWlanBasic(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,WLAN_BASIC_S stWlanBasic,ULONG ulTimeout);
/********************************************
功能: 设置TP-LINK WLAN WDS
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  stWlanWDS: WLAN WDS 参数
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpSetWlanWDS(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,WLAN_WDS_S stWlanWDS,ULONG ulTimeout);
/********************************************
功能: 设置TP-LINK WLAN WDS
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  stWlanWDS: WLAN WDS 参数
	  typedef struct tag_WLAN_WDS
	  {
		UCHAR ucWlanType; //	WLAN_TYPE
		BOOL bEnable; //开启为true 关闭为false
		char szSSID[128];//字符串
		UCHAR szBSSID[6];//mac地址 不能全为0
		UCHAR ucChannel; // 1-255
		UCHAR ucEncryptType;//1不加密 4加密
		UCHAR ucWebKeySeq; //不使用
		UCHAR ucAuthType; //不使用
		char szKey[128];//字符串
	  }WLAN_WDS_S;
	   ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpSetWlanWDS900(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,WLAN_WDS_S stWlanWDS,ULONG ulTimeout);

/********************************************
功能:获取TP-LINK WLAN Basic
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  stWlanWDS: WLAN WDS 参数:
	  { 
	  	UCHAR ucWlanType;
	    	char szSSID[128];
	  }
	  ulTimeout: 函数超时时间，单位为ms
输出：
	stWlanWDS: WLAN WDS 参数
	{
		char szBSSID[6];//mac地址
		UCHAR ucChannel; // CHANNEL_24G CHANNEL_50G
		UCHAR ucEncryptType;//ENCRYPT_TYPE	
	}
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpGetWlanWDS(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,WLAN_WDS_S& stWlanWDS ,ULONG ulTimeout);
//未调通
COM_EXPORT ULONG TphttpGetWlanWDS900(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,WLAN_WDS_S& stWlanWDS ,ULONG ulTimeout);

/********************************************
功能: 保存配置并重启TP-LINK
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpSaveRebootTplink(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG ulTimeout);
/********************************************
功能: 恢复TP-LINK出厂设置
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpRestoreTplink(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId,ULONG ulTimeout);
/********************************************
功能: 退出登陆TP-LINK
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpLogoutTplink(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);
/********************************************
功能: 退出登陆TP-LINK
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based；
	  ulPortId：端口号，1-based；
	  ulTimeout: 函数超时时间，单位为ms
输出：无
	  
返回：成功则返回FD_OK；失败则返回如下值：
    	失败返回其它值:
注意：
*********************************************/
COM_EXPORT ULONG TphttpLogoutTplink900(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId); 
#endif

#ifdef __FOR_CSHARP
}
#endif