//
//  ZMIMOnlyImageButton.h
//  zChatUI
//
//  Created by ryan on 12/06/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMIMBaseButton : PZMRichKeyButton

@property (assign) BOOL entered;
@property (assign) BOOL isHandleMouseEvent;
@property (copy, nullable) NSString* customTooltip;

@property (nonatomic,assign) NSSize zmIntrinsicContentSize;
@property(nonatomic, assign, nullable) SEL hoverAction;
@property(nonatomic, assign, nullable) SEL zmMouseExitedEvent;

@property (assign) BOOL opaqueWhenDisabled;

@property(nonatomic, assign) BOOL delaySendHoverAction;

@end

@interface ZMIMOnlyImageButton : ZMIMBaseButton

@property (assign) NSEdgeInsets edgeInsets;

@property (nonatomic,assign) float radius;

@property (nonatomic,assign) BOOL isChecked;
@property (nonatomic,assign) BOOL ignoreTab;

@property (nonatomic,retain, nullable) NSImage* hoverImage;
@property (nonatomic,retain, nullable) NSImage* disableImage;

@property (nonatomic, assign) BOOL matchImageColorWithTitle;

@property (nonatomic, retain,nullable) id<ZMButtonPigmentProtocol> pigment;

@property (nonatomic,copy,nullable) NSColor* backgroundColor;
@property (nonatomic,copy,nullable) NSColor* normalBackgroundColor;
@property (nonatomic,copy,nullable) NSColor* hoverBackgroundColor;
@property (nonatomic,copy,nullable) NSColor* highlightBackgroundColor;
@property (nonatomic,copy,nullable) NSColor* disabledBackgroundColor;
@property (nonatomic,copy,nullable) NSColor* borderColor;
@property (nonatomic,copy,nullable) NSColor* hoverBorderColor;
@property (nonatomic,copy,nullable) NSColor* pressBorderColor;
@property (nonatomic,copy,nullable) NSColor* disabledBorderColor;
@property (nonatomic,copy,nullable) NSString* zmAccessibilityLabel;
@property (nonatomic,copy,nullable) NSString* zmAccessibilityRoleDescription;
@property (nonatomic,assign) NSRect zmAccessibilityFrame;

@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, copy,nullable) NSColor* textColor;
@property (nonatomic, copy,nullable) NSColor* textHoverColor;
@property (nonatomic, copy,nullable) NSColor* textHighlightColor;
@property (nonatomic, copy,nullable) NSColor* textDisableColor;

@property (nonatomic,retain,nullable) NSImageView *imageView;

@property (retain, nullable) id representedObject;

- (NSSize)fitSize;

@end

NS_ASSUME_NONNULL_END
