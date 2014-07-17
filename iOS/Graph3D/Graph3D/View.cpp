//
//  View.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-17.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "View.h"

View::View(){
    
}

View::~View(){
    
}

void View::display(){
    
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

void View::onMouseEvent(int button, int state, int x, int y){
    if(inArea(x, y)){
        pressed = 1;
        onClick();
    }else{
        pressed = 0;
    }
}

void View::onMotion(int x, int y){
    
}

void View::onPassiveMotion(int x, int y){
    
}