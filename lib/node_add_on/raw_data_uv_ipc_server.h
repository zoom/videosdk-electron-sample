#ifndef _raw_data_uv_ipc_server_h_
#define _raw_data_uv_ipc_server_h_
#include "uv_ipc_common.h"
#include <string>

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
private:
	int  _client_connected_count;
	UVIPCInSubThread _pipe_server;
	UVIPCSink* _external_sink;
};
#endif