//
//  Surface_51_SkyBox.h
//  Graph3D
//
//  Created by 王 岳 on 14-8-8.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_51_SkyBox__
#define __Graph3D__Surface_51_SkyBox__

#include <iostream>
#include "Surface.h"
#include "SkyBox.h"

class SkyBoxSurface : public Surface{
private:
    int enable2D;
    SkyBox * lpSkyBox;
    GLuint * lpTextures;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat rotX;
    GLfloat rotY;
    GLfloat rotZ;
    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f }; 				// 环境光参数
    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };				 // 漫射光参数
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };				 // 光源位置
    int startX;
    int startY;
    GLfloat lastRotX;
    GLfloat lastRotY;
private:
        void loadTexture2D(GLuint id, Image image);
public:
    SkyBoxSurface(){
        enable2D = 1;
        z = -4.0f;
    }
    virtual void onStart();
    virtual void display();
    virtual void keyboard(unsigned char key, int x, int y);
    virtual void onMouseEvent(int button, int state, int x, int y);
    virtual void onMotion(int x, int y);
};
#endif /* defined(__Graph3D__Surface_51_SkyBox__) */
