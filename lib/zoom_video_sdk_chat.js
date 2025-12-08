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
       * Determine whether chat is disabled.
       * @method isChatDisabled
       * @return {Boolean} True if chat is disabled, otherwise false.
       */
      isChatDisabled: function () {
        if (_addon) {
          return _addon.IsChatDisabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Determine whether private chat is disabled.
       * @method isPrivateChatDisabled
       * @return {Boolean} True if private chat is disabled, otherwise false.
       */
      isPrivateChatDisabled: function () {
        if (_addon) {
          return _addon.IsPrivateChatDisabled()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Send a chat message to a specific user.
       * @method sendChatToUser
       * @param {Object} user The receiver.
       * @param {String} msgContent The message content.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
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
       * Send a chat message to all users.
       * @method sendChatToAll
       * @param {String} msgContent The message content.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
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
       * Delete a specific chat message from the Zoom server. This does not delete the message in your user interface.
       * @method deleteChatMessage
       * @param {String} messageID The message ID.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
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
       * Determine if a specific message can be deleted.
       * @method canChatMessageBeDeleted
       * @param {String} messageID The message ID.
       * @return {Boolean} True if the message can be deleted, otherwise false.
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
