//
//  ZMIQConstant.h
//  VideoUI
//
//  Created by Karen Cao on 6/28/23.
//  Copyright © 2023 zoom.us. All rights reserved.
//

#ifndef ZMIQConstant_h
#define ZMIQConstant_h

typedef NS_ENUM(NSUInteger, ZMQueryRequestError) {
    ZMQueryRequestOK = 0,
    ZMQueryRequestErrorInvalidParam,
    ZMQueryRequestErrorSendFailed,
    ZMQueryRequestErrorWebUnAvailable,
    ZMQueryRequestErrorPermissionVerifyFailed,
    ZMQueryRequestErrorQueryRateLimitError,
};

typedef NS_ENUM(NSUInteger, ZMQueriesStatus) {
    ZMQueriesStatusNone = 0,
    ZMQueriesStatusStop,
    ZMQueriesStatusStart,
};

typedef NS_ENUM(NSUInteger, ZMQueriesFeedback) {
    ZMQueriesFeedbackGood = 0,
    ZMQueriesFeedbackBad = 1,
};

typedef NS_ENUM(NSUInteger, ZMMTAICFeatureType) {
    ZMMTAICFeatureTypeSummary,
    ZMMTAICFeatureTypeQuestion,
    ZMMTAICFeatureTypeNone,
    ZMMTAICFeatureTypeAll
};

#endif /* ZMIQConstant_h */
