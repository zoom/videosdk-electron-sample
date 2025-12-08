//
//  ZMStackView.h
//  zChatUI
//
//  Created by Huxley on 2018/4/25.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Prism/ZMAccessibleView.h>
#import <Prism/ZMUserInterfaceOrientation.h>
#import <Prism/ZMLayoutDirection.h>

@interface ZMStackView : ZMAccessibleView

@property IBInspectable ZMUserInterfaceOrientation orientation;

@property IBInspectable CGFloat spacing;
@property IBInspectable NSLayoutAttribute alignment;
@property IBInspectable NSEdgeInsets edgeInsets;
@property IBInspectable CGFloat minContentHeight;

@property IBInspectable BOOL isRespondedArrowKey;
@property IBInspectable BOOL isKeyboardAccessGroup;

/**
 * the property is only effect when alignment == kZMUserInterfaceOrientationHorizontal
 * default value is ZMLayoutDirectionLeftToRight
 */
@property IBInspectable ZMLayoutDirection layoutDirection;

- (void)relayoutUsingFrameCalculation;
- (void)relayoutUsingLayoutConstrains;
/** This method is useless if(self.orientation != kZMUserInterfaceOrientationVertical) */
- (void)relayoutWithFixedWidth:(float)fixedWidth;

- (void)removeAllSubviewsAndConstraints;
@end
