#include "zoom_video_sdk_node_rawdata_helper_mgr_class.h"
#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_events_wrap_class.h"
#include <algorithm>
#if (defined __linux)
#include <link.h>
#endif
extern ZoomVideoNodePipeServerMgr _g_audio_pipe_server;

#define SELF_MODULE_NAME "zoomvideosdk.node"
#if (defined __linux)
static int find_self_module_path_callback(struct dl_phdr_info *info, size_t size, void *data)
{
	if (info && info->dlpi_name && data)
	{
		const char* name = info->dlpi_name;
		const char *p = strrchr(name, '/');
        if (nullptr == p)
            return 0;
            
        const char* name_ptr = p + 1;
        if (name_ptr == strstr(name_ptr, SELF_MODULE_NAME))
        {
			std::string* str_name = (std::string*)data;
			(*str_name).append(name, (size_t)(name_ptr - name));
        }
	}
	return 0;
}
#endif

#ifdef WIN32
#else
#include <dlfcn.h>
#endif
void dummyproc()
{
	int i = 0;
	int j = 100 / i;
	printf("%d", j);
}
#ifdef _WIN32
typedef BOOL(WINAPI *fnSetDllDirectoryW)(
	_In_opt_ const wchar_t* lpPathName
	);
#endif
void ZNativeVideoSDKWrap::Reset()
{
	m_bInit = false;
	m_fnCreateZoomVideoSDKObj = NULL;
	m_fnDestroyZoomVideoSDKObj = NULL;
	m_pSink = NULL;
	m_pVideoSDK = NULL;
}
bool ZNativeVideoSDKWrap::IsValidUser(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser)
{
	bool bRet = false;
	do
	{
		if (!m_pVideoSDK || !pUser)
		{
			break;
		}
		ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = m_pVideoSDK->getSessionInfo();
		if (!pSessionInfo)
		{
			break;
		}
		bRet = pSessionInfo->IsValidUser(pUser);
	} while (false);
	return bRet;
}
bool ZNativeVideoSDKWrap::ConfigSDKModule(ZoomSTRING& path)
{
	void* video_sdk_so = NULL;

	do
	{
		if (m_bInit)
		{
			break;
		}
#if (defined WIN32)
		fnSetDllDirectoryW pfnSetDllDirectory = (fnSetDllDirectoryW)GetProcAddress(GetModuleHandleA("kernel32.dll"), "SetDllDirectoryW");
		if (NULL == pfnSetDllDirectory)
		{
			pfnSetDllDirectory = (fnSetDllDirectoryW)GetProcAddress(GetModuleHandleA("kernelbase.dll"), "SetDllDirectoryW");
		}
		std::wstring strTmp(path);
		if (strTmp.empty())
		{
			strTmp.resize(MAX_PATH);
			HMODULE hSelfMod(NULL);
			GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)dummyproc, &hSelfMod);
			GetModuleFileNameW(hSelfMod, const_cast<wchar_t*>(strTmp.c_str()), MAX_PATH);
			FreeLibrary(hSelfMod);
			strTmp.resize(strTmp.size());
			// 			std::wstring::size_type pos = strTmp.find(L"\\\\?\\");
			// 			if (0 == pos)
			// 			{
			// 				strTmp.erase(pos, 4);
			// 			}
		}

		wchar_t drive[_MAX_DRIVE];
		wchar_t dir[_MAX_DIR];
		wchar_t fname[_MAX_FNAME];
		wchar_t ext[_MAX_EXT];
		_wsplitpath_s(strTmp.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

		wchar_t szPath[MAX_PATH] = { 0 };
		_wmakepath_s(szPath, _MAX_PATH, drive, dir, NULL, NULL);
		if (pfnSetDllDirectory)
			pfnSetDllDirectory(szPath);

		wcscat_s(szPath, MAX_PATH, L"videosdk.dll");
		video_sdk_so = (void*)LoadLibraryW(szPath);
		if (NULL == video_sdk_so)
		{
			break;
		}

		m_fnCreateZoomVideoSDKObj = (fnCreateZoomVideoSDKObj)GetProcAddress((HMODULE)video_sdk_so, "CreateZoomVideoSDKObj");
		m_fnDestroyZoomVideoSDKObj = (fnDestroyZoomVideoSDKObj)GetProcAddress((HMODULE)video_sdk_so, "DestroyZoomVideoSDKObj");
#else
#if (defined __linux)
#define video_sdk_core "libvideosdk.so" 
#else
#define mac_video_sdk "VideoSDK.dylib" 
#endif

#define func_CreateZoomVideoSDK "CreateZoomVideoSDKObj"
#define func_DestroyZoomVideoSDK "DestroyZoomVideoSDKObj"
#if (defined __linux)
		std::string video_sdk_core_path;
		dl_iterate_phdr(find_self_module_path_callback, &video_sdk_core_path);
		video_sdk_core_path.append(video_sdk_core);
		void* video_sdk_so = dlopen(video_sdk_core_path.c_str(), RTLD_LAZY);
		if (!video_sdk_so)
			break;
	
		m_fnCreateZoomVideoSDKObj = (fnCreateZoomVideoSDKObj)dlsym(video_sdk_so, func_CreateZoomVideoSDK);
		m_fnDestroyZoomVideoSDKObj = (fnDestroyZoomVideoSDKObj)dlsym(video_sdk_so, func_DestroyZoomVideoSDK);
#else
		void* video_sdk_so = dlopen(mac_video_sdk, RTLD_LAZY);
		if (!video_sdk_so)
			break;
		char buf[128];
		size_t len = strlcpy(buf, func_CreateZoomVideoSDK, sizeof(buf));
		m_fnCreateZoomVideoSDKObj = (fnCreateZoomVideoSDKObj)dlsym(video_sdk_so, buf);
		len = strlcpy(buf, func_DestroyZoomVideoSDK, sizeof(buf));
		m_fnDestroyZoomVideoSDKObj = (fnDestroyZoomVideoSDKObj)dlsym(video_sdk_so, buf);
#endif
#endif

		if (NULL == m_fnCreateZoomVideoSDKObj
			|| NULL == m_fnDestroyZoomVideoSDKObj)
		{
			break;
		}
		m_bInit = true;
	} while (false);

	if (!m_bInit)
	{
		if (video_sdk_so)
		{
#if (defined WIN32) 
			FreeLibrary((HMODULE)video_sdk_so);
#else
			dlclose(video_sdk_so);
#endif
			Reset();
		}
	}

	return m_bInit;

}

