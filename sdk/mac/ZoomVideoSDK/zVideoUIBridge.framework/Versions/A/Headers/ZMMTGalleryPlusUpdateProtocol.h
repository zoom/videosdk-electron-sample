//
//  ZMMTGalleryPlusUpdateProtocol.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2024/1/25.
//

#ifndef ZMMTGalleryPlusUpdateProtocol_h
#define ZMMTGalleryPlusUpdateProtocol_h

#import <zVideoUIBridge/ZMUIConstants.h>


@protocol ZMMTGalleryPlusUpdateProtocol <NSObject>

@optional

- (void)galleryPlusDidChangeWallpaper:(NSImage *)image;
- (void)galleryPlusDidChangeTransparency:(NSInteger)transparency;
- (void)galleryPlusWallpaperShowingChanged:(BOOL)isShowing;
- (void)galleryPlusDidChangeContentMode:(ZMWallpaperContentMode)wallpaperContentMode;

@end

#endif /* ZMMTGalleryPlusUpdateProtocol_h */
