#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif



#define STA_ERROR_PORT_STATISTICS_TYPE					(300)
#define STA_ERROR_STREAM_STATISTICS_TYPE				(301)
#define STA_ERROR_EXCEED_MAX_STREAM_ID					(302)
#define STA_ERROR_DOING_STATISTICS						(303)
#define STA_ERROR_STATIC_STARTING                       (304)
#define STA_ERROR_STATIC_FILTER_MAP                     (305)



#define STA_MEA_TX_STREAM_FRAME				(0)  //端口和流都适用
#define STA_MEA_RX_STREAM_FRAME				(1)  //端口和流都适用
#define STA_MEA_TX_TOTAL_FRAME				(2)  //端口适用
#define STA_MEA_RX_TOTAL_FRAME				(3)  //端口适用
#define STA_MEA_TX_FPS						(4)  //端口和流都适用
#define STA_MEA_RX_FPS						(5)  //端口和流都适用
#define STA_MEA_TX_BPS						(6)  //端口和流都适用
#define STA_MEA_RX_BPS						(7)  //端口和流都适用
#define STA_MEA_RX_SEQUENCE_ERROR			(8)  //流适用
#define STA_MEA_RX_PAYLOAD_ERROR			(9)  //流适用
#define STA_MEA_RX_IPV4_CHECKSUM_ERROR		(10) //端口适用
#define STA_MEA_RX_FCS_ERROR				(11) //端口适用
#define STA_MEA_RX_FILTER					(12) //端口适用
#define STA_MEA_MIN_LATENCY_S				(13) //流适用, 时延的单位是us
#define STA_MEA_AVG_LATENCY_S				(14) //流适用, 时延的单位是us
#define STA_MEA_MAX_LATENCY_S				(15) //流适用, 时延的单位是us
#define STA_MEA_MIN_LATENCY_C				(16) //流适用, 时延的单位是us
#define STA_MEA_AVG_LATENCY_C				(17) //流适用, 时延的单位是us
#define STA_MEA_MAX_LATENCY_C				(18) //流适用, 时延的单位是us
#define STA_MEA_TX_bps						(19) //端口和流都适用
#define STA_MEA_RX_bps						(20) //端口和流都适用
#define STA_MEA_RX_UTIL						(21) //端口和流都适用
#define STA_MEA_MIN_LATENCY_JITTER_S		(22) //流适用, 时延的单位是us
#define STA_MEA_AVG_LATENCY_JITTER_S		(23) //流适用, 时延的单位是us
#define STA_MEA_MAX_LATENCY_JITTER_S		(24) //流适用, 时延的单位是us
#define STA_MEA_MIN_LATENCY_JITTER_C		(25) //流适用, 时延的单位是us
#define STA_MEA_AVG_LATENCY_JITTER_C		(26) //流适用, 时延的单位是us
#define STA_MEA_MAX_LATENCY_JITTER_C		(27) //流适用, 时延的单位是us
#define STA_MEA_RX_MIN_BPS					(28)  //流适用
#define STA_MEA_RX_AVG_BPS					(29)  //流适用
#define STA_MEA_RX_MAX_BPS					(30)  //流适用
#define STA_MEA_TX_Mbps						(31) //端口和流都适用
#define STA_MEA_RX_Mbps						(32) //端口和流都适用

#define STA_MEA_TX_TOTAL_BYTE               (33)//端口适用
#define STA_MEA_RX_TOTAL_BYTE               (34)//端口适用
#define STA_MEA_RX_PAUSE_FRAME              (35)//端口适用
#define STA_MEA_RX_UNDER_SIZE_FRAME         (36)//端口适用
#define STA_MEA_RX_BIT_ERROR_COUNT          (37)//端口适用
#define STA_MEA_RX_FILTER_RATE              (38)//端口适用
#define STA_MEA_RX_TCP_CHECKSUM_ERROR       (39)//端口适用
#define STA_MEA_RX_UDP_CHECKSUM_ERROR       (40)//端口适用
#define STA_MEA_RX_LOSS_STREAM_FRAME		(41)//流适用


#define STA_MEA_RX_FIRST_PACKET_TIME        (0)
#define STA_MEA_RX_LAST_PACKET_TIME         (1)

typedef struct tag_STA_MEA_SET
{
	BOOL bTxBpsCrc;
	BOOL bTxBpsPreamble;
	BOOL bTxBpsMinIfg;
	BOOL bTxUda;
	ULONG ulTxUdaLen;
	BOOL bRxBpsCrc;
	BOOL bRxBpsPreamble;
	BOOL bRxBpsMinIfg;
	BOOL bRxUda;
	ULONG ulRxUdaLen;
	ULONG ulUsfThreshold;
} STA_MEA_SET;


#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
功能：在指定的目的端口号下选择要统计的流
输入：ulChsId： 目的机框ID，1-based；
      ulSlotId：目的槽位号，1-based;
	  ulPortId：目的端口号，1-based;
	  pcStreamName：流名称；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_DOING_STATISTICS表示正在进行统计，
	  STA_ERROR_EXCEED_MAX_STREAM_ID表示该端口下所选择统计的流中最大的流ID和最小的流ID之差大于256，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaSelectStream(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName);


/********************************************
功能：删除指定的目的端口号下选择要统计的所有流
输入：ulChsId： 目的机框ID，1-based；
      ulSlotId：目的槽位号，1-based;
	  ulPortId：目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  STA_ERROR_DOING_STATISTICS表示正在进行统计，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaRemoveStreams(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：获取指定端口的多个统计数据
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulStaNum: 统计项数目
	  pucStaItem：端口统计项；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  STA_ERROR_PORT_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_CARD_NOT_RESERVED表示该接口卡还没有被预定，
	  FD_ERROR表示其它错误。
注意：不允许存在重复的统计项
*********************************************/
COM_EXPORT ULONG StaGetPortDatas(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);

