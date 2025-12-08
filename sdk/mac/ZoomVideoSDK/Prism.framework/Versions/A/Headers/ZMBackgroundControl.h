//
//  ZMBackgroundControl.h
//  ZCommonUI
//
//  Created by John on 16/4/5.
//  Copyright (c) 2016 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBackgroundView.h>
#import <Prism/NSObject+ZMConvenience.h>
#import <Prism/NSView+ZoomKit.h>

@interface ZMBackgroundControl : ZMTagView{
    NSColor*    _backgroundColor;
    NSImage*    _backgroundImage;
    int         _cornerType;
    int         _radius;
}
@property(nonatomic, retain) NSColor* backgroundColor;
@property(nonatomic, retain) NSImage* backgroundImage;
@property(nonatomic, assign) int cornerType;
@property(nonatomic, assign) int radius;
@end

//ZOOM-30336
typedef void(^ZMBlockViewDrawer)(NSRect bounds);
@interface ZMBlockView : ZMTagView{
    ZMBlockViewDrawer _blockViewDrawer;
}
@property(copy) ZMBlockViewDrawer blockViewDrawer;
- (void)cleanUp;
@end
