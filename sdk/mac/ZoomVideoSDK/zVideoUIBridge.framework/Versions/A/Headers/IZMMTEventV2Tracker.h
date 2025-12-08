//
//  IZMMTEventV2Tracker.h
//  VideoUIBridge
//
//  Created by vinson.wang on 2025/3/26.
//

#import <Foundation/Foundation.h>

#import <zTelemetryBiz/SnowplowBiz/meetings_v2/meetings_v2_telemetry_types.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTEventV2Tracker <NSObject>

- (MeetingsV2MeetingWallpaperEntityParams)getWallpaperEntity;
- (MeetingsV2ShareOptionsEntityParams)getShareOptionsEntity;
- (MeetingsV2ShareOptionsEntityParams)getShareOptionsEntity:(e_meetings_v2_ShareOptionsEntity_share_content_type)shareContentType;
- (MeetingsV2VideoLayoutPreferenceEntityParams)getVideoLayoutPreferenceEntity;
- (MeetingsV2PsSceneEntityParams)getPSSceneEntity;
#pragma mark - UUI
- (ns_zm_conf_universal_ui::UuiEventTrackInfo)getTrackInfo:(ZMMTEntity*)entity;
@end

NS_ASSUME_NONNULL_END
