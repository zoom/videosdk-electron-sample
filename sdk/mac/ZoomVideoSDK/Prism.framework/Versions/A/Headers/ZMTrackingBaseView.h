//
//  ZMTrackingBaseView.h
//  SaasBeePTUIModule
//
//  Created by Justin on 1/22/13.
//  Copyright (c) 2013 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTrackingBaseView : NSView {
    NSTrackingRectTag               _trackingTag;
    BOOL                            _hovered;
    BOOL                            _pressed;
}

@property (nonatomic, readwrite, assign)BOOL    hovered;
@property (nonatomic, readwrite, assign)BOOL    pressed;

- (void)startTrackingView;
- (void)stopTrackingView;
- (void)resetTrackingView;
- (void)cleanup;

@end
