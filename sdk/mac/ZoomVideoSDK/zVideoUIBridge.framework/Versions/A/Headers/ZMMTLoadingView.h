//
//  ZMMTLoadingView.h
//  VideoUI
//
//  Created by Devl on 2022/7/20.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTLoadingConfig : NSObject

@property (nonatomic, assign) CGFloat width;
@property (nonatomic, retain, nullable) NSImage *image;
@property (nonatomic, retain, nullable) NSColor *backgroundColor;

@end

@interface ZMMTLoadingView : ZMBaseView

+ (instancetype)viewWithConfig:(nullable ZMMTLoadingConfig*)config; //default: 16.0f, blue
+ (instancetype)viewWithWidth:(CGFloat)width;
 
@end

NS_ASSUME_NONNULL_END
