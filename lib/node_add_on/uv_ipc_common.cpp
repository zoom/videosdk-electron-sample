 #include "uv_ipc_common.h"
#include <map>
#ifdef _WIN32
#else
#include <unistd.h>
#include <string.h>
#endif

void UVIPCLocker::Lock(bool write/* = true*/)
{
	write ? uv_rwlock_wrlock(&uv_rw_locker) : uv_rwlock_rdlock(&uv_rw_locker);
}
void UVIPCLocker::Unlock(bool write/* = true*/)
{
	write ? uv_rwlock_wrunlock(&uv_rw_locker) : uv_rwlock_rdunlock(&uv_rw_locker);
}

UVIPCLocker g_owner_locker;
std::map<void*, UVIPC* > g_owner_list;
//////////////////////////////////////////////////////////////////////////
UVIPCMessage::UVIPCMessage(const char* in_buf, int in_len, bool using_external_buffer_)
{
	buf = NULL;
	len = 0;
	using_external_buffer = using_external_buffer_;
	if (using_external_buffer)
	{
		buf = const_cast<char*>(in_buf);
		len = in_len;
	}
	else
	{
		if (in_len > 0)
		{
			//owner|buffer
			char* real_buf = (char*)malloc(in_len + UVIPC_MSG_HEADER_LEN);
			if (real_buf)
			{
				unsigned long long& owner_ = *(unsigned long long*)real_buf;
				owner_ = (unsigned long long)this;
				int& buf_len = *(int*)(real_buf + sizeof(unsigned long long));
				buf_len = in_len;
				buf = real_buf + UVIPC_MSG_HEADER_LEN;
				in_buf ? memcpy(buf, in_buf, in_len) : memset(buf, 0, in_len);    //checked safe
				len = in_len;
			}
		}
	}
	

	ref_count.Inc();
}

UVIPCMessage::~UVIPCMessage()
{
	if (buf && !using_external_buffer)
	{
		char* real_buf = buf - UVIPC_MSG_HEADER_LEN;
		free(real_buf);
	}
}

char* UVIPCMessage::GetRealBuf()
{
	if (buf && !using_external_buffer)
	{
		return buf - UVIPC_MSG_HEADER_LEN;
	}
	return NULL;
}
int UVIPCMessage::GetRealLen()
{
	if (buf && !using_external_buffer)
	{
		return len + UVIPC_MSG_HEADER_LEN;
	}
	return 0;
}

char* UVIPCMessage::GetBuf()
{
	return buf;
}
int UVIPCMessage::GetLen()
{
	return len;
}
//////////////////////////////////////////////////////////////////////////
UVIPC::UVIPC()
{
	buffered_ipc_msg = NULL;
	buffered_ipc_msg_offset = 0;
	_msg_callback_loop = NULL;
}

UVIPC::~UVIPC()
{
	Stop();
}
bool UVIPC::IsRunning(bool check_connection/* = false*/)
{
	if (check_connection)
	{
		if (uv_data.is_server_mode)
			return uv_data.ut.part_s.client ? true : false;
		else
			return uv_data.ut.part_c.connect ? true : false;
	}
	else
	{
		return uv_data.owner ? true : false;
	}
}

void uv_ipc_timer_cb(uv_timer_t* handle)
{
	UVIPC::UVIPCTimerData* timer_data = (UVIPC::UVIPCTimerData*)handle;
	if (timer_data && timer_data->owener)
	{
		switch (timer_data->type)
		{
		case UVIPC::send_msg_timer:
		{
			timer_data->owener->uv_cb_ipc_sendmsg_timer(handle);
		}
			break;
#ifndef USING_ASYNC_IN_MSGCALLBACK
		case UVIPC::recv_msg_timer:
		{
			timer_data->owener->uv_cb_ipc_recvmsg_timer(handle);
		}
			break;
#endif
		default:
			break;
		}
	}
}

