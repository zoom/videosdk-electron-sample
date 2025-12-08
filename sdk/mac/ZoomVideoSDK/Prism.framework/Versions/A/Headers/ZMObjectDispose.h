//
//  ZMObjectDispose.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMObjectDispose_h
#define ZMObjectDispose_h

@protocol ZMObjectDispose <NSObject>

@required;
- (void)cleanUp;

@end

#endif /* ZMObjectDispose_h */
