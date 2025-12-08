//
//  ZMShareSelectWindowModelGroup.h
//  ZoomUnit
//
//  Created by Walt.Li on 2024/1/30.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZPShareSelectWindowModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMShareSelectWindowModelGroup : NSObject
@property (copy) NSString *title;
@property (strong) NSArray<ZPShareSelectWindowModel *> *content;

+ (instancetype)modelGroupWithTitle:(NSString *)title
                            content:(NSArray<ZPShareSelectWindowModel *> *)content;
@end

NS_ASSUME_NONNULL_END
