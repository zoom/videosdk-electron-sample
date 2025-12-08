//
//  ZMMTStudioConstants.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2023/11/10.
//

#ifndef ZMMTStudioConstants_h
#define ZMMTStudioConstants_h

typedef NS_ENUM(NSUInteger, ZMMTStudioResourceTag) {
    ZMMTStudioResourceTag_Wallpaper = 99,
    ZMMTStudioResourceTag_Video,
    ZMMTStudioResourceTag_Avatar,
    ZMMTStudioResourceTag_Border_Left,
    ZMMTStudioResourceTag_Border_Right,
    ZMMTStudioResourceTag_Border_Top,
    ZMMTStudioResourceTag_Border_Bottom,
    ZMMTStudioResourceTag_NameBox,
    ZMMTStudioResourceTag_NameTag,
};

typedef NS_ENUM(NSUInteger, ZMMTStudioResourceRelativePosition) {
    ZMMTStudioResourceRelativePosition_BG = 0,
    ZMMTStudioResourceRelativePosition_FG,
    ZMMTStudioResourceRelativePosition_TOP
};

typedef NS_OPTIONS(NSUInteger, ZMMTStudioSceneContentType) {
    ZMMTStudioSceneContentType_None = 0,
    ZMMTStudioSceneContentType_User = 1LL<<0,
    ZMMTStudioSceneContentType_Share = 1LL<<1,
    ZMMTStudioSceneContentType_Image = 1LL<<2,
    ZMMTStudioSceneContentType_Video = 1LL<<3,
};

/**
 The current scene does not support the mixing of multiple media types,
 such as image, Video, share, etc.
 Only one media type can be included in a scene. Combined layout with User Video
 */
typedef NS_OPTIONS(NSUInteger, ZMMTStudioSceneType) {
    ZMMTStudioSceneType_None = 0,
    ZMMTStudioSceneType_User = 1LL<<0,//contain user video
    ZMMTStudioSceneType_Share = 1LL<<1,//contain share, share scene
    ZMMTStudioSceneType_Image = 1LL<<2,//contain image, image scene
    ZMMTStudioSceneType_Video = 1LL<<3,//contain video, video scene
};

typedef NS_ENUM(NSUInteger, ZMMTStudioProgramStatus) {
    ZMMTStudioProgramStatus_None = 0,//webinar not started, ps not living
    ZMMTStudioProgramStatus_WebinarStarted,//only webinar started , ps not living
    ZMMTStudioProgramStatus_PSLiving,//only ps living , webinar not started
    ZMMTStudioProgramStatus_PSLivingByMe,//only ps living , webinar not started
    ZMMTStudioProgramStatus_StartedAndLiving,//webinar started, ps living by other host/cohost
    ZMMTStudioProgramStatus_StartedAndLivingByMe,//webinar started, ps living by other host/cohost
};

extern NSString* const kStudioTipSpeakerJoin;
extern NSString* const kStudioTipDeviceNotSupport;
extern NSString* const kStudioTipLowerResolution;
extern NSString* const kStudioTipQuitPS;

typedef NS_ENUM(NSUInteger, ZMMTStudioInviteUserType) {
    ZMMTStudioInviteUserType_Producer = 0,
    ZMMTStudioInviteUserType_VideoScene,
    ZMMTStudioInviteUserType_All,//Producer&VideoScene
};

typedef NS_ENUM(NSUInteger, ZMMTStudioPreviewMenuTag) {
    ZMMTStudioPreviewMenuTag_Replace = 0,
    ZMMTStudioPreviewMenuTag_Remove,
};

typedef NS_ENUM(NSUInteger, ZMMTStudioVideoStartPosition) {
    ZMMTStudioVideoStartPositionFromBeginning = 0,
    ZMMTStudioVideoStartPositionFromLastPosition,
    ZMMTStudioVideoStartPositionDoNothing
};

typedef NS_ENUM(NSUInteger, ZMMTStudioVideoEndOperation) {
    ZMMTStudioVideoEndOperationDoNothing = 0,
    ZMMTStudioVideoEndOperationLoopVideo,
    ZMMTStudioVideoEndOperationGoNextScene,
    ZMMTStudioVideoEndOperationEndWebinar
};

typedef NS_ENUM(NSUInteger, ZMMTStudioLiveStatus) {
    ZMMTStudioLiveStatusNone = 0,
    ZMMTStudioLiveStatusWillLive,
    ZMMTStudioLiveStatusLiving,
    ZMMTStudioLiveStatusWillStop,
    ZMMTStudioLiveStatusStoped,
};

#endif /* ZMMTStudioConstants_h */