bool UVIPC::Start(char* name_, bool is_server, uv_loop_t* loop_, UVIPCSink* sink_, uv_loop_t* loop_msg_callback/* = NULL*/)
{
	bool succ = false;
	do 
	{
		if (IsRunning())
		{
			break;
		}
		
		if (NULL == name_ || NULL == loop_)
			break;

		succ = is_server ? StartWithServer(name_, is_server, loop_) : StartWithClient(name_, is_server, loop_);
		if (!succ)
			break;

		uv_data.uv_pipe_name = name_;
		uv_data.external_sink = sink_;

		//outgoing msg timer
		uv_timer_init(loop_, &uv_timer_data.uv_timer_req);
		uv_timer_start(&uv_timer_data.uv_timer_req, uv_ipc_timer_cb, 100, 30);
		uv_timer_data.owener = this;
		uv_timer_data.owner_ipc_data = &uv_data;
		uv_timer_data.type = send_msg_timer;

		//incoming msg timer if need
		if (loop_msg_callback)
		{
			_msg_callback_loop = loop_msg_callback;
#ifdef USING_ASYNC_IN_MSGCALLBACK
			uv_async_init(_msg_callback_loop, &_msg_callback_event, msg_callback_thread_sync_proc);
			_msg_callback_event.data = (void*)this;
#else
			StartMsgCallbackTimer(_msg_callback_loop);
#endif
		}		
	} while (false);
	return succ;
}

#ifdef USING_ASYNC_IN_MSGCALLBACK
void UVIPC::SignalMsgCallbackThread()
{
	uv_async_send(&_msg_callback_event);
}
void UVIPC::msg_callback_thread_sync_proc(uv_async_t* handle)
{
	if (handle)
	{
		UVIPC* owner = (UVIPC*)handle->data;
		if (owner)
			owner->HandleUVMsgCallback(owner->uv_data.external_sink);
	}
}
#else
void UVIPC::StartMsgCallbackTimer(uv_loop_t* msg_callback_loop)
{
	if (msg_callback_loop)
	{
		uv_async_t* timer_async_t = new uv_async_t;
		if (timer_async_t)
		{
			#ifndef USING_ASYNC_IN_MSGCALLBACK
			async_handle_list.push_back(timer_async_t);
			#endif
			uv_async_init(msg_callback_loop, timer_async_t, start_msg_callback_timer_sync_proc);
			timer_async_t->data = (void*)this;
			uv_async_send(timer_async_t);
		}
	}
}

void UVIPC::start_msg_callback_timer_sync_proc(uv_async_t* handle)
{
	if (handle && handle->data)
	{
		UVIPC* owner = (UVIPC*)handle->data;
		uv_timer_init(owner->_msg_callback_loop, &owner->msg_callback_uv_timer_data.uv_timer_req);
		uv_timer_start(&owner->msg_callback_uv_timer_data.uv_timer_req, uv_ipc_timer_cb, 100, 30);
		owner->msg_callback_uv_timer_data.owener = owner;
		owner->msg_callback_uv_timer_data.owner_ipc_data = &owner->uv_data;
		owner->msg_callback_uv_timer_data.type = recv_msg_timer;
	
	}
}
#endif

