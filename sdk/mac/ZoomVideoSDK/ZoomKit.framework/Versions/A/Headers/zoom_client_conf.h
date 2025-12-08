#pragma once

#ifndef ZOOM_CLIENT_CONFIGURATION_H_
#define ZOOM_CLIENT_CONFIGURATION_H_

//#define BUILD_FOR_ZOOM_CHINESE
// #define BUILD_FOR_MIMO
//#define BUILD_FOR_RINGCENTRAL
//#define BUILD_FOR_BT
//#define BUILD_FOR_TELUS
//#define BUILD_FOR_ATT
//#define BUILD_FOR_BBM
//#define  BUILD_FOR_BROADVIEW
//#define BUILD_FOR_BBM
//#define BUILD_FOR_BSC
//#define BUILD_FOR_ZOOM
//#define BUILD_FOR_BIZCONF
//#define BUILD_FOR_ZHUMU
//#define BUILD_FOR_ZHUMU

// #ifndef ANDROID
#include "buildtime_client_config.h"
#include "common_def.h"
// #endif
#ifndef  BUILD_FOR_CLIENT_SDK
//temp solution for Zoom Apps, currently only support in Mac/Win. ENABLE_ZAPP will be removed in future. // 1/12/2021

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_ZOOMAPP
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_ZOOMAPP
#endif

#if (((defined WIN_ZOOMAPP) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZAPP) || (defined __IOS__ && !defined(__WATCHOS__)) ) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER))
#ifndef ENABLE_ZAPP
    #define ENABLE_ZAPP
#endif
#endif

#ifndef ENABLE_ZAPP
#if ((defined BUILD_FOR_MIMO) || (defined BUILD_FOR_ZPCONTROLLER))
#   define ENABLE_ZAPP
#endif
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_CCI
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_CCI
#endif

#if (((defined __IOS__ && !defined(__WATCHOS__)) || (defined CMM_ANDROID) || (defined WIN_CCI) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
   #define ENABLE_ZOOM_CCI
#if defined __MACOS__
    #define USE_ZCC_DELEGATE
#endif
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_SIMULIVE_FROM_LOBBY
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_SIMULIVE_FROM_LOBBY
#endif

#if (((defined WIN_SIMULIVE_FROM_LOBBY) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
#define ENABLE_ZOOM_SIMULIVE_FROM_LOBBY
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined (_M_ARM64) )
#   define WIN_BOOKINGS
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined (_M_ARM64) )
#   define WIN_BOOKINGS
#endif

#if (((defined WIN_BOOKINGS) || (defined __MACOS__) || (defined (__LINUX_CLIENT__))) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER) && (!defined __XROS__))
   #define ENABLE_ZOOM_BOOKINGS
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined (_M_ARM64) )
#   define WIN_Calendar
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined (_M_ARM64) )
#   define WIN_Calendar
#endif

#if ((defined WIN_Calendar) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZCALENDAR) || (defined(__IOS__) && !defined(__WATCHOS__))) ||  (defined BUILD_FOR_MIMO) || (defined BUILD_FOR_ZPCONTROLLER)
   #define ENABLE_ZOOM_CALENDAR
#endif

#if defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 )
#   define WIN_MailClient
#elif defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 )
#   define WIN_MailClient
#endif

#if (((defined WIN_MailClient) || (defined __MACOS__) || (defined ENABLE_ANDROID_CLIENT_ZMAIL) || (defined __IOS__ && !defined(__WATCHOS__))) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER))
   #define ENABLE_MAILCLIENT_SERVICE
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_ZOOM_CHAT_JS
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_ZOOM_CHAT_JS
#endif

#if (((defined WIN_ZOOM_CHAT_JS) || (defined __MACOS__)) && (!defined BUILD_FOR_MIMO))
	#define ENABLE_ZOOM_CHAT_JS
#endif

#if (defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 ) || defined _M_ARM64)
#   define WIN_ZOOM_SPACES
#elif (defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 ) || defined _M_ARM64)
#   define WIN_ZOOM_SPACES
#endif

#if (((defined __MACOS__) || (defined WIN_ZOOM_SPACES) || (defined __LINUX_CLIENT__) || ((defined __IOS__) && !defined(__XROS__) && !defined __WATCHOS__)) && (!defined BUILD_FOR_MIMO) && (!defined BUILD_FOR_ZPCONTROLLER))
    #define ENABLE_ZOOM_SPACES
#endif

#else
#if !defined(BUILD_FOR_LITE_SDK) && !defined(__LINUX_CLIENT__)
#define ENABLE_ZAPP
#endif
#endif//BUILD_FOR_CLIENT_SDK

#if !defined(BUILD_FOR_CLIENT_SDK) && !defined(__WATCHOS__)
#define ZOOM_MESH_ENABLE
#endif


#if !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_CLIENT_SDK)
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64) || defined(_M_ARM64)
#define ENABLE_ZOOM_DIAGNOSTIC
#elif (defined __MACOS__) || (defined __LINUX_CLIENT__)
#define ENABLE_ZOOM_DIAGNOSTIC
#elif (defined __IOS__) || (defined CMM_ANDROID)
#define ENABLE_ZOOM_DIAGNOSTIC_MOBILE
#endif
#endif

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#if ((defined CMM_WIN ) || (defined __MACOS__) || (defined __LINUX_CLIENT__)) && !defined(BUILD_FOR_MINIPACKAGE)
#define ENABLE_ZOOM_REQUESTLIFECYDLE_MONITOR
#endif
#endif

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#if ((defined CMM_WIN ) || (defined __MACOS__) || (defined __IOS__) || (defined CMM_ANDROID) || (defined __LINUX_CLIENT__)) && !defined(BUILD_FOR_MINIPACKAGE)
#define BUILD_FOR_FILE_XFER_ENABLE
#endif
#endif

