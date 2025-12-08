//
//  NSString+ZoomUint.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/6/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ZoomUnit)

@property (readonly) BOOL isSvgImageExist;

- (NSString*)appendQueryParameter:(NSString*)queryParameter;

@end

NS_ASSUME_NONNULL_END
