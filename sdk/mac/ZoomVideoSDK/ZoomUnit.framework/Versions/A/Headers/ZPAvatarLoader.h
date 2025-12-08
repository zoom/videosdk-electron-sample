//
//  ZPAvatarLoader.h
//  SaasBeePTUIModule
//
//  Created by sanshi on 12-02-06.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString * const ZPAvatarLoadedNotification;


@interface ZPAvatarLoader : NSObject 

//+ (NSImage *)roundedImage:(NSString *)imagePath radius:(int)theRadius;
+ (NSImage *)normalImage:(NSString *)imagePath;

+ (NSString *)resolveImagePath:(NSString *)imagePath;

+ (NSString *)defaultAvatarPath;

+ (NSImage *)defaultAvatarImage;

+ (NSImage*)imageWithPath:(NSString*)imagePath;

+ (BOOL)checkImageUpdate:(NSString *)imagePath;

+ (BOOL)checkAvatarPicture:(NSString *)avatarPictureFullPath isSameAs:(NSString *)imagePath;

+ (void)cleanUpAllCache;

@end
