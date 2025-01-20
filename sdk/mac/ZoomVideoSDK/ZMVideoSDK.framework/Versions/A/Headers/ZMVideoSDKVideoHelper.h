
#import <Foundation/Foundation.h>
#import "ZMVideoSDKUserHelper.h"

NS_ASSUME_NONNULL_BEGIN
/**
 @brief Virtual background Item interface.
 */
@interface ZMVideoSDKVirtualBackgroundItem : NSObject

/**
 @brief Get the current item image file path.
 */
@property (nonatomic, copy, readonly) NSString *imageFilePath;

/**
 @brief Get the current item image name.
 */
@property (nonatomic, copy, readonly) NSString *imageName;

/**
 @brief Get the current item background type.
 */
@property (nonatomic, assign, readonly) ZMVideoSDKVirtualBackgroundDataType type;

/**
 @brief Determine whether the virtual background can be deleted.
 */
@property (nonatomic, assign, readonly) BOOL canVirtualBackgroundBeDeleted;

@end



/**
 @brief Camera device information interface.
 */
@interface ZMVideoSDKCameraDevice : NSObject
/**
 @brief Get the camera's device Id.
 */
@property (nonatomic, copy, readonly) NSString* deviceID;
    
/**
 @brief Get the camera's device name.
 */
@property (nonatomic, copy, readonly) NSString* deviceName;
    
/**
 @brief Determine if the device is selected.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedDevice;

/**
 @brief Determine whether the camera is selected as multiple stream video.
 */
@property (nonatomic, assign, readonly) BOOL isSelectedAsMultiCamera;
    
/**
 @brief Determine whether the camera is running as multiple stream video.
 */
@property (nonatomic, assign, readonly) BOOL isRunningAsMultiCamera;
@end


/**
 @brief Video preference interface. When setting custom modes, the maximum and minimum frame rates are provided by the developer. If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower resolution. The default maximum and minimum frame rates for other modes are 0.
 */
@interface ZMVideoSDKPreferenceSetting : NSObject
/**
 @brief Preferred video mode.
 */
@property (nonatomic, assign, readwrite) ZMVideoSDKVideoPreferenceMode mode;
    
/**
 @brief Minimum frame rate, default is 0.
 @note The value of minimumFrameRate should be less than maximumFrameRate, the value of minimumFrameRate range from 0 to 30. If the frame rate out of range, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int minimumFrameRate;
    
/**
 @brief Maximum frame rate, default is 0.
 @note The value of maximumFrameRate should be less and equal than 30, the value of maximumFrameRate range from 0 to 30. If the frame rate out of range, will use default frame-rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int maximumFrameRate;
@end


/**
 @brief An interface to control video and manage cameras during a video session.
 */
@interface ZMVideoSDKVideoHelper : NSObject
    
/**
 @brief Call this method to start sending local video data from the camera.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startVideo;
    
/**
 @brief Call this method to stop sending local video data from the camera.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopVideo;
    
/**
 @brief Call this method to rotate the video when the device is rotated.
 @param rotation It is emum.
 @return YES means the function is success, otherwise not.
 */
- (BOOL)rotateMyVideo:(ZMVideoRotation)rotation;
    
/**
 @brief Switch to the next available camera.
 @return YES means the function is success, otherwise not.
 */
- (BOOL)switchCamera;
    
/**
 @brief Switch to the camera passed in as cameraDevice.
 @param cameraDeviceID The id of camera.
 @return YES means the function is success, otherwise not.
 */
- (BOOL)selectCamera:(NSString*)cameraDeviceID;
    
/**
 @brief Returns number of cameras available to share the video.
 @return The count of cameras.
 */
- (unsigned int)getNumberOfCameras;
    
/**
 @brief Returns a collection of camera devices available to share the video as an object of type {@link ZMVideoSDKCameraDevice}.
 @return Camera devices list.
 */
- (NSArray<ZMVideoSDKCameraDevice *>* _Nullable)getCameraList;

