//
//  FakeBannerAdViewController.h
//  AppDeck
//
//  Created by Mathieu De Kermadec on 05/11/2013.
//  Copyright (c) 2013 Mathieu De Kermadec. All rights reserved.
//

#import "../../AppDeckAdViewController.h"
#import "../../JSonHTTPApi.h"
#import "HTMLChunkAdEngine.h"
#import "../../ManagedUIWebViewController.h"

@interface HTMLChunkAdViewController : AppDeckAdViewController <ManagedUIWebViewDelegate, AppDeckApiCallDelegate>
{
    NSTimer *timer; // for interticial
    
    UIImageView *close; // allow close of ad
    
    ManagedUIWebViewController  *contentCtl;
}
@property (nonatomic, strong)   HTMLChunkAdEngine *adEngine;
//@property (nonatomic, strong)   UIImageView *imageView;

@property (nonatomic, strong)   NSString *code;
@property (nonatomic, strong)   NSString *passbackable;

- (id)initWithAdRation:(AdRation *)adRation engine:(HTMLChunkAdEngine *)adEngine config:(NSDictionary *)config;

//- (void)adTapped:(UIGestureRecognizer *)gestureRecognizer;

@end
