//
//  IZMMTShortcutMgr.h
//  VideoUI
//
//  Created by martin.yu on 9/8/22.
//  Copyright © 2022 zoom.us. All rights reserved.
//

#ifndef IZMMTShortcutMgr_h
#define IZMMTShortcutMgr_h

@class ZMHotkey;
@protocol IZMMTShortcutMgr <ZMRoutableObject>
- (BOOL)bindHotKey:(ZMHotkey *)hotKey global:(BOOL)isGlobal;
- (void)unbindHotkeyByIdentifier:(NSString *)identifier global:(BOOL)isGlobal;

@optional
- (void)registerEscHKForFitWindows;//ZOOM-63634
- (void)unregisterEscHKForFitWindows;//ZOOM-63634
@end

#endif /* IZMMTShortcutMgr_h */
