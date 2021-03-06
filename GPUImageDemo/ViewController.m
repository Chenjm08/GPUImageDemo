//
//  ViewController.m
//  GPUImageDemo
//
//  Created by jiemin on 14-6-19.
//  Copyright (c) 2014年 lion. All rights reserved.
//

#import "ViewController.h"
#import "GPUImage.h"
#import "JMGeometry.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    UIImage *inputImage = [UIImage imageNamed:@"4.jpg"];

    GPUImageBrightnessFilter *filter = [[GPUImageBrightnessFilter alloc] init];
    filter.brightness = -0.5;
    
    [filter forceProcessingAtSize:inputImage.size];
    
    [filter useNextFrameForImageCapture];
    
    GPUImagePicture *stillImageSource = [[GPUImagePicture alloc] initWithImage:inputImage];
    
    [stillImageSource addTarget:filter];
    
    [stillImageSource processImage];
    
    UIImage *nearestNeighborImage = [filter imageFromCurrentFramebuffer];

}

- (void)initScroll
{
    _scroll = ({
        UIScrollView *scroll = [[UIScrollView alloc] initWithFrame:JMRectMakeBottom(0, 480-50, 320, 50)];
        [self.view addSubview:scroll];
        scroll.backgroundColor = [UIColor colorWithWhite:1 alpha:0.4];
        scroll;
    });
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