/********************************************
功能：获取指定端口的多个统计数据
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulStaNum: 统计项数目
	  pucStaItem：端口统计项；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  STA_ERROR_PORT_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_CARD_NOT_RESERVED表示该接口卡还没有被预定，
	  FD_ERROR表示其它错误。
注意：不允许存在重复的统计项 功能和StaGetPortDatas相同  非整数的统计项是double数据的二级制数，需要进行类型强转换。
*********************************************/
COM_EXPORT ULONG StaGetPortDatasRaw(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);


/********************************************
功能：获取指定端口的统计数据
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucStaItem：端口统计数据类型；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  STA_ERROR_PORT_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR不是其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaGetPortData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR ucStaItem, UINT64 *pui64Value);


/********************************************
功能：获取指定流的统计数据
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
	  pcStreamName：流名称；
	  ucStaItem：流统计项；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_STREAM_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR不是其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaGetStreamData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, UCHAR ucStaItem, UINT64 *pui64Value);

/********************************************
功能:获取指定流某个包的接收时间
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
	  pcStreamName：流名称；
	  ucStaItem：流统计项0第一包接收的时间，1最后一个包接收的时间

ucStaItem:0第一包接收的时间，1最后一个包接收的时间
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_STREAM_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR不是其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaGetPacketRecTime(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, UCHAR ucStaItem, UINT64 *pui64Value);

/********************************************
功能:获取指定流从开始统计到统计到乱序的时间间隔
输入：ulDstChsId： 指定流的目的机框ID，1-based；
      ulDstSlotId：指定流的目的槽位号，1-based;
	  ulDstPortId：指定流的目的端口号，1-based;
	  pcStreamName：流名称；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_STREAM_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR不是其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaGetStreamSeqErrorTime(ULONG ulDstChsId, ULONG ulDstSlotId, ULONG ulDstPortId, const char *pcStreamName,UINT64 *pui64Value);


/********************************************
功能：获取指定流的多个统计数据
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
	  pcStreamName：流名称；
	  ulStaNum: 统计项数目
	  pucStaItem：流统计项；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_STREAM_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_CARD_NOT_RESERVED表示该接口卡还没有被预定，
	  FD_ERROR表示其它错误。
注意：不允许存在重复的统计项
*********************************************/
COM_EXPORT ULONG StaGetStreamDatas(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);

/********************************************
功能：获取指定流的多个统计数据
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
	  pcStreamName：流名称；
	  ulStaNum: 统计项数目
	  pucStaItem：流统计项；
输出：pui64Value：统计数据指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_STREAM_NAME表示输入的pcStreamName错误，
	  STA_ERROR_STREAM_STATISTICS_TYPE表示输入的ucStaType错误，
	  FD_ERROR_CARD_NOT_RESERVED表示该接口卡还没有被预定，
	  FD_ERROR表示其它错误。
注意：不允许存在重复的统计项 功能和StaGetPortDatas相同  非整数的统计项是double数据的二级制数，需要进行类型强转换。
*********************************************/
COM_EXPORT ULONG StaGetStreamDatasRaw(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	const char *pcStreamName, ULONG ulStaNum, UCHAR pucStaItem[], UINT64 pui64Value[]);


/********************************************
功能：若端口在统计中，清除指定端口的统计数据；若端口未在统计中，复位端口发送和统计状态
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  TRA_ERROR_TRANSMITING表示该端口正在发送，
	  FD_ERROR表示其它错误。
注意：在端口只开启发送不开启统计时需要先调用该函数
*********************************************/
COM_EXPORT ULONG StaClearData(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：设置指定端口的统计过滤模板
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucFilterMask：过滤模板掩码；
	  pucFilterValue：过滤模板值节；
	  ulFilterLen：模板长度，以字节为单位，最大为128字节；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  STA_ERROR_DOING_STATISTICS表示正在进行统计，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG StaSetPortFilter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);

/********************************************
功能：设置指定端口的第二个统计过滤模板
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucFilterMask：过滤模板掩码；
	  pucFilterValue：过滤模板值节；
	  ulFilterLen：模板长度，以字节为单位，最大为128字节；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  STA_ERROR_DOING_STATISTICS表示正在进行统计，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG StaSetPortFilterAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);

/********************************************
功能：设置指定端口的统计过滤生效类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulFilterUsedMap：1:模板1生效 2:模板2生效 3:模板1或模板2生效 4:模板1和模板2同时生效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  STA_ERROR_DOING_STATISTICS表示正在进行统计，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG StaSetPortFilterMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFilterUsedMap);



/********************************************
功能：开始指定端口的统计
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  TRA_ERROR_TRANSMITING表示该端口正在发送，
	  FD_ERROR表示其它错误。
注意：在端口需要同时开启发送与统计时，应先开启统计再开启发送
*********************************************/
COM_EXPORT ULONG StaStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：停止指定端口的统计
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
COM_EXPORT ULONG StaStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);

/********************************************
功能：检测指定端口是否正在统计
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  nType：检测类型，0表示检测本地测试状态，1表示检测服务器测试状态；
输出：pbTesting：TRUE(1)表示正在统计，FALSE(0)表示统计未开启;
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG StaPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);

/********************************************
功能：获取统计状态
输入：无
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
     		STA_ERROR_STATIC_STARTING 开始统计执行中
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG StaGetStaState();

COM_EXPORT ULONG StaSetPortBitErrorMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId ,BOOL bEnable,UCHAR ucData[16]);

#endif
#endif


#ifdef __FOR_CSHARP
}
#endif

