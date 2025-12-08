//
//  ZMRadioButton.h
//  ZCommonUI
//
//  Created by groot.ding on 2018/5/24.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMALButton.h>

#pragma mark - ZMRadioButton
@interface ZMRadioButtonCell : ZMALButtonCell
@end

@interface ZMRadioButton : ZMALButton
@end

#pragma mark - ZMImageRadioButton
@interface ZMImageRadioButtonCell : ZMRadioButtonCell
@end

@interface ZMImageRadioButton : ZMRadioButton
@property(retain)IBInspectable NSImage* bottomImage;
- (void)cleanUp;
@end
