//
//  IZMMTInterpretationMgr.h
//  VideoUIBridge
//
//  Created by martin.yu on 9/26/22.
//

#ifndef IZMMTInterpretationMgr_h
#define IZMMTInterpretationMgr_h

#import <zVideoUIBridge/ZMMTConstants.h>
#import <zVideoUIBridge/ZMSignInterpretLanguage.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTInterpretationMgr <ZMRoutableObject, ZMMTForceUpdateProtocol>
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, readonly) ZMConfSession *confSession;

- (void)showInterpretationMgrWindow;
- (void)closeInterpretationMgrWindow;
- (void)closeAllWindow;

- (void)showInterpreterNotification;

- (void)mainVideoViewSizeDidChanged;

- (void)onSwitchSilentMode;
- (void)onHostChangedWithUser:(ZMUser *)user;
- (void)onCoHostChangedWithUser:(ZMUser *)user;

@property (nonatomic, copy, nullable) ZMSignInterpretLanguage *currentSignLanguage;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTInterpretationMgr_h */
