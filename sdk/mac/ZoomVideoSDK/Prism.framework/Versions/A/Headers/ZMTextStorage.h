//
//  ZMTextStorage.h
//  ZCommonUI
//
//  Created by groot.ding on 2/5/20.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZMTextStotageDelegateProtocol<NSTextStorageDelegate>
@optional
- (void)textStorageDidChange:(id)sender;
@end
@interface ZMTextStorage : NSTextStorage
@property (weak) id<ZMTextStotageDelegateProtocol> delegate;
@end

NS_ASSUME_NONNULL_END
