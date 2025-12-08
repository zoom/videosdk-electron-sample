//
//  ZMTabView.h
//  ZCommonUI
//
//  Created by John on 11/25/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTableRowView : NSTableRowView
{
    NSColor* _hoverColor;
    BOOL    _hovered;
}
@property (nonatomic, readwrite, strong)NSColor*    hoverColor;
@property (nonatomic, readwrite, assign)BOOL        hovered;

- (void)updateState;
@end

@interface ZMTrackingTableView : NSTableView <ZMTrackingScrollViewProtocol>

@property(readwrite,strong)ZMTableRowView*      lastSelectItemView;
@property(readwrite,assign)BOOL                 isEnableTrack;
@property(readwrite,assign)BOOL                 isMouseEntered;

- (void)mouseEnteredView:(id)sender;
- (void)mouseMovedOnView:(id)sender;
- (void)mouseExitedView:(id)sender;
- (void)selectItemViewDidChange;

@end

