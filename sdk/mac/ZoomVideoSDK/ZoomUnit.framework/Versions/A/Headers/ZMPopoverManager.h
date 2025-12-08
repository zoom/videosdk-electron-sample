//
//  ZMPopoverManager.h
//  zChatUI
//
//  Created by Huxley on 2018/8/14.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMPopoverController.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPopoverManager : NSObject

+ (instancetype)sharedManager;

@property (readonly, copy, nullable) NSString *sessionID;
@property (strong, nonatomic,nullable) NSColor *popBackgroundColor;
@property (strong, nonatomic,nullable) NSColor *popTextColor;
@property (readonly) ZMPopoverController *popoverController;

- (void)showContent:(id)content sessionID:(nullable NSString *)sessionID relativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;

- (nullable NSString *)showContent:(id)content relativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge;

- (void)showContent:(id)content sessionID:(NSString *)sessionID relativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge becomeKey:(BOOL)bKey link:(nullable NSString *)link;

- (BOOL)shown;
- (void)close;
- (void)schedule2Close;

@end

NS_ASSUME_NONNULL_END
