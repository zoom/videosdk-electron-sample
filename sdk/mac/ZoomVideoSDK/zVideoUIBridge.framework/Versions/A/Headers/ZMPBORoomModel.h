//
//  ZMPBORoomModel.h
//  VideoUI
//
//  Created by Molay.Yu on 2023/3/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMPBOUserModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZMPBORoomModel : NSObject

@property (nonatomic, assign) NSInteger roomID;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, assign, readonly) NSInteger index;
@property (nonatomic, assign, readonly) NSInteger userCount;
@property (nonatomic, assign, readonly) BOOL hasUser;
@property (nonatomic, assign, readonly) ZMUserID creatorUniqueJoinIndex;

- (NSArray<ZMPBOUserModel *> *)getUserList;
- (ZMPBOUserModel *)getUserById:(ZMUserID)uniqueJoinIndex;

@end

NS_ASSUME_NONNULL_END
