//
//  ZMSVGMgr.h
//  ZMImageRes
//
//  Created by francis zhuo on 11/12/2019.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PZMSvgElement, NSBezierPath;

NS_ASSUME_NONNULL_BEGIN

@interface PZMSVGMgr : NSObject

+ (nonnull instancetype)sharedMgr;
- (void)registerResBundleName:(NSString *)bundleName;
- (void)registerParentBundlePath:(NSString *)parentBundlePath;
- (void)registerPluginsFrameworksPath:(NSString *)pluginsFrameworksPath;
- (nonnull instancetype)parserWithFileURL:(NSURL*_Nonnull)fileURL;
- (nullable NSImage*)imageForIdentifier:(NSString*_Nonnull)imageName;
- (nullable NSImage*)imageForIdentifier:(NSString*_Nonnull)imageName scale:(CGFloat)scale;
- (nullable PZMSvgElement *)svgElementForIdentifier:(nonnull NSString *)identifier;
- (nullable NSBezierPath *)firstPathForIdentifier:(NSString *)imageName scale:(CGFloat)scale;
- (nullable NSImage*)imageName:(NSString*_Nonnull)imageName;
- (nullable NSImage*)imageName:(NSString*_Nonnull)imageName bundle:(NSString *_Nonnull)bundle;
- (nullable NSImage*)imageName:(NSString*_Nonnull)imageName scale:(CGFloat)scale;
- (nullable NSImage*)imageName:(NSString*_Nonnull)imageName scale:(CGFloat)scale bundle:(NSString *_Nonnull)bundle;
- (BOOL)isImageExist:(NSString* _Nonnull)imageName;
- (BOOL)hasParsed:(NSString *)imageName;

@end
@compatibility_alias ZMSVGMgr PZMSVGMgr;
NS_ASSUME_NONNULL_END
