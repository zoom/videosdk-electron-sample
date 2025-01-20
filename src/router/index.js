import Vue from 'vue'
import VueRouter from 'vue-router'
const { ipcRenderer: ipc } = window.require('electron')

const originalPush = VueRouter.prototype.push
VueRouter.prototype.push = function push (location) {
  return originalPush.call(this, location).catch(err => err)
}
Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'index',
    component: () => import(/* webpackChunkName: "index" */ '../views/Index.vue')
  },
  {
    path: '/create',
    name: 'create',
    component: () => import(/* webpackChunkName: "create" */ '../views/CreateOrJoin.vue')
  },
  {
    path: '/meeting',
    name: 'meeting',
    component: () => import(/* webpackChunkName: "meeting" */ '../views/Meeting.vue')
  },
  {
    path: '/share',
    name: 'share',
    component: () => import(/* webpackChunkName: "share" */ '../views/Share.vue')
  },
  {
    path: '/error',
    name: 'error',
    component: () => import(/* webpackChunkName: "error" */ '../views/Error.vue')
  },
  {
    path: '*',
    redirect: '/'
  }
]

const router = new VueRouter({
  routes
})

router.afterEach((to, from) => {
  switch (to.name) {
    case 'meeting':
      setTimeout(() => {
        ipc.send('meeting-window')
      }, 50);
      break;
    case 'index': case 'create': case 'error':
      setTimeout(() => {
        ipc.send('mini-window')
      }, 50);
      break;
  }
})

export default router
