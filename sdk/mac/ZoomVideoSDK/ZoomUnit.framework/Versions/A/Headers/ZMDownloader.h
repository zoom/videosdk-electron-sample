//
//  ZMDownloader.h
//  ZCommonUI
//
//  Created by Yang on 04/12/2017.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMBlockAlert.h>

@class ZMDialogue;
@protocol ZMDownloaderDelegate,ZMProgressIndicator;

NS_ASSUME_NONNULL_BEGIN

@interface ZMDownloader : NSObject
{
    NSURLDownload *_download;
    NSString *_url;
    NSString *_directory;
    long long _fileSize;
    long long _downloadedSize;
    ZMDialogue *_indicatorDialogue;
    BOOL _showIndicatorAlert;
    NSString *_filePath;
    BOOL _isDownloading;
}

// MARK: Init
+ (instancetype)downloaderFromURL:(nullable NSString *)url toDirectory:(nullable NSString *)directory showIndicatorAlert:(BOOL)showIndicatorAlert;

- (instancetype)initFromURL:(NSString *)url toDirectory:(nullable NSString *)directory showIndicatorAlert:(BOOL)showIndicatorAlert;

@property (weak, nullable) id <ZMDownloaderDelegate> delegate;

@property (copy, nonatomic) NSString *url;
@property (readonly) NSString *directory;
@property (readonly) NSString *filePath;

@property (readonly, getter=isDownloading) BOOL downloading;
@property (readonly) long long fileSize;
@property (readonly) long long downloadedSize;

// MARK: Control
- (void)start; //!< Start the download task and show it's UI
- (void)startOnWindow:(nullable NSWindow *)hostWindow;
- (void)abort; //!< Abort the download task and wait to retry
- (void)cleanUp; //!< End the download task and dismiss it's UI
- (void)showOnWindow:(nullable NSWindow *)hostWindow;

//MARK: UI (UI elements on the IndicatorAlert)

//Those buttons align on the IndicatorAlert right to left
@property (readonly) NSButton *firstButton;//default title = @"Download"
@property (readonly) NSButton *secondButton;//default title = @"Cancel"
@property (readonly) NSButton *thirdButton;//default title = @"Manaul"
@property (readonly) NSProgressIndicator *progressIndicator;

@property (readonly) NSWindow *window;
@property (copy, nonatomic) NSString *windowTitle;
@property (copy, nonatomic) NSString *messageText;
@property (copy, nonatomic) NSAttributedString * attributedMessageText;
@property (nonatomic, copy, nullable) NSColor * messageTextColor;

// MARK: Utils
//3 standard UI model for convinient make
- (void)setupUIForInitial;
- (void)setupUIForDownloading;
- (void)setupUIForDownloadFailed;

@end

@protocol ZMDownloaderDelegate <NSObject>

@optional
- (void)downloaderDidBegin:(ZMDownloader *)downloader;
- (void)downloaderDidFinished:(ZMDownloader *)downloader;
- (void)downloaderDidFailed:(ZMDownloader *)downloader;
- (void)downloaderDidFailed:(ZMDownloader *)downloader withError:(NSError *)error;

- (nullable NSURLCredential *)downloaderRequestCredential:(ZMDownloader *)downloader;
- (void)downloader:(ZMDownloader *)downloader performActionOnButton:(NSUInteger)index;
- (void)downloader:(ZMDownloader *)downloader processing:(CGFloat)process;//rate

@end

NS_ASSUME_NONNULL_END

