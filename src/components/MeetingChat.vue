<template>
  <div>
    <div class="chat-box" v-if="isChatShown">
      <div class="chat-list" :class="[isFocusWindow?'':'blur-meeting']">
        <ul>
          <li v-for="(item, index) in chatList" :key="index" :id="`chat${index}`">
            <span :style="{'color': item.color}">{{item.senderDisplayName}}: </span>
            <span class="chat-content">{{item.messageContent}}</span>
          </li>
        </ul>
      </div>
      <el-input
        v-show="isFocusWindow"
        :class="[showChatInput?'input-max':'input-min', showChatSend?'input-focus':'']"
        :disabled="!showChatInput"
        :placeholder="showChatInput?'Type comment here…':''"
        v-model="msgContent"
        maxlength="1024"
        @keyup.enter.native="handleSend"
        @focus="handleFocus"
        @blur="handleBlur">
        <i slot="prefix" class="el-input__icon iconfont" @click="handleShowInput">
          <div class="chat-name" :style="{'color': myselfInfo.color}" v-if="myselfInfo.username">{{myselfInfo.avatarName}}</div>
        </i>
        <span slot="suffix" v-if="showChatInput && showChatSend">
          <span v-if="chatCanSend" @click="handleSend">
            <IconChatSend class="icon-send" />
          </span>
          <IconChatUnSend class="icon-unsend" v-else />
        </span>
      </el-input>
    </div>
  </div>
</template>

<script>
import IconChatUnSend from './Icon/IconChatUnSend'
import IconChatSend from './Icon/IconChatSend'
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  props: ['isFocusWindow', 'allUserList', 'isChatShown', 'myselfInfo'],
  data () {
    return {
      timer: null,
      chatTimer: null,
      showChatInput: false,
      showChatSend: false,
      chatCanSend: false,
      msgContent: '',
      nameList: [],
      chatList: [],
      selfColor: '',
      zoomVideoChat: zoomVideoSdk.getChatHelper(),
      maxDisplayChatLength: 4
    }
  },
  watch: {
    msgContent (val, oldVal) {
      if (val) {
        this.chatCanSend = true
      } else {
        this.chatCanSend = false
      }
    }
  },
  methods: {
    handleShowInput () {
      if (!this.myselfInfo) {
        return
      }
      this.showChatInput = !this.showChatInput
      if (!this.showChatInput) {
        this.msgContent = ''
      }
      this.showChatSend = false
    },
    handleFocus () {
      this.$emit('updateInputStatus', true)
      this.$parent.focusFloatWindow()
      this.showChatSend = true
    },
    handleBlur () {
      this.$emit('updateInputStatus', false)
      this.$parent.focusFloatWindow()
      setTimeout(() => {
        this.showChatSend = false
      }, 120)
    },
    handleSend () {
      this.$emit('updateInputStatus', false)
      this.$parent.focusFloatWindow()
      if (!this.msgContent) {
        return
      }
      const data = {
        msgContent: this.msgContent
      }
      const sendChatToAll = this.zoomVideoChat.sendChatToAll(data)
      if (sendChatToAll === 0) {
        this.msgContent = ''
      }
    },
    onChatNewMessageNotify (data) {
      let color
      for (let item of this.allUserList) {
        if (item.user.pUser === data.getPsender()) {
          color = item.color
          break
        }
      }
      const obj = {
        senderDisplayName: data.getSendername(),
        messageContent: data.getMessagecontent(),
        color: color
      }
      this.chatList.push(obj)
      this.$parent.focusFloatWindow()
      this.$nextTick(() => {
        const container = document.querySelector('.chat-list ul')
        if (container) {
          container.scrollTop = container.scrollHeight
        }
      })
    }
  },
  components: {
    IconChatUnSend,
    IconChatSend
  }
}
</script>

<style lang="scss" scoped>
  .chat-box {
    width: 346px;
    height: 193px;
    position: absolute;
    left: 12px;
    bottom: 22px;
    .blur-meeting {
      bottom: -55px;
    }
    .chat-list {
      height: 145px;
      overflow-y: auto;
      margin-bottom: 12px;
      position: relative;
      ul {
        position: absolute;
        bottom: 0;
        max-height: 100%;
        overflow-y: scroll;
        li {
          width: fit-content;
          color: #F5F5F5;
          font-size: 14px;
          font-weight: 100;
          padding: 8.01px 12px;
          margin: 4px 0;
          background: rgba(26, 26, 26, 0.1);
          backdrop-filter: blur(12px);
          border-radius: 12px;
          word-wrap: break-word;
          word-break: break-all;
          .chat-content {
            white-space: pre-wrap;
          }
          &:nth-last-child(4) {
            background: linear-gradient(rgba(26, 26, 26, 0.1),rgba(26, 26, 26, 0.2));
          }
          &:nth-last-child(3) {
            background: linear-gradient(rgba(26, 26, 26, 0.2),rgba(26, 26, 26, 0.7));
          }
          &:nth-last-child(2), &:nth-last-child(1) {
            background: rgba(26, 26, 26, 0.8);
          }
        }
        &::-webkit-scrollbar {
          display: none;
        }
      }
    }
    .input-max {
      width: 200px;
    }
    .input-min {
      width: 36px;
    }
    .iconfont {
      cursor: pointer;
      display: flex;
      justify-content: center;
      align-items: center;
      .chat-name {
        width: 24px;
        height: 24px;
        background: rgba(255, 255, 255, 0.09);
        border-radius: 6px;
        display: flex;
        align-items: center;
        justify-content: center;
        letter-spacing: -0.01em;
        color: #E8C0C3;
        font-style:normal;
        font-size: 0.8em;
      }
      img {
        width: 24px;
        height: 24px;
        border-radius: 6px;
      }
    }
    .icon-send, .icon-unsend {
      margin-top: 6px;
    }
    .icon-send {
      cursor: pointer;
    }
    .icon-unsend {
      cursor: not-allowed;
    }
  }
</style>
<style lang="scss">
  .chat-box {
    .el-input .el-input__inner {
      color: rgba(255, 255, 255, 0.54);
      background: rgba(26, 26, 26, 0.8);
      border: 1px solid rgba(255, 255, 255, 0.09);
      box-sizing: border-box;
      backdrop-filter: blur(16px);
      border-radius: 8px;
      height: 36px;
      line-height: 36px;
      padding-left: 36px;
      &::-webkit-input-placeholder {
        color: rgba(255, 255, 255, 0.54);
      }
    }
    .input-min .el-input__inner {
      padding: 6px;
    }
    .input-focus .el-input__inner {
      border-color: #4F9AF7;
    }
  }
</style>
