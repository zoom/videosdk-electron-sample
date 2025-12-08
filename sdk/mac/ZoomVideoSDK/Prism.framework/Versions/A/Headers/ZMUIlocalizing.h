//
//  ZMUIlocalizing.h
//  ZoomKit
//
//  Created by Cooper.Chen on 2025/7/2.
//

#ifndef ZMUIlocalizing_h
#define ZMUIlocalizing_h

//MARK: - Utils
@protocol ZMUIlocalizing <NSObject>

- (void)localizingUI;//!< localize itself, subclass should override this method if necessary
- (void)localizingUIRecursively;//!< localize all view hierarchy recursively
@property (assign) BOOL localizingIgnore;

@end

#endif /* ZMUIlocalizing_h */
