//
//  ZMTextView.h
//  ZCommonUI
//
//  Created by groot.ding on 2019/2/28.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMBaseTextAttachmentCell.h>

@class ZMTextView;

@protocol ZMTextViewDelegate <NSTextViewDelegate>

@optional
- (BOOL)checkMenuItem:(NSMenuItem *)menuItem textView:(ZMTextView *)textView;
- (void)fullKeyboardControlTabClicked:(id)sender;
- (void)textView:(ZMTextView *)textView onClickAtAttachmentCell:(id<NSTextAttachmentCell>)cell charIndex:(NSInteger)charIndex point:(NSPoint)point;
- (void)textView:(ZMTextView *)textView onClickLink:(id)link;

- (void)textView:(ZMTextView *)textView clickAttributes:(NSDictionary *)attributes charIndex:(NSInteger)charIndex;

@end

@interface ZMTextView : NSTextView <ZMBaseTextProtocol>

@property (nonatomic, copy) NSString *zmPlaceholderString;
@property (nonatomic, copy) NSAttributedString *zmPlaceholderAttributedString;
@property (nonatomic, copy) void (^updateFirstResponse)(BOOL firstResponse);
@property (nonatomic, assign) BOOL pasteFilesOverLimit;
@property (nonatomic, assign) BOOL placeholderVerTopAlignment;
@property (nonatomic, assign) BOOL needDrawFocusRing;
@property (nonatomic, assign) BOOL needDrawFocusRingAttribute;

@property (nonatomic, assign) BOOL automaticFocusFirstAttribute;

@property (nonatomic,assign) BOOL acceptMouseDown;
@property (nonatomic,assign) BOOL forwardUpDownKeyEvent;
@property (nonatomic,assign) BOOL isFixedFontSizeRate;
@property (nonatomic, readonly, assign) BOOL hasParagraphIndent;
@property (nonatomic, strong, readonly) NSUndoManager *zmUndoManager;

@property (copy) NSString *zm_accessibilityAdjustLabel;

- (void)addString:(NSString*)newString;

- (void)appendNewLine;

- (BOOL)changeTextInRange:(NSRange)range withString:(NSString*)string;
- (BOOL)changeTextInRange:(NSRange)range withAttributeString:(NSAttributedString*)attString;

- (void)focusRingSelectAttributeInRange:(NSRange)range;

- (NSArray <NSValue * >*)getKeyBoardNeedFocusRingRanges;

- (NSPoint)mouseLocationInTextContiner;

- (NSInteger)curAppFontSizeRate;

- (void)cleanUndoStack;

- (void)addAttachmentCell:(ZMBaseTextAttachmentCell *)attachmentCell withFrame:(CGRect)frame;

- (void)setNeedsUpdateAccessbilityElements;

- (void)selectedGiyphRangeChanged:(NSRange)selectedGiphyRange;

@end
