#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef __FOR_CSHARP
extern "C" {
#endif


#define CAP_ERROR_CAPTURING					(400)
#define CAP_ERROR_CAPTURE_PLANE				(401)
#define CAP_ERROR_CAPTURE_TYPE				(402)
#define CAP_ERROR_CAPTURE_ID				(403)
#define CAP_ERROR_FRAME_INDEX				(404)
#define CAP_ERROR_DOWNLOADING				(405)
#define CAP_ERROR_FILTER_MAP                (406)

#define CAP_PLANE_CONTROL_AND_DATA			(0)
#define CAP_PLANE_CONTROL					(1)

#define CAP_TYPE_ALL						(0X00000001)
#define CAP_TYPE_FCS_ERROR					(0X00000002)
#define CAP_TYPE_IPV4_CHECKSUN_ERROR		(0X00000004)
#define CAP_TYPE_PAYLOAD_ERROR				(0X00000008)
#define CAP_TYPE_FILTER						(0X00000010)



#ifndef __SERVER///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __FW
/********************************************
功能：设置指定端口的捕获类型
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ucCapPlane：捕获平面。CAP_PLANE_CONTROL_AND_DATA表示捕获控制和数据平面的接收帧，
	              CAP_PLANE_CONTROL表示捕获控制平面的发送和接收帧；
	  ucCapType：捕获类型。
	             当ucCapPlane==CAP_PLANE_CONTROL_AND_DATA时捕获类型有：
					CAP_TYPE_ALL表示捕获所有帧、
					CAP_TYPE_FCS_ERROR表示捕获FCS错误帧、
					CAP_TYPE_IPV4_CHECKSUN_ERROR表示捕获IPv4首部校验和错误帧、
					CAP_TYPE_PAYLOAD_ERROR表示捕获净荷校验错误帧、
					CAP_TYPE_FILTER表示捕获满足过滤模板的帧。
					其中CAP_TYPE_ALL和其它4种捕获类型是互斥关系，其它4种捕获类型是或的关系；
	             当ucCapPlane==CAP_PLANE_CONTROL时捕获类型有：
					CAP_TYPE_ALL表示捕获所有帧、
					CAP_TYPE_FILTER表示捕获满足过滤模板的帧，这两者是互斥关系。
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  CAP_ERROR_CAPTURE_PLANE表示输入的ucCapPlane错误，
	  CAP_ERROR_CAPTURE_TYPE表示输入ucCapType错误。
注意：若不调用该函数，默认为捕获平面为捕获控制和数据平面的接收帧，捕获类型为捕获所有帧。
*********************************************/
COM_EXPORT ULONG CapSetType(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, UCHAR ucCapPlane, UCHAR ucCapType);


/********************************************
功能：设置指定端口的捕获过滤模板
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucFilterMask：过滤模板掩码；
	  pucFilterValue：过滤模板值节；
	  ulFilterLen：模板长度，以字节为单位，最大为128字节；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURING表示正在捕获帧，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapSetPortFilter(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);


/********************************************
功能：设置指定端口的第二个捕获过滤模板
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  pucFilterMask：过滤模板掩码；
	  pucFilterValue：过滤模板值节；
	  ulFilterLen：模板长度，以字节为单位，最大为128字节；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURING表示正在捕获帧，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapSetPortFilterAdd(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, 
	UCHAR *pucFilterMask, UCHAR *pucFilterValue, ULONG ulFilterLen);


/********************************************
功能：设置指定端口的捕获过滤模板
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulFilterUsedMap：1:模板1生效 2:模板2生效 3:模板1或模板2生效 4:模板1和模板2同时生效
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURING表示正在捕获帧，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapSetPortFilterMap(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFilterUsedMap);


/********************************************
功能：使能或不使能指定端口的帧捕获
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  bEnable： 是否使能报文捕获；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  CAP_ERROR_DOWNLOADING表示端口正在下载捕获报文。
注意：不调用该函数，默认为使能帧捕获。
*********************************************/
COM_EXPORT ULONG CapEnablePort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, BOOL bEnable);


