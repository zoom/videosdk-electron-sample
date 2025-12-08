//
//  ZMTableViewUtilCellView.h
//  zChatUI
//
//  Created by groot.ding on 2018/11/7.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZMBaseTableCellView.h>

typedef enum : NSUInteger {
    ZMUtilCellViewTextOnly = 1,
    ZMUtilCellViewLoadingAnimationOnly,
    ZMUtilCellViewLoadingTextBottom
} ZMUtilCellViewStyle;

@protocol ZMTableViewUtilProtocal <NSObject>

@optional
- (NSString *)title;

- (NSFont *)titleFont;
- (NSColor *)titleColor;
- (NSTextAlignment)titleAlignment;
- (NSAttributedString *)attributedTitle;
- (NSImage*)imageWithIsSelected:(BOOL)isSelected;
- (BOOL)needSplitLine;

- (NSEdgeInsets)contentEdgeInsets;
- (NSEdgeInsets)splitLineEdgeInsets;

- (ZMUtilCellViewStyle)cellViewStyle;

- (NSAttributedString *)attributedTitleWithState:(BOOL)isHighlight;
@end

@interface ZMTableViewUtilInfo : NSObject <ZMTableViewUtilProtocal>

@property (nonatomic,strong) NSFont *titleFont;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,strong) NSColor *titleColor;

@property (nonatomic,strong) NSAttributedString *attributedTitle;

@property (nonatomic,assign) NSTextAlignment titleAlignment;

@property (nonatomic,assign) BOOL needSplitLine;

@property (nonatomic,assign) NSEdgeInsets contentEdgeInsets;
@property (nonatomic,assign) NSEdgeInsets splitLineEdgeInsets;

@property (nonatomic,assign) ZMUtilCellViewStyle cellViewStyle;

+ (instancetype)utilWithStyle:(ZMUtilCellViewStyle)style;

- (NSAttributedString *)attributedTitleWithState:(BOOL)isHighlight;

@end

@interface ZMTableViewUtilCellView : ZMBaseTableCellView

+ (CGFloat)heightOfInfo:(id <ZMTableViewUtilProtocal>)info maxWidth:(CGFloat)maxWidth;

@end
