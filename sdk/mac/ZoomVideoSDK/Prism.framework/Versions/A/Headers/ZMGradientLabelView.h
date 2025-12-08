//
//  ZMGradientLabelView.h
//  ZoomKit
//
//  Created by Felipe Bastos on 2/11/22.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMLabel.h>
#import <Prism/ZMBaseView.h>
#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

enum {
    ZMGradientLabelViewCorner_TopLeft,
    ZMGradientLabelViewCorner_TopRight,
    ZMGradientLabelViewCorner_BottomLeft,
    ZMGradientLabelViewCorner_BottomRight,
};
typedef NSNumber ZMGradientLabelViewCornerStyle;

@interface ZMGradientLabelView : ZMBaseView

@property (nonatomic, strong,nullable) ZMLabel *label;
@property (nonatomic, strong,nullable) CAGradientLayer *gradientLayer;
@property (nonatomic) BOOL isHover;
@property (nonatomic, strong,nullable) NSColor *labelColor;
@property (nonatomic, strong, nullable) NSColor *hoverLabelColor;

+ (instancetype)viewWithString:(NSString *_Nonnull)str leftColor:(NSColor *_Nonnull)leftColor rightColor:(NSColor *_Nonnull)rightColor fontSize:(NSUInteger)fontSize;
+ (instancetype)viewWithString:(NSString *_Nonnull)str leftColor:(NSColor *_Nonnull)leftColor rightColor:(NSColor *_Nonnull)rightColor fontSize:(NSUInteger)fontSize andCornerRadius:(NSUInteger)radius;
+ (instancetype)viewWithString:(NSString *_Nonnull)str leftColor:(NSColor *_Nonnull)leftColor rightColor:(NSColor *_Nonnull)rightColor fontSize:(NSUInteger)fontSize andRoundedCorners:(NSDictionary<ZMGradientLabelViewCornerStyle *, NSNumber *>*)corners;

- (void)didToggleHover;
- (void)setHover:(BOOL)isHovered;
- (void)setGradientLeftColor:(NSColor *_Nonnull)leftColor andRightColor:(NSColor *_Nonnull)rightColor;
- (void)setHoverGradientLeftColor:(NSColor *_Nonnull)leftColor andRightColor:(NSColor *_Nonnull)rightColor;

@end

NS_ASSUME_NONNULL_END
