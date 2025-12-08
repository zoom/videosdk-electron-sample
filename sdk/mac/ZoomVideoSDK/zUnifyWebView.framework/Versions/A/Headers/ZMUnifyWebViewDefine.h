//
//  ZMUnifyWebViewDefine.h
//  ZoomAppUISDK
//
//  Created by Jax Wu on 2023/11/28.
//

#ifndef ZMUnifyWebViewDefine_h
#define ZMUnifyWebViewDefine_h

#import <WebKit/WebKit.h>
#import "UnifyWebViewCommonDefine.h"

extern NSString *const kWebKitDeveloperExtrasEnabled;
extern NSString *const kWebKitCachePath;
extern NSString *const kWebKitDataPath;
extern NSString *const kBlobScheme;

typedef NS_OPTIONS(NSUInteger, ZMWebCaptureDevices) {
    ZMWebCaptureDeviceMicrophone = 1 << 0,
    ZMWebCaptureDeviceCamera = 1 << 1,
    ZMWebCaptureDeviceDisplay = 1 << 2,
};

typedef NS_ENUM(NSInteger, ZMWebDisplayCapturePermissionDecision) {
    ZMWebDisplayCapturePermissionDecisionDeny,
    ZMWebDisplayCapturePermissionDecisionScreenPrompt,
    ZMWebDisplayCapturePermissionDecisionWindowPrompt,
};

typedef NS_ENUM(NSInteger, ZMWebProcessTerminationReason) {
    ZMWebProcessTerminationReasonUnknown = -1,
    ZMWebProcessTerminationReasonExceededMemoryLimit,
    ZMWebProcessTerminationReasonExceededCPULimit,
    ZMWebProcessTerminationReasonRequestedByClient,
    ZMWebProcessTerminationReasonCrash,
};