/**
 @brief Check whether the current user has permission to control the camera.
 @param canControl The output parameter. YES means can control local camera, otherwise not.
 @param deviceID The camera device ID to check. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)canControlCamera:(BOOL *)canControl deviceID:(nullable NSString*)deviceID;

/**
 @brief Pan the camera to the left.
 @param range Rotation range, 10 <= range <= 100.
 @param deviceID The camera device ID to rotate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)turnCameraLeft:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Pan the camera to the right.
 @param range Rotation range, 10 <= range <= 100.
 @param deviceID The camera device ID to rotate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)turnCameraRight:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Tilt the camera up.
 @param range Rotation range, 10 <= range <= 100.
 @param deviceID The camera device ID to rotate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)turnCameraUp:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Tilt the camera down.
 @param range Rotation range, 10 <= range <= 100.
 @param deviceID The camera device ID to rotate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)turnCameraDown:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Zoom the camera in.
 @param range Zoom range, 10 <= range <= 100.
 @param deviceID The camera device ID to operate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)zoomCameraIn:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Zoom the camera out.
 @param range Zoom range, 10 <= range <= 100.
 @param deviceID The camera device ID to operate. The default is the main camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)zoomCameraOut:(unsigned int)range deviceID:(nullable NSString*)deviceID;

/**
 @brief Adjust user's video solution and frame-rate.
 @param preferenceSetting An instance of ZMVideoSDKPreferenceSetting.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
-(ZMVideoSDKErrors)setVideoQualityPreference:(ZMVideoSDKPreferenceSetting*)preferenceSetting;

/**
 @brief Enable multiple stream video if you have multiple cameras, and other participants can see multiple videos of you.
 @param cameraDeviceID The camera ID for the camera to enable.
 @param customDeviceName The custom device name of the camera. If this parameter is not passed, a default name will be generated.
 @return If the function succeeds, it will return YES, otherwise returns NO.
 */
-(BOOL)enableMultiStreamVideo:(NSString *)cameraDeviceID customDeviceName:(nullable NSString *)customDeviceName;

/**
 @brief Disable multiple stream video.
 @param cameraDeviceID The camera id which you want to disable.
 @return If the function succeeds, it will return YES, otherwise returns NO.
 */
-(BOOL)disableMultiStreamVideo:(NSString *)cameraDeviceID;

/**
 @brief Turn off multiple stream video.
 @param cameraDeviceID The camera ID which is running as multiple camera.
 @return If the function succeeds, it will return YES, otherwise returns NO.
 */
-(BOOL)muteMultiStreamVideo:(NSString *)cameraDeviceID;

/**
 @brief Turn on multiple stream video.
 @param cameraDeviceID The camera ID which is running as multiple camera.
 @return If the function succeeds, it will return YES, otherwise returns NO.
 */
-(BOOL)unmuteMultiStreamVideo:(NSString *)cameraDeviceID;
/**
 @brief Get the device ID associated with my multi-camera pipe.
 @param pipe My multi-camera pipe.
 @return The video device ID if successful. Otherwise returns nil.
 */
-(NSString * _Nullable)getDeviceIDByMyPipe:(ZMVideoSDKRawDataPipe *)pipe;
/**
 @brief Subscribe preview video raw data with a callback.
 @param listener The callback sink object.
 @param cameraDeviceID The camera id.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startVideoPreview:(id<ZMVideoSDKRawDataPipeDelegate>)listener deviceID:(NSString* _Nullable)cameraDeviceID;

/**
 @brief UnSubscribe preview video raw data with the subscribed callback.
 @param listener The callback sink object.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopVideoPreview:(id<ZMVideoSDKRawDataPipeDelegate>)listener;

/**
 @brief Starts the preview video with a view.
 @param view The view to preview video.
 @param cameraDeviceID The camera ID.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startVideoCanvasPreview:(NSView*)view deviceID:(NSString* _Nullable)cameraDeviceID;

/**
 @brief Stops the preview video.
 @param view The view to preview video.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopVideoCanvasPreview:(NSView*)view;

/**
 @brief Add virtual background object.
 @param imagePath The path of image.
 @param imageItem An object of type {@link ZMVideoSDKVirtualBackgroundItem}. Once the function is called successfully, this parameter will store the pointer to the ZMVideoSDKVirtualBackgroundItem*.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)addVirtualBackgroundItem:(NSString *)imagePath imageItem:(ZMVideoSDKVirtualBackgroundItem * _Nullable * _Nonnull)imageItem;

/**
 @brief Remove virtual background object.
 @param imageItem The ZMVideoSDKVirtualBackgroundItem object to be removed.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)removeVirtualBackgroundItem:(ZMVideoSDKVirtualBackgroundItem *)imageItem;

/**
 @brief Returns a collection of virtual background item as an object of type {@link ZMVideoSDKVirtualBackgroundItem}.
 @return If the function succeeds, it will return a list of virtual background items.
 */
