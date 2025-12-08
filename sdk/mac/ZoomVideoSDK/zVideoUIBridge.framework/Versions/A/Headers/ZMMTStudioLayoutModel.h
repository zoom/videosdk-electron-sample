//
//  ZMMTStudioLayoutModel.h
//  VideoUI
//
//  Created by Brace Liu on 2022/9/27.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMTStudioLayoutAlignment)
{
    ZMMTStudioLayoutAlignmentLeft = 0,
    ZMMTStudioLayoutAlignmentCenter = 1,
    ZMMTStudioLayoutAlignmentRight = 2,
};

@interface ZMMTStudioLayoutModel : NSObject

@property (nonatomic, assign) NSRect bounds;//default is NSMakeRect(0, 0, 1920, 1080)
@property (nonatomic, assign) NSEdgeInsets marginInsets;//default is {16, 32, 16, 32}
@property (nonatomic, assign) CGFloat itemPadding;//default is 2

@property (nonatomic, assign) NSInteger maxRows;//default is 0, don't limit rows
@property (nonatomic, assign) NSInteger maxCols;//default is 0, don't limit cols

@property (nonatomic, assign) NSSize videoRatioSize;//default is (16, 9)
@property (nonatomic, assign) NSSize miniVideoSize;//default is (160, 90)

@property (nonatomic, assign) ZMMTStudioLayoutAlignment lastLineAlignment;//default is ZMMTStudioLayoutAlignmentLeft

#ifdef __cplusplus
@property (nonatomic, assign) CmmPSLayoutContext layoutContext;
#endif
@property (nonatomic, assign) CGFloat shareArea;//default is 0.7, [0, 1.0]

@end

NS_ASSUME_NONNULL_END
