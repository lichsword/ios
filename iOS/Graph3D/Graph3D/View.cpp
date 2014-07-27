//
//  View.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-17.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "View.h"
#include "Screen.h"
#include "FileLog.h"

const GLint View::COLOR_NONE = 0;

View::View(){

}

View::~View(){
    
}

void View::display(){
    drawBg();
}

void View::drawBg(){
    glPushMatrix();
    
        // --draw bg.
    glClear(GL_COLOR);
        // choose color.
    if(pressed){
        glColor3ub(bgColorPressed[0], bgColorPressed[1], bgColorPressed[2]);
    }else if(hover){
        glColor3ub(bgColorHover[0], bgColorHover[1], bgColorHover[2]);
    }else{
        glColor3ub(bgColor[0], bgColor[1], bgColor[2]);
    }
        // count area.
    SCREENPOSITION screen_position;
    map(&screen_position, left, top, width, height);
    
        // -draw start
    glLoadIdentity();
    glBegin(GL_POLYGON);
    
    glVertex2f(screen_position.left, screen_position.top);
    glVertex2f(screen_position.right, screen_position.top);
    glVertex2f(screen_position.right, screen_position.bottom);
    glVertex2f(screen_position.left, screen_position.bottom);
    
    glEnd();
        // -draw end
        // --draw bg end.
    
    glPopMatrix();
}

void View::setOnClickListener(void (*func)()){
    this->onClickFunc = func;
}

void View::onClick(){
    if(NULL!=onClickFunc){
        onClickFunc();
    }// end if
}

int View::inArea(int x, int y){
    int result = 0;
    
    if(
       (x > left)
       && ((x < left + width))
       && (y > top)
       && (y < (top + height))){
        result = 1;
    }else{
        result = 0;
    }
    
    return result;
}

void View::setBgColor(GLubyte bgColorDefault[3], GLubyte bgColorHover[3], GLubyte bgColorPressed[3]){
        //
    this->bgColor[0] = bgColorDefault[0];
    this->bgColor[1] = bgColorDefault[1];
    this->bgColor[2] = bgColorDefault[2];
        //
    this->bgColorHover[0] = bgColorHover[0];
    this->bgColorHover[1] = bgColorHover[1];
    this->bgColorHover[2] = bgColorHover[2];
        //
    this->bgColorPressed[0] = bgColorPressed[0];
    this->bgColorPressed[1] = bgColorPressed[1];
    this->bgColorPressed[2] = bgColorPressed[2];
}

void View::onMouseEvent(int button, int state, int x, int y){
    char buffer[1024];
    memset(buffer, 0, 1024);
    sprintf(buffer, "button=%d, state=%d, x=%d, y=%d", button, state, x, y);
    FileLog::getInstance()->e(buffer);
    if(inArea(x, y)){
        switch (state) {
//            case GLUT_DOWN:
//                pressed = 1;
//                hover = 0;
//                break;
            case GLUT_UP:
//                if(pressed){// 之前是按下状态
                    onClick();
//                }// end if
//                pressed = 0;
//                hover = 1;
                break;
//            default:
//                break;
        }
//
//        
//    }else{
//        pressed = 0;
    }
}

void View::onMotion(int x, int y){
    
}

void View::onPassiveMotion(int x, int y){
    if(inArea(x, y)){
        hover = 1;
    }else{
        hover = 0;
    }
}