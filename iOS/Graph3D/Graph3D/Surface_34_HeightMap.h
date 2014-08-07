    //
    //  Surface_34_HeightMap.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-5.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__Surface_34_HeightMap__
#define __Graph3D__Surface_34_HeightMap__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"

class HeightMapSurface : public Surface{
private:
        // 相邻顶点的距离
    int STEP_SIZE;
    char * bmp_file_1;
    char * bmp_file_2;
    char * bmp_file_3;
    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f }; 				// 环境光参数
    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };				 // 漫射光参数
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };				 // 光源位置
    int showMode;// 显示线框
    Image * lpImage;// 图像(内存加载了一个灰度图)
    GLfloat rotX;
    GLfloat rotY;
    GLfloat rotZ;
private:
    unsigned char getMapHeight(Image * lpImage, int X, int Y);
    void setVertexColor(Image * lpImage, int x, int y);
    void drawPoint(int x, int y);
public:
    HeightMapSurface(){
        STEP_SIZE = 16;
        showMode = 0;
        bmp_file_1 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/nature_mountain_1024.bmp";
        bmp_file_2 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/nature_tree_1024.bmp";
        bmp_file_3 = "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp";
        rotX = 0.0f;
        rotY = 0.0f;
        rotZ = 0.0f;
    }
    virtual void onStart();
    virtual void display();
    virtual void keyboard(unsigned char key, int x, int y);
};

#endif /* defined(__Graph3D__Surface_34_HeightMap__) */
