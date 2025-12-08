//
//  ZMDistance.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMDistance_h
#define ZMDistance_h

typedef struct _ZMDistance {
    CGFloat x;
    CGFloat y;
} ZMDistance;

APPKIT_EXTERN ZMDistance ZMMakeDistance(CGFloat x, CGFloat y);
APPKIT_EXTERN ZMDistance ZMMakeEvenDistance(CGFloat distance);
APPKIT_EXTERN const ZMDistance ZMZeroDistance;

#endif /* ZMDistance_h */
