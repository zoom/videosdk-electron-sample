//
//  ZMMTStudioRender.h
//  zStudioUI
//
//  Created by geno.chen on 2021/6/2.
//

#import <Cocoa/Cocoa.h>
#include <zPSApp/media/IPSRender.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTStudioBizSession;

@interface ZMMTStudioRender : NSObject

@property (nonatomic, assign) NSRect frame;
@property (nonatomic, assign) SSB_MC_VIDEO_ASPECT_MODE aspectMode;
@property (nonatomic, readonly, nullable) ps::IPSRender *studioRender;
- (instancetype)initWithView:(NSView *)view bizSession:(ZMMTStudioBizSession *)bizSession;
- (void)redraw;
- (void)destroyRender;

@end

NS_ASSUME_NONNULL_END
