//
//  NSString+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMBase.h>
#import <Prism/ZMHtmlNodeColor.h>
#import <Prism/ZMUtil.h>

NS_ASSUME_NONNULL_BEGIN

#if defined(__cplusplus)
extern "C" {
#endif

BOOL IsEmptyString(NSString *str);

#if defined(__cplusplus)
}
#endif

APPKIT_EXTERN NSString * ZMAutoIdentifier(void);//!< a random string
APPKIT_EXTERN NSString * const kNSEmptyString;//!< aka @""
APPKIT_EXTERN NSString * NSNonnullString( NSString * _Nullable aString);//!< no null string
APPKIT_EXTERN NSString * NSNullPlaceholderString(NSString * _Nullable aString, NSString * placeHolder);

APPKIT_EXTERN NSString * const ZMFileInfoLocalPathKey;
APPKIT_EXTERN NSString * const ZMFileInfoFileNameKey;

@interface NSString (ZoomKit)

- (BOOL)zm_containsString:(NSString *)str;
- (BOOL)hasPrefixCaseInsensitive:(NSString*)str;

- (BOOL)zm_openURL;

@property (readonly) NSString *localizedString;
@property (readonly) NSString *unlocalized;//for analyze test
@property (readonly) NSImage *resourceImage;
@property (readonly) NSImage *resourceSvgImage;

//auto means auto flipp X if app is RTL
@property (readonly) NSImage *autoImage;
@property (readonly) NSImage *autoSvgImage;

@property (readonly) NSImage * _Nullable locatedImage;

@property (readonly) NSString *stringByTrimmedWhitespaceAndNewline;
@property (readonly) NSString *stringByReplaceNewlineWithSpace;

+ (NSString *)formattedStringWithSize:(long long)size;
@property (readonly) NSString *formattedMeetingNumber;

@property (readonly) NSInteger zm_hexInteger;
@property (readonly) NSString *shortName;
//Path
@property (nonatomic, readonly) BOOL pathExist;
@property (nonatomic, readonly) BOOL pathIsDirectory;
- (BOOL)pathRemove;
- (nullable NSString *)zmImageSavedPathByAppendingSelf;
- (NSString*)stringByReplaceNewlineAndParagraphWithString:(NSString*)string;
- (BOOL)isURLEncoded;
- (NSString *) MD5;

- (nullable NSDictionary *)getURLParams;
- (NSAttributedString*)attributedString:(NSDictionary*)attributed;
- (BOOL)zm_isEqualToString:(NSString *)string;

- (NSString *)trans2HtmlSnippetALabelWithLink:(NSString *)link;
- (NSString *)trans2HtmlSnippetBLabel;
- (NSString *)trans2HtmlSnippetFontLabel:(NSInteger)fontSize;
- (NSString *)trans2HtmlSnippetFontLabel:(NSInteger)fontSize textColor:(ZMHtmlNodeColor)textColor;

- (NSAttributedString *)parseHTMLSnippet;
- (NSAttributedString *)parseHTMLSnippetWithAttachments:(NSDictionary * _Nullable)attachments;
- (NSString *)htmlEncode;

- (NSString *)trimWhitespaceAndNewline;

- (NSString *)firstComponent;

- (NSString *)stringByUrlEncoding;

- (nullable NSURL *)matchUrl;

- (NSString *)formatMeetingNumber;

- (BOOL)isEqualToStringIgnoreCase:(NSString *)aString;

+ (NSString *) formatByEllipsis:(NSString*)aString;
+ (NSString *) formatByEllipsis:(NSString*)aString withLength:(int)strLen;

- (BOOL)isEmptyOrSpacesOnly;

- (nullable NSArray <NSValue *> *)transUTF8RangesToNSStringRanges:(NSArray <NSValue *> *_Nullable)ranges;

- (NSString *)replaceChineseColonToEnglish;

- (BOOL)containsTWFlagEmoji;
- (NSString *)replaceTWFlagEmoji;

- (nullable NSImage *)asImageWithAttributes:(NSDictionary<NSAttributedStringKey, id> *_Nullable)attributes;

- (NSInteger)countOfCharacters:(NSCharacterSet*)characters inRange:(NSRange)range;

@property (nonatomic, readonly) BOOL isValidEmailHittingWeb;
@property (nonatomic, readonly) BOOL isValidEmail;
//ZOOM-184780 secutity

@property (nonatomic, assign, readonly) NSInteger numberOfLines;
- (NSString*)substringWithMaxUTF8Size:(NSInteger)maxUTF8ByteSize;
- (NSString *)zm_base64UrlToBase64;
- (NSString *)zm_base64ToBase64Url;
@end

@interface NSString (ZMHotkey)
- (NSString*)HKStateId;
- (NSString*)HKComboId;
- (NSString*)gHKStateId;
- (NSString*)gHKComboId;
@end

@interface NSString (File)
+ (nullable NSImage *)iconImageWithFileName:(NSString *)fileName filePath:(nullable NSString *)filePath;
+ (NSDictionary *)preparedFileInfoAtDownloadDirectoryWithName:(NSString *)aFileName;
/// This method will give user a chance to choice a download dir when default download dir be deleted or permission denied
+ (void)preparedFileInfoAtDownloadDirectoryWithName:(NSString *)fileName completion:(void (^)(NSDictionary * fileInfo, BOOL isCustomFilePath))completion;

/// Returns a new string made by appending to the receiver a suitable sequential number.
///
/// Use this method to create a path string that is eligible checked by the given block.
/// A general use case is choosing the path for saving files without overwritting the
/// exisiting files. The predicate block will be called multiple times until the method
/// finds an eligible path. If the receiver is currently eligible, it will be returned
/// unmodified.
///
/// Note that if there is already an sequential number, the method will updated it instead
/// of appending a new one.
///
/// - Parameter block: A predicate block to check whether the given path is eligible.
- (NSString *)stringByAppendingFileSequentialNumberIfNecessaryUsingPredicateBlock:(BOOL (^)(NSString *proposalString))block;
@end

@interface NSMutableString (ZoomKit)
- (void)mutableReplaceTWFlagEmoji;
- (void)replaceNewlineAndParagraphWithString:(NSString *)string;
@end

@interface ZMHTMLStringAdjustment : NSObject
@property (nonatomic, strong, nullable) NSColor *textColor;
@property (nonatomic, assign) CGFloat paragraphSpacing;
@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, assign) BOOL shouldRemoveLastNewlineCharacter;

/// textColor = NSColor.zmPriTextColor
/// paragraphSpacing = 0
/// fontSize = 12
/// shouldRemoveLastNewlineCharacter = NO
+ (instancetype)defaultAdjustment;
@end

@interface NSString (ZMHTMLStringSupport)
/// converting HTML to NSAttributedString "pseudo-asynchronously"
- (void)loadHTMLWithAdjustment:(ZMHTMLStringAdjustment *)adjustment completionBlock:(void (^)(NSMutableAttributedString *htmlAttributedString))completionBlock;

- (nullable NSMutableAttributedString *)loadHTMLWithAdjustment:(ZMHTMLStringAdjustment *)adjustment;
@end

NS_ASSUME_NONNULL_END
