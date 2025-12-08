//
//  ZMMTOnlineBusinessHelper.h
//  VideoUIBridge
//
//  Created by Devl on 3/24/25.
//

#import <zVideoUIBridge/zVideoUIBridge.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTUpgradeBasicInfo : NSObject

@property (nonatomic, assign) BOOL withAiCompanion;
@property (nonatomic, assign) ZMMTUpgradeEntrance entrance;

@property (nonatomic, copy) NSString *desContent;
@property (nonatomic, copy) NSString *linkText;
@property (nonatomic, copy) NSString *linkURL;
@end

@interface ZMMTUpgradeToastItem : NSObject

@property (nonatomic, copy) NSString *prefixIcon;
@property (nonatomic, copy) NSString *suffixIcon;
@property (nonatomic, copy) NSString *content;
@end

@interface ZMMTUpgradeToastInfo : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) ZMMTUpgradeBasicInfo *basicInfo;
@property (nonatomic, strong) NSArray<ZMMTUpgradeToastItem*> *items;
@end

@interface ZMMTOnlineBusinessHelper : ZMBaseHelper

//MARK: - Upgrade
- (nullable ZMMTUpgradeToastInfo *)getUpgradeToastInfo;
- (nullable ZMMTUpgradeBasicInfo *)getUpgradePlistInfo;
- (nullable ZMMTUpgradeBasicInfo *)getUpgradeChatInfo;
- (nullable NSString *)getUpgradeSidePanelInfo;

- (BOOL)isNeedShowUpgradeEntrance:(ZMMTUpgradeEntrance)entrance;
- (BOOL)canShowRemainTimeLabel;
- (BOOL)canShowUpgradeBtnContainUrl;

- (void)onUpgradeEntranceShowed:(ZMMTUpgradeEntrance)entrance;
- (void)onUpgradeEntranceClosed:(ZMMTUpgradeEntrance)entrance;
- (void)onUpgradeNowClicked:(ZMMTUpgradeEntrance)entrance;

//MARK: - Upsell
- (BOOL)isUpsellEligible;
#ifdef __cplusplus
- (ZUUI::LargeMeetingUpsellPrompt)getUpSellType;
- (void)onLargeMeetingUpsellContentShow:(ZUUI::kLargeMeetingUpsellEventTrackSource)source;
- (void)onLargeMeetingUpsellContentClosed:(ZUUI::kLargeMeetingUpsellEventTrackSource)source;
- (void)onByNowLinkUrlClicked:(ZUUI::kLargeMeetingUpsellEventTrackSource)source;
- (ZUUI::OnlineBusinessBannerType)getOnlineBusinessNeedShowBannerType;
#endif
- (nullable NSString *)getUpSellSuccessToast;

//MARK: - Webinar free trial
- (void)onWebinarFreetrialPlistBannershown;

@end

NS_ASSUME_NONNULL_END
