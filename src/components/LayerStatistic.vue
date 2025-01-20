<template>
  <div>
    <div class="statistic" @click="handleStatisticLayer">
      <div class="title">
        Statistics
        <i @click="handleClose" class="right icon-close el-icon-close"></i>
      </div>
      <el-tabs v-model="activeTab" stretch @tab-click="handleTab">
        <el-tab-pane label="Audio" name="audio"></el-tab-pane>
        <el-tab-pane label="Video" name="video"></el-tab-pane>
        <el-tab-pane label="Share" name="share"></el-tab-pane>
      </el-tabs>
      <el-table :data="statisticData" stripe style="width: 100%">
        <el-table-column prop="type" label="Statistical Items" width="150"></el-table-column>
        <el-table-column prop="send" label="Send" :show-overflow-tooltip="true" width="150"></el-table-column>
        <el-table-column prop="receive" label="Receive" :show-overflow-tooltip="true" width="150"></el-table-column>
      </el-table>
    </div>
  </div>
</template>

<script>
const remote = window.require('@electron/remote')
const zoomVideoSdk = remote.app.zoomVideoSdk

export default {
  data() {
    return {
      zoomVideoSDKSessionInfo: zoomVideoSdk.getSessionInfo(),
      activeTab: 'audio',
      tab: {
        name: 'audio'
      },
      statisticData: [{
        type: 'frequency',
        send: '-',
        receive: '-'
      }, {
        type: 'latency',
        send: '-',
        receive: '-'
      }, {
        type: 'jitter',
        send: '-',
        receive: '-'
      }, {
        type: 'packetLossAvg ',
        send: '-',
        receive: '-'
      }, {
        type: 'packetLossMax ',
        send: '-',
        receive: '-'
      }]
    }
  },
  methods: {
    handleStatisticLayer () {
      this.$EventBus.$emit('change')
    },
    handleClose () {
      this.$emit('updateStatisticStatus', false)
    },
    updateStatisticData(index, key) {
      if (this.statisticData[index][key] != '-') {
        switch (this.statisticData[index].type) {
          case 'packetLossAvg': case 'packetLossMax':
            this.statisticData[index][key] = parseFloat(this.statisticData[index][key]).toFixed(2) + ' %'
            break;
          case 'frequency':
            this.statisticData[index][key] = parseInt(this.statisticData[index][key]) + ' KHz'
            break;
          case 'latency': case 'jitter':
            this.statisticData[index][key] = parseInt(this.statisticData[index][key]) + ' ms'
            break;
          default:
            this.statisticData[index][key] = parseInt(this.statisticData[index][key])
            break;
        }
      }
    },
    handleTab(tab, event) {
      this.tab = tab
      let statisticinfoList
      switch (tab.name) {
        case 'audio':
          statisticinfoList = this.zoomVideoSDKSessionInfo.getSessionAudioStatisticInfo()
          break;
        case 'video':
          statisticinfoList = this.zoomVideoSDKSessionInfo.getSessionVideoStatisticInfo()
          break;
        case 'share':
          statisticinfoList = this.zoomVideoSDKSessionInfo.getSessionShareStatisticInfo()
          break;
      }
      let index = 0
      for (let i in statisticinfoList[0]) {
        this.statisticData[index].type = i
        this.statisticData[index].send = statisticinfoList[0][i] ? statisticinfoList[0][i] : '-'
        this.statisticData[index].receive = statisticinfoList[1][i] ? statisticinfoList[1][i] : '-'
        this.updateStatisticData(index, 'send')
        this.updateStatisticData(index, 'receive')
        index++
      }
      setTimeout(() => {
        this.handleTab(this.tab)
      }, 5000);
    }
  },
  mounted() {
    this.handleTab(this.tab)
    this.$EventBus.$on('statistics', () => {
      this.handleTab(this.tab)
    })
  },
  beforeDestroy () {
    this.$EventBus.$off('statistics')
  }
}
</script>

<style lang="scss" scoped>
  .statistic {
    padding: 16px;
    background: #242424;
    border: 0.5px solid rgba(0, 0, 0, 0.25);
    box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.3);
    border-radius: 12px;
    .title {
      font-weight: bold;
      font-size: 16px;
      line-height: 16px;
      color: #f5f5f5;
      margin-bottom: 16px;
      .icon-close {
        cursor: pointer;
      }
    }
  }
</style>
<style lang="scss">
  .statistic {
    .el-tabs__item {
      color: #fff;
      &.is-active, &:hover {
        color: #0E72ED;
      }
    }
    .el-tabs__active-bar {
      width: 124px !important;
    }
  }
</style>
