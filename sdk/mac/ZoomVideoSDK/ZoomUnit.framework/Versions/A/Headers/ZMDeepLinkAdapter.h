//
//  ZMDeepLinkAdapter.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/9/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDeepLinkAdapter: NSObject

+ (BOOL)checkAndHandleZoomInternalNavigateURLAction:(NSString *)url;

+ (void)openOnlineLink:(NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
