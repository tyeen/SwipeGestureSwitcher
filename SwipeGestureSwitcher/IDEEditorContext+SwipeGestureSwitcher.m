//
//  IDEEditorContext+SwipeGestureSwitcher.m
//  SwipeGestureSwitcher
//
//  Created by Yin Tan on 3/16/14.
//  Copyright (c) 2014 Yin Tan. All rights reserved.
//

#import "IDEEditorContext+SwipeGestureSwitcher.h"
#import "NSObject+Swizzle.h"

@implementation IDEEditorContext (SwipeGestureSwitcher)

+ (void)load
{
    NSLog(@"loaded.");
    [self _sgs_swizzleInstanceMethod:@selector(wantsScrollEventsForSwipeTrackingOnAxis:)
                       withNewMethod:@selector(_sgs_wantsScrollEventsForSwipeTrackingOnAxis:)];
}

- (BOOL)_sgs_wantsScrollEventsForSwipeTrackingOnAxis:(long long)arg
{
    return NO;
}

@end
