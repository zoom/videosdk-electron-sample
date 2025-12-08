/**
 * @file zoom_video_sdk_share_helper_interface.h
 * @brief share helper
 */

#ifndef _ZOOM_VIDEO_SDK_SHARE_HELPER_INTERFACE_H_
#define _ZOOM_VIDEO_SDK_SHARE_HELPER_INTERFACE_H_
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_vector_interface.h"
#include "zoom_video_sdk_user_helper_interface.h"

BEGIN_ZOOM_VIDEO_SDK_NAMESPACE
struct ZoomVideoSDKShareOption
{
	/** share option, true: share computer sound when share screen/window, otherwise not. */
    bool isWithDeviceAudio;            
	/** share option, true: optimize the frame rate when share screen/window, otherwise not. */
    bool isOptimizeForSharedVideo;     

    ZoomVideoSDKShareOption()
    {
        isWithDeviceAudio = false;
        isOptimizeForSharedVideo = false;
    }

    ZoomVideoSDKShareOption(const ZoomVideoSDKShareOption& option)
    {
        isWithDeviceAudio = option.isWithDeviceAudio;
        isOptimizeForSharedVideo = option.isOptimizeForSharedVideo;
    }

    ZoomVideoSDKShareOption(bool bWithAudio, bool optimize)
    {
        isWithDeviceAudio = bWithAudio;
        isOptimizeForSharedVideo = optimize;
    }
};


/**
 * @class IZoomVideoSDKShareSender
 * @brief Share raw data sender interface.
 */
class IZoomVideoSDKShareSender
{
public:
	virtual ~IZoomVideoSDKShareSender() {}
	/**
	 * @brief Send one frame data.
     * @param frameBuffer FrameBuffer YUVI420 buffer.
     * @param width Frame width.
     * @param height Frame height.
     * @param frameLength Buffer length.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
	 */
	virtual ZoomVideoSDKErrors sendShareFrame(char* frameBuffer, int width, int height, int frameLength, FrameDataFormat format = FrameDataFormat_I420_FULL) = 0;
};

/**
 * @brief Share source sink interface.
 */
class IZoomVideoSDKShareSource
{
public:
	virtual ~IZoomVideoSDKShareSource() {}
	/**
     * @brief Callback for share source can start send raw data.
     * @param sender See \link IZoomVideoSDKShareSender \endlink.
	 */
	virtual void onShareSendStarted(IZoomVideoSDKShareSender* pSender) = 0; 
	
	/**
     * @brief Callback for share source stop send raw data.
	 */
	virtual void onShareSendStopped() = 0; 
};

class IZoomVideoSDKShareAudioSender
{
public:
	virtual ~IZoomVideoSDKShareAudioSender() {}
	/**
	 * @brief Sends audio raw data.
	 * @param data The audio data address.
	 * @param data_length The audio data length. It must be even numbers.
	 * @param sample_rate The audio data sampling rate.
	 * @param channel The channel type.
	 *  Supported audio data properties:
	 *  When the channel is mono, supported sample rates: 8000/11025/16000/32000/44100/48000/50000/50400/96000/192000
	 *  When the channel is stereo, supported sample rates: 8000/16000/32000/44100/48000/50000/50400/96000
	 *  Channels: mono and stereo
	 *  Resolution: little-endian, 16bit
	 */
	virtual ZoomVideoSDKErrors sendShareAudio(char* data, unsigned int data_length, int sample_rate, ZoomVideoSDKAudioChannel channel) = 0;
};

class IZoomVideoSDKShareAudioSource
{
public:
	virtual ~IZoomVideoSDKShareAudioSource() {}
	/**
	 * @brief Callback for audio source to start sending raw data.
	 * @param pShareAudioSender See \link IZoomVideoSDKShareAudioSender \endlink.
	 */
	virtual void onStartSendAudio(IZoomVideoSDKShareAudioSender* pShareAudioSender) = 0;
	
	/**
	 * @brief Callback for audio source to stop sending raw data.
	 */
	virtual void onStopSendAudio() = 0;
};

/**
 * @class IMonitorListBuilder
 * @brief Monitor List Builder.
 */
