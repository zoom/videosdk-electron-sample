

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMVideoSDKVideoCanvas : NSObject
/**
 @brief The canvas type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKCanvasType canvasType;

/**
 @brief Subscribes to video or share data.
 @param view The NSView object, needed to render video or share.
 @param aspect The aspect ratio of the video or share.
 @param resolution Specified the resolution of video. valid only for subscribe video.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)subscribeWithView:(NSView * _Nonnull)view aspectMode:(ZMVideoSDKVideoAspect)aspect resolution:(ZMVideoSDKResolution)resolution;

/**
 @brief Unsubscribes to video or share data.
 @param view The NSView object, needed to render video or share.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unSubscribeWithView:(NSView * _Nonnull)view;

/**
 @brief Sets the video or share aspect mode.
 @param view The NSView object, needed to render video or share.
 @param aspect The aspect ratio of the video or share.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setAspectMode:(NSView* _Nonnull)view aspect:(ZMVideoSDKVideoAspect)aspect;

/**
 @brief Sets the resolution.
 @param view The NSView object, needed to render video.
 @param resolution The resolution of the video.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 @warning Avaliable only for subscribe video, unavaliable for subscribe sharing.
 */
- (ZMVideoSDKErrors)setResolution:(NSView* _Nonnull)view resolution:(ZMVideoSDKResolution)resolution;
@end
NS_ASSUME_NONNULL_END
