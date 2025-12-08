/**
 * @file ZMVideoSDKAudioSendRawdata.h
 * @brief Interfaces for sending and receiving virtual audio data in Zoom Video SDK.
 */


#import <Foundation/Foundation.h>

@class ZMVideoSDKAudioRawData;
@class ZMVideoSDKUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZMVideoSDKAudioSender
 * @brief Interface for sending raw audio data.
 */
@interface ZMVideoSDKAudioSender : NSObject
/**
 * @brief Send audio raw data, and sampling bits must be 16.
 * @param data Data Pointer to the audio data buffer.
 * @param length The length of audio data in bytes (must be an even number).
 * @param rate Sampling rate of the audio data. Supported rates depend on the channel count:
 *             - Mono: 8000, 11025, 16000, 32000, 44100, 48000, 50000, 50400, 96000, 192000, 2822400
 *             - Stereo: 8000, 16000, 32000, 44100, 48000, 50000, 50400, 96000, 192000
 * @param channel Identifies the audio data channel type. default is ZMVideoSDKAudioChannel_Mono.
 * @return If the function succeeds, it will return ZMVideoSDKErrors_Success.
 */
- (ZMVideoSDKErrors)send:(char*)data dataLength:(unsigned int)length sampleRate:(int)rate channel:(ZMVideoSDKAudioChannel)channel;
@end

/**
 * @protocol ZMVideoSDKVirtualAudioMic
 * @brief Protocol for handling virtual audio microphone events.
 */
@protocol ZMVideoSDKVirtualAudioMic <NSObject>

/**
 * @brief Callback for virtual audio microphone initialization.
 * @param rawdataSender It is a pointer of audio sender object.
 */
- (void)onMicInitialize:(ZMVideoSDKAudioSender*)rawdataSender;

/**
 * @brief Callback for microphone to start sending raw data. For example, this could be sent if the user unmuted audio.
 */
- (void)onMicStartSend;

/**
 * @brief Callback for microphone to stop sending raw data. For example, this could be sent if the user muted audio.
 */
- (void)onMicStopSend;

/**
 * @brief Callback sent when the microphone is uninitialized. For example, if the user left the session.
 */
- (void)onMicUninitialized;

@end

/**
 * @protocol ZMVideoSDKVirtualAudioSpeaker
 * @brief Protocol for receiving virtual audio speaker events.
 */
@protocol ZMVideoSDKVirtualAudioSpeaker <NSObject>

/**
 * @brief Callback event for receiving the mixed audio raw data from the virtual speaker.
 * @param rawdata It is a pointer of audio raw data object.
 */
- (void)onVirtualSpeakerMixedAudioReceived:(ZMVideoSDKAudioRawData*)rawdata;

/**
 * @brief Callback event for receiving the one way audio raw data of a selected user from the virtual speaker.
 * @param rawdata The one way audio raw data. A pointer of audio raw data object.
 * @param user The related user of the audio raw data.
 */
- (void)onVirtualSpeakerOneWayAudioReceived:(ZMVideoSDKAudioRawData*)rawdata user:(ZMVideoSDKUser*)user;

/**
 * @brief Callback event for receiving the share audio raw data such as buffer, sampleRate, etc.
 * @param rawdata The one way audio raw data. A pointer of audio raw data object.
 */
- (void)onVirtualSpeakerSharedAudioReceived:(ZMVideoSDKAudioRawData*)rawdata;

@end
NS_ASSUME_NONNULL_END
