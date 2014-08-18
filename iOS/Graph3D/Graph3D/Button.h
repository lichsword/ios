//
//  Button.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Button__
#define __Graph3D__Button__

#include "View.h"

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

class Button : public View{
public:
    Button(int left, int top, int width, int height);
    void setText(char *);
    void setTextColor(GLubyte color[3]);
    virtual void display();
private:
    void drawText();
private:
    char * text;
    GLubyte textColor[3];
};

#endif /* defined(__Graph3D__Button__) */