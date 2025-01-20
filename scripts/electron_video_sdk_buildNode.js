const fs = require('fs')
const { execSync } = require('child_process')
const { platform, arch } = process
const pkgPath = './package.json'
const pkg = fs.readFileSync(pkgPath)
let pkgObject = JSON.parse(pkg)
let electronPackage
let electronVersion

execSync('node scripts/utils/check_node_modules_installed.js', {stdio: [0, 1, 2]})

try {
  execSync(`${platform == 'win32' ? 'python' : 'python3'} --version`, {stdio: [0, 1, 2]})
} catch (error) {
  console.log('you have not installed python')
}

try {
  console.log('checking electron version...')
  electronPackage = execSync('npm ls electron').toString()
} catch (error) {
  console.log('you have not installed electron')
}

if (electronPackage) {
  var packageList = electronPackage.split('@')
  electronVersion = packageList[packageList.length - 1].trim()
  console.log('electron version is', electronVersion)
  try {
    if (platform == 'darwin') {
      execSync(`node-gyp rebuild --target=${electronVersion} --arch=${arch} --dist-url=https://electronjs.org/headers`, {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk.node ./sdk/mac', {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk_libuv.node ./sdk/mac', {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk_napi_util.node ./sdk/mac', {stdio: [0, 1, 2]})
    } else if (platform == 'linux') {
      execSync(`node-gyp rebuild --target=${electronVersion} --arch=${arch} --dist-url=https://electronjs.org/headers`, {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk.node ./sdk/linux', {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk_libuv.node ./sdk/linux', {stdio: [0, 1, 2]})
      execSync('cp -Rf ./build/Release/zoomvideosdk_napi_util.node ./sdk/linux', {stdio: [0, 1, 2]})
    } else if (platform == 'win32') {
      execSync(`node-gyp rebuild --target=${electronVersion} --arch=${arch} --dist-url=https://electronjs.org/headers --release --msvs_version=2019`, {stdio: [0, 1, 2]})
    }
  } catch (error) {
    console.log('rebuild .node files failed, please refer to README.md')
  }
}

pkgObject.config = {}
fs.writeFileSync(pkgPath, JSON.stringify(pkgObject, null, 2))