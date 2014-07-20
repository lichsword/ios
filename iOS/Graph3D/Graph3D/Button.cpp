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

//void Button::display(){
//    glPushMatrix();
//    
//        // --draw bg.
//        // choose color.
//    if(pressed){
//        glColor3ub(bgColorPressed[0], bgColorPressed[1], bgColorPressed[2]);
//    }else if(hover){
//        glColor3ub(bgColorHover[0], bgColorHover[1], bgColorHover[2]);
//    }else{
//        glColor3ub(bgColor[0], bgColor[1], bgColor[2]);
//    }
//        // count area.
//    SCREENPOSITION screen_position;
//    map(&screen_position, left, top, width, height);
//    
//        // -draw start
//    glLoadIdentity();
//    glBegin(GL_POLYGON);
//    
//    glVertex2f(screen_position.left, screen_position.top);
//    glVertex2f(screen_position.right, screen_position.top);
//    glVertex2f(screen_position.right, screen_position.bottom);
//    glVertex2f(screen_position.left, screen_position.bottom);
//    
//    glEnd();
//        // -draw end
//        // --draw bg end.
//    
//    glPopMatrix();
//}

void Button::setText(const char *){
        // TODO
}