#ifndef _ZOOM_NODE_VIDEO_SDK_ANNOTATION_HELPER_H_
#define _ZOOM_NODE_VIDEO_SDK_ANNOTATION_HELPER_H_
#include "zoom_video_sdk_node_common_include.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_singleton_wrap_class.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomVideoNodeAnnotationHelperWrap :
	public ZoomWrapObject<ZoomVideoNodeAnnotationHelperWrap >
{
	friend class ZoomWrapObject<ZoomVideoNodeAnnotationHelperWrap >;
private:
	ZoomVideoNodeAnnotationHelperWrap();
	~ZoomVideoNodeAnnotationHelperWrap();
public:
	static void CanDoAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetToolType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetToolType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetToolColor(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetToolColor(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetToolWidth(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetToolWidth(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Clear(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Undo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Redo(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<> inline
void InitClassAttribute<ZoomVideoNodeAnnotationHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomVideoNodeAnnotationHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanDoAnnotation", ZoomVideoNodeAnnotationHelperWrap::CanDoAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAnnotation", ZoomVideoNodeAnnotationHelperWrap::StartAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAnnotation", ZoomVideoNodeAnnotationHelperWrap::StopAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetToolType", ZoomVideoNodeAnnotationHelperWrap::SetToolType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetToolType", ZoomVideoNodeAnnotationHelperWrap::GetToolType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetToolColor", ZoomVideoNodeAnnotationHelperWrap::SetToolColor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetToolColor", ZoomVideoNodeAnnotationHelperWrap::GetToolColor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetToolWidth", ZoomVideoNodeAnnotationHelperWrap::SetToolWidth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetToolWidth", ZoomVideoNodeAnnotationHelperWrap::GetToolWidth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Clear", ZoomVideoNodeAnnotationHelperWrap::Clear);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Undo", ZoomVideoNodeAnnotationHelperWrap::Undo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Redo", ZoomVideoNodeAnnotationHelperWrap::Redo);
}
template<> inline
v8::Persistent<v8::Function>* GetConstructor<ZoomVideoNodeAnnotationHelperWrap >() {
	return &ZoomVideoNodeAnnotationHelperWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
