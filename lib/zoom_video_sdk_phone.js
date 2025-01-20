import { ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

export default (function () {
  var instance
  /**
    * Return an instance to manage phone invitations during a video SDK session.
    * @module zoom_video_sdk_phone
    * @return {ZoomVideoSDKLocalPhone}
    */
  function init(opts) {
    const clientOpts = {...opts}
    // Private methods and variables
    if (!clientOpts.addon) {
      return null
    }
    const _addon = clientOpts.addon.GetPhoneHelper()

    return {
      // Public methods and variables
      /**
       * Determine whether the session supports to join by the phone or not.
       * @method isSupportPhoneFeature
       * @return {Boolean} true indicates to support to join by phone. false not.
       */
      isSupportPhoneFeature: function () {
        if (_addon) {
          return _addon.IsSupportPhoneFeature()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the list of the country information where the session supports to join by telephone.
       * @method getSupportCountryInfo
       * @return {Array} List of the country information returns if the session supports to join by telephone. Otherwise null.
       */
      getSupportCountryInfo: function () {
        if (_addon) {
          const result = _addon.GetSupportCountryInfo()
          const message = messages.GetPhoneSupportCountryList.deserializeBinary(result)
          const tempList = message.getPhonesupportcountryinfoList()
          let phoneSupportCountryList = []
          for (let val of tempList) {
            let obj = {
              countryID: val.getCountryid(),
              countryName: val.getCountryname(),
              countryCode: val.getCountrycode()
            }
            phoneSupportCountryList.push(obj)
          }
          return phoneSupportCountryList
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Invite the specified user to join the session by call out. deprecated This interface is marked as deprecated, and is replaced by invitePhoneUser(const InvitePhoneUserInfo& inviteInfo).
      * @method inviteByPhone
      * @param {String} countryCode The country code of the specified user must be in the support list.
      * @param {String} phoneNumber The phone number of specified user.
      * @param {String} name The screen name of the specified user in the session.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      inviteByPhone: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const countryCode = clientOpts.countryCode
            const phoneNumber = clientOpts.phoneNumber
            const name = clientOpts.name
            const InviteByPhoneParams = new messages.InviteByPhoneParams()
            InviteByPhoneParams.setCountrycode(countryCode)
            InviteByPhoneParams.setPhonenumber(phoneNumber)
            InviteByPhoneParams.setName(name)
            const bytes = InviteByPhoneParams.serializeBinary()
            return _addon.InviteByPhone(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
      * Invite the specified user to join the session by call out.
      * @method invitePhoneUser
      * @param {String} countryCode The country code of the specified user must be in the support list.
      * @param {String} phoneNumber The phone number of specified user.
      * @param {String} name The screen name of the specified user in the session.
      * @param {Boolean} bPressOne true: Need press number one to agree to join the session, otherwise not.
      * @param {Boolean} bGreeting true: When joining the session, play a greeting prompt tone., otherwise not.
      * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
        Otherwise failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
      */
      invitePhoneUser: function (opts) {
        if (_addon) {
          const clientOpts = {...opts}
          try {
            const countryCode = clientOpts.countryCode
            const phoneNumber = clientOpts.phoneNumber
            const name = clientOpts.name
            const bPressOne = clientOpts.bPressOne == undefined ? true : clientOpts.bPressOne
            const bGreeting = clientOpts.bGreeting == undefined ? true : clientOpts.bGreeting
            const InvitePhoneUserParams = new messages.InvitePhoneUserParams()
            InvitePhoneUserParams.setCountrycode(countryCode)
            InvitePhoneUserParams.setPhonenumber(phoneNumber)
            InvitePhoneUserParams.setName(name)
            InvitePhoneUserParams.setBpressone(bPressOne)
            InvitePhoneUserParams.setBgreeting(bGreeting)
            const bytes = InvitePhoneUserParams.serializeBinary()
            return _addon.InvitePhoneUser(bytes)
          } catch (error) {
            return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
          }
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Cancel the invitation that is being invited by phone.
       * @method cancelInviteByPhone
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      cancelInviteByPhone: function () {
        if (_addon) {
          return _addon.CancelInviteByPhone()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the process of the invitation by phone.
       * @method getInviteByPhoneStatus
       * @return {Number} If the function succeed, the return value is ZoomVideoSDKErrors_Success.
          Otherwise failed. To get extended error information, see {@link ZoomVideoSDKErrors} enum.
       */
      getInviteByPhoneStatus: function () {
        if (_addon) {
          return _addon.GetInviteByPhoneStatus()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      }
    };
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  }
})()
