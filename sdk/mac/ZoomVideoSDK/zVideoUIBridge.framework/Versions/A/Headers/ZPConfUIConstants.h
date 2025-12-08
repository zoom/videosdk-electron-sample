//
//  ZPConfUIConstants.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 1/19/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#ifndef SaasBeeConfUIModule_ZPConfUIConstants_h
#define SaasBeeConfUIModule_ZPConfUIConstants_h


typedef enum
{
    RENDER_ACTIVE,
    RENDER_MYSELF,
    RENDER_ATTENDEE,
    RENDER_FLOAT,
    RENDER_WALL
}RENDER_CONTAINER_TYPE;

typedef enum
{
	Video_Frame_Bk = 0,
	Video_Pic_Avatar,
	Video_SpeakerName,
	Video_Btn_Switch,
	Video_Icon_Mute,
    Video_WaterMark,
    Video_Quality,
    Video_Conf_Info,
    Video_Confidential_WaterMark,
    Video_Update_AllButtons,
    Video_SDK_WaterMark,//BUILD_FOR_CLIENT_SDK
    VIDEO_UNKNOWN,
}RENDER_PIC_LAYER;

/// This file used to contain a declaration of `enum PT_NAVWEB_TYPE`, but it was a stale duplicate of the same
/// enum, declared in `SaasBeePTAppInterface.h`, with the same name. The introduction of Swift code to the project
/// caused the build to fail because of this redeclaration.
///
/// If you're looking for `enum_PT_NAVWEB_TYPE`, include `zPTApp/SaasBeePTAppInterface.h` instead.

typedef enum {
    ZMVideo_Layout_Customized_None = 0,
    ZMVideo_Layout_Customized_Horizontal,
    ZMVideo_Layout_Customized_Vertical
}ZMVideo_Layout_Customized_Type;

typedef enum {
    ZMConfAudioNotConnect,
    ZMConfAudioConnecting,
    ZMConfAudioConnectSuccess,
    ZMConfAudioConnectFail
} ZMConfAudioConnectStatus;

#define kZoomPTLoginNotEntitled @"1111"
#define kZoomPTLoginNotRegistered @"1112"
#define kZoomPTLoginBBMURL @"http://www.blackberry.com/bbmmeetings"

#endif
