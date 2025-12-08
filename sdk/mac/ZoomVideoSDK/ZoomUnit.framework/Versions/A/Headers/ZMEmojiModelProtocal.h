//
//  ZMEmojiModelProtocal.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/28.
//

#ifndef ZMEmojiModelProtocal_h
#define ZMEmojiModelProtocal_h

NS_ASSUME_NONNULL_BEGIN

@class ZMUnicodeEmojiModel, ZMCustomEmojiModel, ZMEmojiModel;

@protocol ZMEmojiModelProtocal <NSObject>

@property (nonatomic, strong, readonly) ZMUnicodeEmojiModel *unicodeEmoji;
@property (nonatomic, strong, readonly) ZMCustomEmojiModel *customEmoji;

- (nullable NSString *)unicodeEmojiAtToneIndex:(NSInteger)index;
- (BOOL)isCustomEmoji;
- (NSString *)emojiName;
- (NSString *)emojiNameWithoutColon;
- (NSString *)downloadIfNeeded;
- (NSString *)identifierWithToneIndex:(NSInteger)idx;
- (BOOL)isEqualToModel:(ZMEmojiModel *)model;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMEmojiModelProtocal_h */
