//
//  ZMContentSupplementaryView.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/5/30.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMBaseView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMLabel;
@interface ZMContentSupplementaryView : ZMBaseView

@property (nonatomic, strong) ZMLabel *titleLabel;
- (void)showTitle:(NSString *)title;
- (void)showAccessibilityLabel:(NSString *)label;

@end

NS_ASSUME_NONNULL_END