class IMonitorListBuilder
{
public:
    virtual ~IMonitorListBuilder() {}
	/**
     * @brief Add the monitor ID to list. The validity of the monitor ID is not verified here.
     * @param monitorID The screen name.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the function fails.  
	 */
    virtual ZoomVideoSDKErrors addMonitorID(const zchar_t* monitorID) = 0;
	
	/**
     * @brief Remove the monitor ID from list.
     * @param monitorID The screen name.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the function fails.  
	 */
    virtual ZoomVideoSDKErrors removeMonitorID(const zchar_t* monitorID) = 0;
	
	/**
     * @brief Clear the monitor ID list.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the function fails.  
	 */
    virtual ZoomVideoSDKErrors clear() = 0;
	
	/**
     * @brief Returns the monitor ID list.
     * @return If the function succeeds, the return value is the monitor ID list. Otherwise returns nullptr.
	 */
    virtual IVideoSDKVector<const zchar_t*>* getMonitorIDs() = 0;
};


#if defined(WIN32) || defined(__MACOS__)
class IZoomVideoSDKRemoteControlRequestHandler
{
public:
    virtual ~IZoomVideoSDKRemoteControlRequestHandler() {}
	/**
     * @brief Approve the remote control request.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
	 */
    virtual ZoomVideoSDKErrors approve() = 0;
	
	/**
     * @brief Decline the remote control request.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
	 */
    virtual ZoomVideoSDKErrors deny() = 0;
};

/**
 * @class IZoomVideoSDKRemoteControlHelper
 * @brief Video SDK remote control interface.
 */
class IZoomVideoSDKRemoteControlHelper
{
public:
    virtual ~IZoomVideoSDKRemoteControlHelper() {}
	/**
     * @brief Determine if the user is able to ask to remote control the specified user.
     * @note For custom style mode, this interface is only valid after subscribing to the content to be shared by the specified user by calling ICustomizedShareRender::SetUserID(unsigned int userid) successfully.
     * @return If the user is able to request to remote control the specified user, the return value is true. Otherwise false.
	 */
    virtual bool canRequestControl() = 0;
	
	/**
     * @brief Send the remote control request to the specified user.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors requestRemoteControl() = 0;
	
	/**
     * @brief End the remote control of the specified user.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors endRemoteControl() = 0;
	
	/**
     * @brief Determine if the user is able to remote control the specified user.
     * @return If the user is able to remote control the specified user, the return value is true. Otherwise false.
	 */
    virtual bool canRemoteControl() = 0;
	
	/**
     * @brief Remote control the specified user.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors enterRemoteControl() = 0;
	
	/**
     * @brief Determine if the specified user is in the process of being remotely controlled.
     * @return If the specified user is being remotely controled, the return value is true. Otherwise false.
	 */
    virtual bool isRemoteControlling() = 0;
	
	/**
     * @brief The user has temporarily paused remote control, to continue, there is no need to request remote control again.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors leaveRemoteControl() = 0;
};
#endif

struct ZoomVideoSDKViewSize
{
	/** resolution width */
    unsigned int width; 
	/** resolution height */
    unsigned int height; 
    
    ZoomVideoSDKViewSize()
    {
        width = 0;
        height = 0;
    }
    
    ZoomVideoSDKViewSize(const ZoomVideoSDKViewSize& resolution)
    {
        width = resolution.width;
        height = resolution.height;
    }

    ZoomVideoSDKViewSize(unsigned int new_width, unsigned int new_height)
    {
        width = new_width;
        height = new_height;
    }
};

class IZoomVideoSDKShareAction
{
public:
	virtual ~IZoomVideoSDKShareAction() {}
	/**
	 * @brief Get share source ID.
     * @return The user ID of the user object.
	 */
	virtual unsigned int getShareSourceId() = 0;
	

#if !defined __linux && !defined ANDROID
	/**
	 * @brief Get the render canvas object.
	 * @return If the function succeeds, the return value is the share render helper object. Otherwise, this function fails and returns nullptr.
	 */
	virtual IZoomVideoSDKCanvas* getShareCanvas() = 0;
#endif
    /**
	 * @brief Get share raw data pipe.
	 * @return The share pipe.
	 */
	virtual IZoomVideoSDKRawDataPipe* getSharePipe() = 0;
	
