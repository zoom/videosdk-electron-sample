//
//  ZMPopupSelectViewController.h
//  ZCommonUI
//
//  Created by groot.ding on 1/10/20.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <ZoomUnit/ZMPopupAlertViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPopupSelectViewController : ZMPopupAlertViewController

@property (nonatomic,strong,nullable) NSArray <NSString *> * items;

@property (nonatomic,copy) void(^selectBlock)(ZMPopupAlertIndex index,NSString * _Nullable selectItem);

@end

NS_ASSUME_NONNULL_END
