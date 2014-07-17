    //
    //  Screen.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-15.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Screen.h"

Screen::Screen(){
}

int Screen::map(LPSCREENPOSITION pos, int left, int top, int width, int height){
    int result = 0;
    
    pos->left = virtual_left +(float)left / (float)half_w;
    pos->right = virtual_left +(float)(left + width) / (float)half_w;
        //        pos->top = this->top +(float)top / (float)this->half_h ;
        //        pos->bottom = this->top +(float)(top + height) / (float)this->half_h ;
    
        // opengl默认y轴向上，而不是GUI的y轴向下
    pos->top = virtual_top - (float)top / (float)half_h ;
    pos->bottom = virtual_top - (float)(top + height) / (float)half_h ;
    
        // TODO result check.
    return result;
}