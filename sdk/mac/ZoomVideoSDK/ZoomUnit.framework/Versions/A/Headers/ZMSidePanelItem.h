//
//  ZMSidePanelItem.h
//  ZoomUnit
//
//  Created by Jun Pang on 4/12/22.
//

/// The priority of the position in side panel, only works in ZMSidePanelShared mode
/// Prioritizes list shared view if ZMSidePanelShared mode. The lower the number, the closer to the top.
#define InSidePanelFlowMode 0
#define InSidePanelTop 10
#define InSidePanelMiddle 40
#define InSidePanelBottom 60

/// Sidepanel view modes.
///
/// ZMSidePanelExclusive will exclusively show module in sidepanel. Will not share view with any other modules.
///
/// ZMSidePanelShared will share view with pre-existing module.
typedef NS_ENUM(NSInteger, ZMSidePanelViewMode) {
    ZMSidePanelExclusive,
    ZMSidePanelShared,
};

/// Sidepanel window action modes.
///
/// None mode indicates that status is null
///
/// EnterFullScreen mode indicates that the window is Enter Full Screen
///
/// ExitFullScreen mode indicates that the window is Exiting Full Screen
///
/// EnterSilentMode indicates that the window is entering waiting room
///
/// ExiteSilentMode indicates the window is exiting waiting room
///
/// OrderFront mode indicates the window is ordered in front.
///
/// OrderOut mode indicates the window is ordered out.
typedef NS_ENUM(NSInteger, ZMSidePanelWindowAction) {
    ZMSidePanelWindowAction_None,
    ZMSidePanelWindowAction_EnterFullScreen,
    ZMSidePanelWindowAction_ExitFullScreen,
    ZMSidePanelWindowAction_EnterSilentMode,
    ZMSidePanelWindowAction_ExiteSilentMode,
    ZMSidePanelWindowAction_OrderFront,
    ZMSidePanelWindowAction_OrderOut,
};

NS_ASSUME_NONNULL_BEGIN
@class NSView;
@protocol ZMSidePanelItem <NSObject>

/// sidePanelMode should indicate whether exclusive or shared.
@property (nonatomic, assign) ZMSidePanelViewMode sidePanelMode;
/// The main content view of the sidepanel.
///
/// Not optional to implement. Should be based off NSView.
@property (nonatomic, nullable, strong) __kindof NSView* contentView;

@property (assign) NSInteger sizePriority;//1~499, default 300
@property (assign) NSInteger resizePriority;//1~499, default 300
@property (nonatomic, strong) ZMSizeScaleFactor* scaleFactor;

@property (nonatomic, strong) ZMPigment* backgroundPigment;
@optional

/// Head section of module in sidepanel.
///
/// If not implemented, will use a default headView. If set to nil, there will be no head view. Override to customize headView. Should be based off NSView.
@property (nonatomic, nullable, strong) __kindof NSView* headView;
///  Bool value to determine if module uses auto layout. Default value is YES.
@property (nonatomic, assign) BOOL useAutoLayout;


/// Value for height of head view
@property (nonatomic, assign) CGFloat headViewHeight;
/// Minimum size of view
@property (nonatomic, assign) NSSize minimumSize;
/// Maximum size of view
@property (nonatomic, assign) NSSize maximumSize;

/// Using in ZMSidePanelShared mode. If not implement: will not check this value. If side panel's view count >= maxNumSharedView, will change this view to ZMSidePanelExclusive mode to show.
@property (nonatomic, assign) NSInteger maxNumSharedView;

/// Using in ZMSidePanelShared mode. If not implement, this view will be set in the bottom of side panel. Otherwise, side panel will arrange the views from lower orderPriority to larger orderPriority.
@property (nonatomic, assign) NSInteger orderPriority;

/// Boolean value determining whether side panel view is minimized.
@property (nonatomic, assign) BOOL isMiniaturized;

#pragma mark - notification
/// Refers to item added in to the side panel
- (void)onItemAddedInSidePanel;

/// Refers to item removed from the side panel
- (void)onItemRemovedFromSidePanel;

#pragma mark - for using default head
/// 1. if not implement, not provide a default head name. 2. Set nil: no default head name
@property (nonatomic, nullable, copy) NSString* defaultHeadName;
/// Close item in side panel
- (void)close:(id)sender;

/// Minimize item in side panel to only show head name
- (void)miniaturize:(id)sender;

/// Deminimize item in side panel
- (void)deminiaturize:(id)sender;

/// Creates pop up in side panel
- (void)popup:(id)sender;

/// Collapse item view in side panel
- (void)collapse:(id)sender;

/// Expand item view in side panel
- (void)expand:(id)sender;

/// Back ups the changes in the side panel item before closing
- (void)backup:(id)sender action:(ZMSidePanelWindowAction)action;

/// Restores previous changes in the side panel item when reopening
- (void)restore:(id)sender action:(ZMSidePanelWindowAction)action;

- (void)onSomeItemsMiniaturized;
- (void)onSomeItemsRemoved;
@end

@interface ZMSidePanelItem : NSObject<ZMSidePanelItem>
@end

NS_ASSUME_NONNULL_END
