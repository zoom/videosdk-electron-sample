//
//  ZMContentCollectionSubviewDelegate.h
//  ZoomKit
//
//  Created by Michael Lin on 2024/6/7.
//

#ifndef ZMContentCollectionSubviewDelegate_h
#define ZMContentCollectionSubviewDelegate_h

@protocol ZMContentCollectionSubviewDelegate <NSObject>

- (void)contentCollectionSubviewBecomeFirstResponder:(NSView *)view;
- (void)contentCollectionSubviewResignFirstResponder:(NSView *)view;

@end

#endif /* ZMContentCollectionSubviewDelegate_h */
