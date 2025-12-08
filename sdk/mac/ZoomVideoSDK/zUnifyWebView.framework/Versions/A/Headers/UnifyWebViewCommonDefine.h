#ifndef _UNIFYWEBVIEW_COMMON_DEFINE_H_
#define _UNIFYWEBVIEW_COMMON_DEFINE_H_

// Hybrid app index define (type: CmmInt32), https://dg01docs.zoom.us/doc/QFPzi6xeQVuWs14ofn8Icw
#define HybridAppIndex_None           -1
#define HybridAppIndex_SearchApp       0
#define HybridAppIndex_Documentview    9
#define HybridAppIndex_AICApp          18
#define HybridAppIndex_SystemApp       25
#define HybridAppIndex_LauncherApp     28
#define HybridAppIndex_Calendar        34
#define HybridAppIndex_NewChat         35
#define HybridAppIndex_CCIMobile       44
#define HybridAppIndex_Mail            46
#define HybridAppIndex_FilePickerMenu  50    // dev env local load test app
#define HybridAppIndex_AiAdoption      53

#define IS_INVALID_HYBRID_APP_IDX(index) ((index) < 0)

// HybridAppInfo.extraInfo extra info key string define
// home url like: https://[app_domain]/[url_home_path]/[history_route]/index.html#[hash_route]
#define HybridAppExtraInfo_HashRoute    _T("hash_route")    //  <--> GetAppContextExTraParaType_AppResourceHashRoute
#define HybridAppExtraInfo_UrlHomePath  _T("url_home_path") //  <--> GetAppContextExTraParaType_UrlHomePath
#define HybridAppExtraInfo_HistoryRoute _T("history_route") //  <--> GetAppContextExTraParaType_AppResourceHistoryRoute
#define HybridAppExtraInfo_RegionId     _T("region_id")     //  <--> GetAppContextExTraParaType_AppResourceRegionId


#define HybridApp_Default_RegionId _T("___default_region___")

enum UnifyWebViewAppType
{
    UnifyWebViewAppType_None = 0,
    UnifyWebViewAppType_WebViewUISDK = 1,
    UnifyWebViewAppType_ReleaseNote = 2,
    UnifyWebViewAppType_UserUpgrade = 3,
    UnifyWebViewAppType_ZoomOnePro = 4,
    UnifyWebViewAppType_Poll = 5,
    UnifyWebViewAppType_CCI = 6,
    UnifyWebViewAppType_Mail = 7,
    UnifyWebViewAppType_ZoomApps = 8,
    UnifyWebViewAppType_ZoomDocs = 9,
    UnifyWebViewAppType_TeamChat = 10,
    UnifyWebViewAppType_Simulive = 11,
    UnifyWebViewAppType_Clips = 12,
    UnifyWebViewAppType_Whiteboard = 13,
    UnifyWebViewAppType_Note = 14,
    UnifyWebViewAppType_Calendar = 15,
    UnifyWebViewAppType_Scheduler = 16,
    UnifyWebViewAppType_ZoomIQ = 17,
    UnifyWebViewAppType_MeetingProfile = 18,
    UnifyWebViewAppType_WorkSpace = 19,
    UnifyWebViewAppType_ZR = 20,
    UnifyWebViewAppType_ZRC = 21,
    UnifyWebViewAppType_WorkFlow = 22,
    UnifyWebViewAppType_Hub = 23,
    UnifyWebViewAppType_SignUp = 24,
    UnifyWebViewAppType_SSOLogin = 25,
    UnifyWebViewAppType_Diagnostic = 26,
    UnifyWebViewAppType_NewFeedback = 27,
    UnifyWebViewAppType_QA = 28,
    UnifyWebViewAppType_WorkVivo = 29,
    UnifyWebViewAppType_NewChat = 30,
    UnifyWebViewAppType_SdkMeetingFeature = 31,
    UnifyWebViewAppType_WebRTCServer = 32,
    UnifyWebViewAppType_InAppPurchases = 33,
    UnifyWebViewAppType_Tasks = 34,
    UnifyWebViewAppType_FLWToday = 35,
    UnifyWebViewAppType_FLWShifts = 36,
    UnifyWebViewAppType_Surveys = 37,
    UnifyWebViewAppType_ZRCNewMeetingChat = 38,
    UnifyWebViewAppType_AIC = 39,
    UnifyWebViewAppType_Events = 40,
    UnifyWebViewAppType_F2F = 41,
    UnifyWebViewAppType_ZRCompanion = 42,
    UnifyWebViewAppType_NewSearch = 43,
    UnifyWebViewAppType_ClinicalNote = 44,
    UnifyWebViewAppType_ClinicalNotesInRecording = 45,
    UnifyWebViewAppType_ZRHelpButton = 46,
    UnifyWebViewAppType_EnhanceLogin = 47,
    UnifyWebViewAppType_EnhanceLoginAicSidePanel = 48,
    UnifyWebViewAppType_Support = 49,
    UnifyWebViewAppType_PBXCallQueue = 50,
    UnifyWebViewAppType_SmartRecognitionVideo = 51,
    UnifyWebViewAppType_HotDesk = 52,
    UnifyWebViewAppType_AiAdoption = 53,
    UnifyWebViewAppType_Videos = 54,
    UnifyWebViewAppType_ForgotPasswd = 55,
    UnifyWebViewAppType_UnifyWebView = 56,
    UnifyWebViewAppType_BookingScheduler = 60,
    UnifyWebViewAppType_MarketplaceOAuthLogin = 61,
};

