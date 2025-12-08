//
//  ZMSidePanelDefaultHeadView.h
//  ZoomUnit
//
//  Created by Jun Pang on 4/15/22.
//

NS_ASSUME_NONNULL_BEGIN
typedef NS_OPTIONS(NSUInteger, ZMSidePanelHeadViewAbility){
    ZMSidePanelHeadViewAbility_None         = 0,
    ZMSidePanelHeadViewAbility_Close        = 1<<1,
    ZMSidePanelHeadViewAbility_Miniaturize  = 1<<2,
    ZMSidePanelHeadViewAbility_Deminiaturize= 1<<3,
    ZMSidePanelHeadViewAbility_Popup        = 1<<4,
    ZMSidePanelHeadViewAbility_Popin        = 1<<5,
    ZMSidePanelHeadViewAbility_Expand       = 1<<6,
    ZMSidePanelHeadViewAbility_Collapse     = 1<<7,
};

@protocol ZMSidePanelBaseHeadViewDelegate <NSObject>
@optional
- (ZMSidePanelHeadViewAbility)headViewAbility;

- (void)close:(id)sender;
- (void)miniaturize:(id)sender;
- (void)deminiaturize:(id)sender;
- (void)popup:(id)sender;
- (void)expand:(id)sender;
- (void)collapse:(id)sender;
@end

@interface ZMSidePanelBaseHeadView : ZMBaseView

@property(nonatomic, weak) id<ZMSidePanelBaseHeadViewDelegate> delegate;

#pragma mark - action
- (void)close:(id)sender;
- (void)miniaturize:(id)sender;
- (void)deminiaturize:(id)sender;
- (void)popup:(id)sender;
- (void)collapse:(id)sender;
- (void)expand:(id)sender;
@end

NS_ASSUME_NONNULL_END
