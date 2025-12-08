//
//  ZMMTSessionObject.h
//  VideoUI
//
//  Created by Francis Zhuo on 8/30/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zVideoUIBridge/ZMConfBaseSinkAdapter.h>
#import <zVideoUIBridge/ZMMTConfInstSink.h>
#import <zVideoUIBridge/ZMMTDeviceUISink.h>
#import <zVideoUIBridge/ZMMTFeatureMgrSink.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTSessionObject : NSObject
@property(retain) NSString* identifier;
@property(retain) ZMConfSession* confSession;
@property(retain) ZMConfBaseSinkAdapter* sinkAdapter;
@property(nullable, assign) ZMMTConfInstSink* confInstSink;
@property(nullable, assign) ZMMTDeviceUISink* deviceUISink;

@property(nullable, retain) ZMMTFeatureMgrSinkAdapter* featureAdapter;
@property(nullable, assign) ZMMTFeatureMgrSink* featureSink;
@end

NS_ASSUME_NONNULL_END
