//
//  IZMMTWallpaperViewController.h
//  VideoUI
//
//  Created by Brace Liu on 2024/1/15.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#ifndef IZMMTWallpaperViewController_h
#define IZMMTWallpaperViewController_h

#import <ZoomUnit/ZMGalleryPlusConstants.h>

@protocol IZMMTWallpaperViewController <NSObject>

@property (nonatomic, weak) ZMConfSession *confSession;
/*
   If YES, Adjusting the content mode is not supported,It will not be modified automatically.
 */
@property (nonatomic, assign) BOOL fixedContentMode;
@property (nonatomic, assign) ZMWallpaperContentMode wallpaperContentMode;

- (void)startVideo;
- (void)stopVideo;

@end

#endif /* IZMMTWallpaperViewController */
