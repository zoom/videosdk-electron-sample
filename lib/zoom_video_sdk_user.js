import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage users present in a video SDK session.
    * @module zoom_video_sdk_user
    * @return {ZoomVideoSDKUser}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetUserHelper()
    const _renderAddon = clientOpts.addon.GetVideoSDKRender()

    return {
      // Public methods and variables
      /**
       * Subscribe video/share.
       * @method subscribe
       * @param {Object} user The user object to subscribe.
       * @param {Number} dataType 0 means subscribe video, 1 means subscribe share.
       * @param {Number} recv_handle The receive handle.
       * @param {Number} resolution Subscribe size.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      subscribe: function (opts) {
        if (_renderAddon) {
          const clientOpts = {...opts}
          const user = setUserInfo(clientOpts.user)
          const dataType = Number(clientOpts.dataType)
          const recv_handle = Number(clientOpts.recv_handle)
          const resolution = Number(clientOpts.resolution)
          try {
            const SubscribeParams = new messages.SubscribeParams()
            SubscribeParams.setZnUser(user)
            SubscribeParams.setZnType(dataType)
            SubscribeParams.setZnRecvHandle(recv_handle)
            SubscribeParams.setZnResolution(resolution)
            const bytes = SubscribeParams.serializeBinary()
            return _renderAddon.Subscribe(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Unsubscribe video/share.
       * @method unSubscribe
       * @param {Number} recv_handle The receive handle.
       * @param {Object} user The user object to unsubscribe.
       * @param {Number} dataType 0 means UnSubscribe video, 1 means UnSubscribe share.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      unSubscribe: function (opts) {
        if (_renderAddon) {
          const clientOpts = {...opts}
          const recv_handle = Number(clientOpts.recv_handle)
          const user = setUserInfo(clientOpts.user)
          const dataType = Number(clientOpts.dataType)
          try {
            const UnSubscribeParams = new messages.UnSubscribeParams()
            UnSubscribeParams.setZnRecvHandle(recv_handle)
            UnSubscribeParams.setZnUser(user)
            UnSubscribeParams.setZnType(dataType)
            const bytes = UnSubscribeParams.serializeBinary()
            return _renderAddon.UnSubscribe(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Subscribe camera stream.
       * @method subscribeMultiCameraStream
       * @param {Object} user The user object to subscribe.
       * @param {Number} cameraStreamID The id which camera stream will be subscribed.
       * @param {Number} recv_handle The receive handle.
       * @param {Number} resolution Subscribe size.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      subscribeMultiCameraStream: function (opts) {
        if (_renderAddon) {
          const clientOpts = {...opts}
          const user = setUserInfo(clientOpts.user)
          const cameraStreamID = Number(clientOpts.cameraStreamID)
          const recv_handle = Number(clientOpts.recv_handle)
          const resolution = Number(clientOpts.resolution)
          try {
            const SubscribeMultiCameraStreamParams = new messages.SubscribeMultiCameraStreamParams()
            SubscribeMultiCameraStreamParams.setZnUser(user)
            SubscribeMultiCameraStreamParams.setCamerastreamid(cameraStreamID)
            SubscribeMultiCameraStreamParams.setZnRecvHandle(recv_handle)
            SubscribeMultiCameraStreamParams.setZnResolution(resolution)
            const bytes = SubscribeMultiCameraStreamParams.serializeBinary()
            return _renderAddon.SubscribeMultiCameraStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Unsubscribe camera stream.
       * @method unSubscribeMultiCameraStream
       * @param {Number} recv_handle The receive handle.
       * @param {Object} user The user object to unsubscribe.
       * @param {Number} cameraStreamID The id which camera stream will be unsubscribed.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      unSubscribeMultiCameraStream: function (opts) {
        if (_renderAddon) {
          const clientOpts = {...opts}
          const recv_handle = Number(clientOpts.recv_handle)
          const user = setUserInfo(clientOpts.user)
          const cameraStreamID = Number(clientOpts.cameraStreamID)
          try {
            const UnSubscribeMultiCameraStreamParams = new messages.UnSubscribeMultiCameraStreamParams()
            UnSubscribeMultiCameraStreamParams.setZnRecvHandle(recv_handle)
            UnSubscribeMultiCameraStreamParams.setZnUser(user)
            UnSubscribeMultiCameraStreamParams.setCamerastreamid(cameraStreamID)
            const bytes = UnSubscribeMultiCameraStreamParams.serializeBinary()
            return _renderAddon.UnSubscribeMultiCameraStream(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get multi-camera data pipe list.
       * @method getMultiCameraStreamList
       * @param {Object} user The user object to get multi-camera stream list.
       * @return {Array} The return value is the pipe list.
       */
      getMultiCameraStreamList: function (opts) {
        if (_renderAddon) {
          const clientOpts = {...opts}
          const user = setUserInfo(clientOpts.user)
          try {
            const GetMultiCameraStreamList = new messages.GetMultiCameraStreamList()
            GetMultiCameraStreamList.setUser(user)
            const bytes = GetMultiCameraStreamList.serializeBinary()
            const result =  _renderAddon.GetMultiCameraStreamList(bytes)
            const message = new messages.MultiCameraStreamList.deserializeBinary(result)
            const tempList = message.getCamerastreaminfoList()
            let cameraStreamList = []
            for (let val of tempList) {
              let obj = {
                cameraStreamID: val.getCamerastreamid()
              }
              cameraStreamList.push(obj)
            }
            return cameraStreamList
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Change a specific user's name.
       * @method changeName
       * @param {String} name The new name of the user object.
       * @param {Object} user The user object in the session.
       * @return {Boolean} True indicates that name change is success. Otherwise, this function returns false.
       */
      changeName: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const name = clientOpts.name
            const user = setUserInfo(clientOpts.user)
            const ChangeNameParams = new messages.ChangeNameParams()
            ChangeNameParams.setZnName(name)
            ChangeNameParams.setUser(user)
            const bytes = ChangeNameParams.serializeBinary()
            return _addon.ChangeName(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Assign a user as the session host.
       * @method makeHost
       * @param {Object} user The user object in the session.
       * @return {Boolean} True indicates that the user is now the host. Otherwise, this function returns false.
       */
      makeHost: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const MakeHostParams = new messages.MakeHostParams()
            MakeHostParams.setUser(user)
            const bytes = MakeHostParams.serializeBinary()
            return _addon.MakeHost(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Assign a user as the session manager.
       * @method makeManager
       * @param {Object} user The user object in the session.
       * @return {Boolean} True indicates that the user is now the manager. Otherwise, this function returns false.
       */
      makeManager: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const MakeManagerParams = new messages.MakeManagerParams()
            MakeManagerParams.setUser(user)
            const bytes = MakeManagerParams.serializeBinary()
            return _addon.MakeManager(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Revoke manager rights from a user.
       * @method revokeManager
       * @param {Object} user The user object in the session.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      revokeManager: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RevokeManagerParams = new messages.RevokeManagerParams()
            RevokeManagerParams.setUser(user)
            const bytes = RevokeManagerParams.serializeBinary()
            return _addon.RevokeManager(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Remove user from session.
       * @method removeUser
       * @param {Object} user The user object in the session.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
       */
      removeUser: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const RemoveUserParams = new messages.RemoveUserParams()
            RemoveUserParams.setUser(user)
            const bytes = RemoveUserParams.serializeBinary()
            return _addon.RemoveUser(bytes)
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
