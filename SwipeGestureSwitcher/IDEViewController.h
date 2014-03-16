#import "DVTViewController.h"

@class IDEWorkspaceTabController, DVTStateToken, IDESelection, IDEWorkspace, IDEWorkspaceDocument;

@protocol IDESelectionSource <NSObject>
@property(readonly, nonatomic) IDEWorkspaceTabController *workspaceTabController;
@property(readonly, copy) IDESelection *contextMenuSelection;
@property(readonly, copy) IDESelection *outputSelection;
@end

@protocol DVTStatefulObject <NSObject>
+ (long long)version;
+ (void)configureStateSavingObjectPersistenceByName:(NSMutableDictionary *)arg1;
- (void)commitStateToDictionary:(NSMutableDictionary *)arg1;
- (void)revertStateWithDictionary:(NSDictionary *)arg1;
- (void)setStateToken:(DVTStateToken *)arg1;
@end

@protocol IDEWorkspaceDocumentProvider <NSObject>
@property(readonly) IDEWorkspaceDocument *workspaceDocument;
@end

@interface IDEViewController : DVTViewController <IDESelectionSource, DVTStatefulObject>
{
    IDEWorkspaceTabController *_workspaceTabController;
    id <IDEWorkspaceDocumentProvider> _workspaceDocumentProvider;
    id _outputSelection;
    id _contextMenuSelection;
    DVTStateToken *_stateToken;
}

+ (void)configureStateSavingObjectPersistenceByName:(id)arg1;
+ (long long)version;
@property(readonly) DVTStateToken *stateToken; // @synthesize stateToken=_stateToken;
@property(retain, nonatomic) IDEWorkspaceTabController *workspaceTabController; // @synthesize workspaceTabController=_workspaceTabController;
@property(copy) IDESelection *contextMenuSelection; // @synthesize contextMenuSelection=_contextMenuSelection;
@property(copy) IDESelection *outputSelection; // @synthesize outputSelection=_outputSelection;
//- (void).cxx_destruct;
- (void)setStateToken:(DVTStateToken *)arg1;
- (BOOL)_knowsAboutInstalledState;
- (void)revertState;
- (void)commitState;
- (void)commitStateToDictionary:(id)arg1;
- (void)revertStateWithDictionary:(id)arg1;
- (void)primitiveInvalidate;
@property(readonly) BOOL automaticallyInvalidatesChildViewControllers;
- (void)_invalidateSubViewControllersForView:(id)arg1;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
@property(readonly) IDEWorkspace *workspace;
@property(readonly) IDEWorkspaceDocument *workspaceDocument;
- (id)workspaceDocumentProvider;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

@end