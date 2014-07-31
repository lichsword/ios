//
//  BaseWindowSurface.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_01_BaseWindow.h"
#include "FreeType2.h"
#include "image_bitmap.h"

void BaseWindowSurface::onStart(){
    
}

void BaseWindowSurface::display(){
    glColor3ub(0xff,0xff,0xff);
    FreeType2::getInstance()->print(200, 300, "Hello! OpenGL, in Mac OS");
    memset(buffer, 0, 256);
    sprintf(buffer, "unsigned int = %d(bytes)", sizeof(unsigned int));
    FreeType2::getInstance()->print(200, 350, buffer);
    memset(buffer, 0, 256);
    sprintf(buffer, "unsigned short = %d(bytes)", sizeof(unsigned short));
    FreeType2::getInstance()->print(200, 370, buffer);
    memset(buffer, 0, 256);
    sprintf(buffer, "unsigned long = %d(bytes)", sizeof(unsigned long));
    FreeType2::getInstance()->print(200, 390, buffer);
    memset(buffer, 0, 256);
    sprintf(buffer, "BitmapFileHeader = %d(bytes)", sizeof(BitmapFileHeader));
    FreeType2::getInstance()->print(200, 410, buffer);
    memset(buffer, 0, 256);
    sprintf(buffer, "BitmapInfoHeader = %d(bytes)", sizeof(BitmapInfoHeader));
    FreeType2::getInstance()->print(200, 430, buffer);
}