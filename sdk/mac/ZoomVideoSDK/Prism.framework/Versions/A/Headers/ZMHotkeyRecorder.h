//
//  ZMSCRecorder.h
//  ZMSCRecorder
//
//  Created by francis zhuo on 12/09/2017.
//  Copyright © 2017 fenfei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMHotkeyValidatorProtocol.h>

extern const NSEventModifierFlags effectiveModifierFlags;

NS_ASSUME_NONNULL_BEGIN

@class ZMHotkeyRecorder;
@class ZMHotkeyCombo;
@protocol ZMHotkeyRecorderDelegate <NSObject>
@optional
- (void)hotkeyRecorderIdentifierChanged:(ZMHotkeyRecorder*)recorder;
- (BOOL)hotkeyRecorderShouldBeginRecording:(ZMHotkeyRecorder*)recorder;
- (BOOL)hotkeyRecorder:(ZMHotkeyRecorder*)recorder canRecordCombo:(ZMHotkeyCombo*)hkCombo error:(nullable NSError*)error;
- (BOOL)hotkeyRecorder:(ZMHotkeyRecorder*)recorder cacheRecordComboWithConflictFlag:(ZMHotkeyCombo*)hkCombo error:(nullable NSError*)error;
- (void)hotkeyRecorderDidEndRecording:(ZMHotkeyRecorder*)recorder;
- (void)hotkeyRecorderDidClearRecording:(ZMHotkeyRecorder*)recorder;
@end

@interface ZMHotkeyRecorder : NSView{
    NSString*  _hkIdentifier;
    
    BOOL            _enabled;
    BOOL            _isHighlighted;
    BOOL            _isRecording;
    BOOL            _isMouseDown;
    BOOL            _isMouseHover;
    
    NSEventModifierFlags    _allowedModifierFlags;
    NSEventModifierFlags    _requiredModifierFlags;
    BOOL                    _allowsEmptyModifierFlags;
    
    NSTrackingArea* _trackingArea;
    NSTrackingArea* _clearTrackingArea;
    NSTrackingArea* _backTrackingArea;
    NSToolTipTag    _titleToolTipTag;
    ZMHotkeyCombo*  _hotkeyCombo;
    
    BOOL            _allowsEscapeToCancelRecording;
    BOOL            _allowsDeleteToClearAndEndRecording;
    
    id              _localMouseDownEventMonitor;
}
@property(readonly, copy) NSString* hkIdentifier;
- (void)setIdentifier:(NSString*)identifier global:(BOOL)isGlobal;
@property(weak) IBOutlet id<ZMHotkeyRecorderDelegate> delegate;
@property(nonatomic,null_resettable,retain) IBOutlet id<ZMHotkeyValidatorProtocol> validator;
@property(getter=isEnabled) IBInspectable BOOL enabled;
@property(readonly) IBInspectable BOOL allowsEmptyModifierFlags;
@property(readonly) NSEventModifierFlags allowedModifierFlags;
@property(readonly) NSEventModifierFlags requiredModifierFlags;
@property(nullable,retain) ZMHotkeyCombo* hotkeyCombo;
@property(readonly) BOOL isInvalid;
@property(nullable, copy) NSString* specifiedTitle;
/**
 * default value is YES
 */
@property(assign) IBInspectable BOOL allowsEscapeToCancelRecording;
/**
 * default value is YES
 */
@property(assign) IBInspectable BOOL allowsDeleteToClearAndEndRecording;

@property(assign,getter=isHovered) BOOL hovered;
- (void)cleanUp;
- (void)clearRecorder;
- (void)setAllowedModifierFlags:(NSEventModifierFlags)newAllowedModifierFlags
          requiredModifierFlags:(NSEventModifierFlags)newRequiredModifierFlags
       allowsEmptyModifierFlags:(BOOL)newAllowsEmptyModifierFlags;
- (nullable NSImage*)getClearImage;
- (nullable NSImage*)getBackImage;
- (NSRect)titleRectForBounds:(NSRect)bounds;
- (NSRect)clearRectForBounds:(NSRect)bounds;
- (NSRect)backRectForBounds:(NSRect)bounds;
@end
NS_ASSUME_NONNULL_END
