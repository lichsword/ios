//
//  Button.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Screen.h"
#include "Button.h"

namespace button {
    
    int button_data::inArea(int x, int y){
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
    
    void button_data::set(int left, int top, int width, int height){
        this->left = left;
        this->top = top;
        this->width = width;
        this->height = height;
    }
    
    void button_data::setText(char *text){
        memset(this->text, 0, strlen(this->text));
        memcpy(this->text, text, strlen(text));
    }
    
    void button_data::display(){
        glEnable(GL_FLAT);
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,-1.0f);
        glBegin(GL_POLYGON);
        
            // 白色文字
        if(pressed){
            glColor3ub(0, 0xff, 0);
        }else{
            glColor3ub(0xff, 0, 0);
        }
        SCREENPOSITION screen_position;
        screen::map(&screen_position, left, top, width, height);
        
        glVertex2f(screen_position.left, screen_position.top);
        glVertex2f(screen_position.right, screen_position.top);
        glVertex2f(screen_position.right, screen_position.bottom);
        glVertex2f(screen_position.left, screen_position.bottom);

        glPopMatrix();
    }
    
    void button_data::setOnClickFunc(void (*func)()){
        this->onClickFunc = func;
    }
    
    void button_data::onClick(){
        if(NULL!=this->onClickFunc){
            onClickFunc();
        }// end if
    }
    
}