#ifndef BUILD_FOR_LITE_SDK
#define ENABLE_DAL_FEATURE
#endif

#if !defined(BUILD_FOR_LITE_SDK) && !defined(BUILD_FOR_MINIPACKAGE)
#define ENABLE_LOCAL_DNS_CACHE
#endif

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK) && !defined(BUILD_FOR_LITE_SDK)
#define ENABLE_ASYNC_KV_OPERATION
#endif

//#if (defined ENABLE_DAL_FEATURE) && (defined ENABLE_ASYNC_KV_OPERATION) && ((defined CMM_WIN) || (defined CMM_ANDROID) || (defined __MACOS__))
#if (defined ENABLE_DAL_FEATURE) && (defined ENABLE_ASYNC_KV_OPERATION) && (defined(BUILD_FOR_DOGFOOD) || defined(ZOOM_DEBUG))
#define ENABLE_DAL_KV_MODE
#endif

#if (!defined CMM_ANDROID) && (!defined __ZOOM_NO_CLIENT_LOG)
#define ENABLE_NET_COMPOUND_ABILITY
#endif


#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64) || defined(_M_ARM64)
#define USE_HUDDLE_DELEGATE
#elif defined(__MACOS__)
#define USE_HUDDLE_DELEGATE
#define USE_INDEPENDENCE_PROCESS
#endif
#endif

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_CLIENT_SDK)
#if defined(WIN32) || defined(__MACOS__)
#define ENABLE_WORKVIVO
#endif
#endif

#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#if (defined WIN32) || (defined __MACOS__)
#define ENABLE_BACKGROUND_UPDATE_SCHEDULE
#endif
#endif

#if (defined __ZOOM_NO_CLIENT_LOG) || (defined __zoom_no_client_log_zr) || (defined BUILD_FOR_CLIENT_SDK)
#else
#if !defined(BUILD_FOR_MIMO) && !defined(BUILD_FOR_ZPCONTROLLER) && !defined(BUILD_FOR_VDI) && !defined(BUILD_FOR_CLIENT_SDK)
#define BUILD_FOR_TA
#endif
#endif

#if (defined CMM_WIN || defined CMM_ANDROID) && (defined BUILD_FOR_ZPCONTROLLER)
#define ZOOM_DYNAMIC_LIBRARY_IMPLICIT_DEPENDENCY
#endif

#if defined __IOS__ || defined _BB10_ || defined __LINUX_CLIENT__
#define ZOOM_LIBRARY_STATIC_DEPENDENCY
#endif

#if !defined(BUILD_FOR_MIMO) && !defined __LINUX_CLIENT__
#define ENABLE_SIPCALL_THIRDPARTY_INTEGRATION 1 // Avaya, Mitel, Unify
#endif

#ifdef __XROS__
#define ENABLE_VISIONPRO_3DMODEL
#endif

#if defined(BUILD_FOR_ZPCONTROLLER_IOS) || defined(BUILD_FOR_LITE_SDK) || defined(BUILD_FOR_ZOOM_RC_APP)
#define DISABLE_ZMDB_STORAGE
#endif

#define ENABLE_EVENT_LOGGER

#if (!defined(__ZOOM_NO_CLIENT_LOG) && !defined(__zoom_no_client_log_zr)) || (defined BUILD_FOR_DOGFOOD)
#define ENABLE_WRITE_EVENT_LOG_TO_FILE
#endif

#if (defined BUILD_FOR_CLIENT_SDK)
#if (defined ENABLE_WRITE_EVENT_LOG_TO_FILE)
#undef ENABLE_WRITE_EVENT_LOG_TO_FILE
#endif
#endif

#ifdef BUILD_FOR_VDI
#define ENABLE_VB_WHITELIST
#endif

#if (defined CMM_WIN) && (defined BUILD_FOR_NORMAL_CLIENT)
#define ENABLE_POWER_SAVER_MODE
#endif

#if ((defined CMM_WIN) || (defined __MACOS__)) && (defined BUILD_FOR_NORMAL_CLIENT)
#define ENABLE_VIDEO_MODEL_DYNAMIC_DOWNLOAD
#endif

#if (defined ENABLE_ZOOM_DIAGNOSTIC) && (!defined __LINUX_CLIENT__)
#define ENABLE_MTR_AUTO_DETECT
#endif

#define ENABLE_EVENTDATABASE_FTS

#if (defined CMM_ANDROID) && ((defined BUILD_FOR_META) || (defined BUILD_FOR_GXR))
#define BUILD_FOR_ANDROID_VR
#endif


#if defined(CMM_WIN) && defined(BUILD_FOR_NORMAL_CLIENT)
#define ENABLE_UNIFIED_SETTING
#define ENABLE_MCM_SERVICE
#endif

#if (defined BUILD_FOR_CLIENT_SDK) || ((defined (CMM_WIN) || defined(__MACOS__)) && (defined BUILD_FOR_NORMAL_CLIENT))
#define ENABLE_VIDEO_AUTO_FRAMING
#endif

#if !(defined DISABLE_ZMDB_STORAGE) && (defined(BUILD_FOR_DOGFOOD) || defined(ZOOM_DEBUG))
#define ENABLE_DYNAMIC_QUERY_TIMEZONE
#endif

#if ((defined CMM_WIN ) || (defined __MACOS__) || (defined __LINUX_CLIENT__)) && defined(BUILD_FOR_NORMAL_CLIENT)
#define ENABLE_ZOOM_PROCESS_INFO_COLLECTOR
#endif

// dont define the macro after this line!!!
#endif //ZOOM_CLIENT_CONFIGURATION_H_
