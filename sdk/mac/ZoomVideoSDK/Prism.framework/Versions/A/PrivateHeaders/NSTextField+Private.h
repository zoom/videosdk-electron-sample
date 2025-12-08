//
//  NSTextField+Private.h
//  Prism
//
//  Created by Francis Zhuo on 2025/7/14.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSTextField (Private)
- (BOOL)textView:(NSTextView *)textView shouldChangeTextInRange:(NSRange)affectedCharRange replacementString:(NSString *)replacementString;
- (BOOL)textView:(NSTextView *)textView doCommandBySelector:(SEL)commandSelector;
@end

NS_ASSUME_NONNULL_END
