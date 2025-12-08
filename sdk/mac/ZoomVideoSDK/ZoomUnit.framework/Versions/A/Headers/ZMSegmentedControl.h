//
//  ZMSegmentedView.h
//  ZMSegmentedView
//
//  Created by Huxley on 2018/3/28.
//  Copyright © 2018 Huxley. All rights reserved.
//

#import <Zoomkit/ZoomKit.h>
#import <AppKit/AppKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_OPTIONS(NSUInteger, ZMSegmentedViewItemLayout) {
    ZMSegmentedViewItemLayoutEqual = 1 << 0,
    ZMSegmentedViewItemLayoutSizeToFit = 1 << 1,
    ZMSegmentedViewItemLayoutEqualToFittedSize = 1 << 2,
};

@interface ZMSegmentedItem : NSObject

@property (nullable, copy) NSString *label;
@property (nullable, copy) NSString *accessibilitylabel;
@property (nullable, copy) NSString *badge;
@property (nullable, retain) NSImage *image;
@property (nullable, retain) NSImage *alternateImage;
@property (nonatomic, nullable, retain) NSColor *normalTextColor;
@property (nonatomic, nullable, retain) NSColor *selectedTextColor;
@property (nullable, retain) NSColor *disableTextColor;
@property (weak) id target;
@property NSInteger tag;
@property SEL action;

@property (nonatomic) BOOL hidden;
@property (nonatomic) BOOL disable;
@property (nullable, copy) NSString *tooltip;
@property (nullable, copy) NSString *defaultTooltip;
@property (nullable, copy) NSAttributedString *attributedTooltip;
@property (nullable, copy) NSString *link;

@end

typedef NS_ENUM(NSUInteger, ZMSegmentedControlStyle) {
    ZMSegmentedControlNormal,
    ZMSegmentedControlText,
};

@interface ZMSegmentedControl : ZMBaseView
{
    CGFloat _satisfiedItemWidth;
    BOOL _highlight;
}

@property (nonatomic) IBInspectable NSUInteger count;//set this property will recreate items
@property (copy,nullable) NSArray <ZMSegmentedItem *> *items;
@property (nonatomic, retain, nullable) IBInspectable NSColor* foregroundColor;
@property (nonatomic, assign) CGFloat foregroundPadding;
@property (nonatomic, readonly) CGColorRef cgForegroundColor;
@property (copy, null_resettable, nonatomic) NSFont *preferredfont;

@property (weak, nullable) IBOutlet id target;
@property (nullable) SEL action;

@property (assign) ZMSegmentedControlStyle style;
@property (nonatomic, assign) BOOL showToolTipIfNoSpace;

- (nullable ZMSegmentedItem *)itemAtIndex:(NSUInteger)index;

@property (readonly) ZMSegmentedItem *selectedItem;
@property (assign, nonatomic) NSUInteger selectedIndex;//won't trigger Action
@property (assign, nonatomic) NSUInteger selectedTag;

- (NSUInteger)indexWithTag:(NSUInteger)tag;
- (void)selectItemAtIndex:(NSUInteger)index;//will trigger Action
- (void)selectItemWithTag:(NSUInteger)tag;// will trigger action

- (void)setLabel:(nullable NSString *)label forItemAtIndex:(NSInteger)index;
- (void)setBadge:(nullable NSString *)badge forItemAtIndex:(NSInteger)index;
- (void)setImage:(nullable NSImage *)image alternateImage:(nullable NSImage *)alternateImage forItemAtIndex:(NSInteger)index;
- (void)setToolTips:(nullable NSString *)tooltips forItemTag:(NSInteger)tag;


- (void)setAccessibilityLabel:(nullable NSString *)label forItemAtIndex:(NSInteger)index;

- (void)relayout;//relayout immediately
- (void)sizeToFit;//No need when uses Auto Layout

- (void)setLabel:(nullable NSString *)label tagForItem:(NSUInteger)tag forItemAtIndex:(NSInteger)index;
- (void)setImage:(nullable NSImage *)image alternateImage:(nullable NSImage *)alternateImage tagForItem:(NSUInteger)tag forItemAtIndex:(NSInteger)index;
- (void)setBadge:(NSString *)badge forItemTag:(NSInteger)tag;

- (void)setRedPointForItemAtIndex:(NSInteger)index;
- (void)setRedPointForItemTag:(NSInteger)tag;
- (void)setIsEnabled:(BOOL)isEnable;

- (void)speakSelectedItem;
@end
NS_ASSUME_NONNULL_END
