
#ifdef  __OBJC__
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Cocoa/Cocoa.h>
#import <CoreGraphics/CoreGraphics.h>
#endif

#include "zoom_video_sdk_native_sdk_wrap_core.h"
#include "zoom_video_sdk_native_shareinfo_helper_wrap_core.h"

extern ZNativeVideoSDKWrap _g_native_wrap;

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

ZNList<AppInfo> ZShareInfoHelperWrap::GetAppList()
{
    ZNList<AppInfo> appList;

    ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDK* pVideoSDK = _g_native_wrap.GetVideoSDKObj();
    if (!pVideoSDK)
    {
        return appList;
    }
    ZOOM_VIDEO_SDK_NAMESPACE::IZoomVideoSDKShareHelper* pShareHelper = pVideoSDK->getShareHelper();
    if (!pShareHelper)
    {
        return appList;
    }

    NSArray *runningApps = [[NSWorkspace sharedWorkspace] runningApplications];
    CFArrayRef windowList = CGWindowListCopyWindowInfo(kCGWindowListOptionOnScreenOnly, kCGNullWindowID);

    for (NSRunningApplication *app in runningApps) {
        // Skip background applications and accessory applications
        if ([app activationPolicy] == NSApplicationActivationPolicyProhibited || 
            [app activationPolicy] == NSApplicationActivationPolicyAccessory) {
            continue;
        }

        NSString *appName = [app localizedName];
        if (!appName || [appName length] == 0) {
            continue;
        }

        pid_t targetPid = [app processIdentifier];

        if (windowList) {
            for (NSDictionary *window in (__bridge NSArray *)windowList) {
                pid_t pid = [window[(id)kCGWindowOwnerPID] intValue];
                if (pid != targetPid) {
                    continue;
                }

                CGWindowID windowId = [window[(id)kCGWindowNumber] unsignedIntValue];
                if (!pShareHelper->isShareViewValid((void*)windowId)) {
                    continue;
                }

                NSString *windowTitle = window[(id)kCGWindowName];
                if (!windowTitle || [windowTitle length] == 0) {
                    continue;
                }

                AppInfo appInfo;
                appInfo.processId = targetPid;
                appInfo.handle = (uint64_t)windowId;
                appInfo.appName = [appName UTF8String];
                appInfo.title = [windowTitle UTF8String];
                appList.push_back(appInfo);
            }
        }
    }

    if (windowList) {
        CFRelease(windowList);
    }

    return appList;
}