//
//  IZMFitBar.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2023/12/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMFitBar <ZMRoutableObject>

@property (nonatomic, assign) ZMMTType parentViewControllerType;

- (id)initWithAttachedWindow:(NSWindow *)inAttachedWindow;
- (void)cleanUp;
- (BOOL)canAttachStatusWnd;
- (void)attachStatusWnd;
- (void)attachStatusWnd:(NSWindow *)attachedWindow;
- (void)detachStatusWnd;

- (void)showStatusWnd;
- (void)hideStatusWnd;

- (BOOL)isStatusWndVisible;

- (void)updatePositionByParentWnd;
- (void)updateStatusWndLevel;

- (void)updateUI;
@end

@protocol IZMDocFitBar <IZMFitBar>

@end

NS_ASSUME_NONNULL_END
