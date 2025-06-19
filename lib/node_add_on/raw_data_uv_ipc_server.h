#ifndef _raw_data_uv_ipc_server_h_
#define _raw_data_uv_ipc_server_h_
#include "uv_ipc_common.h"
#include "export_h/zoom_video_sdk_def.h"
#include <string>
#include <map>
#include <mutex>

struct MessageRawDataMap {
	UVIPCMessage* msg = nullptr;
	YUVRawDataI420* data = nullptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////
class RawDataUVIPCServer : public UVIPCSink
{
public:
	RawDataUVIPCServer();
	virtual ~RawDataUVIPCServer();
	bool StartPipeServer(const char* pipe_name, UVIPCSink* sink);
	bool StopPipeServer();


	virtual void onMessageRecvNotification(UVIPCMessage* msg);
	virtual void onConnect();
	virtual void onDisconnect();
	virtual void onIdle();
	bool SendMessage(const char* buf, int len);
	bool SendMessage(UVIPCMessage* msg);

	bool HasClientConnected() { return _pipe_server.IsRunning(true); }
	
	void SetMessageRawData(char* key, UVIPCMessage* msg, YUVRawDataI420* data);
	void EraseMessageRawData(std::string key);
	MessageRawDataMap GetMessageRawData(std::string key);
	size_t GetMessageRawDataSize();
	void ClearMessageRawData();
private:
	int  _client_connected_count;
	UVIPCInSubThread _pipe_server;
	UVIPCSink* _external_sink;
	std::map<std::string, MessageRawDataMap> msg_data_map;
	std::mutex msg_data_mutex;
};
#endif