//
//  ZMBandWidthInfo.h
//  zVideoUI
//
//  Created by francis zhuo on 2019/7/8.
//  Copyright © 2019 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
//ZOOM-82229
@protocol ZMBandWidthInfo <NSObject>
@property(readonly) BOOL isEnableBandWidthLimit;
@property(readonly) NSInteger bandWidthLimitUp;
@property(readonly) NSInteger bandWidthLimitDown;
@property(readonly) BOOL isLimitSendVideo;
@property(readonly) BOOL isLimitReceiveVideo;
@end

@interface ZMBandWidthInfo : NSObject<ZMBandWidthInfo>
@property(readwrite) BOOL isEnableBandWidthLimit;
@property(readwrite) NSInteger bandWidthLimitUp;
@property(readwrite) NSInteger bandWidthLimitDown;
@property(readwrite) BOOL isLimitSendVideo;
@property(readwrite) BOOL isLimitReceiveVideo;
@end

NS_ASSUME_NONNULL_END
