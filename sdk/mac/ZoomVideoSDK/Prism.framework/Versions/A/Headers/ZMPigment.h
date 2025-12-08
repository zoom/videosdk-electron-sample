//
//  ZMPigment.h
//  VideoUI
//
//  Created by Francis Zhuo on 2024/1/6.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Prism/ZMNSRectCorner.h>
#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMGradient : NSObject
/* The array of NSColor objects defining the color of each gradient stop.
 */
@property(nullable, strong) NSArray<NSColor*>* colors;

/* An optional array of NSNumber objects defining the location of each
 * gradient stop as a value in the range [0,1]. The values must be
 * monotonically increasing. If a nil array is given, the stops are
 * assumed to spread uniformly across the [0,1] range. When rendered,
 * the colors are mapped to the output colorspace before being
 * interpolated. Defaults to nil. Animatable. */
@property(nullable, strong) NSArray<NSNumber*>* locations;

/* The start and end points of the gradient when drawn into the layer's
 * coordinate space. The start point corresponds to the first gradient
 * stop, the end point to the last gradient stop. Both points are
 * defined in a unit coordinate space that is then mapped to the
 * layer's bounds rectangle when drawn. (I.e. [0,0] is the bottom-left
 * corner of the layer, [1,1] is the top-right corner.) The default values
 * are [.5,0] and [.5,1] respectively. Both are animatable. */
@property CGPoint startPoint;
@property CGPoint endPoint;

- (NSArray*)cgColors;
- (CGPoint)startPointForFlipped:(BOOL)isFlipped;
- (CGPoint)endPointForFlipped:(BOOL)isFlipped;
@end

@interface ZMPigment : NSObject<NSCopying>
@property(nonatomic, nullable, strong) NSColor* color;
@property(nullable, strong) NSImage* image;
@property(nullable, strong) ZMGradient* gradient;

@property(assign) CGFloat borderWidth;
@property(nullable, strong) NSColor* borderColor;
@property(assign) BOOL masksToBounds;

@property(assign) CGFloat cornerRadius;
@property(assign) NSRectCorner cornerMask;

- (void)setPigment:(nullable ZMPigment*)pigment;

@property(readonly) NSColor* appearanceColor;
@end


@interface NSView(ZMPigment)
@property(nonatomic, retain)CAGradientLayer* zmGradientLayer;

- (void)updateLayerWithPigment:(ZMPigment*)content;
@end

typedef void(^ZMBackgroundDrawer)(NSRect bounds);

@protocol ZMButtonPigmentProtocol <NSObject>
@required


@property(nonatomic, assign) BOOL matchImageColorWithTitle;

@property(nonatomic, retain, nullable) NSImage* image;
@property(nonatomic, retain, nullable) NSImage* normalImage;
@property(nonatomic, retain, nullable) NSImage* hoverImage;
@property(nonatomic, retain, nullable) NSImage* pressImage;
@property(nonatomic, retain, nullable) NSImage* selectImage;
@property(nonatomic, retain, nullable) NSImage* disableImage;

@property(copy, nullable) ZMBackgroundDrawer backgroundDrawer;
@property(copy, nullable) ZMBackgroundDrawer normalBackgroundDrawer;
@property(copy, nullable) ZMBackgroundDrawer hoverBackgroundDrawer;
@property(copy, nullable) ZMBackgroundDrawer pressBackgroundDrawer;
@property(copy, nullable) ZMBackgroundDrawer selectBackgroundDrawer;
@property(copy, nullable) ZMBackgroundDrawer disableBackgroundDrawer;

@property(nonatomic, retain, nullable) NSImage* backgroundImage;
@property(nonatomic, retain, nullable) NSImage* normalBackgroundImage;
@property(nonatomic, retain, nullable) NSImage* hoverBackgroundImage;
@property(nonatomic, retain, nullable) NSImage* pressBackgroundImage;
@property(nonatomic, retain, nullable) NSImage* selectBackgroundImage;
@property(nonatomic, retain, nullable) NSImage* disableBackgroundImage;

@property(nonatomic, retain, nullable) NSColor* backgroundColor;
@property(nonatomic, retain, nullable) NSColor* normalBackgroundColor;
@property(nonatomic, retain, nullable) NSColor* hoverBackgroundColor;
@property(nonatomic, retain, nullable) NSColor* pressBackgoundColor;
@property(nonatomic, retain, nullable) NSColor* selectBackgroundColor;
@property(nonatomic, retain, nullable) NSColor* disableBackgroundColor;
@property(nonatomic, retain, nullable) NSColor* selectedHoverBackgroundColor;

@property(nonatomic, retain, nullable) NSColor* titleColor;
@property(nonatomic, retain, nullable) NSColor* normalTitleColor;
@property(nonatomic, retain, nullable) NSColor* hoverTitleColor;
@property(nonatomic, retain, nullable) NSColor* pressTitleColor;
@property(nonatomic, retain, nullable) NSColor* selectTitleColor;
@property(nonatomic, retain, nullable) NSColor* disableTitleColor;

@property(nonatomic, retain, nullable) NSColor* borderColor;
@property(nonatomic, retain, nullable) NSColor* normalBorderColor;
@property(nonatomic, retain, nullable) NSColor* hoverBorderColor;
@property(nonatomic, retain, nullable) NSColor* pressBorderColor;
@property(nonatomic, retain, nullable) NSColor* selectBorderColor;
@property(nonatomic, retain, nullable) NSColor* disableBorderColor;

@property(nonatomic, strong, nullable) NSColor* unreadColor;
@end

@protocol ZMTableCellViewPigmentProtocol <NSObject>
@required
@property (nonatomic,strong,nullable) NSColor *fullFillBackgroundColor;
@property (nonatomic,strong,nullable) NSColor *backgroundColor;
@property (nonatomic,strong,nullable) NSColor *selectedBackgroundColor;
@property (nonatomic,strong,nullable) NSColor *inactiveSelectedBackgroundColor;
@property (nonatomic,strong,nullable) NSColor *hoverSelectedBackgroundColor;

@end

NS_ASSUME_NONNULL_END
