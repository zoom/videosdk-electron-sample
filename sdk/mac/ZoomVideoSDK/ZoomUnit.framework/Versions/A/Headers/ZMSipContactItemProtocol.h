//
//  ZMSipContactItemProtocol.h
//  zChatComponent
//
//  Created by groot.ding on 8/4/23.
//

#ifndef ZMSipContactItemProtocol_h
#define ZMSipContactItemProtocol_h

#import <Foundation/Foundation.h>

//@property (nonatomic,assign)NSInteger contactType;
//@property (nonatomic,copy)NSString* sipContactID;
//@property (nonatomic,copy)NSString* firstName;
//@property (nonatomic,copy)NSString* lastName;
//@property (nonatomic,copy)NSString* emailAddress;
//@property (nonatomic,copy)NSString* userName;
//@property (nonatomic,copy)NSString* folderID;
//@property (nonatomic,copy)NSString* folderName;
//@property (nonatomic,copy)NSString* jID;
//@property (nonatomic,retain) NSMutableArray *phoneArray;
//@property (nonatomic,retain) NSMutableArray *customPhoneTypeArray;
//
////uesed for "Connect a Contact" button
//@property(nonatomic,copy)NSString *title;
//@property(nonatomic,assign)SEL     action;
//@property(nonatomic,weak)id     target;
//@property(nonatomic,assign)BOOL   isHover;
@class ZMBuddyAdapter;
@protocol ZMSipContactItem <NSObject>

- (NSInteger)contactType;
- (NSString *)sipContactID;
- (NSString *)firstName;
- (NSString *)lastName;
- (NSString *)emailAddress;
- (NSString *)userName;
- (NSString *)folderID;
- (NSString *)folderName;
- (NSString *)jID;
- (NSMutableArray *)phoneArray;
- (NSMutableArray *)customPhoneTypeArray;

- (ZMBuddyAdapter *)createBuddyAdapter:(NSString*)phoneNumber;
@end

#endif /* ZMSipContactItemProtocol_h */
