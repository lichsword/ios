//
//  Button.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Screen.h"
#include "Button.h"

Button::Button(int left, int top, int width, int height){
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
}

void Button::display(){
    glPushMatrix();
    
        // 白色文字
    if(pressed){
        glColor3ub(0, 0xff, 0);
    }else{
        glColor3ub(0xff, 0, 0);
    }
    SCREENPOSITION screen_position;
//    Screen * lpScreen = Screen::getInstance();
//    lpScreen->map(&screen_position, left, top, width, height);
    map(&screen_position, left, top, width, height);
    
    glLoadIdentity();
        //      glEnable(GL_FLAT);
        //      glTranslatef(0.0f,0.0f,-1.0f);
    glBegin(GL_POLYGON);
    
    glVertex2f(screen_position.left, screen_position.top);
    glVertex2f(screen_position.right, screen_position.top);
    glVertex2f(screen_position.right, screen_position.bottom);
    glVertex2f(screen_position.left, screen_position.bottom);
    
    glEnd();
    
    glPopMatrix();
}

void Button::setText(const char *){
        // TODO
}