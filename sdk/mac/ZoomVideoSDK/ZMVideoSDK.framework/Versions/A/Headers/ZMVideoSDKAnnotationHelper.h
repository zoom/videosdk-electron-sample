/**
 * @file ZMVideoSDKAnnotationHelper.h
 * @brief Provides interfaces for managing annotation tools and actions in a Zoom Video SDK session.
 */

#import <Foundation/Foundation.h>
#import <ZMVideoSDK/ZMVideoSDKUserHelper.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKAnnotationHelper
 * @brief Annotation helper interface for Zoom Video SDK.
 */
@interface ZMVideoSDKAnnotationHelper : NSObject

/**
 * @brief Whether the current user can do annotation on the share.
 * @return YES means the user can do annotation, otherwise NO.
 */
- (BOOL)canDoAnnotation;

/**
 * @brief Whether annotation was disabled or not by the share owner.
 * @return YES indicates the annotations is disabled, otherwise NO.
 * @deprecated Use \link ZMVideoSDKAnnotationHelper::canDoAnnotation \endlink instead.
 */
- (BOOL)isSenderDisableAnnotation DEPRECATED_MSG_ATTRIBUTE("Use -canDoAnnotation instead");

/**
 * @brief Starts annotation.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)startAnnotation;

/**
 * @brief Stops annotation.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)stopAnnotation;

/**
 * @brief Set the annotation tool color.
 * @param toolColor The specified color
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setToolColor:(NSColor* _Nonnull)toolColor;

/**
 * @brief Gets the annotation tool color.
 * @param toolColor The current tool color.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)getToolColor:(NSColor* _Nullable * _Nonnull)toolColor;

/**
 * @brief Sets the annotation tool type.
 * @param toolType The specified annotation tool type.
 * @return If the function succeeds, it will return @c ZMVideoSDKErrors_Success.
 * @warning The tool type ZMVideoSDKAnnotationToolType_Picker and ZMVideoSDKAnnotationToolType_SpotLight are not support for viewer.
 */
- (ZMVideoSDKErrors)setToolType:(ZMVideoSDKAnnotationToolType)toolType;

/**
 * @brief Gets the annotation tool type.
 * @param toolType The current tool type.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)getToolType:(ZMVideoSDKAnnotationToolType*)toolType;

/**
 * @brief Sets the annotation tool width.
 * @param width The specify annotation tool width.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)setToolWidth:(long)width;

/**
 * @brief Gets the annotation tool width.
 * @param width The line width of annotations.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)getToolWidth:(long*)width;

/**
 * @brief Undoes one annotation content step.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)undo;

/**
 * @brief Redoes one annotation content step.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)redo;

/**
 * @brief Clears the annotation content.
 * @param type The specified clear type.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)clear:(ZMVideoSDKAnnotationClearType)type;
@end

NS_ASSUME_NONNULL_END
