//
//  ZMUnifyWebDataStoreHelper.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/12/4.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "ZMUnifyWebViewDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMUnifyWebDataStoreHelper : NSObject

//
+ (WKWebsiteDataStore *)dafaultDataStore;
+ (WKWebsiteDataStore *)nonPersistentDataStore;

+ (WKWebsiteDataStore *)storePermanentlyWith:(NSString *)identify;

//
+ (ZMUnifyWebDataStoreHelper *)shareInstance;
//
- (WKWebsiteDataStore *)dataStoreWith:(ZMUnifyWebViewConfiguration *)config;
- (WKWebsiteDataStore *)generateDataStoreWith:(NSString *)identity;
// Clear Cache
- (void)clearAllWebCaches;
- (void)clearWebCacheForIdentity:(NSString *)identity;
- (void)clearAllWebCachesByAppId:(NSString *)appId;
- (void)removeDataStore:(NSString *)identity;
- (void)removeCefCacheForAppId:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