	/**
	 * @brief Get share status.
	 * @return Share status of the share object.
	 */
	virtual ZoomVideoSDKShareStatus getShareStatus() = 0;
	
    /**
     * @brief Gets the reason why the share capture is paused.
     * @return The current pause reason of the ongoing share.
     * @note If sharing is not paused, the return value is @c ZoomVideoSDKShare_Capture_Pause_None.
     */
    virtual ZoomVideoSDKShareCapturePauseReason getShareCapturePauseReason() = 0;
    
	/**
	 * @brief Get subscribe fail reason.
	 * @return failed reason of the subscription.
	 */
	virtual ZoomVideoSDKSubscribeFailReason getSubscribeFailReason() = 0;
	
	/**
	 * @brief Determine whether annotation privilege is enabled.
	 * @return True indicates that annotation privilege is enabled, otherwise false.
	 */
	virtual bool isAnnotationPrivilegeEnabled() = 0;
	
	/**
	 * @brief Get share type.
	 * @return Share type of the share object.
	 */
	virtual ZoomVideoSDKShareType getShareType() = 0;
	
    /**
     * @brief Get the size of the share content.
     * @return The size of share content.
	 */
    virtual ZoomVideoSDKViewSize getShareSourceContentSize() = 0;

#if defined(WIN32) || defined(__MACOS__)
	/**
     * @brief Get the helper class instance to access remote control. Only available for controller side. 
     * @return If the function succeeds, the return value is the remote control helper object. Otherwise returns nullptr.
	 */
    virtual IZoomVideoSDKRemoteControlHelper* getRemoteControlHelper() = 0;
	
	/**
     * @brief Get the list of users I have agreed to control. Only available for the controlling user.
     * @return If the function succeeds, the return value is the list of users I have agreed to control. Otherwise returns nullptr.
	 */
    virtual IVideoSDKVector<IZoomVideoSDKUser*>* getRemoteControlApprovedUserList() = 0;
	
	/**
     * @brief Get back all the authority of remote control. Only available for the user themselves.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors revokeRemoteControl() = 0;
	
	/**
     * @brief Get the controller ID who is currently controlling me. Only available for the controlled user.
     * @return If the function succeeds, the return value is the user object. Otherwise nullptr.
	 */
    virtual IZoomVideoSDKUser* getCurrentRemoteController() = 0;
#endif
};

enum ZoomVideoSDKSharePreprocessType
{
	/** For initialization. */
    ZoomVideoSDKSharePreprocessType_none,    
	/** For share screen(monitor). */
    ZoomVideoSDKSharePreprocessType_screen,  
	/** For share view(application window). */
    ZoomVideoSDKSharePreprocessType_view,
#if defined(__MACOS__)
    /** For share process(application). */
    ZoomVideoSDKSharePreprocessType_process
#endif
};

struct ZoomVideoSDKSharePreprocessParam
{
	/** The share pre-process type */
    ZoomVideoSDKSharePreprocessType type; 
	/** The window handle that to share and pre-process.  */
	void* handle;                          
	/** The screen name that to share and pre-process. */
	const zchar_t* monitorID;
#if defined(__MACOS__)
    uint32_t processID;
#endif
    
    ZoomVideoSDKSharePreprocessParam()
	{
        type = ZoomVideoSDKSharePreprocessType_none;
		handle = nullptr;
		monitorID = nullptr;
#if defined(__MACOS__)
        processID = 0;
#endif
	}
};

class IZoomVideoSDKSharePreprocessSender
{
public:
	virtual ~IZoomVideoSDKSharePreprocessSender() {}
	/**
	 * @brief Send preprocessed data.
     * @param pRawData The processed data object.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
	virtual ZoomVideoSDKErrors sendPreprocessedData(YUVRawDataI420* pRawData) = 0;
};

class IZoomVideoSDKSharePreprocessor
{
public:
	virtual ~IZoomVideoSDKSharePreprocessor() {}
	/**
	 * @brief You will receive this callback when calling 'startShareWithPreprocessing' successfully.
	 * @param pRawData You can get the YUV data address through this object and then pre-process the data.
     * @param pSender Use this object to send the processed data out.
	 */
	virtual void onCapturedRawDataReceived(YUVRawDataI420* pRawData, IZoomVideoSDKSharePreprocessSender* pSender) = 0;
	
