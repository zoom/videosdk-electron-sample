//
//  ZMAIDynamicNotifier.h
//  VideoUIBridge
//
//  Created by Amanda Souriyamath on 9/28/23.
//

NS_ASSUME_NONNULL_BEGIN

@interface ZMAIDynamicNotifierItem : NSObject

@property BOOL shouldShowTip;
@property (nonatomic) NSInteger featureId;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* iconURL;
@property (nonatomic, strong) NSString* learnMoreURL;
@property (nonatomic, strong) NSDictionary<NSNumber*, NSString*>* hoverTips;
@property (nonatomic, strong) NSArray<NSString*>* services;

@end

@interface ZMAIDynamicNotifier : NSObject

@property (nonatomic, strong) NSString* desc;
@property (nonatomic, strong) NSString* linkURL;
@property (nonatomic, strong) NSString* linkText;
@property (nonatomic, strong) NSArray<ZMAIDynamicNotifierItem*>* items;

@end

NS_ASSUME_NONNULL_END
