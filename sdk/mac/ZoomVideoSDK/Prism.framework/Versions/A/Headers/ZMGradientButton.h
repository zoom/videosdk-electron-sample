//
//  ZMGradientButton.h
//  ZCommonUI
//
//  Created by John on 6/27/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Prism/ZMButton.h>

@interface ZMGradientButton : ZMButton
{
    NSGradient* _normalGradient;
    NSGradient* _hoverGradient;
    NSGradient* _pressGradient;
    NSGradient* _disableGradient;
    
    float       _angle;
}
@property(nonatomic, retain) NSGradient* normalGradient;
@property(nonatomic, retain) NSGradient* hoverGradient;
@property(nonatomic, retain) NSGradient* pressGradient;
@property(nonatomic, retain) NSGradient* disableGradient;
@property(nonatomic, assign) float angle;
@end
