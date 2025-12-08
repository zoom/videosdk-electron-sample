//
//  ZMAssignedGroupResult.h
//  ZoomUnit
//
//  Created by zhengrong xiao on 2021/11/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMAssignedGroupParam : NSObject

@property (nonatomic,copy,nullable) NSString *groupID;
@property (nonatomic,copy,nullable) NSString *localVersion;
@property (nonatomic,copy,nullable) NSString *targetVersion;
@property (nonatomic,assign) NSInteger cursor;
@property (nonatomic,assign) NSInteger limit;

@end



@interface ZMAssignedGroupResult : NSObject

@property (nonatomic,retain,nullable) ZMAssignedGroupParam *groupParam;
@property (nonatomic,retain,nullable) NSArray<NSString *> *items;
@property (nonatomic,assign) NSInteger result; //0 is success
@property (nonatomic,assign) BOOL hasNextPage;
@property (nonatomic,copy,nullable) NSString *reqID;

@end



@interface ZMZBuddyGroup : NSObject

@property (nonatomic,copy,nullable) NSString *groupID;
@property (nonatomic,copy,nullable) NSString *groupName;
@property (nonatomic,assign) NSInteger groupType;  //BuddyGroupType

@end


@interface ZMAssignedGroupSearchResult : NSObject

@property (nonatomic,retain,nullable) ZMZBuddyGroup *group;
@property (nonatomic,retain,nullable) NSArray *jids;

@end

NS_ASSUME_NONNULL_END
