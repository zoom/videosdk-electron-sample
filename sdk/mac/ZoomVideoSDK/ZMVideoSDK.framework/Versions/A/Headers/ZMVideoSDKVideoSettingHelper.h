//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMVideoSDKVideoSettingHelper : NSObject

/**
 @brief Call this method to enable or disable temporal video denoising. This process reduces noise between frames of video.
 @param enable YES to enable the temporal de-noise of video. NO to disable it.
 @return If the function succeeds, the return value is ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableTemporalDeNoise:(BOOL)enable;

/**
 @brief Query if the option to optimize video quality with de-noise is enabled.
 @return YES if temporal video denoising is enabled, otherwise NO.
 */
-(BOOL)isTemporalDeNoiseEnabled;
@end

NS_ASSUME_NONNULL_END
