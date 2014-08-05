    //
    //  Surface_28_Bezier.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-3.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__Surface_28_Bezier__
#define __Graph3D__Surface_28_Bezier__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"
#include "bezier.h"

class BezierSurface : public Surface{
private:
    char * bmp_file_1;
    char * bmp_file_2;
    char * bmp_file_3;
    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f }; 				// 环境光参数
    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };				 // 漫射光参数
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };				 // 光源位置
    Image * lpImages;
    BezierPatch * lpBezierPath;
        // 细分精度，控制曲面的显示精度
    int divs;
    GLfloat rotX;
    GLfloat rotY;
    GLfloat rotZ;
        // 是否显示控制点
    int showCPoints;
private:
    void loadTexture2D(GLuint id, Image image);
public:
    BezierSurface(){
        divs = 100;
        rotX = 0.0f;
        rotY = 0.0f;
        rotZ = 0.0f;
        
        showCPoints = 1;
        bmp_file_1 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp";
        bmp_file_2 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp";
        bmp_file_3 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/Crate.bmp";
    }
    virtual void onStart();
    virtual void display();
    virtual void keyboard(unsigned char key, int x, int y);
};

#endif /* defined(__Graph3D__Surface_28_Bezier__) */
