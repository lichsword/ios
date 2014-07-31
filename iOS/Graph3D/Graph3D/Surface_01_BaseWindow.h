//
//  BaseWindowSurface.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_01_BaseWindow__
#define __Graph3D__Surface_01_BaseWindow__

#include <iostream>
#include "Surface.h"

class BaseWindowSurface : public Surface{
private:
    char buffer[256];
public:
    virtual void onStart();
    virtual void display();
};

#endif /* defined(__Graph3D__Surface_01_BaseWindow__) */
