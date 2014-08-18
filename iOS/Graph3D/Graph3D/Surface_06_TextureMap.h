    //
    //  Surface_06_TextureMap.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-27.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__Surface_06_TextureMap__
#define __Graph3D__Surface_06_TextureMap__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"

class TextureMapSurface : public Surface{
private:
    GLfloat rotCube;
    GLfloat rotComX;
    Image * lpImages;
    GLuint * lpTextureID;// 声明纹理对象变量
    GLuint texture0;
    GLuint texture1;
    GLuint texture2;
    GLuint texture3;
    GLuint texture4;
    GLuint texture5;
    
    char * bmp_file_0;
    char * bmp_file_1;
    char * bmp_file_2;
    char * bmp_file_3;
    char * bmp_file_4;
    char * bmp_file_5;
private:
    void loadTexture2D(GLuint * id, Image image);
public:
    TextureMapSurface(){
        bmp_file_0 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp";
        bmp_file_1 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp";
        bmp_file_2 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/Crate.bmp";
        bmp_file_3 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_red_win.bmp";
        bmp_file_4 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/mud.bmp";//tim.bmp";
        bmp_file_5 ="/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/Star.bmp";
    }
    virtual void onStart();
    virtual void display();
};

#endif /* defined(__Graph3D__Surface_06_TextureMap__) */
