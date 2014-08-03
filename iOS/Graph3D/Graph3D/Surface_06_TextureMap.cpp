//
//  Surface_06_TextureMap.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-27.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
/**
 * 未解决bug：
 * (1)glTexEnvf()方法的调用次序
 * (2)glBindTexture()的上下文是什么，影响什么
 * (3)依次加载2个位图，则第一个位图无法显示，推理依次加载N个位图也会有问题
 * (4)位图上方几行的相素有杂色
 */
//

#include "Surface_06_TextureMap.h"
#include "Screen.h"

void TextureMapSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}


void TextureMapSurface::onStart(){
    
    lpImages = new Image[2];
    
    lpImages[0].loadImage(bmp_file_1);// 加载位图
    /* 第2个纹理不能加载，一加载第1个纹理就失效，奇怪! */
//    lpImages[1].loadImage(bmp_file_2);// 加载位图
    
    lpTextureID = new GLuint[2];
    
    glEnable(GL_TEXTURE_2D);// 开启2D纹理
    
    glGenTextures(2, lpTextureID);// 生成纹理对象索引,赋值给变量

        //---------------------------
    loadTexture2D(lpTextureID[0], lpImages[0]);
//    loadTexture2D(lpTextureID[1], lpImages[1]);
        //---------------------------
    
        //消除 texture 边缘的接缝
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
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

    glBindTexture(GL_TEXTURE_2D, lpTextureID[0]);// 上下文绑定纹理
    
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();

    glColor3b(255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glLoadIdentity();
    glTranslatef(2.0f, 0.0f, -10.0f);
    glRotatef(rotCube, 0.0f, 1.0f, 0.0f);
    glRotatef(rotComX, 1.0f, 0.0f, 0.0f);
    
    glBegin(GL_QUADS);
    
        // 前面
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左上

        // 后面
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
        // 顶面
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
        // 底面
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
        // 右面
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
        // 左面
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    
    glEnd();
    glPopMatrix();
    
    rotCube -= 1.0f;
    rotComX += 1.0f;
}