bool UVIPC::Stop()
{
	bool succ = false;
	do 
	{
		if (!IsRunning())
		{
			succ = true;
			break;
		}

		if (uv_data.is_server_mode)
		{
			if (uv_data.ut.part_s.client)
			{
				uv_read_stop((uv_stream_t*)uv_data.ut.part_s.client);
				uv_timer_stop(&uv_timer_data.uv_timer_req);
				uv_close((uv_handle_t*)uv_data.ut.part_s.client, NULL);
				free(uv_data.ut.part_s.client);
				uv_data.ut.part_s.client = NULL;
			}
			uv_close((uv_handle_t*)&uv_data.handle, NULL);
		}
		else
		{
			if (uv_data.ut.part_c.connect)
			{
				uv_read_stop((uv_stream_t*)uv_data.ut.part_c.connect->handle);
				uv_timer_stop(&uv_timer_data.uv_timer_req);
				uv_close((uv_handle_t*)uv_data.ut.part_c.connect->handle, NULL);
				free(uv_data.ut.part_c.connect);
				uv_data.ut.part_c.connect= NULL;
			}
		}
		uv_data.uv_pipe_name.clear();
		uv_data.is_server_mode = false;
		uv_data.uv_looper = NULL;
		uv_data.external_sink = NULL;
		uv_data.owner = NULL;
	} while (false);
	if (buffered_ipc_msg)
	{
		free(buffered_ipc_msg);
		buffered_ipc_msg = NULL;
	}
	buffered_ipc_msg_offset = 0;
	_msg_callback_loop = NULL;
#ifndef USING_ASYNC_IN_MSGCALLBACK
	uv_async_t* item = NULL;
	for (int i = 0; i < async_handle_list.size(); i++)
	{
		item = async_handle_list[i];
		if (item)
			delete item;
	}	
#endif
	return succ;
}

void on_pipe_client_connection_cb(uv_stream_t* server,int status)
{
	UVIPC::UVIPCData* ipc_data = (UVIPC::UVIPCData*)server;
	if (NULL == ipc_data || NULL == ipc_data->owner)
		return;

	ipc_data->owner->uv_cb_client_connection_notify(server, status);
}

bool UVIPC::StartWithServer(char* name_, bool is_server, uv_loop_t* loop_)
{
	bool succ = false;
	do 
	{
		if (NULL == name_ || NULL == loop_ || !is_server)
			break;
		uv_fs_t req;
		uv_fs_unlink(loop_, &req, name_, NULL);
		uv_pipe_init(loop_, (uv_pipe_t*)&uv_data, 0);
		uv_data.owner = this;
		int ret=uv_pipe_bind((uv_pipe_t*)&uv_data, name_);
		if(ret)
		{
			break;
		}

		ret=uv_listen((uv_stream_t*)&uv_data, 128, on_pipe_client_connection_cb);
		if(ret)
		{
			break;
		}

		uv_data.is_server_mode = is_server;
		uv_data.uv_looper = loop_;
		succ = true;
	} while (false);
	return succ;
}

void on_server_connected_cb(uv_connect_t* req,int status)
{
	UVIPC::UVIPCData* ipc_data = (UVIPC::UVIPCData*)req->handle;
	if (ipc_data && ipc_data->owner)
		ipc_data->owner->uv_cb_server_connected_notify(req, status);
}

bool UVIPC::StartWithClient(char* name_, bool is_server, uv_loop_t* loop_)
{
	bool succ = false;
	do 
	{
		if (is_server || NULL == name_ 
			|| NULL == loop_ || NULL != uv_data.ut.part_c.connect)
			break;

		uv_data.owner = this;
		int ret = uv_pipe_init(loop_, (uv_pipe_t*)&uv_data, 0);
		uv_data.ut.part_c.connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));
		uv_pipe_connect(uv_data.ut.part_c.connect, (uv_pipe_t*)&uv_data, name_, on_server_connected_cb);

		uv_data.is_server_mode = is_server;
		uv_data.uv_looper = loop_;
		succ = true;
	} while (false);

	return succ;
}

void alloc_buffer_for_uv_pipe(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf)
{
	buf->base = (char*)malloc(suggested_size);
	buf->len = suggested_size;
}

void on_pipe_data_read_cb(uv_stream_t* client, ssize_t nread,const uv_buf_t* buf)
{
	UVIPC* owner_ = NULL;
	{
		g_owner_locker.Lock(false);
		std::map<void *, UVIPC *>::iterator iter_ = g_owner_list.find(client);
		if (g_owner_list.end() != iter_)
		{
			owner_ = iter_->second;
		}
		g_owner_locker.Unlock(false);
	}

	if (owner_)
		owner_->uv_cb_pipe_data_read(client, nread, buf);
}

