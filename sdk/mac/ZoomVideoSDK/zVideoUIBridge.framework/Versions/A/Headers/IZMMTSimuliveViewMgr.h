//
//  IZMMTSimuliveViewMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2023/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTSimuliveViewController;
@protocol IZMMTSimuliveViewMgr <ZMRoutableObject>
- (ZMMTSimuliveViewController*)newViewControllerWithType:(ZMMTType)type;

@end

@protocol IZMMTSimuliveStatusSinkProtocol <NSObject>
@optional
- (void)onSimuliveWebinarAutoReplyStatusChanged:(BOOL)autoReply replyText:(NSString *)replyText;
- (void)onSimuliveMasterVideoPlayerChanged:(uint32_t)originalUJID nowUJID:(uint32_t)nowUJID;
- (void)onSimuliveStartFailed;
@end

NS_ASSUME_NONNULL_END
