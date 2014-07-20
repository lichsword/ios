//
//  Button.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//
#include "Button.h"
#include "FreeType2.h"
#include "Screen.h"

Button::Button(int left, int top, int width, int height){
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
    
        // initial text color as white.
    textColor[0] = 0xff;
    textColor[1] = 0xff;
    textColor[2] = 0xff;
}

void Button::display(){
    drawBg();// view::drawBg();
    drawText();
}

void Button::setText(char * text){
    this->text = text;
}

void Button::setTextColor(GLubyte *color){
    this->textColor[0]= color[0];
    this->textColor[1]= color[1];
    this->textColor[2]= color[2];
}

void Button::drawText(){
    
    glColor3ub(textColor[0], textColor[1], textColor[2]);
    
    int realLeft = left;
    int realTop = real_h - top;
    if(NULL!=text){
        FreeType2::getInstance()->print(realLeft, realTop, text);
    }// end if
}
