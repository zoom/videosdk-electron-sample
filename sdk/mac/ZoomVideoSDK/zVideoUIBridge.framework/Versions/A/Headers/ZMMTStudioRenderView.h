//
//  ZMMTStudioRenderView.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/20.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <zVideoUIBridge/ZMMTBaseView.h>

@class ZMMTStudioBizSession;
@class ZMMTStudioRootCanvas;
@class ZMMTStudioRender;
NS_ASSUME_NONNULL_BEGIN

@interface ZMMTStudioRenderView : ZMMTBaseView

@property (nonatomic, strong, readonly) ZMMTStudioRender *render;

- (instancetype)initWithBizSession:(ZMMTStudioBizSession *)session;

- (void)destroyRender;
- (void)updateUI;
- (void)attachCanvas:(ZMMTStudioRootCanvas *)canvas;
- (void)detachCanvas;
@end

NS_ASSUME_NONNULL_END
