const fs = require('fs')
const { platform, arch } = process
const { execSync } = require('child_process')

const sdkPathMap = {
  'darwin:x64': './sdk/mac',
  'darwin:arm64': './sdk/mac',
  'win32:ia32': './sdk/win32',
  'win32:x64': './sdk/win64',
  'linux:x64': './sdk/linux'
}
const sdkNodePath = sdkPathMap[`${platform}:${arch}`]
const existsNodeFiles = fs.existsSync(`${sdkNodePath}/zoomvideosdk.node`) && fs.existsSync(`${sdkNodePath}/zoomvideosdk_libuv.node`) && fs.existsSync(`${sdkNodePath}/zoomvideosdk_napi_util.node`)
console.log('node files exist', existsNodeFiles)
if (!existsNodeFiles) {
  console.log('rebuilding .node files...')
  execSync('node scripts/electron_video_sdk_buildNode.js', {stdio: [0, 1, 2]})
}