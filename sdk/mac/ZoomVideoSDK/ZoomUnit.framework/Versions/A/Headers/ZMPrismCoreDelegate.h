//
//  ZMPrismCoreDelegate.h
//  ZoomUnit
//
//  Created by Felipe Bastos on 7/19/24.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPrismCoreDelegate : NSObject<PrismCoreDelegate>

+ (void)start;

+ (void)registerStringLocalizationFor:(NSString * _Nonnull)string
                      localizationKey:(NSString * _Nonnull)localizationKey
                        localizeBlock:(NSString * _Nonnull (^_Nullable)(NSString * _Nonnull key))localize;

@end

NS_ASSUME_NONNULL_END
