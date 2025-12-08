//
//  ZMMTTrafficLight.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2024/2/21.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTTrafficLightConfig : NSObject
///relative to window top-left corner
@property(assign) NSEdgeInsets padding;//default {8,8,0,0}
@property(assign) CGFloat space;//default 8

+ (instancetype)defaultConfig;
@end

@interface ZMMTTrafficLight : NSStackView
@property (strong, readonly) NSButton *closeButton;//_NSThemeWidget
@property (strong, readonly) NSButton *miniaturizeButton;//
@property (strong, readonly) NSButton *zoomButton;//_NSThemeZoomWidget

@property (null_resettable, strong) ZMMTTrafficLightConfig* layoutConfig;
- (void)relayoutUI;
- (void)redisplayTrafficLight;
@end

@interface NSWindow(TrafficLight)
@property (strong, readonly) NSButton *zmmt_closeButton;//_NSThemeWidget
@property (strong, readonly) NSButton *zmmt_miniaturizeButton;//
@property (strong, readonly) NSButton *zmmt_zoomButton;//_NSThemeZoomWidget
@end

NS_ASSUME_NONNULL_END
