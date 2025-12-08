//
//  ZMConfHelper.h
//  SaasBeeConfUIModule
//
//  Created by John on 15/2/14.
//  Copyright (c) 2015 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUIConstants.h>
#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#import <zm_conf_universal_ui/zm_conf_universal_ui_online_business_interface.h>
#import <zm_conf_universal_ui/zm_conf_uui_ui_collection_interface.h>
#import <zm_conf_universal_ui/zm_conf_uui_psl_interface.h>
#define ZUUI NS_ZM_CONF_UNIVERSAL_UI
#define PLIST ns_uui_participant_list
@interface ZMConfHelper : ZMBaseHelper

+ (ICmmConfMgrAPI*)getConfApi;
+ (ICmmConfContext*)getConfContext;
+ (ICmmConfStatus*)getConfStatusObject;
+ (ICmmVideoAPI*)getVideoApi;
+ (ICmmVideoBkgndImageMgr*)getVBApi;
+ (ICmmAudioAPI*)getAudioApi;
+ (IZoomRaiseHandInWebinar*)getWebinarHandApi;
+ (IZoomQAComponent*)getQAComponent;
+ (ICmmBOMgrAPI*)getBOMgrApi;
+ (IZoomChatInWebinar*)getWebinarChatComponent;
+ (ICmmPollAPI*)getPollApi;
+ (ICmmAttentionTrackMgrAPI*)getAttentionTrackApi;//ZOOM-4026
+ (ICmmFeedbackMgrAPI*)getFeedbackApi;
+ (ISBMeetingItem*)getMeetingItem;
+ (ICmmChatComponent*)getChatAPIObj;//ZOOM-14788
+ (ICmmRecordAPI*)getRecordApi;//[Zoom-16564]
+ (ICmmLocalRecordAPI*)getLocalRecordApi;
//+ (CMM_SHARESTATUS)getShareStatus;//[Zoom-16564]
+ (ICmmInterpretationMgr *)getInterpretationObj;//ZOOM-73504
+ (ICmmSceneBkgndMgr *)getSceneBkgndApi;//ZOOM-261363
#ifdef ENABLE_ZAPP
+ (IZappService*)getZappAPI;
+ (IZappJSRegister *)getZappJsRegisterInterface;
#endif
+ (ICmmConfAppAPI*)getConfAppApi;//ZOOM-266431
+ (ICmmGRMgrAPI *)getGRMgrApi;
+ (zm::multi_conf_ins::IFeature *)getGRFeatureApi;
+ (ICmmConfInst *)getBackstageInst;
+ (ICmmWebAgentAPI*)getWebAgentAPI;
+ (ICmmConfEventTrackingAPI *)getEventTrackingAPI;
+ (ISBPTAppAPI*)getPtAppAPI;//ZOOM-381157
+ (ICmmConfJoiner*)getConfJoinerAPI;
+ (ICmmQAApi*)getQAApi;//jeffery add
#pragma mark - WebinarBO
+ (zm::new_bo::INewBOManager *)getNewBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getNewBOFeatureApi;
+ (zm::new_bo::IBOControl *)getNewBOControlApi;
+ (zm::new_bo::IBOMainConf *)getNewBOMainConfApi;
#pragma mark - PBO
+ (zm::pbo::IPBOManager *)getPBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getPBOFeatureApi;
+ (zm::pbo::IPBOControl *)getPBOControlApi;
+ (zm::pbo::IPBOMainConf *)getPBOMainConfApi;

#pragma mark - Clips
- (ICmmClipsShareApi *)getShareClipsAPI;

- (ICmmConfInst *)getConfInst;
- (ICmmConfContext*)getConfInstContext;
- (ICmmConfStatus*)getConfInstStatusObject;
- (CmmUInt32)getConfInstId;
- (ICmmVideoAPI*)getConfInstVideoApi;
- (ICmmAudioAPI*)getConfInstAudioApi;

- (ICmmShareMgr *)getConfInstShareMgr;
- (ICmmASShareMgr *)getConfInstASShareMgr;
- (ICmmShareConfig *)getConfInstShareConfig;
- (ICmmASSharePortMgr *)getConfInstASSharePortMgr;
- (ICmmASShareSourceMgr *)getConfInstASShareSourceMgr;
- (ICmmASShareRenderMgr *)getConfInstASShareRenderMgr;
- (ICmmASShareRender *)getConfInstASShareRenderByViewHandle:(NSView *)view;
- (ICmmASSharePort *)getConfInstDefaultASSharePort;
- (ICmmAnnotationAPI *)getConfInstAnnotationAPI;

