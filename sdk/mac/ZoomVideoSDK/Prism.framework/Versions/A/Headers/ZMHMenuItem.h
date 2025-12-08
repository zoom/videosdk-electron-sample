//
//  ZMHMenuItem.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/24.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Prism/ZMBaseMenuItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMHMenuItem : ZMBaseMenuItem
- (void)updateImage:(NSImage *)image;
- (void)handleAccessibilityMethod;
@end

NS_ASSUME_NONNULL_END

