//
//  ZMInterpreter.h
//  InterpretationDemo
//
//  Created by Geno on 2019/5/27.
//  Copyright © 2019 chenjiannan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMInterpretLanguage.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMInterpreter : NSObject <NSCopying>

@property (nonatomic, assign) ZMUserID userID;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy, nullable) NSString *email;

@property (nonatomic, retain) ZMInterpretLanguage *firstLanguage;
@property (nonatomic, retain) ZMInterpretLanguage *secondLanguage;

- (void)update:(ZMInterpreter *)object;

- (BOOL)isVaild;

@end

NS_ASSUME_NONNULL_END