- (IZoomRaiseHandInWebinar*)getConfInstWebinarHandApi;
- (IZoomQAComponent*)getConfInstQAComponent;
- (ICmmQAApi *)getConfInstQAApi;
- (IZoomChatInWebinar*)getConfInstWebinarChatComponent;
- (ICmmPollAPI*)getConfInstPollApi;
- (ICmmAttentionTrackMgrAPI*)getConfInstAttentionTrackApi;
- (ICmmFeedbackMgrAPI*)getConfInstFeedbackApi;
- (ISBMeetingItem*)getConfInstMeetingItem;
- (ICmmChatComponent*)getConfInstChatAPIObj;
- (ICmmRecordAPI*)getConfInstRecordApi;
//- (CMM_SHARESTATUS)getConfInstShareStatus;//[Zoom-16564]
- (ICmmInterpretationMgr *)getConfInstInterpretationObj;//ZOOM-73504
- (ICmmSignInterpretationMgr *)getConfInstSignInterpretationObj;//ZOOM-330475
- (ICmmWhiteboardAPI*)getConfInstWhiteboardApi;
- (ICmmZoomNotesApi*)getConfInstNotesApi;
- (ICmmLTTAPI *)getLTTApi;//ZOOM-283768
- (ICmmStudioAPI *)getStudioApp;
- (IZoomLaunchConfParameter *)getLanuchConfParamenter;
#pragma mark - newBO
- (zm::new_bo::IBOControl *)getNewBOControlApi;
- (std::shared_ptr<zm::new_bo::IBOList>)getNewBOListApi;
- (std::shared_ptr<zm::new_bo::IBORoom>)getNewBORoomApi;
#pragma mark - NextBO
- (std::shared_ptr<zm::new_bo::IPlan>)getNextBOControlApi;
- (std::shared_ptr<zm::new_bo::IBOList>)getNextBOListApi;

- (zm::multi_conf_ins::IFeature *)getPBOFeatureApi;
- (zm::pbo::IPBOControl *)getPBOControlApi;
- (std::shared_ptr<zm::pbo::IPBORoom>)getPBORoomApi;

#pragma mark - SpotsBO
#ifdef ENABLE_ZAPP
- (zm::spots::ISpotsControl *)getSpotsBOControlApi;
+ (zm::spots::ISpotsManager *)getSpotsBOMgrApi;
+ (zm::multi_conf_ins::IFeature *)getSpotsBOFeatureApi;
- (std::shared_ptr<zm::spots::ISpotsData>)getSpotsBOList;
+ (ICmmConfInst *)getSpotsBOMainConfInst;
- (std::shared_ptr<zm::spots::IBubble>)getSpotsBORoomApi;
#endif

#pragma mark - Docs
- (zm::docs::ICmmZoomDocsAPI *)getConfDocsAPI;

#pragma mark - ConfUniversalUI
+ (ZUUI::IZmConfUniversalUi*)getConfUniversalUI;
#pragma mark - Closed Caption
+ (ZUUI::ICCUniversalUi *)getCCUniversalUi;
+ (ZUUI::ILTTUniversalUi *)getLTTUniversalUi;
#pragma mark - Transcript
+ (ZUUI::ITranscriptUniversalUi*)getTranscriptUniversalUI;
#pragma mark - Share
+ (ZUUI::IShareUniversalUi*)getShareUniversalUI;
#pragma mark - RaiseHand
+ (ZUUI::IRaiseHandUniversalUi *)getRaiseHandUniversalUI;
+ (ZUUI::IRaiseHandIndexMgr *)getRaiseHandIndexMgr;
#pragma mark - ProcessEmoji
+ (ZUUI::IProcessEmojiUniversalUi *)getProcessEmojiUniversalUI;
#pragma mark - Archive
+ (ZUUI::IArchiveUniversalUi *)getArchiveUniversalUi;
#pragma mark - IParticipantPanelUI
+ (ZUUI::IParticipantListUniversalUi*)getPlistUUI;
+ (ZUUI::PLIST::IParticipantPanelLogic *)getPlistLogic;
+ (ZUUI::PLIST::IUuiPlistListLogic *)getPlistListLogic;
+ (ZUUI::IUuiPlistCoachMarkLogic *)getPlistCoachMarkLogicWithType:(ZUUI::UuiPlistCoachMarkType)type;
+ (ZUUI::PLIST::IParticipantPanelLogic *)getRemovePlistLogic;
+ (ZUUI::IUuiConfUserActionLogic *)getPlistUserActionLogic;
#pragma mark - OnlineBusiness
+ (ZUUI::IOnlineBusinessUniversalUi *)getOnlineBusinessUniversalUi;
+ (ZUUI::IWebinarFreetrialUniversalUi *)getWebinarFreetrialUniversalUi;
+ (ZUUI::ILargeMeetingUpSellUniversalUi *)getLargeMeetingUpSellUniversalUi;
+ (ZUUI::IZpnsCommonNoticeUniversalUi *)getZpnsCommonNoticeUniversalUi;
#pragma mark - BO
+ (ZUUI::IBOUniversalUi *)getBOUniversalUI;
#pragma mark - Join Session
+ (ZUUI::IJoinSessionUniversalUi*)getJoinSessionUUI;
#pragma mark - Layout
+ (ZUUI::ILayoutUniversalUi *)getLayoutUniversalUI;
#pragma mark - Audio
+ (ZUUI::IAudioUniversalUi *)getAudioUUI;
#pragma mark - UICollection
+ (ZUUI::IUiCollectionUniversalUi *)getUICollectionUUI;
+ (ZUUI::IConfUserActionUniversalUi *)getUserActionUUI;
#pragma mark - Video
+ (ZUUI::IVideoPortUniversalUi *)getVideoPortUUI;
+ (ZUUI::IUuiVideoPortLogic *)getVideoPortLogic;
+ (ZUUI::IUuiConfUserActionLogic *)getVideoUserActionLogic;
#pragma mark - Toolbar
+ (ZUUI::IToolbarUniversalUi *)getToolbarUUI;
+ (ZUUI::IMainToolbarLogic *)getMainToolbarLogic;
#pragma mark - Watermark
+ (ZUUI::IWatermarkUniversalUi *)getWatermarkUUI;
#pragma mark - leaveMeeting
+ (ZUUI::ILeaveSessionUniversalUi *)getLeaveSessionUniversalUi;
@end
