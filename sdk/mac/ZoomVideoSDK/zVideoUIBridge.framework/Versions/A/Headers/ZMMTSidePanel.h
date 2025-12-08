//
//  ZMMTSidePanel.h
//  VideoUIBridge
//
//  Created by Devl on 7/16/25.
//

#import <zVideoUIBridge/ZMInvisibleWindow.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMTSidePanelDelegate <NSWindowDelegate>
- (void)windowWillPopIn:(NSButton *)sender;
- (void)windowClickClose:(NSButton *)sender;

@end

@interface ZMMTSidePanel : ZMInvisibleWindow
@property (weak) id<ZMMTSidePanelDelegate> delegate;

- (instancetype)init;
- (void)showWithContentView:(NSView*)view;

@end

NS_ASSUME_NONNULL_END
