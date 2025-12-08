//
//  NSTableCellView+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/6/20.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSTableCellView (ZoomKit)

- (void)rowSelectionDidChangeTo:(BOOL)bSelected;//!< do nothing, to override

- (BOOL)isTableViewFirstResponse;

- (nullable NSTableView *)currentTableView;

- (nullable NSScrollView *)currentEnclosingScrollView;

- (NSTableRowView* _Nullable)enclosingRowView;
- (NSTableView* _Nullable)enclosingTableView;
- (NSOutlineView* _Nullable)enclosingOutlineView;
@end

NS_ASSUME_NONNULL_END
