//
//  ZMPkgAuthHelper.h
//  ZoomKit
//
//  Created by Feder Huang on 2022/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPkgAuthHelper : NSObject

+ (BOOL)isPkgCodesignValidForPathSync:(NSString *)pkgPath;
+ (void)verifyPkgCodesignValidityForPathAsync:(NSString *)pkgPath completion:(void (^)(BOOL isValid))completion;
@end

NS_ASSUME_NONNULL_END
