//
//  ZMChatButton.h
//  SaasBeePTUIModule
//
//  Created by John on 5/23/14.
//  Copyright (c) 2014 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomKit/ZoomKit.h>
#import <ZoomUnit/ZMFileConstants.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

enum
{
    ZMChatFileError_InvalidFile     = 20,
    ZMChatFileError_FileTooBig      = 21,
    ZMChatFileError_NoDiskSpace     = 22,
    ZMChatFileError_DiskIOError     = 23,
    ZMChatFileError_URLTimeOut      = 24,
    ZMChatFileError_Disconnected    = 25,
    ZMChatFileError_FileNotFound    = 100
};
typedef NSUInteger ZMChatFileErrorInfo;

enum
{
    ZMChatButton_Style_RoundedCorner = 0,
    ZMChatButton_Style_SquareCorner,
};
typedef NSUInteger ZMChatButtonStyle;

enum
{
    ZMPTAppIntegrationType_GitHub = 0,
    ZMPTAppIntegrationType_GitLab,
    ZMPTAppIntegrationType_Jira,
    ZMPTAppIntegrationType_other,
};
typedef NSUInteger ZMPTAppIntegrationType;

@interface ZMChatButton : NSButton
{
    BOOL                _shouldShowTriangle;
    BOOL                _hasBorder;
    BOOL                _entered;
    BOOL                _smallCorner;
    BOOL                _notTracing;
    NSTrackingArea*     _area;
}

@property(nonatomic, assign) BOOL shouldShowTriangle;
@property(nonatomic, assign) BOOL hasBorder;
@property(nonatomic, assign) BOOL entered;
@property(nonatomic, assign) BOOL smallCorner;
@property(nonatomic, assign) BOOL notTracing;

@end

@interface ZMAnotherChatButton : NSButton
{
    BOOL                _isSquare;
}

@property (nonatomic, readwrite, assign) BOOL isSquare;

@end

@interface ZMPTCheckEnterView : NSButton
{
    NSImage*            _hoverImage;
    BOOL                _entered;
    NSTrackingArea*     _area;
}

@property (nonatomic, readwrite, retain) NSImage* hoverImage;

@end

@interface ZMIMImageButton : PZMRichKeyButton
{
    BOOL                            _entered;
    NSTrackingArea*                 _area;
    NSImage*                        _hoverImage;
    BOOL                            _hasBack;
    BOOL                            _shouldShowTitle;
    NSColor*                        _hoverTitleColor;
    NSColor*                        _defaultTitleColor;
}

@property(nonatomic, readwrite, retain) NSImage* hoverImage;
@property (nonatomic, readwrite, assign) BOOL hasBack;
@property (nonatomic, readwrite, assign) BOOL entered;
@property (nonatomic, readwrite, assign) BOOL shouldShowTitle;
@property (nonatomic, readwrite, copy) NSColor* hoverTitleColor;
@property (nonatomic, readwrite, copy) NSColor* defaultTitleColor;

@end


@interface ZMPTCenterImageAttachmentCell : NSTextAttachmentCell
{
    float       _fontSize;
}

@property (assign) float fontSize;

@end
//ZOOM-72640 RTT {
@interface ZMPTLeftImageTitleAttachmentCell : NSTextAttachmentCell
{
}

@end
//ZOOM-72640 RTT }
//@interface ZMPTBaseTextAttachmentCell : NSTextAttachmentCell
//
//@property (assign) BOOL shouldUpdateWhenExit;
//@property (assign) BOOL isAnimating;
//@property (assign) NSRect cellFrame;
//@property (assign) BOOL isSelected;
//@property (nonatomic,readonly) BOOL needFocusRing;
//
//- (BOOL)shouldDoSomeAtPoint:(NSPoint)point hasUIChange:(BOOL*)hasChange;
//- (void)mouseExisted;
//- (void)onMouseClickOnPoint:(NSPoint)point andControlView:(NSTextView*)controlView;
//@end

@interface ZMPTMissCallCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _message;
    NSString*                   _url;
    NSDate*                     _time;
    BOOL                        _isDeclined;
    BOOL                        _isHistory;
}

@property(nonatomic, readwrite, copy) NSString* message;
@property(nonatomic, readwrite, assign) BOOL isDeclined;
@property(nonatomic, readwrite, assign) BOOL isHistory;
@property(nonatomic, readwrite, retain) NSDate* time;
@property(copy) NSString* url;

