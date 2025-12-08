//
//  ZMAXHelper.h
//  ZCommonUI
//
//  Created by likevin on 6/29/16.
//  Copyright © 2016 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMAXHelper : NSObject

+ (void)registAXHelperObserver API_AVAILABLE(macos(10.13));

+ (BOOL)isVoiceOverOn;
+ (BOOL)isTabToAllControlOptionOn;
@end

@interface NSView (ZMAccessibility)

//@property (nonatomic, retain) IBOutlet NSView * preferPreviousKeyView;
//@property (nonatomic, retain) IBOutlet NSView * preferNextKeyView;

//- (void)setPreferCanBecomeKeyView:(BOOL)canBecomeKeyView;

@end
