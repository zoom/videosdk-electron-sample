//
//  IZMMTWallViewMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2022/11/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTWallViewMgr <ZMRoutableObject>
@property (nonatomic, readonly) BOOL isDragging;
@property (nonatomic, readonly) NSArray<ZMUser*> *usersForSave;
@end

NS_ASSUME_NONNULL_END
