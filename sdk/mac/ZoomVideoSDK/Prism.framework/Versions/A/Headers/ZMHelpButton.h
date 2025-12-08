//
//  ZMHelpButton.h
//  zChatUI
//
//  Created by Huxley on 2018/9/3.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Prism/ZMBubbleButton.h>

@interface ZMHelpButton : ZMTextBubbleButton

@property (copy, nonatomic) NSString *helpString;
@property (copy, nonatomic) NSAttributedString *helpAttributedString;
@property (assign, nonatomic) BOOL needIcon;
@property (assign, nonatomic) BOOL stackViewEscape;//default is YES
@end
