//
//  ZMGalleryPlusSettingViewController.h
//  VideoUI
//
//  Created by Brace Liu on 2023/12/25.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#import "ZMGalleryPlusConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class ZMGalleryPlusSettingViewController;
@class ZMGalleryPlusWallpaperModel;

@protocol ZMGalleryPlusSettingViewControllerDelegate <NSObject>

@optional

- (void)galleryPlusSettingViewController:(ZMGalleryPlusSettingViewController *)settingViewController didSelectItem:(ZMGalleryPlusWallpaperModel *)model;
- (void)galleryPlusSettingViewController:(ZMGalleryPlusSettingViewController *)settingViewController didChangeTransparency:(NSInteger)transparency isChecked:(BOOL)isChecked isDragging:(BOOL)isDragging;
- (void)galleryPlusSettingViewController:(ZMGalleryPlusSettingViewController *)settingViewController didChangeContentMode:(ZMWallpaperContentMode)wallpaperContentMode;

@end

@interface ZMGalleryPlusSettingViewController : ZMBaseViewController
@property (nonatomic, weak) id <ZMGalleryPlusSettingViewControllerDelegate> delegate;
@property (nonatomic, strong, readonly) NSMutableArray *dataItems;
@property (nonatomic, strong) ZMGalleryPlusWallpaperModel *selectModel;
@property (nonatomic, assign) BOOL isWebinar;
@property (nonatomic, strong) NSString *subtitle;
@property (nonatomic, assign) BOOL showDownloadingView;//default is YES
@property (nonatomic, assign) BOOL transparencyHidden;//default is NO

- (void)updateDataItems:(NSArray *)dataItems;
- (void)updateSelectModel:(ZMGalleryPlusWallpaperModel *_Nullable)model;
- (void)updateWallpaperModel:(ZMGalleryPlusWallpaperModel *)model downloadSuccess:(BOOL)isSuccess;
- (void)updateThumbnailModel:(ZMGalleryPlusWallpaperModel *)model;
- (void)updateTransparencyChecked:(BOOL)isChecked value:(NSInteger)blendValue;
- (void)updateWallpaperContentMode:(ZMWallpaperContentMode)wallpaperContentMode;

@end

NS_ASSUME_NONNULL_END
