//
//  ZMToolSuitePTUIAction.h
//  VideoUI
//
//  Created by Peter Xu on 2024/4/3.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMToolSuitePTUIAppInfo : NSObject

@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *targetURLStr;
@property (nonatomic, assign) BOOL isSupportTransfer2ZR;

@end

@interface ZMToolSuitePTUIWBInfo : NSObject

@property (nonatomic, copy) NSString *whiteBoardId;
@property (nonatomic, copy) NSString *whiteBoardName;
@property (nonatomic, assign) BOOL isWhiteBoardDetailPage;

@end

NS_ASSUME_NONNULL_END
