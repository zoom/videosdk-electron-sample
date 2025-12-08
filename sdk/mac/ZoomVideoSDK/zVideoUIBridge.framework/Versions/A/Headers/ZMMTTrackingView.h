//
//  ZMMTTrackingView.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/24/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseView.h>
#import <zVideoUIBridge/ZMMTConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTTrackingView : ZMMTBaseView
@property(assign) BOOL hovered;
@property(weak) id<ZMMTTrackingViewDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
