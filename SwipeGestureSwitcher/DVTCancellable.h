@protocol DVTCancellable <NSObject>
@property(readonly, getter=isCancelled) BOOL cancelled;
- (void)cancel;
@end