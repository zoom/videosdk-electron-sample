//
//  ZMPassKeyManager.h
//  zLoginUI
//
//  Created by Davies Zhao on 2025/09/04.
//

#import <Foundation/Foundation.h>
#import <AuthenticationServices/ASFoundation.h>
#import <AuthenticationServices/AuthenticationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPasskeyAllowedCredentials : NSObject
@property (nonatomic, strong) NSData *credentialID;
@property (nonatomic, copy) NSArray<NSString *> *transports;

@end

@interface ZMPasskeyEnrollParams : NSObject
@property (nonatomic, copy) NSString *rpId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, strong) NSData *userId;
@property (nonatomic, strong) NSData *challenge;
@end

@interface ZMPasskeyAuthParams : NSObject
@property (nonatomic, strong) NSData *challenge;
@property (nonatomic, copy) NSString *rpId;
@property (nonatomic, copy) NSArray<ZMPasskeyAllowedCredentials *> *allowedCredentials;
@end

@interface ZMPasskeyRegistrationCredential : NSObject
@property (nonatomic, copy) NSString *credentialID;
@property (nonatomic, copy) NSString *rawClientDataJSON;
@property (nonatomic, copy) NSString *rawAttestationObject;
@property (nonatomic, copy) NSString *attachment;
@property (nonatomic, copy) NSArray<NSString *> *transports;

@end

@interface ZMPasskeyAssertionCredential : NSObject
@property (nonatomic, copy) NSString *credentialID;
@property (nonatomic, copy) NSString *rawClientDataJSON;
@property (nonatomic, copy) NSString *signature;
@property (nonatomic, copy) NSString *rawAuthenticatorData;
@property (nonatomic, copy) NSString *userID;

@end


@class ZMPassKeyManager;
@protocol ZMPassKeyDelegate <NSObject>

@optional
- (void)passKeyManager:(ZMPassKeyManager *)manager didCreatePassKeyWithCredential:(ZMPasskeyRegistrationCredential *)credential;
- (void)passKeyManager:(ZMPassKeyManager *)manager didAuthenticateWithCredential:(ZMPasskeyAssertionCredential *)credential;
- (void)passKeyManager:(ZMPassKeyManager *)manager didCompleteWithError:(NSError *)error;
- (ASPresentationAnchor)presentationAnchorForPassKeyManager:(ZMPassKeyManager *)manager;
@end

API_AVAILABLE(macos(12.0))
@interface ZMPassKeyManager : NSObject

@property (nonatomic, weak) id<ZMPassKeyDelegate> delegate;

+ (BOOL)isPassKeySupported;

- (void)createPassKey:(ZMPasskeyEnrollParams *)params;

- (void)authenticateWithPassKey:(ZMPasskeyAuthParams *)params;

@end

NS_ASSUME_NONNULL_END
