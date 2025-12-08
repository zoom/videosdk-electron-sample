//
//  ZMGridAccessibilityView.h
//  ZoomKit
//
//  Created by Groot Ding on 19/1/22.
//

#import <Prism/ZMBaseView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMGridkeyViewProtocal <NSObject>

@optional

- (NSArray <NSView *> *)getSubGridKeyViews;

@end

@interface ZMGridAccessibilityView : ZMBaseView
@property (nonatomic,assign) BOOL doNotHandleKeyDownEventSpeically;
@end

NS_ASSUME_NONNULL_END
