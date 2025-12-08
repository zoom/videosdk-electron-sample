//
//  ZMHyperLinkTextField.h
//  hyperLinkTest
//
//  Created by likevin on 16/3/10.
//  Copyright © 2016 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#define kHyperlinkIsResponseAction      @"isResponseAction"

@interface ZMHyperLinkTextField : NSTextField{
    NSTrackingArea* _trackingArea;
    NSTextView * _textView;
    
    NSMutableArray *_hyperlinkInfos;
    NSMutableArray *_hyperlinkRectArray;
    NSMutableArray *_hyperlinkCusorArray;
    
    NSMutableDictionary*   _urlAttribute;
    BOOL  _bUnderlineWhenMouseHover;
}
@property (nonatomic, retain) NSTrackingArea *trackingArea;
@property (nonatomic, readonly) NSTextView * textView;
@property (nonatomic, readonly) NSMutableArray *hyperlinkInfos;
@property (nonatomic, retain)NSMutableDictionary*     urlAttribute;
@property (nonatomic, assign) BOOL isUnderlineWhenMouseHover;

- (BOOL) setURL:(NSString*)url forSubString:(NSString*)subStr;
- (BOOL) setURLs:(NSArray *)urlArray forSubStrs:(NSArray*)subStrArray;
- (BOOL) setURLWithDictionary:(NSDictionary*)subStr2UrlDict;
@end

@interface ZMHyperLinkTextFieldExtend : ZMHyperLinkTextField
@property (nonatomic, readwrite, weak)id  targetObject;
@property (nonatomic, readwrite, assign)SEL targetAction;
@end

//HyperlinkTextView support accessibility
//Can only added or remove all of them and re-add
//If the TextView change it's frame or scroll need call relayoutUrlButton outside
//ZOOM-40537{
@interface ZMHyperLinkButton: NSButton
{
    NSString*       _urlString;
    NSRange         _urlRange;
}
@property(nonatomic, assign) NSRange urlRange;

- (void)setHyperLinkString:(NSString*)urlString range:(NSRange)range;
@end

@interface ZMHyperLinkTextView : NSTextView
{
    NSMutableArray*        _urlButtonArray;
}

- (void)cleanupUrlButton;
- (void)relayoutUrlButton;
- (void)addUrlbyRange:(NSString*)usrString range:(NSRange)range;
@end
//ZOOM-40537}


@interface ZMCustomCursorTextField:NSTextField
@end
