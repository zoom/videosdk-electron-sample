const { arch } = process
const fs = require('fs')
const pkgPath = './package.json'
const pkg = fs.readFileSync(pkgPath)
let pkgObject = JSON.parse(pkg)

pkgObject.config = {arch: `${arch}`}
fs.writeFileSync(pkgPath, JSON.stringify(pkgObject, null, 2))

fs.writeFile('.npmrc',`arch=${arch}`,'utf8',function (error) {
  if (error) {
    console.log(error)
    return false
  }
  fs.close(0, function() {
    console.log('write .npmrc file success')
  })
})