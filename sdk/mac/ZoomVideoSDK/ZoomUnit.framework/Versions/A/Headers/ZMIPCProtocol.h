//
//  ZMIPCProtocol.h
//  ZoomUnit
//
//  Created by Francis Zhuo on 5/19/23.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, ZMIPCCustomType){
    ZMIPCCustomType_Default = 0,
    ZMIPCCustomType_MT2PT   = 1,
};

typedef NS_ENUM(NSUInteger, ZMIPCTypeConf2PT) {
    ZMIPCTypeConf2PT_ConfFail = 1,
    ZMIPCTypeConf2PT_OpenSetting,
    ZMIPCTypeConf2PT_ProfileCardRefreshAvatar,
    ZMIPCTypeConf2PT_ProfileCardWillDisappear,
    ZMIPCTypeConf2PT_ProfileCardSelectedChanged,
    ZMIPCTypeConf2PT_ReloadVBUI,
	ZMIPCTypeConf2PT_SpotsMeetingWindowChanged,
	ZMIPCTypeConf2PT_HuddleDownLoadAvatar,
    ZMIPCTypeConf2PT_StartNetworkDiagnosticsHotkey
};
