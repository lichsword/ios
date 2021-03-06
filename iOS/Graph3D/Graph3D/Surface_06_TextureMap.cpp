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
#include "ErrorReport.h"

void TextureMapSurface::loadTexture2D(GLuint * id, Image image){
        //    glGenerateMipmap(GL_TEXTURE_2D);
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, *id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
                                                                      //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);// mipmap
                                                                      //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);// mipmap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    
        //    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, 32, 32, GL_RGBA, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 1, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 2, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 3, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 4, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        //    glTexImage2D(GL_TEXTURE_2D, 5, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getImageDataRef());
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}


void TextureMapSurface::onStart(){

    glEnable(GL_TEXTURE_2D);// 开启2D纹理
    
    lpImages = new Image[6];
    
    lpImages[0].loadImage(bmp_file_0);// 加载位图
    
    /* 第2个纹理不能加载，一加载第1个纹理就失效，奇怪! */
    lpImages[1].loadImage(bmp_file_1);// 加载位图
    lpImages[2].loadImage(bmp_file_2);// 加载位图
    lpImages[3].loadImage(bmp_file_3);// 加载位图
    lpImages[4].loadImage(bmp_file_4);// 加载位图
    lpImages[5].loadImage(bmp_file_5);// 加载位图
    
        //    lpTextureID = new GLuint[6];
    

    
        //    glGenTextures(6, lpTextureID);// 生成纹理对象索引,赋值给变量
    glGenTextures(1, &texture0);
    glGenTextures(1, &texture1);
    glGenTextures(1, &texture2);
    glGenTextures(1, &texture3);
    glGenTextures(1, &texture4);
    glGenTextures(1, &texture5);
    
        //    ErrorReport::getInstance()->print("");
        //---------------------------
    loadTexture2D(&texture0, lpImages[0]);
        //    ErrorReport::getInstance()->print("");
    loadTexture2D(&texture1, lpImages[1]);
    loadTexture2D(&texture2, lpImages[2]);
    loadTexture2D(&texture3, lpImages[3]);
    loadTexture2D(&texture4, lpImages[4]);
    loadTexture2D(&texture5, lpImages[5]);
        //---------------------------
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
                                                                      //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);// mipmap
                                                                      //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);// mipmap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    
    
        //消除 texture 边缘的接缝
        //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used
     */
        //    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    
    setProjection();
        // do clear temp image data buffer.
        // TODO
}

void TextureMapSurface::display(){
    
    glEnable(GL_TEXTURE_2D);// 开启2D纹理
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    
    glColor3b(255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glLoadIdentity();
        //    glTranslatef(2.0f, 0.0f, -10.0f);
    glTranslatef(0.0f, 0.0f, -10.0f);
    glRotatef(rotCube, 0.0f, 1.0f, 0.0f);
    glRotatef(rotComX, 1.0f, 0.0f, 0.0f);
    
        // 前面
    glBindTexture(GL_TEXTURE_2D, texture0);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);// 纹理和四边形的左上
    glEnd();
    
        // 后面
    glBindTexture(GL_TEXTURE_2D, texture1);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glEnd();
    
        // 顶面
    glBindTexture(GL_TEXTURE_2D, texture2);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,  1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glEnd();
    
        // 底面
    glBindTexture(GL_TEXTURE_2D, texture3);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);// 纹理和四边形的右下
    glEnd();
    
        // 右面
    glBindTexture(GL_TEXTURE_2D, texture4);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);// 纹理和四边形的左下
    glEnd();
    
        // 左面
//    glBindTexture(GL_TEXTURE_2D, texture5);// 上下文绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);// 纹理和四边形的左上
    glEnd();
    
    glPopMatrix();
    
    rotCube -= 1.0f;
    rotComX += 1.0f;
}