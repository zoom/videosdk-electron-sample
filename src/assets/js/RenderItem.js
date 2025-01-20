import CanvasRender from './CanvasRender.js'

class RenderItem {
  constructor(canvas, index) {
    this.canvas = canvas
    this.croppingParams = {}
    this.viewPortParam = {
      x: 0,
      y: 0,
      width: 0,
      height: 0
    }
    this.dataType = null
    this.resolution = 0
    this.isDrawVideo = false
    this.CanvasRender = new CanvasRender(this.canvas, index)
    this.clearColor = new Uint8Array(4)
  }

  setDataType (dataType) {
    this.dataType = dataType
  }
  
  setResolution (resolution) {
    this.resolution = resolution
  }
  
  setDrawVideoStatus (isDrawVideo) {
    this.isDrawVideo = isDrawVideo
    if (!isDrawVideo) {
      this.clearViewPort()
    }
  }
  
  setViewPort (viewPortParam) {
    if (this.isDrawVideo) {
      this.viewPortParam = viewPortParam
    }
  }
  
  UpdateVideoTextures (croppingParams, data) {
    if (this.isDrawVideo) {
      this.croppingParams = croppingParams
      this.CanvasRender.UpdateVideoTextures(croppingParams.width, croppingParams.height, croppingParams, data, croppingParams.rotation, 1)
    }
  }
  
  DrawVideo () {
    this.CanvasRender.DrawVideo(this.viewPortParam)
  }
  
  clearViewPort () {
    let croppingParams = {
      top: 0,
      left: 0,
      width: 1,
      height: 1
    }
    let RGBA = {
      R: 0,
      G: 0,
      B: 0,
      A: 1
    }
    this.clearColor[0] = RGBA.R * 255;
    this.clearColor[1] = RGBA.G * 255;
    this.clearColor[2] = RGBA.B * 255;
    this.clearColor[3] = RGBA.A * 255;
    this.CanvasRender.clearVideoTextures(croppingParams.width, croppingParams.height, this.clearColor, croppingParams)
    this.viewPortParam.width = 0
    this.viewPortParam.height = 0
    this.DrawVideo()
  }
}

export default RenderItem