void UVIPC::uv_cb_client_connection_notify(uv_stream_t* server, int status)
{
	if(status < 0 || NULL == uv_data.uv_looper
		|| NULL != uv_data.ut.part_s.client)
	{  
		return;
	}
	uv_data.ut.part_s.client = (uv_pipe_t*)malloc(sizeof(uv_pipe_t));
	if (NULL == uv_data.ut.part_s.client)
	{
		return;
	}
	
	uv_pipe_init(uv_data.uv_looper, uv_data.ut.part_s.client ,0);
	int ret=uv_accept(server, (uv_stream_t*)uv_data.ut.part_s.client);
	if(ret==0)
	{
		{
			g_owner_locker.Lock(true);
			g_owner_list.insert(std::make_pair((void*)uv_data.ut.part_s.client, this));
			g_owner_locker.Unlock(true);
		}
		if (uv_data.external_sink)
			uv_data.external_sink->onConnect();
		uv_read_start((uv_stream_t*)uv_data.ut.part_s.client, alloc_buffer_for_uv_pipe, on_pipe_data_read_cb);
	}
}

#define BUFFERED_MSG_MAX_LEN (30*1024*1024)
void UVIPC::uv_cb_pipe_data_read(uv_stream_t* client, ssize_t nread,const uv_buf_t* buf)
{
	if(nread<0)
	{
		if(nread!=UV_EOF)
		{    
		}

		if (uv_data.external_sink)
			uv_data.external_sink->onDisconnect();
		Stop();
	}
	else if(nread > 0 && uv_data.external_sink)
	{
		if (NULL == buffered_ipc_msg)
		{
			buffered_ipc_msg = (char*)malloc(BUFFERED_MSG_MAX_LEN);
			buffered_ipc_msg_offset = 0;
		}
		const char* p(NULL), *end(NULL);
		if (buffered_ipc_msg_offset == 0)
		{
			p = buf->base;
			end = p + nread;
		}
		else
		{
            ssize_t buffer_remain = BUFFERED_MSG_MAX_LEN - buffered_ipc_msg_offset;
			if (buffer_remain > nread)
			{
				memcpy(buffered_ipc_msg + buffered_ipc_msg_offset, buf->base, nread);   //checked safe
				buffered_ipc_msg_offset += nread;
				p = buffered_ipc_msg;
				end = p + buffered_ipc_msg_offset;
			}
			else
			{
				//fix me.
			}
		}
		
		while (p < end) {
            if (p + UVIPC_MSG_HEADER_LEN >= end)
                break;
			int msgLen = *(int*)(p+sizeof(unsigned long long));
			int dataLen = msgLen + UVIPC_MSG_HEADER_LEN;
			if (p + dataLen <= end)
			{
				char* real_buf = (char*)(p + UVIPC_MSG_HEADER_LEN);
				UVIPCMessage* msg = new UVIPCMessage(real_buf, msgLen);
				if (msg)
				{
					uv_data.owner->HandleMessageRecvNotification(msg);
					msg->Release();
				}
				p = p + dataLen;
			}
			else {
				// Last message is partial.
				break;
			}
		}
		memmove(buffered_ipc_msg, p, end - p);    //checked safe
		buffered_ipc_msg_offset = end - p;
	}

	if (buf && buf->base)
	{
		free(buf->base);
	}
}

void UVIPC::uv_cb_pipe_data_write(uv_write_t* req, int status)
{

}

void on_write_data_cb(uv_write_t* req,int status)
{
	if (status == 0) {
	}

	uv_buf_t* w_buf = (uv_buf_t*)req->data;
	if (w_buf)
	{
		unsigned long long* real_buf = (unsigned long long*)(w_buf->base);
		UVIPCMessage* msg = (UVIPCMessage*)*real_buf;
		msg->Release();
		free(w_buf);
	}
	free(req);

}

