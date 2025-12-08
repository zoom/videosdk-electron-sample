//
//  ZMFileCopyMgr.h
//  zChatUI
//
//  Created by Geno on 2018/10/29.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMFileCopyMgr : NSObject

+ (BOOL)copyFile:(NSString *)inFilePath toFolder:(NSString *)inDestFolder withAuthPromptText:(NSString *)authPromptText;

@end
