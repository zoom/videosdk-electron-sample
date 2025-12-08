//
//  ZMSizeScaleFactor.h
//  VideoUI
//
//  Created by Francis Zhuo on 5/23/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMSizeScaleFactorType){
    ZMSizeScaleFactorTypePercent,
    ZMSizeScaleFactorTypeAbsolute,
};

@interface ZMSizeScaleFactor : NSObject
@property(assign) ZMSizeScaleFactorType type;
@property(assign) CGFloat scaleValue;
@property(assign) CGFloat absoluteValue;
@end
@compatibility_alias ZMMTSizeScaleFactor ZMSizeScaleFactor;
NS_ASSUME_NONNULL_END
