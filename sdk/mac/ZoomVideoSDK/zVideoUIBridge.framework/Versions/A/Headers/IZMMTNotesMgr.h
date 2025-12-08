//
//  IZMMTNotesMgr.h
//  VideoUIBridge
//
//  Created by Lester on 2023/05/10.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
class ICmmZoomNotesApi;
#endif

@class ZMMTSplitViewController;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMTNotesMgr <ZMRoutableObject>

@property (nonatomic, assign, readonly) BOOL isSidePanelVisible;
@property (nonatomic, copy, readonly) NSString* dashboardUrl;
- (NSString*)makeDocumentUrl:(NSString*)noteID;
@property (nonatomic, assign) BOOL sidePanelOpen;
- (void)postStringToWeb:(NSString*)stringContent;
- (void)onInviteCollaboration:(NSString*)presenterName
                  presenterID:(unsigned int)presenterID
                       noteID:(NSString*)noteID;
- (void)onCollaborationEnds:(NSString*)presenterName
                presenterID:(unsigned int)presenterID;
- (void)onShareOptionVary;
- (void)onFitbarButton;
- (void)onNotesSidePanelRemove;
- (void)showNotesOptions;
- (void)jsRequiresToFinishLoading;
- (nullable NSString*)popNoteIDtoLoad;
- (void)pushNoteIDtoLoad:(nullable NSString*)noteIDtoLoad;
#ifdef __cplusplus
- (ICmmZoomNotesApi*)getNotesApiIfAvailable:(nullable ZMConfSession*)confSession;
#endif

- (BOOL)isSharingAllowed:(nullable BOOL *)isSharingAllowed
  isSharingOptionsLocked:(nullable BOOL *)isSharingOptionsLocked
isAttendeeSharingAllowed:(nullable BOOL * )isAttendeeSharingAllowed
isAttendeeGrabSharingAllowed:(nullable BOOL *)isAttendeeGrabSharingAllowed;
- (void)setIsAttendeeSharingAllowed:(BOOL)isAttendeeSharingAllowed;
@end

#define zmNotesMgr ZMMTSharedFor(IZMMTNotesMgr)
#define ZM_NOTES_WIDTH 370.0f
NS_ASSUME_NONNULL_END