ZNativeVideoSDKInternalMagicCallback g_global_rawdata_callback;
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::CreateZoomVideoSDKObj(ZoomSTRING path)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Load_Module_Error;
#ifdef WIN32
	ZoomSTRING sdkpath = path.size() ? path : L"";
	sdkpath = L"";
#else
    ZoomSTRING sdkpath = path.size() ? path : "";
    sdkpath = "";
#endif
	if (!ConfigSDKModule(sdkpath))
	{
		return err;
	}
	if (!m_fnCreateZoomVideoSDKObj)
	{
		return err;
	}
	m_pVideoSDK = m_fnCreateZoomVideoSDKObj();
	if (!m_pVideoSDK)
	{
		return err;
	}
	err = ZNZoomVideoSDKErrors_Success;
	
	return err;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::DestroyZoomVideoSDKObj()
{
	if (!m_fnDestroyZoomVideoSDKObj)
	{
		return ZNZoomVideoSDKErrors_UnLoad_Module_Error;
	}
	m_fnDestroyZoomVideoSDKObj();
	m_pVideoSDK = NULL;
	return ZNZoomVideoSDKErrors_Success;
}

ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::Initialize(ZNZoomVideoSDKInitParams& initParam)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	if (!m_pVideoSDK)
	{
		return ZNZoomVideoSDKErrors_Load_Module_Error;
	}
	
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKInitParams params;
	params.domain = initParam.domain.c_str();
	params.logFilePrefix = initParam.logFilePrefix.c_str();
	params.enableLog = initParam.enableLog;
	params.enableIndirectRawdata = true;
	params.audioRawDataMemoryMode = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataMemoryMode)initParam.audioRawDataMemoryMode;
	params.shareRawDataMemoryMode = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataMemoryMode)initParam.shareRawDataMemoryMode;
	params.videoRawDataMemoryMode = (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKRawDataMemoryMode)initParam.videoRawDataMemoryMode;
	params.extendParam.speakerTestFilePath = initParam.extendParam.speakerTestFilePath.c_str();
	params.extendParam.wrapperType = initParam.extendParam.wrapperType;
	ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors ret = ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Unknown;
	ret = m_pVideoSDK->initialize(params);
	if (ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKErrors_Success == ret)
	{
		m_pVideoSDK->addListener(&VideoSDKEventWrapMgr::GetInst().m_zoomVideoSDKDelegate);
	}

	IZoomElectronHelper* helper = dynamic_cast<IZoomElectronHelper*>(m_pVideoSDK);
	if (helper)
	{
		helper->RegisterGlobalRawDataCB(&g_global_rawdata_callback);
	}

	return (ZNZoomVideoSDKErrors)ret;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::CleanUp()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	if (m_pVideoSDK)
	{
		m_pVideoSDK->removeListener(&VideoSDKEventWrapMgr::GetInst().m_zoomVideoSDKDelegate);
		err = (ZNZoomVideoSDKErrors)m_pVideoSDK->cleanup();
	}
	return err;
}
ZNativeVideoSDKWrap::ZNativeVideoSDKWrap()
{
	m_bInit = false;
	m_fnCreateZoomVideoSDKObj = NULL;
	m_fnDestroyZoomVideoSDKObj = NULL;
	m_pVideoSDK = NULL;
	m_pSink = NULL;
	VideoSDKEventWrapMgr::GetInst().m_zoomVideoSDKDelegate.SetOwner(this);
}
ZNativeVideoSDKWrap::~ZNativeVideoSDKWrap()
{
	VideoSDKEventWrapMgr::GetInst().m_zoomVideoSDKDelegate.SetOwner(NULL);
	m_pSink = NULL;
	m_pVideoSDK = NULL;
	m_bInit = false;
	m_fnCreateZoomVideoSDKObj = NULL;
	m_fnDestroyZoomVideoSDKObj = NULL;
}
void ZNativeVideoSDKWrap::SetSink(ZNativeZoomVideoSDKSinksWrap* pSink)
{
	m_pSink = pSink;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::JoinSession(ZNZoomVideoSDKSessionContext& joinParams)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Session_Join_Failed;
	ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKSession* pSessionInfo = NULL;
	if (m_pVideoSDK)
	{
		ZOOM_VIDEO_SDK_NAMESPACE::ZoomVideoSDKSessionContext sessionContex;
		sessionContex.sessionName = joinParams.sessionName.c_str();
		sessionContex.sessionPassword = joinParams.sessionPassword.c_str();
		sessionContex.token = joinParams.token.c_str();
		sessionContex.userName = joinParams.userName.c_str();
		sessionContex.videoOption.localVideoOn = joinParams.videoOption.localVideoOn;
		sessionContex.audioOption.connect = joinParams.audioOption.connect;
		sessionContex.audioOption.mute = joinParams.audioOption.mute;
		sessionContex.sessionIdleTimeoutMins = joinParams.sessionIdleTimeoutMins;
		
		pSessionInfo = m_pVideoSDK->joinSession(sessionContex);
		if (pSessionInfo)
		{
			err = ZNZoomVideoSDKErrors_Success;
		}
	}
	return err;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::LeaveSession(bool bEnd)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	if (m_pVideoSDK)
	{
		err = (ZNZoomVideoSDKErrors)m_pVideoSDK->leaveSession(bEnd);
	}
	return err;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::InputSessionPassword(ZoomSTRING passWord)
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = ZNZoomVideoSDKPasswordHandler::GetInst().InputSessionPassword(passWord);
	return err;
}
ZNZoomVideoSDKErrors ZNativeVideoSDKWrap::LeaveSessionIgnorePassword()
{
	ZNZoomVideoSDKErrors err = ZNZoomVideoSDKErrors_Internal_Error;
	err = ZNZoomVideoSDKPasswordHandler::GetInst().LeaveSessionIgnorePassword();
	return err;
}

