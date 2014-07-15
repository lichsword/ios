//
//  Button.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

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
    
}