enum UnifyWebViewType
{
    UnifyWebViewType_None,
    UnifyWebViewType_SystemWebView2,
    UnifyWebViewType_CEF,
    UnifyWebViewType_FixVersionWebView2,
    UnifyWebViewType_WKWebView,
    UnifyWebViewType_AndroidWebView
};

enum UnifyWebViewIdleRecycleType {
    UnifyWebViewIdleRecycleType_Disabled = 0,
    UnifyWebViewIdleRecycleType_Enabled,
    UnifyWebViewIdleRecycleType_NoResponseEnabled,
};

enum UnifyWebviewCrashType
{
    UnifyWebviewCrashType_None,
    UnifyWebviewCrashType_WebViewAgentCrashed,
    UnifyWebviewCrashType_ExitCodeNonZero,
    UnifyWebviewCrashType_WasKilled,
    UnifyWebviewCrashType_Crashed,
    UnifyWebviewCrashType_OutOfMemory,
    UnifyWebviewCrashType_BrowserProcessExited,
    UnifyWebviewCrashType_RenderProcessExited,
    UnifyWebviewCrashType_RenderProcessUnresponsive,
    UnifyWebviewCrashType_FrameRenderProcesExited,
    UnifyWebviewCrashType_UtilityProcessExited,
    UnifyWebviewCrashType_SandboxHelperProcessExited,
    UnifyWebviewCrashType_GpuProcessExited,
    UnifyWebviewCrashType_PpapiPluginProcessExited,
    UnifyWebviewCrashType_PpapiBrokerProcessExited,
    UnifyWebviewCrashType_UnknownProcessExited,
    UnifyWebviewCrashType_ExceededCPULimit,
    UnifyWebviewCrashType_RequestedByClient
};

enum UnifyWebViewOperateState
{
    UnifyWebViewOperateState_Deny,
    UnifyWebViewOperateState_Allow,
    UnifyWebViewOperateState_Hold
};

