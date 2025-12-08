//
//  PZPTrackingButton.h
//  ZoomUnit
//
//  Created by Cooper.Chen on 2025/4/17.
//

#import <Prism/Prism-Swift.h>
#import <Prism/Prism.h>

@interface PZPTrackingButton : PZMRichKeyButton

@property(nonatomic, assign) BOOL enableHover;///< enableHover default value is YES
@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, strong) NSTrackingArea* trackingArea;
@property(nonatomic, strong) NSString* customTooltip;
/// If YES, self.customTooltip will also appear when this button is the first responder.
/// @discussion Use this to make the tooltip appear when VoiceOver/full-tab-access users select the button.
@property (nonatomic, assign) BOOL showTooltipWhenFirstResponder;
@property(nonatomic, assign) SEL hoverAction;

@property (nonatomic, assign) BOOL overrideCanBecomeKeyView;

@property(nonatomic, assign) BOOL updateHoveredWhenUpdateTrackingAreas;//default YES

@end
