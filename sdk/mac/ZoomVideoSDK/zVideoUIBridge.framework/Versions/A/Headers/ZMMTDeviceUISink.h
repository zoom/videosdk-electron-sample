//
//  ZMMTDeviceUISink.h
//  VideoUI
//
//  Created by Francis Zhuo on 8/29/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>

class ZMMTDeviceUISink : public ICmmDeviceUIAPI {
    
public:
    ZMMTDeviceUISink(ZMConfBaseSinkAdapter *adapter);
    virtual ~ZMMTDeviceUISink();
    
    virtual void OnDeviceStatusChanged(DEVICE_CMD cmd, CmmUInt32 ret = 0, CmmUInt32 handle = 0); // Along with a status code for each status
    virtual void ShowMyAudioLevel(CmmUInt32 level, CmmUInt32 handle, CmmBool isMic = CmmTrue);
    virtual void OnVolumeChange(CmmUInt32 vol, CmmBool isMic);
    virtual void OnAudioDeviceSpecialInfoChange(SSB_MC_DEVICE_SPECIAL_INFO special_info, CmmAudioDeviceBriefInfo adbi);

    virtual void OnUltraSoundDetect_PairCode(CmmBool is_timeout, const CAString& pair_code);
    virtual void OnDeviceStatelessButtonDown(const CString& device_id);
    
private:
    ZMConfBaseSinkAdapter *_sinkAdapter;
};
