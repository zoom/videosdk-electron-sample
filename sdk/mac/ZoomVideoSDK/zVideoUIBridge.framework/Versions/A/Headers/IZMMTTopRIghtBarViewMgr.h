//
//  IZMMTTopRightBarViewMgr.h
//  VideoUIBridge
//
//  Created by Devl on 2023/4/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMMTTopRightBarContentType)
{
    ZMMTTopRightBarContent_None       = 0,
    ZMMTTopRightBarContent_Fullscreen = 1 << 0,
    ZMMTTopRightBarContent_View       = 1 << 1,
    ZMMTTopRightBarContent_PairZr     = 1 << 2,
    ZMMTTopRightBarContent_Options    = 1 << 3,
};

@class ZMMTTopRightBarViewController;
@protocol IZMMTTopRightBarViewMgr <ZMRoutableObject>

- (ZMMTTopRightBarViewController*)newViewControllerWithType:(ZMMTType)type;
- (ZMMTTopRightBarViewController*)getViewControllerWithType:(ZMMTType)type;
- (BOOL)isMouseInTopbar;
- (BOOL)isMenuShowing;

- (void)updateContent;
- (void)updateContentItems:(ZMMTTopRightBarContentType)type;
- (void)hideMultipleSpeakersToolbarTip;

@end

NS_ASSUME_NONNULL_END
