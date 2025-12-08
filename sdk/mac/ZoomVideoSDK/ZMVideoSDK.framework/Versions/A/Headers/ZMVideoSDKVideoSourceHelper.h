/**
 * @file ZMVideoSDKVideoSourceHelper.h
 * @brief Provides interfaces for custom video source integration in Zoom Video SDK.
 */

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZMVideoSDKYUVProcessDataI420
 * @brief Represents I420 YUV raw data and its metadata for preprocessing.
 */
@interface ZMVideoSDKYUVProcessDataI420 : NSObject

/**
 * @brief Get the stream width.
 */
@property (nonatomic, assign, readonly) unsigned int width;

/**
 * @brief Get the stream height.
 */
@property (nonatomic, assign, readonly) unsigned int height;

/**
 * @brief Get the Y stride.
 */
@property (nonatomic, assign, readonly) unsigned int yStride;

/**
 * @brief Get the U stride.
 */
@property (nonatomic, assign, readonly) unsigned int uStride;

/**
 * @brief Get the V stride.
 */
@property (nonatomic, assign, readonly) unsigned int vStride;

/**
 * @brief Get the video raw data rotation.
 */
@property (nonatomic, assign, readonly) unsigned int rotation;

/**
 * @brief Determine if video raw data is limited.
 */
@property (nonatomic, assign, readonly) BOOL isLimitedI420;

/**
 * @brief Get the YUVI420 Y buffer.
 * @param lineNum The Y component represents the luma or brightness value of the color.
 * @return Y buffer.
 */
- (char* _Nullable)getYBuffer:(unsigned int)lineNum;

/**
 * @brief Get the YUVI420 U.
 * @param lineNum The U component represents the chroma value.
 * @return U buffer.
 */
- (char* _Nullable)getUBuffer:(unsigned int)lineNum;

/**
 * @brief Get the YUVI420 V buffer.
 * @param lineNum The V component represents the chroma value.
 * @return V buffer.
 */
- (char* _Nullable)getVBuffer:(unsigned int)lineNum;
@end


/**
 * @protocol ZMVideoSDKVideoSourcePreProcessor
 * @brief Protocol to receive raw video frames for preprocessing before sending.
 */
@protocol ZMVideoSDKVideoSourcePreProcessor <NSObject>

/**
 * @brief Callback on device capture video frame.
 * @param rawData It is a pointer of YUV process data I420 object.
 */
- (void)onPreProcessRawData:(ZMVideoSDKYUVProcessDataI420*)rawData;
@end

/**
 * @class ZMVideoSDKVideoSender
 * @brief Interface for sending custom raw video data to the Zoom Video SDK.
 */
@interface ZMVideoSDKVideoSender : NSObject

/**
 * @brief For user to send video raw data.
 * @param frameBuffer YUVI420 buffer.
 * @param width The width of buffer size.
 * @param height The height of buffer size.
 * @param frameLength The lenght of buffer.
 * @param rotation The rotation of buffer.
 * @param format Raw data format.
 */
- (void)sendVideoFrame:(char*)frameBuffer width:(int)width height:(int)height frameLength:(int)frameLength rotation:(int)rotation format:(ZMVideoSDKFrameDataFormat)format;
@end

/**
 * @class ZMVideoSDKVideoCapability
 * @brief Represents the video resolution, frame rate, and data mode capabilities.
 */
@interface ZMVideoSDKVideoCapability : NSObject
/**
 * @brief Width of video capability.
 */
@property(nonatomic, assign) int width;

/**
 * @brief Height of video capability.
 */
@property(nonatomic, assign) int height;

/**
 * @brief Frame of video capability.
 */
@property(nonatomic, assign) int frame;

/**
 * @brief Video source data mode.
 */
@property(nonatomic, assign) ZMVideoSDKVideoSourceDataMode dataMode;
@end

/**
 * @protocol ZMVideoSDKVideoSource
 * @brief Protocol defining lifecycle events for a custom video source.
 */
@protocol ZMVideoSDKVideoSource <NSObject>

/**
 * @brief Notify when video source prepare.
 * @param sender The pointer of video sender object.
 * @param supportedCapList The list of supported video capability.
 * @param suggestCap Suggest video capability.
 */
- (void)onInitialize:(ZMVideoSDKVideoSender*)sender supportedCapbilityList:(NSArray<ZMVideoSDKVideoCapability *>*)supportedCapList suggestCapbility:(ZMVideoSDKVideoCapability*)suggestCap;

/**
 * @brief Notify when video size or fps changed.
 * @param supportedCapList The list of supported video capability.
 * @param suggestCap Suggest video capability.
 */
- (void)onPropertyChange:(NSArray<ZMVideoSDKVideoCapability *>*)supportedCapList suggestCapbility:(ZMVideoSDKVideoCapability*)suggestCap;

/**
 * @brief Notify when video start send raw data.
 */
- (void)onStartSend;

/**
 * @brief Notify when video stop send raw data.
 */
- (void)onStopSend;

/**
 * @brief Notify when video source uninitialized.
 */
- (void)onUninitialized;
@end
NS_ASSUME_NONNULL_END