	/**
     * @brief You will receive this callback when call 'stopShare' successfully.
     * @note In this event notification, you can perform some stop and destroy actions if necessary.
	 */
	virtual void onShareStopped() = 0;
};

/**
 * @class IZoomVideoSDKShareHelper
 * @brief Share helper interface.
 */
class IZoomVideoSDKRawDataPipeDelegate;
class IZoomVideoSDKAnnotationHelper;
class IZoomVideoSDKWhiteboardHelper;
class IZoomVideoSDKShareHelper
{
public:
	/**
	 * @brief Share a selected window, if virtual speaker is enabled, don't support share audio.
     * @param handle The window handle that will to be share.
     * @param option See \link ZoomVideoSDKShareOption \endlink.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors startShareView(void* handle, ZoomVideoSDKShareOption option = {false, false}) = 0;

    /**
     * @brief Starts sharing a specific application process.
     * @param processID The process identifier of the target application. Must be valid in the current user session.
     * @param option Optional share settings.
     * @return If the function succeeds, the return value is @c ZoomVideoSDKErrors_Success. Otherwise the method failed.
     * @note This API is only supported on macOS.
     */
	virtual ZoomVideoSDKErrors startShareApplication(uint32_t processID, ZoomVideoSDKShareOption option = {false, false}) = 0;

	/**
	 * @brief Determine whether the handle being shared is valid.
	 * @return True indicates that the handle is valid, otherwise false.
	 */
	virtual bool isShareViewValid(void* handle) = 0;
	
	/**
	 * @brief Share a selected screen, if virtual speaker is enabled, don't support share audio.
     * @param monitorID The screen name that will to be share.
     * @param option See \link ZoomVideoSDKShareOption \endlink.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors startShareScreen(const zchar_t* monitorID, ZoomVideoSDKShareOption option = { false, false }) = 0;
	
	/**
     * @brief Returns the monitor ID list builder object, the monitor ID list will be cleared after calling startShareMultiScreen.
     * @return If the function succeeds, the return value is the monitor ID list builder object. Otherwise returns nullptr.
	 */
    virtual IMonitorListBuilder* getMonitorListBuilder() = 0;
	
	/**
     * @brief Share all screens in IMonitorListBuilder, if virtual speaker is enabled, don't support share audio.
     * @param option See \link ZoomVideoSDKShareOption \endlink.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors startShareMultiScreen(ZoomVideoSDKShareOption option = { false, false }) = 0;
	
	/**
     * @brief Start sharing only the computer audio.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors startShareComputerAudio() = 0;
	
	/**
	 * @brief Starts sharing the pure external audio source.
     * @param pShareAudioSource the pointer of external audio source object. 
     * @param isPlaying true means audio raw data is played locally at the same time, false not.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise this function fails.  
     * @note The feature is similar to share computer audio, except that the shared content is user-defined.
	 */
    virtual ZoomVideoSDKErrors startSharePureAudioSource(IZoomVideoSDKShareAudioSource* pShareAudioSource, bool isPlaying = true) = 0;
	
	/**
	 * @brief Stop share.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors stopShare() = 0;
	
	/**
     * @brief Pause share.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors pauseShare() = 0;
	
	/**
     * @brief Resume share.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors resumeShare() = 0;
	
	/**
	 * @brief Determine whether the current user is sharing.
	 * @return True indicates the current user is sharing. Otherwise returns false.
	 */
    virtual bool isSharingOut() = 0;
	
	/**
	 * @brief Determine whether the current user is sharing the screen.
     * @return True indicates the current user is sharing the screen, otherwise false.
	 */
    virtual bool isScreenSharingOut() = 0;
	
