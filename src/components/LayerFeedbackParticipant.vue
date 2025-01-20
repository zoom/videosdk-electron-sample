<template>
  <div class="feedback">
    <i class="el-icon-close icon-close right" @click="handleClose"></i>
    <div class="feedback-tip" v-if="isFeedbackTipShown">
      <div><i class="el-icon-success icon-success"></i></div>
      <div class="main-tip">Thank you for your feedback</div>
      <div class="second-tip">We really appreciate your time</div>
    </div>
    <div class="feedback-content" v-else> 
      <div class="title">How do you like our session?</div>
      <div class="participant-feedback">
        <span v-for="(item, index) in feedbackOptions" :key="index" @click="feedbackChecked=item">
          <IconFeedbackOptions :active="feedbackChecked==item" :type="item" />
        </span>
      </div>
      <div class="participant-checked">
       <span v-if="feedbackChecked">{{feedbackChecked}}!</span>
      </div>
      <div class="btn-bottom">
        <el-button type="primary" size="mini" :disabled="feedbackChecked==undefined" class="btn-start" @click="handleSubmit">Submit</el-button>
      </div>
    </div> 
  </div>
</template>

<script>
import { CmdTypes, FeedbackTypes } from '../assets/js/cmd_defines'
import { findKey } from '../assets/js/util'
import IconFeedbackOptions from './Icon/IconFeedbackOptions'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKCmd = zoomVideoSdk.getCmdHelper()

export default {
  props: ['parent', 'isStartFeedback'],
  data() {
    return {
      isFeedbackTipShown: false,
      feedbackOptions: ['Very Satisfied', 'Satisfied', 'Neutral', 'Unsatisfied', 'Very Unsatisfied'],
      feedbackChecked: undefined
    }
  },
  watch: {
    isStartFeedback (val, oldVal) {
      if (val) {
        this.feedbackChecked = undefined
        this.isFeedbackTipShown = false
      }
    }
  },
  methods: {
    handleSubmit() {
      let feedback = findKey(FeedbackTypes, this.feedbackChecked)
      let strCmd = `${CmdTypes.cmd_feedback_submit}|${feedback}`
      let sendCommand = zoomVideoSDKCmd.sendCommand({strCmd})
      console.log('sendCommand', sendCommand, strCmd)
      this.isFeedbackTipShown = true
      setTimeout(() => {
        this.handleClose()
      }, 5 * 1000);
    },
    handleClose() {
      this.feedbackChecked = undefined
      this.isFeedbackTipShown = false
      this.parent.isFeedbackLayerShown = false
    }
  },
  components: {
    IconFeedbackOptions
  }
}
</script>

<style lang="scss" scoped>
  .feedback {
    width: 350px;
    padding: 24px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    overflow: hidden;
    .icon-close {
      color: rgba(255, 255, 255, 0.54);
      font-size: 16px;
      cursor: pointer;
    }
    .feedback-content, .feedback-tip {
      min-height: 110px;
      text-align: center;
      margin-top: 8px;
    }
    .feedback-tip {
      color: #F7F9FA;
      min-height: 163px;
      .icon-success {
        color: #23D959;
        font-size: 40px;
      }
      .main-tip {
        font-weight: bold;
        font-size: 24px;
        line-height: 32px;
        margin: 16px 0;
      }
      .second-tip {
        font-size: 15px;
        line-height: 20px;
      }
    }
    .feedback-content {
      .title {
        font-size: 23px;
        line-height: 32px;
        color: #F7F9FA;
      }
      .participant-feedback {
        display: flex;
        justify-content: center;
        margin: 10px 0 16px;
        .svg {
          cursor: pointer;
          margin: 0 12px;
        }
      }
      .participant-checked {
        font-size: 15px;
        height: 20px;
        line-height: 20px;
        color: #F7F9FA;
      }
    }
    .btn-bottom {
      margin-top: 16px;
      text-align: center;
      button {
        border-radius: 8px;
      }
    }
  }
</style>
