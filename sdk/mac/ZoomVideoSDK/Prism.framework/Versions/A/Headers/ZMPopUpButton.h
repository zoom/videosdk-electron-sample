//
//  ZMPopUpButton.h
//  Test
//
//  Created by Huxley on 11/3/19.
//  Copyright © 2019 Huxley. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMHMenu;
@interface ZMHPopUpButtonCell : NSPopUpButtonCell

@property (retain,nullable) ZMHMenu *hMenu;
@property (nonatomic, retain,nullable) NSColor *borderColor;
@property (nonatomic, retain,nullable) NSColor *titleColor;
@property (nonatomic, copy) void(^drawIndicatorBlock)(NSRect frame, NSView *controlView);
@property IBInspectable CGFloat cornerRadius;

@end

@interface ZMPopUpButton : NSPopUpButton

@property (nonatomic, retain,nullable) NSColor *borderColor;
@property (assign) BOOL stackViewEscape;
/// ZOOM-707645 Scroll to selected when menu pops up to fix rendering bug.
@property (nonatomic, assign) BOOL scrollOnAppear;
@end

NS_ASSUME_NONNULL_END
