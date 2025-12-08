//
//  ZMMTShareWatermarkOptions.h
//  VideoUIBridge
//
//  Created by Molay Yu on 2025/7/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTShareWatermarkOption : NSObject

@property (nonatomic, strong, nullable) NSNumber *showWatermark;
@property (nonatomic, strong, nullable) NSNumber *isOptionOn;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
