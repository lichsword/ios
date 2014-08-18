    //
    //  Main.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-12.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //
#include "Main.h"
#include "Test.h"
#include "FileLog.h"
#include "FreeType2.h"
#include "Scene.h"

    // mac 的屏幕大小
int SCREEN_W = 1280;
int SCREEN_H = 800;

    // 主窗口大小
#define WIN_W 800
#define WIN_H 600

Scene our_scene;

void initApp(){
    our_scene.init();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    our_scene.display();

    glutPostRedisplay();
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            exit(0);
            break;
        default:
            our_scene.keyboard(key, x, y);
            break;
    }
}

void mouse(int button , int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
        default:
            break;
    }
    
    switch (state) {
        case GLUT_UP:
            break;
        case GLUT_DOWN:
            break;
        default:
            break;
    }
    
    our_scene.onMouseEvent(button, state, x, y);
}

/* 鼠标移动，且有按钮被按下 */
void motion(int x, int y){
    our_scene.onMotion(x, y);
}

/* 鼠标移动，无论是否有按钮按下 */
void passiveMotion(int x, int y){
    our_scene.onPassiveMotion(x, y);
}

void entry(int state){
    switch (state) {
        case GLUT_LEFT:
                // 离开窗口
            break;
        case GLUT_ENTERED:
                // 进入窗口
            break;
        default:
            break;
    }
}

int main(int argc, char ** argv)
{
    Test::getInstance();
    
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutReshapeWindow(WIN_W, WIN_H);
    glutPositionWindow((SCREEN_W- WIN_W)/2, (SCREEN_H - WIN_H)/2);
        //    glutPositionWindow((SCREEN_W- WIN_W)/2 + 400,(SCREEN_H - WIN_H)/2 + 400);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passiveMotion);
    glutEntryFunc(entry);
    
    initApp();
    glutMainLoop();
}