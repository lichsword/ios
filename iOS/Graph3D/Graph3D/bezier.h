    //
    //  bezier.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-3.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__bezier__
#define __Graph3D__bezier__

#include <iostream>
    //OpenGL 头文件
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/Glut.h>

class Point3D{
public:
    GLdouble x;
    GLdouble y;
    GLdouble z;
public:
    Point3D(){
        x = 0;
        y = 0;
        z = 0;
    }
};

class BezierPatch{
    
public:
    Point3D anchors[4][4];// 4*4的网格点
    GLuint dlBPatch;// 绘制片面的显示列表名称
    GLuint texture;// 面片的纹理
public:
    BezierPatch(){
            // 生成纹理对象索引,赋值给变量
        glGenTextures(1, &texture);
    }
    
    ~BezierPatch(){
            // 释放纹理对象
        glDeleteTextures(1, &texture);
    }
};

void makePoint(Point3D * point3d, GLdouble x, GLdouble y, GLdouble z);

/**
 * 两个向量相加
 * point3d_a = point3d_a + point3d_b;
 */
void point3dAdd(Point3D * point3d_a, Point3D * point3d_b);

/**
 * 向量与标量相乘
 */
void point3dTimes(Point3D * point3d, GLdouble c);

/**
 * 计算bezier方程，得到插值点
 */
void bezierCount(Point3D * point3d, float u, Point3D * point3dList);

/**
 * 生成bezier曲面的显示列表
 */
GLuint genBezier(BezierPatch * patch, int divs);

/**
 * 初始化bezier曲面
 */
void initBezier(BezierPatch * bezier);

#endif /* defined(__Graph3D__bezier__) */