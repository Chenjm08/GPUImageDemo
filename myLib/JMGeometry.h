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
#define SCREEN_SIZE    [[UIScreen mainScreen] bounds].size
#define SCREEN_WIDTH   [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT  [[UIScreen mainScreen] bounds].size.height

#define SCREEN_RATE     SCREEN_WIDTH / 320.0
#define IS_PAD          ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define IS_IPHONE       ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#define IS_IPHONE4      CGSizeEqualToSize(320, 480)
#define IS_IPHONE5      CGSizeEqualToSize(320, 568)


CG_INLINE CGRect JMRectMakeTop(CGFloat x, CGFloat y, CGFloat w, CGFloat h)
{
    CGRect rect = CGRectMake(x * SCREEN_RATE, y * SCREEN_RATE, w * SCREEN_RATE, h * SCREEN_RATE);
    
    return rect;
}

CG_INLINE CGRect JMRectMakeBottom(CGFloat x, CGFloat y, CGFloat w, CGFloat h)
{
    CGRect rect = CGRectMake(x * SCREEN_RATE,
                             SCREEN_HEIGHT - (480 - x - h) * SCREEN_RATE,
                             w * SCREEN_RATE,
                             h *
                             SCREEN_RATE);
    return rect;
}

CG_INLINE CGSize JMScaleInnerSize(CGSize innerSize, CGSize outerSize)
{
    assert(innerSize.width > 0.01);
    assert(innerSize.height > 0.01);
    assert(outerSize.width > 0.01);
    assert(outerSize.height > 0.01);
    
    CGFloat innerRate = innerSize.width / innerSize.height;
    CGFloat outerRate = outerSize.width / outerSize.height;
    CGSize landscapeSize = CGSizeMake(outerSize.width, outerSize.height * innerRate);
    CGSize portaitSize = CGSizeMake(outerSize.height / innerRate, outerSize.height);
    CGSize newSize = (innerRate > outerRate) ? landscapeSize : portaitSize;

    return newSize;
}

CG_INLINE CGSize JMScaleOuterSize(CGSize outerSize, CGSize innerSize)
{
    assert(innerSize.width > 0.01);
    assert(innerSize.height > 0.01);
    assert(outerSize.width > 0.01);
    assert(outerSize.height > 0.01);
    
    CGFloat innerRate = innerSize.width / innerSize.height;
    CGFloat outerRate = outerSize.width / outerSize.height;
    CGSize landscapeSize = CGSizeMake(outerSize.width, outerSize.height * outerRate);
    CGSize portaitSize = CGSizeMake(outerSize.height / outerRate, outerSize.height);
    CGSize newSize = (innerRate > outerRate) ? landscapeSize : portaitSize;
    
    return newSize;
}

#endif
