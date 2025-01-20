<template>
  <div class="feedback" ref="feedback">
    <div class="title">
      Feedbacks
      <span class="result-type right">{{totalSubmit}} responses</span>
    </div>
    <div class="feedback-content">
      <div class="feedback-title">How do you like our session?</div> 
      <div class="feedback-item feedback-result-item" v-for="(item, index) in feedbackOptions" :key="index">
        <IconFeedbackOptions :type="item" />
        <div>
          <span class="option">{{item}}</span>
          <template v-if="feedbackSubmitMap && feedbackSubmitMap[item]">
            <el-progress :percentage="Math.round(feedbackSubmitMap[item] / totalSubmit)*100"></el-progress>
            <span class="rate">{{feedbackSubmitMap[item]}} responses</span>
          </template>
          <template v-else>
            <el-progress :percentage="0"></el-progress>
            <span class="rate">0 responses</span>
          </template>
        </div>
      </div>
    </div> 
    <div class="btn-bottom">
      <span class="tip-pushed" v-if="isSendSurvey"><i class="el-icon-success"></i>Pushed!</span>
      <div class="btn-survey" title="Push feedback survey to everyone in the session" @click="handleSurvey" v-else>Push Feedback Survey</div>
      <el-button type="primary" size="mini" class="btn-start right" @click="handleClose">Close</el-button>  
    </div>
    <img :src="require(`../assets/images/tip_feedback.png`)" class="feedback-tip" :style="{'left': feedbackTipPosition}" v-if="!hasShownFeedbackTip" @click="handleFeedbackTip" />
  </div>
</template>

<script>
import { CmdTypes } from '../assets/js/cmd_defines'
import IconFeedbackOptions from './Icon/IconFeedbackOptions'
import config from '../../config.json'
const fs = window.require('fs')
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKCmd = zoomVideoSdk.getCmdHelper()

export default {
  props: ['parent', 'feedbackSubmitMap', 'totalSubmit'],
  data() {
    return {
      feedbackOptions: ['Very Satisfied', 'Satisfied', 'Neutral', 'Unsatisfied', 'Very Unsatisfied'],
      isSendSurvey: false,
      feedbackTipPosition: '',
      hasShownFeedbackTip: config.hasShownFeedbackTip
    }
  },
  methods: {
    handleSurvey () {
      this.handleFeedbackTip()
      let strCmd = `${CmdTypes.cmd_feedback_push}`
      let sendCommand = zoomVideoSDKCmd.sendCommand({strCmd})
      console.log('sendCommand', sendCommand, strCmd)
      this.isSendSurvey = true
      setTimeout(() => {
        this.isSendSurvey = false
      }, 60 * 1000);
    },
    handleClose() {
      this.parent.isFeedbackLayerShown = false
    },
    handleFeedbackTip() {
      if (!this.hasShownFeedbackTip) {
        this.hasShownFeedbackTip = true
        const configPath = './config.json'
        let config = fs.readFileSync(configPath)
        config = JSON.parse(config)
        config.hasShownFeedbackTip = true
        fs.writeFileSync(configPath, JSON.stringify(config, null, 2))
      }
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
  .title {
    font-weight: 500;
    font-size: 20px;
    line-height: 24px;
    color: #F7F9FA;
    margin-bottom: 16px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    .result-type {
      font-size: 13px;
      color: #98A0A9;
    }
  }
  .feedback-content {
    min-height: 224px;
    .feedback-title {
      font-size: 24px;
      line-height: 32px;
      color: #F7F9FA;
      font-size: 24px;
      line-height: 32px;
      margin-bottom: 16px;
      word-wrap: break-word;
      word-break: break-all;
    }
    .feedback-item {
      height: 40px;
      margin: 8px 0;
      color: #F7F9FA;
      background: #252A30;
      border-radius: 10px;
    }
    .feedback-result-item {
      height: 62px;
      display: flex;
      align-items: center;
      padding-left: 12px;
      .svg {
        width: 48px;
      }
      &>div {
        width: 100%;
        position: relative;
        .option {
          font-size: 14px;
          line-height: 24px;
          color: #F5F5F5;
          position: absolute;
          top: 6px;
        }
        .rate {
          font-size: 12px;
          line-height: 16px;
          color: #6E7680;
          position: absolute;
          bottom: 6px;
        }
        .el-progress {
          padding: 24px 0;
        }
      }
    }
  }
  .btn-bottom {
    margin-top: 28px;
    position: relative;
    button {
      border-radius: 8px;
    }
    .tip-pushed {
      font-weight: 500;
      font-size: 14px;
      line-height: 20px;
      color: #F7F9FA;
      i {
        color: #23D959;
        font-size: 16px;
        margin-right: 7px;
      }
    }
    .btn-survey {
      display: inline-block;
      font-weight: 500;
      font-size: 14px;
      color: #4793F1;
      padding: 6px 16px;
      border-radius: 8px;
      cursor: pointer;
      &:hover {
        background: #001F45;
      }
    }
  }
  .feedback-tip {
    width: 283px;
    position: absolute;
    bottom: 25px;
    left: -15px;
    cursor: pointer;
  }
}
</style>
