//
//  ZMHotkeyMenuCenter.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/10/30.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMHotkeyMenuCenter : NSObject
+ (id)sharedInstance;
- (void)cleanUp;
- (BOOL)bindMenuItem:(NSMenuItem*)item withIdentifier:(NSString*)identifier;
- (void)unbindMenuItem:(NSMenuItem*)item;
- (void)unbindAll;
@end
