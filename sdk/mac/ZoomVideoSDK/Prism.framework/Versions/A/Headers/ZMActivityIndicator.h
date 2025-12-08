//
//  ZMActivityIndicator.h
//  ReplicatorDemo
//
//  Created by Huxley on 2018/3/27.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMActivityIndicator : NSView

@property (copy, nonatomic) IBInspectable NSColor *foregroundColor;//default: White
@property (copy, nonatomic) IBInspectable NSColor *backgroundColor;//default: nil

@property (nonatomic) IBInspectable NSControlSize effectiveSize;

- (void)startAnimation;
- (void)stopAnimation;

@end

NS_ASSUME_NONNULL_END
