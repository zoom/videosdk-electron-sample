//
//  ZPBundleHelper.h
//  SaasBeePTUIModule
//
//  Created by sanshi on 11-12-8.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZPBundleHelper : NSObject

+ (void)setParentBundlePath:(nullable NSString *)bundlePath;
+ (nullable NSString *)getParentBundlePath;
+ (NSString *)zoomPrivateFrameworksPath;
/// return the zoom client bundle
+ (nullable NSBundle *)zoomBundle;
/// return the Bundle Name like zoom.us
+ (nullable NSString *)zoomBundleName;
/// return the path like ~/Library/Application Support/zoom.us
+ (nullable NSString *)zoomApplicationSupportPath;
/// return the path like ~/Library/Application Support/zoom.us/Plugins
+ (nullable NSString *)zoomPluginsPath;
/// return the path like ~/Library/Application Support/zoom.us/Plugins/Frameworks
+ (nullable NSString *)zoomPluginsFrameworksPath;
/// return the path like ~/Library/Application Support/zoom.us/data/image
+ (nullable NSString *)zoomDataImagePath;
+ (NSBundle *)resBundle;
+ (NSString *)resBundlePath;
+ (NSString *)resBundlePathForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (NSString *)mainResBundlePathForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (nullable NSImage *)resBundleImageForResource:(NSString *)resName ofType:(NSString *)typeName;
+ (nullable NSImage *)getAvatarByPath:(NSString*)inPath;
+ (BOOL)removeAvatarByPath:(NSString*)inPath;//ZOOM-123364

+ (nullable NSImage *)getImageByName:(NSString*)resName;//[Zoom-33534]

+ (NSString *)resolveImagePath:(NSString *)imagePath;
+ (NSString* _Nonnull)localizedString:(NSString * _Nonnull)theKey;
+ (NSString* _Nonnull)localizedString:(NSString * _Nonnull)theKey bundle:(NSBundle *)bundle extraEnbundle:(NSBundle *)extraEnbundle;
//+ (NSString* _Nonnull)localizedString:(NSString * _Nonnull)theKey value:(NSString* _Nonnull)value bundle:(NSBundle *)bundle;
+ (NSString* _Nonnull)localizedString:(NSString * _Nonnull)theKey value:(NSString* _Nonnull)value;
+ (void)cleanUp;
+ (NSString*)localizedEnString:(NSString *)theKey value:(NSString*)value;


/**
 Use +hasValidZoomCodeSignWithPath:completion: instead. You should not call this function in main thread!
 
 If you call this function in main thread, it will return NO after Client 5.17.0
 */
+ (BOOL)hasValidZoomCodeSign:(NSString*)path;
+ (BOOL)hasValidZoomCodeSign:(NSString*)path needValidateResources:(BOOL)needValidate;

+ (void)hasValidZoomCodeSignWithPath:(NSString *)path completion:(void (^)(BOOL result))completion; // ZOOM-455387
+ (void)hasValidZoomCodeSignWithPath:(NSString *)path needValidateResources:(BOOL)needValidate completion:(void (^)(BOOL result))completion;

+ (void)hasValidZoomCodeSignWithPathArray:(NSArray *)pathArray completion:(void (^)(BOOL result))completion;
+ (void)hasValidZoomCodeSignWithPathArray:(NSArray *)pathArray needValidateResources:(BOOL)needValidate completion:(void (^)(BOOL result))completion;



+ (NSString *)getCodeSignTeamIdentifer;
+ (NSString *)getCodeSignAuthority;

+ (nullable NSString *)getBundleVersion:(NSString *)bundlePath;
+ (BOOL)needDownloadWithLatestVersion:(NSString*)inLatestVersion currentVersion:(NSString*)inCurrentVersion;

+ (BOOL)isRunningOnArm64;
+ (BOOL)isBuildForArm64;
+ (BOOL)isDevApp;

+ (nullable NSURL *)URLForImageName:(NSString *)imageName;

+ (NSString *)getCodesignTeamIdentifer;
+ (NSString *)getCodesignAuthority;

+ (NSBundle*)retinaImageBundle;

@end

NS_ASSUME_NONNULL_END