typedef NS_ENUM(NSInteger, ZMContextMenuItemTag) {
    kZMContextMenuItemTagNoAction = 0,
    kZMContextMenuItemTagOpenLinkInNewWindow,
    kZMContextMenuItemTagDownloadLinkToDisk,
    kZMContextMenuItemTagCopyLinkToClipboard,
    kZMContextMenuItemTagOpenImageInNewWindow,
    kZMContextMenuItemTagDownloadImageToDisk,
    kZMContextMenuItemTagCopyImageToClipboard,
    kZMContextMenuItemTagOpenFrameInNewWindow,
    kZMContextMenuItemTagCopy,
    kZMContextMenuItemTagGoBack,
    kZMContextMenuItemTagGoForward,
    kZMContextMenuItemTagStop,
    kZMContextMenuItemTagReload,
    kZMContextMenuItemTagCut,
    kZMContextMenuItemTagPaste,
    kZMContextMenuItemTagSpellingGuess,
    kZMContextMenuItemTagNoGuessesFound,
    kZMContextMenuItemTagIgnoreSpelling,
    kZMContextMenuItemTagLearnSpelling,
    kZMContextMenuItemTagOther,
    kZMContextMenuItemTagSearchInSpotlight,
    kZMContextMenuItemTagSearchWeb,
    kZMContextMenuItemTagLookUpInDictionary,
    kZMContextMenuItemTagOpenWithDefaultApplication,
    kZMContextMenuItemTagPDFActualSize,
    kZMContextMenuItemTagPDFZoomIn,
    kZMContextMenuItemTagPDFZoomOut,
    kZMContextMenuItemTagPDFAutoSize,
    kZMContextMenuItemTagPDFSinglePage,
    kZMContextMenuItemTagPDFFacingPages,
    kZMContextMenuItemTagPDFContinuous,
    kZMContextMenuItemTagPDFNextPage,
    kZMContextMenuItemTagPDFPreviousPage,
    kZMContextMenuItemTagOpenLink,
    kZMContextMenuItemTagIgnoreGrammar,
    kZMContextMenuItemTagSpellingMenu,
    kZMContextMenuItemTagShowSpellingPanel,
    kZMContextMenuItemTagCheckSpelling,
    kZMContextMenuItemTagCheckSpellingWhileTyping,
    kZMContextMenuItemTagCheckGrammarWithSpelling,
    kZMContextMenuItemTagFontMenu,
    kZMContextMenuItemTagShowFonts,
    kZMContextMenuItemTagBold,
    kZMContextMenuItemTagItalic,
    kZMContextMenuItemTagUnderline,
    kZMContextMenuItemTagOutline,
    kZMContextMenuItemTagStyles,
    kZMContextMenuItemTagShowColors,
    kZMContextMenuItemTagSpeechMenu,
    kZMContextMenuItemTagStartSpeaking,
    kZMContextMenuItemTagStopSpeaking,
    kZMContextMenuItemTagWritingDirectionMenu,
    kZMContextMenuItemTagDefaultDirection,
    kZMContextMenuItemTagLeftToRight,
    kZMContextMenuItemTagRightToLeft,
    kZMContextMenuItemTagPDFSinglePageScrolling,
    kZMContextMenuItemTagPDFFacingPagesScrolling,
    kZMContextMenuItemTagInspectElement,
    kZMContextMenuItemTagTextDirectionMenu,
    kZMContextMenuItemTagTextDirectionDefault,
    kZMContextMenuItemTagTextDirectionLeftToRight,
    kZMContextMenuItemTagTextDirectionRightToLeft,
    kZMContextMenuItemTagCorrectSpellingAutomatically,
    kZMContextMenuItemTagSubstitutionsMenu,
    kZMContextMenuItemTagShowSubstitutions,
    kZMContextMenuItemTagSmartCopyPaste,
    kZMContextMenuItemTagSmartQuotes,
    kZMContextMenuItemTagSmartDashes,
    kZMContextMenuItemTagSmartLinks,
    kZMContextMenuItemTagTextReplacement,
    kZMContextMenuItemTagTransformationsMenu,
    kZMContextMenuItemTagMakeUpperCase,
    kZMContextMenuItemTagMakeLowerCase,
    kZMContextMenuItemTagCapitalize,
    kZMContextMenuItemTagChangeBack,
    kZMContextMenuItemTagOpenMediaInNewWindow,
    kZMContextMenuItemTagDownloadMediaToDisk,
    kZMContextMenuItemTagCopyMediaLinkToClipboard,
    kZMContextMenuItemTagToggleMediaControls,
    kZMContextMenuItemTagToggleMediaLoop,
    kZMContextMenuItemTagEnterVideoFullscreen,
    kZMContextMenuItemTagMediaPlayPause,
    kZMContextMenuItemTagMediaMute,
    kZMContextMenuItemTagDictationAlternative,
    kZMContextMenuItemTagPlayAllAnimations,
    kZMContextMenuItemTagPauseAllAnimations,
    kZMContextMenuItemTagPlayAnimation,
    kZMContextMenuItemTagPauseAnimation,
    kZMContextMenuItemTagCopyImageUrlToClipboard,
    kZMContextMenuItemTagSelectAll,
    kZMContextMenuItemTagOpenLinkInThisWindow,
    kZMContextMenuItemTagToggleVideoFullscreen,
    kZMContextMenuItemTagShareMenu,
    kZMContextMenuItemTagToggleVideoEnhancedFullscreen,
    kZMContextMenuItemTagAddHighlightToCurrentQuickNote,
    kZMContextMenuItemTagAddHighlightToNewQuickNote,
    kZMContextMenuItemTagRevealImage,
    kZMContextMenuItemTagTranslate,
    kZMContextMenuItemTagCopyCroppedImage,
    kZMContextMenuItemBaseApplicationTag = 10000,
};

API_AVAILABLE(macos(10.11))
@interface WKWebsiteDataStore (UnifyWebView)
- (void)clearWebCache:(nullable void (^)(void))completionHandler;
@end

@protocol ZMUnifyWebViewURLSchemeHandlerProtocol <NSObject>

- (id<WKURLSchemeHandler>)urlSchemeHandler;
- (NSString *)urlSchemeName;

@end

/// UnifyWebViewConfiguration
/// asyncClipboardEnabled  Default YES;
/// mediaDevicesEnabled Default YES;
@interface ZMUnifyWebViewConfiguration : NSObject
@property (nonatomic, assign) enum UnifyWebViewType unifyWebViewType;
@property (nonatomic, assign) enum UnifyWebViewAppType moduleType;

@property (nonatomic, copy) NSString *processDisplayName;
@property (nonatomic, assign) BOOL asyncClipboardEnabled;
@property (nonatomic, assign) BOOL fullScreenEnabled;
@property (nonatomic, assign) BOOL fullScreenObserverEnabled;
@property (nonatomic, assign) BOOL mediaDevicesEnabled;
@property (nonatomic, assign) BOOL tabFocusesLinksEnabled;
@property (nonatomic, assign) BOOL checkJSMessageEnabled;
@property (nonatomic, assign) BOOL isWindowOpenEnabled;
@property (nonatomic, assign) BOOL isThirdPartyCookieEnabled;
@property (nonatomic, assign) BOOL forceKillWebContentProcessOnDestroyEnabled;
@property (nonatomic, strong) WKWebsiteDataStore *websiteDataStore;
@property (nonatomic, strong) NSArray<id<ZMUnifyWebViewURLSchemeHandlerProtocol>> *handlerArray;

