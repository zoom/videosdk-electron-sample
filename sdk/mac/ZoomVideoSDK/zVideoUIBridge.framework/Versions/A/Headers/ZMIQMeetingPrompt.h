//
//  ZMIQMeetingPrompt.h
//  VideoUIBridge
//
//  Created by Karen Cao on 11/6/23.
//

NS_ASSUME_NONNULL_BEGIN

@interface ZMIQMeetingPrompt : NSObject

@property (nonatomic, assign) BOOL showPrompt;
@property (nonatomic, assign) BOOL isFresh;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* desc;
@property (nonatomic, strong) NSString* linkURL;
@property (nonatomic, strong) NSString* linkText;

@end

@interface ZMAICDialogInfo : NSObject

@property (nonatomic, assign) NSInteger recommandSettingID;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* descOriginalHost;
@property (nonatomic, strong) NSString* descNormalHost;

@end

NS_ASSUME_NONNULL_END
