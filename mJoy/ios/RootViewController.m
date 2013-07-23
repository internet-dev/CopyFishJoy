//
//  mJoyAppController.h
//  mJoy
//
//  Created by Jerry Yang on 7/8/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#import "RootViewController.h"


@implementation RootViewController

/*
 // The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil])) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/

/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
}
 
*/
// Override to allow orientations other than the default portrait orientation.
// This method is deprecated on ios6
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return UIInterfaceOrientationIsLandscape( interfaceOrientation );
}

// For ios6, use supportedInterfaceOrientations & shouldAutorotate instead
- (NSUInteger) supportedInterfaceOrientations{
#ifdef __IPHONE_6_0
    return UIInterfaceOrientationMaskLandscape;
#endif
}

- (BOOL) shouldAutorotate {
    return YES;
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

/**
- (void)viewDidLoad {
    [super viewDidLoad];

    // 在屏幕底部创建标准尺寸的视图。
    bannerView_ = [[GADBannerView alloc]
                   initWithFrame:CGRectMake(768.0,
                                            //self.view.frame.size.height -
                                            //GAD_SIZE_320x50.height,
                                            350.0,
                                            GAD_SIZE_320x50.width,
                                            GAD_SIZE_320x50.height)];

    // 指定广告的“单元标识符”，也就是您的 AdMob 发布商 ID。
    bannerView_.adUnitID = @"a151e55ea6b6b8b";

    // 告知运行时文件，在将用户转至广告的展示位置之后恢复哪个 UIViewController
    // 并将其添加至视图层级结构。
    bannerView_.rootViewController = self;
    [self.view addSubview:bannerView_];

    // 启动一般性请求并在其中加载广告。
    [bannerView_ loadRequest:[GADRequest request]];
    NSLog(@"google admob: a151e55ea6b6b8b");
}
*/

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;

    //[bannerView_ release];
}


- (void)dealloc {
    [super dealloc];
}


@end
