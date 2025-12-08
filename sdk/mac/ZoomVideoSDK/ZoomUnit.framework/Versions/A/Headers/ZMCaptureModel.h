//
//  ZMCaptureModel.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/3/12.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,ZMCaptureType){
    ZMCaptureTypeNone,
    ZMCaptureTypeScreen,
    ZMCaptureTypeWindow,
};

@interface ZMCaptureModel : NSObject
{
    NSString*       _name;
    ZMCaptureType   _modelType;
    NSRect          _frame;
    NSInteger       _order;
    NSImage*        _image;
    
    //for ZMCaptureTypeScreen
    NSInteger       _displayID;
    
    //for ZMCaptureTypeWindow
    NSString*       _appName;
    NSString*       _windowName;
    NSInteger       _windowID;
    NSInteger       _PID;
    NSInteger       _level;
    CGFloat         _alphaValue;
    CGRect          _cgBounds;//ZOOM-57318
}
@property(copy)NSString* name;
@property(assign)ZMCaptureType modelType;
@property(assign)NSRect frame;
@property(assign)NSInteger order;
@property(retain)NSImage* image;
@property(assign)NSInteger PID;
@property(copy)NSString* appName;
@property(copy)NSString* windowName;
@property(assign)NSInteger displayID;
@property(assign)NSInteger windowID;
@property(assign)NSInteger level;
@property(assign)CGFloat alphaValue;
@property(assign)CGRect cgBounds;//ZOOM-57318
- (void)cleanUp;
@end
