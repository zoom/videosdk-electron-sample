//
//  ZMShareSelectWindow.h
//  ZCommonUI
//
//  Created by walt.li on 3/2/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//


#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMShareSelectDef.h>
#import <ZoomUnit/ZMShareSelectSegmentObject.h>
#import <ZoomUnit/ZMShareSelectWindowModelGroup.h>
NS_ASSUME_NONNULL_BEGIN

@class ZPShareSelectWindowModel;
@class ZMSharePaddingMgr;
@class ZMZAppShareScreenInfo;

typedef NS_ENUM(NSInteger, ZMShareSelectOptionsDesign) {
    ZMShareSelectOptionsDesign_Linear,
    ZMShareSelectOptionsDesign_Parallel
};

@protocol ZMShareSelectWindowDelegate <NSObject>

@property (assign) BOOL isShareAudioOnForVideoShare;
@property (assign) BOOL isShareVideoOnForVideoShare;
@property (readonly) BOOL isShareAudioEnabledForVideoShare;
@property (readonly) BOOL isShareVideoEnabledForVideoShare;
@property (readonly) BOOL hasShareSoundToBOFeature;

@optional
//control action
- (void)onSegmentSelected:(NSUInteger)selectedIndex;
- (void)onStartShare:(NSArray<ZPShareSelectWindowModel *> * )selectedItems
             options:(ZMShareSelectOptions *)options;
- (void)onStartCollaborate:(nullable NSString *)appId;

- (void)onShowZoomWindowCheckBoxClicked:(NSControlStateValue)state;
- (void)onShowToolbarCheckBoxClicked:(NSControlStateValue)state;
- (void)onHideRepeatWindowCheckBoxClicked:(NSControlStateValue)state;

- (void)onShowWatermarkCheckBoxClicked:(NSControlStateValue)state;
- (void)onShowWatermarkCheckBoxStateChanged:(NSControlStateValue)state;

- (BOOL)isShareVideoOnForClipsShare;

//item state
- (void)onItemSelected:(ZPShareSelectWindowModel *)item;
- (void)onItemSelectByInputEvent:(ZPShareSelectWindowModel *)item;

//window state
- (void)onStandardCloseButtonClicked;
- (void)selectWindowWillClose;
- (void)shareSelectWindowShow;
- (void)selectWindowDidPerformClose;//todo:discard
//holdkey tip && segment tip
- (void)selectTipBannerClosed:(ZMShareSelectBannerType)type;
//audio option
- (void)onAudioMoreMenuClicked:(ZPShareSelectWindowModel *)model menuTag:(NSInteger)menuTag;
- (NSNumber *)audioMoreMenuSelectedStatus:(ZPShareSelectWindowModel *)model;
//sidepanel
- (void)sidePanelStatusChanged;

//Zapp
- (BOOL)isAppCollaborateEnable:(NSString *)appId;
- (void)onShareButtonClick;
- (BOOL)isShareFilterSwitchEnabled;

//watermark
- (BOOL)canShowWatermarkOption;
- (BOOL)canEditWatermarkOption;
@end

@interface ZMShareSelectWindow : /*ZMInvisibleWindow*/NSPanel

