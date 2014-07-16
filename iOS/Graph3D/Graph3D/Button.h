//
//  Button.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Button__
#define __Graph3D__Button__

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

namespace button {
    using std::vector;
    using std::string;
    
    struct button_data{
        int width;
        int height;
        int top;
        int left;
        
        char text[80];
        
        void (* onClickFunc)(void);
        
        void setOnClickFunc(void (*func)(void));
        
        int pressed;// 0: default; 1: pressed.
        
        int inArea(int x, int y);
        
        void set(int left, int top, int width, int height);
        
        void setText(char * text);
        
        void display();
        
        void onClick();
    };
}

#endif /* defined(__Graph3D__Button__) */