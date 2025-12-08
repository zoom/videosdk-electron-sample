//
//  ZMAlertInfo.h
//  zChatUI
//
//  Created by fistice on 7/29/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism.h>
#import <Prism/Prism-Swift.h>
#ifdef __cplusplus
#include <zPTApp/SaasBeePTAppInterface.h>
#endif


typedef NS_ENUM(NSUInteger, ZMAlertType) {
    ZMAlertTypeToast,
    ZMAlertTypeBubble,
    ZMAlertTypeDialog,
    ZMAlertTypeBanner,
};
typedef NS_ENUM(NSUInteger, ZMAlertButtonType) {
    ZMAlertButtonTypeNone,
    ZMAlertButtonTypeLink,
    ZMAlertButtonTypeDeepLink,
    ZMAlertButtonTypeOpenAICPanel,
};
typedef NS_ENUM(NSUInteger, ZMAlertButtonPosition) {
    ZMAlertButtonPositionNone,
    ZMAlertButtonPositionPrimary,
    ZMAlertButtonPositionSecondary,
    ZMAlertButtonPositionLeftLink,
    ZMAlertButtonPositionClose,
};
NS_ASSUME_NONNULL_BEGIN
@interface ZMAlertButtonInfo : NSObject
@property (nonatomic,copy) NSString *title;
@property (nonatomic,assign) ZMAlertButtonType type;
@property (nonatomic,copy) NSString *content;
@property (nonatomic,assign) ZMAlertButtonPosition position;

@end

@interface ZMAlertInfo : NSObject

#ifdef __cplusplus
/*
"type": "toast/coachmark",
"businessType":"pt/in-meeting",

 */
- (instancetype)initWithZPNSToastInfo:(const CmmZpnsToast&)obj;
- (instancetype)initWithZPNSBubbleInfo:(const CmmZpnsCoachmark&)obj;
#endif

@property (nonatomic,copy) NSString *identifier;
@property (nonatomic,copy) NSString *title;
@property (nonatomic,copy) NSString *information;
@property (nonatomic,strong) ZMAlertButtonInfo *primaryBtn;
@property (nonatomic,strong) ZMAlertButtonInfo *secondaryBtn;
@property (nonatomic,strong) ZMAlertButtonInfo *leftLinkBtn;

@property (nonatomic,assign) BOOL isCoachmark;
@property (nonatomic,copy) NSString *coachmarkID;
@property (nonatomic,assign) NSUInteger coachmarkPriority;
@property (nonatomic,copy) NSString *entry;
@property (nonatomic,copy) NSString *group;

@property (nonatomic,assign) BOOL isShowClose;
@property (nonatomic,assign) ZMToastType iconType;
@property (nonatomic,copy) NSString *iconTitle;
@property (nonatomic,assign) ZMAlertType displayType;

@property (nonatomic,assign) BOOL needRequestShownCount;
@property (nonatomic,copy) NSString *displayEventType;
@property (nonatomic,copy) NSString *dismissEventType;

@property (nonatomic,assign) BOOL needAppendMtUUIdInURL;
@end


NS_ASSUME_NONNULL_END
