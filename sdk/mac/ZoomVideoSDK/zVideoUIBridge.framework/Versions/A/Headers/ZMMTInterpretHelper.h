//
//  ZMMTInterpretHelper.h
//  VideoUIBridge
//
//  Created by martin.yu on 9/20/22.
//

#import <zVideoUIBridge/ZMBaseHelper.h>
#import <zVideoUIBridge/ZMSignLanguageInterpreter.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser, ZMInterpreter, ZMInterpretLanguage;

@interface ZMMTInterpretHelper : ZMBaseHelper

#pragma mark - Audio Interpretation

- (BOOL)isInterpretationEnabled;
- (BOOL)isInterpretationStarted;

- (BOOL)startInterpretation:(NSArray<ZMInterpreter *> *)interpreters;
- (BOOL)updateInterpreterList:(NSArray<ZMInterpreter *> *)interpreters;
- (void)stopInterpretation;
- (nullable NSArray<ZMInterpretLanguage *> *)getAvailableInterpreteLansList;
- (BOOL)setInterpreterActiveLan:(ZMInterpretLanguage *)language;
- (nullable ZMInterpretLanguage *)getInterpreterActiveLan;
- (void)setParticipantActiveLan:(ZMInterpretLanguage *)language;
- (nullable ZMInterpretLanguage *)getParticipantActiveLan;
- (nullable NSArray<ZMInterpreter *> *)getWebInterpreterList;
- (nullable NSArray<ZMInterpreter *> *)getInterpreterList;
- (nullable NSArray<ZMInterpretLanguage *> *)getCustomInterpreteLanList;
- (void)setCustomInterpreteLanList;

- (void)setOriginalAudioChannelEnable:(BOOL)enable;//ZOOM-140277
- (BOOL)isOriginalAudioChannelEnabled;//ZOOM-140277

- (void)setInterpreterListenLan:(ZMInterpretLanguage *)lan;
- (nullable ZMInterpretLanguage *)getInterpreterListenLan;

- (nullable ZMInterpretLanguage *)getInterpretLanguage:(int)language;
- (nullable ZMInterpretLanguage *)getInterpretLanguageWithID:(NSString *)languageID;

#pragma mark - Sign Language Interpretation

- (BOOL)isSignLanguageInterpretationEnabled;
- (BOOL)isSignLanguageInterpretationStarted;

- (BOOL)startSignLanguageInterpretation:(NSArray<ZMSignLanguageInterpreter *> *)interpreters;
- (BOOL)updateSignLanguageInterpreterList:(NSArray<ZMSignLanguageInterpreter *> *)interpreters;
- (void)stopSignLanguageInterpretation;

- (nullable ZMSignInterpretLanguage *)getSignLanguageWithLanguageID:(NSString *)languageID;
- (nullable NSArray<ZMSignInterpretLanguage *> *)getAvailableSignLanguageList;
- (nullable NSArray<ZMSignInterpretLanguage *> *)getWebSignLanguageList;

- (nullable NSArray<ZMSignLanguageInterpreter *> *)getWebSignLanguageInterpreterList;
- (nullable NSArray<ZMSignLanguageInterpreter *> *)getSignLanguageInterpreterList;

- (nullable NSArray<ZMSignLanguageInterpreter *> *)getShowInterpreterListCurrentLanguage:(ZMSignInterpretLanguage *)language;

- (BOOL)allowSignLanguageInterpreterToTalk:(BOOL)allow user:(ZMUser *)user;
@end

NS_ASSUME_NONNULL_END
