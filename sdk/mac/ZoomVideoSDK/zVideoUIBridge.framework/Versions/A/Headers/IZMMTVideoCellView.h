//
//  IZMMTVideoCellView.h
//  VideoUI
//
//  Created by martin.yu on 9/14/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTVideoCellView_h
#define IZMMTVideoCellView_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTVideoCellView;
@protocol ZMMTVideoCellViewDelegate <ZMMTBaseVideoCellViewDelegate>
@optional
- (BOOL)enableShowButtonsForVideoCellView:(ZMMTBaseVideoCellView<IZMMTVideoCellView> *)cellView;
- (BOOL)enableShowMuteButtonForVideoCellView:(ZMMTBaseVideoCellView<IZMMTVideoCellView> *)cellView;
- (BOOL)enableShowLiveTagForVideoCellView:(ZMMTBaseVideoCellView<IZMMTVideoCellView> *)cellView;

@end

@class PZMMenu;
@protocol IZMMTVideoCellView <ZMRoutableObject>
@property (nonatomic, weak) id<ZMMTVideoCellViewDelegate> delegate;
@property (nonatomic, nullable, retain) PZMMenu* moreMenu;
- (BOOL)enableShowMoreButton;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTVideoCellView_h */
