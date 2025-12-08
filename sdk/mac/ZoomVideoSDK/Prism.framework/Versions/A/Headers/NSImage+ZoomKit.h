//
//  NSImage+ZoomKit.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMUserInterfaceOrientation.h>

typedef NS_ENUM(NSUInteger, NSImageIndentifier) {
    kNSImageIndentifierMore = 1000,
    kNSImageIndentifierDot,
    kNSImageIndentifierArrayUp,
    kNSImageIndentifierArrayDown,
    kNSImageIndentifierArrayLeft,
    kNSImageIndentifierArrayRight,
    kNSImageIndentifierFilledArrayDown
};

typedef NS_ENUM(NSUInteger,ZMDirection){
    ZMDirectionUp,
    ZMDirectionDown,
    ZMDirectionLeft,
    ZMDirectionRight,
};

NS_ASSUME_NONNULL_BEGIN
APPKIT_EXTERN NSImage * ZMImage(NSString * lightName, NSString * darkName);
APPKIT_EXTERN NSImage * ZMTemplateImage(NSString * name);
APPKIT_EXTERN NSImage * NSTemplateImage(NSString * name);//!<Images provided by appkit

@interface NSImage (ZoomKit)

+ (void)registerResBundle:(NSBundle *)bundle;

+ (void)registerRetinaBundle:(NSBundle *)bundle;

+ (void)registerDataImagePath:(NSString *)path;

+ (NSString *)getDataImagePath;

+ (nullable NSImage *)imageWithSize:(NSSize)size drawingHandler:(void (^)(NSRect rect))drawingHandler;
+ (nullable NSImage *)imageWithSize:(CGFloat)size tintColor:(NSColor *_Nullable)tintColor drawingHandler:(void (^)(void))drawingHandler;
+ (nullable NSImage *)imageWithIndentifier:(NSImageIndentifier)indentifier tintColor:(NSColor *_Nullable)tintColor;
+ (nullable NSImage *)imageWithIndentifier:(NSImageIndentifier)indentifier tintColor:(NSColor *_Nullable)tintColor size:(CGFloat)size;
+ (nullable NSImage *)imageWithIndentifier:(NSImageIndentifier)indentifier tintColor:(NSColor *)tintColor width:(CGFloat)width height:(CGFloat)height;
- (void)drawInBounds:(NSRect)bounds;
- (nullable NSImage *)newImageWithTintColor:(NSColor *_Nullable)tintColor;
- (nullable NSImage *)newImageWithTintColor:(NSColor *_Nullable)tintColor operation:(NSCompositingOperation)operation;
- (nullable NSImage *)zmImageWithTintColor:(NSColor * _Nullable)tintColor;
- (NSImage *)zmImageWithTintColor:(NSColor * _Nullable)tintColor operation:(NSCompositingOperation)operation;

+ (nullable NSImage*)triangleImage:(NSInteger)length width:(int)lineWidth angle:(CGFloat)angle direction:(ZMDirection)dirction tintColor:(NSColor*)tintColor;
+ (nullable NSImage*)triangleImage:(NSSize)size width:(int)lineWidth direction:(ZMDirection)direction tintColor:(NSColor*)tintColor;
+ (NSImage*)crossImage:(NSSize)size width:(int)lineWidth tintColor:(NSColor*)tintColor;
+ (NSImage*)threeDotImage:(NSSize)size tintColor:(NSColor*)tintColor;

@property (readonly) NSImage * templatedImage;//!< self make template and return

+ (BOOL)isImagePath:(NSString *)imagePath;
+ (BOOL)isValidImagePath:(NSString *)imagePath;
+ (NSSize)getImageSizeWithPath:(NSString *)path;
+ (NSSize)getBestImageSizeWithOriginalSize:(NSSize)imageSize minSize:(NSSize)minSize maxSize:(NSSize)maxSize;

@property (readonly) NSSize pixelSize;
@property (nullable, readonly) CGImageRef CGImage;
@property (nullable, readonly) NSBitmapImageRep *bitmapImageRep;

- (void)zm_drawInRect:(NSRect)rect;//!< Available
- (NSImage *)zm_forceUpdateImage; //ZOOM-71195
- (NSImage *)effectiveImage;
+ (nullable NSImage *)thumbnailWithContentsOfURL:(NSURL *)URL maxPixelSize:(CGFloat)maxPixelSize;

+ (nullable NSString *)compressSaveImage:(NSImage*)inImage;
- (BOOL)saveAsJPGtoPath:(NSString *)path;

