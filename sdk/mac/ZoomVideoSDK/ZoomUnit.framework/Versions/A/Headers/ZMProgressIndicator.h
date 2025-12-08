//
//  ZMProgressIndicator.h
//  TestDownloader
//
//  Created by Yang on 05/01/2018.
//  Copyright © 2018 Yang. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMProgressIndicator : NSProgressIndicator
{
    NSAttributedString *_attributedStringValue;
}

@property (copy, nonatomic) NSAttributedString *attributedStringValue;

@end

@interface ZMProgressIndicatorView : NSView

@property (nonatomic, retain) NSProgressIndicator *progressIndicator;

- (void)start;
- (void)stop;
- (BOOL)isShowing;

@end
