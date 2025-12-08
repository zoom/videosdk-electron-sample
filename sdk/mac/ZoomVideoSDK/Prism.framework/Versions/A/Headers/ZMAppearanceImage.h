//
//  ZMAppearanceImage.h
//  ZCommonUI
//
//  Created by javenlee on 2019/4/22.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMAppearanceImage : NSImage

@property (nonatomic, strong) NSImage *lightImg;
@property (nonatomic, strong) NSImage *darkImg;

+ (NSImage*)imageNamed:(NSImageName)name;
+ (NSImage*)imageNamed:(NSImageName)lightName darkName:(NSImageName)darkName;

- (ZMAppearanceImage *)initImageWithLight:(NSImage *)lightImg darkImg:(NSImage *)darkImg;

@end

@interface NSImage(ZMAppearanceImage)
/// support dark and light mode
+ (instancetype)zmImageWithSize:(NSSize)size drawingHandler:(void (^)(NSRect rect))drawingHandler;
@end
