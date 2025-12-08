//
//  ZPShareSelectWindowModel.h
//  ZCommonUI
//
//  Created by sanshi on 3/26/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>
#import <ZoomUnit/ZMCaptureModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZPShareSelectThirdPartyInfo: NSObject

@property (nonatomic, assign) ZMShareSelectItemType docType;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *docURL;
@property (nonatomic, copy) NSString *appName;

@end

@protocol ZPShareSelectWindowModelDelegate <NSObject>

@optional
- (NSArray<NSNumber *> *)filterOutWinIDsForDS;

@end

@interface ZPShareSelectWindowModel : ZMCaptureModel

@property(assign)ZMShareSelectItemType sharingType;
@property(copy)NSString* toolTipString;
@property(copy)NSAttributedString* toolTipAttributedString;
@property(copy)NSString* disabledInfo;
@property(copy)NSString* documentPath;
@property(assign)NSUInteger winCount;
@property(copy)NSString* axTitle;
@property(copy)NSString* nativeToolTip;
@property (nonatomic, strong, nonnull) NSString *audioShareToolTip;
@property (nonatomic, strong, nonnull) NSString *videoShareToolTip;
@property(retain)NSArray<NSNumber *> *winIDsForPS;
@property(weak) id<ZPShareSelectWindowModelDelegate> delegate;
@property(retain, readonly)NSArray<NSNumber *> *filterOutWinIDsForDS;
@property(retain)NSDictionary<NSNumber *, NSString *> *moreMenus;
@property(assign)BOOL disabled;
@property(copy)NSString* appId;
@property(assign)BOOL canCollaborate;
@property(retain) ZPShareSelectThirdPartyInfo *docInfo;
@property(assign)BOOL hasBadge;
@property(assign)BOOL showWarningIcon;

+ (id)modelWithCaptureModel:(ZMCaptureModel*)model;
- (id)initWithCaptureModel:(ZMCaptureModel*)model;
- (BOOL)isValid;
- (BOOL)isEqualToModel:(ZPShareSelectWindowModel *)model;
- (BOOL)isDesktopModel;
- (BOOL)isAsOrPsModel:(BOOL)containZapp;
- (BOOL)isAsModel;
- (BOOL)isZoomAppsCollaborationModel; //add for collaborateMode
- (BOOL)isPsModel;
- (BOOL)isAudioModel;
- (BOOL)isVideoModel;
- (BOOL)isClipsModel;
- (BOOL)isDocModel;
- (BOOL)isWebWBModel;
- (BOOL)isFrameModel;
- (BOOL)isThirdPartyDoc;
- (BOOL)isZNotesModel;
- (BOOL)canEnableShareButton;
- (BOOL)supportAudioShare;
- (BOOL)supportVideoShare;
- (BOOL)supportBoShare;
- (BOOL)supportWatermark;
+ (NSArray<ZPShareSelectWindowModel*>*)getScreensModelList;
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelList;
/*
 pIds indicates the sharing process
 if pIds is nil, then the system local share window is excluded
 */
+ (NSArray<ZPShareSelectWindowModel*>*)getWindowsModelListExcludingLocalShareWindows:(nullable NSArray<NSNumber *> *)pIds;
+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeList;
/*
 pIds indicates the sharing process
 if pIds is nil, then the system local share window is excluded
 */
+ (NSArray<ZPShareSelectWindowModel*>*)getProcessModeListExcludingLocalShareWindows:(nullable NSArray<NSNumber *> *)pIds;
+ (ZPShareSelectWindowModel*)getEmptyScreenModel;
+ (ZPShareSelectWindowModel*)getIOSDevideModel;
+ (ZPShareSelectWindowModel*)getIOSWiredDeviceModel;
+ (ZPShareSelectWindowModel*)getModelWithFileStorageModel:(NSString *)name imageName:(NSString *)imageName shareType:(ZMShareSelectItemType)shareType;
+ (ZPShareSelectWindowModel*)getClassicWhiteboardModel;
+ (ZPShareSelectWindowModel*)getWebWhiteboardModel;
+ (ZPShareSelectWindowModel*)getCameraModel;
+ (ZPShareSelectWindowModel*)getFrameModel;
+ (ZPShareSelectWindowModel*)getSoundModel;
+ (ZPShareSelectWindowModel*)getDocModel;
+ (ZPShareSelectWindowModel*)getVideoModel;
+ (ZPShareSelectWindowModel*)getZoomNotesModel;
+ (ZPShareSelectWindowModel*)getZoomDocsModel;
+ (ZPShareSelectWindowModel*)getZoomClipsModel;
@end

@interface ZPAppShareSelectWindowModel : ZPShareSelectWindowModel

@property(retain)NSDictionary* zappShareParam;
@property(assign)BOOL isAppOpened;
@property(assign)BOOL isSidePanel;

@end

NS_ASSUME_NONNULL_END
