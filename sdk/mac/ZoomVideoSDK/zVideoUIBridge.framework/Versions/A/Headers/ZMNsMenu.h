//
//  ZMNsMenu.h
//  zVideoUI
//
//  Created by francis zhuo on 6/16/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMenu(ZmmtKit)
@property(nullable, retain) id representedObject;
@end

@interface ZMNsMenu : NSMenu
- (void)addItem:(nullable NSMenuItem *)newItem;
- (void)addSeparatorItem;
@end

NS_ASSUME_NONNULL_END
