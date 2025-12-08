//
//  ZMAudioCountryView.h
//  SaasBeeConfUIModule
//
//  Created by John on 6/17/14.
//  Copyright (c) 2014 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMAudioCountryView : NSView
{
    NSColor* _backgroundColor;
}
@property(nonatomic, strong) NSColor* borderColor;
@property(nonatomic, strong) NSColor* backgroundColor;
@end

@interface ZMAudioCountryInfo : NSObject
{
    NSString* _countryId;
    int _countryCode;
    NSString* _countryName;
    NSString* _countryNumber;
    NSString* _countryDisplayNumber;
    NSMutableArray* _numberArray;
    NSMutableArray* _tollFreeNumberArray;
    int _callType;
}
@property(nonatomic, copy)NSString* countryId;
@property(nonatomic, assign)int countryCode;
@property(nonatomic, copy)NSString* countryName;
@property(nonatomic, copy)NSString* countryNumber;
@property(nonatomic, copy)NSString* countryDisplayNumber;
@property(nonatomic, copy)NSString* phoneType;
@property(nonatomic, strong)NSMutableArray* numberArray;
@property(nonatomic, strong)NSMutableArray* tollFreeNumberArray;
@property(nonatomic, assign)int callType;
- (id)initWithCode:(int)inCode name:(NSString*)inName;
- (void)addCountryNumber:(NSString*)inNumber isFree:(BOOL)isFree;
@end

@interface ZMAudioCountryButton : ZMButton
{
    NSString* _countryId;
}
@property(nonatomic, copy) NSString* countryId;
@property(nonatomic, strong) ZMAudioCountryInfo *info;
@end
