//
//  Surface_07_Light.h
//  Graph3D
//
//  Created by 王 岳 on 14-8-3.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_07_Light__
#define __Graph3D__Surface_07_Light__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"

class LightSurface : public Surface{
private:
    int toggleLight;
    GLfloat xRot;
    GLfloat yRot;
    GLfloat z;
    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f }; 				// 环境光参数
    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };				 // 漫射光参数
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };				 // 光源位置
    GLuint	filter;									// 滤波类型
    Image * lpImages;
    GLuint * lpTextureID;// 声明3种纹理的储存空间
    char * bmp_file_1;
    char * bmp_file_2;
    char * bmp_file_3;
private:
    void loadTexture2D(GLuint id, Image image);
public:
    LightSurface(){
        toggleLight=1;
        xRot = 0.0f;
        yRot = 0.0f;
        z = -10.0f;
        bmp_file_1 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp";
        bmp_file_2 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp";
        bmp_file_3 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/Crate.bmp";
    }
    virtual void onStart();
    virtual void display();
};


#endif /* defined(__Graph3D__Surface_07_Light__) */