void UVIPC::uv_cb_server_connected_notify(uv_connect_t* req,int status)
{
	do 
	{
		{
			g_owner_locker.Lock(true);
			g_owner_list.insert(std::make_pair((void*)req->handle, this));
			g_owner_locker.Unlock(true);
		}
		if (uv_data.external_sink)
		{
			(0 == status) ? uv_data.external_sink->onConnect() : uv_data.external_sink->onDisconnect();
		}

		if (0 == status)
			uv_read_start((uv_stream_t*)req->handle, alloc_buffer_for_uv_pipe, on_pipe_data_read_cb);
		else
			Stop();
	} while (false);
}

bool UVIPC::SendMessage(const char* buf, int len)
{
	if (NULL == buf || len <= 0)
		return false;

	if (!IsRunning(true))
		return false;
	
	UVIPCMessage* msg = new UVIPCMessage(buf, len);
	outmsg_locker.Lock();
	outmsg_list.push_back(msg);
	outmsg_locker.Unlock();

	return true;
}

bool UVIPC::SendMessage(UVIPCMessage* msg)
{
	if (!IsRunning(true))
		return false;

	outmsg_locker.Lock();
	outmsg_list.push_back(msg);
	outmsg_locker.Unlock();

	return true;
}

void UVIPC::uv_cb_ipc_sendmsg_timer(uv_timer_t* handle)
{
	if (outmsg_list.size() <= 0
		|| (uv_data.is_server_mode && NULL == uv_data.ut.part_s.client)
		|| (!uv_data.is_server_mode && NULL == uv_data.ut.part_c.connect))
	{
		if (outmsg_list.size() <= 0 && uv_data.external_sink && IsRunning(true))
			uv_data.external_sink->onIdle();
		return;
	}

	std::list<UVIPCMessage* > tmp_outmsg_list;
	outmsg_locker.Lock();
	tmp_outmsg_list.swap(outmsg_list);
	outmsg_locker.Unlock();
	std::list<UVIPCMessage* >::iterator it_msg = tmp_outmsg_list.begin();
	while(tmp_outmsg_list.end() != it_msg)
	{
		UVIPCMessage* msg = *it_msg;
		if (msg)
		{
			uv_write_t* w_req = (uv_write_t*)malloc(sizeof(uv_write_t));
			uv_buf_t* w_buf = (uv_buf_t*)malloc(sizeof(uv_buf_t));

			w_buf->base = msg->GetRealBuf();
			w_buf->len = msg->GetRealLen();
			w_req->data = w_buf;
			int ret = uv_write(w_req, (uv_data.is_server_mode ? (uv_stream_t*)uv_data.ut.part_s.client : uv_data.ut.part_c.connect->handle),
				w_buf, 1, on_write_data_cb);
			it_msg = tmp_outmsg_list.erase(it_msg);
		}
	}
}

void UVIPC::HandleMessageRecvNotification(UVIPCMessage* msg)
{
	if (NULL == _msg_callback_loop)
	{
		if (uv_data.external_sink)
			uv_data.external_sink->onMessageRecvNotification(msg);
	}
	else
	{
		msg->AddRef();
		inmsg_locker.Lock();
		inmsg_list.push_back(msg);
		inmsg_locker.Unlock();
#ifdef USING_ASYNC_IN_MSGCALLBACK
		SignalMsgCallbackThread();
#endif
	}
}

#ifndef USING_ASYNC_IN_MSGCALLBACK
void  UVIPC::uv_cb_ipc_recvmsg_timer(uv_timer_t* handle)
{
	HandleUVMsgCallback(uv_data.external_sink);
}
#endif

