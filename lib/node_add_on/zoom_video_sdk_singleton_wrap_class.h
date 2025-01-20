#ifndef _zoom_video_sdk_singleton_wrap_class_h_
#define _zoom_video_sdk_singleton_wrap_class_h_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_napi_util_exporter.h"
template<class T>
static void InitClassAttribute(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{}

template<class T>
static v8::Persistent<v8::Function>* GetConstructor(){
	return NULL;
}

template<class T>
class ZoomWrapObject : public node::ObjectWrap
{
public:
	static void Init(v8::Isolate* isolate)
	{
		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
		InitClassAttribute<T >(tpl, isolate);
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		(*GetConstructor<T >()).Reset(isolate, tpl->GetFunction(context).ToLocalChecked());
	}
	static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		const unsigned argc = 1;
		v8::Local<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> instance =
			cons->NewInstance(context, argc, argv).ToLocalChecked();

		args.GetReturnValue().Set(instance);
	}

	static void New(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();

		if (args.IsConstructCall()) {
			T* obj = new T();
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		}
		else {
			const int argc = 1;
			v8::Local<v8::Value> argv[argc] = { args[0] };
			v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
			v8::Local<v8::Object> instance =
				cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(instance);
		}
	}
	
	static v8::Local<v8::Object> GetNewInstance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		const unsigned argc = 1;
		v8::Local<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> instance =
			cons->NewInstance(context, argc, argv).ToLocalChecked();
		return instance;
	}
	
protected:
	ZoomWrapObject() {};
	~ZoomWrapObject() {};
};

class ZoomNodeVideoSinkHelper
{
public:

	v8::Persistent<v8::Function> onNodeAddonCallbacks;

	static ZoomNodeVideoSinkHelper& GetInst()
	{
		static ZoomNodeVideoSinkHelper inst;
		return inst;
	}
	void Reset()
	{
		onNodeAddonCallbacks.Reset();
	}
	~ZoomNodeVideoSinkHelper() {}
private:
	ZoomNodeVideoSinkHelper() {}
};
///////////////////////////////////////////////////////////////////////////////

template<class T>
static bool SetProtoParam(const v8::FunctionCallbackInfo<v8::Value>& args, T& proto_param) {

	v8::Isolate* isolate_temp = args.GetIsolate();

	if (args.Length() < 1 ||
		!args[0]->IsUint8Array()
		)
	{
		isolate_temp->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate_temp, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return false;
	}
	v8::Local<v8::Uint8Array> uint8array_temp_param = args[0].As<v8::Uint8Array>();

	size_t sz_temp_param = 0;
	char* char_temp_param = nullptr;
	fnGetRawBufferPtr pGetRawBufferPtr = NULL;
	pGetRawBufferPtr = ZoomNodeAPIUtilHelper::GetInst().m_fnGetRawBufferPtr;
	if (!pGetRawBufferPtr)
	{
		return false;
	}
	pGetRawBufferPtr(uint8array_temp_param, (void**)(&char_temp_param), sz_temp_param);

	if (!char_temp_param)
	{
		isolate_temp->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate_temp, "V8 internal error", v8::NewStringType::kInternalized).ToLocalChecked()));
		return false;
	}

	if (!proto_param.ParseFromArray(char_temp_param, sz_temp_param))
	{
		isolate_temp->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate_temp, "Protobuf internal error", v8::NewStringType::kInternalized).ToLocalChecked()));
		return false;
	}
	return true;
}
#endif 
