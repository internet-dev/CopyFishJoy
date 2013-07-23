//
//  mJoyAppController.h
//  mJoy
//
//  Created by Jerry Yang on 7/8/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

@class RootViewController;
#import "GADBannerView.h"

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate, UIApplicationDelegate, GADBannerViewDelegate> {
    UIWindow *window;
    RootViewController    *viewController;

    GADBannerView* bannerView_;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

