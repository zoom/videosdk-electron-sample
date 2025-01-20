import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'
import { setUserInfo } from './zoom_video_sdk_user_util.js'

export default (function () {
  var instance
  /**
    * Return an instance to send and receive chat messages within video SDK session participants.
    * @module zoom_video_sdk_chat
    * @return {ZoomVideoSDKChat}
    */
  function init (opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetChatHelper()

    return {
      // Public methods and variables
      /**
       * Determine if chat is disable
       * @method isChatDisabled
       * @return {Boolean} true if chat is disable. Otherwise returns false.
       */
      isChatDisabled: function () {
        if (_addon) {
          return _addon.IsChatDisabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine if private chat is disable
       * @method isPrivateChatDisabled
       * @return {Boolean} true if private chat is disable. Otherwise returns false.
       */
      isPrivateChatDisabled: function () {
        if (_addon) {
          return _addon.IsPrivateChatDisabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Send message to someone
       * @method sendChatToUser
       * @param {Object} user it's the user which you want to send to.
       * @param {String} msgContent the message content
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      sendChatToUser: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const user = setUserInfo(clientOpts.user)
            const msgContent = clientOpts.msgContent
            const SendChatToUserParams = new messages.SendChatToUserParams()
            SendChatToUserParams.setUser(user)
            SendChatToUserParams.setZnMsgcontent(msgContent)
            const bytes = SendChatToUserParams.serializeBinary()
            return _addon.SendChatToUser(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Send message to all
       * @method sendChatToAll
       * @param {String} msgContent the message content
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      sendChatToAll: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const msgContent = clientOpts.msgContent
            const SendChatToAllParams = new messages.SendChatToAllParams()
            SendChatToAllParams.setZnMsgcontent(msgContent)
            const bytes = SendChatToAllParams.serializeBinary()
            return _addon.SendChatToAll(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * delete chat message by message id.	
       * @method deleteChatMessage
       * @param {String} messageID
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
       */
      deleteChatMessage: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            if (clientOpts.messageID == undefined || clientOpts.messageID == "") {
              return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter
            }
            const messageID = clientOpts.messageID
            const DeleteChatMessageParams = new messages.DeleteChatMessageParams()
            DeleteChatMessageParams.setMessageid(messageID)
            const bytes = DeleteChatMessageParams.serializeBinary()
            return _addon.DeleteChatMessage(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
       /**
       * Determine whether the message can be delete.
       * @method canChatMessageBeDeleted
       * @param {String} messageID
       * @return {Boolean} true indicates the message can be delete. Otherwise false.	
       */
      canChatMessageBeDeleted: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            if (clientOpts.messageID == undefined || clientOpts.messageID == "") {
              return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter
            }
            const messageID = clientOpts.messageID
            const CanChatMessageBeDeletedParams = new messages.CanChatMessageBeDeletedParams()
            CanChatMessageBeDeletedParams.setMessageid(messageID)
            const bytes = CanChatMessageBeDeletedParams.serializeBinary()
            return _addon.CanChatMessageBeDeleted(bytes)
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
