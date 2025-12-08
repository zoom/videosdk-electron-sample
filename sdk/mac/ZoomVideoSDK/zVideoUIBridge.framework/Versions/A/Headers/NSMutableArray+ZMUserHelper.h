//
//  NSMutableArray+ZMUserHelper.h
//  zVideoUI
//
//  Created by francis zhuo on 6/10/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMUser;
NS_ASSUME_NONNULL_BEGIN
ZMUserID RealUserID(ZMUserID userID);

@interface NSNumber (ZMUserHelper)
- (ZMUserID)userID;
@end

@interface NSArray (ZMUserHelper)
- (BOOL)containUserID:(ZMUserID)userID;
- (NSUInteger)indexOfUserID:(ZMUserID)userID;
- (BOOL)containUserID:(ZMUserID)userID outUser:(NSNumber*_Nullable*_Nullable)outUser;

- (BOOL)containUser:(ZMUser*)user;
- (NSUInteger)indexOfUser:(ZMUser*)user;
@end

@interface NSMutableArray (ZMUserHelper)
- (BOOL)addUserID:(ZMUserID)userID;
- (BOOL)insertUserID:(ZMUserID)userID atIndex:(NSUInteger)index;
- (BOOL)removeUserID:(ZMUserID)userID;

- (BOOL)addUser:(ZMUser*)user;
- (BOOL)insertUser:(ZMUser*)user atIndex:(NSUInteger)index;
- (BOOL)removeUser:(ZMUser*)user;
@end

@interface ZMMutableArray (ZMUserHelper)
- (BOOL)containUserID:(ZMUserID)userID;
@end

@interface ZMOrderedSet (ZMUserHelper)
- (BOOL)addUserID:(ZMUserID)userID;
- (BOOL)removeUserID:(ZMUserID)userID;
@end


NS_ASSUME_NONNULL_END
