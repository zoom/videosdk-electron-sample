//
//  ZMFormatTextField.h
//  ZCommonUI
//
//  Created by huangxin on 8/26/15.
//  Copyright (c) 2015 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMFormatterFilter : NSFormatter
{
    BOOL                        _valid;
    NSMutableString*            _format;
    NSMutableCharacterSet*      _validCharacter;
    NSString*                   _formattedString;
    NSRange                     _formattedRange;
    NSRange                     _selectedRange;
}
@property (nonatomic, readwrite, assign)BOOL valid;

- (id)init;
- (BOOL)setString:(NSString*)string;
- (void)setFormat:(NSString*)format CharacterSet:(NSString*)characterSet;
- (NSRange)formattedSelectionRange;
- (NSString*)formattedStringFromString:(NSString*)string;

- (BOOL)isConfirmedToFormat:(NSString*)srcString;
- (BOOL)formattedStringFromStringRange:(NSString*)srcString SelectedRange:(NSRange)selectedRange;
@end

@interface ZMFormatTextField : ZMTextField
@property (nonatomic, readwrite, weak) id         zmTarget;//ZOOM-5960
@property (nonatomic, readwrite, assign) SEL        zmAction;//ZOOM-5960

- (id)initWithFrame:(NSRect)frameRect;
- (void)setFormatString:(NSString *)format CharacterSet:(NSString*)characterSet;
- (void)setString:(NSString*)string;
@end

@interface ZMNumberTextField : ZMFormatTextField {
    int             _max;
    int             _min;
}
@property (nonatomic, readwrite, assign)int    max;
@property (nonatomic, readwrite, assign)int    min;
- (id)initWithFrame:(NSRect)frameRect;
- (void)setString:(NSString*)string;
@end
//ZOOM-1560
@interface ZMMaxLengthTextField : NSTextField {
    int             _max;
}
@property (nonatomic, readwrite, assign)int    max;
- (id)initWithFrame:(NSRect)frameRect;
@end


@interface ZMSearchField : NSTextField<NSTextFieldDelegate>

/*
 5.14.0-Patch: the property is replacing `stringValue`, since invoking the getter`stringValue` will triggle invoking [NSCell stringValue] and [NScell setStringValue], which causes bad performance.
 */
@property (nonatomic, copy) NSString *currentText;
@end

//ZOOM-5960
@interface ZMYCentralTextFieldCell : NSTextFieldCell
{
}
@end

@interface ZMDirectShareTextField : ZMFormatTextField {
    NSColor*    _focusColor1;
    NSColor*    _focusColor2;
}
@property (nonatomic, readwrite, strong) NSColor*    focusColor1;
@property (nonatomic, readwrite, strong) NSColor*    focusColor2;
- (id)initWithFrame:(NSRect)frameRect;
@end

