//
//  ZMMenuConfig.h
//  ZoomKit
//
//  Created by Ado Du on 2021/12/20.
//

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMHMenuAppearance) {
    ZMHMenuAppearanceSystem,
    ZMHMenuAppearanceLight,
    ZMHMenuAppearanceDark,
};

@interface ZMMenuConfig : NSObject

+ (ZMMenuConfig *)defaultConfig; /**< init config */

#pragma mark ====== menu ======
@property (nonatomic, assign) ZMHMenuAppearance appearance; /**< default is ZMHMenuAppearanceSystem */
@property (nonatomic, strong, nullable) NSColor *menuBackgroundColor; /**< menu backgroundColor, default is zmBackgroundColor */

@property (nonatomic, assign) NSSize menuMaxSize;
@property (nonatomic, assign) NSSize subMenuMaxSize;
@property (nonatomic, assign) NSEdgeInsets menuEdgePaddings; /**< default is {7, 0, 7, 0} */

#pragma mark ====== item ======
@property (nonatomic, strong,nullable) NSFont *itemTitleFont; /**< default is [NSFont systemFontOfSize:13] */
@property (nonatomic, strong,nullable) NSColor *itemTitleColor; /**< default is zmPriTextColor */
@property (nonatomic, strong,nullable) NSColor *itemTitleHighlightColor; /**< default is zmWhiteColor */
@property (nonatomic, strong,nullable) NSColor *itemSubtitleColor; /**< default is zmGreyColor */
@property (nonatomic, strong,nullable) NSColor *itemSubtitleHighlightColor; /**< default is zmWhiteColor */
@property (nonatomic, strong,nullable) NSColor *itemSelectBackgroundColor; /**< default check color */
@property (nonatomic, strong,nullable) NSColor *itemHighlightBackgroundColor; /**< hover color */
@property (nonatomic, strong,nullable) NSImage *itemCheckImage;

@property (nonatomic, assign) NSEdgeInsets itemMargin; /**< default is {6, 16, 6, 16} */
@property (nonatomic, assign) CGFloat itemMinWidth;

@end

NS_ASSUME_NONNULL_END
