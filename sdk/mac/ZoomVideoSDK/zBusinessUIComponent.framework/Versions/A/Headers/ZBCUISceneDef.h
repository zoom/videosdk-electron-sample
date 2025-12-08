//
//  ZBCUISceneDef.h
//  zBusinessUIComponent
//
//  Created by Giannis Ge on 2023/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - enums
typedef NS_ENUM(NSUInteger, ZBCUILeaveSceneToolbarEndButtonColorType) {
    ZBCUILeaveSceneToolbarEndButtonColorType_Default = 0,
    ZBCUILeaveSceneToolbarEndButtonColorType_Blue,
    ZBCUILeaveSceneToolbarEndButtonColorType_Grey,
    ZBCUILeaveSceneToolbarEndButtonColorType_Red,
};

typedef NS_ENUM(NSUInteger, ZBCUISceneType) {
    ZBCUISceneType_None = 0,
    ZBCUISceneType_Toolbar,
    ZBCUISceneType_Audio,
    ZBCUISceneType_Video,
    ZBCUISceneType_SendShare,
    ZBCUISceneType_ViewShare,
    ZBCUISceneType_Chat,
    ZBCUISceneType_ClosedCaption,
    ZBCUISceneType_Whiteboard,
    ZBCUISceneType_ContactCenter,
    ZBCUISceneType_LeaveMeeting,
    ZBCUISceneType_Participant,
    ZBCUISceneType_Recording,
};

typedef NS_ENUM(NSUInteger, ZBCUIToolbarComponentType) {
    ZBCUIToolbarComponentType_None = 0,
    ZBCUIToolbarComponentType_Audio,
    ZBCUIToolbarComponentType_FitAudio,
    ZBCUIToolbarComponentType_Mute,
    ZBCUIToolbarComponentType_FitMute,
    ZBCUIToolbarComponentType_Volume,
    ZBCUIToolbarComponentType_FitVolume,
    ZBCUIToolbarComponentType_Video,
    ZBCUIToolbarComponentType_FitVideo,
    ZBCUIToolbarComponentType_Chat,
    ZBCUIToolbarComponentType_FitChat,
    ZBCUIToolbarComponentType_TeamChat,
    ZBCUIToolbarComponentType_FitTeamChat,
    ZBCUIToolbarComponentType_Participants,
    ZBCUIToolbarComponentType_FitParticipants,
    ZBCUIToolbarComponentType_Invite,
    ZBCUIToolbarComponentType_FitInvite,
    ZBCUIToolbarComponentType_Share,
    ZBCUIToolbarComponentType_NewShare,
    ZBCUIToolbarComponentType_PauseShare,
    ZBCUIToolbarComponentType_Annotation,
    ZBCUIToolbarComponentType_ClosedCaption,
    ZBCUIToolbarComponentType_Whiteboard,
    ZBCUIToolbarComponentType_Recording,
    ZBCUIToolbarComponentType_TakeOver,
    ZBCUIToolbarComponentType_Hold,
    ZBCUIToolbarComponentType_Release,
    ZBCUIToolbarComponentType_Transfer,
    ZBCUIToolbarComponentType_More,
    ZBCUIToolbarComponentType_FitMore,
    ZBCUIToolbarComponentType_Leaving,
    ZBCUIToolbarComponentType_RemoteControl,
    ZBCUIToolbarComponentType_FitRemoteControl,
};

// Toolbar is divided into three stacks: Head stack || middle stack || tail stack
typedef NS_ENUM(NSUInteger, ZBCUIToolbarStackViewType) {
    ZBCUIToolbarStackViewType_Head = 0,
    ZBCUIToolbarStackViewType_Middle,
    ZBCUIToolbarStackViewType_Tail,
};

@protocol ZBCUIWindowDelegateListener <NSObject>
@optional
- (void)windowWillEnterFullScreen;
- (void)windowDidEnterFullScreen;
- (void)windowWillExitFullScreen;
- (void)windowDidExitFullScreen;
- (void)windowWillMove;
- (void)windowDidMove;
- (void)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize;
- (void)windowDidResize;

@end

typedef void (^ZBCUIViewLayoutBlock)(NSView *view);
typedef void (^ZBCUIWindowLayoutBlock)(NSWindow *window);
typedef void (^ZBCUIWindowDelegateListenerBlock)(id<ZBCUIWindowDelegateListener> listener);

@interface ZBCUISceneDef : NSObject

@end

@interface ZBCUILeaveSceneDropdownButtonModel : NSObject
@property (nonatomic, retain) NSString *identifier;
@property (nonatomic, retain) NSString *title;
@property (nonatomic, assign) ZBCUILeaveSceneToolbarEndButtonColorType colorType;
@end

NS_ASSUME_NONNULL_END
