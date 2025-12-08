//
//  ZBCUILayerDefine.h
//  zBusinessUIComponent
//
//  Created by Jax Wu on 2024/1/13.
//

#ifndef ZBCUILayerDefine_h
#define ZBCUILayerDefine_h

#import <ZoomUnit/ZoomUnit.h>

typedef NS_ENUM(NSInteger, ZBCUILayerModelType) {
    ZBCUILayerModelTypeVideo = 0,
    ZBCUILayerModelTypeImage,
};

@protocol ZBCUILayerModelProtocol <NSObject>

@property (nonatomic, assign) ZBCUILayerModelType modelType;
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) NSInteger zIndex;
@property (nonatomic, assign) NSRect designRect;
@property (nonatomic, assign) NSInteger radius;

// Animation
@property (nonatomic, assign) BOOL bIsAnimation;
@property (nonatomic, assign) CFTimeInterval duration;
@property (nonatomic, assign) NSRect oldRect;

// Info Config
@property (nonatomic, assign) BOOL bIsShowName;
@property (nonatomic, assign) BOOL bIsShowMuteIcon;
@property (nonatomic, assign) BOOL bIsShowNoAudioIcon;
@property (nonatomic, assign) BOOL bIsShowTalking;
@property (nonatomic, assign) NSEdgeInsets infoEdge;

//
@property (nonatomic, assign) UInt32 userID;
@property (nonatomic, retain) NSImage *image;
@property (nonatomic, assign) ZMZappLayersCutoutType cutoutType;

@end

#endif /* ZBCUILayerDefine_h */
