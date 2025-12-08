//
//  IZMWallpaperDownloadProtocol.h
//  ZoomUnit
//
//  Created by Brace Liu on 2024/8/2.
//

#ifndef IZMWallpaperDownloadProtocol_h
#define IZMWallpaperDownloadProtocol_h

@protocol IZMWallpaperDownloadProtocol <NSObject>

- (void)onPersonalWallpaperDownloaded:(NSString *_Nullable)wallpaperID path:(NSString *_Nullable)path success:(BOOL)success;
- (void)onPersonalThumbnailDownloaded:(NSString *_Nullable)wallpaperID path:(NSString *_Nullable)path success:(BOOL)success;

@end
#endif /* IZMWallpaperDownloadProtocol_h */
