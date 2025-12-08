//
//  ZMMTGalleryPlusWallpaperModel.h
//  VideoUI
//
//  Created by Brace Liu on 2024/1/19.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMGalleryPlusWallpaperDownloadStatus) {
    ZMGalleryPlusWallpaperDownloadStatus_None = 0,
    ZMGalleryPlusWallpaperDownloadStatus_Downloading,
    ZMGalleryPlusWallpaperDownloadStatus_Downloaded,
    ZMGalleryPlusWallpaperDownloadStatus_Failed
};

@interface ZMGalleryPlusWallpaperModel : NSObject

@property (nonatomic, copy) NSString *wallpaperID;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *thumbnailPath;

@property (nonatomic, assign) ZMGalleryPlusWallpaperDownloadStatus downloadStatus;

@end

NS_ASSUME_NONNULL_END
