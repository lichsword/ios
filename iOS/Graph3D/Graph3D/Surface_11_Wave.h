//
//  Surface_11_wave.h
//  Graph3D
//
//  Created by 王 岳 on 14-8-7.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_11_Wave__
#define __Graph3D__Surface_11_Wave__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"

class WaveSurface : public Surface{
private:
    GLuint * lpTextures;
    char * bmp_file_1;
    char * bmp_file_2;
    char * bmp_file_3;
    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f }; 				// 环境光参数
    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };				 // 漫射光参数
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };				 // 光源位置
    Image * lpImages;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat rotX;
    GLfloat rotY;
    GLfloat rotZ;
    int rotateLeft;
    float points[45][45][3];// Points网格顶点数组
    int wiggle_count = 0;// 指定旗形波浪的运动速度
    GLfloat hold;// 临时变量
private:
    void loadTexture2D(GLuint id, Image image);
public:
    WaveSurface(){
        x = 0;
        y = 0;
        z = -10.0f;
        rotateLeft = 0;
        bmp_file_1 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp";
        bmp_file_2 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp";
        bmp_file_3 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/Crate.bmp";
    }
    virtual void onStart();
    virtual void display();
    virtual void keyboard(unsigned char key, int x, int y);
};

#endif /* defined(__Graph3D__Surface_11_wave__) */
