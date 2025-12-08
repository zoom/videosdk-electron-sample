//
//  IZMMTCustomViewMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTCustomViewController;
@protocol IZMMTCustomViewMgr <ZMRoutableObject>

- (ZMMTCustomViewController*)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isCustomModeOn;
- (BOOL)isCustomModeOnForSession:(ZMConfSession*)session;
- (BOOL)isCustomSharingOn;
- (BOOL)isCustomModeDepends;
- (BOOL)isCustomModeEnabled;
- (BOOL)isAble2EnterCustomMode;
- (BOOL)isAble2ViewOtherShare;

- (BOOL)shouldVideoCutout;
- (BOOL)shouldVideoReplace;
- (BOOL)shouldVideoUnmirror;
- (BOOL)disableSmartErase;

- (NSString *)layoutFilePath;

- (void)prepareForRecording:(BOOL)force;
- (void)updateVideoCutoutState;

- (void)tryToCheckImmersePackage;
- (void)exitCustomLayoutMode;

- (void)setImmersiveMode:(BOOL)on;
- (void)cancelSmartErase;

- (BOOL)isSelectWindowShowing;
- (void)closeSelectWindow;
- (void)showSelectWindow;

// status
- (void)onSceneDependerChanged;
- (void)onMyVideoDeviceRunStarted:(NSNumber*)runType;

- (void)onVideoLayoutChanged;
- (void)onFloatLayoutChanged;

@end

@protocol IZMMTCustomViewStatusProtocol <NSObject>
@optional
- (void)onViewUsersUpdated;
- (void)onSharePortUpdated;

- (void)onVideoLayoutUpdated;
- (void)onFloatLayoutUpdated;

- (void)onMyVideoStatusChanged:(BOOL)changed;
- (void)onMyVideoReplaceChanged;

- (void)onImmersiveModeChanged;
@end

@class ZMMTCustomLayoutModel;
@class ZMMTCustomLayoutTemplate;
@class ZMMTCustomFloatData;
@class ZMMTCustomXMLHelper;
@protocol IZMMTCustomLayoutMgr <ZMRoutableObject>

@property (nonatomic, readonly) NSMutableArray *layoutModels;
@property (nonatomic, readonly) ZMMTCustomLayoutModel *layoutModel;
@property (nonatomic, readonly) ZMMTCustomLayoutTemplate *layoutTemplate;
@property (nonatomic, readonly) ZMMTCustomXMLHelper *xmlHelper;
@property (nonatomic, readonly) ZMShareSource *viewShareSource;

- (ZMMTCustomLayoutModel *)getCurrentModel;
- (ZMMTCustomLayoutModel *)createCustomizeModel;
- (ZMMTCustomLayoutModel *)addCustomImage:(NSString *)path;
- (ZMMTCustomLayoutModel *)addCustomVideo:(NSString *)path;
- (void)removeLayout:(ZMMTCustomLayoutModel*)layout;

- (void)setVideoCutout:(BOOL)isCutout;
- (void)setVideoLayout:(nullable ZMMTCustomLayoutModel *)layout;
- (void)setFloatLayoutDatas:(NSArray *)datas;

- (void)syncCustomLayoutModel;
- (void)deliverLayoutTips:(NSString *)tips;
- (void)prepareForRecording:(BOOL)force;

- (void)onImmersivePackageReady;
- (void)onImmersiveStatusChanged;
- (void)onVideoLayoutUpdate;
- (void)onFloatLayoutUpdate;
- (void)onVideoLayoutReady:(NSString *)layoutId;
- (void)onSharePortUpdated:(ZMShareSource*)zmShareSource;

//MARK: Users
- (void)addFloatUser:(ZMUser *)user;
- (void)addFloatData:(ZMMTCustomFloatData *)data;
- (void)removeFloatUser:(ZMUser *)user;
- (void)updateVideoUser;

- (NSMutableArray<ZMUser*> *)obtainCustomViewUsersWithSelf:(BOOL)withSelf;

@end

@protocol IZMMTCustomDownloadMgr <ZMRoutableObject>

- (BOOL)isAomhostReady;
- (BOOL)isThumbnailReady;
- (BOOL)isDownloadingLayoutModel:(ZMMTCustomLayoutModel *)layoutModel;

- (void)tryToDownloadImmersePackage;
- (void)startDownloadVideoLayout:(NSString*)layoutId;
- (void)startDownloadLayoutModel:(ZMMTCustomLayoutModel *)layoutModel;
- (void)stopDownload;
- (void)removeDownloadTip;

- (void)onDownloadVideoLayoutThumbStart;
- (void)onDownloadVideoLayoutThumbUpdate;
- (void)onDownloadVideoLayoutThumbEnd;
- (void)onDownloadVideoLayoutThumbFailed;

- (void)onDownloadVideoLayoutSuccess:(NSString *)layoutID;
- (void)onDownloadVideoLayoutUpdate:(NSString *)layoutID progress:(NSInteger)progress;
- (void)onDownloadVideoLayoutFailed:(NSString *)layoutID;

@end

@protocol IZMMTCustomSelectSceneMgr <ZMRoutableObject>

- (void)reloadVideoLayouts;

- (void)onAomhostReady;
- (void)onVideoLayoutReady:(ZMMTCustomLayoutModel*)layout;

@end

NS_ASSUME_NONNULL_END
