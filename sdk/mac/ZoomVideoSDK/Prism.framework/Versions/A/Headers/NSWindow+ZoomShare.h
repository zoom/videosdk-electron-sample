//
//  NSWindow+InvisibleInShare.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/11/23.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
typedef NS_ENUM(NSInteger, ZMWindowShareType){
    ZMWindowShareTypeShareable4ZoomShare        = 0,
    ZMWindowShareTypeUnshareable4ZoomShare      = 1,
    ZMWindowShareTypeShareableAlways            = 2,
};

@interface NSWindow (ZoomShare)
@property(nonatomic,assign) ZMWindowShareType zmShareType;
@property(nonatomic,assign) BOOL zmShareTypeFollowParentWindow;//default is YES
@property(nonatomic,assign) BOOL zmPreventScreenCaptureWindow;//default is NO

- (BOOL)configWindowCaptureExcludeShape;
- (void)clearWindowCaptureExcludeShape;

@end
