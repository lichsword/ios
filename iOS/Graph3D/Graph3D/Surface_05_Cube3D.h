//
//  Surface_05_3D.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-24.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_05_3D__
#define __Graph3D__Surface_05_3D__

#include <iostream>
#include "Surface.h"

class Cube3DSurface : public Surface{
private:
    GLfloat rotTri;// 三棱锥的旋转量
    GLfloat rotCube;// 立方体的旋转量
    GLfloat rotComX;// 共用的x轴的旋转量
public:
    virtual void onStart();
    virtual void display();
};

#endif /* defined(__Graph3D__Surface_05_3D__) */
