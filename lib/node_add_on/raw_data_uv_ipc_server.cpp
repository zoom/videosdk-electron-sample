#include "raw_data_uv_ipc_server.h"
#ifdef _WIN32
#else
#include <unistd.h>
#endif
#include <sstream>
#include <iomanip>

RawDataUVIPCServer::RawDataUVIPCServer()
{
	_client_connected_count = 0;
	_external_sink = NULL;
}
RawDataUVIPCServer::~RawDataUVIPCServer()
{
	ClearMessageRawData();
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
std::string CPtrToStr(char* ptr)
{
	std::ostringstream oss;
	oss << "0x"
		<< std::hex << std::nouppercase
		<< std::setw(sizeof(void*) * 2)
		<< std::setfill('0')
		<< reinterpret_cast<uintptr_t>(ptr);
	return oss.str();
}
void RawDataUVIPCServer::SetMessageRawData(char* key, UVIPCMessage* msg, YUVRawDataI420* data)
{
	std::lock_guard<std::mutex> lock(msg_data_mutex);
	msg->AddRef();
	msg_data_map[CPtrToStr(key)] = MessageRawDataMap{msg, data};
}
void RawDataUVIPCServer::EraseMessageRawData(std::string key)
{
	std::lock_guard<std::mutex> lock(msg_data_mutex);
	auto it = msg_data_map.find(key);
	if (it != msg_data_map.end()) {
		if (it->second.data) it->second.data->Release();
		if (it->second.msg) it->second.msg->Release();
		msg_data_map.erase(it);
	}
}
MessageRawDataMap RawDataUVIPCServer::GetMessageRawData(std::string key)
{
	std::lock_guard<std::mutex> lock(msg_data_mutex);
	auto it = msg_data_map.find(key);
	if (it != msg_data_map.end()) {
		return it->second;
	}
	return MessageRawDataMap{};
}
size_t RawDataUVIPCServer::GetMessageRawDataSize() {
	std::lock_guard<std::mutex> lock(msg_data_mutex);
	return msg_data_map.size();
}
void RawDataUVIPCServer::ClearMessageRawData() {
	std::lock_guard<std::mutex> lock(msg_data_mutex);
	for (auto& pair : msg_data_map) {
		MessageRawDataMap& map = pair.second;
		if (map.data) map.data->Release();
		if (map.msg) map.msg->Release();
	}
	msg_data_map.clear();
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
