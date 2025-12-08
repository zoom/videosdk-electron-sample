//
//  ZMMTModuleProtocol.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 6/1/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTModuleProtocol <NSObject>
- (void)launchModule;
@optional
- (void)willTermModule;
- (void)termModule;
@end

NS_ASSUME_NONNULL_END
