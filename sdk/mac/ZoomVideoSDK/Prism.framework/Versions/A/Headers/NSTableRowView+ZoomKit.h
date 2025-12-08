//
//  NSTableRowView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/6/9.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSTableRowView (ZoomKit)

- (void)mouseHover:(BOOL)bHovered;//!< do nothing, to override

@property (readonly) NSTableCellView *cellView;

@end
