//
//  ZMMTFeatureMgrSink.h
//  VideoUI
//
//  Created by Francis Zhuo on 10/17/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#import <zm_conf_callback_dispatcher/zm_conf_callback_dispatcher_api.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTFeatureMgrSinkAdapter;
class ZMMTFeatureMgrSink : public zm::multi_conf_ins::IFeatureManagerSink,
public NS_ZM_CONF_CALLBACK_DISPATCHER::IMultiConfContainerApiSink,
public NS_ZM_UNIVERSAL_UI::IZmDllInfoApi

{
public:
    ZMMTFeatureMgrSink(ZMMTFeatureMgrSinkAdapter *adapter);
    virtual ~ZMMTFeatureMgrSink(void);

public:
    virtual void OnPrepareFeatureMaterial(zm::multi_conf_ins::FeatureType nFeature, zm::multi_conf_ins::FeatureMaterial& fm) override;
    virtual void OnFeatureCreated(CmmBool bOk, zm::multi_conf_ins::FeatureType nFeature) override;
    virtual void OnFeatureDestroying(zm::multi_conf_ins::FeatureType nFeature) override;
        
    virtual void OnBeginSwitchFeature(const zm::multi_conf_ins::FeatureDetails& newRoom, const std::vector<zm::multi_conf_ins::FeatureDetails>& oldRoom, const zm::multi_conf_ins::FeatureSwitchDetails& fsd) override;
    virtual void OnSwitchFeature(const zm::multi_conf_ins::FeatureDetails& finalRoom, const zm::multi_conf_ins::FeatureSwitchResult& result) override;
    
    // MARK: UniversalUI
    ZM_OVERRIDE_GET_INTERFACE(zm::multi_conf_ins::IFeatureManagerSink) {return this;};
    ZM_OVERRIDE_GET_INTERFACE(NS_ZM_UNIVERSAL_UI::IZmDllInfoApi) {return this;};
    virtual NS_ZM_UNIVERSAL_UI::AtDll GetAtDll() override { return NS_ZM_UNIVERSAL_UI::AtDll::kAtDllZVideoUi; }

protected:
    ZMMTFeatureMgrSinkAdapter  *_Nullable m_sinkAdapter;
};

@interface ZMMTFeatureMgrSinkAdapter : NSObject
- (void)onPrepareFeatureMaterial:(zm::multi_conf_ins::FeatureType)featureType material:(zm::multi_conf_ins::FeatureMaterial&)material;
- (void)onFeatureCreated:(CmmBool)success forFeature:(zm::multi_conf_ins::FeatureType)featureType;
- (void)onFeatureDestroying:(zm::multi_conf_ins::FeatureType)nFeature;
- (void)onBeginSwitchFeature:(const zm::multi_conf_ins::FeatureDetails&)newRoom oldRooms:(const std::vector<zm::multi_conf_ins::FeatureDetails>&)oldRooms;
- (void)onEndedSwitchFeature:(const zm::multi_conf_ins::FeatureDetails&)finalRoom success:(BOOL)success;
@end

NS_ASSUME_NONNULL_END
