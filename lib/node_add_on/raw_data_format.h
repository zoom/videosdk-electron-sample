#ifndef _raw_data_format_h_
#define _raw_data_format_h_
#include "export_h/zoom_video_sdk_def.h"

#include "uv_ipc_common.h"
#include <set>
#define TYPE_NONE  0
#define TYPE_VIDEO 1
#define TYPE_SHARE 2
#define TYPE_AUDIO 3
#if (defined _WIN32)
#define VIDEO_PIPE_NAME "\\\\.\\pipe\\videoPipe"
#define SHARE_PIPE_NAME "\\\\.\\pipe\\sharePipe"
#define AUDIO_PIPE_NAME "\\\\.\\pipe\\audioPipe"
#else
#define VIDEO_PIPE_NAME "/tmp/videoPipe"
#define SHARE_PIPE_NAME "/tmp/sharePipe"
#define AUDIO_PIPE_NAME "/tmp/audioPipe"
#endif
struct RawDataCommonHeader
{
	unsigned int type;
	RawDataCommonHeader()
	{
		type = TYPE_NONE;
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 
struct VideoRawDataHeader
{
	RawDataCommonHeader common_header;
	unsigned int dataBufferLen;
	//unsigned long long recvHandle;
	unsigned int isLimitedI420;
	unsigned int width;
	unsigned int height;
	unsigned int rotation;
	unsigned long long y_offset;
	unsigned long long u_offset;
	unsigned long long v_offset;
	unsigned int source_id;
	unsigned int recv_handle_len;
	VideoRawDataHeader()
	{
		common_header.type = TYPE_NONE;
		dataBufferLen = 0;
		isLimitedI420 = 0;
		width = 0;
		height = 0;
		rotation = 0;
		y_offset = 0;
		u_offset = 0;
		v_offset = 0;
		source_id = 0;
		recv_handle_len = 0;
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 

enum AudioRawDataType
{
	AudioRawDataType_None = 0,
	AudioRawDataType_Mixed,
	AudioRawDataType_OneWay,
	AudioRawDataType_Shared
};

struct AudioRawDataHeader
{
	RawDataCommonHeader common_header;
	bool isMixed;
	std::string userid;
	unsigned int dataBufferLen;
	unsigned int sampleRate;
	unsigned int channelNum;
	AudioRawDataType type;
	AudioRawDataHeader()
	{
		common_header.type = TYPE_NONE;
		isMixed = false;
		dataBufferLen = 0;
		sampleRate = 0;
		channelNum = 0;
		type = AudioRawDataType_None;
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 

UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, unsigned long long* recv_handl_list, int num, unsigned int type);
UVIPCMessage* MakeUVIPCMsg(AudioRawData* data_, AudioRawDataType audio_rawdata_type, std::string userid, unsigned int type);
UVIPCMessage* MakeUVIPCMsg(YUVProcessDataI420* data_, std::set<unsigned long long>& recv_handle, unsigned int type);
#endif // !_raw_data_format_h_
