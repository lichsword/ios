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
#include <math.h>
    //STL异常类
#include <stdexcept>

class Surface{
protected:
        // 设置投影矩阵
    void setProjection();
public:
    virtual void onStart();
    virtual void display();
    virtual void keyboard(unsigned char key, int x, int y);
    virtual void onMotion(int x, int y);
    virtual void onMouseEvent(int button, int state, int x, int y);
};

#endif /* defined(__Graph3D__SurfaceView__) */
