//
//  ZMMTPopOutWindow.h
//  ZoomAppUI
//
//  Created by Neko Chen on 2024/1/31.
//  Copyright © 2024 us.zoom. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTPopOutWindowDelegate <NSObject>

- (void)popInBtnClick;
- (void)closeWindowBtnClick;
- (BOOL)shouldShowPopInBtn;
@optional
- (NSString *)getWindowId;
- (BOOL)canCollaborate;
- (void)windowClose;
- (void)windowDidClose;
- (BOOL)isCurrentAppSharing;
- (BOOL)needHideInShareCtrl;

@end

@interface ZMMTPopOutWindow : NSPanel

@property (nonatomic, weak) id<ZMMTPopOutWindowDelegate> windowDelegate;
- (instancetype)initWithTitle:(NSString *)title windowName:(NSString *)windowName;
- (void)setWindowName:(NSString *)windowName;
- (void)reloadHeader;
- (NSString *)getWindowId;
- (NSNumber *)canCollaborate;
- (NSNumber *)needHideInShareCtrl;

@end

NS_ASSUME_NONNULL_END