@end

@interface ZMPTURLPreviewCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _jid;
    NSArray*                    _previewInfos;
    BOOL                        _isWideModel;
}
/*!
 @abstract True if this cell should render corners/edges to match an adjacent view above.
 */
@property (nonatomic, assign) BOOL hasElementAbove;
/*!
 @abstract True if this cell should render corners/edges to match an adjacent view below.
 */
@property (nonatomic, assign) BOOL hasElementBelow;
/*! @abstract Spacing between each drawn previewInfo */
@property (nonatomic, assign) CGFloat spacing;
/*! Whether the cell uses the new corner masking UI from ZOOM-354983 */
@property (nonatomic, assign) BOOL imageFileSharingImprovement;
@property(retain) NSString* jid;
@property(nonatomic, retain) NSArray* previewInfos;

- (void)imageDownloadForURL:(NSString*)url isFavicon:(BOOL)isFavicon;

@end

@protocol ZMPTURLPreviewCellResponder

@optional
- (void)URLPreviewCell:(ZMPTURLPreviewCell *)cell openURL:(NSURL *)URL;

@end

@interface ZMPTAppIntegrationCell : ZMPTBaseTextAttachmentCell
{
    ZMPTAppIntegrationType      _appType;
    NSString*                   _imageURL;
    NSArray*                    _bodyURLsInfo;
    NSTextStorage*              _textStorage;
    NSRange                     _glyphRange;
    NSSize                      _size;
    NSMutableArray*             _titleURLArray;
    NSTextStorage*              _titleAttString;
    NSArray*                    _actionArray;
    NSString*                   _jid;
}

@property (copy) NSString* imageURL;
@property (copy) NSString* jid;
@property (retain) NSArray* bodyURLsInfo;
@property (retain) NSArray* actionArray;
@property (nonatomic, retain, setter=setTitleArray:) NSArray* titleURLArray;
@property (assign) ZMPTAppIntegrationType appType;

- (void)setBody:(NSAttributedString *)body;
- (NSString*)titleURL;
- (BOOL)hasActionButton;
- (float)stringHeightForFixedWidth:(float)width;

@end

@interface ZMPTIMVoiceCell : ZMPTBaseTextAttachmentCell
{
    NSImage*                    _playImage;
    NSImage*                    _backImage;
    NSImage*                    _stopImage;
    NSInteger                   _length;
    NSString*                   _path;
    BOOL                        _isDownloaded;
    NSString*                   _messageID;
    NSArray*                    _animationImages;
    NSInteger                   _counter;
    BOOL                        _isMe;
    BOOL                        _isHistory;
}
@property(nonatomic, readwrite, assign) NSInteger length;
@property(nonatomic, readwrite, assign) NSInteger counter;
@property(nonatomic, readwrite, retain) NSString* path;
@property(nonatomic, readwrite, assign) BOOL isDownloaded;
@property(nonatomic, readwrite, assign) BOOL isMe;
@property(nonatomic, readwrite, retain) NSString* messageID;
@property(nonatomic, readwrite, assign) BOOL isHistory;

@end

@interface ZMPTEmojiCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _name;
    NSString*                   _emojiCode;
    NSUInteger                  _index;
    BOOL                        _addByPanel;
    BOOL                        _isBigSize;
    BOOL                        _isSmallSize;
}

@property(nonatomic, readwrite, copy) NSString* name;
@property(nonatomic, readwrite, copy) NSString* emojiCode;
@property(nonatomic, readwrite, setter=setIndex:, assign) NSUInteger index;
@property(nonatomic, readwrite, assign) BOOL addByPanel;
@property(nonatomic, readwrite, assign) BOOL isBigSize;
@property(nonatomic, readwrite, assign) BOOL isSmallSize;
@end

@interface ZMPTCodeSnippetHeadCell : ZMPTBaseTextAttachmentCell

@property(retain) NSString* fileName;
@property(retain) NSString* languageName;
@property(assign) BOOL  isCollapsed;
@property(retain) NSMutableAttributedString* titleInfo;

@end

@interface ZMPTCodeSnippetCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _fileName;
    NSString*                   _languageName;
    NSString*                   _filePath;
    NSString*                   _codeFilePath;
    NSString*                   _messageID;
    NSTextStorage*              _content;
    NSTextStorage*              _downloadText;
    NSRange                     _glyphRange;
    NSInteger                   _linesNumber;
    BOOL                        _needShowDownloadUI;
    NSMutableAttributedString*  _titleInfo;
    NSRect                      _collapseRect;
    NSRange                     _viewMoreRange;
    NSRange                     _downloadGlyphRange;
    NSRange                     _downloadActionRange;
    float                       _titleLenght;
    float                       _downloadTextHeight;
    float                       _cellHeight;
}
@property(assign) BOOL  isCollapsed;
@property(retain) NSString* fileName;
@property(retain) NSString* filePath;
@property(retain) NSString* languageName;
@property(copy)   NSString* codeFilePath;
@property(assign) NSInteger linesNumber;
@property(assign) BOOL needShowDownloadUI;
@property(nonatomic, readwrite, retain) NSString* messageID;
@property(nonatomic, readonly, retain) NSTextStorage *content;

- (void)initContent:(NSMutableAttributedString*)content;
- (BOOL)isPointOnViewMore:(NSPoint)point;
- (BOOL)isPointOnTitle:(NSPoint)point;
- (BOOL)isPointOnDownload:(NSPoint)point;
- (float)stringHeightForFixedWidth:(float)width;
- (float)downloadStringHeightForFixedWidth:(float)width;

@end


@interface ZMPTFileCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _filePath;
    NSString*                   _messageID;
    NSImage*                    _image;
    NSString*                   _fileSize;
    ZMChatSendFileStatus        _status;
    NSString*                   _fileName;
    NSRect                      _cancelDownloadActionRect;
    NSRect                      _retryActionRect;
    NSRect                      _cancelSendActionRect;
    unsigned long long          _realSize;
    unsigned long long          _receivedSize;
    NSUInteger                  _speed;
    NSUInteger                  _ratio;
    ZMChatFileErrorInfo         _fileErrorID;
    BOOL                        _isHistory;
    BOOL                        _isMySend;
    BOOL                        _isEnableShare;
    BOOL                        _isHovered;
}

@property(retain) NSString* filePath;
@property(retain) NSString* fileName;
@property(retain) NSString* messageID;
@property(retain) NSString* sessionID;
@property(retain) NSString* fileSize;
@property(retain) NSString* fileSizeString;
@property(assign) ZMChatSendFileStatus status;
@property(assign) NSRect cancelDownloadActionRect;
@property(assign) NSRect retryActionRect;
@property(assign) NSRect cancelSendActionRect;
@property(assign) NSRect fileNameRect;
@property(assign) NSRect fileDetailInfoRect;
@property(assign) unsigned long long realSize;
@property(assign) unsigned long long receivedSize;
@property(assign) NSUInteger speed;
@property(assign) NSUInteger ratio;
@property(assign) BOOL isHistory;
@property(assign) BOOL isMySend;
@property(assign) BOOL isEnableShare;
@property(nonatomic, assign, getter = isHovered) BOOL hovered;
@property(nonatomic, assign, getter = isSupportHoverStatus) BOOL supportHoverStatus;
@property(assign) ZMChatFileErrorInfo fileErrorID;
@property(assign) NSUInteger animatedCounter;
@property(assign) NSInteger fileShareType;
@property(assign) BOOL isFileTransferResumeEnabled; //ZOOM-70706

- (NSString *)formattedSizeString;

@end

@interface ZMPTVisableToYouCell : ZMPTBaseTextAttachmentCell

@end

@interface ZMPTAppIconCell : ZMPTBaseTextAttachmentCell

@property (nonatomic, copy) NSString *labelString;

@end

typedef NS_ENUM(NSInteger, ZMPTLabelIconCellStateType)
{
    ZMPTLabelIconCellStateType_Normal,
    ZMPTLabelIconCellStateType_Hover,
    ZMPTLabelIconCellStateType_Selected,
    ZMPTLabelIconCellStateType_NoAlpha,
    ZMPTLabelIconCellStateType_Normal_Dark,
    ZMPTLabelIconCellStateType_Hover_Dark,
    ZMPTLabelIconCellStateType_Normal_Default,
    ZMPTLabelIconCellStateType_Hover_Default,
};

/// @note Set cell.font to ensure that the cell is correctly centered
@interface ZMPTLabelIconCell : ZMPTBaseTextAttachmentCell

@property (nonatomic, copy) NSString* string;
@property (assign) ZMPTLabelIconCellStateType stateType;
@property (assign) BOOL scaleEnable;
@property (assign) BOOL forceDarkModeStyle;
- (instancetype)initWithIconString:(NSString *)iconString;
- (NSSize)stringSize;

