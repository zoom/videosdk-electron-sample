//
//  NSBundle+ZoomKit.h
//  ZCommonUI
//
//  Created by Francis Zhuo on 4/15/21.
//  Copyright © 2021 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (localize)

+ (nullable NSBundle *)getBundleWithBundleName:(NSString *)bundle;
+ (nullable NSBundle *)getCurrentLanguageBundleWithMainBundle:(NSBundle *)bundle;

@end

@interface NSBundle (ZoomKit)
+ (BOOL)loadBundleWithComponentName:(NSString*)componentName;
+ (BOOL)loadBundleWithComponentName:(NSString*)componentName checkVersion:(BOOL)check;
+ (BOOL)loadBundleWithComponentName:(NSString*)componentName checkVersion:(BOOL)check outBundle:(NSBundle*_Nullable*_Nullable)outBundle;
+ (BOOL)loadFrameworkBundleWithComponentName:(NSString*)componentName outBundle:(NSBundle*_Nullable*_Nullable)outBundle;
+ (void)loadOnDemandBundleWithComponentName:(NSString*)componentName checkVersion:(BOOL)check completion:(void (^)(BOOL result))completion;

+ (nullable NSBundle *)getBundleWithComponentName:(NSString *)componentName checkVersion:(BOOL)check;

@end

NS_ASSUME_NONNULL_END

