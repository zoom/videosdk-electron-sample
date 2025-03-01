import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import './assets/style/index.scss'
import './plugins/element.js'

Vue.config.productionTip = false
Vue.prototype.$EventBus = new Vue()

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
