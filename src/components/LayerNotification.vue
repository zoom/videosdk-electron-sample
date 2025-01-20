<template>
  <div class="layer-notification">
    {{notificationContent}}
  </div>
</template>

<script>
export default {
  props: ['notificationContent']
}
</script>

<style lang="scss" scoped>
  .layer-notification {
    display: flex;
    flex-direction: row;
    align-items: center;
    padding: 8px 16px;
    min-height: 40px;
    position: absolute;
    left: 50%;
    top: 42px;
    transform: translateX(-50%);
    color: #F7F9FA;
    background: #252A30;
    border-radius: 10px;
    z-index: var(--video-top-level);
  }
</style>