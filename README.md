### What is this
Annoyed by Xcode's "swipe to navigate to previous/next file" gesture when using trackpad, while what
you're trying to do is just to scroll the source?

Well, you can turn it off by setting:

    System Preferences -> Trackpad -> More Gestures -> Swipe between pages

But, how about using Safari while coding? Do you prefer to turning the System Preferences off when
coding in Xcode and then turning it on before switching to Safari and then turning it off again to
go back to Xcode?

If that bothered you, you may try this plug-in.
This plug-in adds a menu item to the `View` menu and gives you the control to turn that gesture on or off.

![](https://raw.github.com/tyeen/SwipeGestureSwitcher/master/screenshot.png)

It doesn't do anything else but just try to disable the swipe gesture. So the file's browsing
history is still there. You can use the default navigating shortcut (`cmd`+`ctrl`+`←` and
`cmd`+`ctrl`+`→`, which you can find in the `Navigate` menu) or use the left/right arrow in
navigation bar to perform the navigation.

> This plug-in is built under OS X 10.9.2 & Xcode 5.1. I haven't tested it on other versions.
But it should work:)

### Installation
* Download the source and open it in Xcode.
* Build it(`cmd` + `B`) and restart Xcode.
* A new menu item should be in the "View" menu.

The gesture is enabled by default. So the menu item should look like "Disable Swipe Gesture".

### Uninstallation
Just delete the bundle with the name of `SwipeGestureSwitcher.xcplugin` in

    ~/Library/Application Support/Developer/Shared/Xcode/Plug-ins

This plug-in also added a new key-value pair with the name of `com.tyeen.xcplugin.swipegestureswitcher.enabled` to

    ~/Library/Preferences/com.apple.dt.Xcode.plist

It won't effect anything, but for uninstalling clearly, you may want to remove it, too.
