//
//  ZMTipPlane.h
//  zVideoUI
//
//  Created by javenlee on 2020/07/12.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/IZMConfTipMgr.h>

NS_ASSUME_NONNULL_BEGIN

#define TIPNORMALHEIGHT 44
#define TipMaxWidth 570

@protocol ZMTipNotificationProtocol <NSObject>

- (void)closeTipWindowWithIdentifier:(NSString*)tipIdentifier fadeoutAnimation:(BOOL)fadeoutAnimation;

@end

@interface ZMTipNotification : NSObject <ZMMTTipNotification>

@property (nonatomic, assign) BOOL manualClose;
@property (nonatomic, assign) BOOL transformIfNeed;
@property (nonatomic, assign) BOOL flashUpdate;
@property (nonatomic, assign) BOOL announcement;
@property (nonatomic, assign) NSTimeInterval announcementDelay;
@property (nonatomic, assign) BOOL rotateAnimation;
@property (nonatomic, assign) BOOL fadeoutAnimation;//default is YES
@property (nonatomic, assign) BOOL supportSilentMode;
@property (nonatomic, assign) CGFloat outTiming;//if outTiming == 0, will not auto close
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSAttributedString *attributedTitle;
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *actionButtonTitle;
@property (nonatomic, strong) void(^actionButtonConfigBlock)(ZMButton *actionButton);
@property (nonatomic, strong) NSString *otherButtonTitle;
@property (nonatomic, strong) NSString *actionTitle;
@property (nonatomic, strong) NSString *openHelpAccessibilitySuffix;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock actionButtonResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock otherButtonResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock clickContentResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock closeResponse;
@property (nonatomic, copy) ZMMTTipNotificationResponseBlock actionTitleResponse;
@property (nonatomic, strong, nullable) NSImage *contentImage;
@property (nonatomic, strong, nullable) NSURL *contentImageURL;
@property (nonatomic, weak) id <ZMZappNotificationDelegate> notiDelegate;

@property (nonatomic, assign) ZMTipType tipType;

+ (id)notification;
@end

@protocol ZMMTTipPanelProtocol <NSObject>
@property (nonatomic, strong) id<ZMMTTipNotification> tip;

- (void)setTip:(id<ZMMTTipNotification>)tip tipMgr:(id<ZMTipNotificationProtocol>)mgr;
- (void)updateUI;
- (NSString*)accessibilityLabel;
- (void)windowWillAddToParent:(NSWindow*)window;
@end

@interface ZMTipPanel : NSPanel <ZMMTTipPanelProtocol>
@property (nonatomic, strong) id<ZMMTTipNotification> tip;

+ (id)tipPanelWithTip:(id<ZMMTTipNotification>)tip tipMgr:(id<ZMTipNotificationProtocol>)mgr;
@end


@interface ZMBubbleTip : ZMTipNotification

@property (nonatomic, strong) NSString *btnString;
@property (nonatomic, strong) NSString *tooltipString;
@property (nonatomic, strong, nullable) NSImage *btnImage;
@property (nonatomic, assign) NSRectEdge tipPreferredEdge; // Default is NSMinYEdge
@end

@interface ZMBubbleTipPanel : ZMTipPanel

@end

typedef void(^ZMMTNoticeBannerActionBlock)(ZMButton *sender, BOOL *shouldClose);
typedef void(^ZMMTNoticeBannerConfigBlock)(ZMButton *aButton);

@interface ZMMTNoticeBannerActionItem : NSObject
@property (nonatomic, copy, nullable) __kindof NSView *(^actionViewConstructor)(void);
@property (nonatomic, copy, nullable) void(^windowWidthDidUpdate)(__kindof NSView *actionView, CGFloat newWidth);
@end

@interface ZMMTNoticeBannerButtonItem : ZMMTNoticeBannerActionItem
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) BOOL isDefault;
@property (nonatomic, copy, nullable) ZMMTNoticeBannerConfigBlock configBlock;
@property (nonatomic, copy, nullable) ZMMTNoticeBannerActionBlock actionBlock;
@end

@interface ZMMTNoticeBanner : ZMTipNotification
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSAttributedString *attributedDesc;

@property (nonatomic, strong) NSArray<ZMMTNoticeBannerActionItem *> *actionItems;
@end

@interface ZMMTNoticeBannerPanel : NSPanel <ZMMTTipPanelProtocol>
@property (nonatomic, strong) ZMMTNoticeBanner *tip;
@property (nonatomic, assign) CGFloat width;

+ (instancetype)tipPanelWithTip:(id<ZMMTTipNotification>)tip tipMgr:(id<ZMTipNotificationProtocol>)mgr;
@end

NS_ASSUME_NONNULL_END
