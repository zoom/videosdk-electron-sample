//
//  ZMMTInterpretExMgr.h
//  VideoUIBridge
//
//  Created by martin.yu on 10/14/22.
//

#ifndef ZMMTInterpretExMgr_h
#define ZMMTInterpretExMgr_h

#import <zVideoUIBridge/ZMSignInterpretLanguage.h>

@class ZMInterpretLanguage;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTInterpretExMgr <ZMRoutableObject>
- (void)showInterpretationMgrWindow;
- (void)closeInterpretationMgrWindow;

- (void)layoutInterpreterToolbarWindow;
- (void)showInterpreterToolbarWindow;
- (void)closeInterpreterToolbarWindow;

- (void)closeAllWindow;

- (void)updateListeningLanguage:(ZMInterpretLanguage *)language;
- (void)hideListeningSpeakingTip;

@property (nonatomic, copy, nullable) ZMSignInterpretLanguage *currentSignLanguage;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMTInterpretExMgr_h */
