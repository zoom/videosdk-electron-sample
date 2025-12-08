//
//  IZMMTVideoContentProtocol.h
//  VideoUIBridge
//
//  Created by Devl on 2023/4/13.
//

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTVideoContentProtocol <NSObject>

@optional
- (void)onVideoContentTypeDidChange:(ZMMTType)viewType from:(ZMMTContentType)oldType to:(ZMMTContentType)newType;
- (void)onVideoContentTypeNotChangeButPreferTypeDid:(ZMMTType)viewType;

- (void)onWindowWillEnterFullScreen:(NSWindow *)window;
- (void)onWindowDidEnterFullScreen:(NSWindow *)window;
- (void)onWindowWillExitFullScreen:(NSWindow *)window;
- (void)onWindowDidExitFullScreen:(NSWindow *)window;
- (void)onWindowWillMove:(NSWindow *)window;
- (void)onWindowDidMove:(NSWindow *)window;
- (void)onWindowDidResize:(NSWindow *)window;

- (void)onWindowWillMiniaturize:(NSWindow *)window;
- (void)onWindowDidMiniaturize:(NSWindow *)window;
- (void)onWindowDidDeminiaturize:(NSWindow *)window;

- (void)onWindowWillStartVideo:(NSWindow *)window;
- (void)onWindowDidStartVideo:(NSWindow *)window;
- (void)onWindowWillStopVideo:(NSWindow *)window;
- (void)onWindowDidStopVideo:(NSWindow *)window;

- (void)onSwitch2MiniVideoMode:(BOOL)toMiniMode;

@end

NS_ASSUME_NONNULL_END
