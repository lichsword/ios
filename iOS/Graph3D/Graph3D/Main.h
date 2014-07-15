//
//  Main.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-12.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Main__
#define __Graph3D__Main__

#include <iostream>
    //OpenGL 头文件
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/Glut.h>
    //STL 头文件
#include <vector>
#include <string>
#include <math.h>

/* OpenGL defines */
typedef struct {
    GLfloat      x;
    GLfloat      y;
} POINTFLOAT;

typedef struct {
    GLfloat      gmfBlackBoxX;
    GLfloat      gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    GLfloat      gmfCellIncX;
    GLfloat      gmfCellIncY;
} GLYPHMETRICSFLOAT;
typedef GLYPHMETRICSFLOAT *LPGLYPHMETRICSFLOAT;


#endif /* defined(__Graph3D__Main__) */