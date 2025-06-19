#include "zoom_video_sdk_node_annotation_helper.h"

ZoomVideoNodeAnnotationHelperWrap::ZoomVideoNodeAnnotationHelperWrap()
{

}

ZoomVideoNodeAnnotationHelperWrap::~ZoomVideoNodeAnnotationHelperWrap()
{

}
void ZoomVideoNodeAnnotationHelperWrap::CanDoAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bCan = _g_native_wrap.GetAnnotationHelperWrap().CanDoAnnotation();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bCan);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().StartAnnotation();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().StopAnnotation();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::SetToolType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetToolTypeParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetToolTypeParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_tooltype())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int temp = (int)proto_param.tooltype();
		ZNZoomVideoSDKAnnotationToolType zn_tooltype = (ZNZoomVideoSDKAnnotationToolType)temp;

		err = _g_native_wrap.GetAnnotationHelperWrap().SetToolType(zn_tooltype);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::GetToolType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNZoomVideoSDKAnnotationToolType zn_tooltype;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().GetToolType(zn_tooltype);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "annotationToolType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_tooltype));

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAnnotationHelperWrap::SetToolColor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetToolColorParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetToolColorParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_toolcolor())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		unsigned long zn_toolcolor = (unsigned long long)proto_param.toolcolor();

		err = _g_native_wrap.GetAnnotationHelperWrap().SetToolColor(zn_toolcolor);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::GetToolColor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	unsigned long zn_toolcolor;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().GetToolColor(zn_toolcolor);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "annotationToolColor", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int64_t)zn_toolcolor));

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAnnotationHelperWrap::SetToolWidth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::SetToolWidthParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::SetToolWidthParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_toolwidth())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}
		long zn_toolwidth = (long)proto_param.toolwidth();
		err = _g_native_wrap.GetAnnotationHelperWrap().SetToolWidth(zn_toolwidth);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::GetToolWidth(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	long zn_toolwidth;
	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().GetToolWidth(zn_toolwidth);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "annotationToolWidth", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int64_t)zn_toolwidth));

	args.GetReturnValue().Set(node);
}
void ZoomVideoNodeAnnotationHelperWrap::Clear(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Success;
	do
	{
		com::electron::zoomvideo::sdk::proto::ClearAnnotationParams proto_param;
		if (!SetProtoParam<com::electron::zoomvideo::sdk::proto::ClearAnnotationParams >(args, proto_param))
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		if (!proto_param.has_cleartype())
		{
			err = ZNZoomVideoSDKErrors_Invalid_Parameter;
			break;
		}

		int temp = (int)proto_param.cleartype();
		ZNZoomVideoSDKAnnotationClearType zn_cleartype = (ZNZoomVideoSDKAnnotationClearType)temp;

		err = _g_native_wrap.GetAnnotationHelperWrap().Clear(zn_cleartype);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::Undo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().Undo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomVideoNodeAnnotationHelperWrap::Redo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	ZNZoomVideoSDKErrors err = _g_native_wrap.GetAnnotationHelperWrap().Redo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
