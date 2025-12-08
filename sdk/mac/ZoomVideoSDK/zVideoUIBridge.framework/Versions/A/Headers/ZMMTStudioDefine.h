//
//  ZMMTStudioDefine.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef ZMMTStudioDefine_h
#define ZMMTStudioDefine_h

#include <zPSApp/define/PSDefine.h>

static inline ps::PSRect StudioCanvasRectFromNSRect(NSRect rect) {
    ps::PSRect rc;
    rc.x = rect.origin.x;
    rc.y = rect.origin.y;
    rc.width = rect.size.width;
    rc.height = rect.size.height;
    return rc;
}
static inline NSRect NSRectFromStudioCanvasRect(ps::PSRect rect) {
    return NSMakeRect(rect.x, rect.y, rect.width, rect.height);
}

static inline ps::PSFrameSize StudioFrameSizeFromVideoSize(NSInteger videoSize) {
    ps::PSFrameSize psSize = ps::PSFrameSize_None;
    if (videoSize == SSB_MC_VIDEO_SIZE_4) {
        psSize = ps::PSFrameSize_1080P;
    } else if (videoSize == SSB_MC_VIDEO_SIZE_3) {
        psSize = ps::PSFrameSize_720P;
    } else if (videoSize == SSB_MC_VIDEO_SIZE_2) {
        psSize = ps::PSFrameSize_360P;
    } else if (videoSize == SSB_MC_VIDEO_SIZE_1) {
        psSize = ps::PSFrameSize_180P;
    } else if (videoSize == SSB_MC_VIDEO_SIZE_0) {
        psSize = ps::PSFrameSize_90P;
    }
    
    return psSize;
}

#endif /* Header_h */
