//
//  Copyright (c) 2014 Sam Leitch. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//

// modified by Matthias Behrens (github.com/soliton4) for Broadway.js


/**
 * This class can be used to render output pictures from an H264bsdDecoder to a canvas element.
 * If available the content is rendered using WebGL.
 */
function CanvasRender(canvas, index, forceNoGL, contextOptions) {
  this.canvasElement = canvas;
  this.contextOptions = contextOptions;
  this.glInitSucceed = 0;
  this.textureindex = index ? index : 0;
  this.texturestride = 3;
  CanvasRender.prototype.ROTATION_CLOCK0 = 0;
  CanvasRender.prototype.ROTATION_CLOCK90 = 1;
  CanvasRender.prototype.ROTATION_CLOCK180 = 2;
  CanvasRender.prototype.ROTATION_CLOCK270 = 3;

  if (!forceNoGL) this.initContextGL();

  if (this.contextGL) {
      this.initProgram();
      this.initBuffers();
      this.initTextures(index);

      var a = new ArrayBuffer(4);
      this.dummpyCursor = new Uint8Array(a);
      this.dummpyWaterMark = new Uint8Array(a);
      this.glInitSucceed = this.contextGL.getError() ? 0 : 1;
      this.cursorWidth = 0;
      this.cursorHeight = 0;
      this.hasCursor = 0;
      this.hasWaterMark = 0;
      this.hasWholeFrame = 0;
      this.croppingParams = {};
      this.croppingParams.top = 0;
      this.croppingParams.left = 0;
      this.croppingParams.width = 0;
      this.croppingParams.height = 0;
      this.textureWidth = 0;
      this.textureHeight = 0;
      this.canvasWidth = 0;
      this.canvasHeight = 0;
      this.picRotation = -1;
      this.bgColor = [0, 0, 0];
      this.cx = 0;
      this.cy = 0;
      this.cw = 0;
      this.ch = 0;
      this.colorRange = -1; // 0: limited , 1 full
  }
};

/**
* Create the GL context from the canvas element
*/
CanvasRender.prototype.initContextGL = function () {
  var canvas = this.canvasElement;
  var gl = null;

  var validContextNames = ["webgl", "experimental-webgl", "moz-webgl", "webkit-3d"];
  var nameIndex = 0;

  while (!gl && nameIndex < validContextNames.length) {
      var contextName = validContextNames[nameIndex];

      try {
          if (this.contextOptions) {
              gl = canvas.getContext(contextName, this.contextOptions);
          } else {
              gl = canvas.getContext(contextName);
          }
          ;
      } catch (e) {
          gl = null;
      }

      if (!gl || typeof gl.getParameter !== "function") {
          gl = null;
      }

      ++nameIndex;
  }

  this.contextGL = gl;
};

/**
* Initialize GL shader program
*/
CanvasRender.prototype.initProgram = function () {
  var gl = this.contextGL;

  var vertexShaderScript = [
      'attribute vec4 vertexPos;',
      'attribute vec4 texturePos;',
      "uniform mat4 rotate;" +
      'varying vec2 textureCoord;',

      'void main()',
      '{',
      'gl_Position = rotate * vertexPos;',
      'textureCoord = texturePos.xy;',
      '}'
  ].join('\n');

  var fragmentShaderScript = [
      'precision highp float;',
      'varying highp vec2 textureCoord;',
      'uniform sampler2D ySampler;',
      'uniform sampler2D uSampler;',
      'uniform sampler2D vSampler;',
      'uniform int onlyRGBA;',
      'uniform int colorRange;',
      'const mat4 YUV2RGB_L = mat4',
      '(',
      '1.1643828125, 0, 1.59602734375, -.87078515625,',
      '1.1643828125, -.39176171875, -.81296875, .52959375,',
      '1.1643828125, 2.017234375, 0, -1.081390625,',
      '0, 0, 0, 1',
      ');',
      'const mat4 YUV2RGB_F = mat4',
      '(',
      '1.0, 0, 1.402, -.701,',
      '1.0, -.34413, -.71414, .529135,',
      '1.0, 1.772, 0, -.886,',
      '0, 0, 0, 1',
      ');',

      'void main(void) {',
      'vec4 c;',
      'if(onlyRGBA==0){',
      'highp float y = texture2D(ySampler,  textureCoord).r;',
      'highp float u = texture2D(uSampler,  textureCoord).r;',
      'highp float v = texture2D(vSampler,  textureCoord).r;',

      'if (colorRange == 0)',
      '{',
      '  c = vec4(y, u, v, 1) * YUV2RGB_L;',
      '} else {',
      '  c = vec4(y, u, v, 1) * YUV2RGB_F;',
      '}',
      '}',
      'else{',
      ' c = texture2D(ySampler, textureCoord);',
      '}',
      'c.a = 1.0;',
      'gl_FragColor = c;',

      '}'
  ].join('\n');

  var vertexShader = gl.createShader(gl.VERTEX_SHADER);
  gl.shaderSource(vertexShader, vertexShaderScript);
  gl.compileShader(vertexShader);
  if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
      console.log('Vertex shader failed to compile: ' + gl.getShaderInfoLog(vertexShader));
  }

  var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
  gl.shaderSource(fragmentShader, fragmentShaderScript);
  gl.compileShader(fragmentShader);
  if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
      console.log('Fragment shader failed to compile: ' + gl.getShaderInfoLog(fragmentShader));
  }

  var program = gl.createProgram();
  gl.attachShader(program, vertexShader);
  gl.attachShader(program, fragmentShader);
  gl.linkProgram(program);
  if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
      console.log('Program failed to compile: ' + gl.getProgramInfoLog(program));
  }

  gl.useProgram(program);

  this.shaderProgram = program;
};

