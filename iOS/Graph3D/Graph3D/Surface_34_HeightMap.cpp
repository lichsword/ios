    //
    //  Surface_34_HeightMap.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-5.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Surface_34_HeightMap.h"
#include "Screen.h"

void HeightMapSurface::onStart(){
    this->lpImage = new Image();
    lpImage->loadImage(bmp_file_1);
    
        // 使用2D纹理
        //	glEnable(GL_TEXTURE_2D);
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
    
    
        //        // 设置环境光
        //    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
        //        // 设置光源位置
        //    glLightfv(GL_LIGHT0, GL_POSITION,LightPosition);
        //        // 启用0号光源
        //    glEnable(GL_LIGHT0);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used GL_REPLACE
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    setProjection();
}

unsigned char HeightMapSurface::getMapHeight(Image * lpImage, int X, int Y){
    if(!lpImage){
        return 0;
    }// end if
    return *(lpImage->getImageDataRef() + X + Y * lpImage->getWidth());
}

/**
 * 按高度设置顶点的颜色，越高的地方越亮
 */
void HeightMapSurface::setVertexColor(Image * lpImage, int x, int y){
	if(!lpImage){
        return;
    }// end if
    
        //  蓝色分量值
	float fColor = (getMapHeight(lpImage, x, y ) / 256.0f);
        // 设置顶点的颜色
	glColor3f(0.0f, 0.0f, fColor );
}

void HeightMapSurface::drawPoint(int mapX, int mapY){
    int mapWidth = lpImage->getWidth();
    int mapheight = lpImage->getHeight();
    
    int x;// 0 ~ width(1024);
    int y;// 0 ~ height(1024);
    int z;// 0 ~ 255
    
    int MAX_X = (int)mapWidth / 2;
    int MAX_Y = (int)mapheight / 2;
    int MAX_Z = (int)0xff;
    
    x = mapX;
    y = getMapHeight(lpImage, mapX, mapY);
    z = mapY;
        // 设置顶点颜色
    setVertexColor(lpImage, x, z);
        // 调用OpenGL绘制顶点的命令
    glVertex3f((GLfloat)x/MAX_X - 1.0f, (GLfloat)y/MAX_Z, (GLfloat)z/MAX_Y - 1.0f);
}

void HeightMapSurface::display(){
    
        //    glBindTexture(GL_TEXTURE_2D, lpBezierPath->texture);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
	glLoadIdentity();
        // 移入屏幕4个单位
	glTranslatef(0.0f, 0.0f, -4.0f);
        // 旋转一定的角度
        //	glRotatef(75.0f, 1.0f, 1.0f, 0.0f);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    
    int mapWidth = lpImage->getWidth();
    int mapheight = lpImage->getHeight();
    
        // 选择渲染模式
    switch (showMode) {
        case 0:
            glBegin(GL_LINES);// 渲染为直线
            break;
        case 1:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glBegin(GL_QUADS);// 渲染为线框四边形
            break;
        case 2:
        default:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glBegin(GL_QUADS);// 渲染为填充四边形
            break;
    }
    
    for (int X = 0; X < mapWidth; X += STEP_SIZE){
		for(int Y = 0; Y < mapheight; Y += STEP_SIZE){
                // 绘制(x,y)处的顶点
                // 获得(x,y,z)坐标
			drawPoint(X, Y);
                // 绘制(x,y+1)处的顶点
			drawPoint(X, Y+STEP_SIZE);
                // 绘制(x+1,y+1)处的顶点
			drawPoint(X+STEP_SIZE, Y+STEP_SIZE);
                // 绘制(x+1,y)处的顶点
			drawPoint(X+STEP_SIZE, Y);
		}
    }
    glEnd();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);			// 重置颜色
    
    glPopMatrix();
    
    rotX += 1.0f;
    rotY += 0.5f;
    rotZ += 0.2f;
}

void HeightMapSurface::keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'l':
        case 'L':
            if(showMode == 0){
                showMode = 1;
            }else if(showMode == 1){
                showMode = 2;
            }else {
                showMode = 0;
            }
            break;
        default:
            break;
    }
}