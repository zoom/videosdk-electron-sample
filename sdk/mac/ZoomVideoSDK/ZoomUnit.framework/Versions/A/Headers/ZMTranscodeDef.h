//
//  ZMTranscodeDef.h
//  ZoomUnit
//
//  Created by Devl on 12/27/23.
//

#ifndef ZMTranscodeDef_h
#define ZMTranscodeDef_h

#define kZMTranscodePortName            @"us.zoom.transcode"
#define kZMTranscodeFileName            @"kZMTranscodeFileName"
#define kZMTranscodeStatusUpdate        @"kZMTranscodeStatusUpdate"
#define kZMTranscodeProgressUpdate      @"kZMTranscodeProgressUpdate"

typedef NS_ENUM(NSUInteger, ZMTranscodeStatusType) {
    ZMTranscodeStatusStopped,
    ZMTranscodeStatusInProgress,
    ZMTranscodeStatusSuccess,
    ZMTranscodeStatusFailed,
};

#endif /* ZMTranscodeDef_h */
