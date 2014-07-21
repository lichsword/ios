//
//  Surface_03_Colors.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_03_Colors.h"
#include "Screen.h"

void ColorsSurface::onStart(){
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
                      // 设置视口的大小
	gluPerspective(45.0f,(GLfloat)real_w/(GLfloat)real_h,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
}

void ColorsSurface::display(){
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SMOOTH);
    
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    
    glBegin(GL_TRIANGLES);
    glColor3ub(0xff, 0, 0);
    glVertex3f( 0.0f, 1.0f, 0.0f);					// 上顶点
    glColor3ub(0, 0xff, 0);
    glVertex3f(-1.0f,-1.0f, 0.0f);					// 左下
    glColor3ub(0, 0, 0xff);
    glVertex3f( 1.0f,-1.0f, 0.0f);					// 右下
    
    glEnd();
    
    glTranslatef(3.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    
    glColor3ub(0xff, 0, 0);
    glVertex3f(-1.0f, 1.0f, 0.0f);					// 左上
    glColor3ub(0, 0xff, 0);
    glVertex3f( 1.0f, 1.0f, 0.0f);					// 右上
    glColor3ub(0, 0, 0xff);
    glVertex3f( 1.0f,-1.0f, 0.0f);					// 左下
    glColor3ub(0, 0xff, 0xff);
    glVertex3f(-1.0f,-1.0f, 0.0f);					// 右下
    
    glEnd();
    glPopMatrix();
}