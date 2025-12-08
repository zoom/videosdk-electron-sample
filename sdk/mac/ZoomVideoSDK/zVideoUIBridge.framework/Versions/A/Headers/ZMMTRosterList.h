//
//  ZMMTRosterList.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 11/2/22.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTRosterList : NSObject

@property(null_resettable,nonatomic,retain) NSMutableArray<ZMUser*>* joinedArray;
@property(null_resettable,nonatomic,retain) NSMutableArray<ZMUser*>* updateArray;
@property(null_resettable,nonatomic,retain) NSMutableArray<ZMUser*>* leftArray;
@property(nonatomic, assign) BOOL isAttendeeRoster;
@end

NS_ASSUME_NONNULL_END
