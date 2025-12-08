//
//  ZMFileConstants.h
//  ZoomUnit
//
//  Created by Kevin Li on 2022/4/14.
//

#ifndef ZMFileConstants_h
#define ZMFileConstants_h

static NSString * const kZMFileErrorDomain_FTCDisabled = @"kZMFileErrorDomain_FTCDisabled";

typedef NS_ENUM(unsigned long long, ZMHybridFileStyle) {
    ZMHybridFileStyle_JPG = 0x100000,
    ZMHybridFileStyle_PNG = 0x800000,
    ZMHybridFileStyle_GIF = 0x1000000,
    ZMHybridFileStyle_Giphy = 0x4000000,
    ZMHybridFileStyle_Screenshot = 0x20000000L, /* "ZMHybridFileStyle_Screenshot" is an abstract type, do not use this alone */
    ZMHybridFileStyle_Screenshot_JPG = ZMHybridFileStyle_Screenshot|ZMHybridFileStyle_JPG,
    ZMHybridFileStyle_Screenshot_PNG = ZMHybridFileStyle_Screenshot|ZMHybridFileStyle_PNG,
    ZMHybridFileStyle_OtherFile = 0x2000000,
    ZMHybridFileStyle_WhiteboardPreview = 0x40000000L, //2^30
};

typedef NS_ENUM(NSUInteger, ZMFileSourceType) {
    ZMFileSourceType_IM = 0,
    ZMFileSourceType_Meeting = 1,
    ZMFileSourceType_SMS = 2,
    ZMFileSourceType_Phone = 3,
};

typedef NS_ENUM(NSUInteger, ZMFileDLActSource) {
    ZMFileDLActSource_Default = 0,
    ZMFileDLActSource_BrowseFileList, // Resouce Tab
    ZMFileDLActSource_BrowseMsgFileList, // pin/bookmark msg
    ZMFileDLActSource_BrowseLeftTabFiles,
    ZMFileDLActSource_BrowseNewSearch
};

typedef NS_ENUM(NSUInteger, ZMChatSendFileStatus) {
    ZMChat_SendFileStatus_None = 0,
    ZMChat_SendFile_uploading = 1,
    ZMChat_SendFile_uploaded = 2,
    ZMChat_SendFile_uploadFailed = 3,
    ZMChat_SendFile_uploadFailed_Cancel = 4,
    ZMChat_SendFile_uploadPause = 5,
    ZMChat_SendFile_downloading = 6,
    ZMChat_SendFile_downloaded = 7,
    ZMChat_SendFile_downloadFailed = 8,
    ZMChat_SendFile_downloadPause = 9,
    ZMChat_SendFile_canDownload = 10,
    ZMChat_SendFile_canUpload = 11,
    ZMChat_SendFile_cancelByInfoBarries = 12,
    ZMChat_SendFile_InvalidMIME = 13,
};

typedef NS_ENUM(NSUInteger, ZMChatFileSummaryStatus) {
    ZMChatFileSummaryStatus_None = 0,
    ZMChatFileSummaryStatus_Processing = 1,
    ZMChatFileSummaryStatus_Done = 2,
};

typedef NS_ENUM (NSInteger, FileShareType) {
    FileShareType_Disabled = -1,
    FileShareType_Normal  = 0,
    FileShareType_Dropbox = 1,
    FileShareType_Onedrive,
    FileShareType_Googledrive,
    FileShareType_Box,
    FileShareType_Sharepoint
};

typedef NS_ENUM (NSUInteger, ZMThirdPartyFileType){
    ZMThirdPartyFileType_None  = 0,
    ZMThirdPartyFileType_Word = 1,
    ZMThirdPartyFileType_Excel,
    ZMThirdPartyFileType_PPT,
    ZMThirdPartyFileType_OneNote,
    ZMThirdPartyFileType_BoxNode,
    ZMThirdPartyFileType_BoxNodeFromTemplate,
    ZMThirdPartyFileType_GoogleDocs,
    ZMThirdPartyFileType_GoogleSlides,
    ZMThirdPartyFileType_GoogleSheet,
};

typedef NS_ENUM (NSUInteger, ZMDownloadFileFlag) {
    ZMDownloadFileFlag_None = 0,
    ZMDownloadFileFlag_NeedReConnnect = 1,
    ZMDownloadFileFlag_Manually = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMFileStorageSource)
{
    ZMFileStorageSource_Zoom        = 0,
    ZMFileStorageSource_Sharepoint,
    ZMFileStorageSource_Box,
};

typedef NS_ENUM (NSUInteger, ZMEmojiType){
    ZMEmoji_UnKnown  = 0,
    ZMEmoji_SavedEmoji = 1,
    ZMEmoji_Giphy = 2,
};

typedef NS_OPTIONS (NSUInteger, ZMDownloadFileOptions) {
    ZMDownloadFileOption_None = 0,
    ZMDownloadFileOption_NeedReConnnect = 1,
    ZMDownloadFileOption_Manually = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMFTPermissionType) {
    ZMFTPermission_None = 0,
    ZMFTPermission_NotAllowed,
    ZMFTPermission_NotAllowedExtension,
    ZMFTPermission_NotAllowedExtension_External,
    ZMFTPermission_NotAllowedSize,
    ZMFTPermission_NotAllowedSize_External,
    ZMFTPermission_NotAllowedScopeBySenderAdmin,
    ZMFTPermission_NotAllowedScopeByMyAdmin,
    ZMFTPermission_Allowed,
    ZMFTPermission_NotTrust,
};

typedef NS_ENUM(NSUInteger, ZMFileScopeType) {
    ZMFileScope_Anyone = 0,
    ZMFileScope_SameOrg,
    ZMFileScope_SameAccount,
    ZMFileScope_Invalid,
};

typedef NS_ENUM(NSInteger, ZMFileCheckResult) {
    ZMFileCheckResult_ParaError = -1,
    ZMFileCheckResult_Valid = 0,
    ZMFileCheckResult_NotExist,
    ZMFileCheckResult_Directory,
    ZMFileCheckResult_LargeFile,
    ZMFileCheckResult_LargeFile4External,
    ZMFileCheckResult_EmptyFile, /* ZOOM-318851, File size is Zero */
    ZMFileCheckResult_SmallFileSizeErrorInE2ESession, /*File size must >= 16 byte in E2E chat */
    ZMFileCheckResult_BlockedFile,
    ZMFileCheckResult_BlockedFile4Extenral,
    ZMFileCheckResult_BlockedFileSameOrgOnly, /* ZOOM-373520, Files transfer is restricted to the same org */
    ZMFileCheckResult_FileNameContainsInvalidChar,
};

#endif /* ZMFileConstants_h */
