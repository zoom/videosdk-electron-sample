//
//  ZMBaseTableCellView.h
//  zChatUI
//
//  Created by groot.ding on 2018/5/8.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMPigment.h>

@interface ZMBaseTableRowView : NSTableRowView

@end


@interface ZMBaseTableCellView : NSTableCellView

@property (nonatomic,assign) NSEdgeInsets selectedEdgeInset;

@property (nonatomic,assign) CGFloat selectedRadius;

@property (nonatomic,strong) NSColor *fullFillBackgroundColor;

@property (nonatomic,strong) NSColor *backgroundColor;

@property (nonatomic,strong) NSColor *selectedBackgroundColor;

@property (nonatomic,strong) NSColor *inactiveSelectedBackgroundColor;

@property (nonatomic,strong) NSColor *hoverSelectedBackgroundColor;

@property(getter=isSelected) BOOL selected;

@property(getter=isHoverSelected) BOOL hoverSelected;

@property(nonatomic,assign) BOOL ignoreSelected;

@property(nonatomic,assign) BOOL ignoreHoverSelected;

@property(nonatomic,assign) BOOL animationEnable;

@property(nonatomic,assign) CGFloat animationDuration;

@property (nonatomic, retain, nullable) id<ZMTableCellViewPigmentProtocol> pigment;

- (NSColor *)currentBackgroudColor;

- (void)updateUI;

- (void)updateUIForSelected:(ZMBaseTableCellView*)selected;

- (void)backgroundColorDidChange;

- (NSBezierPath *)getSelectedAreaBezierPath;

@end
