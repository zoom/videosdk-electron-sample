#ifndef IZoomSDKMemoryHelper_h
#define IZoomSDKMemoryHelper_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZoomSDKMemoryHelper <ZMRoutableObject>

- (BOOL)getBoolValueForKey:(int)key;
- (BOOL)getStringValueForKey:(int)key value:(NSString *_Nullable *_Nonnull)outValue;
- (BOOL)isExistKey:(int)key;
@end

NS_ASSUME_NONNULL_END

#endif /* IZoomSDKMemoryHelper_h */
