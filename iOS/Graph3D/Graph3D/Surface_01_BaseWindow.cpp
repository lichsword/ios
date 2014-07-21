//
//  BaseWindowSurface.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_01_BaseWindow.h"
#include "FreeType2.h"

void BaseWindowSurface::display(){
    glColor3ub(0xff,0xff,0xff);
    FreeType2::getInstance()->print(200, 300, "Hello! OpenGL, in Mac OS");
}