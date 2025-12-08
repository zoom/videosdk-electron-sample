//
//  ZMWindow.h
//  Prism
//
//  Created by Devl on 10/22/25.
//

#import <Prism/ZMBaseWindow.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMWindow : ZMBaseWindow

@property (nonatomic, nullable, copy) void (^escBlock)(void);
@property (nonatomic, assign) BOOL alertAsSheet;
@property (nonatomic, assign) BOOL responseESC;

@end

@interface ZMUnsharableWindow : ZMWindow
@end

NS_ASSUME_NONNULL_END
