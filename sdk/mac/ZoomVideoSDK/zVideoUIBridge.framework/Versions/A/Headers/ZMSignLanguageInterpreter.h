//
//  ZMSignLanguageInterpreter.h
//  VideoUI
//
//  Created by martin.yu on 5/5/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMSignInterpretLanguage.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSignLanguageInterpreter : NSObject <NSCopying>
@property (nonatomic, weak) ZMConfSession *confSession;
@property (nonatomic, readonly, nullable) ZMUser *zmUser;

@property (nonatomic, assign) ZMUserID userID;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy, nullable) NSString *email;

@property (nonatomic, retain) ZMSignInterpretLanguage *language;

- (void)update:(ZMSignLanguageInterpreter *)object;

- (BOOL)isVaild;
@end

NS_ASSUME_NONNULL_END
