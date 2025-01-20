const path = require('path')
const crypto = require('crypto')
const TerserPlugin = require('terser-webpack-plugin')

const isProduction = process.env.NODE_ENV === 'production'
const enableProductionSourceMap = process.argv.includes('sourceMap')
const needRewritePath = process.argv.includes('rewritePath')

const { platform, arch } = process
const sdkPathMap = {
  'darwin:x64': './sdk/mac',
  'darwin:arm64': './sdk/mac',
  'win32:ia32': './sdk/win32',
  'win32:x64': './sdk/win64',
  'linux:x64': './sdk/linux'
}
const sdkPath = sdkPathMap[`${platform}:${arch}`]

const origCreateHash = crypto.createHash
crypto.createHash = (alg, opts) => {
  return origCreateHash(/^md\d$/.test(alg) ? 'sha256' : alg, opts)
}

function resolve (dir) {
  return path.join(__dirname, dir)
}

const date = new Date()
const month = date.getMonth() < 9 ? '0' + (date.getMonth() + 1) : date.getMonth() + 1
const day = date.getDate() < 10 ? '0' + date.getDate() : date.getDate()

module.exports = {
  lintOnSave: true,
  crossorigin: 'anonymous',
  publicPath: '/',
  outputDir: 'dist',
  productionSourceMap: enableProductionSourceMap,
  parallel: false, // require('os').cpus().length > 1,
  devServer: {
    compress: false,
    host: '0.0.0.0',
    port: 8081,
    open: false, 
    https: false
  },
  pluginOptions: {
    electronBuilder: {
      customFileProtocol: './',
      chainWebpackMainProcess: config => {
        config.module
        .rule('node')
        .test(/\.node$/)
        .use('native-ext-loader')
        .loader('native-ext-loader')
        .tap(options => {
          options = {
            rewritePath: isProduction && !needRewritePath ? null : resolve(sdkPath),
            emit: false
          }
          return options
        })
        .end()
      },
      builderOptions: {
        appId: 'video.sdk.zoom',
        productName: `zoom-video-sdk`,
        compression: 'maximum',
        artifactName: "${productName}_Setup_${version}.${copyright}.${ext}",
        copyright: `${month}${day}`,
        icon: `./src/assets/images/${platform}.ico`,
        asar: false,
        mac: {
          extraResources: [
            {
              from: './sdk/mac/ZoomVideoSDK/',
              to: '../Frameworks/'
            },
            {
              from: './sdk/mac/',
              to: './app/',
              filter: ["*.node"]
            }
          ],
          target: [
            {
              target: 'zip',
              arch: [arch]
            }
          ],
          extendInfo:{
            NSMicrophoneUsageDescription: "Please allow this program to access your microphone",
            NSCameraUsageDescription: "Please allow this program to access your camera"
          }
        },
        win: {
          extraResources: [
            {
              from: sdkPath,
              to: './app/'
            },
            {
              from: './config.json',
              to: '../'
            }
          ],
          target: [
            // configure generate a zip package that requires no installation
            // {
            //   target: 'zip',
            //   arch: ['ia32', 'x64']
            // },
            {
              target: 'nsis',
              arch: [arch]
            }
          ]
        },
        linux: {
          icon: './src/assets/images/linux.png',
          extraResources: [
            {
              from: sdkPath,
              to: './app/'
            },
            {
              from: './config.json',
              to: '../'
            }
          ],
          target: [
            {
              target: 'deb',
              arch: 'x64'
            }
          ]
        },
        nsis: {
          oneClick: false,
          allowElevation: true,
          allowToChangeInstallationDirectory: true,
          installerIcon: `./src/assets/images/${platform}.ico`,
          uninstallerIcon: `./src/assets/images/${platform}.ico`,
          installerHeaderIcon: `./src/assets/images/${platform}.ico`,
          createDesktopShortcut: true,
          createStartMenuShortcut: true,
          deleteAppDataOnUninstall: true,
          include: 'scripts/installer.nsh'
        }
      },
      externals: ['@electron/remote']
    }
  },
  css: {
    extract: isProduction ? {
      ignoreOrder: true,
    } : false,
    sourceMap: true,
    loaderOptions: {
      sass: {
        prependData: `
          @import "@/assets/style/index.scss";
        `
      }
    }
  },
  chainWebpack: config => {
    config.resolve.alias
      .set('@', resolve('src'))
      .set('@scss', resolve('src/assets/style'))
      .set('path', require.resolve('path-browserify'))
    if (isProduction) {
      config.plugins.delete('preload')
      config.plugins.delete('prefetch')
      config.optimization.minimize(true)
      config.optimization.splitChunks({
        chunks: 'all'
      })
    }
  },
  configureWebpack: config => {
    config.devtool = isProduction ? (enableProductionSourceMap ? 'inline-source-map' : undefined) : 'source-map'
    config.module.rules.push({
      test: /\.node$/,
      loader: 'native-ext-loader',
      options: {
        basePath: ['../app/'],
        rewritePath: isProduction && !needRewritePath ? (platform=='win32'?'./':null) : resolve(sdkPath),
        emit: false
      }
    })
    if (isProduction) {
      config.plugins.push(
        new TerserPlugin({
          cache: true,
          parallel: true,
          sourceMap: enableProductionSourceMap,
          terserOptions: {
            compress: {
              drop_console: true,
              drop_debugger: true
            }
          }
        })
      )
    }
  }
}
