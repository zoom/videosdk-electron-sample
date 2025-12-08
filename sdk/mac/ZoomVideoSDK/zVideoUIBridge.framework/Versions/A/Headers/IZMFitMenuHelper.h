//
//  IZMFitMenuHelper.h
//  VideoUIBridge
//
//  Created by Molay.Yu on 2024/2/27.
//

#import <Foundation/Foundation.h>

@class ZMMenu, ZMMTBaseViewController;
@protocol IZMMTDocViewController;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMFitDocMenuHelper <ZMRoutableObject>

@property (nonatomic, weak) ZMMTBaseViewController<IZMMTDocViewController> *docViewController;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithViewController:(ZMMTBaseViewController<IZMMTDocViewController> *)controller;

- (BOOL)canShowMenu;
- (ZMMenu *)getMoreMenu;

@end

NS_ASSUME_NONNULL_END
