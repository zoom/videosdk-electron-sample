//
//  ZMHotkeyValidatorProtocol.h
//  ZCommonUI
//
//  Created by francis zhuo on 2019/3/7.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,ZMRecordErrorType){
    ZMRecordErrorType_RequireModifierFlag,
    ZMRecordErrorType_IllegalModifierFlag,
    ZMRecordErrorType_TakenBySystem,
    ZMRecordErrorType_TakenByCustom,
    ZMRecordErrorType_TakenByMenu,
};

NS_ASSUME_NONNULL_BEGIN
@class ZMHotkeyCombo;
@protocol ZMHotkeyValidatorProtocol <NSObject>
@optional
- (BOOL)isAvailableHotkeyCombo:(ZMHotkeyCombo*)combo identifier:(nullable NSString*)identifier global:(BOOL)isGlobal error:(NSError **)outError;
@end
NS_ASSUME_NONNULL_END
