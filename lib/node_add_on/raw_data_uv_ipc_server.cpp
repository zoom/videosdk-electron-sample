#include "raw_data_uv_ipc_server.h"
#ifdef _WIN32
#else
#include <unistd.h>
#endif
RawDataUVIPCServer::RawDataUVIPCServer()
{
	_client_connected_count = 0;
	_external_sink = NULL;
}
RawDataUVIPCServer::~RawDataUVIPCServer()
{
}
bool RawDataUVIPCServer::StartPipeServer(const char* pipe_name, UVIPCSink* sink)
{
	_external_sink = sink;
	return _pipe_server.StartInSubThread(pipe_name, true, this, NULL);
}
bool RawDataUVIPCServer::StopPipeServer()
{
	return _pipe_server.Stop();
}

bool RawDataUVIPCServer::SendMessage(const char* buf, int len)
{
	if (_pipe_server.IsSubThreadRunning())
	{
		return _pipe_server.SendMessage(buf, len);
	}

	return false;
}
bool RawDataUVIPCServer::SendMessage(UVIPCMessage* msg)
{
	if (_pipe_server.IsSubThreadRunning())
	{
		return _pipe_server.SendMessage(msg);
	}

	return false;
}

void RawDataUVIPCServer::onMessageRecvNotification(UVIPCMessage* msg)
{
	if (_external_sink)
		_external_sink->onMessageRecvNotification(msg);
}
void RawDataUVIPCServer::onConnect()
{
	++_client_connected_count;
	if (_external_sink)
		_external_sink->onConnect();
}
void RawDataUVIPCServer::onDisconnect()
{
	--_client_connected_count;
	if (_external_sink)
		_external_sink->onConnect();
}
void RawDataUVIPCServer::onIdle()
{
	if (_external_sink)
		_external_sink->onIdle();
}
