//
//  ZMSignInterpretLanguage.h
//  VideoUI
//
//  Created by martin.yu on 5/5/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSignInterpretLanguage : NSObject <NSCopying>
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *iconContent;
@property (nonatomic, copy) NSString *languageID;
@property (nonatomic, retain, readonly, nullable) NSImage *icon;
@end

NS_ASSUME_NONNULL_END