@property (nonatomic, assign) BOOL isZoomControlEnabled; // WKWebView and CEF, allow web page zooming through shortcut keys, zoom in: commad + +, zoom out: command + -, restore: command + 0
@property (nonatomic, assign) BOOL isUpgradeMixedContentEnabled; // WKWebView Only, allows non-localhost non-https requests to be sent in Https web pages, such as http, zmdf and other requests.
//@property (nonatomic, assign) BOOL isSpellCheckEnabled; // WKWebView Only, Native spell checking for web pages
@property (nonatomic, assign) BOOL isDrawsTransparentBackgroundEnabled; // WKWebView Only, Keep webview background transparent
@property (nonatomic, assign) BOOL isBackgroundKeepAliveEnabled; // WKWebView Only, Keep webview active in the background to prevent it from going into sleep mode
@property (nonatomic, assign) BOOL isBackspaceKeyNavigationEnabled; // WKWebView Only, Disable response to the system backspace shortcut key.
@property (nonatomic, assign) BOOL isBlankPageDetectionEnabled; // WKWebView and CEF, When the webview is visible, an error is displayed once a white screen is detected.
@property (nonatomic, assign) BOOL isShowLoadingEnabled; // WKWebView and CEF, When this value is YES, the loading interface provided by Unify Webview is used.
@property (nonatomic, assign) BOOL isProblemReportButtonInErrorViewEnabled; // WKWebView and CEF, When this value is NO, the problem report button in the error view provided by UnifyWebView will hide.
@property (nonatomic, assign) BOOL isZoomStyleContextMenuEnabled;
@property (nonatomic, assign) BOOL isHandlingDeeplinkEnabled;
@property (nonatomic, strong) NSString *userAgentSuffix;
@property (nonatomic, strong) NSString *cacheAndCookieIdentify;
@property (nonatomic, assign) BOOL isPrivacyMode;
@property (nonatomic, assign) BOOL isInMeeting;

@property (nonatomic, assign) BOOL needShowContextMenu;
@property (nonatomic, assign) BOOL enableTrackingArea;
@property (nonatomic, assign) enum UnifyWebViewIdleRecycleType idleRecycleType;
@property (nonatomic, assign) BOOL isEnableSilentDownloadWebViewPlugin;
@property (nonatomic, assign) BOOL enableClearSensitiveCacheOnly;

- (NSString *)dataStoreIdentity;

@end

@interface NSURLRequest (UnifyWebSchemeHandler)

@property (nonatomic, strong) NSNumber *unifyTimestamp;

@end

@interface ZMWebResourceAllowDomains : NSObject
@property (nonatomic, strong) NSArray *domains;
@property (nonatomic, assign) BOOL isAllowDomains;
@end

@interface ZMUnifyWebViewNavigatePara : NSObject
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *customRequestHeaders;
@property (nonatomic, strong) NSArray<ZMWebResourceAllowDomains*> *allowDomainList;
@end

@interface ZMUnifyWebViewCaptureImage : NSObject
@property (nonatomic, assign) int type;
@property (nonatomic, strong) NSData *imgData;
@end

@interface ZMHybridAppInfo : NSObject
@property (nonatomic, assign) int hybridAppIdx;
@property (nonatomic, assign) BOOL isInMeeting;
@property (nonatomic, assign) BOOL needFallbackToCDN;
@property (nonatomic, strong) NSDictionary<NSString*, NSString*>* extraInfo;
@end

@interface ZMOpenHybridAppResult : NSObject
@property (nonatomic, assign) int hybridAppIdx;
@property (nonatomic, strong) NSString* appId;
@property (nonatomic, assign) BOOL bSuccess;
@property (nonatomic, assign) enum HybridAppLoadType loadType;
@end

@interface ZMUnifyWebViewButtonPara : NSObject
@property (nonatomic, strong) NSString* labelString;
@end


@interface ZMUnifyWebViewWindowOpenParam : NSObject
@property (nonatomic, strong) NSString* url;
@end

@interface ZMUnifyWebViewNewWindowOpenResult : NSObject
@property (nonatomic, assign) enum UnifyWebViewNewWindowOpenResultCode returnCode;
@property (nonatomic, assign) BOOL handled;
@end


#endif /* ZMUnifyWebViewDefine_h */
