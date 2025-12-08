//
//  IZMDeviceProtocol.h
//  ZoomUnit
//
//  Created by Javenlee.Li on 2024/8/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMDeviceProtocol <NSObject>
@optional
- (void)onDeviceStatusChanged:(int)deviceCmd param:(unsigned int)value handle:(unsigned int)handle;
- (void)onAudioLevelChanged:(unsigned int)level handle:(unsigned int)handle isMic:(BOOL)isMic;
- (void)onAudioDeviceSpecialInfoChange:(unsigned int)special_info type:(unsigned int)device_type transport:(unsigned int)transport_type;

@end

NS_ASSUME_NONNULL_END