/**
* Initialize vertex buffers and attach to shader program
*/
CanvasRender.prototype.initBuffers = function () {
  var gl = this.contextGL;
  var program = this.shaderProgram;

  var vertexPosBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, vertexPosBuffer);
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([1, 1, -1, 1, 1, -1, -1, -1]), gl.STATIC_DRAW);

  var vertexPosRef = gl.getAttribLocation(program, 'vertexPos');
  gl.enableVertexAttribArray(vertexPosRef);
  gl.vertexAttribPointer(vertexPosRef, 2, gl.FLOAT, false, 0, 0);

  this.vertexPosBuffer = vertexPosBuffer;

  var texturePosBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, texturePosBuffer);
  gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([1, 0, 0, 0, 1, 1, 0, 1]), gl.STATIC_DRAW);

  var texturePosRef = gl.getAttribLocation(program, 'texturePos');
  gl.enableVertexAttribArray(texturePosRef);
  gl.vertexAttribPointer(texturePosRef, 2, gl.FLOAT, false, 0, 0);

  this.texturePosBuffer = texturePosBuffer;
};

/**
* Initialize GL textures and attach to shader program
*/
CanvasRender.prototype.initTextures = function () {
  var gl = this.contextGL;
  var program = this.shaderProgram;
  gl.pixelStorei(gl.UNPACK_ALIGNMENT, 1);

  var yTextureRef = this.initTexture();
  var ySamplerRef = gl.getUniformLocation(program, 'ySampler');
  gl.uniform1i(ySamplerRef, this.textureindex * this.texturestride + 0);
  this.yTextureRef = yTextureRef;
  var uTextureRef = this.initTexture();
  var uSamplerRef = gl.getUniformLocation(program, 'uSampler');
  gl.uniform1i(uSamplerRef, this.textureindex * this.texturestride + 1);
  this.uTextureRef = uTextureRef;
  var vTextureRef = this.initTexture();
  var vSamplerRef = gl.getUniformLocation(program, 'vSampler');
  gl.uniform1i(vSamplerRef, this.textureindex * this.texturestride + 2);
  this.vTextureRef = vTextureRef;
  var colorRangeRef = gl.getUniformLocation(program, 'colorRange');
  this.colorRangeRef = colorRangeRef;
  var onlyRGBARef = gl.getUniformLocation(program, 'onlyRGBA');
  this.onlyRGBARef = onlyRGBARef;
};

/**
* Create and configure a single texture
*/
CanvasRender.prototype.initTexture = function () {
  var gl = this.contextGL;

  var textureRef = gl.createTexture();
  gl.bindTexture(gl.TEXTURE_2D, textureRef);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
  gl.bindTexture(gl.TEXTURE_2D, null);

  return textureRef;
};

