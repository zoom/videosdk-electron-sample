//
//  ZPTrackingButton.h
//  SaasBeeUILib
//
//  Created by zoom on 13-2-25.
//  Copyright (c) 2013 zoom. All rights reserved.
//

#import <Prism/ZMRichKeyButton.h>

@interface ZPTrackingButton : ZMRichKeyButton

@property(nonatomic, assign) BOOL enableHover;///< enableHover default value is YES
@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, retain) NSTrackingArea* trackingArea;
@property(nonatomic, retain) NSString* customTooltip;
/// If YES, self.customTooltip will also appear when this button is the first responder.
/// @discussion Use this to make the tooltip appear when VoiceOver/full-tab-access users select the button.
@property (nonatomic, assign) BOOL showTooltipWhenFirstResponder;
@property(nonatomic, assign) SEL hoverAction;

@property (nonatomic, assign) BOOL overrideCanBecomeKeyView;

@property(nonatomic, assign) BOOL updateHoveredWhenUpdateTrackingAreas;//default YES

- (void)cleanUp;

- (void)customMouseEntered;
- (void)customMouseExited;

- (NSRect)trackingRect;
- (NSTrackingAreaOptions)trackingOptions;

@end
