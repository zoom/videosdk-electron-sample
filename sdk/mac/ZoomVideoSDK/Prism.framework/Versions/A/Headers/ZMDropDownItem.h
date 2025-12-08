//
//  ZMDropDownItem.h
//  ZCommonUI
//
//  Created by Geno on 2019/6/25.
//  Copyright © 2019 chenjiannan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDropDownItem : NSObject<NSCopying>

@property (nonatomic, retain, nullable) NSString *title;
@property (nonatomic, retain, nullable) NSImage *icon;
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, retain, nullable) id representedObject;
@end

NS_ASSUME_NONNULL_END