- (NSArray<ZMVideoSDKVirtualBackgroundItem* >* _Nullable)getVirtualBackgroundItemList;

/**
 @brief Select virtual background item.
 @param imageItem The ZMVideoSDKVirtualBackgroundItem object to select.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setVirtualBackgroundItem:(ZMVideoSDKVirtualBackgroundItem*)imageItem;

/**
 @brief Get a selected virtual background item.
 @return If the function succeeds, it will return the object of type {@link ZMVideoSDKVirtualBackgroundItem}.
 */
- (ZMVideoSDKVirtualBackgroundItem* _Nullable)getSelectedVirtualBackgroundItem;

/**
 @brief Determine whether current aspect ratio is the original aspect ratio of video.
 @return YES if is original aspect ratio, otherwise NO.
 */
- (BOOL)isOriginalAspectRatioEnabled;

/**
 @brief Set the aspect ratio of the video sent out.
 @Note If session is using video source and data_mode is not VideoSourceDataMode_None, default always use original aspect ration of video.
 @param bEnabled NO means the aspect ratio is 16:9, YES means that using the original aspect ratio of video.
 @return If the function succeeds, it will return YES.
 */
- (BOOL)enableOriginalAspectRatio:(BOOL)bEnabled;


/**
 @brief Mirrors the current user's video. Valid only for canvas.
 @param bEnabled YES to enable mirror my video.
 @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)mirrorMyVideo:(BOOL)bEnabled;

/**
 @brief Determine whether mirror my video is enabled.
 @return YES if mirror my video is enabled, otherwise NO.
 */
- (BOOL)isMyVideoMirrored;

/**
 * @brief Determine if the current device supports alpha channel mode.
 * @return YES indicates that the current device supports alpha channel mode, Otherwise it does not.
 */
- (BOOL)isDeviceSupportAlphaChannelMode;

/**
 * @brief Determine if alpha channel mode can be enabled.
 * @return YES means it can be enabled. Otherwise NO.
 */
- (BOOL)canEnableAlphaChannelMode;

/**
 * @brief Enable or disable alpha channel mode.
 * @param enabled YES indicates to enable alpha channel mode. Otherwise, disable it.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)enableAlphaChannelMode:(BOOL)enabled;

/**
 * @brief Determine if alpha channel mode is enabled.
 * @return YES indicates is in alpha channel mode. Otherwise NO.
 */
- (BOOL)isAlphaChannelModeEnabled;

/**
 * @brief Call this method to spotlight user's video.
 * @param user Which you  want to spotlight video.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)spotLightVideo:(ZMVideoSDKUser*)user;

/**
 * @brief Call this method to unSpotlight user's video.
 * @param user Which you  want to unSpotlight video.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unSpotLightVideo:(ZMVideoSDKUser*)user;

/**
 * @brief Call this method to set all user's video unSpotlight.
 * @return If the function succeeds, the return value is ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)unSpotlightAllVideos;

/**
 * @brief Enable or disable alpha channel mode.
 * @return If the function succeeds, the return value is ZMVideoSDKUser object list.
 */
- (NSArray<ZMVideoSDKUser *>* _Nullable)getSpotlightedVideoUserList;
@end

NS_ASSUME_NONNULL_END
