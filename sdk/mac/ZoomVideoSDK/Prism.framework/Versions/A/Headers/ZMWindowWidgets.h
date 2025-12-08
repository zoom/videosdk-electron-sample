//
//  ZMWindowWidgets.h
//  NewUI
//
//  Created by Huxley Yang on 12/01/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Prism/ZMStackView.h>

@interface ZMWindowWidgets : ZMStackView
{
    @protected
    BOOL _widgetsLoad;
    BOOL _mouseInside;
    NSTrackingArea *_trackingArea;
}

@property (weak, readonly) NSButton *closeButton;//_NSThemeWidget
@property (weak, readonly) NSButton *miniaturizeButton;//
@property (weak, readonly) NSButton *zoomButton;//_NSThemeZoomWidget

- (void)loadWidgetsIfNeeded;

- (void)redisplayWidgets;

@end
