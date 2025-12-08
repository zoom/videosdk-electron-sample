//
//  ZMShareSelectDef.h
//  ZCommonUI
//
//  Created by walt.li on 9/21/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

typedef NS_ENUM(NSInteger, ZMShareSoundsMode){
    ZMShareSoundsMode_Mono,
    ZMShareSoundsMode_Stereo,
};

typedef NS_ENUM(NSInteger, ZMShareSelectItemType) {
    ZMShareSelectItemEmpty = -1,
    ZMShareSelectItemUnknown = 0, //old client
    ZMShareSelectItemAs,    //application share
    ZMShareSelectItemDs,    //desktop share
    ZMShareSelectItemClassicWB,    //classic whiteboard share
    ZMShareSelectItemWebWB,    //Web whiteboard share
    ZMShareSelectItemAirhost,    //mobile device from PC
    ZMShareSelectItemCamera,    //camera share
    ZMShareSelectItemWiredDevice, //wired device, connect between Mac and iPhone
    ZMShareSelectItemFrame, //share a selected region area of desktop
    ZMShareSelectItemComputerAudio, //pure computer audio share, note: this type is different with other share
    ZMShareSelectItemDropbox, //share dropbox, open dropbox website in default browser
    ZMShareSelectItemOneDriver,
    ZMShareSelectItemGoogleDriver,
    ZMShareSelectItemOneDriverPicker,
    ZMShareSelectItemGoogleDriverPicker,
    ZMShareSelectItemBox,//SSB_MC_AS_SHARED_OBJ_BOX,
    ZMShareSelectItemBoxPicker,
    ZMShareSelectItemDoc,//share ppt/slide
    ZMShareSelectItemMsSharePoint, //ZOOM-135932
    ZMShareSelectItemMsSharePointPicker,
    ZMShareSelectItemPs,
    ZMShareSelectItemVideo,
    ZMShareSelectItemZoomApps,
    ZMShareSelectItemZoomNotes,
    ZMShareSelectItemZoomDocs,
    ZMShareSelectItemZoomClips,
};

typedef NS_ENUM(NSInteger, ZMShareSelectSegmentType) {
    ZMShareSelectSegmentNormal,
    ZMShareSelectSegmentCustomized,
};

typedef NS_ENUM(NSUInteger, ZMShareSelectVideoQuality) {
    ZMShareSelectVideoQuality_1080p30fps = 0,
    ZMShareSelectVideoQuality_720p30fps,
    ZMShareSelectVideoQuality_1080p60fps,
    ZMShareSelectVideoQuality_720p60fps,
    ZMShareSelectVideoQuality_Count
};

typedef NS_ENUM(NSInteger, ZMShareSelectBannerType){
    ZMShareSelectBannerType_HoldKey,
    ZMShareSelectBannerType_Segment,
};

@interface ZMShareSelectVideoQualityHelper : NSObject

+ (NSString *)descriptionForVideoQuality:(ZMShareSelectVideoQuality)videoQuality;
+ (BOOL)isHighFps:(ZMShareSelectVideoQuality)videoQuality;
+ (BOOL)isFullHD:(ZMShareSelectVideoQuality)videoQuality;
+ (ZMShareSelectVideoQuality)videoQualityForLowFps:(ZMShareSelectVideoQuality)videoQuality;
+ (ZMShareSelectVideoQuality)videoQualityForLowResolution:(ZMShareSelectVideoQuality)videoQuality;
+ (ZMShareSelectVideoQuality)videoQualityWithHighFps:(BOOL)highFps
                                              fullHD:(BOOL)fullHD;
@end

@interface ZMShareSelectOptions : NSObject

@property (nonatomic, assign) BOOL videoShare;
@property (nonatomic, assign) BOOL audioShare;
@property (nonatomic, assign) BOOL boShare;
@property (nonatomic, assign) ZMShareSelectVideoQuality videoQuality;

@property (nonatomic, assign) BOOL showZoomWindow;
@property (nonatomic, assign) BOOL showToolbar;
@property (nonatomic, assign) BOOL hideRepeatWindow;

@property (nonatomic, assign) BOOL showWatermark;

+ (instancetype)selectOptions:(BOOL)videoShare
                   audioShare:(BOOL)audioShare
                      boShare:(BOOL)boShare;

+ (instancetype)selectOptions:(BOOL)videoShare
                   audioShare:(BOOL)audioShare
                      boShare:(BOOL)boShare
                 videoQuality:(ZMShareSelectVideoQuality)videoQuality;
@end