void UVIPC::HandleUVMsgCallback(UVIPCSink* external_sink)
{
	if (external_sink)
	{
		std::list<UVIPCMessage* > tmp_inmsg_list;
		inmsg_locker.Lock();
		tmp_inmsg_list.swap(inmsg_list);
		inmsg_locker.Unlock();
		std::list<UVIPCMessage* >::iterator it_msg = tmp_inmsg_list.begin();
		while (tmp_inmsg_list.end() != it_msg)
		{
			UVIPCMessage* msg = *it_msg;
			if (msg)
			{
				external_sink->onMessageRecvNotification(msg);
				msg->Release();
			}
			it_msg++;
		}
	}
}

/////////////////////////////////////////

static void z_sleep(unsigned int millisecond) {
#ifdef _WIN32
	::Sleep(millisecond);
#else
	usleep(millisecond * 1000);
#endif
}

void UVIPCInSubThread::work_thread_sync_proc(uv_async_t* handle) {
	if (handle && handle->data)
	{
		UVIPCInSubThread* p_work = (UVIPCInSubThread*)handle->data;
		if (0xccdd == p_work->_action)
		{
			p_work->_action = 0;
			uv_stop(p_work->_sub_thread_loop);
		}
	}
}

void UVIPCInSubThread::work_thread_proc(void* param)
{
	if (NULL == param)
		return;

	UVIPCInSubThread* p_work = (UVIPCInSubThread*)param;
	p_work->_sub_thread_loop = new uv_loop_t;
	if (p_work->_sub_thread_loop)
	{
		uv_loop_init(p_work->_sub_thread_loop);
		uv_async_init(p_work->_sub_thread_loop, &p_work->_async, work_thread_sync_proc);
		p_work->BeforeSubThreadLoopRun();

		p_work->_running = true;
		uv_sem_post(&p_work->sem_start_thread);
		uv_run(p_work->_sub_thread_loop, UV_RUN_DEFAULT);
        p_work->AfterSubThreadLoopRun();
		uv_close((uv_handle_t*)&p_work->_async, NULL);

		uv_loop_close(p_work->_sub_thread_loop);
		p_work->_running = false;
		uv_sem_post(&p_work->sem_stop_thread);
	}

	if (p_work->_sub_thread_loop)
	{
		delete p_work->_sub_thread_loop;
		p_work->_sub_thread_loop = NULL;
	}
}


UVIPCInSubThread::UVIPCInSubThread()
{
	Reset();
}

void UVIPCInSubThread::Reset()
{
	_is_server_mode = false;
	memset(&_async, 0, sizeof(_async));     //checked safe
	_pipe_name.clear();
	_sub_thread_loop = NULL;
	_msg_callback_loop = NULL;
	_sink = NULL;
	_running = false;
	_action = 0;
}
UVIPCInSubThread::~UVIPCInSubThread()
{
}
bool UVIPCInSubThread::StartInSubThread(const char* name_, bool is_server, UVIPCSink* sink_, uv_loop_t* msg_callback_loop_ /*= NULL*/)
{
	if (NULL == name_)
		return false;

	if (_running)
		return false;

	_pipe_name = name_;
	_sink = sink_;
	_is_server_mode = is_server;
	uv_thread_t work_thread;
	_msg_callback_loop = msg_callback_loop_;
	uv_sem_init(&sem_start_thread, 0);
	uv_thread_create(&work_thread, work_thread_proc, this);
	uv_sem_wait(&sem_start_thread);

	return true;
}

bool UVIPCInSubThread::Stop()
{
	if (_running && 0xccdd != _action)
	{
		uv_sem_init(&sem_stop_thread, 0);
		_action = 0xccdd;
		_async.data = (void*)this;
		uv_async_send(&_async);
		uv_sem_wait(&sem_stop_thread);
	}
	return true;
}

void UVIPCInSubThread::BeforeSubThreadLoopRun()
{
	UVIPC::Start(const_cast<char*>(_pipe_name.c_str()), _is_server_mode, _sub_thread_loop, _sink, _msg_callback_loop);
}

void UVIPCInSubThread::AfterSubThreadLoopRun()
{
    UVIPC::Stop();
}
