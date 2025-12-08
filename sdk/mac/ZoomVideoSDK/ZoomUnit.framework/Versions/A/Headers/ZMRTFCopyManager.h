//
//  ZMRTFCopyManager.h
//  ChatUI
//
//  Created by Yong Zhou on 1/17/22.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMessageFontInfo;
@class ZMMessageMentionInfo;

@interface ZMRTFCopyMentionData : NSObject
@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *originalMessgeContent;
@property (nonatomic, copy) NSArray<ZMMessageMentionInfo*> *mentionInfoList;
@end

@interface ZMRTFCopyManager : NSObject

@property (nonatomic, readonly, assign) NSInteger changeCount;
@property (nonatomic, readonly, assign) BOOL hasPasteItem;
@property (nonatomic, readonly, strong) NSArray<NSDictionary<NSArray<ZMMessageFontInfo *>*, NSString*> *> *pasteItems;

+ (ZMRTFCopyManager*)sharedInstance;

+ (void)releaseInstance;

- (void)cleanCopyManager;

- (void)addFontInfoList:(NSArray<ZMMessageFontInfo*>* _Nullable)infoList forContent:(NSString* _Nonnull)content;

- (void)addFontInfoList:(NSArray<ZMMessageFontInfo*>* _Nullable)infoList
             forContent:(NSString* _Nonnull)content
            mentionData:(ZMRTFCopyMentionData* _Nullable)mentionData;

@end

NS_ASSUME_NONNULL_END
