//
//  ZMBaseView.h
//  zChatUI
//
//  Created by Huxley on 2018/3/29.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Prism/ZMViewProviding.h>
#import <Prism/ZMAccessibleView.h>
#import <Prism/ZMPigment.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseView : ZMAccessibleView

- (void)commonInit;//!< to override

@property (nonatomic, nullable, copy) IBInspectable NSColor *zmBackgroundColor;



@property (nonatomic) BOOL needsRelayout;//logic like needsDisplay
- (void)relayout;//call this will force relayout

@property (weak, nullable) id <ZMViewProviding> controller;
- (void)viewWillMoveToWindow:(nullable NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;

@property (getter=isFlipped) BOOL flipped;

@property (nonatomic, assign) BOOL shouldAcceptsFirstMouseEvent;
@property (assign)BOOL ignoreViewLiftCircleWhenMoveToWindow;//default is NO, for 10.9

@property (nonatomic, nullable) CGColorRef cgBackgroundColor;
@property (nonatomic) IBInspectable CGFloat cornerRadius;
@property (nonatomic) IBInspectable CGFloat borderWidth;
@property (nonatomic, nullable, copy) IBInspectable NSColor *borderColor;
@property (nonatomic, nullable) CGColorRef cgBorderColor;
@property (nonatomic, assign) NSRectCorner cornerMask;
@property (nonatomic, nullable, retain) ZMPigment* pigment;
@property (nonatomic, assign) BOOL ignoreEffectiveChange;
@end

@interface ZMNonLayerBaseView : ZMBaseView
@end

NS_ASSUME_NONNULL_END
