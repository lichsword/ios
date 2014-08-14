    //
    //  SurfaceView.cpp
    //  Graph3D
    //  SurfaceView 不是继承自View，它与View不同，是一种全屏的视图，无背景色属性，其子类可以实现各种3D的效果。
    //
    //  Created by 王 岳 on 14-7-16.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Surface.h"
#include "FreeType2.h"
#include "ErrorReport.h"
#include "Screen.h"

GLfloat	cnt1;			// 字体移动计数器1
GLfloat	cnt2;			// 字体移动计数器2

void Surface::onStart(){
        // do nothing.
}

void Surface::display(){
        // 红色文字
    glColor3ub(0xff,0,0);
    
    glPushMatrix();
    glLoadIdentity();
    glRotatef(cnt1,0,0,1);
    glScalef(1,.8+.3*cos(cnt1/5),1);
    glTranslatef(-180,0,0);
        //绘制freetype文字
    FreeType2::getInstance()->print(300, 200, "Active FreeType Text- %7.2f", cnt1);
    glPopMatrix();
    
    cnt1+=2.0f;
    cnt2+=0.005f;
}

void Surface::keyboard(unsigned char key, int x, int y){
        // do nothing.
}

void Surface::onMotion(int x, int y){
        // do nothing
}

void Surface::onMouseEvent(int button, int state, int x, int y){
    // do nothing
}

void Surface::setProjection(){
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
                      // 设置视口的大小
	gluPerspective(45.0f,(GLfloat)real_w/(GLfloat)real_h,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
}