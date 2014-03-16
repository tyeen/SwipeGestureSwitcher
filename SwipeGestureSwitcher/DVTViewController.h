@class DVTExtension, DVTStackBacktrace;
@class DVTControllerContentView;

@protocol DVTControllerContentViewViewControllerAdditions
- (void)_willUninstallContentView:(DVTControllerContentView *)arg1;
- (void)_didInstallContentView:(DVTControllerContentView *)arg1;
@end

@protocol DVTEditor <NSObject>
- (void)discardEditing;
- (BOOL)commitEditingForAction:(int)arg1 errors:(NSMutableArray *)arg2;
@end

@protocol DVTInvalidation <NSObject>
- (void)primitiveInvalidate;

@optional
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly, nonatomic, getter=isValid) BOOL valid;
- (void)invalidate;
@end

@interface DVTViewController : NSViewController <DVTControllerContentViewViewControllerAdditions, DVTEditor, DVTInvalidation>
{
  DVTExtension *_representedExtension;
  BOOL _isViewLoaded;
  BOOL _didCallViewWillUninstall;
  void *_keepSelfAliveUntilCancellationRef;
}

+ (id)defaultViewNibBundle;
+ (id)defaultViewNibName;
+ (void)initialize;
@property(retain, nonatomic) DVTExtension *representedExtension; // @synthesize representedExtension=_representedExtension;
@property BOOL isViewLoaded; // @synthesize isViewLoaded=_isViewLoaded;
//- (void).cxx_destruct;
- (void)primitiveInvalidate;
- (void)invalidate;
- (BOOL)commitEditingForAction:(int)arg1 errors:(id)arg2;
- (void)_willUninstallContentView:(id)arg1;
- (void)_didInstallContentView:(id)arg1;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (void)loadView;
- (void)setView:(id)arg1;
- (void)separateKeyViewLoops;
- (BOOL)delegateFirstResponder;
- (id)supplementalMainViewController;
- (id)description;
- (BOOL)becomeFirstResponder;
- (id)view;
- (id)initWithCoder:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initUsingDefaultNib;
- (void)dvtViewController_commonInit;
@property(readonly) BOOL canBecomeMainViewController;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(copy, nonatomic) NSString *title; // @dynamic title;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end