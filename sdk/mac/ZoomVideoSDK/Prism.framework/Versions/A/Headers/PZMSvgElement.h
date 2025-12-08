//
//  ZMSvgElement.h
//  ZMImageRes
//
//  Created by francis zhuo on 12/12/2019.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PZMSvgElement : NSObject<NSCopying>
@property(assign) CGFloat scale;
@property(nullable, copy) NSString* elementName;
@property(nullable, strong) NSDictionary* attribute;
@property(nullable, strong) NSArray* childElements;
@end
@compatibility_alias ZMSvgElement PZMSvgElement;

NS_ASSUME_NONNULL_END
