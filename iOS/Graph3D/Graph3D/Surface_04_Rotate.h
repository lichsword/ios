//
//  Surface_03_Rotate.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_04_Rotate__
#define __Graph3D__Surface_04_Rotate__

#include <iostream>
#include "Surface.h"

class RotateSurface : public Surface{
public:
    virtual void onStart();
    virtual void display();
};

#endif /* defined(__Graph3D__Surface_04_Rotate__) */