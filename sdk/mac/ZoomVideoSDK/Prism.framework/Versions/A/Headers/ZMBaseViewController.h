//
//  ZMBaseViewController.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/2/8.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import <Prism/ZMViewProviding.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseViewController : NSViewController <ZMViewProviding>

@property (readonly, class, nonatomic) Class viewClass;

@property (readonly, getter=isViewLoaded) BOOL viewLoaded;
@property (readonly, getter=isViewAppeared) BOOL viewAppeared;

///only [self.view isKindOfClass:ZMBaseView.class] == YES can receive this callback
- (void)effectiveAppearanceDidChange:(NSAppearance *)appearance NS_REQUIRES_SUPER;

- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;
- (void)viewWillMoveToSuperview:(nullable NSView *)newSuperview NS_REQUIRES_SUPER;
- (void)viewDidMoveToSuperview NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
