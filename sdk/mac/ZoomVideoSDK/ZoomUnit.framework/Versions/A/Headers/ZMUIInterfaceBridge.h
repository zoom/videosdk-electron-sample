//
//  ZMUIInterfaceBridge.h
//  ZCommonUI
//
//  Created by Justin Fang on 6/6/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMPConfDataProtocol.h>
#import <ZoomUnit/ZMPPTDataProtocol.h>

@protocol ZPMainWinowControllerProtocol <NSObject>//ZOOM-5960
- (void)presentToRoomStatusUpdate:(int)status;
- (void)onUserLogin;
@end


@interface ZMUIInterfaceBridge : NSObject 

@property(nonatomic, readwrite, weak) id<ZMPConfDataProtocol>                             zmpMTData;
@property(nonatomic, readwrite, weak) id<ZMPPTDataProtocol>                               zmPTData;
@property(nonatomic, readwrite, weak) id<ZPMainWinowControllerProtocol>                   zmPMainWindowController;//ZOOM-5960

+ (ZMUIInterfaceBridge*)sharedBridge;

@end
