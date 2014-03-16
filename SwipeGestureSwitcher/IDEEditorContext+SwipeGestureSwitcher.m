//
//  IDEEditorContext+SwipeGestureSwitcher.m
//  SwipeGestureSwitcher
//
//  Created by Yin Tan on 3/16/14.
//  Copyright (c) 2014 Yin Tan. All rights reserved.
//

#import "IDEEditorContext+SwipeGestureSwitcher.h"
#import "NSObject+Swizzle.h"
#import "SwipeGestureSwitcher.h"

@implementation IDEEditorContext (SwipeGestureSwitcher)

+ (void)load
{
    [self _sgs_swizzleInstanceMethod:@selector(wantsScrollEventsForSwipeTrackingOnAxis:)
                       withNewMethod:@selector(_sgs_wantsScrollEventsForSwipeTrackingOnAxis:)];
}

- (BOOL)_sgs_wantsScrollEventsForSwipeTrackingOnAxis:(long long)arg
{
    BOOL gestureEnabled = [[NSUserDefaults standardUserDefaults] boolForKey:kSwipeGestureEnabledStateKey];
    return gestureEnabled ? [self _sgs_wantsScrollEventsForSwipeTrackingOnAxis:arg] : NO;
}

@end
