//
//  ZMShareSelectSegmentObject.h
//  ZoomUnit
//
//  Created by walt.li on 6/25/23.
//

#import <ZoomUnit/ZMShareSelectDef.h>
NS_ASSUME_NONNULL_BEGIN


@interface ZMShareSelectSegmentObject : NSObject

@property (nonatomic, assign) ZMShareSelectSegmentType  type;
@property (nonatomic, copy, nullable) NSString    *title;
@property (nonatomic, assign) NSUInteger    identifier;
//ability
@property (nonatomic, assign) BOOL      supportLayouts;
@property (nonatomic, assign) BOOL      supportShareBo;
@property (nonatomic, assign) BOOL      supportMultiSelection;
//customized view
@property (nonatomic, weak, nullable) NSView    *footView;
@property (nonatomic, weak, nullable) NSView    *workingView;
//banner
@property (nonatomic, copy, nullable) NSString  *bannerString;
//attched view only for ZMShareSelectSegmentNormal
@property (nonatomic, weak, nullable) NSView    *attachedView;
//ax
@property (nonatomic, copy, nullable) NSString  *axString;

+(instancetype)segmentWithTitle:(NSString *)title
                     identifier:(NSUInteger)identifier;

-(BOOL)isNormalSegment;
@end

NS_ASSUME_NONNULL_END
