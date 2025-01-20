# Zoom Video SDK -- Electron Sample App

## Documentation

## Install & Run the Sample App

In the light of the rapid version iteration of the Electron framework, the requirements for building and running an Electron application keep changing, as a result, manual installation of the dependencies based on the Electron version is required to build and to run the sample app. The following instruction will show you the basic steps to do so:

**Note**:
* If you have already installed the required environment and dependencies, you may skip the steps in **Install dependencies**.
* **Please note that, for demo purposes, when the node uses the `libuv` library to pass the raw data to Electron to render the video, the raw data is not encrypted nor have additional protection. If you would like to refer to the implementation in this demo, please add protection to your raw data transmission and handling.**

### Windows

#### Prerequisites
* A device with Windows OS
* Protobuf 22.3

#### Install dependencies
1. Install **node.js 20.17.0**. You may find the installation packages at https://nodejs.org/en/
2. Install **Electron 33.0.0**. You may use the command line to install Electron:
    * `npm i electron@33.0.0'
3. Install build environment. You may install the **Windows build tools**, OR install **Visual Studio 2019 or above**.
    * Option 1: Installing **Windows build tools**:
       * You may use the command line to install windows build tools:
         * `npm install --global --production windows-build-tools`
       * Or download the installer from the Microsoft website:
          * `https://www.microsoft.com/en-us/download/details.aspx?id=48159`
    * Option 2: Installing Visual Studio:
        * You may find the Visual Studio from the Microsoft website:
          * `https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16`
4. Install **Python**. Based on the Electron version that you are using, you might install a different python version.  Python 2.7 works with Electron 2 to Electron 9, and Python 3 works with Electron 4 and upper versions.
    * Download the installation packages from `https://www.python.org/downloads/`, suggest using Python version below 3.12 or older, otherwise you may see build .node files error due to a missing 'distutils' module
    * Once you have installed Python, please make sure python is added to the system PATH

#### Build & Run
After successfully installed the above dependencies, here are the steps to build and run the sample app:

1. 1. Follow the steps below to install protobuf 22.3
    * Download the protobuf 22.3 source file from https://github.com/protocolbuffers/protobuf/releases/tag/v22.3
    * Rename the src folder to protobuf_src
    * Download abseil-cpp 20230802.1 from https://github.com/abseil/abseil-cpp/tree/20230802.1
    * Extract the archive and copy the absl folder to protobuf_src
    * Copy the protobuf_src folder into the lib/node_add_on
2. Configure the domain
    * Configure the web domain locates in `config.js`, by default it should be `zoom.us`
3. Run the command `npm run electron:serve`
    * This command will run the file `scripts/electron_sdk_install.js`, configures the project based on `package.json` and install the required dependencies (including Electron). Once finished, the sample app will be launched.
     * If you would like to install other versions of the Electron framework, you may edit the corresponding version number in `package.json`. Please note that the sample app currently does not support Electron 10 or above.

### macOS

#### Prerequisites
* A device with mac OS
* Protobuf 22.3

#### Install dependencies
1. Install **node.js 20.17.0**.
    * You may find the installation packages at https://nodejs.org/en/
    * Or use the following command lines:
        * `ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)`
        * `sudo brew install node`
2. Install **Electron 33.0.0**. You may use the command line to install Electron:
    * `npm i electron@33.0.0`
3. Install Xcode 14 or above
    * You may install from App Store
    * Or download from `https://developer.apple.com/download/more/`
4. Install **Python**. Based on the Electron version that you are using, you might install a different python version.  Python 2.7 works with Electron 2 to Electron 9, and Python 3 works with Electron 4 and upper versions.
    * Download the installation packages from `https://www.python.org/downloads/`, suggest using Python version below 3.12 or older, otherwise you may see build .node files error due to a missing 'distutils' module
    * Once you have installed Python, please make sure python is added to the system PATH

#### Build & Run

After successfully installed the above dependencies, here are the steps to build and run the sample app:

1. Follow the steps below to install protobuf 22.3
    * Download the protobuf 22.3 source file from https://github.com/protocolbuffers/protobuf/releases/tag/v22.3
    * Rename the src folder to protobuf_src
    * Download abseil-cpp 20230802.1 from https://github.com/abseil/abseil-cpp/tree/20230802.1
    * Extract the archive and copy the absl folder to protobuf_src
    * Copy the protobuf_src folder into the lib/node_add_on
2. Configure the domain
    * Configure the web domain locates in `config.json`, by default it should be `zoom.us`
3. Run the command `npm run electron:serve`
 * This command will run the file `scripts/electron_sdk_install.js`, configures the project based on `package.json` and install the required dependencies (including Electron). Once finished, the sample app will be launched.
  * If you would like to install other versions of the Electron framework, you may edit the corresponding version number in `package.json`. Please note that the sample app currently does not support Electron 10 or above.

### Linux

#### Prerequisites
* A device with linux OS
* Protobuf 22.3

#### Install dependencies
1. Install **node.js 20.17.0**.
    * You may find the installation packages at https://nodejs.org/en/
    * Or use the following command lines on ubuntu:
        * `sudo apt update`
        * `sudo apt install nodejs npm`
        * `node -v`
2. Install **Electron 33.0.0**. You may use the command line to install Electron:
    * `npm i electron@33.0.0`

#### Build & Run

After successfully installed the above dependencies, here are the steps to build and run the sample app:

1. Follow the steps below to install protobuf 22.3
    * Download the protobuf 22.3 source file from https://github.com/protocolbuffers/protobuf/releases/tag/v22.3
    * Rename the src folder to protobuf_src
    * Download abseil-cpp 20230802.1 from https://github.com/abseil/abseil-cpp/tree/20230802.1
    * Extract the archive and copy the absl folder to protobuf_src
    * Copy the protobuf_src folder into the lib/node_add_on
2. Configure the domain
    * Configure the web domain locates in `config.json`, by default it should be `zoom.us`
3. Run the command `npm run electron:serve`
 * This command will run the file `scripts/electron_sdk_install.js`, configures the project based on `package.json` and install the required dependencies (including Electron). Once finished, the sample app will be launched.
  * If you would like to install other versions of the Electron framework, you may edit the corresponding version number in `package.json`. Please note that the sample app currently does not support Electron 10 or above.

## Changelog

For the changelog, see [Video SDK - Electron](https://devsupport.zoom.us/hc/en-us/sections/11766697610765-Electron-demo).

## Support

For any issues regarding our SDK, please visit our Developer Support Forum at https://devforum.zoom.us/.

## License

Use of this SDK is subject to our [License and Terms of Use](https://explore.zoom.us/docs/en-us/video-sdk-terms.html);

---
Copyright ©2012-2025 Zoom Communications, Inc. All rights reserved.
