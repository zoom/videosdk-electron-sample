//
//  IZMMTVcardMgr.h
//  VideoUIBridge
//
//  Created by davies zhao on 10/24/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMWKWebUserProfileViewController;
@class ZMBubbleObject;

@protocol IZMMTVcardMgr <ZMRoutableObject>
- (void)showVCard:(ZMUser*)user;
- (void)closeVCard;
- (BOOL)enableShowVcard:(ZMUser*)user;
- (BOOL)enableShowVCardByJid:(NSString*)jid;
- (BOOL)isUserLeft:(ZMUser *)user;

@property (nonatomic, strong) ZMWKWebUserProfileViewController *webProfileVC;
@property (nonatomic, strong) ZMBubbleObject *previousShowedBubble;

@end

NS_ASSUME_NONNULL_END
