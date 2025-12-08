//
//  ZMBaseHelper.h
//  VideoUI
//
//  Created by javenlee.li on 2021/11/13.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMConfSession;

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseHelper : NSObject

@property (nonatomic, copy) NSString* identifier;
@property (nonatomic, weak) ZMConfSession *confSession;

+ (instancetype)helperWithIdentifier:(NSString *)identifier;
- (void)commonInit NS_REQUIRES_SUPER;
@end

NS_ASSUME_NONNULL_END
