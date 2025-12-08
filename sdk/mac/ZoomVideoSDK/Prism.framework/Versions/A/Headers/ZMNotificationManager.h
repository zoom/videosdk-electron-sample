//
//  ZMNotificationManager.h
//  zChatUI
//
//  Created by javenlee on 2019/5/14.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMNotificationProtocol.h>
#import <UserNotifications/UserNotifications.h>

typedef NS_ENUM(NSUInteger, ZMUserNotificationActivationType)
{
    ZMUserNotificationActivationTypeNone,
    ZMUserNotificationActivationTypeDismiss,
    ZMUserNotificationActivationTypeContentsClicked,
    ZMUserNotificationActivationTypeOtherButtonClicked,
    ZMUserNotificationActivationTypeActionButtonClicked
};

NS_ASSUME_NONNULL_BEGIN

static NSString * const ZMUserNotificationThreadIdentifierChat = @"ZMUserNotificationThreadIdentifierChat";
static NSString * const ZMUserNotificationThreadIdentifierMail = @"ZMUserNotificationThreadIdentifierMail";
static NSString * const ZMUserNotificationThreadIdentifierUpcomingMeetingReminder = @"ZMUserNotificationThreadIdentifierUpcomingMeetingReminder";

extern NSString *kZMUserNotificationClickContentNoticiation;

typedef void(^ZMNotfCallbackBlock)(ZMUserNotification *notification, BOOL *remove);

@interface ZMUserNotification : NSObject

@property (nonatomic, retain,nullable) NSString *identifier;
@property (nonatomic, retain,nullable) NSString *title;
@property (nonatomic, retain,nullable) NSString *subtitle;
@property (nonatomic, retain,nullable) NSString *body;
@property (nonatomic, retain,nullable) NSImage *contentImage;
@property (nonatomic, retain,nullable) NSURL *contentImageURL;
@property (nonatomic, assign) BOOL hasReplyButton;// default NO
@property (nonatomic, assign) BOOL hasActionButton;// default NO
@property (nonatomic, retain,nullable) NSString *actionButtonTitle;// if hasActionButton = YES, need set this property
@property (nonatomic, retain,nullable) NSString *otherButtonTitle;
@property (nonatomic, retain) NSArray *customActions;
@property (nonatomic, copy) NSString *customActionIdentifier;
@property (nonatomic, retain,nullable) NSDictionary *userInfo;
@property (nonatomic, assign) BOOL playSound;// default NO
@property (nonatomic, readonly) NSString *userText;
@property (nonatomic, readonly) ZMUserNotificationActivationType activationType;
@property (nonatomic, copy) NSString *threadIdentifier;

@end

@interface ZMNotificationManager : NSObject <NSUserNotificationCenterDelegate, UNUserNotificationCenterDelegate>

+ (ZMNotificationManager *)sharedInstance;

- (void)removeNotificationWithTarget:(id)target;
- (void)removeNotificationWithDelegate:(id)delegate;

- (void)deliverNotification:(ZMUserNotification *)notification;
- (void)deliverNotification:(ZMUserNotification *)notification delegate:(id<ZMNotificationProtocol>)delegate;
- (void)deliverNotification:(ZMUserNotification *)notification callBackTarget:(id)target block:(nullable ZMNotfCallbackBlock)completion;

- (void)getDeliveredNotificationsWithCompletionHandler:(void(^)(NSArray<ZMUserNotification *> *notifications))completionHandler;

- (void)removeDeliveredNotificationWithIdentifier:(NSString *)identifier;
- (void)removeAllDeliveredNotifications;

@end
NS_ASSUME_NONNULL_END

