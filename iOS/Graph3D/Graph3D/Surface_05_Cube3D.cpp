//
//  Surface_05_3D.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-24.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_05_Cube3D.h"
#include "Screen.h"

void Cube3DSurface::onStart(){
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
                      // 设置视口的大小
	gluPerspective(45.0f,(GLfloat)real_w/(GLfloat)real_h,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
}

void Cube3DSurface::display(){
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);// 左1.5f,深入6.0f
    glRotatef(rotTri, 0.0f, 1.0f, 0.0f);
    glRotatef(rotComX, 1.0f, 0.0f, 0.0f);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);			// 红色
    glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (前侧面)
    glColor3f(0.0f,1.0f,0.0f);			// 绿色
    glVertex3f(-1.0f,-1.0f, 1.0f);			// 三角形的左下顶点 (前侧面)
    glColor3f(0.0f,0.0f,1.0f);			// 蓝色
    glVertex3f( 1.0f,-1.0f, 1.0f);			// 三角形的右下顶点 (前侧面)

    glColor3f(1.0f,0.0f,0.0f);			// 红色
    glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (右侧面)
    glColor3f(0.0f,0.0f,1.0f);			// 蓝色
    glVertex3f( 1.0f,-1.0f, 1.0f);			// 三角形的左下顶点 (右侧面)
    glColor3f(0.0f,1.0f,0.0f);			// 绿色
    glVertex3f( 1.0f,-1.0f, -1.0f);			// 三角形的右下顶点 (右侧面)
    
    glColor3f(1.0f,0.0f,0.0f);			// 红色
    glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (后侧面)
    glColor3f(0.0f,1.0f,0.0f);			// 绿色
    glVertex3f( 1.0f,-1.0f, -1.0f);			// 三角形的左下顶点 (后侧面)
    glColor3f(0.0f,0.0f,1.0f);			// 蓝色
    glVertex3f(-1.0f,-1.0f, -1.0f);			// 三角形的右下顶点 (后侧面)
    
    glColor3f(1.0f,0.0f,0.0f);			// 红色
    glVertex3f( 0.0f, 1.0f, 0.0f);			// 三角形的上顶点 (左侧面)
    glColor3f(0.0f,0.0f,1.0f);			// 蓝色
    glVertex3f(-1.0f,-1.0f,-1.0f);			// 三角形的左下顶点 (左侧面)
    glColor3f(0.0f,1.0f,0.0f);			// 绿色
    glVertex3f(-1.0f,-1.0f, 1.0f);			// 三角形的右下顶点 (左侧面)
    
    glEnd();
    
    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -6.0f);// 右1.5f,深入6.0f
    glRotatef(rotCube, 0.0f, 1.0f, 0.0f);
    glRotatef(rotComX, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    
    glColor3f(0.0f,1.0f,0.0f);			// 颜色改为蓝色
    glVertex3f( 1.0f, 1.0f,-1.0f);			// 四边形的右上顶点 (顶面)
    glVertex3f(-1.0f, 1.0f,-1.0f);			// 四边形的左上顶点 (顶面)
    glVertex3f(-1.0f, 1.0f, 1.0f);			// 四边形的左下顶点 (顶面)
    glVertex3f( 1.0f, 1.0f, 1.0f);			// 四边形的右下顶点 (顶面)
    
    glColor3f(1.0f,0.5f,0.0f);			// 颜色改成橙色
    glVertex3f( 1.0f,-1.0f, 1.0f);			// 四边形的右上顶点(底面)
    glVertex3f(-1.0f,-1.0f, 1.0f);			// 四边形的左上顶点(底面)
    glVertex3f(-1.0f,-1.0f,-1.0f);			// 四边形的左下顶点(底面)
    glVertex3f( 1.0f,-1.0f,-1.0f);			// 四边形的右下顶点(底面)
    
    glColor3f(1.0f,1.0f,0.0f);			// 颜色改成黄色
    glVertex3f( 1.0f,-1.0f,-1.0f);			// 四边形的右上顶点(后面)
    glVertex3f(-1.0f,-1.0f,-1.0f);			// 四边形的左上顶点(后面)
    glVertex3f(-1.0f, 1.0f,-1.0f);			// 四边形的左下顶点(后面)
    glVertex3f( 1.0f, 1.0f,-1.0f);			// 四边形的右下顶点(后面)
    
    glColor3f(1.0f,0.0f,0.0f);			// 颜色改成红色
    glVertex3f( 1.0f, 1.0f, 1.0f);			// 四边形的右上顶点(前面)
    glVertex3f(-1.0f, 1.0f, 1.0f);			// 四边形的左上顶点(前面)
    glVertex3f(-1.0f,-1.0f, 1.0f);			// 四边形的左下顶点(前面)
    glVertex3f( 1.0f,-1.0f, 1.0f);			// 四边形的右下顶点(前面)
    
    glColor3f(0.0f,0.0f,1.0f);			// 颜色改成蓝色
    glVertex3f(-1.0f, 1.0f, 1.0f);			// 四边形的右上顶点(左面)
    glVertex3f(-1.0f, 1.0f,-1.0f);			// 四边形的左上顶点(左面)
    glVertex3f(-1.0f,-1.0f,-1.0f);			// 四边形的左下顶点(左面)
    glVertex3f(-1.0f,-1.0f, 1.0f);			// 四边形的右下顶点(左面)

    glColor3f(1.0f,0.0f,1.0f);			// 颜色改成紫罗兰色
    glVertex3f( 1.0f, 1.0f,-1.0f);			// 四边形的右上顶点(右面)
    glVertex3f( 1.0f, 1.0f, 1.0f);			// 四边形的左上顶点(右面)
    glVertex3f( 1.0f,-1.0f, 1.0f);			// 四边形的左下顶点(右面)
    glVertex3f( 1.0f,-1.0f,-1.0f);			// 四边形的右下顶点(右面)
    
    glEnd();
    glPopMatrix();
    
    rotTri += 2.0f;
    rotCube -= 1.0f;
    rotComX += 1.0f;
}