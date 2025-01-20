const { execSync } = require('child_process')
const { existsSync } = require('fs')
const { platform } = process

if (platform == 'darwin') {
  if (!existsSync('./node_modules/electron/dist/Electron.app/Contents/Frameworks/VideoSDK.dylib')) {
    execSync('chmod 777 ./node_modules/electron/dist/Electron.app/Contents/Frameworks/', {stdio: [0, 1, 2]})
    execSync('cp -Rf ./sdk/mac/ZoomVideoSDK/* ./node_modules/electron/dist/Electron.app/Contents/Frameworks', {stdio: [0, 1, 2]})
  }
}