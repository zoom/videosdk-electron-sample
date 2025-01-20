'use strict'

import { app, protocol, ipcMain, BrowserWindow, nativeTheme, screen, Menu } from 'electron'
import {
  createProtocol,
  installVueDevtools
} from 'vue-cli-plugin-electron-builder/lib'

import ZoomVideoSDK from '../lib/zoom_video_sdk.js'
import { configDomain } from '../config.json'

const { execSync } = require('child_process')
const isDevelopment = process.env.NODE_ENV !== 'production'
const remote = require('@electron/remote/main')
remote.initialize()

const { platform, arch } = process
app.platform = platform
app.arch = arch

if (platform === 'darwin') {
  if (nativeTheme) {
    nativeTheme.themeSource = 'light'
  }
  const template = [
    {
      label: app.getName(),
      submenu: [
        { label: "Quit", accelerator: "CmdOrCtrl+Q", click() { app.quit() }}
      ]
    }, 
    {
      label: "Edit",
      submenu: [
        { label: "Copy", accelerator: "CmdOrCtrl+C", selector: "copy:" },
        { label: "Paste", accelerator: "CmdOrCtrl+V", selector: "paste:" },
        { label: "Cut", accelerator: "CmdOrCtrl+X", selector: "cut:" },
        { label: "selectAll", accelerator: "CmdOrCtrl+A", selector: "selectAll:" }
      ]
    }
  ]
  const menu = Menu.buildFromTemplate(template)
  Menu.setApplicationMenu(menu)
} 

if (platform === 'win32') {
  app.disableHardwareAcceleration()
  const gotTheLock = app.requestSingleInstanceLock()
  if (!gotTheLock) {
    app.quit()
  } else {
    app.on('second-instance', (event, commandLine, workingDirectory) => {
      // Someone tried to run a second instance, we should focus our window.
      if (mainWindow) {
        if (mainWindow.isMinimized()) mainWindow.restore()
        mainWindow.focus()
      }
    })
  }
}

const zoomVideoSdk = ZoomVideoSDK.getInstance()
app.zoomVideoSdk = zoomVideoSdk
app.allowRendererProcessReuse = false

const createZoomVideoSDKObj = zoomVideoSdk.createZoomVideoSDKObj()
console.log('createZoomVideoSDKObj', createZoomVideoSDKObj)

let domain = configDomain ? configDomain: 'https://www.zoom.us'
console.log('init domain is', domain)
let screenSize

const initObj = {
  domain: domain,
  logFilePrefix: 'sdk',
  enableLog: true,
  audioRawDataMemoryMode: 0,
  videoRawDataMemoryMode: 0,
  shareRawDataMemoryMode: 0
}

const initialize = zoomVideoSdk.initialize(initObj)
console.log('initialize', initialize)

// Keep a global reference of the window object, if you don't, the window will
// be closed automatically when the JavaScript object is garbage collected.
let mainWindow
let shareWindow = null
global.muteStatus = {}

// Scheme must be registered before the app is ready
try {
  protocol.registerSchemesAsPrivileged([{ scheme: 'app', privileges: { secure: true, standard: true } }]) 
} catch (error) {
  console.log(error)
}

ipcMain.on('setDomain', (event, arg) => {
  domain = arg
})
ipcMain.on('setToolbarStatus', (event, arg) => {
  global.muteStatus = arg
  if (shareWindow) {
    shareWindow.webContents.send('getToolbarStatus', arg)
  }
})
ipcMain.on('setVideoList', () => {
  if (mainWindow) {
    mainWindow.webContents.send('setVideoList')
  }
})
ipcMain.on('min', e => mainWindow.minimize())
ipcMain.on('max', e => mainWindow.maximize())
ipcMain.on('toggle', e => {
  if (mainWindow.isMaximized()) {
    mainWindow.unmaximize()
  } else {
    mainWindow.maximize()
  }
})

