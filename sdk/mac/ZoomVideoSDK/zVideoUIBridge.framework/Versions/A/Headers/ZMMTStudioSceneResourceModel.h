//
//  ZMMTStudioSceneResourceModel.h
//  VideoUIBridge
//
//  Created by Brace Liu on 2023/11/15.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMMTStudioConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTStudioSceneResourceModel : NSObject
@property (nonatomic, assign) ZMMTStudioSceneContentType type;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *resourceID;
@property (nonatomic, copy) NSString *thumbnail;
@property (nonatomic, copy) NSString *url;
@end

NS_ASSUME_NONNULL_END
