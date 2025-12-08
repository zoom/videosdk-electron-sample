//
//  ZMSharePaddingWindow.h
//  ZCommonUI
//
//  Created by walt.li on 8/14/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSharePaddingWindow : NSPanel
- (void)invisibleInSharing;
- (void)startAnimation;
- (void)stopAnimation;
@end

@interface ZMShareNumberWindow : NSPanel
- (void)invisibleInSharing;
- (void)setIndex:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
