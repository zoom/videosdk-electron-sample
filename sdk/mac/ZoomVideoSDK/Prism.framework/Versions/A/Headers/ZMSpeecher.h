//
//  ZMSpeecher.h
//  ZCommonUI
//
//  Created by Yang on 2016/9/19.
//  Copyright © 2016 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMSpeecher : NSObject
{
    NSSpeechSynthesizer * _synthesizer;
    NSMutableArray * _prepareStrings;
}

+ (void)speakString:(NSString *)string;
+ (void)speakString:(NSString *)string afterDelay:(NSTimeInterval)delay;
+ (void)speakStringWithSynthesizer:(NSString *)string;
+ (BOOL)speakString:(NSString *)string toUrl:(NSURL *)url;//[zoom-35476]

@end
