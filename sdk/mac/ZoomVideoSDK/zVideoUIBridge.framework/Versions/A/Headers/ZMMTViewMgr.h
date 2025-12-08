//
//  ZMMTViewMgr.h
//  SaasBeeConfUIModule
//
//  Created by Francis Zhuo on 8/11/21.
//  Copyright © 2021 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTViewMgr<__covariant ViewController : ZMMTBaseViewController*> : NSObject
@property(retain) NSMutableDictionary* viewControllerDictionary;
- (void)cleanUp NS_REQUIRES_SUPER;

- (nullable ViewController)newViewControllerWithType:(ZMMTType)type;//need override
- (ViewController)getViewControllerWithType:(ZMMTType)type;
@end

NS_ASSUME_NONNULL_END
