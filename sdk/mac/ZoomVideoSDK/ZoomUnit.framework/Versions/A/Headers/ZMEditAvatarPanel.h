//
//  ZMEditAvatarPanel.h
//  ZCommonUI
//
//  Created by francis zhuo on 18/12/2019.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <ZoomUnit/ZMAlertPanel.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMEditAvatarPanel;
@protocol ZMEditAvatarPanelDelegate <NSObject>
- (void)avatarEditComplete:(ZMEditAvatarPanel*)avatarEditer outImage:(NSImage*)outImage;
@optional
- (void)userDidClickChangePictureButton:(ZMEditAvatarPanel*)avatarEditer;
- (void)userDidClickCancelButton:(ZMEditAvatarPanel*)avatarEditer;

@end

@interface ZMEditAvatarPanel : ZMAlertPanel

@property (class, nonatomic) BOOL disbled;

@property(nullable,weak) id<ZMEditAvatarPanelDelegate> editDelegate;
@property(readonly, retain) NSImage* inputImage;
@property(readonly, retain) NSImage* outputImage;
- (void)setInputImage:(NSImage *)inputImage displayWithOriginSize:(BOOL)displayWithOriginSize;
@end

NS_ASSUME_NONNULL_END
