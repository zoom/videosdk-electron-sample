//
//  ZMTrackingScrollView.h
//  ZCommonUI
//
//  Created by francis on 04/01/2017.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@protocol ZMTrackingScrollViewProtocol <NSObject>
@optional
- (void)mouseEnteredView:(id)sender;
- (void)mouseMovedOnView:(id)sender;
- (void)mouseExitedView:(id)sender;
- (void)scrollWheelView:(id)sender;
@end

@interface ZMTrackingScrollView : NSScrollView
{
    NSTrackingArea*                         _area;
    id<ZMTrackingScrollViewProtocol>        _delegate;
    
    BOOL _canRespondMouseEntered;
    BOOL _canRespondMouseExited;
    BOOL _canRespondMouseMoved;
}

@property (weak) IBOutlet id<ZMTrackingScrollViewProtocol> delegate;

- (void)setCustomScrollerStyle:(NSScrollerStyle)customScrollerStyle;
- (void)cleanUp;
@end
