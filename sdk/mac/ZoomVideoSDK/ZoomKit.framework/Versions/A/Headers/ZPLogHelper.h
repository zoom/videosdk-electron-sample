//
//  ZPLogHelper.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 5/4/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomKit/log_control.h>

#define ZPLogHelper [ZMLogger getLogger]

#if (defined(__ZOOM_NO_CLIENT_LOG) || defined(__ZOOM_ROOMS_UI_LOG_DISABLED))

    #define ZRLog(format, ...)
    #define ZRLogFuncName()
    #define ZRLogInt(intValue)
    #define ZRLogLongLong(longlongValue)
    #define ZRLogBool(boolValue)
    #define ZRLogFloat(floatValue)
    #define ZRLogString(stringValue)
    #define ZRLogRect(rectValue)
    #define ZRLogPoint(pointValue)
    #define ZRLogSize(sizeValue)

    #define ZMLog(format, ...)
    #define ZMFuncLog(format, ...)
    #define ZMMacLog(info)
    #define ZMMacLogInt(info,intValue)
    #define ZMMacLogLongLong(info,longlongValue)
    #define ZMMacLogBool(info,boolValue)
    #define ZMMacLogFloat(info,floatValue)
    #define ZMMacLogString(info,stringValue)
    #define ZMMacLogRect(info,rectValue)
    #define ZMMacLogPoint(info,pointValue)
    #define ZMMacLogSize(info,sizeValue)
    #define ZMMacWarningLog(info)

#else

    #define ZRLog(format, ...)              ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])
    #define ZRLogFuncName()              ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s ", __func__]])
    #define ZRLogInt(intValue)    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=", __func__, #intValue] withInt:intValue])
    #define ZRLogLongLong(longlongValue)            ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",  __func__,  info, #longlongValue] withLongLong:(long long)longlongValue])
    #define ZRLogBool(boolValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #boolValue] withBOOL:boolValue])
    #define ZRLogFloat(floatValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #floatValue] withFloat:floatValue])
    #define ZRLogString(stringValue)                ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #stringValue] withString:stringValue])
    #define ZRLogRect(rectValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #rectValue] withString:NSStringFromRect(rectValue)])
    #define ZRLogPoint(pointValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #pointValue] withString:NSStringFromPoint(pointValue)])
    #define ZRLogSize(sizeValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%s, %s=",   __func__, #sizeValue] withString:NSStringFromSize(sizeValue)])


    #define ZMLog(format, ...)                              ([ZPLogHelper infoLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])
    #define ZMFuncLog(format, ...)                          ([ZPLogHelper infoLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])
    #define ZMMacLog(info)                                  ([ZPLogHelper infoLog:info])
    #define ZMMacLogInt(info,intValue)                      ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #intValue] withInt:intValue])
    #define ZMMacLogLongLong(info,longlongValue)            ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #longlongValue] withLongLong:(long long)longlongValue])
    #define ZMMacLogBool(info,boolValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #boolValue] withBOOL:boolValue])
    #define ZMMacLogFloat(info,floatValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #floatValue] withFloat:floatValue])
    #define ZMMacLogString(info,stringValue)                ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #stringValue] withString:stringValue])
    #define ZMMacLogRect(info,rectValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #rectValue] withString:NSStringFromRect(rectValue)])
    #define ZMMacLogPoint(info,pointValue)                  ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #pointValue] withString:NSStringFromPoint(pointValue)])
    #define ZMMacLogSize(info,sizeValue)                    ([ZPLogHelper infoLog:[NSString stringWithFormat:@"%@, %s = ", info, #sizeValue] withString:NSStringFromSize(sizeValue)])
    #define ZMMacWarningLog(info)                           ([ZPLogHelper warningLog:info])

#endif

#define ZMMemLog(format, ...) ([ZPLogHelper memoryLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])

#define ZMMemFuncLog(format, ...)  ([ZPLogHelper memoryLog: [NSString stringWithFormat: @"%s " format, __func__, ##__VA_ARGS__]])

