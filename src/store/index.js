import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    token: '',
    renderAddon: {},
    joinSessionParams: {},
    toolbarStatus: {
      isAudioMute: false,
      isVideoMute: false,
      liveOnNum: 0
    },
    isFillScreen: false,
    isLowerThird: false,
    isStartFeedback: false,
    cmdFeedbackSubmitMap: {},
    cmdRaisedHandMap: {},
    cmdReactionMap: {},
    cmdLowerThirdMap: {}
  },
  mutations: {
    setToken (state, token) {
      state.token = token
    },
    setRenderAddon (state, renderAddon) {
      state.renderAddon = renderAddon
    },
    setJoinSessionParams (state, joinSessionParams) {
      state.joinSessionParams = joinSessionParams
    },
    setToolbarStatus (state, toolbarStatus) {
      state.toolbarStatus = toolbarStatus
    },
    setFillScreen (state, isFillScreen) {
      state.isFillScreen = isFillScreen
    },
    setLowerThird (state, isLowerThird) {
      state.isLowerThird = isLowerThird
    },
    setStartFeedback (state, isStartFeedback) {
      state.isStartFeedback = isStartFeedback
    },
    setFeedbackSubmitMap (state, feedbackSubmitMap) {
      state.cmdFeedbackSubmitMap = feedbackSubmitMap
    },
    setRaisedHandMap (state, cmdRaisedHandMap) {
      state.cmdRaisedHandMap = cmdRaisedHandMap
    },
    setReactionMap (state, cmdReactionMap) {
      state.cmdReactionMap = cmdReactionMap
    },
    setLowerThirdMap (state, cmdLowerThirdMap) {
      state.cmdLowerThirdMap = cmdLowerThirdMap
    }
  },
  actions: {
  },
  modules: {
  }
})
