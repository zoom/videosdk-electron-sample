//
//  ZMMTStudioAppLoader.h
//  VideoUI
//
//  Created by geno.chen on 2022/7/19.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <zPSApp/app/IPSApp.h>
#include <zPSApp/media/IPSMediaAgent.h>
#include <zPSApp/media/IPSRender.h>
#include <zPSApp/media/IPSCanvas.h>

@interface ZMMTStudioAppLoader : NSObject

@property (nonatomic, assign, readonly) ps::IPSApp *psApp;;

- (ps::IPSRenderMgr *)renderMgr;
- (ps::IPSCanvasMgr *)canvasMgr;
    
+ (instancetype)shared;

- (void)loadStudioApp;
- (void)unloadStudioApp;

@end

