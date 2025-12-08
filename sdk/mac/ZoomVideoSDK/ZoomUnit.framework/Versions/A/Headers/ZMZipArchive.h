#ifndef _ZMZipArchive_H
#define _ZMZipArchive_H

#import <Foundation/Foundation.h>
#import <unzip.h>

@protocol ZMZipArchiveDelegate;

@interface ZMZipArchive : NSObject

// Unzip
+ (NSDictionary*)unzipFileListAtPath:(NSString *)path
								  password:(NSString *)password
									 error:(NSError **)error
                              expFileCount:(NSInteger)expFileCount
                        maxUnzipedFileSize:(unsigned long)maxUnzipedFileSize
                            delegate:(id<ZMZipArchiveDelegate>)delegate;


+ (BOOL)unzipFileAtPath:(NSString *)zipFilePath
              toDestDir:(NSString *)unzipDestDir
           expFileCount:(NSInteger)expFileCount
     maxUnzipedFileSize:(unsigned long)maxUnzipedFileSize
               delegate:(id<ZMZipArchiveDelegate>)delegate
  terminateWhenOverSize:(BOOL)terminateWhenOverSize;

@end

@protocol ZMZipArchiveDelegate <NSObject>

@optional

- (void)zmDidUnzipArchiveAtPath:(NSString *)path zipInfo:(unz_global_info)zipInfo unzippedPath:(NSString *)unzippedPath;

- (BOOL)zmShouldUnzipFileAtIndex:(NSInteger)fIdx sumFiles:(NSInteger)tFiles zipPath:(NSString *)zipPath fInfo:(unz_file_info)fInfo;
- (BOOL)zmWillUnzipFileAtIndex:(NSInteger)fIdx sumFiles:(NSInteger)tFiles zipPath:(NSString *)zipPath fInfo:(unz_file_info)fInfo fileName:(NSString *)fName;
- (void)zmDidUnzipFileAtIndex:(NSInteger)fIdx sumFiles:(NSInteger)tFiles zipPath:(NSString *)zipPath fInfo:(unz_file_info)fInfo;
- (void)zmDidUnzipFileAtIndex:(NSInteger)fIdx sumFiles:(NSInteger)tFiles zipPath:(NSString *)zipPath unzipFilePath:(NSString *)unzipFilePath;
- (BOOL)zmGetUnzipFilePermissionAtIndex:(NSInteger)fileIndex sumFiles:(NSInteger)tFiles zipPath:(NSString *)zipPath fInfo:(unz_file_info)fInfo fileName:(NSString *)fName;
- (NSUInteger)zmMaxFileNamePathLength;

@end

#endif /* _ZMZipArchive_H */