	/**
	 * @brief Determine if other user is sharing.
     * @return True indicates another user is sharing, otherwise false.
	 */
    virtual bool isOtherSharing() = 0;
	
	/**
	 * @brief Lock sharing the view or screen. Only the host can call this method.
     * @param lock True to lock sharing
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors lockShare(bool lock) = 0;
	
    /**
	 * @brief Determine whether sharing is locked.
     * @return True indicates that sharing is locked, otherwise false.
	 */
    virtual bool isShareLocked() = 0;
	
	/**
	 * @brief Enable or disable participants can share simultaneously.
	 * @param enable True to enable. False to disable.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the function fails.  
     * @warning When you switch multi share from enable to disable, all sharing will be stopped.
	 */
    virtual ZoomVideoSDKErrors enableMultiShare(bool enable) = 0;
	
	/**
	 * @brief Determine whether multi share is enabled or not.
     * @return true enabled, false not enabled.
	 */
    virtual bool isMultiShareEnabled() = 0;
	
	/**
	 * @brief Enable or disable the computer sound when sharing. The SDK does not support sharing device audio, for example, when you've enabled virtual speaker.
     * @param enable True to enable. False to disable.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise the function fails.  
	 */
	virtual ZoomVideoSDKErrors enableShareDeviceAudio(bool enable) = 0;
	
	/**
	 * @brief Determine if the SDK has enabled share device sound. This reflects the execution status of `enableShareDeviceAudio` instead of `startShareComputerAudio`.
     * @return True if enabled, otherwise false.
	 */
    virtual bool isShareDeviceAudioEnabled() = 0;
	
	/**
	 * @brief Enable or disable the optimization of frame rate, you can enable it when there is video in shared content.
     * @param enable True indicates to enable. False disable.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
	virtual ZoomVideoSDKErrors enableOptimizeForSharedVideo(bool enable) = 0;
	
	/**
	 * @brief Determine if optimization for shared video is enabled.
     * @return True if enabled. Otherwise returns false.
	 */
    virtual bool isOptimizeForSharedVideoEnabled() = 0;
	
	/**
     * @brief Start sharing a camera feed specified by the cameraID as the second camera.
     * @param cameraID The camera ID.Warning: This must be a different camera than the one sending your primary video.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
	 */
    virtual ZoomVideoSDKErrors startShare2ndCamera(const zchar_t* cameraID) = 0;
	
	/**
     * @brief Subscribe to the raw data stream of the camera that is shared as the second camera.
     * @param data_handler Data handler object.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
     * @deprecated This interface will be marked as deprecated, then it will be instead by IZoomVideoSDKRawDataPipe->subscribe, please stop using it.
	 */
    virtual ZoomVideoSDKErrors subscribeMyShareCamera(IZoomVideoSDKRawDataPipeDelegate* data_handler) = 0;
	
	/**
     * @brief Unsubscribe to the raw data stream of the camera that is shared as the second camera.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.  
     * @deprecated This interface will be marked as deprecated, then it will be instead by IZoomVideoSDKRawDataPipe->unSubscribe, please stop using it.
	 */
    virtual ZoomVideoSDKErrors unSubscribeMyShareCamera() = 0;
	
	/**
	 * @brief Shares an external source.
	 * @param pSource External share source, \link IZoomVideoSDKShareSource \endlink.
     * @param pAudioSource external share audio source.
     * @param isPlaying true means audio raw data is played locally at the same time, false not.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise this function fails.  
     * @note If pAudioSource is non-null, it means share user-defined audio at the same time.
	 */
	 virtual ZoomVideoSDKErrors startSharingExternalSource(IZoomVideoSDKShareSource* pSource, IZoomVideoSDKShareAudioSource* pAudioSource = nullptr, bool isPlaying = true) = 0;
	 
	/**
	 * @brief Whether annotation is enabled or not.
	 * @return true support, false not support.
	 */
	virtual bool isAnnotationFeatureSupport() = 0;
	
	/**
	 * @brief Disable or enable viewer's annotation by the share owner.
	 * @param bDisable true means annotation is disabled, false means it is enabled.
	 * @warning Only the share owner can call this function.
	 */
	virtual ZoomVideoSDKErrors disableViewerAnnotation(bool bDisable) = 0;
	
