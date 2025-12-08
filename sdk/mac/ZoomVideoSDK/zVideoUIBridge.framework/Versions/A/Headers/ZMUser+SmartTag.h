//
//  ZMUser+SmartTag.h
//  VideoUI
//
//  Created by Devl on 7/30/24.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTSmartTag : NSObject <NSCopying>
@property (nonatomic, assign) ZMUserID userID;
@property (nonatomic, assign) ZMUserID companionID;
@property (nonatomic, assign) int tagID;

@property (nonatomic, assign) BOOL isActive;
@property (nonatomic, assign) SmartNameTagAlignment alignment;
@property (nonatomic, assign) float positionX;  //0~1
@property (nonatomic, assign) float positionY;  //0~1

@property (nonatomic, copy) NSString *tagJid;
@property (nonatomic, copy) NSString *tagName;
@property (nonatomic, copy) NSString *tagAvatar;
@property (nonatomic, copy) NSString *tagShortName;
@property (nonatomic, readonly) BOOL isPositionValid;
@property (nonatomic, readonly) BOOL isCompanionBinded;
@end

@interface ZMUser (SmartTag)
- (nullable NSString *)activeSpeakerName;
- (nullable NSArray<ZMMTSmartTag*> *)smartTagArray;
- (BOOL)hasSmartTag:(BOOL)checkPos;
- (BOOL)hasSmartTagBinded;

- (BOOL)isAble2ShowSmartTag:(CGFloat)width inVideo:(BOOL)inVideo;

@end

NS_ASSUME_NONNULL_END
