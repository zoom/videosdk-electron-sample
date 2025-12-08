//
//  ZMMTRenderInfoView.h
//  VideoUIBridge
//
//  Created by Devl on 2023/2/23.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUser;
@class ZMMTVideoRender;
@class ZMMTRenderInfoView;
@protocol ZMMTRenderInfoViewDelegate <NSObject>
- (BOOL)videoRenderInfoViewNeedShowUserName:(ZMMTRenderInfoView *)renderInfoView;
- (NSImage *)videoRenderInfoViewAudioImage:(ZMMTRenderInfoView *)renderInfoView;
- (BOOL)isVideoRenderInfoViewPinned:(ZMMTRenderInfoView *)renderInfoView;
- (BOOL)isVideoRenderInfoViewSpotlighted:(ZMMTRenderInfoView *)renderInfoView;

@optional
- (BOOL)canShowVCardWhenClickNameAndIcon;
- (NSRect)videoRenderInfoView:(ZMMTRenderInfoView*)renderInfoView frameForInfoTextField:(NSRect)defaultFrame;
- (NSImage *)videoRenderInfoViewDisabledAudioImage:(ZMMTRenderInfoView *)renderInfoView;
@end

@interface ZMMTRenderInfoView : NSView
@property (nonatomic, weak) id<ZMMTRenderInfoViewDelegate> delegate;

- (instancetype)initWithRender:(ZMMTVideoRender*)render;
- (void)cleanUp;

- (void)displayInfoTip:(ZMUser*)user;
- (void)displayInfoReady;
- (void)hideAllTip;

- (CGFloat)getInfoTipWidth;

@end

NS_ASSUME_NONNULL_END
