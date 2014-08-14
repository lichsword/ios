    //
    //  Surface_28_Bezier.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-3.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Surface_28_Bezier.h"
#include "Screen.h"

void BezierSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}

void BezierSurface::onStart(){
        // 使用2D纹理
	glEnable(GL_TEXTURE_2D);
        // 使用平滑着色
	glShadeModel(GL_SMOOTH);
        // 设置黑色背景
	glClearColor(0.05f, 0.05f, 0.05f, 0.5f);
        // 设置深度缓存
	glClearDepth(1.0f);
        // 使用深度缓存
	glEnable(GL_DEPTH_TEST);
        // 设置深度方程
	glDepthFunc(GL_LEQUAL);
    
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    lpBezierPath = new BezierPatch();
    lpImages = new Image();
        // 初始化贝塞尔曲面
	initBezier(lpBezierPath);
        // 载入位图
    lpImages->loadImage(bmp_file_1);
        // 载入纹理
    loadTexture2D(lpBezierPath->texture, *lpImages);
        // 创建显示列表
    lpBezierPath->dlBPatch = genBezier(lpBezierPath, divs);
    
        // 设置环境光
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
        // 设置光源位置
    glLightfv(GL_LIGHT0, GL_POSITION,LightPosition);
        // 启用0号光源
    glEnable(GL_LIGHT0);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used GL_REPLACE
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    setProjection();
}

void BezierSurface::display(){
    int i, j;
    
    glBindTexture(GL_TEXTURE_2D, lpBezierPath->texture);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
	glLoadIdentity();
        // 移入屏幕4个单位
	glTranslatef(0.0f, 0.0f, -6.0f);
        // 旋转一定的角度
//	glRotatef(-75.0f,1.0f,0.0f,0.0f);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    
        // 调用显示列表，绘制贝塞尔曲面
	glCallList(lpBezierPath->dlBPatch);
        // 是否绘制控制点
	if (showCPoints) {
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f,0.0f,0.0f);
            // 绘制水平线
		for(i=0;i<4;i++) {
			glBegin(GL_LINE_STRIP);
			for(j=0;j<4;j++){
				glVertex3d(lpBezierPath->anchors[i][j].x, lpBezierPath->anchors[i][j].y, lpBezierPath->anchors[i][j].z);
            }// end for
			glEnd();
		}
            // 绘制垂直线
		for(i=0;i<4;i++) {
			glBegin(GL_LINE_STRIP);
			for(j=0;j<4;j++){
				glVertex3d(lpBezierPath->anchors[j][i].x, lpBezierPath->anchors[j][i].y, lpBezierPath->anchors[j][i].z);
            }// end for
			glEnd();
		}
		glColor3f(1.0f,1.0f,1.0f);
		glEnable(GL_TEXTURE_2D);
	}// end if
    
    glPopMatrix();
    
    rotX += 1.0f;
//    rotY += 1.0f;
    rotZ += 1.0f;
}

void BezierSurface::keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'l':
        case 'L':
            if(showCPoints){
                showCPoints = 0;
            }else{
                showCPoints = 1;
            }
            break;
        case 'f':
        case 'F':
                // TODO
            break;
        default:
            break;
    }
}