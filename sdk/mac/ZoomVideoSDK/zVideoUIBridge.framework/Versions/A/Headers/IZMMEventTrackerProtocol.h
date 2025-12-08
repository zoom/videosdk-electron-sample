//
//  IZMMEventTrackerProtocol.h
//  VideoUIBridge
//
//  Created by Lenard Zhou on 2022/12/26.
//

#import <Foundation/Foundation.h>
#import <ZoomPaapDef.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMEventTrackerProtocol <ZMRoutableObject>

- (ZoomPAAP::PAAPMeetingSettingInteract)getMeetingSettings;
- (ZoomPAAP::MeetingPreferences)getMeetingPreferences;
- (ZoomPAAP::PAAPChat)getChatEntity;
- (ZoomPAAP::MeetingWallpaper)getMeetingWallpaperEntity;
- (ZoomPAAP::PAAPSharerData)getSharerDataEntity;
- (ZoomPAAP::PAAPSharerData)getSharerDataEntity:(e_meetings_SharerDataEntity_share_session_type)sessionType;

@end

NS_ASSUME_NONNULL_END
