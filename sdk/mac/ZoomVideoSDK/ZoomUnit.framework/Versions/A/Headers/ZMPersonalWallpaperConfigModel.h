//
//  ZMPersonalWallpaperConfigModel.h
//  ZoomUnit
//
//  Created by Brace Liu on 2024/7/23.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMGalleryPlusConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPersonalWallpaperConfigModel : NSObject
@property (nonatomic, copy) NSString *wallpaperID;
@property (nonatomic, assign) NSInteger transparency;//default is -1
@property (nonatomic, assign) ZMWallpaperContentMode wallpaperContentMode;
@end

NS_ASSUME_NONNULL_END
