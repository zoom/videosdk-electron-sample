//
//  ZMPlainBlock.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMPlainBlock_h
#define ZMPlainBlock_h

typedef void(^ZMPlainBlock)(void);
APPKIT_EXTERN void CALayerNoActionChanging(NS_NOESCAPE _Nonnull ZMPlainBlock block);//!< disable the CALayer's implicit animation

//MARK: - Common
typedef void(^ZMViewVisibility)(NS_NOESCAPE _Nullable ZMPlainBlock block);

#endif /* ZMPlainBlock_h */
