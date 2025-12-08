//
//  ZPMaxLengthFormatter.h
//  SaasBeeConfUIModule
//
//  Created by sanshi on 5/17/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZPMaxLengthFormatter : NSFormatter
{
    int _maxLength;
}

@property (nonatomic, readwrite, assign) int maxLength;


@end

@interface ZPMaxLengthNumberFormatter : ZPMaxLengthFormatter
@end
