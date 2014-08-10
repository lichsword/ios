    //
    //  Surface_51_SkyBox.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-8.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Surface_51_SkyBox.h"
#include "Screen.h"

void SkyBoxSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}

void SkyBoxSurface::onStart(){
        // 加载纹理
    lpSkyBox = new SkyBox(SkyBox::TYPE_BOX);
    lpSkyBox->a(0, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_down.bmp");
    lpSkyBox->a(1, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_up.bmp");
    lpSkyBox->a(2, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_east.bmp");
    lpSkyBox->a(3, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_west.bmp");
    lpSkyBox->a(4, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_north.bmp");
    lpSkyBox->a(5, "/Users/lichsword/Documents/workspace_apple/others/nehe-tuts/Data/redsky/redsky_south.bmp");
        // 绑定纹理
    int size = SkyBox::SIZE_BOX;
        //
    lpTextures = new GLuint[size];
    glGenTextures(size, lpTextures);
    
    Image * lpImages = lpSkyBox->getImageRef();
    for(int i =0; i<size; i++){
        glBindTexture(GL_TEXTURE_2D, lpTextures[i]);
        loadTexture2D(lpTextures[i], lpImages[i]);
    }
    
        // 使用2D纹理
    glEnable(GL_TEXTURE_2D);
        // 使用平滑着色
	glShadeModel(GL_SMOOTH);
        // 设置黑色背景
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
        // 设置深度缓存
	glClearDepth(1.0f);
        // 使用深度缓存
	glEnable(GL_DEPTH_TEST);
        // 设置深度方程
	glDepthFunc(GL_LEQUAL);
    
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used GL_REPLACE
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
    
	gluPerspective(45.0f, (GLfloat)real_w/(GLfloat)real_h, 0.1f, 100.0f);// 设置视口的大小
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
    
        // 设置环境光
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
        // 设置光源位置
    glLightfv(GL_LIGHT0, GL_POSITION,LightPosition);
        // 启用0号光源
    glEnable(GL_LIGHT0);
}

void SkyBoxSurface::display(){
    
        // 设置深度缓冲值为1.0f
    glClearDepth(1.0f);
        // 清除颜色缓冲区 和 深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        // 开启深度测试
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
        // 保护原栈
    glPushMatrix();
        // 初始化矩阵
    glLoadIdentity();
        // 偏移和旋转
    glTranslatef(x, y, z);
    glRotatef(rotX, 0.0f, 1.0f, 0.0f);
    glRotatef(rotY, 1.0f, 0.0f, 0.0f);
        // 前面
    glBindTexture(GL_TEXTURE_2D, lpTextures[0]);
        // 开始绘制
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
        // 后面
    glBindTexture(GL_TEXTURE_2D, lpTextures[1]);
        // 开始绘制
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
        // 左面
    glBindTexture(GL_TEXTURE_2D, lpTextures[2]);
        // 开始绘制
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    
    glPopMatrix();
}

void SkyBoxSurface::keyboard(unsigned char key, int x, int y){
    
}

void SkyBoxSurface::onMouseEvent(int button, int state, int x, int y){
    if(button!=GLUT_LEFT_BUTTON){
        return;
    }// end if
    
    switch (state) {
        case GLUT_DOWN:
            startX = x;
            startY = y;
            break;
        case GLUT_UP:
            lastRotX = rotX;
            lastRotY = rotY;
            break;
        default:
            break;
    }
}

void SkyBoxSurface::onMotion(int x, int y){
    rotX = lastRotX + ((GLfloat)(x - startX) / (GLfloat)10);
    rotY = lastRotY + ((GLfloat)(y - startY) / (GLfloat)10);
}