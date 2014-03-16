//
//  SwipeGestureSwitcher.m
//  SwipeGestureSwitcher
//
//  Created by Yin Tan on 3/16/14.
//  Copyright (c) 2014 Yin Tan. All rights reserved.
//

#import "SwipeGestureSwitcher.h"

#define kSWSMenuTitleEnable @"Enable Swipe Gesture"
#define kSWSMenuTitleDisable @"Disable Swipe Gesture"

@implementation SwipeGestureSwitcher

+ (void)pluginDidLoad:(NSBundle *)plugin
{
    static dispatch_once_t once;
    static id instance = nil;
    dispatch_once(&once, ^{
        instance = [[self alloc] init];
    });
}

- (instancetype)init
{
    if (self = [super init]) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(applicationDidFinishLaunching:)
                                                     name:NSApplicationDidFinishLaunchingNotification
                                                   object:nil];
        NSDictionary *defaults = @{kSwipeGestureEnabledStateKey: @YES};
        [[NSUserDefaults standardUserDefaults] registerDefaults:defaults];
    }
    return self;
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
    [self addMenu];
}

- (void)addMenu
{
    NSMenuItem *naviItem = [[NSApp mainMenu] itemWithTitle:@"View"];
    if (naviItem) {
        [[naviItem submenu] addItem:[NSMenuItem separatorItem]];

        BOOL gestureEnabled = [[NSUserDefaults standardUserDefaults] boolForKey:kSwipeGestureEnabledStateKey];
        NSString *title = gestureEnabled ? kSWSMenuTitleDisable : kSWSMenuTitleEnable;
        NSMenuItem *swipeSwitcherItem = [[NSMenuItem alloc] initWithTitle:title
                                                                   action:@selector(toggleSwipeGesture:)
                                                            keyEquivalent:@""];
        [swipeSwitcherItem setTarget:self];
        [[naviItem submenu] addItem:swipeSwitcherItem];
    }
}

- (void)toggleSwipeGesture:(id)sender
{
    BOOL gestureEnabled = [[NSUserDefaults standardUserDefaults] boolForKey:kSwipeGestureEnabledStateKey];
    gestureEnabled = !gestureEnabled;
    [[NSUserDefaults standardUserDefaults] setBool:gestureEnabled forKey:kSwipeGestureEnabledStateKey];

    NSMenuItem *item = (NSMenuItem *)sender;
    if (gestureEnabled) {
        item.title = kSWSMenuTitleDisable;
    } else {
        item.title = kSWSMenuTitleEnable;
    }
}

@end
