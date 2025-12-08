//
//  ZMMTReactionHelper.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2023/8/14.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#ifdef __cplusplus
#import <zm_conf_universal_ui/zm_conf_universal_ui_api.h>
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMSessionOptions){
    ZMAVStatusNone = 0,
    ZMAVStatusAudioOn = 1 << 0,
    ZMAVStatusVideoOn = 1 << 1,
};

@interface ZMMTReactionHelper : ZMBaseHelper

- (BOOL)isUseAllEmojis;

- (BOOL)isFeedbackEnabled;

- (BOOL)isEmojiReactionEnabled;

- (BOOL)canSendDynamicEmojis;

- (BOOL)isDynamicEmojiEnabled;

- (BOOL)isEmojiAudibleReactionEnabled;

- (BOOL)isSupportSkinTone;

// type: CMM_NONVERBAL_FEEDBACK
- (NSUInteger)feedbackCountWithType:(int)type;

- (NSUInteger)raiseHandCount;

- (NSUInteger)brbCount;

- (BOOL)canClearAllFeedback;

- (BOOL)isWebinarEmojiReactionEnabled;

- (void)SetAllowWebinarEmojiReaction:(BOOL)allow;

- (BOOL)isAllowWebinarEmojiReactionEnabled;

- (BOOL)isShowMyReactionOnToolbarEnabled;

- (BOOL)isHandGestureCaptureEnabledOfLocalSetting;

- (BOOL)isHandGestureCaptureEnableOfWebSettingAndLocalSupport;

- (BOOL)isMeetingAnimatedReactionsEnable;

- (BOOL)isLottieEnable;

// [ZOOM-426408] Raise Hand Improvements
- (BOOL)isRaiseHandImprovementsAvaiable;

- (BOOL)isRaiseHandButtonSeparatedFromReactions;

- (BOOL)isBeRightBackFeatureEnabled;

- (BOOL)isPlayChimeWhenRaiseHand;

- (void)setIsPlayChimeWhenRaiseHand:(BOOL)isPlayChime;

- (BOOL)isSupportRaiseHandQueue;

- (BOOL)isMeetingFloatingEmojiEnabled;

#ifdef __cplusplus
- (nullable NS_ZM_CONF_UNIVERSAL_UI::IRaiseHandIndexArray *)getRaiseHandIndexArray;
#endif

@end

NS_ASSUME_NONNULL_END