#define ZMPTMemLog(format, ...) ([ZPLogHelper ptMemoryLog:[NSString stringWithFormat:format, ##__VA_ARGS__]])


/**
 define log module name
 */
#define ZMLoggingModule_VideoUI  "VideoUI"
#define ZMLoggingModule_VideoUI_Clips  "VideoUI_Clips"
#define ZMLoggingModule_ChatUI_Clips  "ChatUI_Clips"
#define ZMLoggingModule_ChatUI_MeetingInvite  "ChatUI_MeetingInvite"
#define ZMLoggingModule_ChatUI   "ChatUI"
#define ZMLoggingModule_LoginUI  "LoginUI"
#define ZMLoggingModule_PhoneUI  "PhoneUI"
#define ZMLoggingModule_PTUI     "PTUI"
#define ZMLoggingModule_MailUI   "MailUI"
#define ZMLoggingModule_AppUI    "AppUI"
#define ZMLoggingModule_CCIUI    "CCIUI"
#define ZMLoggingModule_CalendarUI  "CalendarUI"
#define ZMLoggingModule_ClientSDK  "ClientSDK"
#define ZMLoggingModule_Clips  "Clips"
#define ZMLoggingModule_ZoomSetting  "ZoomSetting"
#define ZMLoggingModule_ZoomSetting_Clips  "ZoomSetting_Clips"
#define ZMLoggingModule_ZoomUpdate "ZoomUpdate"
#define ZMLoggingModule_Other  "Other"
#define ZMLoggingModule_BusinessUI  "BusinessUI"
#define ZMLoggingModule_ZoomKit "ZoomKit"
#define ZMLoggingModule_QAUI      "QAUI"
#define ZMLoggingModule_HuddlesUI "HuddlesUI"
#define ZMLoggingModule_SpacesUI "SpacesUI"
#define ZMLoggingModule_AudioUI "AudioUI"

/**
 This macro is used to replace the original ZMLog macro and can be used to print debug information. However, please use the ZTSLog macro as much as possible to print troubleshooting logs.
 */
#ifdef __ZOOM_NO_CLIENT_LOG
    #define ZUILog(module, ...)
#else
    #define ZUILog(module, ...) ([ZPLogHelper infoLog:[NSString stringWithFormat:__VA_ARGS__] moduleName:ZMLoggingModule_ ## module function:__PRETTY_FUNCTION__ line:__LINE__])
#endif


/**
 ZTSLog is used to print troubleshooting logs, and we encourage using it more often. However, please note that ZTSLog cannot print PII (personally identifiable information). If the content you want to print contains PII, you can use the PII macro to handle it.
 */
#ifdef BUILD_FOR_TROUBLESHOOT
    #define ZTSLog(module, ...) ([ZPLogHelper ts_infoLog:[NSString stringWithFormat:__VA_ARGS__] moduleName:ZMLoggingModule_ ## module function:__PRETTY_FUNCTION__ line:__LINE__])
    #define ZTSLevelLog(level, module, ...) ([ZPLogHelper ts_levelLog:[NSString stringWithFormat:__VA_ARGS__] logLevel:ZMLogLevel_ ## level moduleName:ZMLoggingModule_ ## module function:__PRETTY_FUNCTION__ line:__LINE__])
    // enable PII macro
    #define __UI_DEFINE_ENABLE_PII_LOG__
#else
    #ifdef __ZOOM_NO_CLIENT_LOG
        #define ZTSLog(module, ...)
        #define ZTSLevelLog(level, module, ...)
    #else
        #define ZTSLog(module, ...) ([ZPLogHelper infoLog:[NSString stringWithFormat:__VA_ARGS__] moduleName:ZMLoggingModule_ ## module function:__PRETTY_FUNCTION__ line:__LINE__])
        #define ZTSLevelLog(level, module, ...) ([ZPLogHelper levelLog:[NSString stringWithFormat:__VA_ARGS__] logLevel:ZMLogLevel_ ## level moduleName:ZMLoggingModule_ ## module function:__PRETTY_FUNCTION__ line:__LINE__])
    #endif