bool ZNativeVideoSDKWrap::IsInSession()
{
	bool bIsInSession = false;
	if (m_pVideoSDK)
	{
		bIsInSession = m_pVideoSDK->isInSession();
	}
	return bIsInSession;
}
ZoomSTRING ZNativeVideoSDKWrap::GetSDKVersion()
{
	ZoomSTRING sdkVersion;
	if (m_pVideoSDK)
	{
		sdkVersion = m_pVideoSDK->getSDKVersion();
	}
	return sdkVersion;
}
ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* ZNativeVideoSDKWrap::GetVideoSDKObj()
{
	return m_pVideoSDK;
}
ZCmdChannelHelperWrap& ZNativeVideoSDKWrap::GetCmdChannelWrap()
{
	return m_CmdChannelHelper;
}
ZPhoneHelperWrap& ZNativeVideoSDKWrap::GetPhoneHelperWrap()
{
	return m_PhoneHelper;
}
ZRecordingHelperWrap& ZNativeVideoSDKWrap::GetRecordingHelperWrap()
{
	return m_RecordingHelper;
}
ZRemoteCameraControlHelperWrap& ZNativeVideoSDKWrap::GetRemoteCameraCtrlHelperWrap()
{
	return m_RemoteCameraCtrlHelper;
}
ZSessionInfoWrap& ZNativeVideoSDKWrap::GetSessionInfoWrap()
{
	return m_SessionInfoCtrl;
}
ZAudioSettingWrap& ZNativeVideoSDKWrap::GetAudioSettingWrap()
{
	return m_AudioSetting;
}
ZTestAudioDeviceWrap& ZNativeVideoSDKWrap::GetTestAudioDeviceWrap()
{
	return m_TestAudioDevice;
}
ZAudioHelperWrap& ZNativeVideoSDKWrap::GetAudioHelperWrap()
{
	return m_AudioHelper;
}
ZVideoHelperWrap& ZNativeVideoSDKWrap::GetVideoHelperWrap()
{
	return m_VideoHelper;
}
ZShareHelperWrap& ZNativeVideoSDKWrap::GetShareHelperWrap()
{
	return m_ShareHelper;
}
ZShareInfoHelperWrap& ZNativeVideoSDKWrap::GetShareInfoHelperWrap()
{
	return m_ShareInfoHelper;
}
ZUserHelperWrap& ZNativeVideoSDKWrap::GetUserHelperWrap()
{
	return m_UserHelper;
}
ZChatHelperWrap& ZNativeVideoSDKWrap::GetChatHelperWrap()
{
	return m_ChatHelper;
}
ZLiveStreamHelperWrap& ZNativeVideoSDKWrap::GetLiveStreamHelperWrap()
{
	return m_LiveStreamHelper;
}
ZIncomingLiveStreamHelperWrap& ZNativeVideoSDKWrap::GetIncomingLiveStreamHelperWrap()
{
	return m_IncomingLiveStreamHelper;
}
ZLiveTranscriptionHelperWrap& ZNativeVideoSDKWrap::GetLiveTranscriptionHelperWrap()
{
	return m_LTTHelper;
}
ZShareSettingWrap& ZNativeVideoSDKWrap::GetShareSettingWrap()
{
	return m_ShareSetting;
}
//ZNativeVideoSDKVideoSource& ZNativeVideoSDKWrap::GetVideoSourceWrap()
//{
//	return m_ExternalVideoSource;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ZNativeVideoSDKWrap::onSessionJoin()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onSessionJoin);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onSessionLeave(ZNZoomVideoSDKSessionLeaveReason eReason)
{
	ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().Clear();
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onSessionLeaveParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onSessionLeaveParams;
		callBackBody_temp_param->set_ereason((int)eReason);
		
		callBackBody.set_allocated_onsessionleaveparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onSessionLeave);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}

