//
//  ZMMTGridDragView.h
//  ZMGridDemo
//
//  Created by Francis Zhuo on 2020/8/13.
//  Copyright © 2020 Francis Zhuo. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZMMTGridDragViewDelegate <NSObject>
- (BOOL)onLeftMouseDown:(NSEvent*)event;
- (BOOL)onLeftMouseDrag:(NSEvent*)event;
- (BOOL)onLeftMouseUp:(NSEvent*)event;
@end


@interface ZMMTGridDragView : NSView
@property(assign)id<ZMMTGridDragViewDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
