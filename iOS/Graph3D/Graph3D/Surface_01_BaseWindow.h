//
//  BaseWindowSurface.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__BaseWindowSurface__
#define __Graph3D__BaseWindowSurface__

#include <iostream>
#include "Surface.h"

class BaseWindowSurface : public Surface{
public:
    virtual void display();
};

#endif /* defined(__Graph3D__BaseWindowSurface__) */