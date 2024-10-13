#import <Cocoa/Cocoa.h>

// Compile: clang -framework AppKit -o simple_window simple_window.m
// Run: ./simple_window

// AppDelegate interface declaration
// Conforms to NSApplicationDelegate for application lifecycle management
// and NSWindowDelegate for window-related events
@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
@property(strong, nonatomic) NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Create the window
    self.window = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, 300, 200)
                                              styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable
                                                backing:NSBackingStoreBuffered
                                                  defer:NO];
    // Make the window visible and bring it to the front
    [self.window makeKeyAndOrderFront:nil];

    // Set the window delegate to self (AppDelegate)
    // This allows us to respond to window-related events
    [self.window setDelegate:self];

    // Create the button
    NSButton *button = [[NSButton alloc] initWithFrame:NSMakeRect(100, 80, 100, 40)];
    [button setTitle:@"Click Me"];
    [button setBezelStyle:NSBezelStyleRounded];
    [button setTarget:self];
    [button setAction:@selector(buttonClicked:)];

    // Add the button to the window's content view
    [[self.window contentView] addSubview:button];
}

// Method called when the button is clicked
- (void)buttonClicked:(id)sender
{
    // Create and configure an alert (message box)
    NSAlert *alert = [[NSAlert alloc] init];
    [alert setMessageText:@"Hello, World!"];
    [alert setInformativeText:@"You clicked the button!"];
    [alert addButtonWithTitle:@"OK"];

    // Display the alert as a modal dialog
    [alert runModal];
}

// Window delegate method called when the window is about to close
- (void)windowWillClose:(NSNotification *)notification
{
    // Terminate the application when the window is closed
    [NSApp terminate:self];
}

@end

// Main function - entry point of the application
int main(int argc, const char *argv[])
{
    @autoreleasepool
    {
        // Create the application instance
        NSApplication *application = [NSApplication sharedApplication];

        // Create an instance of our AppDelegate
        AppDelegate *delegate = [[AppDelegate alloc] init];

        // Set the application's delegate
        [application setDelegate:delegate];

        // Start the application's run loop
        [application run];
    }
    return 0;
}