enum UnifyWebViewError
{
    UnifyWebViewError_NoError                           = 0,
    UnifyWebViewError_ConnectError                      = 1,
    UnifyWebViewError_ServerError                       = 2,
    UnifyWebViewError_Timeout                           = 3,
    UnifyWebViewError_ServerUnreachable                 = 4,
    UnifyWebViewError_CertificateError                  = 5,
    UnifyWebViewError_OperationCanceled                 = 6,
    UnifyWebViewError_AuthenticationFail                = 7,
    UnifyWebViewError_RedirectFail                      = 8,
    UnifyWebViewError_DnsError                          = 9,
    UnifyWebViewError_ExceededLimit                     = 10,
    UnifyWebViewError_UnRegisterModule                  = 11,
    UnifyWebViewError_Unknown                           = 12,
    UnifyWebViewError_ConnectRefused                    = 13,
    UnifyWebViewError_WebViewVersionTooLow              = 14,
    UnifyWebViewError_ResourceError                     = 15,
    UnifyWebViewError_UrlError                          = 16,
    UnifyWebViewError_FilePermissionsError              = 17,
    UnifyWebViewError_DecodeError                       = 18,
    UnifyWebViewError_CacheWriteFailure                 = 19,
    UnifyWebViewError_CacheReadFailure                  = 20,
    UnifyWebViewError_CheckUrlFailed                    = 21,
    UnifyWebViewError_PermissionDenied                  = 22,
    UnifyWebViewError_ResourceUnavailable               = 23,
    UnifyWebViewError_DataError                         = 24,
    UnifyWebViewError_WebviewUnsupport                  = 25,
    UnifyWebViewError_WebviewDisable                    = 26,
    UnifyWebViewError_PageShowBlank                     = 27,
    UnifyWebViewError_JsUnanswered                      = 28,
    UnifyWebViewError_HugeMemoryUsage                   = 29,
    UnifyWebViewError_SystemUnsupportCEF                = 30,
    UnifyWebViewError_CEFPluginDownloadFail             = 31,
    UnifyWebViewError_TypeIllegal                       = 32,
    UnifyWebViewError_RecordNotFound                    = 33,
    UnifyWebViewError_CEFPluginNotExist                 = 34,
    UnifyWebViewError_RenderProcessUnresponsive         = 35,
    UnifyWebViewError_RenderProcessTerminated           = 36,
    UnifyWebViewError_WebView2RuntimeOutDated           = 37,
    UnifyWebViewError_CreateCEFTimeout                  = 38,
    UnifyWebViewError_CreateCEFTimeoutUnInited          = 39,
    UnifyWebViewError_CreateCEFTimeoutUnCreated         = 40,
    UnifyWebViewError_CreateCEFTimeoutUnLoading         = 41,
    UnifyWebViewError_ComposeResultCancelled            = 42,
    UnifyWebViewError_ComposeResultFailed               = 43,
};

enum UnifyWebviewHybridAppError
{
    UnifyWebviewHybridAppError_None                        = 7000,
    UnifyWebviewHybridAppError_DownloadPkgFailed           = 7001,
    UnifyWebviewHybridAppError_DownloadRequestFailed       = 7002,
    UnifyWebviewHybridAppError_LoadLocalPathFailed         = 7003,
    UnifyWebviewHybridAppError_RecheckAfterDownloadFailed  = 7004,
    UnifyWebviewHybridAppError_NoRemoteCdnUrl              = 7005,
    UnifyWebviewHybridAppError_NotUseLocalResource         = 7006,
    UnifyWebviewHybridAppError_DownloadPkgTimeout          = 7007,
};

enum UnifyWebviewAPMError
{
    UnifyWebviewAPMError_ConnectAgentTimeout,
    UnifyWebviewAPMError_ApiVerificationFailed,
    UnifyWebviewAPMError_CreateBrowserFailed,
    UnifyWebviewAPMError_CreateAgentProcessFailed,
};

enum UnifyWebViewPermissionState
{
    UnifyWebViewPermissionState_Default = 0,
    UnifyWebViewPermissionState_Allow,
    UnifyWebViewPermissionState_Deny
};

enum UnifyWebViewBlankCheckResult
{
    OperationNotCompleted = 0,
    Invisible,
    Blank,
    Normal,
};

enum UnifyWebViewBlankCheckType
{
    WindowShot     = 1,
    ViewShot       = 2,
    Api            = 4,
}; 

enum UnifyWebViewProcessType
{
    WebViewProcessType_Unknown = 0,
    WebViewProcessType_Browser = 1,
    WebViewProcessType_Renderer = 2,
    WebViewProcessType_GPU = 3,
    WebViewProcessType_Utility = 4,
    WebViewProcessType_Zygote = 5,
    WebViewProcessType_SandboxHelper = 6,
    WebViewProcessType_PPAPIPlugin = 7,
    WebViewProcessType_PPAPIBroker = 8,
};

// For iOS, default load type is REMOTE_CDN_URL
// for other platform, when local LOCAL_PKG failed will fallback to REMOTE_CDN_URL unless needFallbackToCDN set to false
enum HybridAppLoadType
{
    NONE,
    LOCAL_PKG,
    REMOTE_CDN_URL,
};

enum UnifyWebViewNewWindowOpenResultCode
{
    ResultCodeNone = 0,
    OpenUrlInSystemBrowser,
    PopNewWindow,
    Ignore,
    PopCommonWindow,
};

enum UnifyWebViewNavigationType {
    NavigationType_Unknown = 0,
    NavigationType_Others,
    NavigationType_Reload_API,
    NavigationType_Reload_Script,
    NavigationType_BackOrForward,
    NavigationType_API,
    NavigationType_Script,
    NavigationType_Redirect,
    NavigationType_LinkActivated,
};

#endif
