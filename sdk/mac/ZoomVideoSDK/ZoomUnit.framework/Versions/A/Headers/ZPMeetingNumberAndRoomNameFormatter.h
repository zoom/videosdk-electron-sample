//
//  ZPMeetingNumberAndRoomNameFormatter.h
//  ZCommonUI
//
//  Created by ryan on 2016/3/3.
//  Copyright © 2016 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZPMeetingNumberAndRoomNameFormatterDelegate <NSObject>
@property (nonatomic, readonly) BOOL isSupportMinimumOneCharesVanityName;
@end

@interface ZPMeetingNumberAndRoomNameFormatter : NSFormatter
@property (nonatomic, weak) id<ZPMeetingNumberAndRoomNameFormatterDelegate> delegate;

@end
