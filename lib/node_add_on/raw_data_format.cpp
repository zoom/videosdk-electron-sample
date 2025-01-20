#include "raw_data_format.h"
#include <set>
#include <string.h>

UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, unsigned long long* recv_handl_list, int num, unsigned int type)
{
	if (NULL == data_)
		return NULL;
	
	IYUVRawDataI420Converter* yuv_data_converter = dynamic_cast<IYUVRawDataI420Converter*>(data_);
	if (NULL == yuv_data_converter)
		return NULL;
	unsigned int dataBufferLen = (data_->GetStreamWidth()*data_->GetStreamHeight()*3)/2;
	
	int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + sizeof(unsigned long long) * num + dataBufferLen;//head+recv_list+buffer
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;
	char* buf_ptr = rawdata_msg->GetBuf();
	if (NULL == buf_ptr)
	{
		rawdata_msg->Release();
		return NULL;
	}
	unsigned long long* recv_list = (unsigned long long*)(buf_ptr + sizeof(VideoRawDataHeader));
	memcpy(recv_list, recv_handl_list, sizeof(unsigned long long) * num);   //checked safe
	YUVRawDataI420* filled_data = yuv_data_converter->ConvertToYUVViaExternalBuffer(buf_ptr + sizeof(VideoRawDataHeader) + sizeof(unsigned long long) * num, dataBufferLen);
	if (filled_data)
	{
		//fill header
		VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
		head_ptr->common_header.type = type;
		head_ptr->recv_handle_len = num;
		head_ptr->dataBufferLen = filled_data->GetBufferLen();
		head_ptr->isLimitedI420 = filled_data->IsLimitedI420() ? 1 : 0;
		head_ptr->width = filled_data->GetStreamWidth();
		head_ptr->height = filled_data->GetStreamHeight();
		head_ptr->rotation = filled_data->GetRotation();
		head_ptr->y_offset = (unsigned long long)filled_data->GetYBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->u_offset = (unsigned long long)filled_data->GetUBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->v_offset = (unsigned long long)filled_data->GetVBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->source_id = filled_data->GetSourceID();
	
		filled_data->Release();
	}
	return rawdata_msg;
}
UVIPCMessage* MakeUVIPCMsg(YUVProcessDataI420* data_, std::set<unsigned long long>& recv_handle, unsigned int type)
{
	if (NULL == data_)
		return NULL;

	IYUVRawDataI420Converter* yuv_data_converter = dynamic_cast<IYUVRawDataI420Converter*>(data_);
	if (NULL == yuv_data_converter)
		return NULL;
	unsigned int dataBufferLen = (data_->GetWidth()*data_->GetHeight() * 3) / 2;

	int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + sizeof(unsigned long long) * recv_handle.size() + dataBufferLen;//head+recv_list+buffer
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;
	char* buf_ptr = rawdata_msg->GetBuf();
	if (NULL == buf_ptr)
	{
		rawdata_msg->Release();
		return NULL;
	}
	unsigned long long* recv_list = (unsigned long long*)(buf_ptr + sizeof(VideoRawDataHeader));
	std::set<unsigned long long>::iterator iter = recv_handle.begin();
	int index = 0;
	while (recv_handle.end() != iter)
	{
		recv_list[index] = *iter;
		index++;
		iter++;
	}
	YUVRawDataI420* filled_data = yuv_data_converter->ConvertToYUVViaExternalBuffer(buf_ptr + sizeof(VideoRawDataHeader) + sizeof(unsigned long long) * recv_handle.size(), dataBufferLen);
	if (filled_data)
	{
		//fill header
		VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
		head_ptr->common_header.type = type;
		head_ptr->recv_handle_len = recv_handle.size();
		head_ptr->dataBufferLen = filled_data->GetBufferLen();
		head_ptr->isLimitedI420 = filled_data->IsLimitedI420() ? 1 : 0;
		head_ptr->width = filled_data->GetStreamWidth();
		head_ptr->height = filled_data->GetStreamHeight();
		head_ptr->rotation = filled_data->GetRotation();
		head_ptr->y_offset = (unsigned long long)filled_data->GetYBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->u_offset = (unsigned long long)filled_data->GetUBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->v_offset = (unsigned long long)filled_data->GetVBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->source_id = filled_data->GetSourceID();

		filled_data->Release();
	}
	return rawdata_msg;
}

UVIPCMessage* MakeUVIPCMsg(AudioRawData* data_, AudioRawDataType audio_rawdata_type, std::string user_id, unsigned int type)
{
	if (NULL == data_)
		return NULL;

	unsigned int dataBufferLen = data_->GetBufferLen();
	unsigned int sampleRate = data_->GetSampleRate();
	unsigned int channelNum = data_->GetChannelNum();

	int ipc_msg_buffer_len = sizeof(AudioRawDataHeader) + dataBufferLen;
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;

	char* buf_ptr = rawdata_msg->GetBuf();
	if (NULL == buf_ptr)
	{
		rawdata_msg->Release();
		return NULL;
	}
	//fill header
	AudioRawDataHeader* head_ptr = (AudioRawDataHeader*)buf_ptr;
	head_ptr->common_header.type = type;
	head_ptr->userid = user_id;
	head_ptr->dataBufferLen = dataBufferLen;
	head_ptr->sampleRate = sampleRate;
	head_ptr->channelNum = channelNum;
	head_ptr->type = audio_rawdata_type;
	//fill buffer
	char* data_buf = buf_ptr + sizeof(AudioRawDataHeader);
	memcpy(data_buf, data_->GetBuffer(), dataBufferLen);    //checked safe
	return rawdata_msg;
}

