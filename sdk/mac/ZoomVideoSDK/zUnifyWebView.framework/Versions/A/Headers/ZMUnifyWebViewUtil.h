//
//  ZMUnifyWebViewUtil.h
//  zUnifyWebView
//
//  Created by Jax Wu on 2024/1/16.
//

#import <Cocoa/Cocoa.h>

@class ZMUnifyLocalPathInfo;

@interface ZMUnifyWebViewUtil : NSObject

+ (BOOL)isEnableWebViewContextMenu;
+ (BOOL)isEnableOsrWebViewContextMenu;

+ (NSString *)disableServiceWorkerJSCode;
+ (NSString *)checkSoundJSCode;
+ (NSString *)getFilterAllowDomains:(NSArray *)allowedDomains ifDomain:(NSString *)ifDomain customSchemes:(NSArray<NSString *>*)customSchemes;
+ (NSString *)getLocalHostFilterDomain:(NSArray *)localAllowedDomains customSchemes:(NSArray<NSString *>*)customSchemes;
+ (NSString *)getBlockListFilter:(NSArray *)disallowedDomains;

+ (void)removeCookieAndLocalStorageFolderForIdentity:(NSString *)appIdentity;
+ (void)deleteWebCacheFolders;
+ (BOOL)isJSCallSrcURLInvalid:(NSURL *)srcURL;

+ (NSString *)getCommonInjectJSString:(BOOL)isCef;
+ (NSDictionary *)getInjectJSCommonSysPra:(BOOL)isCef;
+ (NSDictionary *)getHTTPCommonHeader;
+ (NSString *)webviewVisibilityChangeJSCode:(BOOL)isHidden;
+ (NSString *)computerWakeStatusChangeJSCode:(BOOL)isSleep;
+ (NSString *)themeModeChangedEventJSCode;
+ (NSString *)getInjectFullscreenObserverJSCode;
+ (NSString*)getWebviewZoomFactorChangedJSCode:(int)zoomFactor;

+ (BOOL)safeRemoveItemAtPath:(NSString *)path error:(NSError **)error;

+ (NSString*)getUrlFromLocalPath:(ZMUnifyLocalPathInfo *)pathInfo;
+ (NSString*)getLocalFile:(NSString *)urlString localPathInfo:(ZMUnifyLocalPathInfo*)pathInfo;
+ (NSString *)getFilePathFrom:(NSString *)url;
+ (BOOL)isRelativePath:(NSString *)urlStr;

+ (NSString *)urlToMIME:(NSURL *)url;

+ (NSString *)getWebKitVersionInUse;
+ (NSString *)getCEFVersionInUseWithPath:(NSString *)path;
+ (NSString *)getOriginalUserAgent:(BOOL)isCEF;
+ (NSString*)getThemeMode;
+ (uint32_t)getWebViewBackgroundColor;

+ (NSString*)getLanguageForCookie;
+ (NSString*)getHostForCookie:(NSString*)urlHost;
+ (NSString *)getDownloadFilePathWithFolder:(NSString *)downloadFolder suggestedName:(NSString *)fileName;

+ (NSString*)getCookieFolder;
+ (NSString*)getPersistCookieFolder;
+ (NSString*)getLocalStorageFolder;

+ (NSScreen *)currentScreenForMouse;
+ (BOOL)isRectValidOnScreen:(NSRect)rect;
+ (NSRect)constrainRectToVisibleScreen:(NSRect)rect;

+ (BOOL)getIntegerValue:(NSInteger*)value with:(id)paramValue;
+ (BOOL)getBoolValue:(BOOL*)value with:(id)paramValue;
+ (NSString *)getStringValueWith:(id)paramValue;
+ (NSArray *)getArrayValueWith:(id)paramValue;

+ (NSString*)getInjectDebugFrame:(NSString*)htmlBodyStr;

+ (BOOL)isProductionRun;
@end