@property (nonatomic, weak, nullable) ZMSharePaddingMgr* paddingMgr;
@property (nonatomic, weak, nullable) id<ZMShareSelectWindowDelegate> wndDelegate;
//segment
//trigger onSegmentSelected every time
@property (nonatomic, retain, nullable) NSArray<ZMShareSelectSegmentObject *> *segmentObjects;
//default value is 0
@property (nonatomic, assign) NSUInteger segmentSelectedIndex;
@property (nonatomic, readonly, nullable) ZMShareSelectSegmentObject *currentSegment;
@property (nonatomic, assign) BOOL segmentHidden;
@property (nonatomic, assign) NSInteger desiredWindowLevel;
//collection
@property (nonatomic, retain, nullable) NSArray<ZMShareSelectWindowModelGroup *> *collectionViewContent;
@property (nonatomic, readonly, nullable) NSArray<ZPShareSelectWindowModel *> *collectionViewAllModels;
@property (nonatomic, retain, nullable) NSSet<NSIndexPath *> *collectionViewSelectedIndexPaths;
@property (nonatomic, readonly, nullable) NSArray<ZPShareSelectWindowModel *> *collectionViewSelectedItems;
//options
@property (nonatomic, assign) BOOL supportShareOptions;//for remote support
@property (nonatomic, assign) BOOL audioShareDefaultOn;
@property (nonatomic, assign, getter = isAudioShareHidden) BOOL audioShareHidden;
@property (nonatomic, assign) BOOL videoShareDefaultOn;
@property (nonatomic, assign, getter = isVideoShareHidden) BOOL videoShareHidden;
@property (nonatomic, assign) BOOL boShareDefaultOn;
@property (nonatomic, assign) BOOL audioShareDefaultEnabled;
@property (nonatomic, assign) BOOL videoShareDefaultEnabled;
@property (nonatomic, assign) BOOL audioMoreButtonHidden;
@property (nonatomic, assign) BOOL boCheckButtonHidden;
@property (nonatomic, assign) BOOL showZoomWindowDefaultEnabled;
@property (nonatomic, assign) BOOL showToolBarDefaultEnabled;
@property (nonatomic, assign) BOOL hideRepeatWindowDefaultEnabled;
@property (nonatomic, assign) BOOL showWatermark;

//options - full HD & high fps
@property (nonatomic, assign) BOOL supportVideoQualityOption;
@property (nonatomic, assign) ZMShareSelectVideoQuality defaultVideoQualityOption;
@property (nonatomic, assign) BOOL supportFullHD;
//button
@property (nonatomic, copy, nullable) NSString *shareButtonTitle;
@property (nonatomic, assign) BOOL collaborateButtonHidden;
// customize string
@property (nonatomic, copy, nullable) NSString *audioShareCheckBoxTitle;
@property (nonatomic, copy, nullable) NSString *videoShareCheckBoxTitle;
//multi select
@property (nonatomic, assign) BOOL allowMultiSelect;
@property (nonatomic, assign) NSUInteger maxMultiSelectDesktop;
@property (nonatomic, assign) BOOL supportMultiSelectDesktop;
//multi select - tip
@property (nonatomic, assign) BOOL holdKeyTipAppShareHidden;
@property (nonatomic, assign) BOOL holdKeyTipDesktopShareHidden;
//layouts
@property (nonatomic, assign) BOOL expandedLayouts;
@property (nonatomic, weak, nullable) NSView *expandedLayoutsView;
@property (nonatomic, assign) BOOL sidePanelExpanded;
@property (nonatomic, assign) BOOL supportLayoutsExpand;
//banner
@property (nonatomic, assign, readonly) BOOL segmentBannerEverShown;

- (instancetype)initWithLayoutsEditView:(NSView *)layoutsEditView;//new layouts UI

/// init share select window support two options design and layouts edit view.
/// - Parameters:
///   - optionDesign: options design like linear or parallel
///   - layoutsEditView: layouts Edit View for choose layout and wallpaper
- (instancetype)initWithOptionsDesign:(ZMShareSelectOptionsDesign)optionDesign
                      layoutsEditView:(nullable NSView *)layoutsEditView;
- (void)closeSidePanelAnimation;
- (void)showSidePanelAnimation;
- (void)showWithPostion:(NSPoint)position;
- (void)invisibleInSharing;
- (void)switchNormalWindowLevel:(BOOL)bNormal;

- (void)updateCheckBoxForZapp:(ZMZAppShareScreenInfo *)shareInfo;
- (void)setCollaborateBGBtnEnable:(BOOL)enable;

- (void)bindCollectionOverlayView:(NSView *)overlayView segmentId:(NSUInteger)segmentId;
- (void)unbindCollectionOverlayView:(NSUInteger)segmentId;

- (void)updateCheckBox;
@end

NS_ASSUME_NONNULL_END
