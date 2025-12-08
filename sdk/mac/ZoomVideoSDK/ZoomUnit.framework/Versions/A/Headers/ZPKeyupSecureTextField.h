//
//  ZPKeyupTextField.h
//  SaasBeeConfUIModule
//
//  Created by sanshi on 6/27/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZPKeyupSecureTextField : NSSecureTextField

@property (nonatomic, weak, readwrite) id keyupTarget;
@property (nonatomic, assign, readwrite) SEL keyupAction;

@property (nonatomic, weak, readwrite) id textChangeTarget;
@property (nonatomic, assign, readwrite) SEL textChangeAction;


- (void)cleanUp;



@end
