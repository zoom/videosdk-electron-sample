

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKDef.h>

NS_ASSUME_NONNULL_BEGIN
/**
 @brief Test audio device interface.
 */
@interface ZMVideoSDKAudioDeviceTestHelper : NSObject
/**
 @brief Start the microphone test. This will start recording the input from the mic. Once the recording is complete, stopMicTestRecording must be called to finish the recording.
 @param deviceID Specify to test a microphone device. If the param is a wrong microphone ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected.
 The SDK will test the default device if no parameter is input.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)startMicTestRecording:(NSString *)deviceID;
    
/**
 @brief Stop the microphone test. Before calling this, you must have successfully started the microphone test by calling startMicTestRecording. Otherwise this returns an error.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)stopMicTestRecording;
    
/**
 @brief Play the microphone recorded sound. You must complete a microphone test by successfully executing startMicTestRecording and stopMicTestRecording before calling this. Otherwise this returns an error.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)playMicTestRecording;

/**
 @brief Start the speaker test.
 @param deviceID Specify to test a speaker device. If the param is a wrong speaker ID, the SDK will return an error. Otherwise the SDK tests the specified device and sets it as selected.
 The SDK will test the default device if no parameter is input.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)startSpeakerTest:(nullable NSString *)deviceID;
    
/**
 @brief Stop the speaker test. Before calling this, you must have successfully started the speaker test by calling startSpeakerTest. Otherwise this returns an error.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)stopSpeakerTest;
    
/**
 @brief Set the time interval for the audio test.
 @param timerInterval Usually the SDK sends the mic and speaker volumes every 200 ms by default via onMicSpeakerVolumeChanged:(unsigned int)micVolume speakerVolume:. With this function, the user can modify the time interval instead of 200, default is 200 ms.
 Accepted values between 50 to 1000 milliseconds.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 @note This interface will stop the mic or speaker test (if there is on ongoing). As a best practice, call it before the audio test.
 */
-(ZMVideoSDKErrors)setTimerInterval:(unsigned int)timerInterval;
@end

/**
 @brief Audio helper interface.
 */
@interface ZMVideoSDKAudioSettingHelper : NSObject
    
/**
 @brief Get the suppress background noise level.
 @param level The suppress background noise level.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)getSuppressBackgroundNoiseLevel:(ZMVideoSDKSuppressBackgroundNoiseLevel*)level;
    
/**
 @brief Set the suppress background noise level.
 @param level The suppress background noise level.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)setSuppressBackgroundNoiseLevel:(ZMVideoSDKSuppressBackgroundNoiseLevel)level;
    
/**
 @brief Call this method to enable or disable the original input of mic.
 @param bEnable YES to enable the original input of the microphone or NO to disable it.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableMicOriginalInput:(BOOL)bEnable;
    
/**
 @brief Determine whether the original input of the microphone is enabled.
 @param bEnable YES means enabled.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)isMicOriginalInputEnable:(BOOL*)bEnable;
    
/**
 @brief Set whether to enable the function of high fidelity music mode or not.
 @param bEnable YES means to enable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableHighFidelityMusicMode:(BOOL)bEnable;

/**
 @brief Check whether the high fidelity music mode is enabled or not.
 @param bEnable YES means enabled.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)isHighFidelityMusicModeEnable:(BOOL*)bEnable;

/**
 @brief Set whether to disable the function of echo cancellation or not.
 @param bEnable YES means to enable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableEchoCancellation:(BOOL)bEnable;

/**
 @brief Check whether the echo cancellation is enabled or not.
 @param bEnable YES means enabled.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)isEchoCancellationEnable:(BOOL*)bEnable;

/**
 @brief Set whether to enable stereo audio.
 @param bEnable YES means to enable.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableStereoAudio:(BOOL)bEnable;

/**
 @brief Check whether the stereo audio is enabled or not.
 @param bEnable YES means enabled.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)isStereoAudioEnable:(BOOL*)bEnable;

/**
 @brief Get the echo cancellation level.
 @param level The echo cancellation level.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)getEchoCancellationLevel:(ZMVideoSDKEchoCancellationLevel*)level;

/**
 @brief Set the echo cancellation level.
 @param level The echo cancellation level to be set.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)setEchoCancellationLevel:(ZMVideoSDKEchoCancellationLevel)level;

/**
 @brief Call this method to enable or disable the auto adjust input of microphone volume.
 @param bEnable True to enable auto adjust input or false to disable it.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)enableAutoAdjustMicVolume:(BOOL)bEnable;

/**
 @brief Determine whether the original input of the microphone volume is enabled.
 @param bEnable YES means enabled, otherwise NO.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)isAutoAdjustMicVolumeEnabled:(BOOL*)bEnable;

@end

NS_ASSUME_NONNULL_END
