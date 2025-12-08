//
//  DynamicPropertyAccessor.h
//  Prism
//
//  Created by Cooper.Chen on 2025/3/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DynamicPropertyAccessor : NSObject

+ (id)getPropertyValue:(id)object propertyName:(NSString *)propertyName;

@end

NS_ASSUME_NONNULL_END
