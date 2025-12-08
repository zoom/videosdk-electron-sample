//
//  ZMBase.h
//  ZCommonUI
//
//  Created by Huxley on 2018/4/11.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMNSRectCorner.h>
#import <Prism/ZMDistance.h>
#import <Prism/ZMUserInterfaceOrientation.h>
#import <Prism/ZMObjectDispose.h>
#import <Prism/ZMUIlocalizing.h>
#import <Prism/ZMPlainBlock.h>
#import <Prism/ZMLayoutDirection.h>
#import <Prism/ZMViewProviding.h>

//MARK: - Object
#ifndef ZMCleanUpToNil
#define ZMCleanUpToNil(arg) if (arg) {[arg cleanUp]; arg = nil;}
#endif

#ifndef ZMCleanUpReleaseToNil
#define ZMCleanUpReleaseToNil(arg) if (arg) {[arg cleanUp]; [arg release]; arg = nil;}
#endif

#ifndef ZMReleaseToNil
#define ZMReleaseToNil(arg) if (arg) {[arg release]; arg = nil;}
#endif

#ifndef WEAK_SELF
#define WEAK_SELF __weak __typeof(&*self)weakSelf = self;
#endif

#ifndef Weak
#define Weak(o) __weak __typeof(o) weak##o = o;
#endif

#ifndef Strong
#define Strong(o) __strong __typeof(o) o = weak##o;
#endif

static const NSUInteger ZMByteUnit = 1000; // keep the same with system's unit of calculation

NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN CFTypeRef ZMAutorelease(CFTypeRef CF_RELEASES_ARGUMENT arg);

NS_INLINE BOOL ZMAvailableV2(NSUInteger versionMajor, NSUInteger versionMinor) {
	
	static NSInteger verMajor = 10;
	static NSInteger verMinor = 9;
	static BOOL isVersionReady = NO;
	
	if (!isVersionReady) {
        NSProcessInfo* systemInfo = [NSProcessInfo processInfo];
        NSOperatingSystemVersion version = [systemInfo operatingSystemVersion];
        verMajor = version.majorVersion;
        verMinor = version.minorVersion;
		isVersionReady = YES;
	}
	
	if(verMajor > versionMajor)
		return YES;
	if(verMajor == versionMajor && verMinor >= versionMinor)
		return YES;
	
	return NO;
}

NS_INLINE BOOL ZMAvailable(NSUInteger versionMinor) {
	
	return ZMAvailableV2(10, versionMinor);
}
NS_INLINE BOOL ZMAvailableIfEarlierThan(NSUInteger versionMajor, NSUInteger versionMinor) {
    
    return !ZMAvailableV2(versionMajor, versionMinor);
}

APPKIT_EXTERN BOOL CGFloatEqual(CGFloat a, CGFloat b);
APPKIT_EXTERN BOOL CGFloatLessThan(CGFloat a, CGFloat b);
APPKIT_EXTERN const NSEdgeInsets ZMZeroEdgeInsets;
APPKIT_EXTERN BOOL ZMEdgeInsetsEqual(NSEdgeInsets aInsets, NSEdgeInsets bInsets);

APPKIT_EXTERN NSRect NSEdgeInsetRect(NSRect aRect, NSEdgeInsets edge);
APPKIT_EXTERN NSRect NSEdgeInsetRectV3(NSRect aRect, NSEdgeInsets edge, BOOL isFlipped);

NS_INLINE NSRect NSOriginSquare(CGFloat length) {
    return NSMakeRect(0, 0, length, length);
};

NS_INLINE NSPoint NSRectCenter(NSRect rect) {
    return NSMakePoint(NSMidX(rect), NSMidY(rect));
}

//based screen coordinate system
APPKIT_EXTERN CGRect NSRect2CGRect(NSRect rect);
APPKIT_EXTERN NSRect CGRect2NSRect(CGRect rect);


APPKIT_EXTERN size_t ZM_Strlen( const char *str);

@protocol ZMMouseEventDelegate <NSObject>

@optional
- (void)sender:(NSView *)sender mouseDown:(NSEvent *)theEvent;
- (void)sender:(NSView *)sender mouseUp:(NSEvent *)theEvent;
- (void)sender:(NSView *)sender mouseHover:(BOOL)hovered;

@end

//ZOOM-71195
@protocol ZMForceUpdateUIProtocol <NSObject>
- (void)forceUpdateUIImage;
@end
NS_ASSUME_NONNULL_END
