//
//  loaderViewController.h
//  AppDeck
//
//  Created by Mathieu De Kermadec on 15/12/12.
//  Copyright (c) 2012 Mathieu De Kermadec. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDeck.h"
#import "LogViewController.h"

typedef enum LoaderPopUp: int {
    //    AdManagerEventError = -1,
    LoaderPopUpDefault = 0,
    LoaderPopUpYes = 1,
    LoaderPopUpNo = 2
} LoaderPopUp;

typedef enum AdManagerEvent: int {
    //    AdManagerEventError = -1,
    AdManagerEventNone = 0,
    AdManagerEventPush = 1,
    AdManagerEventPop = 2,
    AdManagerEventSwipe = 3,
    AdManagerEventRoot = 4,
    AdManagerEventLaunch = 5,
    AdManagerEventPopUp = 6,
    AdManagerEventWakeUp = 7
} AdManagerEvent;

//@class AppDelegate;
@class PageViewController;
@class ScreenConfiguration;
@class AppDeck;
@class EmbedResources;
@class RemoteAppCache;
@class MenuViewController;
@class ECSlidingViewController;
@class LoaderChildViewController;
@class LoaderConfiguration;
@class MobclixFullScreenAdViewController;
@class AdManager;
@class JSonHTTPApi;
@class LoaderNavigationController;
@protocol GAITracker;

@interface LoaderViewController : UIViewController <UIWebViewDelegate, UINavigationControllerDelegate, AppDeckApiCallDelegate, UIGestureRecognizerDelegate>
{
    LoaderNavigationController* navController;
    UINavigationController* popUp;
    
    UIViewController    *centerController;
    MenuViewController    *leftController;
    MenuViewController    *rightController;
    
    UIImageView         *backgroundImageView;
    UIActivityIndicatorView      *loadingView;

    UIView *statusBarInfo;
    
    BOOL appIsBusy;
    
    RemoteAppCache *remoteAppCache;
    
    BOOL mobiclickIsInit;
    
    BOOL    pushNotificationRegistered;
    
    EmbedResources *embed_compilation;
    EmbedResources *embed_runtime;
    
    UIView *fakeStatusBar;
    
    NSTimer *debug_timer;
    JSonHTTPApi *debugJson;
    
    JSonHTTPApi *appJson;
    
    UIView *overlay;
}

@property (nonatomic) AppDeck *appDeck;

@property (strong, nonatomic) LoaderConfiguration *conf;

@property (strong, nonatomic) AdManager *adManager;

@property (strong, nonatomic) NSString *appLogoUrl;

@property (strong, nonatomic) NSURL *jsonUrl;
//@property (strong, nonatomic) NSURL *url;

@property (assign, nonatomic) BOOL appIsBusy;

@property (assign, nonatomic) BOOL syncEmbedResource;

@property (assign, nonatomic) float width;
@property (assign, nonatomic) float height;

@property (strong, nonatomic) ECSlidingViewController *slidingViewController;

@property (strong, nonatomic) NSDictionary *launchOptions;

@property (strong, nonatomic) LogViewController *log;

@property (assign, nonatomic) BOOL forceStatusBarHidden;

@property (assign, nonatomic) BOOL leftMenuOpen;
@property (assign, nonatomic) BOOL rightMenuOpen;


@property (assign, nonatomic) BOOL appRunInBackground;

/*
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t backgroundQueue; // this is for Xcode 4.5 with LLVM 4.1 and iOS 6 SDK
#else
@property (nonatomic, assign) dispatch_queue_t backgroundQueue; // this is for older Xcodes with older SDKs
#endif
*/

//@property (strong, nonatomic) LoaderChildViewController *currentPage;

//-(LoaderChildViewController *)loadPage:(NSString *)pageUrlString root:(BOOL)root forcePopup:(BOOL)forcePopup;
-(LoaderChildViewController *)loadPage:(NSString *)pageUrlString root:(BOOL)root popup:(LoaderPopUp)popup;
-(LoaderChildViewController *)loadRootPage:(NSString *)pageUrlString;
-(LoaderChildViewController *)loadPage:(NSString *)pageUrlString;
-(LoaderChildViewController *)loadChild:(LoaderChildViewController *)page root:(BOOL)root popup:(LoaderPopUp)popup;

-(LoaderChildViewController *)getCurrentChild;

-(void)closePopUp:(id)origin;

-(void)showStatusBarError:(NSString *)message;
-(void)showStatusBarNotice:(NSString *)message;

@property(nonatomic, retain) id<GAITracker> tracker;
@property(nonatomic, retain) id<GAITracker> globalTracker;

//-(void)loadAppWithURL:(NSString *)base_url andConf:(NSString *)conf_url;

-(LoaderChildViewController *)getChildViewControllerFromURL:(NSString *)pageUrlString type:(NSString *)type;

-(void)setFullScreen:(BOOL)fullScreen animation:(UIStatusBarAnimation)animation;

-(void)loadConf;

-(BOOL)apiCall:(AppDeckApiCall *)call;

- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken;
- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

- (void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

@end
