//
//  ZMMTImageView.h
//  zVideoUI
//
//  Created by Francis Zhuo on 10/28/20.
//  Copyright © 2020 zoom.us. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface ZMMTImageView : ZMTagView
@property(nullable, nonatomic, retain) NSImage* image;
@property(nonatomic) NSRectCorner cornerType;
@property(nonatomic) CGFloat cornerRadius;
@property(nonatomic) CGFloat borderWidth;
@property(nonatomic, retain, null_resettable) NSColor* borderColor;
@property(nonatomic, retain, null_resettable) NSColor* backgroundColor;
@property(nonatomic, retain) CALayerContentsGravity gravity;
@property(nonatomic, assign) BOOL ignoreAccessibility;//default is NO
@end

NS_ASSUME_NONNULL_END
