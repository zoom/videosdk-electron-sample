//
//  ZMMTStudioBizSession.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <zPSApp/media/IPSRender.h>
#include <zPSApp/media/IPSCanvas.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus


class IPSRender;
class IPSCanvas;

class IPSCanvasMgr;
class IPSRenderMgr;

#endif

typedef NS_ENUM(NSInteger, ZMMTStudioBizSessionType) {
    ZMMTStudioBizSessionTypeMeeting
};

@interface ZMMTStudioBizSession : NSObject

@property (nonatomic, class, readonly) ZMMTStudioBizSession *meetingSession;

@property (nonatomic, readonly) ZMMTStudioBizSessionType sessionType;
- (instancetype)initWithSessionType:(ZMMTStudioBizSessionType)sessionType;

#ifdef __cplusplus
@property (nonatomic, assign, nullable, readonly) ps::IPSCanvasMgr *canvasMgr;
@property (nonatomic, assign, nullable, readonly) ps::IPSRenderMgr *videoRenderMgr;
#endif

@end

NS_ASSUME_NONNULL_END
