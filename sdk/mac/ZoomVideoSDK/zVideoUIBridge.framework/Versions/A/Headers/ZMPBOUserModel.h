//
//  ZMPBOUserModel.h
//  VideoUI
//
//  Created by Molay.Yu on 2023/3/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPBOUserModel : ZMUser<NSCopying>

@property (nonatomic, assign) NSInteger roomID;

+ (nullable instancetype)pboUserWithIPBOUser:(std::shared_ptr<zm::pbo::IPBOUser>)model;
+ (nullable instancetype)pboUserWithICmmUser:(ICmmUser *)model;

@end

NS_ASSUME_NONNULL_END
