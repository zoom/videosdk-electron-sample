//
//  ZMGuideHelpButton.h
//  ZoomKit
//
//  Created by Francis Zhuo on 11/4/21.
//

#import <ZoomKit/ZoomKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGuideHelpButton : ZMTextBubbleButton
@property (copy) NSString *guideString;
@property (assign) CGFloat outTiming;//if outTiming == 0, will not auto close

@property(copy) void (^guideTipMouseEventAction)(ZMBubbleObject* bubbleObj,NSEvent* event);
- (void)showGuideTip;
- (void)hideGuideTip;
@end

NS_ASSUME_NONNULL_END
