//
//  Surface_07_Light.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-8-3.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_07_Light.h"
#include "Screen.h"

void LightSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}


void LightSurface::onStart(){
    lpImages = new Image[3];
    lpImages[0].loadImage(this->bmp_file_3);
    
    lpTextureID = new GLuint[3];
    glEnable(GL_TEXTURE_2D);// 开启2D纹理
    
    glGenTextures(2, lpTextureID);// 生成纹理对象索引,赋值给变量

    loadTexture2D(lpTextureID[0], lpImages[0]);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// 设置环境光
    
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// 设置光源位置
    
    glEnable(GL_LIGHT1);							// 启用一号光源
    
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
    
}

void LightSurface::display(){
    
        // 清除背景色
    glColor3b(255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glBindTexture(GL_TEXTURE_2D, lpTextureID[0]);// 上下文绑定纹理
    
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    
    glLoadIdentity();
    glTranslatef(2.0f, 0.0f, z);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    
    glBegin(GL_QUADS);
    
        // 前面
    glNormal3f( 0.0f, 0.0f, 1.0f);					// 法线指向观察者
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    
        // 后面
    glNormal3f( 0.0f, 0.0f,-1.0f);					// 法线背向观察者
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    
        // 顶面
    glNormal3f( 0.0f, 1.0f, 0.0f);					// 法线向上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    
        // 底面
    glNormal3f( 0.0f,-1.0f, 0.0f);					// 法线朝下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    
        // 右面
    glNormal3f( 1.0f, 0.0f, 0.0f);					// 法线朝右
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    
        // 左面
    glNormal3f(-1.0f, 0.0f, 0.0f);					// 法线朝左
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    
    glEnd();
    glPopMatrix();

    xRot += 1.0f;
    yRot -= 2.0f;
    z = -10.0f;
}