ipcMain.on('close', e => mainWindow.close())
ipcMain.on('meeting-window', () => {
  mainWindow.setSize(1120, 630)
  mainWindow.setResizable(true)
  mainWindow.setMinimumSize(735, 420)
  mainWindow.center()
})
ipcMain.on('mini-window', () => {
  if (mainWindow.isMaximized()) {
    mainWindow.restore()
  }
  mainWindow.setMinimumSize(480, 630)
  mainWindow.setSize(480, 630)
  mainWindow.setResizable(false)
})
ipcMain.on('share', () => {
  if (shareWindow === null) {
    createShare()
  }
})
ipcMain.on('stop-share', () => {
  if (mainWindow.isMinimized()) {
    mainWindow.restore()
  }
  if (shareWindow) {
    shareWindow.close()
    shareWindow = null
  }
})

class AppWindow extends BrowserWindow {
  constructor(config) {
    const basicConfig = {
      width: 480,
      height: 630,
      useContentSize: true,
      frame: false,
      show: false,
      resizable: false,
      webPreferences: {
        nodeIntegration: true,
        webSecurity: false,
        contextIsolation: false,
        enableRemoteModule: true
      }
    }
    const finalConfig = { ...basicConfig, ...config }
    super(finalConfig)
  }
}

function createWindow () {
  // Create the browser window.
  mainWindow = new AppWindow()
  if (process.env.WEBPACK_DEV_SERVER_URL) {
    // Load the url of the dev server if in development mode
    mainWindow.loadURL(process.env.WEBPACK_DEV_SERVER_URL)
    // if (!process.env.IS_TEST) mainWindow.webContents.openDevTools()
  } else {
    createProtocol('app')
    // Load the index.html when not in development
    mainWindow.loadURL('app://./index.html')
  }

  mainWindow.on('ready-to-show', () => {
    mainWindow.show()
  })
  mainWindow.on('minimize', () => {
    mainWindow.webContents.send('isMinimize', true)
  })
  mainWindow.on('restore', () => {
    mainWindow.webContents.send('isMinimize', false)
  })
  mainWindow.on('maximize', () => {
    mainWindow.webContents.send('isMinimize', false)
  })
  mainWindow.on('close', (e) => { 
    const obj = {
      bEnd: false
    }
    zoomVideoSdk.leaveSession(obj)
  })
  mainWindow.on('closed', () => {
    mainWindow = null
    if (shareWindow) {
      shareWindow.close()
      shareWindow = null
    }
  })
}

function createShare () {
  shareWindow = new AppWindow({
    width: 262,
    height: 44,
    x: screenSize.width - 350,
    y: 50,
    transparent: true,
    alwaysOnTop: true
  })
  if (process.env.WEBPACK_DEV_SERVER_URL) {
    // Load the url of the dev server if in development mode
    shareWindow.loadURL(`${process.env.WEBPACK_DEV_SERVER_URL}#/share`)
  } else {
    createProtocol('app')
    // Load the index.html when not in development
    shareWindow.loadURL('app://./index.html#/share')
  }

  shareWindow.on('ready-to-show', () => {
    shareWindow.show()
  })
  shareWindow.on('closed', () => {
    shareWindow = null
  })
}

// Quit when all windows are closed.
app.on('will-quit', () => {
  // On macOS it is common for applications and their menu bar
  // to stay active until the user quits explicitly with Cmd + Q
  const cleanup = zoomVideoSdk.cleanup()
  if (cleanup === 0) {
    zoomVideoSdk.destroyZoomVideoSDKObj()
  }
  app.quit()
})

app.on('activate', () => {
  // On macOS it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (mainWindow === null) {
    createWindow()
  }
})

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', async () => {
  screenSize = screen.getPrimaryDisplay().workAreaSize
  if (platform == 'linux') {
    let display = execSync('echo $DISPLAY').toString()
    app.display = display.trim()
    let bounds = screen.getPrimaryDisplay().bounds
    app.screenArea = `(${bounds.x},${bounds.y},${bounds.width},${bounds.height})`
  }
  if (isDevelopment && !process.env.IS_TEST) {
    // Install Vue Devtools
    try {
      // await installVueDevtools()
    } catch (e) {
      console.error('Vue Devtools failed to install:', e.toString())
    }
  }
  createWindow()
})

app.on("web-contents-created", (e, webContents) => {
  remote.enable(webContents);
})

// Exit cleanly on request from parent process in development mode.
if (isDevelopment) {
  if (process.platform === 'win32') {
    process.on('message', data => {
      if (data === 'graceful-exit') {
        app.quit()
      }
    })
  } else {
    process.on('SIGTERM', () => {
      app.quit()
    })
  }
}