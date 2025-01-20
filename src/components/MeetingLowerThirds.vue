<template>
  <div :class="['lower-thirds', {'when-camera-controlled': isCameraControlled||isSharingSecondCamera}]">
    <div class="bar" :style="{'background': userLowerThirdMap[2]}"></div>
    <div :class="['content', {'vertical-middle': !userLowerThirdMap[1]}]">
      <div class="username text-overflow">{{userLowerThirdMap[0]}}</div>
      <div class="department"
        v-if="userLowerThirdMap[1]"
        :style="{'background': userLowerThirdMap[2]?`linear-gradient(-65deg, transparent 6px, ${userLowerThirdMap[2]} 0)`:null}">
        <span :class="['text-overflow', {'dark-title': userLowerThirdMap[2]=='#66CC84'||userLowerThirdMap[2]=='#FF8422'||userLowerThirdMap[2]=='#FFBF39'}]">{{userLowerThirdMap[1]}}</span>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  props: ['userLowerThirdMap', 'isCameraControlled', 'isSharingSecondCamera']
}
</script>

<style lang="scss" scoped>
  .lower-thirds {
    width: 162px;
    height: 40px;
    padding: 8px 10px;
    background: #131619;
    border: 1px solid rgba(255, 255, 255, 0.09);
    border-radius: 12px;
    position: absolute;
    top: 42px;
    left: 8px;
    display: flex;
    .bar {
      width: 4px;
      height: 100%;
      background: #444B53;
      border-radius: 2px;
    }
    .content {
      margin-left: 12px;
      position: relative;
      .username {
        font-size: 16px;
        font-weight: bold;
        height: 20px;
        line-height: 20px;
        color: #F7F9FA;
        max-width: 145px;
      }
      .department {
        width: 170px;
        position: absolute;
        font-size: 13px;
        line-height: 16px;
        color: #F7F9FA;
        padding: 0 3px;
        border-radius: 2px;
        background: linear-gradient(-65deg, transparent 6px, #444B53 0);
        display: flex;
        align-items: center;
        span {
          width: 93%;
        }
      }
      .dark-title {
        color: #444B53;
      }
    }
    .vertical-middle {
      display:flex;
      align-items:center;
    }
  }
  .when-camera-controlled {
    top: 66px;
  }
</style>
