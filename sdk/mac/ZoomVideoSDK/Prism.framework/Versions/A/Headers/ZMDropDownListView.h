//
//  ZMDropDownListView.h
//  ZCommonUI
//
//  Created by Geno on 2019/6/25.
//  Copyright © 2019 chenjiannan. All rights reserved.
//

#import <Prism/ZMBaseView.h>

@class ZMDropDownListView;
@class ZMDropDownItem;
@protocol ZMDropDownListViewDelegate <NSObject>

- (void)dropDownListView:(ZMDropDownListView *)listView didSelectRow:(NSInteger)row;

@end


@interface ZMDropDownListView : ZMNonLayerBaseView


@property (nonatomic, retain) NSMutableArray <ZMDropDownItem *> *itemArray;
@property (nonatomic, weak) id<ZMDropDownListViewDelegate> delegate;
@property (nonatomic, assign) CGFloat rowHeight;
@property (nonatomic, assign) NSInteger selectedRow;

- (void)scrollRowToVisible:(NSInteger)row;

@end
