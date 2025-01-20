<template>
  <div class="reaction">
    <ul class="reaction-group">
      <li v-for="(item, index) in emojiList" :key="index" @click="handleSendCmd(item)">
        <img :src="require(`../assets/images/${item}.png`)" :alt="`${item}.png`" />
      </li>
    </ul>
    <div class="reaction-raised-hand" @click="handleSendCmd('lowerhand')" v-if="isRaisedHand">
      <img src="../assets/images/raisehand.png" alt="raisehand.png" />
      <span>Lower Hand</span>
    </div>
    <div class="reaction-raised-hand" @click="handleSendCmd('raisehand')" v-else>
      <img src="../assets/images/raisehand.png" alt="raisehand.png" />
      <span>Raise Hand</span>
    </div>
  </div>
</template>

<script>
import { CmdTypes } from '../assets/js/cmd_defines'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk
const zoomVideoSDKCmd = zoomVideoSdk.getCmdHelper()

export default {
  props: ['parent', 'myselfInfo'],
  data() {
    return {
      emojiList: ['clap', 'thumbsup', 'joy', 'hushed', 'heart', 'tada'],
      reactionTimer: undefined
    }
  },
  computed: {
    isRaisedHand () {
      let raisedHandObj = this.$store.state.cmdRaisedHandMap
      let pUser = this.myselfInfo.pUser
      return raisedHandObj[pUser]
    }
  },
  methods: {
    handleSendCmd(item) {
      let reaction = item
      let pUser = this.myselfInfo.pUser
      let strCmd = `${CmdTypes.cmd_reaction}|${reaction}`
      let sendCommand = zoomVideoSDKCmd.sendCommand({strCmd})
      console.log('sendCommand', sendCommand, strCmd)
      if (reaction == 'raisehand') {
        let reactionObj = this.$store.state.cmdReactionMap
        if (reactionObj[pUser]) {
          let newReaction = {
            [pUser]: null
          }
          let newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
          this.$store.commit('setReactionMap', newReactionObj)
        }
        let handStatus = {
          [pUser]: reaction
        }
        let newRaisedHandObj = {...this.$store.state.cmdRaisedHandMap, ...handStatus}
        this.$store.commit('setRaisedHandMap', newRaisedHandObj)
      } else if (reaction == 'lowerhand') {
        let handStatus = {
          [pUser]: null
        }
        let newRaisedHandObj = {...this.$store.state.cmdRaisedHandMap, ...handStatus}
        this.$store.commit('setRaisedHandMap', newRaisedHandObj)
      } else {
        clearTimeout(this.reactionTimer)
        let newReaction = {
          [pUser]: reaction
        }
        let newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
        this.$store.commit('setReactionMap', newReactionObj)
        this.reactionTimer = setTimeout(() => {
          let newReaction = {
            [pUser]: null
          }
          newReactionObj = {...this.$store.state.cmdReactionMap, ...newReaction}
          this.$store.commit('setReactionMap', newReactionObj)
        }, 5000)
      }
      this.parent.isReactionLayerShown = false
    }
  }
}
</script>

<style lang="scss" scoped>
  .reaction {
    padding: 8px;
    width: 232px;
    height: 66px;
    background: #131619;
    border: 0.7px solid rgba(255, 255, 255, 0.12);
    box-shadow: 0px 6px 18px rgba(0, 0, 0, 0.2);
    border-radius: 12px;
    .reaction-group {
      overflow: hidden;
      li {
        float: left;
        width: 32px;
        height: 32px;
        border-radius: 8px;
        display: flex;
        justify-content: center;
        align-items: center;
        cursor: pointer;
        margin: 0 4px;
        &:first-child {
          margin-left: 0;
        }
        &:last-child {
          margin-right: 0;
        }
        &:hover {
          background: rgba(255, 255, 255, 0.18);
        }
        &:active {
          background: rgba(255, 255, 255, 0.27);
        }
        &>img {
          width: 24px;
        }
      }
    }
    .reaction-raised-hand {
      width: 100%;
      height: 32px;
      background: rgba(255, 255, 255, 0.09);
      border-radius: 8px;
      margin-top: 3px;
      display: flex;
      justify-content: center;
      align-items: center;
      &>img {
        width: 17px;
      }
      span {
        color: #FFFFFF;
        font-size: 13px;
        font-weight: bold;
        margin-left: 5px;
      }
      &:hover {
        background: rgba(255, 255, 255, 0.18);
      }
      &:active {
        background: rgba(255, 255, 255, 0.27);
      }
    }
  }
</style>