#endif

#define ZPII(string) [ZPLogHelper rotatePIINSString:string]
#define ZPIICutLeft(string) [ZPLogHelper cutPIILeftNSString:string]
#define ZPIICutRight(string) [ZPLogHelper cutPIIRightNSString:string]

#define ZPIIInt(string) [ZPLogHelper rotatePIIInt:string]
#define ZPIICutLeftInt(string) [ZPLogHelper cutPIILeftInt:string]
#define ZPIICutRightInt(string) [ZPLogHelper cutPIIRightInt:string]

#define ZPIIDouble(string) [ZPLogHelper rotatePIIDouble:string]
#define ZPIICutLeftDouble(string) [ZPLogHelper cutPIILeftDouble:string]
#define ZPIICutRightDouble(string) [ZPLogHelper cutPIIRightDouble:string]
#define ZPath(string) [string stringByAbbreviatingWithTildeInPath]

/**
 enable_log=y enabletroubleshoot=y
 ZUILog, ZMLog work. But the log content will be encrypted. ZTSLog also works.
 
 enable_log=n enabletroubleshoot=y
 ZUILog, ZMLog will not work. ZTSLog works.
 
 enable_log=n enabletroubleshoot=n
 ZMLog, ZUILog, ZTSLog all of that will not work
 
 enable_log=y enabletroubleshoot=n
 ZUILog, ZMLog work, and the ZTSLog will work like ZUILog
 */

typedef NS_ENUM(int, ZMLogLevel) {
    ZMLogLevel_VERBOSE = -1, // Not supported by common layer
    ZMLogLevel_DBG,
    ZMLogLevel_INFO,
    ZMLogLevel_WARNING,
    ZMLogLevel_ERROR,
    ZMLogLevel_ERROR_REPORT,
    ZMLogLevel_FATAL,
    ZMLogLevel_NUM_SEVERITIES, // Not supported by common layer
}; // from CmmLogging.h

@protocol ZMLogProtocal <NSObject>

- (void)infoLog:(NSString*)content;
- (void)memoryLog:(NSString*)content;
- (void)ptMemoryLog:(NSString*)content;
- (void)infoLog:(NSString*)content withInt:(long)intValue;
- (void)infoLog:(NSString*)content withLongLong:(long long)longlongValue;
- (void)infoLog:(NSString*)content withBOOL:(BOOL)boolValue;
- (void)infoLog:(NSString*)content withFloat:(float)floatValue;
- (void)infoLog:(NSString*)content withString:(NSString*)stringValue;
- (void)warningLog:(NSString*)content;
- (void)infoLog:(NSString *)content moduleName:(const char *)moduleName function:(const char *)function line:(int)line;
- (void)levelLog:(NSString *)content logLevel:(ZMLogLevel)logLevel moduleName:(const char *)moduleName function:(const char *)function line:(int)line;
- (void)ts_infoLog:(NSString *)content moduleName:(const char *)moduleName function:(const char *)function line:(int)line;
- (void)ts_levelLog:(NSString *)content logLevel:(ZMLogLevel)logLevel moduleName:(const char *)moduleName function:(const char *)function line:(int)line;

- (NSString *)rotatePIINSString:(NSString *)pii;
- (NSString *)cutPIILeftNSString:(NSString *)pii;
- (NSString *)cutPIIRightNSString:(NSString *)pii;

- (NSString *)rotatePIIInt:(int)pii;
- (NSString *)cutPIILeftInt:(int)pii;
- (NSString *)cutPIIRightInt:(int)pii;

- (NSString *)rotatePIIDouble:(double)pii;
- (NSString *)cutPIILeftDouble:(double)pii;
- (NSString *)cutPIIRightDouble:(double)pii;



@end

@interface ZMLogger : NSObject

+ (void)setLogger:(id <ZMLogProtocal>)logger;
+ (id <ZMLogProtocal>)getLogger;
+ (BOOL)isNoLogClient;

@end
