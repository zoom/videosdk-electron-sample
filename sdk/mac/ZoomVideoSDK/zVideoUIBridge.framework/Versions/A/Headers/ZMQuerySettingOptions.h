//
//  ZMQuerySettingOptions.h
//  VideoUIBridge
//
//  Created by Karen Cao on 9/18/23.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMQuerySettingAbility){
    ZMQuerySettingAbilityUnknown    = 0,
    ZMQuerySettingAbilitySpported   = 1,
    ZMQuerySettingAbilityUnspported = 2,
};

@interface ZMQuerySettingOptions : NSObject
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* tip;
@property (nonatomic, strong) NSString* desc;
@property (nonatomic, strong) NSString* image;
@property (nonatomic, strong) NSString* imageSelected;
@property (nonatomic, strong) NSString* imageDisabled;
@property (nonatomic, strong) NSString* queryMgrInfo;
@property (nonatomic, strong) NSString* queryParticipantsInfo;
@property (nonatomic) NSInteger tag;
@property (nonatomic) ZMQuerySettingAbility ability;
@property (nonatomic) BOOL isSelected;

@end

NS_ASSUME_NONNULL_END
