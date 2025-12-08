//
//  ZMHotkeyValidator.h
//  ZMHotkeySetting
//
//  Created by francis zhuo on 2018/8/28.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <Prism/ZMHotkeyValidatorProtocol.h>
NS_ASSUME_NONNULL_BEGIN
FOUNDATION_EXPORT NSErrorDomain const ZMErrorDomain;

@class ZMHotkeyCombo;
@interface ZMHotkeyValidator : NSObject<ZMHotkeyValidatorProtocol>
@property(class, readonly, retain) id sharedValidator;
//- (BOOL)hasTakenBySystemForCombo:(ZMHotkeyCombo*)combo;
- (BOOL)hasTakenByMenu:(NSMenu*)aMenu Combo:(ZMHotkeyCombo*)combo exception:(nullable NSString*)identifier error:(NSError **)outError;
- (BOOL)hasTakenByCustomForCombo:(ZMHotkeyCombo *)combo exception:(nullable NSString*)identifier global:(BOOL)isGlobal error:(NSError **)outError;
@end
NS_ASSUME_NONNULL_END
