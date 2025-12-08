//
//  ZMAvatarHelper.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 2/13/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
NSString* const kZMDefaultUserAvatar = @"Avatar_Default";
NSString* const kZMDefaultAppAvatar = @"zapp_logo_zoom";

@interface ZMAvatarHelper : NSObject

+ (void)cleanUp;
+ (instancetype)shared;

- (NSImage*)getAvatarByPath:(NSString*)path hasDownloaded:(BOOL)bDownloaded;//will return default avatar if not exist
- (NSImage*)getOriginalAvatarByPath:(NSString*)path hasDownloaded:(BOOL)bDownloaded;
- (BOOL)resetUserAvatarByUser:(ICmmUser *)user;//ZOOM-123364

+ (NSImage *)activePureCallImage;
+ (NSImage *)normalPureCallImage;
+ (NSImage *)h323Image;
+ (NSImage *)zoomRoomImage;
+ (NSImage *)defaultAvatarImage;


#pragma mark - Get display avatar
- (NSImage*)getUploadAvatarByUser:(ICmmUser*)theUser isAvatarAllowed:(BOOL)isAvatarAllowed constrainSize:(NSSize)inSize;

- (NSImage*)getDisplayAvatarByUser:(ICmmUser*)theUser constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayAvatarByUser:(ICmmUser*)theUser isAvatarAllowed:(BOOL)isAvatarAllowed constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayAvatarByUser:(ICmmUser*)theUser isAvatarAllowed:(BOOL)isAvatarAllowed constrainSize:(NSSize)inSize generateWithNameIfNeed:(BOOL)needed;

- (NSImage*)getDisplayAvatarByUserName:(NSString*)userName constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayIconByApp:(ICmmConfAppItem*)appItem constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayAvatarByUserId:(int)inUserId constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayAvatarByJid:(NSString*)inUserJid constrainSize:(NSSize)inSize;
- (NSImage*)getAvatarByKey:(NSString*)key constrainSize:(NSSize)inSize;
- (NSImage*)getAvatarByInviteeItem:(NS_ZOOM_DATA::ConfInviteeItem *)inviteeItem constrainSize:(NSSize)inSize;
- (NSImage*)getDisplayAvatarByPath:(NSString*)path constrainSize:(NSSize)inSize;
@end
