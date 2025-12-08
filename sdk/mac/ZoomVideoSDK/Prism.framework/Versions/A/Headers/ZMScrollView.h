//
//  ZMScrollView.h
//  ZCommonUI
//
//  Created by groot.ding on 2019/5/29.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMScrollView : NSScrollView

@property (nonatomic,assign) BOOL scrollEnable;

@property (nonatomic,assign) BOOL disableScrollWhenBeginOutside;

@property (nonatomic,assign) BOOL disableScrollWhenDocumentInside;

@property (nonatomic,assign) BOOL disableScrollWheel;

@property (nonatomic,assign) BOOL allowPassScrollEvent;

@end
