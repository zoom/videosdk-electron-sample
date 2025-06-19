import { ZoomVideoSDKAnnotationToolType, ZoomVideoSDKErrors } from './zoom_video_sdk_defines.js'
import messages from './electron_zoomvideosdk_pb.js'

function hexToColorRef(hex) {

    if (hex.startsWith('#')) hex = hex.slice(1);

    if (hex.length !== 6) {
        throw new Error('Invalid hex color');
    }

    const r = parseInt(hex.slice(0, 2), 16);
    const g = parseInt(hex.slice(2, 4), 16);
    const b = parseInt(hex.slice(4, 6), 16);

    return (b << 16) | (g << 8) | r;
}

export default (function () {
    var instance
    /**
     * Return an instance to manage annotation during a video SDK session.
     * @module zoom_video_sdk_annotation
     * @return {ZoomVideoSDKAnnotation}
     */
    function init (opts) {
        const clientOpts = {...opts}
        // Private methods and variables
        if (!clientOpts.addon) {
            return null
        }
        const _addon = clientOpts.addon.GetAnnotationHelper() || null

        return {
            /**
             * Determine Whether the current user can do annotation on the share.
             * @method canDoAnnotation
             * @return {Boolean} true means the user can do annotation, otherwise false.
             */
            canDoAnnotation: function () {
                if (_addon) {
                    return _addon.CanDoAnnotation()
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Start annotation.
             * @method startAnnotation
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            startAnnotation: function () {
                if (_addon) {
                    return _addon.StartAnnotation()
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Stop annotation.
             * @method stopAnnotation
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            stopAnnotation: function () {
                if (_addon) {
                    return _addon.StopAnnotation()
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Sets the annotation tool type.
             * @method setToolType
             * @param {Number} toolType The specified tool type, {@link ZoomVideoSDKAnnotationToolType} enum.
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            setToolType: function (opts) {
                if (_addon) {
                    const clientOpts = {...opts}
                    try {
                        const toolType = clientOpts.toolType || ZoomVideoSDKAnnotationToolType.ZoomVideoSDKAnnotationToolType_None
                        const SetToolTypeParams = new messages.SetToolTypeParams()
                        SetToolTypeParams.setTooltype(toolType)
                        const bytes = SetToolTypeParams.serializeBinary()
                        return _addon.SetToolType(bytes)
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Gets the annotation tool type.
             * @method getToolType
             * @return {Object} contains err and toolType. toolType value is the annotation tool type. {@link ZoomVideoSDKAnnotationToolType} enum.
             */
            getToolType: function () {
                if (_addon) {
                    try {
                        return _addon.GetToolType()
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Sets the annotation tool color.
             * @method setToolColor
             * @param {String} toolColor The hex string of the tool color.
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            setToolColor: function (opts) {
                if (_addon) {
                    const clientOpts = {...opts}
                    try {
                        const color = hexToColorRef(clientOpts.toolColor)
                        const SetToolColorParams = new messages.SetToolColorParams()
                        SetToolColorParams.setToolcolor(color)
                        const bytes = SetToolColorParams.serializeBinary()
                        return _addon.SetToolColor(bytes)
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Gets the annotation tool color.
             * @method getToolColor
             * @return {Object} contains err and toolColor.
             */
            getToolColor: function () {
                if (_addon) {
                    try {
                        return _addon.GetToolColor()
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Sets the annotation tool type.
             * @method setToolWidth
             * @param {Number} toolWidth The tool width.
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            setToolWidth: function (opts) {
                if (_addon) {
                    const clientOpts = {...opts}
                    try {
                        const toolWidth = clientOpts.toolWidth
                        const SetToolWidthParams = new messages.SetToolWidthParams()
                        SetToolWidthParams.setToolwidth(toolWidth)
                        const bytes = SetToolWidthParams.serializeBinary()
                        return _addon.SetToolWidth(bytes)
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Gets the annotation tool type.
             * @method getToolWidth
             * @return {Object} contains err and toolWidth.
             */
            getToolWidth: function () {
                if (_addon) {
                    try {
                        return _addon.GetToolWidth()
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Clear the annotation with a clear type.
             * @method clear
             * @param {Number} clearType The specified clear type, {@link ZoomVideoSDKAnnotationToolType} enum.
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            clear: function (opts) {
                if (_addon) {
                    const clientOpts = {...opts}
                    try {
                        const clearType = clientOpts.clearType || ZoomVideoSDKAnnotationToolType.ZoomVideoSDKAnnotationToolType_None
                        const ClearAnnotationParams = new messages.ClearAnnotationParams()
                        ClearAnnotationParams.setCleartype(clearType)
                        const bytes = ClearAnnotationParams.serializeBinary()
                        return _addon.Clear(bytes)
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Undo the annotation
             * @method undo
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            undo: function () {
                if (_addon) {
                    try {
                        return _addon.Undo()
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
            /**
             * Redo the annotation
             * @method redo
             * @return {ZoomVideoSDKErrors} If the function succeeds, the return value is ZoomVideoSDKErrors_Success.
             Otherwise, failed. To get extended error information, {@link ZoomVideoSDKErrors} enum.
             */
            redo: function () {
                if (_addon) {
                    try {
                        return _addon.Redo()
                    } catch (error) {
                        return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Invalid_Parameter;
                    }
                }
                return ZoomVideoSDKErrors.ZoomVideoSDKErrors_Internal_Error
            },
        }
    };

    return {
        getInstance: function (opts) {
            if (!instance) {
                instance = init(opts)
            }
            return instance
        }
    }
})()