void ZNativeVideoSDKWrap::onError(ZNZoomVideoSDKErrors errorCode, int detailErrorCode)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onErrorParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onErrorParams;
		callBackBody_temp_param->set_detailerrorcode(detailErrorCode);
		callBackBody_temp_param->set_errorcode(errorCode);
		callBackBody.set_allocated_onerrorparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onError);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUserJoin(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do 
	{
		if (!m_pSink || !userList)
		{
			return;
		}
		if (0 == userList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserJoinParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserJoinParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		for (int i = 0; i < userList->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
			if (!pUserTemp || !callBackBody_VideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);

		callBackBody.set_allocated_onuserjoinparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserJoin);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onUserLeave(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do
	{
		if (!m_pSink || !userList)
		{
			return;
		}
		if (0 == userList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserLeaveParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserLeaveParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		for (int i = 0; i < userList->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
			if (!pUserTemp || !callBackBody_VideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
			//erase the user from multi camera stream map
			int64_t temp_user = (int64_t)pUserTemp;
			std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find(temp_user);
			if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() != iter_user)
			{
				ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.erase(temp_user);
			}
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);

		callBackBody.set_allocated_onuserleaveparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserLeave);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onUserVideoStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do
	{
		if (!m_pSink || !userList)
		{
			return;
		}
		if (0 == userList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserVideoStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserVideoStatusChangedParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		for (int i = 0; i < userList->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
			if (!pUserTemp || !callBackBody_VideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);

		callBackBody.set_allocated_onuservideostatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserVideoStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
	
}
void ZNativeVideoSDKWrap::onUserAudioStatusChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do
	{
		if (!m_pSink || !userList)
		{
			return;
		}
		if (0 == userList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserAudioStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserAudioStatusChangedParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		for (int i = 0; i < userList->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
			if (!pUserTemp || !callBackBody_VideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);
	
		callBackBody.set_allocated_onuseraudiostatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserAudioStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onUserShareStatusChanged(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserShareStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserShareStatusChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		com::electron::zoomvideo::sdk::proto::ShareAction* callBackBody_ShareAction = new com::electron::zoomvideo::sdk::proto::ShareAction;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, callBackBody_ShareAction);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_shareaction(callBackBody_ShareAction);
		callBackBody.set_allocated_onusersharestatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserShareStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onFailedToStartShare(IZoomVideoSDKUser* pUser)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onFailedToStartShareParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onFailedToStartShareParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody.set_allocated_onfailedtostartshareparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onFailedToStartShare);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCameraListChanged()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onCameraListChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onLiveStreamStatusChanged(ZNZoomVideoSDKLiveStreamStatus status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveStreamStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveStreamStatusChangedParams;
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_onlivestreamstatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onLiveStreamStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUserHostChanged(IZoomVideoSDKUser* pUser)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserHostChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserHostChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody.set_allocated_onuserhostchangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserHostChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUserManagerChanged(IZoomVideoSDKUser* pUser)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserManagerChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserManagerChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody.set_allocated_onusermanagerchangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserManagerChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUserNameChanged(IZoomVideoSDKUser* pUser)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserNameChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserNameChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody.set_allocated_onusernamechangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserNameChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUserActiveAudioChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do
	{
		if (!m_pSink || !userList)
		{
			return;
		}
		if (0 == userList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUserActiveAudioChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUserActiveAudioChangedParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		for (int i = 0; i < userList->GetCount(); ++i)
		{
			IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
			if (!pUserTemp || !callBackBody_VideoSDKUser)
			{
				continue;
			}
			ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);

		callBackBody.set_allocated_onuseractiveaudiochangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUserActiveAudioChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onChatNewMessageNotify(ZNZoomVideoSDKChatMessageInfo messageInfo)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onChatNewMessageNotifyParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onChatNewMessageNotifyParams;
		
		
		callBackBody_temp_param->set_psender(messageInfo.pSender);
		callBackBody_temp_param->set_sendername(ws2s(messageInfo.senderName).c_str());
		callBackBody_temp_param->set_preceiver(messageInfo.pReceiver);
		callBackBody_temp_param->set_receivername(ws2s(messageInfo.receiverName).c_str());
		callBackBody_temp_param->set_messagecontent(ws2s(messageInfo.messageContent).c_str());
		callBackBody_temp_param->set_timestamp(messageInfo.timeStamp);
		callBackBody_temp_param->set_ischattoall(messageInfo.isChatToAll);
		callBackBody_temp_param->set_isselfsend(messageInfo.isSelfSend);
		callBackBody_temp_param->set_messageid(ws2s(messageInfo.messageID).c_str());

		callBackBody.set_allocated_onchatnewmessagenotifyparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onChatNewMessageNotify);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onChatMsgDeleteNotification(ZoomSTRING msgID, ZNZoomVideoSDKChatMessageDeleteType deleteBy)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onChatMsgDeleteNotificationParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onChatMsgDeleteNotificationParams;

		callBackBody_temp_param->set_messageid(ws2s(msgID).c_str());
		callBackBody_temp_param->set_deleteby((int)deleteBy);

		callBackBody.set_allocated_onchatmsgdeletenotificationparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onChatMsgDeleteNotification);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCommandReceived(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pSender, ZoomSTRING strCmd)
{
	if (m_pSink && pSender)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCommandReceivedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCommandReceivedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pSender, callBackBody_VideoSDKUser);

		callBackBody_temp_param->set_strcmd(ws2s(strCmd).c_str());

		callBackBody_temp_param->set_allocated_psender(callBackBody_VideoSDKUser);
		callBackBody.set_allocated_oncommandreceivedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCommandReceived);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCommandChannelConnectResult(bool isSuccess)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCommandChannelConnectResultParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCommandChannelConnectResultParams;
		callBackBody_temp_param->set_issuccess(isSuccess);

		callBackBody.set_allocated_oncommandchannelconnectresultparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCommandChannelConnectResult);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onHostAskUnmute()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onHostAskUnmute);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onInviteByPhoneStatus(ZNPhoneStatus status, ZNPhoneFailedReason reason)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onInviteByPhoneStatusParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onInviteByPhoneStatusParams;
		callBackBody_temp_param->set_status((int)status);
		callBackBody_temp_param->set_reason((int)reason);

		callBackBody.set_allocated_oninvitebyphonestatusparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onInviteByPhoneStatus);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onMultiCameraStreamStatusChanged(ZNZoomVideoSDKMultiStreamStatus status, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKRawDataPipe* pVideoPipe)
{
	if (m_pSink)
	{
		int64_t temp_user = (int64_t)pUser;
		int64_t temp_pipe = (int64_t)pVideoPipe;
		int32_t camera_stream_id = 1;
		switch (status)
		{
		case ZNZoomVideoSDKMultiCameraStreamStatus_Joined:
		{
			bool need_add = true;
			std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find(temp_user);
			if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() != iter_user)
			{
				std::map<int32_t, int64_t >::iterator iter_camerastreamid;
				//check if this pipe is already in map
				for(iter_camerastreamid = iter_user->second.begin(); iter_camerastreamid != iter_user->second.end(); iter_camerastreamid++)
				{
					if (iter_camerastreamid->second == temp_pipe)
					{
						need_add = false;
						break;
					}
				}

				if (need_add)
				{
					//get and sort key vectror
					std::vector<int32_t> vec_camerid_existed;
					for (iter_camerastreamid = iter_user->second.begin(); iter_camerastreamid != iter_user->second.end(); iter_camerastreamid++)
					{
						vec_camerid_existed.push_back(iter_camerastreamid->first);
					}
					std::sort(vec_camerid_existed.begin(), vec_camerid_existed.end());

					int i = 0;
					int32_t new_key = 0;
					while (i < vec_camerid_existed.size())
					{
						if (vec_camerid_existed[i] != i + 1)
						{
							break;
						}
						i++;
					}
					new_key = i + 1;
					
					iter_user->second.insert(std::make_pair(new_key, temp_pipe));
					camera_stream_id = new_key;
				}
			}
			else
			{
				std::map<int32_t, int64_t > new_camera_pipe_map;
				new_camera_pipe_map.insert(std::make_pair(1, temp_pipe));
				ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.insert(std::make_pair(temp_user, new_camera_pipe_map));
				camera_stream_id = 1;
			}
		}
		break;
		case ZNZoomVideoSDKMultiCameraStreamStatus_Left:
		{
			std::map<int64_t, std::map<int32_t, int64_t > >::iterator iter_user = ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.find(temp_user);
			if (ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.end() != iter_user)
			{
				bool need_erase_user = false;
				if (pUser && pUser->getMultiCameraStreamList() && pUser->getMultiCameraStreamList()->GetCount() == 1) //should erase this user from user-camera map
				{
					need_erase_user = true;
				}
				std::map<int32_t, int64_t >::iterator iter_camerastreamid;
				for (iter_camerastreamid = iter_user->second.begin(); iter_camerastreamid != iter_user->second.end(); iter_camerastreamid++)
				{
					if (iter_camerastreamid->second == temp_pipe)
					{
						camera_stream_id = iter_camerastreamid->first;
						iter_user->second.erase(iter_camerastreamid);
						if (need_erase_user)
						{
							ZoomVideoNodeMultiCameraStreamHelperMgr::GetInst().m_multicamerastreamhelper_map.erase(temp_user);
						}
						break;
					}
				}
			}
		}
		break;
		default:
			break;
		}

		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onMultiCameraStreamStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onMultiCameraStreamStatusChangedParams;
		callBackBody_temp_param->set_status((int)status);
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		if (pVideoPipe)
		{
			callBackBody_temp_param->set_camerastreamid(camera_stream_id);
		}

		callBackBody.set_allocated_onmulticamerastreamstatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onMultiCameraStreamStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onMicSpeakerVolumeChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onMicSpeakerVolumeChangedParams;
		callBackBody_temp_param->set_micvolume(micVolume);
		callBackBody_temp_param->set_speakervolume(speakerVolume);

		callBackBody.set_allocated_onmicspeakervolumechangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onMicSpeakerVolumeChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onAudioDeviceStatusChanged(ZNZoomVideoSDKAudioDeviceType type, ZNZoomVideoSDKAudioDeviceStatus status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onAudioDeviceStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onAudioDeviceStatusChangedParams;
		callBackBody_temp_param->set_type((int)type);
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_onaudiodevicestatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onAudioDeviceStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onTestMicStatusChanged(ZNZoomVideoSDK_TESTMIC_STATUS status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onTestMicStatusChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onTestMicStatusChangedParams;
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_ontestmicstatuschangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onTestMicStatusChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onSelectedAudioDeviceChanged()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onSelectedAudioDeviceChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCloudRecordingStatus(ZNRecordingStatus status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCloudRecordingStatusParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCloudRecordingStatusParams;
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_oncloudrecordingstatusparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCloudRecordingStatus);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCameraControlRequestResult(IZoomVideoSDKUser* pUser, bool isApproved)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCameraControlRequestResultParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCameraControlRequestResultParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_puser(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_isapproved(isApproved);

		callBackBody.set_allocated_oncameracontrolrequestresultparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCameraControlRequestResult);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCameraControlRequestReceived(IZoomVideoSDKUser* pUser, ZNZoomVideoSDKCameraControlRequestType requestType)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCameraControlRequestReceivedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCameraControlRequestReceivedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_puser(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_requesttype((int)requestType);

		callBackBody.set_allocated_oncameracontrolrequestreceivedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCameraControlRequestReceived);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onSessionNeedPassword()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onSessionNeedPassword);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onSessionPasswordWrong()
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		callBackBody.set_msgtype(CallMessageType_onSessionPasswordWrong);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onMixedAudioRawDataReceived(AudioRawData* data_)
{
	if (_g_audio_pipe_server._uv_ipc_server.HasClientConnected() && data_)
	{
		bool isMixed = true;
		std::string userid = "Mixed";
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, AudioRawDataType_Mixed, userid, TYPE_AUDIO);
		if (rawdata_msg)
			_g_audio_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}
void ZNativeVideoSDKWrap::onOneWayAudioRawDataReceived(AudioRawData* data_, IZoomVideoSDKUser* pUser)
{
	if (_g_audio_pipe_server._uv_ipc_server.HasClientConnected() && data_ && pUser)
	{
		bool isMixed = false;
		ZoomSTRING userid = pUser->getCustomIdentity();
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, AudioRawDataType_OneWay, zs2s(userid), TYPE_AUDIO);
		if (rawdata_msg)
			_g_audio_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}
void ZNativeVideoSDKWrap::onSharedAudioRawDataReceived(AudioRawData* data_)
{
	if (_g_audio_pipe_server._uv_ipc_server.HasClientConnected() && data_)
	{
		bool isMixed = true;
		std::string userid = "Shared";
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, AudioRawDataType_Shared, userid, TYPE_AUDIO);
		if (rawdata_msg)
			_g_audio_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}

void ZNativeVideoSDKWrap::onLiveTranscriptionStatus(ZNZoomVideoSDKLiveTranscriptionStatus status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveTranscriptionStatusParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveTranscriptionStatusParams;
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_onlivetranscriptionstatusparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onLiveTranscriptionStatus);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onLiveTranscriptionMsgError(ILiveTranscriptionLanguage* spokenLanguage, ILiveTranscriptionLanguage* transcriptLanguage)
{
	if (m_pSink && spokenLanguage && transcriptLanguage)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveTranscriptionMsgErrorParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onLiveTranscriptionMsgErrorParams;
		com::electron::zoomvideo::sdk::proto::LTTLanguage* zn_spokenLanguage = new com::electron::zoomvideo::sdk::proto::LTTLanguage;
		com::electron::zoomvideo::sdk::proto::LTTLanguage* zn_transcriptLanguage = new com::electron::zoomvideo::sdk::proto::LTTLanguage;
		if (zn_transcriptLanguage && zn_spokenLanguage)
		{
			zn_spokenLanguage->set_lttlanguagename(zs2s(spokenLanguage->getLTTLanguageName()).c_str());
			zn_spokenLanguage->set_lttlanguageid(spokenLanguage->getLTTLanguageID());
			zn_transcriptLanguage->set_lttlanguagename(zs2s(transcriptLanguage->getLTTLanguageName()).c_str());
			zn_transcriptLanguage->set_lttlanguageid(transcriptLanguage->getLTTLanguageID());
		}
		callBackBody_temp_param->set_allocated_spokenlanguage(zn_spokenLanguage);
		callBackBody_temp_param->set_allocated_transcriptlanguage(zn_transcriptLanguage);

		callBackBody.set_allocated_onlivetranscriptionmsgerrorparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onLiveTranscriptionMsgError);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}

void ZNativeVideoSDKWrap::onLiveTranscriptionMsgInfoReceived(ZNLiveTranscriptionMessageInfo messageInfo)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_liveTranscriptionMsgInfoParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_liveTranscriptionMsgInfoParams;
		if (!callBackBody_temp_param)
		{
			return;
		}

		callBackBody_temp_param->set_messageid(ws2s(messageInfo.messageID).c_str());
		callBackBody_temp_param->set_messagecontent(ws2s(messageInfo.messageContent).c_str());
		callBackBody_temp_param->set_timestamp(messageInfo.timeStamp);
		callBackBody_temp_param->set_speakerid(ws2s(messageInfo.speakerID).c_str());
		callBackBody_temp_param->set_speakername(ws2s(messageInfo.speakerName).c_str());
		callBackBody_temp_param->set_messagetype((int)messageInfo.messageType);

		callBackBody.set_allocated_livetranscriptionmsginfoparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onLiveTranscriptionMsgInfoReceived);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onOriginalLanguageMsgReceived(ZNLiveTranscriptionMessageInfo messageInfo)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_liveTranscriptionMsgInfoParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_liveTranscriptionMsgInfoParams;
		if (!callBackBody_temp_param)
		{
			return;
		}

		callBackBody_temp_param->set_messageid(ws2s(messageInfo.messageID).c_str());
		callBackBody_temp_param->set_messagecontent(ws2s(messageInfo.messageContent).c_str());
		callBackBody_temp_param->set_timestamp(messageInfo.timeStamp);
		callBackBody_temp_param->set_speakerid(ws2s(messageInfo.speakerID).c_str());
		callBackBody_temp_param->set_speakername(ws2s(messageInfo.speakerName).c_str());
		callBackBody_temp_param->set_messagetype((int)messageInfo.messageType);

		callBackBody.set_allocated_livetranscriptionmsginfoparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onOriginalLanguageMsgReceived);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onCalloutJoinSuccess(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, ZoomSTRING phoneNumber)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onCalloutJoinSuccessParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onCalloutJoinSuccessParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_phonenumber(ws2s(phoneNumber).c_str());

		callBackBody.set_allocated_oncalloutjoinsuccessparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onCalloutJoinSuccess);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onSpotlightVideoChanged(ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IZoomVideoSDKUser*>* userList)
{
	do
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onSpotlightVideoChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onSpotlightVideoChangedParams;
		com::electron::zoomvideo::sdk::proto::UserList* callBackBody_UserList = new com::electron::zoomvideo::sdk::proto::UserList;
		if (userList && userList->GetCount() > 0)
		{
			for (int i = 0; i < userList->GetCount(); ++i)
			{
				IZoomVideoSDKUser* pUserTemp = userList->GetItem(i);
				com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = callBackBody_UserList->add_user();
				if (!pUserTemp || !callBackBody_VideoSDKUser)
				{
					continue;
				}
				ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUserTemp, callBackBody_VideoSDKUser);
			}
		}
		callBackBody_temp_param->set_allocated_zn_userlist(callBackBody_UserList);

		callBackBody.set_allocated_onspotlightvideochangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onSpotlightVideoChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onBindIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onBindIncomingLiveStreamResponseParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onBindIncomingLiveStreamResponseParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);
		callBackBody_temp_param->set_strstreamkeyid(ws2s(strStreamKeyID).c_str());

		callBackBody.set_allocated_onbindincominglivestreamresponseparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onBindIncomingLiveStreamResponse);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onUnbindIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onUnbindIncomingLiveStreamResponseParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onUnbindIncomingLiveStreamResponseParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);
		callBackBody_temp_param->set_strstreamkeyid(ws2s(strStreamKeyID).c_str());

		callBackBody.set_allocated_onunbindincominglivestreamresponseparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onUnbindIncomingLiveStreamResponse);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onIncomingLiveStreamStatusResponse(bool bSuccess, ZOOM_VIDEO_SDK_NAMESPACE::IVideoSDKVector<IncomingLiveStreamStatus>* pStreamsStatusList)
{
	do
	{
		if (!m_pSink || !pStreamsStatusList)
		{
			return;
		}
		if (0 == pStreamsStatusList->GetCount())
		{
			return;
		}
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onIncomingLiveStreamStatusResponseParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onIncomingLiveStreamStatusResponseParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);
		com::electron::zoomvideo::sdk::proto::IncomingLiveStreamStatusList* callBackBody_IncomingLiveStreamStatusList = new com::electron::zoomvideo::sdk::proto::IncomingLiveStreamStatusList;
		for (int i = 0; i < pStreamsStatusList->GetCount(); ++i)
		{
			ZOOM_VIDEO_SDK_NAMESPACE::IncomingLiveStreamStatus pStatusTemp = pStreamsStatusList->GetItem(i);
			com::electron::zoomvideo::sdk::proto::IncomingLiveStreamStatus* callBackBody_IncomingLiveStreamStatus = callBackBody_IncomingLiveStreamStatusList->add_status();					
			if (!pStatusTemp.strStreamKeyID || !callBackBody_IncomingLiveStreamStatus)
			{
				continue;
			}
			ZoomSTRING temp_strStreamKeyID = pStatusTemp.strStreamKeyID;
			callBackBody_IncomingLiveStreamStatus->set_strstreamkeyid(zs2s(temp_strStreamKeyID).c_str());
			callBackBody_IncomingLiveStreamStatus->set_isrtmpconnected(pStatusTemp.isRTMPConnected);
			callBackBody_IncomingLiveStreamStatus->set_isstreampushed(pStatusTemp.isStreamPushed);
		}
		callBackBody_temp_param->set_allocated_pstreamsstatuslist(callBackBody_IncomingLiveStreamStatusList);

		callBackBody.set_allocated_onincominglivestreamstatusresponseparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onIncomingLiveStreamStatusResponse);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	} while (false);
}
void ZNativeVideoSDKWrap::onStartIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onStartIncomingLiveStreamResponseParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onStartIncomingLiveStreamResponseParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);
		callBackBody_temp_param->set_strstreamkeyid(ws2s(strStreamKeyID).c_str());

		callBackBody.set_allocated_onstartincominglivestreamresponseparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onStartIncomingLiveStreamResponse);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onStopIncomingLiveStreamResponse(bool bSuccess, ZoomSTRING strStreamKeyID)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onStopIncomingLiveStreamResponseParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onStopIncomingLiveStreamResponseParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);
		callBackBody_temp_param->set_strstreamkeyid(ws2s(strStreamKeyID).c_str());

		callBackBody.set_allocated_onstopincominglivestreamresponseparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onStopIncomingLiveStreamResponse);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onShareContentChanged(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onShareContentChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onShareContentChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		com::electron::zoomvideo::sdk::proto::ShareAction* callBackBody_ShareAction = new com::electron::zoomvideo::sdk::proto::ShareAction;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, callBackBody_ShareAction);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_shareaction(callBackBody_ShareAction);
		callBackBody.set_allocated_onsharecontentchangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onShareContentChanged);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onShareContentSizeChanged(IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
{
	if (m_pSink && pUser)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onShareContentSizeChangedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onShareContentSizeChangedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		com::electron::zoomvideo::sdk::proto::ShareAction* callBackBody_ShareAction = new com::electron::zoomvideo::sdk::proto::ShareAction;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, callBackBody_ShareAction);

		callBackBody_temp_param->set_allocated_user(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_shareaction(callBackBody_ShareAction);
		callBackBody.set_allocated_onsharecontentsizechangedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onShareContentSizeChange);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
#if (!defined __linux)
void ZNativeVideoSDKWrap::onRemoteControlStatus(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction, ZNZoomVideoSDKRemoteControlStatus status)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlStatusParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlStatusParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		com::electron::zoomvideo::sdk::proto::ShareAction* callBackBody_ShareAction = new com::electron::zoomvideo::sdk::proto::ShareAction;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, callBackBody_ShareAction);

		callBackBody_temp_param->set_allocated_puser(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_shareaction(callBackBody_ShareAction);
		callBackBody_temp_param->set_status((int)status);

		callBackBody.set_allocated_onremotecontrolstatusparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onRemoteControlStatus);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
void ZNativeVideoSDKWrap::onRemoteControlRequestReceived(ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKUser* pUser, IZoomVideoSDKShareAction* pShareAction)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlRequestReceivedParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlRequestReceivedParams;
		com::electron::zoomvideo::sdk::proto::VideoSDKUser* callBackBody_VideoSDKUser = new com::electron::zoomvideo::sdk::proto::VideoSDKUser;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKUserToProtoUser(pUser, callBackBody_VideoSDKUser);
		com::electron::zoomvideo::sdk::proto::ShareAction* callBackBody_ShareAction = new com::electron::zoomvideo::sdk::proto::ShareAction;
		ZoomVideoNodeUtilityHelper::GetInst().ConvertSDKShareActionToProtoShareAction(pShareAction, callBackBody_ShareAction);

		callBackBody_temp_param->set_allocated_puser(callBackBody_VideoSDKUser);
		callBackBody_temp_param->set_allocated_shareaction(callBackBody_ShareAction);
		
		callBackBody.set_allocated_onremotecontrolrequestreceivedparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onRemoteControlRequestReceived);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
#endif
#if (defined _WIN32)
void ZNativeVideoSDKWrap::onRemoteControlServiceInstallResult(bool bSuccess)
{
	if (m_pSink)
	{
		com::electron::zoomvideo::sdk::proto::CallbackBody callBackBody;
		com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlServiceInstallResultParams* callBackBody_temp_param = new com::electron::zoomvideo::sdk::proto::CallbackBody_onRemoteControlServiceInstallResultParams;
		callBackBody_temp_param->set_bsuccess(bSuccess);

		callBackBody.set_allocated_onremotecontrolserviceinstallresultparam(callBackBody_temp_param);
		callBackBody.set_msgtype(CallMessageType_onRemoteControlServiceInstallResult);
		m_pSink->onNodeAddonCallbacks(callBackBody);
	}
}
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


