//
//  ZMMTBaseVeiw.h
//  ZMMTNewUIDemo
//
//  Created by francis zhuo on 5/10/20.
//  Copyright © 2020 zoom. All rights reserved.
//

typedef NSUInteger ZMMTType;

#define ZMMTViewInstType(baseType, identifier) (baseType | (((NSUInteger)identifier) << ZMMTViewType.instance_id_shift))
#define ZMMTViewInstTypeID(type) ((type & ZMMTViewType.instance_id_mask) >> ZMMTViewType.instance_id_shift)

@interface ZMMTViewType : NSObject

@property(class, readonly) ZMMTType invalid;

// NOTE: when modify the level 1 type, do not forget to
// apply changes to the viewL1TypeFromType: method below

//level 1 type
@property(class, readonly) ZMMTType main;
@property(class, readonly) ZMMTType aux;
@property(class, readonly) ZMMTType mini;
@property(class, readonly) ZMMTType floatPanel;
@property(class, readonly) ZMMTType countDown;
@property(class, readonly) ZMMTType interpreter;

@property(class, readonly) ZMMTType spotLayer;
@property(class, readonly) ZMMTType tabPopout;

//level 2 type
@property(class, readonly) ZMMTType dummyScene;
@property(class, readonly) ZMMTType backstage;
@property(class, readonly) ZMMTType immersive;
@property(class, readonly) ZMMTType proctoring;
@property(class, readonly) ZMMTType sendShare;
@property(class, readonly) ZMMTType face2face;

//level 3 type
@property(class, readonly) ZMMTType share_screen;
@property(class, readonly) ZMMTType viewer_screen;
@property(class, readonly) ZMMTType wallpaper;
@property(class, readonly) ZMMTType productionStudio;

// type encoding
// the bit 56 - 63 is used as number encoding bits
// to support up to 256 instances of the same type
@property(class, readonly) NSUInteger instance_id_count;
@property(class, readonly) NSUInteger instance_id_shift;
@property(class, readonly) NSUInteger instance_id_mask;

+ (ZMMTType)viewL1TypeFromType:(ZMMTType)viewType;

@end

#import <ZoomKit/ZoomKit.h>
@interface ZMMTBaseView : ZMBaseView
@end
