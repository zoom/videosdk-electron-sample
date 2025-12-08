//
//  IZMMTAnnotationEventProtocol.h
//  VideoUIBridge
//
//  Created by walt.li on 5/17/23.
//

#ifndef IZMMTAnnotationEventProtocol_h
#define IZMMTAnnotationEventProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTAnnotationEventProtocol <NSObject>

@optional
- (void)whiteboardWindowStateChanged:(nullable NSView *)renderView;
- (void)whiteboardAutoSaved:(nullable NSView *)renderView data:(nullable NSValue *)data;
- (void)toolChanged:(nullable NSView *)renderView;
- (void)rootWindowChanged:(nullable NSView *)renderView;
- (void)undoRedoChanged:(nullable NSView *)renderView;
- (void)imprintChanged:(nullable NSView *)renderView;
- (void)showSavedInfo:(nullable NSView *)renderView data:(nullable NSValue *)data;
- (void)startedUp:(nullable NSView *)renderView;
- (void)onToolbarClosed:(nullable NSView *)renderView;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMMTAnnotationEventProtocol */
