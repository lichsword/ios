//
//  Screen.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Screen__
#define __Graph3D__Screen__

#include <iostream>

    //STL 头文件
#include <vector>
#include <string>
#include <math.h>
    //STL异常类
#include <stdexcept>

typedef struct{
    float left;
    float top;
    float right;
    float bottom;
}SCREENPOSITION;
typedef  SCREENPOSITION * LPSCREENPOSITION;

class Screen {
private:
    static Screen * sInstance;
    Screen();
public:
    static Screen* getInstance(){
        if(NULL==sInstance){
            sInstance = new Screen();
        }// end if
        return sInstance;
    }
    
    const float virtual_left = -1.0f;
    const float virtual_top = 1.0;
    const float virtual_right = 1.0;
    const float virtual_bottom = -1.0;
    
    const float virtualWidth = virtual_right - virtual_left;
    const float virtualHeight = virtual_bottom - virtual_top;
    
    const int real_w = 800;
    const int real_h = 600;
    const int half_w = real_w /2;
    const int half_h = real_h /2;

    int map(LPSCREENPOSITION pos, int left, int top, int width, int height);
};

Screen * Screen::sInstance=NULL;

#endif /* defined(__Graph3D__Screen__) */
