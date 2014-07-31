//
//  Surface_06_TextureMap.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-27.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_06_TextureMap.h"
#include "Screen.h"

/**
 * 未解决bug：
 * (1)glTexEnvf()方法的调用次序
 * (2)glBindTexture()的上下文是什么，影响什么
 *
 *
 */
void TextureMapSurface::onStart(){
//    image.loadImage("/Users/lichsword/Documents/workspace_apple/iOS/Graph3D/Graph3D/NeHe.bmp");// 加载位图
//    image.loadImage("/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp");// 加载位图
    lpImages = new Image[2];
    lpImages[0].loadImage("/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/NeHe_rebuild.bmp");// 加载位图
//    lpImages[1].loadImage("/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/test_color_green_win.bmp");// 加载位图
    
    textureIDs = new GLuint[2];
    
    glEnable(GL_TEXTURE_2D);// 开启2D纹理
    glGenTextures(2, textureIDs);// 生成纹理对象索引,赋值给变量
    
    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);// 上下文绑定纹理(一般在glTexImage2D之后调用)
    
        // 加载纹理数据 1
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, lpImages[0].getWidth(), lpImages[0].getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, lpImages[0].getImageDataRef());

//    glBindTexture(GL_TEXTURE_2D, textureIDs[1]);// 上下文绑定纹理(一般在glTexImage2D之后调用)
    
        // 加载纹理数据 2
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, lpImages[1].getWidth(), lpImages[1].getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, lpImages[1].getImageDataRef());

    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        //消除 texture 边缘的接缝
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
    
	gluPerspective(45.0f, (GLfloat)real_w/(GLfloat)real_h, 0.1f, 100.0f);// 设置视口的大小
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
    
        // do clear temp image data buffer.
        // TODO
}

void TextureMapSurface::display(){

    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);// 上下文绑定纹理
    
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    glColor3b(255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glLoadIdentity();
//    glTranslatef(1.5f, 0.0f, -6.0f);// 右1.5f,深入6.0f
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(rotCube, 0.0f, 1.0f, 0.0f);
    glRotatef(rotComX, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

        // 前面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);// 上下文绑定纹理
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左上

        // 后面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[1]);// 上下文绑定纹理
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
        // 顶面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);// 上下文绑定纹理
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
        // 底面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[1]);// 上下文绑定纹理
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
        // 右面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);// 上下文绑定纹理
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
        // 左面
//    glBindTexture(GL_TEXTURE_2D, textureIDs[1]);// 上下文绑定纹理
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    
    glEnd();
    glPopMatrix();
    
    rotCube -= 1.0f;
    rotComX += 1.0f;
}