	/**
	 * @brief Whether annotation on current sharing is disabled or not.
	 * @return true disable, false not disable.
	 * @warning Only the share owner can call this function.
	 */
	virtual bool isViewerAnnotationDisabled() = 0;
	
	/**
	 * @brief Creates annotation helper based on shared view.
	 * @param handle the shared view handle. Pass the null will return the helper for self sharing.
	 * @return If the function succeeds, the return value is the IZoomVideoSDKAnnotationHelper helper object. Otherwise returns nullptr. For more details, see \link IZoomVideoSDKAnnotationHelper \endlink.
	 * @warning The view passed in this function should be subscribed share view. If the share view aspect mode is set to ZoomVideoSDKVideoAspect_Full_Filled, annotation is not supported.
	 *          When the share owner not support the feature of annotate, the others should not do annotate in that case.
	 */
	virtual IZoomVideoSDKAnnotationHelper* createAnnotationHelper(void* handle) = 0;
	
	/**
	 * @brief Destroys annotation helper.
	 * @param helper IZoomVideoSDKAnnotationHelper object.
	 */
	virtual ZoomVideoSDKErrors destroyAnnotationHelper(IZoomVideoSDKAnnotationHelper* helper) = 0;
	
	/**
	 * @brief Sets the vanishing tool time.
	 * @param displayTime The time in milliseconds the tool remains visible before fading.
	 * @param vanishingTime The time in milliseconds for the tool to fade out after displayTime.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success.Otherwise failed.
	 * @note This setting only takes effect for the user's own share. The displayTime can be 0 or up to 15000 milliseconds (15 seconds), 
	 *		 and the vanishingTime must be greater than 1000 milliseconds (1 second) and less than or equal to 15000 milliseconds (15 seconds).
	 */
	virtual ZoomVideoSDKErrors setAnnotationVanishingToolTime(unsigned int displayTime, unsigned int vanishingTime) = 0;

	/**
	 * @brief Gets the current vanishing tool time settings.
	 * @param displayTime [out] The time in milliseconds the tool remains visible before fading.
	 * @param vanishingTime [out] The time in milliseconds for the tool to fade out after displayTime.	 
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success.Otherwise failed.
	 * @note This function can only retrieve the time settings for your own share.
	 */
	virtual ZoomVideoSDKErrors getAnnotationVanishingToolTime(unsigned int& displayTime, unsigned int& vanishingTime) = 0;

	/**
     * @brief Enable or disable local playback of shared audio raw data.
     * @param isPlaying true to play shared audio raw data, false not.
	 */
    virtual ZoomVideoSDKErrors enablePlaySharingAudioRawdata(bool isPlaying) = 0;
	
	/**
     * @brief Start share preprocessing.
     * @param param The share preprocessing parameters.
     * @param preprocessor Object that handles preprocessing events.
     * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise this function fails.  
	 */
    virtual ZoomVideoSDKErrors startShareWithPreprocessing(const ZoomVideoSDKSharePreprocessParam& param, IZoomVideoSDKSharePreprocessor* preprocessor) = 0;

	/**
	 * @brief Set share transparent window or not when sharing.
	 * @param hWnd The window handle of the transparent window that you want to share or not.
	 * @param bShare true to share the transparent window, false not.
	 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise this function fails.
	 * @note The provided hWnd must point to a transparent window. Otherwise unexpected issues may occur.
	 */
	virtual ZoomVideoSDKErrors setShareTransparentWindow(void* hWnd, bool bShare) = 0;

#if !defined (__linux) || defined ANDROID
    /**
	 * @brief Returns an instance to manage whiteboard during a video SDK session.
	 * @return If the function succeeds, the return value is the whiteboard helper object. Otherwise returns nullptr. For more details, see \link IZoomVideoSDKWhiteboardHelper \endlink.
	 */
	virtual IZoomVideoSDKWhiteboardHelper* getWhiteboardHelper() = 0;
#endif
};
END_ZOOM_VIDEO_SDK_NAMESPACE
#endif