@end

@interface ZMPTAtUserCell : ZMPTBaseTextAttachmentCell <NSSecureCoding>
{
    NSString*                   _name;
    NSString*                   _jid;
    NSColor*                    _backgroundColor;
}
/** The uniform type identifier for ZMPTAtUserCells when put on the pasteboard */
+ (NSString*)uti;

@property(nonatomic, retain,nullable) NSString* name;
@property(retain,nullable) NSString* jid;
@property(nonatomic, assign) BOOL isInChannel;
@property(nonatomic, assign) BOOL isMentionChannel;
@property(nonatomic, assign) BOOL isMentionGroup;
@property(retain,nullable) NSColor* backgroundColor;
@property(assign) BOOL isShort;
@property(nonatomic, retain,nullable) NSString* deletedName;
@property(assign) NSInteger index;
/**
 @abstract The index of the ZMPTAtUserCell.attachment's character when  this cell was pasted
 @discussion For use when copy/pasting a ZMPTAtUserCell. This is only set when the cell is copied.
 */
@property (nonatomic, assign) NSUInteger indexWhenCopied;

- (BOOL)changeToShortStyle;

@end

@interface ZMPTCommandCell : ZMPTBaseTextAttachmentCell
{
    NSString*                   _command;
}

@property(nonatomic, readwrite, retain) NSString* command;

@end

enum {
    ZMChatMetionType_none = 0,
    ZMChatMetionType_all,
    ZMChatMetionType_me,
};
typedef NSUInteger ZMChatMetionType;

@class ZMNewMessageReceivedView;

@protocol ZMNewMessageReceivedViewDelegate <NSObject>

- (void)newMessageReceivedViewClicked:(ZMNewMessageReceivedView*)view;

@end


@interface ZMNewMessageReceivedView : NSView
{
    NSUInteger                                  _unreadMessage;
    BOOL                                        _isMentioned;
    BOOL                                        _isUp;
    BOOL                                        _isMentionedMe;
    BOOL                                        _onlyShowNumber;
    ZMChatMetionType                            _metionType;
}

@property (weak) id<ZMNewMessageReceivedViewDelegate> delegate;
@property (assign) NSUInteger unreadMessage;
@property (assign) BOOL isMentioned;
@property (assign) BOOL isMentionedMe;
@property (assign) BOOL isUp;
@property (assign) BOOL onlyShowNumber;
@property (assign) ZMChatMetionType metionType;

- (float)getStringWidth;
- (NSString *)fetchString;

@end

enum
{
    ZMBezierPathRoundCornorStyle_topLeft = 1 << 0,
    ZMBezierPathRoundCornorStyle_topRight = 1 << 1,
    ZMBezierPathRoundCornorStyle_buttomLeft = 1 << 2,
    ZMBezierPathRoundCornorStyle_buttomRight = 1 << 3,
};
typedef NSUInteger ZMBezierPathRoundCornorStyle;

@interface NSBezierPath (Extension)

+ (nullable NSBezierPath*)bezierPathWithRect:(NSRect)rect radius:(CGFloat)radius withStyle:(ZMBezierPathRoundCornorStyle)style;
+ (nullable NSBezierPath*)bezierPathWithThreeCornorsRoundedRect:(NSRect)rect radius:(CGFloat)radius;
+ (nullable NSBezierPath*)bezierPathWithTwoCornorsRoundedRect:(NSRect)rect radius:(CGFloat)radius;

@end

@interface ZMChatTableView : NSTableView
{
    NSColor*            _selectedColor;
}
@property (nonatomic, readwrite, copy) NSColor* selectedColor;
@end

@class ZMPTGiphyData;

@interface ZMPTIconCell : ZMPTBaseTextAttachmentCell{
    NSImage*  _icon;
}
@property(nonatomic, readwrite, retain)NSImage* icon;
@end

@interface ZMPTSeparatorCell : ZMPTBaseTextAttachmentCell

@property (nonatomic,retain,nullable) NSColor *titleColor;
@property (nonatomic,retain,nullable) NSColor *tintColor;
@property (nonatomic,assign) CGFloat lineWidth;

@property (nonatomic,assign) NSTextAlignment zmAlignment;
@property (nonatomic,assign) NSEdgeInsets contentInset;

@end

@interface ZMChatSearchField : NSTextField

@end

NS_ASSUME_NONNULL_END
