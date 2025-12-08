//
//  ZMPopupTipWindow.h
//  ZCommonUI
//
//  Created by lin on 10/01/2018.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMPopupTipWindow : NSWindow 
{
    NSColor *_alertWindowColor;
    NSColor *_alertTextColor;
    float _autoCloseTime;
}
@property(nonatomic,strong)NSColor *alertWindowColor;
@property(nonatomic,strong)NSColor *alertTextColor;
@property(nonatomic, assign)float autoCloseTime;
- (id)initWithFrame:(NSRect)frame;
- (void)setAlertTitle:(NSString *)title;
@end

