//
//  ZMViewProviding.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMViewProviding_h
#define ZMViewProviding_h

#import <Prism/ZMPlainBlock.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMViewProviding <NSObject> //deprecated

- (nullable NSView *)view;

@property (readonly) ZMViewVisibility viewAppear;
@property (readonly) ZMViewVisibility viewDisappear;

- (void)effectiveAppearanceDidChange:(NSAppearance *)appearance; //NS_REQUIRES_SUPER

- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow; //NS_REQUIRES_SUPER
- (void)viewDidMoveToWindow; //NS_REQUIRES_SUPER
- (void)viewWillMoveToSuperview:(nullable NSView *)newSuperview; //NS_REQUIRES_SUPER
- (void)viewDidMoveToSuperview; //NS_REQUIRES_SUPER;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMViewProviding_h */