/********************************************
功能：从FloodServer下载指定端口已经捕获的帧
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pulCapId：捕获ID指针。捕获ID供捕获模块其它函数使用；
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURING表示正在捕获报文，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口的端口还没有预定，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapDownloadFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulCapId);


/********************************************
功能：从FloodServer下载指定端口已经捕获的帧
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  caCapFilePath：为空则表示下载到内存，不为空表示以cap文件格式保存到指定路径；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURING表示正在捕获报文，
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示指定端口的端口还没有预定，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortDownloadFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char *caCapFilePath);


/********************************************
功能：停止指定端口的下载
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapDownloadStop(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：等待上一次下载指令完成
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  ulTimeout：等待超时时间，单位为ms；
输出：：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapWaitForDownloadFinish(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulTimeout);


/********************************************
功能：判断指定端口是否正在下载
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  nType：检测类型，0表示检测本地测试状态，1表示检测服务器测试状态；
输出：pbDownloading：TRUE(1)表示正在下载，FALSE(0)表示下载未开启;
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortIsDownloading(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbDownloading);


/********************************************
功能：获取当前已下载或捕获的帧数目
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  nType：获取类型，0表示获取本地已下载的帧数目，1表示获取服务器已捕获的帧数目；
输出：pulFrameCount：捕获帧的数目指针；
	  pbIsFull：是否捕获满的指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  FD_ERROR_TIMEOUT表示获取超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortGetFrameCount(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, ULONG *pulFrameCount, BOOL *pbIsFull);


/********************************************
功能：获取当前已下载的帧数目
输入：ulCapId： 捕获ID，由函数CapDownloadFrames输出；
输出：pulFrameCount：捕获帧的数目指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURE_ID表示输入的ulCapId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapGetFrameCount(ULONG ulCapId, ULONG *pulFrameCount);


/********************************************
功能：获取当前服务器已捕获到的帧数目
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：pulFrameCount：捕获帧的数目指针；
	  pbIsFull：是否捕获满的指针
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示端口未预约，
	  FD_ERROR_TIMEOUT表示获取超时，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapGetFrameCountEx(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG *pulFrameCount, BOOL *pbIsFull);


/********************************************
功能：获取指定序号的帧
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
      ulFrameIndex：要获取的已经捕获的帧的序号，1-based;
输出：ppucFrame：该帧内容的指针的指针；
      pulFrameLength：帧长度指针；
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  CAP_ERROR_FRAME_INDEX表示输入的帧序号错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortGetFrame(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, ULONG ulFrameIndex, UCHAR **ppucFrame, ULONG *pulFrameLength);


/********************************************
功能：获取指定序号的帧
输入：ulCapId： 捕获ID，由函数CapDownloadFrames输出；
      ulFrameIndex：要获取的已经捕获的帧的序号，1-based;
输出：ppucFrame：该帧内容的指针的指针；
      pulFrameLength：帧长度指针；
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURE_ID表示输入的ulCapId错误，
	  CAP_ERROR_FRAME_INDEX表示输入的帧序号错误。
注意：
*********************************************/
COM_EXPORT ULONG CapGetFrame(ULONG ulCapId, ULONG ulFrameIndex, UCHAR **ppucFrame, ULONG *pulFrameLength);


/********************************************
功能：删除指定端口已下载的报文
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：CapPortDownloadFrames调用之后须调用该函数来释放申请的空间。
*********************************************/
COM_EXPORT ULONG CapPortDeleteFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：将指定端口已下载的帧以cap文件格式保存到指定路径；
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  caCapFilePath：cap文件路径；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR表示其它错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortSaveFrames(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, const char *caCapFilePath);


/********************************************
功能：删除由Capture ID指定的帧
输入：ulCapId： 捕获ID，由函数CapDownloadFrames输出；
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
	  CAP_ERROR_CAPTURE_ID表示输入的ulCapId错误。
注意：CapDownloadFrames调用之后须调用该函数来释放申请的空间。
*********************************************/
COM_EXPORT ULONG CapDeleteFrames(ULONG ulCapId);
#endif


/********************************************
功能：开始指定端口的捕获
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG CapStartPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：停止指定端口的捕获
输入：ulChsId： 指定流的目的机框ID，1-based；
      ulSlotId：指定流的目的槽位号，1-based;
	  ulPortId：指定流的目的端口号，1-based;
输出：无
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误，
	  FD_ERROR_PORT_NOT_RESERVED表示该端口还没有被预定，
	  FD_ERROR表示其它错误。
注意：无
*********************************************/
COM_EXPORT ULONG CapStopPort(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId);


/********************************************
功能：判断指定端口是否正在捕获
输入：ulChsId： 机框ID，1-based；
      ulSlotId：槽位号，1-based;
	  ulPortId：端口号，1-based;
	  nType：检测类型，0表示检测本地测试状态，1表示检测服务器测试状态；
输出：pbTesting：TRUE(1)表示正在捕获，FALSE(0)表示捕获未开启;
返回：成功则返回FD_OK；失败则返回如下值：
      FD_ERROR_CHASSIS_ID表示输入的ulChsId错误，
	  FD_ERROR_SLOT_ID表示输入的ulSlotId错误，
	  FD_ERROR_PORT_ID表示输入的ulPortId错误。
注意：
*********************************************/
COM_EXPORT ULONG CapPortIsTesting(ULONG ulChsId, ULONG ulSlotId, ULONG ulPortId, int nType, BOOL *pbTesting);


/********************************************
功能：启动报文捕获
输入：无
输出：无
返回：无
注意：
*********************************************/
COM_EXPORT void CapStart();


/********************************************
功能：停止报文捕获
输入：无
输出：无
返回：无
注意：
*********************************************/
COM_EXPORT void CapStop();
#endif


#ifdef __FOR_CSHARP
}
#endif

