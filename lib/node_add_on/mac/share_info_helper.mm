
#ifdef  __OBJC__
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#endif

#include "zoom_video_sdk_native_shareinfo_helper_wrap_core.h"


ZShareInfoHelperWrap::ZShareInfoHelperWrap(){
    
}

ZShareInfoHelperWrap::~ZShareInfoHelperWrap(){
    
}

ZNList<ZoomSTRING> ZShareInfoHelperWrap::GetMonitorsList()
{
    NSArray *screenArr = [NSScreen  screens];
    ZNList<ZoomSTRING> screenIdList;
    for (NSScreen *screen in screenArr) {
        NSDictionary *screenDic = screen.deviceDescription;
        NSNumber *num = [screenDic objectForKey:@"NSScreenNumber"];
        NSString *screenID = [num stringValue];
        ZoomSTRING ID = screenID.UTF8String;
        if (!ID.empty()) {
            screenIdList.push_back(ID);
        }
    }
    return screenIdList;
}
