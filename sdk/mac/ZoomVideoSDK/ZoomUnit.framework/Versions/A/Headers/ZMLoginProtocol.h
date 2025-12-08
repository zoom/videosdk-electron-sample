//
//  ZMLoginProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 7/27/23.
//

#ifndef ZMLoginProtocol_h
#define ZMLoginProtocol_h


@protocol ZMLoginProtocol <NSObject>
@optional
- (void)willLogin;//TODO: replaced with priority router center
- (void)didLogin;
- (void)willLogout;
- (void)didLogout;
- (void)loginWindowWillClose;
- (void)webLoginNotification:(NSInteger)result;
@end

#endif /* ZMLoginProtocol_h */
