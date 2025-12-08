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
       * Determine if the session supports join by phone or not.
       * @method isSupportPhoneFeature
       * @return {Boolean} True indicates join by phone is supported, otherwise false.
       */
      isSupportPhoneFeature: function () {
        if (_addon) {
          return _addon.IsSupportPhoneFeature()
        }
        return false
      },
      /**
       * Get the list of the country information where the session supports to join by telephone.
       * @method getSupportCountryInfo
       * @return {Array} If the function succeeds, returns an array of country information objects with the following members:
       *   - {String} countryID - The country ID
       *   - {String} countryName - The country name
       *   - {String} countryCode - The country code
       *   Otherwise returns ZoomVideoSDKErrors error code.
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
       * Invite the specified user to join the session by call out.
       * @method inviteByPhone
       * @param {String} countryCode The country code of the specified user must be in the support list.
       * @param {String} phoneNumber The phone number of specified user.
       * @param {String} name The screen name of the specified user in the session.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
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
       * @param {Boolean} bGreeting true: When joining the session, play a greeting prompt tone, otherwise not.
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
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
       * @return {Number} If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed.
       */
      cancelInviteByPhone: function () {
        if (_addon) {
          return _addon.CancelInviteByPhone()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the status of the invitation by phone.
       * @method getInviteByPhoneStatus
       * @return {Number} If the function succeeds, returns the PhoneStatus of the invitation by phone.
       */
      getInviteByPhoneStatus: function () {
        if (_addon) {
          return _addon.GetInviteByPhoneStatus()
        }
        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
      },
      /**
       * Get the list of dial in numbers supported by session.
       * @method getSessionDialInNumbers
       * @return {Array} If the function succeeds, returns an array of dial in number information objects with the following members:
       *   - {String} countryID - The country ID of the current information.
       *   - {String} countryName - The country name of the current information.
       *   - {String} countryCode - The country code of the current information.
       *   - {String} number - The telephone number of the current information.
       *   - {String} displayNumber - The display number of the current information.
       *   - {Number} type - Call type. For more details, see ZoomVideoSDKDialInNumType.
       *   - {Boolean} isDedicateID - Is the dial number an account dedicated number.
       */
      getSessionDialInNumbers: function () {
        if (_addon) {
          const result = _addon.GetSessionDialInNumbers()
          const message = messages.GetSessionDialInNumbersList.deserializeBinary(result)
          const tempList = message.getSessiondialinnumbersinfoList()
          let sessionDialInNumbersList = []
          for (let val of tempList) {
            let obj = {
              countryID: val.getCountryid(),
              countryName: val.getCountryname(),
              countryCode: val.getCountrycode(),
              number: val.getNumber(),
              displayNumber: val.getDisplaynumber(),
              type: val.getType(),
              isDedicateID: val.getIsdedicateid()
            }
            sessionDialInNumbersList.push(obj)
          }
          return sessionDialInNumbersList
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
