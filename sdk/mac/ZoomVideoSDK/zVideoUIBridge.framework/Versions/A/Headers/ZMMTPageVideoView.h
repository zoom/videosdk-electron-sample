//
//  ZMMTPageVideoView.h
//  VideoUI
//
//  Created by Francis Zhuo on 7/15/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTThumbnailView.h>

NS_ASSUME_NONNULL_BEGIN
@interface ZMMTPageVideoView : ZMMTVideoView
@property(readonly, retain) ZMMTThumbnailView* thumbnailView;

@property (nonatomic, retain) ZMButton* prePageButton;
@property (nonatomic, retain) ZMButton* nextPageButton;

+ (Class)thumbnailViewClass;//default is ZMMTThumbnailView

- (void)updatePageButton;//for override
@end

NS_ASSUME_NONNULL_END