+ (NSImage *)thumbnailWithWindowId:(NSInteger)windowID withSize:(NSSize)size;
+ (NSImage *)thumbnailWithWindowArray:(NSArray<NSNumber *>*)windowArray withSize:(NSSize)size;
+ (nullable NSImage *)thumbnailWithIcon:(NSImage *)icon withSize:(NSSize)size;
- (NSImage *)imageByApplyingAlpha:(CGFloat)alpha;

- (NSImage *)imageByRotate:(CGFloat)degrees;
- (NSImage *)imageByFlipped:(ZMUserInterfaceOrientation)orientation;
- (nullable NSImage *)compositeWithSize:(NSSize)size backgroundColor:(NSColor *)backgroundColor radius:(float)radius;
- (nullable NSImage *)rotateImageWithDegrees:(CGFloat)degrees;

- (NSImage *)roundCornersImageCornerRadius:(NSInteger)radius;
- (nullable NSImage *)resizeImage:(NSSize)size;
+ (BOOL)cropImage:(NSString *)imagePath size:(NSSize)size toFile:(nonnull NSString *)toFilePath;
+ (nullable NSImage *)compositeImageWithIconImages:(NSArray<NSImage *> *)images withSize:(NSSize)size;
+ (nullable NSImage *)compositeImageWithImages:(NSArray<NSImage *> *)images
                               frames:(NSArray<NSValue *> *)frames
                                 size:(NSSize)size;
- (nullable NSBitmapImageRep *)bitmapImageRepWithSize:(NSSize)size;
#pragma mark - accessibility
@property(copy) NSString* announceLabel;

+ (NSImage *)getImageByName:(NSString*)resName;

+ (nullable NSImage *)getDarkImageByName:(NSString *)resName;

+ (NSImage*)getNormalImageByName:(NSString*)resName;

+ (NSImage*)getRetinaImageByName:(NSString*)resName;

+ (NSString *)getImagePathByImage:(NSImage*)inImage;

@end

@interface NSImage (Extension)
- (void)drawInRect:(NSRect)dstSpacePortionRect
         operation:(NSCompositingOperation)op
          fraction:(CGFloat)requestedAlpha
    respectFlipped:(BOOL)respectContextIsFlipped
             hints:(NSDictionary *)hints
            topCap:(CGFloat)top
         bottomCap:(CGFloat)bottom
           leftCap:(CGFloat)left
          rightCap:(CGFloat)right;

- (void)drawInRect:(NSRect)dstSpacePortionRect
            topCap:(CGFloat)top
         bottomCap:(CGFloat)bottom
           leftCap:(CGFloat)left
          rightCap:(CGFloat)right;

- (void)drawInRect:(NSRect)dstSpacePortionRect
         heightCap:(CGFloat)heightCap
          widthCap:(CGFloat)widthCap;

- (void)drawInRect:(NSRect)dstSpacePortionRect
           withCap:(CGFloat)cap;

//##############################
//#central image position 9 grid
//#########
//# 1 2 3 #
//# 4 5 6 #
//# 7 8 9 #
//#########
//#outline type
//# 1 circle
//#############
//#backgroud color
//#border width
//#border color
//##############################
+ (NSImage *)imageWithZMImage:(NSRect)outRect centralImage:(NSImage *)image position:(int)position outlineType:(int)type backgroud:(NSColor*)bgColor border:(float)borderWide borderColor:(NSColor*)borderColor;

+ (nullable NSImage *)imageRepWithPath:(NSString*)imgPath;
@end

@interface NSColor (Extension)
+ (nullable NSColor*)colorWithRGBString:(NSString*)colorString;//@"a5d7c8" (RGB)or @"a5d7c8ff" (RGBA)
- (CGColorRef)newZMCGColor;
@end

@interface NSImage(ZMCapture)
+ (nullable NSImage*)getScreenShot:(NSUInteger)displayId;
+ (nullable NSImage*)getWindowShot:(NSInteger)windowId;
+ (nullable NSImage*)getWindowShot:(NSInteger)windowID imageOptions:(CGWindowImageOption)options;
+ (nullable NSImage*)getWindowArrayShot:(NSArray<NSNumber *>*)windowArray;
+ (nullable NSImage *)getWindowArrayShot:(NSArray<NSNumber *>*)windowArray imageOptions:(CGWindowImageOption)options;
@end


//remove NSScrollViewMirrorView from NSWindow before dealloc NSWindow
//for leaving meeting crash 15-12-14 Sail
//#pragma GCC visibility push(default)
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//void removeNSScrollViewMirrorViewFromNSWindow(NSWindow* window);
//
//#ifdef __cplusplus
//}
//#endif
//#pragma GCC visibility pop
NS_ASSUME_NONNULL_END
