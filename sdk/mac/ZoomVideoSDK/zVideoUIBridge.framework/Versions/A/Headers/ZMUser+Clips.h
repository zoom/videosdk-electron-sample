//
//  ZMUser+Clips.h
//  VideoUIBridge
//
//  Created by Michael Lin on 2025/4/9.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMUser (Clips)

- (NSMutableArray<NSNumber *> *)getClipsGwUserList;
- (BOOL)isSharingClips;
- (BOOL)isClipsUser;
- (ZMUserID)getClipsOwner;
- (UInt64)totalDuration;

@end

NS_ASSUME_NONNULL_END
