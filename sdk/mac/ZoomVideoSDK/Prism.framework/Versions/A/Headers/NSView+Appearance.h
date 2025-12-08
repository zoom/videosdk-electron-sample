//
//  NSView+Appearance.h
//  Prism
//
//  Created by Felipe Bastos on 7/2/25.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSView (LegacyAppearance)

- (void)_hook_viewDidChangeEffectiveAppearance;

@end

NS_ASSUME_NONNULL_END
