//
//  IZMAuxUIMgr.h
//  VideoUIBridge
//
//  Created by Peter Xu on 2024/4/5.
//

#ifndef IZMAuxUIMgr_h
#define IZMAuxUIMgr_h
@protocol IZMAuxUIMgr <ZMRoutableObject>
- (void)enterFullScreen;
- (void)exitFullScreen;
- (BOOL)isFullScreen;

- (void)showAuxFitbar;
- (void)hideAuxFitbar;
@end
#endif /* IZMAuxUIMgr_h */
