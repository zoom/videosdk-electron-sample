import { ZoomVideoSDKErrors, ZoomVideoSDKVideoPreferenceMode } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo, getUserInfo } from './zoom_video_sdk_user_util'

function checkCameraCtrlRange(range) {
  if (!range || range < 10) {
    return 10
  } else if (range > 100) {
    return 100
  } else {
    return parseInt(range)
  }
}

function checkVideoPreferenceFrameRate(frame_rate) {
  if (frame_rate < 0) {
    return 0
  } else if (frame_rate > 30) {
    return 30
  } else {
    return parseInt(frame_rate)
  }
}

export default (function () {
  var instance
  /**
    * Return an instance to manage cameras and video during a video SDK session.
    * @module zoom_video_sdk_video
    * @return {ZoomVideoSDKVideo}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetVideoHelper()

    return {
      // Public methods and variables
      /**
       * Call this method to start sending local video data from the camera.
       * @method startVideo
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      startVideo: function () {
        if (_addon) {
          return _addon.StartVideo()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to stop sending local video data from the camera.
       * @method stopVideo
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      stopVideo: function () {
        if (_addon) {
          return _addon.StopVideo()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Call this method to spotlight user's video.
      * @method spotLightVideo
      * @param {Object} user The user which you want to spotlight.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      spotLightVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const SpotLightVideoParams = new messages.SpotLightVideoParams()
            SpotLightVideoParams.setUser(user)
            const bytes = SpotLightVideoParams.serializeBinary()
            return _addon.SpotLightVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
       /**
      * Call this method to unSpotlight user's video.
      * @method unSpotLightVideo
      * @param {Object} user The user which you want to unSpotlight.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      unSpotLightVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const UnSpotLightVideoParams = new messages.UnSpotLightVideoParams()
            UnSpotLightVideoParams.setUser(user)
            const bytes = UnSpotLightVideoParams.serializeBinary()
            return _addon.UnSpotLightVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to set all user's video unSpotlight.
       * @method unSpotlightAllVideos
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
	        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      unSpotlightAllVideos: function () {
        if (_addon) {
          return _addon.UnSpotlightAllVideos()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to get spotlighted video user list.
       * @method getSpotlightedVideoUserList
       * @return {Array} If the function succeed, the return value is user list object(userid, username, customIdentity, userReference, emailAddress, isHasVideoDevice, isVideoOn, audioType, isAudioMuted, isTalking, shareStatus, isHost, isManager, isVideoSpotLighted, isIncomingLiveStreamUser, videoStatisticInfo_height, videoStatisticInfo_width, videoStatisticInfo_bpf, videoStatisticInfo_fps, shareStatisticInfo_height, shareStatisticInfo_width, shareStatisticInfo_bpf, shareStatisticInfo_fps). Otherwise failed. the return value is NULL.
       */
      getSpotlightedVideoUserList: function () {
        if (_addon) {
          try {
            const message = messages.UserList.deserializeBinary(_addon.GetSpotlightedVideoUserList())
            const tempList = message.getUserList()
            let userList = []
            for (let val of tempList) {
              let obj = getUserInfo(val)
              userList.push(obj)
            }
            return userList
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Call this method to rotate the video when the device is rotated.
       * @method rotateMyVideo
       * @param {Number} rotation
       * @return {Boolean} Return true if the rotation was successful, false otherwise.
       */
      rotateMyVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          const rotation = clientOpts.rotation
          try {
            const RotateMyVideoParams = new messages.RotateMyVideoParams()
            RotateMyVideoParams.setZnRotation(rotation)
            const bytes = RotateMyVideoParams.serializeBinary()
            return _addon.RotateMyVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Switch to the next available camera
       * @method switchCamera
       * @return {Boolean} Return true if the switch to the next camera was successful, false otherwise.
       */
      switchCamera: function () {
        if (_addon) {
          return _addon.SwitchCamera()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Select camera with cameraDeviceID
       * @method selectCamera
       * @param {String} deviceID
       * @return {Boolean} true if success. Otherwise returns false.
       */
      selectCamera: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          const deviceID = clientOpts.deviceID
          try {
            const SelectCameraParams = new messages.SelectCameraParams()
            SelectCameraParams.setZnDeviceid(deviceID)
            const bytes = SelectCameraParams.serializeBinary()
            return _addon.SelectCamera(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Return number of cameras available to share the video.
       * @method getNumberOfCameras
       * @return {Number} number of cameras.
       */
      getNumberOfCameras: function () {
        if (_addon) {
          return _addon.GetNumberOfCameras()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get camera device list
       * @method getCameraList
       * @return {Array} camera devices list
       */
      getCameraList: function () {
        if (_addon) {
          const result = _addon.GetCameraList()
          const message = new messages.GetCameraList.deserializeBinary(result)
          const tempList = message.getCamerainfoList()
          let cameraList = []
          for (let val of tempList) {
            let obj = {
              deviceID: val.getDeviceid(),
              deviceName: val.getDevicename(),
              isSelectedDevice: val.getIsselecteddevice()
            }
            cameraList.push(obj)
          }
          return cameraList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Check whether the current user has permission to control the camera.
       * @method canControlCamera
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      canControlCamera: function () {
        if (_addon) {
          return _addon.CanControlCamera()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera to the left.
      * @method turnCameraLeft
      * @param {Number} Rotation range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnCameraLeft: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlTurnLeftParams = new messages.LocalCameraCtrlTurnLeftParams()
            LocalCameraCtrlTurnLeftParams.setRange(range)
            const bytes = LocalCameraCtrlTurnLeftParams.serializeBinary()
            return _addon.TurnCameraLeft(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera to the right.
      * @method turnCameraRight
      * @param {Number} Rotation range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnCameraRight: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlTurnRightParams = new messages.LocalCameraCtrlTurnRightParams()
            LocalCameraCtrlTurnRightParams.setRange(range)
            const bytes = LocalCameraCtrlTurnRightParams.serializeBinary()
            return _addon.TurnCameraRight(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera up.
      * @method turnCameraUp
      * @param {Number} Rotation range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnCameraUp: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlTurnUpParams = new messages.LocalCameraCtrlTurnUpParams()
            LocalCameraCtrlTurnUpParams.setRange(range)
            const bytes = LocalCameraCtrlTurnUpParams.serializeBinary()
            return _addon.TurnCameraUp(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Turn the camera down.
      * @method turnCameraDown
      * @param {Number} Rotation range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      turnCameraDown: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlTurnDownParams = new messages.LocalCameraCtrlTurnDownParams()
            LocalCameraCtrlTurnDownParams.setRange(range)
            const bytes = LocalCameraCtrlTurnDownParams.serializeBinary()
            return _addon.TurnCameraDown(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Zoom the camera in.
      * @method zoomCameraIn
      * @param {Number} Zoom range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      zoomCameraIn: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlZoomInParams = new messages.LocalCameraCtrlZoomInParams()
            LocalCameraCtrlZoomInParams.setRange(range)
            const bytes = LocalCameraCtrlZoomInParams.serializeBinary()
            return _addon.ZoomCameraIn(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Zoom the camera out.
      * @method zoomCameraOut
      * @param {Number} Zoom range, 10 <= range <= 100.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      zoomCameraOut: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const range = checkCameraCtrlRange(clientOpts.range)
            const LocalCameraCtrlZoomOutParams = new messages.LocalCameraCtrlZoomOutParams()
            LocalCameraCtrlZoomOutParams.setRange(range)
            const bytes = LocalCameraCtrlZoomOutParams.serializeBinary()
            return _addon.ZoomCameraOut(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Automatically adjust user's video solution and frame-rate. When setting custom modes, the maximum and minimum frame rates are provided by the developer. If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower resolution.
      * @method setVideoQualityPreference
      * @param {Number} mode, {@link ZoomVideoSDKVideoPreferenceMode} enum. When setting custom modes, the maximum and minimum frame rates are provided by the developer.
      * @param {Number} minimum_frame_rate, 0 for the default value,minimum_frame_rate should be less than maximum_frame_rate, range: from 0 to 30 .out of range for frame-rate will use default frame-rate of Zoom.
      * @param {Number} maximum_frame_rate, 0 for the default value,maximum_frame_rate should be less and equal than 30, range: from 0 to 30.out of range for frame-rate will use default frame-rate of Zoom.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      setVideoQualityPreference: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const mode = clientOpts.mode || ZoomVideoSDKVideoPreferenceMode.ZoomVideoSDKVideoPreferenceMode_Balance
            const minimum_frame_rate = checkVideoPreferenceFrameRate(clientOpts.minimum_frame_rate == undefined ? 0 : clientOpts.minimum_frame_rate)
            const maximum_frame_rate = checkVideoPreferenceFrameRate(clientOpts.maximum_frame_rate == undefined ? 0 : clientOpts.maximum_frame_rate)
            const SetVideoQualityPreferenceParams = new messages.SetVideoQualityPreferenceParams()
            SetVideoQualityPreferenceParams.setMode(mode)
            SetVideoQualityPreferenceParams.setMinimumFrameRate(minimum_frame_rate)
            SetVideoQualityPreferenceParams.setMaximumFrameRate(maximum_frame_rate)
            const bytes = SetVideoQualityPreferenceParams.serializeBinary()
            return _addon.SetVideoQualityPreference(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Enable multiple stream video if you have multiple cameras and other participants can see multiple videos of you.
      * @method enableMultiStreamVideo
      * @param {String} deviceID the camera ID which you want to enable. 
      * @return {Boolean} True if success. Otherwise returns false.
      */
      enableMultiStreamVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const EnableMultiStreamVideoParams = new messages.EnableMultiStreamVideoParams()
            EnableMultiStreamVideoParams.setDeviceid(deviceID)
            const bytes = EnableMultiStreamVideoParams.serializeBinary()
            return _addon.EnableMultiStreamVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Disable multiple stream video 
      * @method disableMultiStreamVideo
      * @param {String} deviceID the camera id which you want to disable.
      * @return {Boolean} True if success. Otherwise returns false.
      */
      disableMultiStreamVideo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const deviceID = clientOpts.deviceID
            const DisableMultiStreamVideoParams = new messages.DisableMultiStreamVideoParams()
            DisableMultiStreamVideoParams.setDeviceid(deviceID)
            const bytes = DisableMultiStreamVideoParams.serializeBinary()
            return _addon.DisableMultiStreamVideo(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Subscribe preview video raw data with a callback.
      * @method startVideoPreview
      * @param {Number} recv_handle
      * @param {String} cameraDeviceID
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      startVideoPreview: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const recv_handle = clientOpts.recv_handle
            const cameraDeviceID = clientOpts.cameraDeviceID
            const StartVideoPreviewParams = new messages.StartVideoPreviewParams()
            StartVideoPreviewParams.setZnRecvHandle(recv_handle)
            StartVideoPreviewParams.setCameradeviceid(cameraDeviceID)
            const bytes = StartVideoPreviewParams.serializeBinary()
            return _addon.StartVideoPreview(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * UnSubscribe preview video raw data with the subscribed callback.
      * @method stopVideoPreview
      * @param {Number} recv_handle
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      stopVideoPreview: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const recv_handle = clientOpts.recv_handle
            const StopVideoPreviewParams = new messages.StopVideoPreviewParams()
            StopVideoPreviewParams.setZnRecvHandle(recv_handle)
            const bytes = StopVideoPreviewParams.serializeBinary()
            return _addon.StopVideoPreview(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * add virtual background object.
      * @method addVirtualBackgroundItem
      * @param {String} imagePath setting using image path.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      addVirtualBackgroundItem: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const imagePath = clientOpts.imagePath
            const AddVirtualBackgroundItemParams = new messages.AddVirtualBackgroundItemParams()
            AddVirtualBackgroundItemParams.setImagepath(imagePath)
            const bytes = AddVirtualBackgroundItemParams.serializeBinary()
            return _addon.AddVirtualBackgroundItem(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * remove virtual background object.
      * @method removeVirtualBackgroundItem
      * @param {Number} vbItemHandle the choosing virtual background item handle.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      removeVirtualBackgroundItem: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const vbItemHandle = clientOpts.vbItemHandle
            const RemoveVirtualBackgroundItemParams = new messages.RemoveVirtualBackgroundItemParams()
            RemoveVirtualBackgroundItemParams.setVbitemhandle(vbItemHandle)
            const bytes = RemoveVirtualBackgroundItemParams.serializeBinary()
            return _addon.RemoveVirtualBackgroundItem(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * get virtual background item list, this function need to call first before create virtual background object to get background item last time.
      * @method getVirtualBackgroundItemList
      * @return {Array} If the function succeeds, the return value is VirtualBackgroundItem object Array. Otherwise failed. the return value is null.
      */
      getVirtualBackgroundItemList: function () {
        if (_addon) {
          const result = _addon.GetVirtualBackgroundItemList()
          const message = new messages.VBItemHandleList.deserializeBinary(result)
          return message.getVbitemhandleList()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * set virtual background item.
      * @method setVirtualBackgroundItem
      * @param {Number} vbItemHandle the choosing virtual background item handle.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      setVirtualBackgroundItem: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const vbItemHandle = clientOpts.vbItemHandle
            const SetVirtualBackgroundItemParams = new messages.SetVirtualBackgroundItemParams()
            SetVirtualBackgroundItemParams.setVbitemhandle(vbItemHandle)
            const bytes = SetVirtualBackgroundItemParams.serializeBinary()
            return _addon.SetVirtualBackgroundItem(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * get virtual background handle which is been selected.
      * @method getSelectedVirtualBackgroundItem
      * @return {Number} If the function succeeds, the return value is virtual background handle. Otherwise failed. the return value is null.
      */
      getSelectedVirtualBackgroundItem: function () {
        if (_addon) {
          return _addon.GetSelectedVirtualBackgroundItem()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * get the virtual background item information.
      * @method getVirtualBackgroundItemInfo
      * @param {Number} vbItemHandle the choosing virtual background item handle.
      * @return {Object} If the function succeeds, the return value is VirtualBackgroundItem object. Otherwise failed. the return value is null.
      */
      getVirtualBackgroundItemInfo: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const vbItemHandle = clientOpts.vbItemHandle
            const GetVirtualBackgroundItemInfoParams = new messages.GetVirtualBackgroundItemInfoParams()
            GetVirtualBackgroundItemInfoParams.setVbitemhandle(vbItemHandle)
            const bytes = GetVirtualBackgroundItemInfoParams.serializeBinary()
            let temp_info = _addon.GetVirtualBackgroundItemInfo(bytes)
            if (temp_info.err == ZoomVideoSDKErrors.ZoomVideoSDKErrors_Success) {
              let temp_obj = new messages.VBItemInfo.deserializeBinary(temp_info.vbItemInfo)
              temp_info.vbItemInfo = {
                imageFilePath: temp_obj.getImagefilepath(),
                imageName: temp_obj.getImagename(),
                vbType: temp_obj.getVbtype(),
                canBeDeleted: temp_obj.getCanbedeleted()
              }
            }
            const virtualBackgroundItemInfo = {...temp_info}
            return virtualBackgroundItemInfo
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      }
    }
  };

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
