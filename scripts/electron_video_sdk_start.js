const fs = require('fs')
const { execSync } = require('child_process')

const existsBundled = fs.existsSync('./dist_electron') && fs.existsSync('./dist_electron/bundled')
console.log('bundled js files exist', existsBundled)

const needRebuild = process.argv.includes('rebuild')
console.log('needRebuild', needRebuild)

if (!existsBundled || needRebuild) {
  execSync('node scripts/electron_video_sdk_build.js sourceMap rewritePath', {stdio: [0, 1, 2]})
}
execSync('electron ./dist_electron/bundled', {stdio: [0, 1, 2]})