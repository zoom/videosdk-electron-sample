//
//  ZMMTOnlineBusinessProtocol.h
//  VideoUIBridge
//
//  Created by Devl on 3/25/25.
//

#ifndef ZMMTOnlineBusinessProtocol_h
#define ZMMTOnlineBusinessProtocol_h

#import <zVideoUIBridge/ZMUIConstants.h>

@protocol ZMMTOnlineBusinessProtocol <NSObject>

@optional
- (void)onUpgradeEntranceUpdated;
- (void)onUpgradeEntranceClosed:(ZMMTUpgradeEntrance)entrance;

- (void)showPlistBannerIfNeeded;
#ifdef __cplusplus
- (void)hidePlistBannerWithType:(ZUUI::OnlineBusinessBannerType)type;
#endif

@end

#endif /* ZMMTOnlineBusinessProtocol_h */
