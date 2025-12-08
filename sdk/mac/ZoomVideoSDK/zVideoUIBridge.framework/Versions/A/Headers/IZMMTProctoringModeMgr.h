//
//  IZMMTProctoringModeMgr.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2023/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMMTProctoringModeViewController;

typedef NS_ENUM(NSInteger, ZMMTProctoringType) {
    ZMMTProctoringTypeNone,
    ZMMTProctoringTypeSideBySide,
    ZMMTProctoringTypeFoucsOne,
};

@protocol IZMMTProctoringModeMgr <ZMRoutableObject>

- (ZMMTProctoringModeViewController *)newViewControllerWithType:(ZMMTType)type;

- (void)tryScroll2PrevPage;

- (void)tryScroll2NextPage;

- (void)onSceneDependerChanged;

- (void)stopProctoringMode;

#ifdef __cplusplus
- (void)startProctoringWithContext:(CmmProctoringModeContext)context;
#endif

- (void)updateShareFocusModeIfNeed:(ZMConfSession *)confSession;

- (void)requestToStartShareDesktop:(ZMUser *)inUser;

- (ZMMTProctoringType)getCurrentProctoringTypeByViewControllerType:(ZMMTType)viewControllerType;

@end


@protocol IZMMTProctoringModeProtocol <NSObject>

@optional
- (void)foucsSharingWithShareSource:(ZMShareSource *)inShareSource;
- (void)exitFoucsSharingWithShareSource:(ZMShareSource *)inShareSource;
- (void)proctoringTypeChangedWithShareSource:(ZMShareSource *)inShareSource;

@end

NS_ASSUME_NONNULL_END
