//
//  ZMMTWindow.h
//  VideoUIBridge
//
//  Created by Francis Zhuo on 2024/2/20.
//

#import <Cocoa/Cocoa.h>
#import <zVideoUIBridge/ZMMTTrafficLight.h>
NS_ASSUME_NONNULL_BEGIN
typedef NS_OPTIONS(NSUInteger, ZMMTWindowBehavior){
    ZMMTWindowBehavior_None = 0,
    
    ZMMTWindowBehavior_StandarLight = 1ll<<0,//default
    ZMMTWindowBehavior_CustomLight  = 1ll<<1,
    
    ZMMTWindowBehavior_FullScreenStandarLight       = 1ll<<2,//default
    ZMMTWindowBehavior_FullScreenCustomLight        = 1ll<<3,
    ZMMTWindowBehavior_HideFullScreenStandarTitlebar= 1ll<<4,
    
    ZMMTWindowBehavior_Titlebar                     = 1ll<<10,
    ZMMTWindowBehavior_HideTitlebar                 = 1ll<<11,
    ZMMTWindowBehavior_FullScreenFloatingTitlebar   = 1ll<<12,//default
    ZMMTWindowBehavior_FullScreenAutohidingTitlebar = 1ll<<13,//default
    ZMMTWindowBehavior_FullScreenHideTitlebar       = 1ll<<14,
    
    ///fadebar is the titlebar fade view, when mouse hover to top area, ensure the text in titlebar match acc
    ZMMTWindowBehavior_FullScreenFadebar            = 1ll<<15,//default
    ZMMTWindowBehavior_FullScreenAutohidingFadebar  = 1ll<<16,//default
    ZMMTWindowBehavior_FullScreenHideFadebar        = 1ll<<17,
};

@protocol ZMMTTitleBarProtocol<NSObject>
- (ZMMTWindowBehavior)customizeTrafficLight;
- (ZMMTTrafficLightConfig*)trafficLightConfig;
- (CGFloat)titlebarHeight;

@property(nonatomic,weak) ZMMTTrafficLight* trafficLight;

@optional
- (void)windowWillEnterFullScreen:(NSWindow *)window;
- (void)windowDidEnterFullScreen:(NSWindow *)window;
- (void)windowWillExitFullScreen:(NSWindow *)window;
- (void)windowDidExitFullScreen:(NSWindow *)window;

- (void)trafficLightDidHidden:(ZMMTTrafficLight*)trafficLight;
- (void)trafficLightDidShown:(ZMMTTrafficLight*)trafficLight;

- (void)titlebarDidReveal:(NSWindow *)window;
- (void)titlebarDidConceal:(NSWindow *)window;

- (void)fullScreenFadebarDidReveal:(NSWindow *)window;
- (void)fullScreenFadebarDidConceal:(NSWindow *)window;

/**
 when any popup menu displayed in titlebar, return NO to keep the titlebar persist, or use lockFocusTitlebar
 */
- (BOOL)canConcealFullscreenTitlebar:(NSWindow *)window;
- (BOOL)canConcealFullscreenFadebar:(NSWindow *)window;
@end

@interface ZMMTWindow : ZMWindow

@property (nullable, nonatomic, strong) ZMPigment* framePigment;

@property (strong, readonly) NSButton *closeButton;//_NSThemeWidget
@property (strong, readonly) NSButton *miniaturizeButton;//
@property (strong, readonly) NSButton *zoomButton;//_NSThemeZoomWidget

@property (nonatomic, assign) ZMMTWindowBehavior zmBehavior;

@property (nonatomic, assign) ZMMTWindowBehavior trafficLightBehavior;//default standar light
@property (nonatomic, strong) ZMMTTrafficLightConfig* trafficLightLayout;//defaultConfig

@property (strong, readonly) NSLayoutGuide* zmContentGuide;
@property (nonatomic, assign) CGFloat zmTitlebarHeight;//default defaultTitlebarHeight
/**
  User can set customer titlebar view
  If titlebarViewController conformsToProtocol ZMMTTitleBarLayoutProtocol, will prefer use titlebarViewController config.
 */
@property (nullable, nonatomic, strong) NSViewController* titlebarViewController;
@property (nullable, nonatomic, strong) ZMPigment* titlebarPigment;
@property (nonatomic, assign) BOOL lockFocusTitlebar;

//for override
- (void)windowWillEnterFullScreen:(NSNotification *)notification NS_REQUIRES_SUPER;
- (void)windowDidEnterFullScreen:(NSNotification *)notification NS_REQUIRES_SUPER;
- (void)windowWillExitFullScreen:(NSNotification *)notification NS_REQUIRES_SUPER;
- (void)windowDidExitFullScreen:(NSNotification *)notification NS_REQUIRES_SUPER;

// Accessibility
- (void)scheduleAccFeedbackForTogglingFullscreen;

@end

NS_ASSUME_NONNULL_END
