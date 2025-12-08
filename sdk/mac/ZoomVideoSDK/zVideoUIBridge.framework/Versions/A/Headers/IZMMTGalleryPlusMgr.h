//
//  IZMMTGalleryPlusMgr.h
//  VideoUI
//
//  Created by Brace Liu on 2024/1/9.
//  Copyright © 2024 zoom.us. All rights reserved.
//



#ifndef IZMMTGalleryPlusMgr_h
#define IZMMTGalleryPlusMgr_h

#import <ZoomUnit/ZMGalleryPlusConstants.h>
#import <zVideoUIBridge/IZMMTWallpaperViewController.h>
#import <zVideoUIBridge/ZMMTBaseViewController.h>

@protocol IZMMTGalleryPlusMgr <ZMRoutableObject>
@property(nonatomic, readonly, strong) NSImage * _Nullable wallpaperImage;
@property(nonatomic, readonly, assign) NSInteger transparency;
@property(nonatomic, readonly, assign) ZMWallpaperContentMode wallpaperContentMode;
@property(nonatomic, readonly, strong) NSString * _Nullable wallpaperId;
@property (nonatomic, strong) NSImage * _Nullable innerWallpaperImage;

- (nullable ZMMTBaseViewController<IZMMTWallpaperViewController> *)newViewControllerWithType:(ZMMTType)type;

- (BOOL)isGalleryPlusWallpaperEnabled;
- (BOOL)isGalleryPlusTransparencyEnabled;
- (BOOL)canShowGalleryPlusWallpaper;
- (BOOL)canShowWallpaperWithFill;
- (BOOL)canShowWallpaperWithFit;

- (void)showSettingWindow;
- (void)closeSettingWindow;
- (BOOL)isSettingWindowShowing;
- (void)updateWallpaperDisplayStatus;
- (void)onPersonalWallpaperConfigChanged;

//sync wallpaper and video transparency
- (void)onGalleryPlusWallpaperChanged:(ZMUser *_Nullable)user wallpaperID:(NSString *_Nullable)wallpaperID;
- (void)onGalleryPlusTransparencyChanged:(ZMUser *_Nullable)user transparency:(NSInteger)transparency;
- (void)onGalleryPlusLayoutModeChanged:(ZMUser *_Nullable)user layoutMode:(ZMWallpaperContentMode)layoutMode;
- (void)onPersonalWallpaperDownloaded:(NSString *_Nullable)wallpaperID success:(BOOL)success;
- (void)onPersonalThumbnailDownloaded:(NSString *_Nullable)wallpaperID success:(BOOL)success;

@end

#endif /* IZMMTGalleryPlusMgr_h */
