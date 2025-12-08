//
//  ZMUser+SmartTag.h
//  VideoUI
//
//  Created by Devl on 7/30/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTNameTag : NSObject <NSCopying>
@property (nonatomic, assign) BOOL isValid;
@property (nonatomic, copy) NSString *templateid;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *pronouns;
@property (nonatomic, copy) NSColor *textColor;
@property (nonatomic, copy) NSColor *backgroundColor;
@property (nonatomic, copy) NSColor *accentColor;
+ (instancetype)nameTag:(CmmUserNameTag)cmmNameTag;
- (BOOL)isNotNone;
@end

@interface ZMUser (NameTag)
@property(nullable, readonly) ZMMTNameTag *nameTag;
@end

NS_ASSUME_NONNULL_END
