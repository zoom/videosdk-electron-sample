//
//  ZMMTThumbnailView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 2020/8/14.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTGridView.h>
#import <zVideoUIBridge/ZMMTVideoView.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMMTThumbnailView;
@protocol ZMMTThumbnailViewDelegate <ZMMTGridViewDelegate>
@optional

- (BOOL)isFirstPageForView:(ZMMTThumbnailView*)thumbnailView;
- (BOOL)isLastPageForView:(ZMMTThumbnailView*)thumbnailView;

- (BOOL)canScroll2PrevPageForView:(ZMMTThumbnailView*)thumbnailView;
- (BOOL)canScroll2NextPageForView:(ZMMTThumbnailView*)thumbnailView;

- (NSUInteger)totalPageNumberForView:(ZMMTThumbnailView*)thumbnailView;
- (NSUInteger)currentPageNumberForView:(ZMMTThumbnailView*)thumbnailView;

- (void)onScroll2PrevPageForView:(ZMMTThumbnailView*)thumbnailView;
- (void)onScroll2NextPageForView:(ZMMTThumbnailView*)thumbnailView;

- (BOOL)canShowedArrowButtonForView:(ZMMTThumbnailView*)thumbnailView;

- (NSRect)getLeftArrowRectForView:(ZMMTThumbnailView*)thumbnailView;
- (NSRect)getRightArrowRectForView:(ZMMTThumbnailView*)thumbnailView;

- (BOOL)canMoveWindowForView:(ZMMTThumbnailView*)thumbnailView;

- (BOOL)isVerticalLayoutForView:(ZMMTThumbnailView*)thumbnailView;

//for key view
- (BOOL)canShowFocusRingForView:(ZMMTThumbnailView*)thumbnailView;
- (NSRect)focusRingMaskBoundsForView:(ZMMTThumbnailView*)thumbnailView;

- (NSRect)visibleRectForView:(ZMMTThumbnailView*)thumbnailView;
@end

@class ZMMTBaseVideoCellView;
@interface ZMMTThumbnailView : ZMMTGridView<ZMMTVideoView>
@property(nullable, weak) id<ZMMTThumbnailViewDelegate> delegate;
@property(assign) BOOL oneRenderMode;
@property(readonly, assign) BOOL isVideoShowing;
@property(readonly, retain) NSArray<ZMMTBaseVideoCellView*>* videoViews;

+ (Class)videoViewClass;//default is ZMMTBaseVideoCellView

- (void)cleanUp NS_REQUIRES_SUPER;

- (void)updateArrowButton;//for subclass override
- (void)relayoutUI;
- (void)relayoutUIWithAnimation:(BOOL)animation;

//for inheritance
- (id)getNewVideoView;
- (void)recyclingVideoView:(id)videoView;

- (void)showFocusRingStatusChanged;

- (NSRect)visibleBounds;
@end
NS_ASSUME_NONNULL_END
