#import "DVTCancellable.h"
#import "IDEViewController.h"

@class DVTStateRepository, IDEEditorContext, IDENavigableItem, IDENavigableItemArchivableRepresentation, IDEWorkspace;
@class IDEEditor, IDENavigableItemCoordinator, IDEEditorHistoryItem;
@class IDEEditorSplittingController;
@class DVTFindBar, DVTDocumentLocation, DVTFindResult;
@class IDEViewController;
@class IDEPathCell, IDEPathComponentCell;
@class IDEEditorDocument;
@class DVTStateToken;

@class DVTBorderedView, IDENavBar, DVTGradientImagePopUpButton, IDEEditorStepperView;
@class DVTStateRepository, DVTFileDataType, IDEEditorArea, DVTNotificationToken, DVTObservingToken, DVTBindingToken;
@class IDEEditorGeniusResults, IDEEditorHistoryController, CDUnknownBlockType, DVTStackBacktrace, DVTScopeBarsManager;
@class IDEEditorMultipleContext, _IDEGeniusResultsContext, IDEEditorReadOnlyIndicatorController;
@class IDEEditorIssueMenuController;

@protocol IDEEditorContextDelegate <NSObject>

@optional
- (void)editorContext:(IDEEditorContext *)arg1 editorStateRepositoryDidChange:(DVTStateRepository *)arg2;
- (void)removeSplitForEditorContext:(IDEEditorContext *)arg1;
- (void)addSplitForEditorContext:(IDEEditorContext *)arg1;
- (IDENavigableItem *)editorContext:(IDEEditorContext *)arg1 navigableItemForEditingFromArchivedRepresentation:(IDENavigableItemArchivableRepresentation *)arg2 error:(id *)arg3;
- (IDEEditorContext *)primaryEditorContext;
- (void)editorContextDidBecomeLastActiveEditor:(IDEEditorContext *)arg1;
- (BOOL)provideWorkspaceStructureForEmptyEditorContext:(IDEEditorContext *)arg1;
- (void)_editorContext:(IDEEditorContext *)arg1 openingEmptyEditorInsteadOfNavigableItem:(IDENavigableItem *)arg2;
- (BOOL)editorContext:(IDEEditorContext *)arg1 emptyEditorRootNavigableItem:(id *)arg2 selectedNavigableItem:(id *)arg3;
- (void)editorContext:(IDEEditorContext *)arg1 didUpdateMenu:(NSMenu *)arg2;
- (BOOL)canCloseDocumentForEditorContext:(IDEEditorContext *)arg1;
- (void)editorContext:(IDEEditorContext *)arg1 didSetNavigableItem:(IDENavigableItem *)arg2;
- (NSArray *)editorContext:(IDEEditorContext *)arg1 relatedMenuItemsForNavItem:(IDENavigableItem *)arg2;
- (IDEWorkspace *)workspaceForEditorContext:(IDEEditorContext *)arg1;
@end

@protocol IDEEditorSplittingControllerDelegate <NSObject>
- (void)removeSplitForSplittingController:(IDEEditorSplittingController *)arg1;
- (void)addSplitForSplittingController:(IDEEditorSplittingController *)arg1;
@end

@protocol IDEEditorContextProtocol <NSObject>
@property(readonly, nonatomic) IDEEditor *editor;
@property(readonly) IDENavigableItemCoordinator *navigableItemCoordinator;
- (BOOL)_openEmptyEditor;
- (void)_giveEditorFocusIfNeeded;
- (BOOL)_openEditorHistoryItem:(IDEEditorHistoryItem *)arg1 updateHistory:(BOOL)arg2;
- (IDEEditorHistoryItem *)currentHistoryItem;
@end


@protocol DVTFindBarFindable

@optional
- (struct _NSRange)selectedRangeForFindBar:(DVTFindBar *)arg1;
- (DVTDocumentLocation *)startingLocationForFindBar:(DVTFindBar *)arg1 findingBackwards:(BOOL)arg2;
- (void)dvtFindBar:(DVTFindBar *)arg1 didUpdateCurrentResult:(DVTFindResult *)arg2;
- (void)dvtFindBar:(DVTFindBar *)arg1 didUpdateResults:(NSArray *)arg2;
@end

