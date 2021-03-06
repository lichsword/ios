//
//  Surface_02_Quads.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-21.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Surface_02_Quads.h"
#include "Screen.h"

void QuadsSurface::onStart(){
    setProjection();
}

void QuadsSurface::display(){
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3ub(0xff,0xff,0xff);
    
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    
    glBegin(GL_TRIANGLES);
    
    glVertex3f( 0.0f, 1.0f, 0.0f);					// 上顶点
    glVertex3f(-1.0f,-1.0f, 0.0f);					// 左下
    glVertex3f( 1.0f,-1.0f, 0.0f);					// 右下
    
    glEnd();
    
    glTranslatef(3.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    
    glVertex3f(-1.0f, 1.0f, 0.0f);					// 左上
    glVertex3f( 1.0f, 1.0f, 0.0f);					// 右上
    glVertex3f( 1.0f,-1.0f, 0.0f);					// 左下
    glVertex3f(-1.0f,-1.0f, 0.0f);					// 右下
    
    glEnd();
    glPopMatrix();
}