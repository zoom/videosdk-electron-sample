//
//  ZMMTBadgeView.h
//  VideoUI
//
//  Created by  Devl on 5/18/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTBadgeConfig : NSObject

/// If backgroundColor is set, leftColor and rightColor will be ignored
@property (nonatomic, strong, nullable) NSColor *backgroundColor;

/// Currently only work when backgroundColor is set
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, strong) NSColor *borderColor;

@property (nonatomic, strong, nullable) NSColor *leftColor;
@property (nonatomic, strong, nullable) NSColor *rightColor;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, copy) NSString *badgeTxt;
@property (nonatomic, strong) NSColor *badgeTxtColor;
@property (nonatomic, strong) NSFont *badgeFont;
@property (nonatomic) BOOL useCustomizedCornerRadius;
@property (nonatomic) ZMRectCornerRadius customizedCornerRadius;

+ (instancetype)smallConfig;// "NEW", 16f
+ (instancetype)defaultConfig;// "NEW", 20f
+ (instancetype)blueNewConfig;// "NEW", 18f
+ (instancetype)lightNewConfig;// "NEW", 18f light
+ (instancetype)freeTrialConfig;// "Free trial", 16f
+ (nullable instancetype)configWithBadgeTxt:(NSString *)badgeTxt; // badgeTxt, 16f

@end

@interface ZMMTBadgeView : NSView

+ (instancetype)viewWithConfig:(ZMMTBadgeConfig *)config;
@end

NS_ASSUME_NONNULL_END