@protocol DVTFindBarHostable <DVTFindBarFindable>
- (void)dismissFindBar:(DVTFindBar *)arg1 andRestoreSelection:(BOOL)arg2;

@optional
- (NSView *)viewToShowWrapOrEndOfFileBezelOn:(DVTFindBar *)arg1;
- (BOOL)dvtFindBar:(DVTFindBar *)arg1 validateUserInterfaceItem:(id <NSValidatedUserInterfaceItem>)arg2;
- (void)dvtFindBar:(DVTFindBar *)arg1 didWrap:(BOOL)arg2 reverse:(BOOL)arg3;
@end

@protocol IDEPathCellDelegate <NSPathCellDelegate>

@optional
- (void)pathCell:(IDEPathCell *)arg1 didEndDragForComponentCell:(IDEPathComponentCell *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 beginDragForComponentCell:(IDEPathComponentCell *)arg2;
- (NSString *)pathCell:(IDEPathCell *)arg1 toolTipForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCell:(IDEPathCell *)arg1 accessibilityDescriptionForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCell:(IDEPathCell *)arg1 titleForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCellNoSelectionTitle;
- (struct CGPoint)pathCell:(IDEPathCell *)arg1 adjustPopupMenuLocation:(struct CGPoint)arg2;
- (NSMenuItem *)pathCell:(IDEPathCell *)arg1 menuItemForNavigableItem:(IDENavigableItem *)arg2 defaultMenuItem:(NSMenuItem *)arg3;
- (void)pathCell:(IDEPathCell *)arg1 didUpdateMenu:(NSMenu *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldEnableSelection:(IDENavigableItem *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldInitiallyShowMenuSearch:(IDENavigableItem *)arg2;
- (NSArray *)pathCell:(IDEPathCell *)arg1 childItemsForItem:(IDENavigableItem *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldPopUpMenuForPathComponentCell:(IDEPathComponentCell *)arg2 item:(IDENavigableItem *)arg3;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldSeparateDisplayOfChildItemsForItem:(IDENavigableItem *)arg2;
@end

@protocol DVTScopeBarHost <NSObject>
@property(readonly) NSView *scopeBarsBaseView;

@optional
@property(readonly) NSScrollView *scopeBarsAdjustableScrollView;
@end

@protocol IDENavigableItemCoordinatorDelegate <NSObject>

@optional
- (NSArray *)navigableItem:(IDENavigableItem *)arg1 childRepresentedObjectsForArray:(NSArray *)arg2;
- (IDEEditorDocument *)navigableItemCoordinator:(IDENavigableItemCoordinator *)arg1 editorDocumentForNavigableItem:(IDENavigableItem *)arg2;
@end

@protocol IDEEditorDelegate <NSObject>

@optional
- (DVTScopeBarsManager *)scopeBarsManagerForEditor:(IDEEditor *)arg1;
@end

@protocol DVTStateRepositoryDelegate <NSObject>
- (void)stateRepositoryDidChange:(DVTStateRepository *)arg1;
@end

@interface IDEEditorContext : IDEViewController <NSMenuDelegate, IDEEditorContextProtocol, IDEEditorSplittingControllerDelegate, DVTFindBarHostable, NSPathControlDelegate, IDEPathCellDelegate, DVTScopeBarHost, IDENavigableItemCoordinatorDelegate, IDEEditorDelegate, DVTStateRepositoryDelegate, NSAnimationDelegate>
{
    NSView *_editorAndNavBarView;
    IDENavBar *_navBar;
    DVTBorderedView *_editorBorderedView;
    DVTGradientImagePopUpButton *_relatedItemsPopUpButton;
    IDEEditorStepperView *_stepperView;
    id <IDEEditorContextDelegate> _delegate;
    DVTStateRepository *_stateRepository;
    IDENavigableItemCoordinator *_navigableItemCoordinator;
    IDENavigableItem *_navigableItem;
    IDENavigableItem *_greatestDocumentAncestor;
    DVTFileDataType *_cacheFromNavigation_greatestDocumentAncestorFileDataType;
    IDENavigableItem *_navBarNavigableItemRoot;
    IDENavigableItem *_navBarNavigableItem;
    IDEEditorArea *_editorArea;
    IDEEditor *_editor;
    NSString *_documentExtensionIdentifier;
    NSArray *_documentSelectedItems;
    DVTNotificationToken *_editorContextWillOpenNavigableItemNotificationToken;
    DVTNotificationToken *_editorDocumentForNavBarStructureDidChangeNotificationToken;
    DVTNotificationToken *_editorDocumentForNavBarStructureWillCloseNotificationToken;
    DVTNotificationToken *_editorDocumentIsEditedStatusDidChangeNotificationToken;
    DVTNotificationToken *_editorDocumentWillCloseNotificationToken;
    DVTNotificationToken *_findStringChangedNotificationToken;
    DVTNotificationToken *_navigableItemPropertyObserver;
    DVTNotificationToken *_navigableItemCoordinatorDidForgetItemsNotificationToken;
    DVTNotificationToken *_workspaceWillWriteNotificationToken;
    DVTObservingToken *_editorDocumentForNavBarStructureChangedObservingToken;
    DVTObservingToken *_windowMainViewControllerChangedObservingToken;
    DVTNotificationToken *_windowDidBecomeKeyObserverToken;
    DVTObservingToken *_lastActiveEditorContextChangedObservingToken;
    DVTObservingToken *_currentSelectedItemsObservingToken;
    id <DVTCancellable> _deferredUpdateSubDocumentNavigableItemsCancellableToken;
    DVTBindingToken *_navBarNavigableItemRootChildItemsBindingToken;
    DVTBindingToken *_navBarNavigableItemBindingToken;
    IDEEditorGeniusResults *_editorGeniusResults;
    IDENavigableItem *_geniusResultsRootNavigableItem;
    DVTObservingToken *_counterpartsObservingToken;
    IDEEditorHistoryController *_historyController;
    NSArrayController *_navigableItemSiblingsController;
    NSArray *_navigableItemSiblings;
    NSIndexSet *_navigableItemSiblingsSelectionIndexes;
    DVTScopeBarsManager *_scopeBarsManager;
    IDEEditorReadOnlyIndicatorController *_readOnlyIndicatorController;
    DVTObservingToken *_showReadOnlyIndicatorObserver;
    DVTFindBar *_findBar;
    NSDictionary *_editorStateDictionaryPreviousToFind;
    IDEEditorIssueMenuController *_issueMenuController;
    DVTObservingToken *_showIssueMenuControllerObserver;
    IDEEditorMultipleContext *_multipleContext;
    IDEEditorSplittingController *_splittingController;
    // pared result: CDUnknownBlockType, not id
    id _retryOpenOperationBlock;
    DVTObservingToken *_workspaceLoadingObservingToken;
    IDEEditorHistoryItem *_beforeUninstallHistoryItem;
    NSString *_emptyContentString;
    NSMutableArray *_commandExtensions;
    NSArray *_defaultEditorCategories;
    NSArray *_validEditorCategories;
    DVTStackBacktrace *_beganChangingNavigableItemBacktrace;
    int _borderSides;
    BOOL _showRelatedItemsControl;
    BOOL _showNavBarHistoryStepperControls;
    BOOL _showSiblingStepperControl;
    BOOL _showMiniIssueNavigator;
    BOOL _showSplittingControls;
    BOOL _changingNavBarNavigableItem;
    BOOL _isComparisonContext;
    BOOL _isPrimaryEditorContext;
    BOOL _viewIsInstalled;
    BOOL _shouldObserveDocumentChanges;
    BOOL _editorProvidesPathCellMenuItems;
    BOOL _isPerformingStateRestoration;
    BOOL _hideWorkspaceLoadingProgressIndicator;
    BOOL _canAddSplit;
    BOOL _canRemoveSplit;
    BOOL _isReplacingClosedDocument;
    BOOL _isDraggingPathCell;
    BOOL _isFetchingCurrentSelectedItems;
    unsigned long long _currentSwipeAnimationGeneration;
    char *_swipeAnimationAborted;
    BOOL _disableGeniusResultUpdatesDuringSwipeAnimation;
    NSView *_swipeLayerView;
    CALayer *_swipeBackgroundLayer;
    CALayer *_swipeForegroundLayer;
    // pared result: CDUnknownBlockType, not id
    id _swipeCompletionBlock;
    NSDictionary *_editorStateDictionaryPreviousToSwipe;
    _IDEGeniusResultsContext *_geniusResultsContext;
}

+ (id)_titleForNavigationUserInterfaceItem:(id)arg1 forEventBehavior:(int)arg2 fromPrimaryEditorContext:(BOOL)arg3;
+ (struct CGColor *)linenColor;
+ (BOOL)_canEditEditorHistoryItem:(id)arg1 withEditorCategories:(id)arg2;
+ (BOOL)_canEditDocumentURL:(id)arg1 fileDataType:(id)arg2 documentExtensionIdentifier:(id)arg3 withEditorCategories:(id)arg4;
+ (id)_defaultDocumentExtensionForDocumentURL:(id)arg1 fileDataType:(id)arg2 withEditorCategories:(id)arg3;
+ (BOOL)automaticallyNotifiesObserversOfNavBarNavigableItem;
+ (BOOL)automaticallyNotifiesObserversOfNavigableItem;
+ (id)navigationLogAspect;
+ (void)initialize;
+ (BOOL)automaticallyNotifiesObserversOfGreatestDocumentAncestor;
+ (id)keyPathsForValuesAffectingIsLastActiveEditorContext;
+ (id)keyPathsForValuesAffectingValueForNavBarNavigableItemRootChildItems;
@property(retain) _IDEGeniusResultsContext *geniusResultsContext; // @synthesize geniusResultsContext=_geniusResultsContext;
// pared result: CDUnknownBlockType, not id
@property(copy) id retryOpenOperationBlock; // @synthesize retryOpenOperationBlock=_retryOpenOperationBlock;
@property BOOL hideWorkspaceLoadingProgressIndicator; // @synthesize hideWorkspaceLoadingProgressIndicator=_hideWorkspaceLoadingProgressIndicator;
@property(nonatomic) BOOL canRemoveSplit; // @synthesize canRemoveSplit=_canRemoveSplit;
@property(nonatomic) BOOL canAddSplit; // @synthesize canAddSplit=_canAddSplit;
@property(retain) IDEEditorMultipleContext *multipleContext; // @synthesize multipleContext=_multipleContext;
@property(copy) NSArray *validEditorCategories; // @synthesize validEditorCategories=_validEditorCategories;
@property(nonatomic) BOOL showSiblingStepperControl; // @synthesize showSiblingStepperControl=_showSiblingStepperControl;
@property(nonatomic) BOOL showRelatedItemsControl; // @synthesize showRelatedItemsControl=_showRelatedItemsControl;
@property(nonatomic) BOOL showNavBarHistoryStepperControls; // @synthesize showNavBarHistoryStepperControls=_showNavBarHistoryStepperControls;
@property(nonatomic) BOOL showSplittingControls; // @synthesize showSplittingControls=_showSplittingControls;
@property(nonatomic) BOOL showMiniIssueNavigator; // @synthesize showMiniIssueNavigator=_showMiniIssueNavigator;
@property(readonly) DVTScopeBarsManager *scopeBarsManager; // @synthesize scopeBarsManager=_scopeBarsManager;
@property(readonly) NSIndexSet *navigableItemSiblingsSelectionIndexes; // @synthesize navigableItemSiblingsSelectionIndexes=_navigableItemSiblingsSelectionIndexes;
@property(readonly) NSArray *navigableItemSiblings; // @synthesize navigableItemSiblings=_navigableItemSiblings;
@property(readonly) IDENavigableItemCoordinator *navigableItemCoordinator; // @synthesize navigableItemCoordinator=_navigableItemCoordinator;
@property(retain, nonatomic) IDENavigableItem *navigableItem; // @synthesize navigableItem=_navigableItem;
@property(readonly) IDENavigableItem *navBarNavigableItemRoot; // @synthesize navBarNavigableItemRoot=_navBarNavigableItemRoot;
@property(readonly) IDENavigableItem *navBarNavigableItem; // @synthesize navBarNavigableItem=_navBarNavigableItem;
@property(readonly) IDEEditorGeniusResults *editorGeniusResults; // @synthesize editorGeniusResults=_editorGeniusResults;
@property(retain, nonatomic) IDEEditor *editor; // @synthesize editor=_editor;
@property(retain, nonatomic) IDEEditorArea *editorArea; // @synthesize editorArea=_editorArea;
@property(readonly) NSString *documentExtensionIdentifier; // @synthesize documentExtensionIdentifier=_documentExtensionIdentifier;
@property(retain) id <IDEEditorContextDelegate> delegate; // @synthesize delegate=_delegate;
@property(copy) NSArray *defaultEditorCategories; // @synthesize defaultEditorCategories=_defaultEditorCategories;
@property(getter=isComparisonContext) BOOL comparisonContext; // @synthesize comparisonContext=_isComparisonContext;
@property(nonatomic) int borderSides; // @synthesize borderSides=_borderSides;
//- (void).cxx_destruct;
- (void)stateRepositoryDidChange:(id)arg1;
- (id)_navigableItemForEditingFromArchivedRepresentation:(id)arg1 error:(id *)arg2;
- (void)discardEditing;
- (BOOL)commitEditingForAction:(int)arg1 errors:(id)arg2;
- (id)scopeBarsManagerForEditor:(id)arg1;
- (void)goBackInHistoryByCommandWithShiftPlusAlternate:(id)arg1;
- (void)goForwardInHistoryByCommandWithShiftPlusAlternate:(id)arg1;
- (void)goBackInHistoryByCommandWithAlternate:(id)arg1;
- (void)goForwardInHistoryByCommandWithAlternate:(id)arg1;
- (void)goBackInHistoryByCommand:(id)arg1;
- (void)goForwardInHistoryByCommand:(id)arg1;
- (void)_setShowNavBarHistoryStepperControls:(BOOL)arg1;
- (void)_setShowRelatedItemsControl:(BOOL)arg1;
- (void)_rebuildRightControlGroup;
- (void)_rebuildLeftControlGroup;
- (void)updateWithHistoryStack:(id)arg1;
- (id)currentHistoryStack;
- (void)_openEditorHistoryItemFromStateSaving:(id)arg1;
- (void)_giveEditorFocusIfNeeded;
- (BOOL)_editorHasFocus;
- (BOOL)_findBarHasFocus;
- (BOOL)_viewHasFocus:(id)arg1;
- (void)takeFocus;
- (id)supplementalMainViewController;
- (BOOL)canBecomeMainViewController;
- (id)viewToShowWrapOrEndOfFileBezelOn:(id)arg1;
- (struct _NSRange)selectedRangeForFindBar:(id)arg1;
- (id)startingLocationForFindBar:(id)arg1 findingBackwards:(BOOL)arg2;
- (void)dvtFindBar:(id)arg1 didUpdateCurrentResult:(id)arg2;
- (void)dvtFindBar:(id)arg1 didUpdateResults:(id)arg2;
- (void)dismissFindBar:(id)arg1 andRestoreSelection:(BOOL)arg2;
- (void)hideFindBar:(id)arg1;
- (void)_hideFindBarAndRestoreSelection:(BOOL)arg1 animate:(BOOL)arg2;
- (void)replaceAndFindPrevious:(id)arg1;
- (void)replaceAndFindNext:(id)arg1;
- (void)replaceAll:(id)arg1;
- (void)replace:(id)arg1;
- (void)findPrevious:(id)arg1;
- (void)findNext:(id)arg1;
- (void)findAndReplace:(id)arg1;
- (void)find:(id)arg1;
- (void)_uninstallFindBar;
- (void)_installFindBar;
- (id)_findScopeBar;
- (id)_findBar;
- (BOOL)dvtFindBar:(id)arg1 validateUserInterfaceItem:(id)arg2;
@property(readonly) NSScrollView *scopeBarsAdjustableScrollView;
@property(readonly) NSView *scopeBarsBaseView;
- (void)primitiveInvalidate;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)_validateOpenInAdjacentEditorCommandForUserInterfaceItem:(id)arg1 forEventBehavior:(int)arg2;
- (void)showMiniIssuesNavigatorMenu:(id)arg1;
- (void)showDocumentItemsMenu:(id)arg1;
- (void)showGroupFilesMenu:(id)arg1;
- (void)showTopLevelItemsMenu:(id)arg1;
- (void)showNextFilesHistoryMenu:(id)arg1;
- (void)showNextHistoryMenu:(id)arg1;
- (void)showPreviousFilesHistoryMenu:(id)arg1;
- (void)showPreviousHistoryMenu:(id)arg1;
- (void)showRelatedItemsMenu:(id)arg1;
- (void)ide_unlockDocument:(id)arg1;
- (void)_popUpMenuForNavigableItem:(id)arg1;
- (void)closeDocument:(id)arg1;
- (BOOL)_canAskDocumentToClose;
- (void)openInAdjacentEditorWithShiftPlusAlternate:(id)arg1;
- (void)openInAdjacentEditorWithAlternate:(id)arg1;
- (void)_openInAdjacentEditorWithEventBehavior:(int)arg1;
- (void)scrollWheel:(id)arg1;
- (void)_moveOverlayToMatchGestureAmount:(double)arg1 imageOfCurrentEditorOnTop:(BOOL)arg2;
- (void)_hideSwipeOverlay;
- (BOOL)_showSwipeOverlayForDirection:(BOOL)arg1 imageOfCurrentEditorOnTop:(char *)arg2;
- (id)_imageOfCurrentEditor;
- (void)_preloadSwipeInfrastructure;
- (struct CGRect)_swipeLayerViewFrame;
- (BOOL)wantsScrollEventsForSwipeTrackingOnAxis:(long long)arg1;
- (void)swipeWithEvent:(id)arg1;
- (void)_swipeToGoForward:(BOOL)arg1;
- (void)jumpToInstructionPointer:(id)arg1;
- (void)fixPreviousIssue:(id)arg1;
- (void)fixNextIssue:(id)arg1;
- (void)jumpToPreviousIssue:(id)arg1;
- (void)jumpToNextIssue:(id)arg1;
- (void)jumpToPreviousCounterpartWithShiftPlusAlternate:(id)arg1;
- (void)jumpToPreviousCounterpartWithAlternate:(id)arg1;
- (void)jumpToPreviousCounterpart:(id)arg1;
- (void)jumpToNextCounterpartWithShiftPlusAlternate:(id)arg1;
- (void)jumpToNextCounterpartWithAlternate:(id)arg1;
- (void)jumpToNextCounterpart:(id)arg1;
- (void)_jumpToCounterpartUp:(BOOL)arg1;
- (BOOL)pathControl:(id)arg1 acceptDrop:(id)arg2;
- (unsigned long long)pathControl:(id)arg1 validateDrop:(id)arg2;
- (id)pathControlPasteboardReadingOptions;
- (unsigned long long)draggingSourceOperationMaskForLocal:(BOOL)arg1;
- (void)pathCell:(id)arg1 didEndDragForComponentCell:(id)arg2;
- (BOOL)pathCell:(id)arg1 beginDragForComponentCell:(id)arg2;
- (id)pathCell:(id)arg1 menuItemForNavigableItem:(id)arg2 defaultMenuItem:(id)arg3;
- (BOOL)pathCell:(id)arg1 shouldEnableSelection:(id)arg2;
- (id)pathCell:(id)arg1 childItemsForItem:(id)arg2;
- (void)pathCell:(id)arg1 didUpdateMenu:(id)arg2;
- (id)_hiddenMenuItemForCommandExtension:(id)arg1;
- (BOOL)pathCell:(id)arg1 shouldInitiallyShowMenuSearch:(id)arg2;
- (BOOL)pathCell:(id)arg1 shouldSeparateDisplayOfChildItemsForItem:(id)arg2;
- (void)_currentSelectedItemsChanged;
- (void)_checkShouldCoalesceUpdatesForCurrentSelectedItemsChanged;
- (BOOL)_isCurrentEventARepeatKeyDownEvent;
- (void)_updateSubDocumentNavigableItems;
- (void)_selectNavigableItem:(id)arg1 updateOutputSelection:(id)arg2;
- (void)removeSplitForSplittingController:(id)arg1;
- (void)addSplitForSplittingController:(id)arg1;
- (void)setEmptyContentString:(id)arg1;
- (struct CGRect)grabRect;
- (void)_setSupportsReadOnlyIndicator:(BOOL)arg1;
- (void)_setCanRemoveSplit:(BOOL)arg1;
- (void)_setCanAddSplit:(BOOL)arg1;
- (void)_setShowSplittingControls:(BOOL)arg1;
- (void)_setShowMiniIssueNavigator:(BOOL)arg1;
- (void)_setShowSiblingStepperControl:(BOOL)arg1;
- (void)_updateSiblingStepperControlVisibility;
- (void)menuNeedsUpdate:(id)arg1;
- (void)_clearRecentEditorDocumentsList:(id)arg1;
- (void)_changeMaximumRecentFilesLimit:(id)arg1;
- (id)_recentEditorDocumentsCapacityPreferenceMenuItem;
- (void)_navigateToRelatedNavigableItem:(id)arg1;
- (void)setNavigableItemSiblingsSelectionIndexes:(NSIndexSet *)arg1;
- (void)_importNavigableItem:(id)arg1;
- (BOOL)_notifyDelegateAndOpenEditorHistoryItem:(id)arg1 previousHistoryItemOrNil:(id)arg2 skipSubDocumentNavigationUnlessEditorIsReplaced:(BOOL)arg3;
- (BOOL)_notifyDelegateAndOpenEditorHistoryItem:(id)arg1 updateHistory:(BOOL)arg2 skipSubDocumentNavigationUnlessEditorIsReplaced:(BOOL)arg3;
- (BOOL)_notifyDelegateAndOpenEditorOpenSpecifier:(id)arg1 updateHistory:(BOOL)arg2;
- (BOOL)_notifyDelegateAndOpenNavigableItem:(id)arg1 withContentsURL:(id)arg2 documentExtensionIdentifier:(id)arg3 locationToSelect:(id)arg4 annotationRepresentedObject:(id)arg5 stateDictionary:(id)arg6 annotationWantsIndicatorAnimation:(BOOL)arg7 exploreAnnotationRepresentedObject:(id)arg8 highlightSelection:(BOOL)arg9 skipSubDocumentNavigationUnlessEditorIsReplaced:(BOOL)arg10;
- (BOOL)_canEditEditorHistoryItem:(id)arg1;
- (BOOL)_canEditEditorOpenSpecifier:(id)arg1;
- (BOOL)_canEditEditorOpenSpecifier:(id)arg1 withEditorCategories:(id)arg2;
- (void)_applyEditorStateDictionary:(id)arg1 forDocumentExtensionIdentifier:(id)arg2 atDocumentURLToCurrentEditor:(id)arg3;
// pared result: CDUnknownBlockType, not id
- (int)_openNavigableItem:(id)arg1 documentExtension:(id)arg2 document:(id)arg3 shouldInstallEditorBlock:(id)arg4;
// pared result: CDUnknownBlockType, not id
- (int)_openNavigableItem:(id)arg1 withContentsOfURL:(id)arg2 documentExtension:(id)arg3 shouldInstallEditorBlock:(id)arg4;
- (id)_newEditorDocumentWithClass:(Class)arg1 forURL:(id)arg2 withContentsOfURL:(id)arg3 ofType:(id)arg4 extension:(id)arg5 error:(id *)arg6;
// pared result: CDUnknownBlockType, not id
- (int)_openNavigableItem:(id)arg1 withContentsOfURL:(id)arg2 shouldInstallEditorBlock:(id)arg3;
- (id)_defaultDocumentExtensionForNavigableItem:(id)arg1;
- (void)_navigateAwayFromCurrentDocumentWithURL:(id)arg1;
- (BOOL)openEditorHistoryItem:(id)arg1;
- (BOOL)openEditorOpenSpecifier:(id)arg1;
- (BOOL)_openEditorOpenSpecifier:(id)arg1 updateHistory:(BOOL)arg2;
- (BOOL)_openEditorHistoryItem:(id)arg1 previousHistoryItemOrNil:(id)arg2 skipSubDocumentNavigationUnlessEditorIsReplaced:(BOOL)arg3;
- (void)_navigableItemChanged;
- (BOOL)_openEditorHistoryItem:(id)arg1 updateHistory:(BOOL)arg2;
- (BOOL)_openEmptyEditor;
- (void)_teardownDocumentNotifications;
- (void)_registerForDocumentNotificationsForDocument:(id)arg1;
- (void)_updateNavBarNavigableItemForNavItem:(id)arg1;
- (void)_setEmptyRootNavigableItem;
- (void)_clearWorkspaceloadingObservation;
- (void)_primitiveSetNavBarRootNavigableItem:(id)arg1 selectedNavigableItem:(id)arg2;
- (void)setNavBarNavigableItem:(IDENavigableItem *)arg1;
- (id)currentHistoryItemWithImageOfCurrentEditor;
- (id)currentHistoryItem;
- (id)_currentSelectedDocumentLocations;
- (void)_updateSiblingInfoFromNavigableItem;
// pared result: CDUnknownBlockType, not id
- (void)_performBlockInsideReentrantGuard:(id)arg1;
- (BOOL)_canChangeNavigableItem;
- (void)setupNewEditor:(id)arg1;
- (void)_mainViewControllerChanged;
- (void)_syncGradientStyleForJumpBarControls;
@property(readonly, getter=isPrimaryEditorContext) BOOL primaryEditorContext;
- (BOOL)isLastActiveEditorContext;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (BOOL)_enableJumpToCounterpartMenuItems;
- (id)_jumpToCounterpartsCategoryNavigableItem;
- (void)_setEditorGeniusResultsGenerationEnabled:(BOOL)arg1;
- (BOOL)_editorGeniusResultsGenerationEnabled;
- (void)_writeCurrentStateToLastUsedDictionaryIfNeeded;
- (id)_defaultEditorStateDictionaryForDocumentExtensionIdentifier:(id)arg1 forDocumentURL:(id)arg2;
- (id)navigableItemCoordinator:(id)arg1 editorDocumentForNavigableItem:(id)arg2;
- (void)_greatestDocumentAncestorWasForgotten;
- (id)willPresentError:(id)arg1;
- (BOOL)presentError:(id)arg1;
- (void)presentError:(id)arg1 modalForWindow:(id)arg2 delegate:(id)arg3 didPresentSelector:(SEL)arg4 contextInfo:(void *)arg5;
- (id)workspace;
- (void)loadView;
- (void)_setEditorView;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (void)_adjustSubviewBorders;
- (void)setGreatestDocumentAncestor:(id)arg1;
- (id)greatestDocumentAncestor;
- (id)navBarNavigableItemRootChildItems;
- (id)_generateNodeAndAddMappingToWorkspaceTabControllerLayoutTree:(id)arg1;

@end