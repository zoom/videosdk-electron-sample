//
//  ZMBaseAvatarView.h
//  ZoomUnit
//
//  Created by fistice on 5/29/25.
//

#import <Cocoa/Cocoa.h>
#import <ZoomUnit/ZPUICommonDef.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseAvatarView : NSButton

- (void)setup;

@property (nonatomic,assign) int radius;
@property (nonatomic,assign) float alpha;
@property (nonatomic,assign) NSSize inset;

@property (strong,nullable) NSImage* image;
@property (nonatomic,retain,nullable) NSImageView *imageView;

@property (nonatomic,assign) BOOL needShowPresence;
@property (nonatomic,assign) ZMIMBuddyPresenceType presenceType;
@property (nonatomic,assign) BOOL isHighlighted;
@property (nonatomic,assign) BOOL isDark;

@property (nonatomic,retain) NSImage* presenceImage;
@property (nonatomic,retain) NSImageView *presenceImageView;

@property (nonatomic,assign) BOOL needShowHuddleBorder;
@property (assign, nonatomic) IBInspectable BOOL dropDown;
@property (nonatomic, retain) ZMBaseView *borderView;

@property (nullable) SEL keyPressAction;

+ (nullable NSImage *)getPresenceImageByType:(ZMIMBuddyPresenceType)presenceType dark:(BOOL)isDark highlight:(BOOL)isHighlight;
+ (CGFloat)getPresenceRadiusByType:(ZMIMBuddyPresenceType)presenceType;
@end

NS_ASSUME_NONNULL_END
