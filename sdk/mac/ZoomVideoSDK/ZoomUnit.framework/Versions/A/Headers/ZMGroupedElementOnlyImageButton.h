//
//  ZMGroupedElementOnlyImageButton.h
//  ChatUI
//
//  Created by simon shang on 2021/12/1.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <ZoomUnit/ZMIMOnlyImageButton.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGroupedElementOnlyImageButton : ZMIMOnlyImageButton <ZMGroupedAccessibilityElement>
@property (nonatomic, assign) BOOL enableKeyView;
@end

NS_ASSUME_NONNULL_END
