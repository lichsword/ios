//
//  SkyBox.h
//  Graph3D
//
//  Created by 王 岳 on 14-8-9.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__SkyBox__
#define __Graph3D__SkyBox__

#include <iostream>
#include "image_bitmap.h"

class SkyBox{
private:
    Image * lpImages;
    int type;
public:
        // 类型：天空盒
    static const int TYPE_BOX = 0;
        // 类型：天空球
    static const int TYPE_SPHERE = 1;
        // 帖图数量：天空盒要6张图
    static const int SIZE_BOX = 6;    
public:
    SkyBox(int type){
        
    }
    
    void setType(int type){
        this->type = type;
    }
    
    int getType(){
        return type;
    }
    void loadBmp(int index, char * path);
    
    Image * getImageRef(){
        return lpImages;
    }
};

#endif /* defined(__Graph3D__SkyBox__) */
