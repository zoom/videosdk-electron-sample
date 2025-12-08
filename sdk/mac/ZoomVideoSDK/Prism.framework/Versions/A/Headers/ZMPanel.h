//
//  ZMPanel.h
//  Prism
//
//  Created by Devl on 10/22/25.
//

#import <Prism/ZMBasePanel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPanel : ZMBasePanel

@property (nonatomic, nullable, copy) void (^escBlock)(void);
@property (nonatomic, assign) BOOL alertAsSheet;
@property (nonatomic, assign) BOOL responseESC;

@end

@interface ZMUnsharablePanel : ZMPanel
@end

NS_ASSUME_NONNULL_END
