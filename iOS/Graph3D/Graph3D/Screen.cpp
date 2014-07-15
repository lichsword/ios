//
//  Screen.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Screen.h"

namespace screen {
    
    int screen_data::map(LPSCREENPOSITION pos, int left, int top, int width, int height){
        int result = 0;
        
        pos->left = this->left +(float)left / (float)this->real_w;
        pos->right = this->left +(float)(left + width) / (float)this->real_w;
//        pos->top = this->top +(float)top / (float)this->real_h ;
//        pos->bottom = this->top +(float)(top + height) / (float)this->real_h ;
        
        // opengl默认y轴向上，而不是GUI的y轴向下
        pos->top = this->top - (float)top / (float)this->real_h ;
        pos->bottom = this->top - (float)(top + height) / (float)this->real_h ;
        
            // TODO result check.
        return result;
    }
    
    
}