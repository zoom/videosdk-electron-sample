//
//  ZMGiftPanel.h
//  ZCommonUI
//
//  Created by lin on 13/07/2018.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger,ZMGiftType){
    ZMGiftType_First_30Min,
    ZMGiftType_First_end,
    ZMGiftType_Second_end,
    ZMGiftType_Third_30Min,
    ZMGiftType_Third_Timeout,
    ZMGiftType_For_Enterprise,
    ZMGiftType_Thank_Choosing,
    ZMGiftType_Webinar_Thank_Choosing,
    
    ZMGiftType_Sip_First_30Min,
    ZMGiftType_Sip_First_End,
    ZMGiftType_Sip_Second_End,
    ZMGiftType_Sip_Third_30Min,
    ZMGiftType_Sip_Third_Timeout,
    
    ZMGiftType_Webinar_Third_30Min,
    ZMGiftType_Webinar_Third_30Min_Attendee,
    ZMGiftType_Webinar_Third_Timeout,
    
};

@interface ZMGiftPanel : ZMPlainPanel
@property(assign) NSUInteger elapsedTime;
@property(nullable, copy) NSString* upgradeUrl;
@property(nullable, copy) void (^giftActionBlock)(ZMGiftType type);
@property(nullable, copy) NSString* (^getMeetingDurationLimitBlock)(void);
@property(nullable, copy) void (^cancelActionBlock)(ZMGiftType type);
@property(nullable, copy) NSString* titleText;
@property(nullable, copy) NSString* descriptionText;
@property(nullable, copy) NSString* buttonText;
@property(nullable, retain) NSImage *giftImage;
- (nullable NSString *)displayedTitleText;
- (void)cleanUp;
- (void)invisibleInSharing;
- (void)showWindowWithType:(ZMGiftType)type;
@end

NS_ASSUME_NONNULL_END
