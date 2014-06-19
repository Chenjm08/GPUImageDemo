//
//  JMGeometry.h
//  GPUImageDemo
//
//  Created by jiemin on 14-6-19.
//  Copyright (c) 2014年 lion. All rights reserved.
//

#ifndef GPUImageDemo_JMGeometry_h
#define GPUImageDemo_JMGeometry_h

#define SCREEN_BOUNDS  [[UIScreen mainScreen] bounds]
#define SCREEN_SIZE   [[UIScreen mainScreen] bounds].size
#define SCREEN_WIDTH  [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT 

#define SCREEN_RATE SCREEN_WIDTH / 320.0
#define IS_PAD ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define IS_IPHONE ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#define IS_IPHONE4 (IS_IPHONE && abs(SCREEN_HEIGHT - 480.0) == 0)
#define IS_IPHONE5 (IS_IPHONE && abs(SCREEN_HEIGHT - 568.0) == 0)


CG_INLINE CGRect CGRectMakeTop(CGFloat x, CGFloat y, CGFloat w, CGFloat h)
{
    CGRect rect = CGRectMake(x * SCREEN_RATE, y, w * SCREEN_RATE, h * SCREEN_RATE);
    
    return rect;
}

CG_INLINE CGRect CGRectMakeTopY(CGFloat x, CGFloat y, CGFloat w, CGFloat h)
{
    CGRect rect = CGRectMake(x * SCREEN_RATE, y * SCREEN_RATE, w * SCREEN_RATE, h * SCREEN_RATE);
    
    return rect;
}






#endif