CanvasRender.prototype.UpdateVideoTextures = function (width, height, croppingParams, data, rotation, limitedColorRange = true) {
  var gl = this.contextGL;
  if (!gl || !this.glInitSucceed) {
      return;
  }

  gl.useProgram(this.shaderProgram);
  var yTextureRef = this.yTextureRef;
  var uTextureRef = this.uTextureRef;
  var vTextureRef = this.vTextureRef;

  gl.enable(gl.BLEND);
  gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);

  if ((width <= 0 || height <= 0) ||
      !data || !data.length ||
      data.length != width * height * 3 / 2 ||
      (croppingParams && (croppingParams.top < 0 || croppingParams.left < 0 || croppingParams.left + croppingParams.width > width || croppingParams.top + croppingParams.height > height))
  ) {
      return;
  }

  rotation = rotation ? rotation : this.ROTATION_CLOCK0;
  croppingParams = croppingParams ? croppingParams : {"top": 0, "left": 0, "width": width, "height": height};

  var picSizeChange = (croppingParams.width != this.croppingParams.width || croppingParams.height != this.croppingParams.height);
  var picPosChange = (croppingParams.top != this.croppingParams.top || croppingParams.left != this.croppingParams.left);
  var texSizeChange = (width != this.textureWidth || height != this.textureHeight);
  var rotationChange = (rotation != this.picRotation);

  if (picSizeChange || picPosChange || texSizeChange || rotationChange) {
    var radian = Math.PI * rotation / 180.0;
    if (rotation == 90 || rotation == 270) {
      radian = Math.PI * (rotation - 180) / 180.0;
    }
    var cosB = Math.cos(radian);
    var sinB = Math.sin(radian);
    var xformMatrix = new Float32Array([
      cosB,  sinB, 0.0, 0.0,
      -sinB, cosB, 0.0, 0.0,
      0.0,    0.0, 1.0, 0.0,
      0.0,    0.0, 0.0, 1.0
    ]);
    var rotate = gl.getUniformLocation(this.shaderProgram, "rotate");
    gl.uniformMatrix4fv(rotate, false, xformMatrix);
  }

  let colorRange = limitedColorRange ? 0 : 1;
  if (colorRange != this.colorRange) {
      gl.uniform1i(this.colorRangeRef, colorRange);
      this.colorRange = colorRange;
  }

  this.croppingParams = croppingParams;
  this.textureWidth = width;
  this.textureHeight = height;
  this.picRotation = rotation;
  this.canvasWidth = gl.canvas.width;
  this.canvasHeight = gl.canvas.height;


  var i420Data = data;

  var yDataLength = width * height;
  var yData = i420Data.subarray(0, yDataLength);
  gl.activeTexture(gl.TEXTURE0 + this.textureindex * this.texturestride);
  gl.bindTexture(gl.TEXTURE_2D, yTextureRef);
  gl.texImage2D(gl.TEXTURE_2D, 0, gl.LUMINANCE, width, height, 0, gl.LUMINANCE, gl.UNSIGNED_BYTE, yData);

  var cbDataLength = width / 2 * height / 2;
  var cbData = i420Data.subarray(yDataLength, yDataLength + cbDataLength);
  gl.activeTexture(gl.TEXTURE1 + this.textureindex * this.texturestride);
  gl.bindTexture(gl.TEXTURE_2D, uTextureRef);
  gl.texImage2D(gl.TEXTURE_2D, 0, gl.LUMINANCE, width / 2, height / 2, 0, gl.LUMINANCE, gl.UNSIGNED_BYTE, cbData);

  var crDataLength = cbDataLength;
  var crData = i420Data.subarray(yDataLength + cbDataLength, yDataLength + cbDataLength + crDataLength);
  gl.activeTexture(gl.TEXTURE2 + this.textureindex * this.texturestride);
  gl.bindTexture(gl.TEXTURE_2D, vTextureRef);
  gl.texImage2D(gl.TEXTURE_2D, 0, gl.LUMINANCE, width / 2, height / 2, 0, gl.LUMINANCE, gl.UNSIGNED_BYTE, crData);
};


CanvasRender.prototype.DrawVideo = function (viewPortParams) {
  var gl = this.contextGL;
  if (!gl || !this.glInitSucceed) {
      return;
  }

  gl.useProgram(this.shaderProgram);
  gl.uniform1i(this.onlyRGBARef, 0);
  gl.viewport(viewPortParams.x, viewPortParams.y, viewPortParams.width, viewPortParams.height);
  gl.enable(gl.BLEND);
  gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
  gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
};

CanvasRender.prototype.clearVideoTextures = function (width, height, data) {
  var gl = this.contextGL;
  if (gl && this.glInitSucceed) {
      if ((width <= 0 || height <= 0) ||
          !data ||
          data.length % 4 != 0) {
          return;
      }
      gl.activeTexture(gl.TEXTURE0 + this.textureindex * this.texturestride);
      gl.bindTexture(gl.TEXTURE_2D, this.yTextureRef);
      gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, data);
  }
}

export default CanvasRender;

