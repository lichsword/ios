//
//  SurfaceView.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-16.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__SurfaceView__
#define __Graph3D__SurfaceView__

#include <iostream>
    //OpenGL 头文件
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/Glut.h>
    //STL 头文件
#include <vector>
#include <string>
#include <math.h>
    //STL异常类
#include <stdexcept>

namespace surfaceview {
    using std::vector;
    using std::string;
    
    struct surfaceview_data{

        void init();
        
        void display();

    };
}
#endif /* defined(__Graph3D__SurfaceView__) */
