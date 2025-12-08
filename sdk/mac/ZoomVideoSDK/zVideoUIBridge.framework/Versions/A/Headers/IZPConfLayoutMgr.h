//
//  IZPConfLayoutMgr.h
//  VideoUIBridge
//
//  Created by martin.yu on 12/16/22.
//

#ifndef IZPConfLayoutMgr_h
#define IZPConfLayoutMgr_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZPConfLayoutMgr <ZMRoutableObject>
- (CGFloat)getToolBarViewHeight;
- (CGFloat)getTitleBarViewHeight;
@end

NS_ASSUME_NONNULL_END

#endif /* IZPConfLayoutMgr_h */
