//
//  ZMSwitch.h
//  Training
//
//  Created by Huxley on 2018/8/30.
//  Copyright © 2018 Huxley. All rights reserved.
//

@interface ZMSwitch : NSView <NSAccessibilitySwitch>

@property (assign, nonatomic) NSControlStateValue state;//NSOnState or NSOffState
@property (assign, nonatomic) BOOL enable;
@property (assign, nonatomic) CGFloat focusedBorderWidth;//Default value is 3
@property (copy, nonatomic) IBInspectable NSString *onString;
@property (copy, nonatomic) IBInspectable NSString *offString;

@property (weak) IBOutlet id target;
@property SEL action;

- (void)toggle;

@end

@interface ZMRoundSwitch : ZMSwitch

@property (copy, nonatomic) NSString *zmAccessibilityLabel;

@end
